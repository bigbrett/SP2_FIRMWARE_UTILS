#!/usr/bin/perl -s
#==============================================================================================
#
#         FILE:  update_translations.pl 
#
#        USAGE:  perl update_translations.pl <CSV_FILE.csv> <HEADER_FILE.h>
#
#  DESCRIPTION:  This script parses a CSV file containing translated
#                strings and their variable names, and updates the strings 
#                in the C data structure to match the CSV file. 
#                Ensure the CSV language table is up-to-date, and then call this script 
#                as detailed above. 
#
#      OPTIONS:  ---
#
#    ARGUMENTS:  1) <CSV_FILE.csv> - CSV file containing translated strings of the format below
#
#                       str_VAR_NAME,english,french,german,italian,spanish
#                       str_HELLO,hello,bonjour,hallo,ciao,hola
#                       str_THANK_YOU,thank you,merci,danke,grazie,gracias
#                       ...
#
#                2) <HEADER_FILE.h> - C header file containing language string data structure
#
#                       /* Enumerated type for string names */ 
#                       typedef enum {
#                           str_HELLO,
#                           str_THANKS,
#                           // .... lots of these
#                           NUM_STRINGS 
#                       } SP2_STRING_T;
#
#                   
#                       /* String data structure declaration */
#                       typedef struct 
#                       {
#                           uint16_t const string_lens[NUM_LANGUAGES]; // Maximum string length 
#                           const char* language_ptrs[NUM_LANGUAGES]; // Array of string pointers
#                       } sp2_string_struct_t;
#
#
#                       /* String data structure instantiation */ 
#                       static const sp2_string_struct_t string_array[NUM_STRINGS] = 
#                       {
#                           /* str_HELLO */ {{5,7,5,4,4},{"HELLO","BONJOUR","HALLO","CIAO","HOLA"}},
#                           /* str_THANK_YOU */ { {6,5,5,6,7},{"THANKS","MERCI","DANKE","GRAZIE","GRACIAS"}},
#                           // ... lots of these
#                       }; 
#
# REQUIREMENTS:  perl version 5.014 or newer 
#         BUGS:  ---
#        NOTES:  Copy of old header file is stored in <old_header>.h.bak
#       AUTHOR:  Brett Nicholas
#      COMPANY:  Avatech
#      VERSION:  1.0
#      CREATED:  08/10/2015
#     REVISION:  2
#==============================================================================================
use 5.014;
use strict;
use warnings;
no warnings 'uninitialized';
use Data::Dumper;
use Tie::File;
use File::Copy; 

# Get file names from command line
my $csvfile = "copy.csv";      
my $headerfile = "sp2_string.h";
my $backupfile= "$headerfile.bak"; 

# Global variables
my %langHash; # hash table holding language arrays, indexed by elements of @langs
my @langs; # array holding languages (hash keys to %langHash) 
my @str_names; # array holding string labels (hash keys to %{ $langHash{$lang} })

# Create backup of original header file with .orig extension
copy($headerfile,$backupfile) or die "Failed to create backup file: $!\n"; 


# --------------------------------------------------------------------------------
# ------------------ Parse CSV file to get updated strings -----------------------
# --------------------------------------------------------------------------------
print "\n...Parsing CSV file for updated values...\n";
open (my $fh_csv,'<', $csvfile) or die "Couldn't read '$csvfile': $!"; # open csv file for reading
while ( <$fh_csv> ) # parse file line by line
{
    # split $_ by commas
    my @fields = split /,/;

    # Each field of 1st line is stored in @langs
    if ($. == 1) 
    {
        @langs=@fields[1 .. $#fields]; # ignore first column 
        my $numlangs=$#langs; # number of languages declared
    }
    elsif (($. != 1) and ($#fields+1 == 6))  # if not first line and store each comma-separated string in correct language hash
    {
        push(@str_names, $fields[0]); # push string variable names onto array
        my @curr_strs = @fields[1 .. $#fields]; # store language strings in current string array
        
        # store each string in appropriate language hash array 
        my $i=0; 
        foreach my $string (@curr_strs) 
        {
            chomp $string; # remove possible trailing newline 
            ${ $langHash{$langs[$i++]} }{ $fields[0] } = $string; 
        }
    }
}
close $fh_csv or die "couldn't close '$csvfile' : $!"; #close file


# --------------------------------------------------------------------------------
# ------------ Rewrite string variable name declaration in header file ----------- 
# --------------------------------------------------------------------------------
print "\n...Updating string variable names...\n"; 
open (my $fh_header, '<', $headerfile) or die "Couldn't read '$headerfile': $!"; # open header file for reading
my ($startlinenum, $endlinenum, $numstringlines) = 0; # start and end line number for screen replacement 
while ( <$fh_header> )  # parse read-only file line by line
{
    # get starting line of string structure declaration
    /typedef enum \/\*SP2_STRING_T__PERL_START\*\// and $startlinenum=$.+1; 

    # count number of lines to be replaced 
    /typedef enum \/\*SP2_STRING_T__PERL_START\*\// .. /NUM_STRINGS/ and $numstringlines++ and $endlinenum=$.; 
}
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";

my @sub_strs = map{"    $_" . ","} @str_names; # format variable names

# replace string variable names in header with those from CSV 
tie my @flines, 'Tie::File', $headerfile or die "error using Tie to read file <$headerfile>";  # tie file lines to array 
splice(@flines,$startlinenum,($endlinenum-$startlinenum-1), @sub_strs); 
untie @flines;  


# --------------------------------------------------------------------------------
# ------- rewrite all fields in string structure in header file -------
# --------------------------------------------------------------------------------
print "\n...Updating string structure contents...\n";
open ($fh_header, '<', $headerfile) or die "Couldn't read '$headerfile': $!"; # open header file for reading
($startlinenum, $endlinenum, $numstringlines) = 0; # start and end line number for screen replacement 
while (<$fh_header>) # loop through file to get start and end line number for replacement
{
    /static const sp2_string_struct_t string_array\[NUM_STRINGS\]/ and $startlinenum=$.+1; 
    /static const sp2_string_struct_t string_array\[NUM_STRINGS\]/ .. /end string_array\[\]/ and $numstringlines++ and $endlinenum=$.; 
}
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";


my @newlines; # new array to be spliced into @flines
my (@templen, @tempstr); # dummy array containers to allow push/pop of strings
my ($commentlabel,$lens,$strs,$currline); # concatenate substrings to form $currline which is then pushed onto @newlines

# loop over hash structure and construct each line of the declaration, then push onto @newlines
foreach my $str_name (@str_names)
{
    $commentlabel = "/*" . $str_name . "*/"; # start each line with a commented string name 
    foreach my $lang (@langs)
    {
        push (@tempstr, "\"" . ${$langHash{$lang}}{$str_name} . "\""); #translated strings
        push (@templen, length ${$langHash{$lang}}{$str_name}) # push lengths
    }
    $lens = "{" . join(",",@templen) . "}" and @templen= (); # create syntactically correct length array field
    $strs = "{" . join(",",@tempstr) . "}" and @tempstr= (); # create syntactically correct string array field
    $currline = $commentlabel . " \{" . $lens . "," . $strs . "\}" and push(@newlines,$currline); # format current line and push current line onto new line
}

@newlines = join (",\n",@newlines); # separate lines with comma and newline

tie @flines, 'Tie::File', $headerfile or die "error using Tie to read file <$headerfile>"; # tie file lines to array 
splice(@flines,$startlinenum,($endlinenum-$startlinenum-1), @newlines); # replace line range with @newlines
untie @flines;



END { print "\n\n$headerfile updated successfully!\n\n";} 

