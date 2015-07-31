#!/bin/bash

# This shell script aggregates data from ACC_Calib files below argument
# and appends it to a new file in CSV format 
#
# Author: Brett Nicholas
# Created: 7/14/2015


directory=$1

# aggregate all ACC_calib data in subdirectory and write to file
ACC_Values=`find $directory -type f -name *_ACC_Values*`
destfile="ACC_Values.csv"

if [ -f $destfile ]; then
    rm $destfile    
fi

for file in $ACC_Values; do
    # split file into fields and append to single file
    while read Ax Ay Az A0; do
            echo $Ax,$Ay,$Az
    done < $file >> $destfile
done

