#!/usr/bin/perl -s
#==============================================================================================
#
#         FILE:  update_languages.pl
#
#        USAGE:  ./update_languages.pl <CSV_FILE.csv> <HEADER_FILE.h>
#
#  DESCRIPTION:  This script parses a CSV file containing translated
#                strings, and updates the strings in the C data structure
#                to match the CSV file
#
#      OPTIONS:  [ -convert ] : invoking this option strips input and output files of DOS-style
#                 line endings by calling dos2unix
#
#    ARGUMENTS:  1) <CSV_FILE.csv> - CSV file containing translated strings of the format below
#
#                       english,french,german,italian,spanish
#                       hello,bonjour,hallo,ciao,hola
#                       thanks,merci,danke,grazie,gracias
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
#                       typedef struct {
#                           uint16_t const string_lens[NUM_LANGUAGES]; // Maximum string length 
#                           const char* language_ptrs[NUM_LANGUAGES]; // Array of string pointers
#                       } sp2_string_struct_t;
#
#
#                       /* String data structure instantiation */ 
#                       static const sp2_string_struct_t string_array[NUM_STRINGS] = {
#                           /* str_HELLO */ 
#                           { {5,7,5,4,4},
#                           {   "HELLO",     // ENGLISH
#                               "BONJOUR",   // FRENCH
#                               "HALLO",     // GERMAN
#                               "CIAO",      // ITALIAN 
#                               "HOLA"       // SPANISH 
#                           } },
#
#                           /* str_THANKS */ 
#                           { {6,5,5,6,7},
#                           {   "THANKS",     // ENGLISH
#                               "MERCI",      // FRENCH
#                               "DANKE",      // GERMAN
#                               "GRAZIE",     // ITALIAN 
#                               "GRACIAS"     // SPANISH 
#                           } },
#                           
#                           // ... lots of these
#                       }; 
#
# REQUIREMENTS:  perl version 5.014 or newer 
#         BUGS:  ---
#        NOTES:  Copy of old header file stored in <old_header>.h.orig
#       AUTHOR:  Brett Nicholas
#      COMPANY:  Avatech
#      VERSION:  1.0
#      CREATED:  08/10/2015
#     REVISION:  1
#==============================================================================================
use 5.014;
use strict;
use warnings;
no warnings 'uninitialized';


our ($convert); # command line option to strip DOS line endings using dos2unix program 


(my $csvfile, my $headerfile) = @ARGV;      # get file names from command line
my $tempfile = "tempfile";                  # name of temporary file


my @langs = ("english","french","german","italian","spanish"); # array holding what languages are used
my (%french, %german, %italian, %spanish);  # hash table for each language where hash key is english string
my @english_keys; # array holding all english strings (keys)
my $key;
my $convert_success = 0;

print "OS = $^O\n\n"; # Print operating system 
# If running linux or mac, get rid of DOS-style line endings with BASH system call to dos2unix program
if ($convert) {
	system('command -v dos2unix >/dev/null 2>&1 || { echo >&2 "I require foo but it\'s not installed.  Aborting."; exit 1; }') == 0
			or die "FATAL ERROR: missing program: dos2unix\n\tdos2unix can be downloaded at http://sourceforge.net/projects/dos2unix or can be installed via your OS's native package manager (apt-get, apt-cyg, homebrew, etc. ). ";
	system("dos2unix $headerfile $csvfile");    # get rid of DOS-style line endings with BASH system call to dos2unix program
}
else {
    warn "WARNING: File may contain MS-DOS line endings, which could cause unwanted CRLF metacharacters to be inserted into strings (or other formatting issues).\nTo ensure line endings are *NIX compatible, use command-line option [ -convert ] to strip DOS CRLF characters using dos2unix program'\n";
}


