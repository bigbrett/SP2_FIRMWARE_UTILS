#!/usr/bin/perl -s
use 5.014;
use strict;
use warnings;
no warnings 'uninitialized';

use Data::Dumper;
use Tie::File;

(my $csvfile) = "copy.csv";      # get file names from command line
my $headerfile = "sp2_string.h";

my @langs; # array holding languages (hash keys) 
my %langHash; # hash table holding language arrays, indexed by elements of @langs
my @str_names;

open (my $fh_csv,'<', $csvfile) or die "Couldn't read '$csvfile': $!"; # open csv file for reading
while ( <$fh_csv> ) # parse file line by line
{
    # split $_ by commas
    my @fields = split /,/;

    # Each field of 1st line are stored as langs
    if ($. == 1) 
    {
        @langs=@fields[1 .. $#fields]; # ignore first column 
        my $numlangs=$#langs;
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

#
# Rewrite string variable names in header
#
open (my $fh_header, '<', $headerfile) or die "Couldn't read '$headerfile': $!"; # open header file for reading
my ($startlinenum, $endlinenum, $numstringlines) = 0; # start and end line number for screen replacement 
while ( <$fh_header> )  # parse read-only file line by line
{
    # get starting line of string structure declaration
    /typedef enum \/\*SP2_STRING_T__PERL_START\*\// and $startlinenum=$.+2; 

    # count number of lines to be replaced 
    /typedef enum \/\*SP2_STRING_T__PERL_START\*\// .. /NUM_STRINGS/ and $numstringlines++ and $endlinenum=$.; 
    # /([^,]+)/ and print; 
}
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";

# replace string variable names in header with those from CSV 
tie my @flines, 'Tie::File', $headerfile or die "error using Tie to read file <$headerfile>";  
#$endlinenum -= 2; 
#
# replace string labels in structure with csv values
my @sub_strs = map{"    $_" . ","} @str_names; 
splice(@flines,$startlinenum,($endlinenum-$startlinenum-1), @sub_strs); 
untie @flines;  

#
# rewrite all fields in language string structure declaration
#
open ($fh_header, '<', $headerfile) or die "Couldn't read '$headerfile': $!"; # open header file for reading

while (<$fh_header>)
{
    # get start of structure declaration
    /static const sp2_string_struct_t string_array\[NUM_STRINGS\]/ and $startlinenum=$.+2; 
    
    /static const sp2_string_struct_t string_array\[NUM_STRINGS\]/ .. /end string_array\[\]/ and $numstringlines++ and $endlinenum=$.; 
}
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";

# replace string variable names in header with those from CSV 
tie @flines, 'Tie::File', $headerfile or die "error using Tie to read file <$headerfile>";  

# create array with all languages in order 
my (@ordered_strs);
my %lenHash;
foreach my $str_name ( @str_names )
{
    # loop through hash structure and add each string's translation in order 
    foreach my $lang (@langs)
    {
        push( @ordered_strs, ${$langHash{$lang}}{ $str_name });
        ${$lenHash{$lang}}{$str_name} = length ${$langHash{$lang}}{$str_name};  # add each string's length tho length hash
    }
}

#print join("\n",@flines[$startlinenum .. $endlinenum]); 
#print join("\n",@ordered_strs); 

# create new definition content
#splice(@flines,$startlinenum,($endlinenum-$startlinenum-1), @sub_strs);

my @newlines;
my (@templen, @tempstr);
my ($lens,$strs);

foreach my $str_name (@str_names)
{
    push (@newlines, "/*" . $str_name . "*/") and print "$newlines[-1]\n\t";
    foreach my $lang (@langs)
    {
        push (@tempstr, "\"" . ${$langHash{$lang}}{$str_name} . "\""); #holds each translated string
        push (@templen, length ${$langHash{$lang}}{$str_name}); #holds lengths
    } 
    $lens = "{" . join(",",@templen) . "}" and print "$lens\n\t" and @templen= (); # create length array field
    $strs = "{" . join(",",@tempstr) . "}" and print "$strs\n\t" and @tempstr= (); # create length array field
}



untie @flines;

=begin GHOSTCODE
    # if line falls within language struct declaration
    if ( /^static const sp2_string_struct_t string_array\[NUM_STRINGS\] =/.../end string_array/ )
    {
				# get current string label	
        /\/\*.*(str_.*?)\*\//s and $curr_str_name=$1;

        # get english translation hash key
        /$langs[0]/i and /"(.*?)"/i and $key="$1" # if line contains "english", $key=string between quotes
        and ( ($key eq $english_keys[$string_count]) # make sure english string in header matches csv string or DIE 
                or ( ($error_line = $string_count+3) and die "\nERROR: ENGLISH STRING MISMATCH \n | \($headerfile - line $.\): \"$key\" \n | \($csvfile - line $error_line\): \"$english_keys[$string_count]\"\n >>> program terminated at" ) )
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


=end GHOSTCODE
=cut
# close files
#close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";
#close $fh_tempfile, $tempfile or die "Couldn't close '$tempfile': $!";


# rename tempfile to sp2_string.h and rename original to sp2_string.h.orig
#rename $headerfile, "$headerfile.orig";
#rename $tempfile, $headerfile;


# print success message 
#($change_flag == 0) and print "  ... * no strings updated *\n"; # no strings updated
#print "\nLanguage strings successfully updated! Old header saved as  \'$headerfile.orig\' \n";


END { print "\n";} 

