#!/usr/bin/perl
use strict;
use warnings;
no warnings 'uninitialized';


(my $csvfile, my $headerfile) = @ARGV;      # get file names from command line
my $tempfile = "tempfile";                  # name of temporary file

my @langs = ("english","french","german","italian","spanish"); # array holding what languages are used
my (%french, %german, %italian, %spanish);  # hash table for each language where hash key is english string
my @english_keys; # array holding all english strings (keys)
my $key;

system("dos2unix $headerfile $csvfile");    # get rid of DOS-style line endings with BASH system call to dos2unix program

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

while ( <$fh_header> )  # parse read-only file line by line
{
    # if line falls within language struct declaration
    if ( /^static const sp2_string_struct_t string_array\[NUM_STRINGS\] =/.../end string_array/ )
    {
        #get english translation hash key
        /$langs[0]/i and /"(.*?)"/i and $key="$1";

        # Check that translations exist
        #$french{$key} or die "ERROR: no French translation for '$key': $!";
        #$german{$key} or die "ERROR: no German translation for '$key': $!";
        #$italian{$key} or die "ERROR: no Italian translation for '$key': $!";
        #$spanish{$key} or die "ERROR: no Spanish translation for '$key': $!";

        # replace each language string with new hash value  by replacing string between
        # quotation marks with $<language>{$key} on lines that contain "<language>"
        # /$langs[1]/i and s/"(.*?)"/"$french{$key}"/g;
        # /$langs[2]/i and s/"(.*?)"/"$german{$key}"/g;
        # /$langs[3]/i and s/"(.*?)"/"$italian{$key}"/g;
        #/$langs[4]/i and s/"(.*?)"/"$spanish{$key}"/g;
        /$langs[4]/i and s/"(.*?)"/"$spanish{$key}"/g;
    }
    print $fh_tempfile "$_" or die "ERROR: Couldn't write to $tempfile: $!"; # print output to tempfile
}

# close files
close $fh_header, $headerfile or die "Couldn't close '$headerfile': $!";
close $fh_tempfile, $tempfile or die "Couldn't close '$tempfile': $!";

# rename tempfile to sp2_string.h and rename original to sp2_string.h.orig
rename $headerfile, "$headerfile.orig";
rename $tempfile, $headerfile;

