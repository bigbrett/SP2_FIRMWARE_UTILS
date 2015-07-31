#!/usr/bin/perl -wln -s
# PRINTS ALL STRINGS DECLARED IN HEADER FILE


/$lang/i and /"(.*?)"/i and print $1;


