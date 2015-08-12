#!/usr/bin/perl
#=========================================================================
#
#         FILE:  update_languages.pl
#
#        USAGE:  ./update_languages.pl <CSV_FILE.csv> <HEADER_FILE.h>
#
#  DESCRIPTION:  This script parses a CSV file containing translated
#                strings, and updates the strings in the C data structure
#                to match the CSV file
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  Brett Nicholas
#      COMPANY:  Avatech
#      VERSION:  1.0
#      CREATED:  08/10/2015
#     REVISION:  1
#=========================================================================
use 5.014;
use strict;
use warnings;
no warnings 'uninitialized';


(my $csvfile, my $headerfile) = @ARGV;      # get file names from command line
my $tempfile = "tempfile";                  # name of temporary file

my @langs = ("english","french","german","italian","spanish"); # array holding what languages are used
my (%french, %german, %italian, %spanish);  # hash table for each language where hash key is english string
my @english_keys; # array holding all english strings (keys)
my $key;

#system("dos2unix $headerfile $csvfile");    # get rid of DOS-style line endings with BASH system call to dos2unix program


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
        /$langs[0]/i and /"(.*?)"/i and $key="$1" 
					and ( ($key eq $english_keys[$string_count]) 
						or ( ($error_line = $string_count+3) 
							and die "\nERROR: ENGLISH STRING MISMATCH \n
												| \($headerfile - line $.\): \"$key\" \n
												| \($csvfile - line $error_line\): \"$english_keys[$string_count]\"\n 
												>>> program terminated at" ) ) 
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
rename $tempfile, $headerfile;

($change_flag == 0) and print "  ... * no strings updated *\n";
print "\nLanguage strings successfully updated! Old header saved as  \'$headerfile.orig\' \n";

END { print "\n";}