open (my $fh_csv,'<', $csvfile) or die "Couldn't read '$csvfile': $!";      # open csv file for reading
while ( <$fh_csv> ) # parse file line by line
{
    # split $_ by commas
    my @fields = split /,/;

    # store each comma-separated string in correct language hash
    if (($. != 1) and ($#fields+1 == 5))
    {
        push(@english_keys, $fields[0]);        # english array
        $french{ $fields[0] } = $fields[1];     # french is second column
        $german{ $fields[0] } = $fields[2];     # german is third column
        $italian{ $fields[0] } = $fields[3];    # italian is fourth column

        chomp $fields[4];                       #remove trailing newline from last field
        $spanish{ $fields[0] } = $fields[4];    #spanish is fifth column
    }
}
close $fh_csv or die "couldn't close '$csvfile' : $!"; #close file


open (my $fh_header, '<', $headerfile) or die "Couldn't read '$headerfile': $!"; # open header file for reading
open (my $fh_tempfile, '>', $tempfile) or die "Couldn't create '$tempfile': $!"; # open temporary file for writing


# print header 
print "\nReplacing strings in $headerfile. Changes listed below...\n";
print "\nstr_STRING_NAME   (language):   \"old_string\" --> \"new_string\"\n";
print " --------------------------------------------------------------\n";


my $string_count = 0; # counts number of english strings processed 
my $error_line = 0; # holds line of first error
my $change_flag = 0; # flag incremented if any string is changed. 0 = no changes
my $curr_str_name; # holds name of current string


while ( <$fh_header> )  # parse read-only file line by line
{
    # if line falls within language struct declaration
    if ( /^static const sp2_string_struct_t string_array\[NUM_STRINGS\] =/.../end string_array/ )
    {
				# get current string label	
        /\/\*.*(str_.*?)\*\//s and $curr_str_name=$1;

        # get english translation hash key
        /$langs[0]/i and /"(.*?)"/i and $key="$1" # if line contains "english", $key=string between quotes
        and ( ($key eq $english_keys[$string_count]) # make sure english string in header matches csv string or DIE 
                or ( ($error_line = $string_count+3)
                    and unlink $tempfile
                    and die "\nERROR: ENGLISH STRING MISMATCH \n | \($headerfile - line $.\): \"$key\" \n | \($csvfile - line $error_line\): \"$english_keys[$string_count]\"\n >>> program terminated at" ) )
	    and $string_count++;

        # Check that translations exist
        /$langs[1]/i and !$french{$key} and warn "WARNING: no $langs[1] translation for $key";
        /$langs[2]/i and !$german{$key} and warn "WARNING: no $langs[2] translation for $key";
        /$langs[3]/i and !$italian{$key} and warn "WARNING: no $langs[3] translation for $key";
        /$langs[4]/i and !($spanish{$key}) and warn "WARNING: no $langs[4] translation for $key";

        # replace each language string with new hash value  by replacing string between
        # quotation marks with $<language>{$key} on lines that contain "<language>"
        /$langs[1]/i and s/"(.*?)"/"$french{$key}"/g
					and (($1 eq $french{$key}) or ( print "  $curr_str_name \($langs[1]\): \"$1\" --> \"$french{$key}\"\n" and $change_flag++ ));
        /$langs[2]/i and s/"(.*?)"/"$german{$key}"/g
					and (($1 eq $german{$key}) or ( print "  $curr_str_name \($langs[2]\): \"$1\" --> \"$german{$key}\"\n" and $change_flag++ ));
        /$langs[3]/i and s/"(.*?)"/"$italian{$key}"/g
					and (($1 eq $italian{$key}) or ( print "  $curr_str_name \($langs[3]\): \"$1\" --> \"$italian{$key}\"\n" and $change_flag++ ));
        /$langs[4]/i and s/"(.*?)"/"$spanish{$key}"/g 
					and (($1 eq $spanish{$key}) or ( print "  $curr_str_name \($langs[4]\): \"$1\" --> \"$spanish{$key}\"\n" and $change_flag++ ));
    }
    print $fh_tempfile "$_" or die "ERROR: Couldn't write to $tempfile: $!"; # print output to tempfile
}


# close files
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";
close $fh_tempfile, $tempfile or die "Couldn't close '$tempfile': $!";


# rename tempfile to sp2_string.h and rename original to sp2_string.h.orig
rename $headerfile, "$headerfile.orig";
($change_flag == 0) and print "  ... * no strings updated *\n\n"; # no strings updated
(rename $tempfile, $headerfile) and $convert and system("dos2unix $headerfile"); 

# print success message
print "\nLanguage strings successfully updated! Old header saved as  \'$headerfile.orig\' \n\n";

END { print "\n";}
