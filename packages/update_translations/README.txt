FILE:  update_languages.pl

USAGE:  ./update_languages.pl <CSV_FILE.csv> <HEADER_FILE.h>

DESCRIPTION:  This script parses a CSV file containing translated
                strings, and updates the strings in the C data structure
                to match the CSV file

OPTIONS:  ---

ARGUMENTS:  1) <CSV_FILE.csv> - CSV file containing translated strings of the format below

                       english,french,german,italian,spanish
                       hello,bonjour,hallo,ciao,hola
                       thanks,merci,danke,grazie,gracias
                       ...

            2) <HEADER_FILE.h> - C header file containing language string data structure

                       /* Enumerated type for string names */ 
                       typedef enum {
                           str_HELLO,
                           str_THANKS,
                           // .... lots of these
                           NUM_STRINGS 
                       } SP2_STRING_T;

                       /* String data structure declaration */
                       typedef struct {
                           uint16_t const string_lens[NUM_LANGUAGES]; // Maximum string length 
                           const char* language_ptrs[NUM_LANGUAGES]; // Array of string pointers
                       } sp2_string_struct_t;


                       /* String data structure instantiation */ 
                       static const sp2_string_struct_t string_array[NUM_STRINGS] = {
                           /* str_HELLO */ 
                           { {5,7,5,4,4},
                           {   "HELLO",     // ENGLISH
                               "BONJOUR",   // FRENCH
                               "HALLO",     // GERMAN
                               "CIAO",      // ITALIAN 
                               "HOLA"       // SPANISH 
                           } },

                           /* str_THANKS */ 
                           { {6,5,5,6,7},
                           {   "THANKS",     // ENGLISH
                               "MERCI",      // FRENCH
                               "DANKE",      // GERMAN
                               "GRAZIE",     // ITALIAN 
                               "GRACIAS"     // SPANISH 
                           } },
                           
                           // ... lots of these
                       }; 

REQUIREMENTS:  perl version 5.014 or newer 
BUGS:  ---
NOTES:  Copy of old header file stored in <old_header>.h.orig
AUTHOR:  Brett Nicholas
COMPANY:  Avatech
VERSION:  1.0
CREATED:  08/10/2015
REVISION:  1
