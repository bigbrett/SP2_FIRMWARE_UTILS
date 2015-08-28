@ECHO OFF
REM This script formats the SD Card for use in Avatech SP2 devices
REM Author: Joe Trovato
REM Company: Avatech, Inc.
SET filedir=Z:\Users\brettttt\Desktop
SET SD=F:

REM CD Z:\Users\brettttt\Desktop\ALL SD Card Files
REM format the sd card as FAT32 with 64K Application space
ECHO Formatting SD card
FORMAT %SD% /FS:FAT32 /Q /A:64K

REM copy the files to the newly formated SD card
ECHO Copying files to SD card
FOR %%I IN (IRDMS_calib_data.txt Pressure_calib_data.txt ROS_calib_data.txt Accelerometer_calib_data.txt Magnetometer_calib_Data.txt calib.bin image.bin usbmsd.bin) DO COPY "%filedir%\%%I" "%SD%/"

SET /P sn=Please Enter Device Serial Number:
ECHO %sn% > "%filedir%\serial.txt"
COPY "%filedir%\serial.txt" "%SD%/"

ECHO SD Card formated and loaded
