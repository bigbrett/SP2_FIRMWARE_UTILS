#ifndef SP2_STRING_H_
#define SP2_STRING_H_

#include "common_headers.h"

/* Enumerated language type */ 
typedef enum
{
  ENGLISH,
  FRENCH,
  GERMAN,
  ITALIAN,
  SPANISH,

  NUM_LANGUAGES  // holds number of languages 
} SP2_LANGUAGE_T;


/*
 * Enumerated string type
 * Strings are listed by the UI screen state in which they are used (State_of_Screen)
 */
typedef enum 
{
    /* Header/Footer text */ 
    str_SELECT,
    str_BACK,
    str_NEXT,
    str_MENU,
    str_OPTIONS, 
    str_DELETE,
    str_DISCARD,
    str_DETAIL,
    str_GPS,
    str_GPS_COLON,
    str_SLOPE,
    str_FAVORITE,
    str_CANCEL,
    str_START,
    str_RETRY,
    str_ON,
    str_OFF,
    str_OK,
    str_NOT_APPLICABLE,
    str_SAVE,

    /* UI_MAINMENU_LIST menu items */
    str_NEW_TEST,
    str_SNOW_PROFILES,
    str_FAVORITES,
    str_SETTINGS,
    str_MASS_STORAGE,
    str_BLUETOOTH_TRANSFER,
    str_NEW_SNOW_PROFILE,
    str_SLOPE_MEASUREMENT,
    str_SETTINGS_SEL,
    str_CONFIG_SETTINGS,
    str_SETTINGS_MENU,
    
   /* File/Folder deletion prompts */
    str_DELETE_TEST,
    str_DELETE_ALL,
    str_DELETE_ALL_TESTS,
    str_IN_THIS_FOLDER,
    str_DELETE_FILE_PROMPT,
    str_DELETE_ALL_IN_FOLDER_PROMPT,
    str_DELETING_FOLDER,

    /* User testing strings */ 
    str_ALIGN_PROBE, 
    str_PRESS,
    str_TO_BEGIN, 
    str_CALIBRATING,
    str_COLLECTING_DATA,

    /* Calibration and loading screens */ 
    str_COMPASS_CALIBRATION,	
    str_GPS_LOCK_ACQUIRED,
    str_GPS_INFORMATION,
    str_ACQUIRED,
    str_PLEASE_ENTER_THE,
    str_ENTER,
    str_MANUAL_ENTRY,
    str_ASPECT,
    

    /* Test errors, warning messages, and user feedback */ 
    str_ERROR,
    str_REMOVE_SDCARD,
    str_PLEASE_INSERT,
    str_A_VALID_SDCARD,
    str_TO_THE_DEVICE,
    str_REBOOTING,
    str_REBOOTING_ELIPSES,
    str_REBOOT,
    str_SW_REBOOT,
    str_FIRMWARE_UPDATE,
    str_FAILED,
    str_PLEASE,
    str_RECONNECT_TO_PC,
    str_AND_TRY_AGAIN,
    str_NEW_FIRMWARE,
    str_DETECTED,
    str_PRESS_SELECT,
    str_TO_REBOOT,
    str_VALIDATING,
    str_GRAPH_CUT_AT_PAUSE,
    str_ARE_YOU_SURE_YOU,
    str_WANT_TO_DELETE,
    str_WANT_TO_DISCARD,
    str_THIS_TEST,
    str_PROCESSING_DATA,
    str_PLEASE_WAIT_ELIPSES,
    str_PLEASE_WAIT,
    str_WHILE_READING,
    str_THE_RECORD,
    str_READING_RECORD,
    str_LINK,
    str_LINK_SNOW_PROFILE,
    str_ENTER_PASSWORD,
    str_DAILY_TEST_LIMIT,
    str_OF_DT_NUM_REACHED,
    str_FAVORITE_LIMIT_OF,
    str_FAV_NUM_REACHED,
    str_EDITING_DISABLED,
    //TODO 
    

    /* UI_SETTINGS menu items */
    str_DATE_AND_TIME,
    str_BLUETOOTH,
    str_INITIALIZING_BLUETOOTH,
    str_GRAPH_DETAIL,
    str_GRAPH_DETAIL_0,
    str_GRAPH_DETAIL_1,
    str_GRAPH_DETAIL_2,
    str_GRAPH_DETAIL_3,
    str_GRAPH_DETAIL_4,
    str_LANGUAGE,
    str_TESTS_REQUIRE_SLOPE,
    str_ABOUT_DEVICE,

    /* Bluetooth main content */
    str_INITIALIZING,
    str_THE_DEVICE_IS_NOW,
    str_DISCOVERABLE,
    str_PLEASE_CONNECT,
    str_YOUR_DEVICE,
    str_CONNECTED,
    str_PREPARING_TO_SYNC,
    str_SYNCING,
    str_SYNC_COMPLETE,
    str_SYNC_FAILED,
    str_PLEASE_TRY_AGAIN,
    str_PLEASE_TURN,
    str_ON_BLUETOOTH,
    str_TO_SEND_THE_FILE,
    str_NO_TESTS_AVAILABLE,
    str_TO_SYNC,
    
    
    /* UI_DATE_AND_TIME */
    str_DATE,
    str_TIME_FORMAT,
    str_TIME_ZONE,
    str_TIME,
    str_ZONE,
    str_DAYLIGHT_SAVINGS_TIME_1,
    str_DAYLIGHT_SAVINGS_TIME_2,
    
    /* Time zone lists */
	str_ADELAIDE,
	str_ALMATY,
	str_AUCKLAND,
	str_BANGKOK,
	str_BOMBAY,
	str_BRASILIA,
	str_BRISBANE,
	str_CAIRO,
	str_CAPE_TOWN,
	str_CAPE_VERDE,
	str_CHITA,
	str_DARWIN,
	str_EKATERINBURG,
	str_EU_CENTRAL,
	str_EU_EASTERN,
	str_EU_WESTERN,
	str_FIJI,
	str_HONG_KONG,
	str_ICELAND,
	str_ISLAMABAD,
	str_JAKARTA,
	str_KABUL,
	str_KALININGRAD,
	str_KATHMANDU,
	str_KRASNOYARSK,
	str_LAGOS,
	str_MAGADAN,
	str_MEX_CENTRAL,
	str_MEX_MOUNTAIN,
	str_MEX_PACIFIC,
	str_MOSCOW,
	str_MUSCAT,
	str_NEWFOUNDLAND,
	str_NOVOSIBIRSK,
	str_PERTH,
	str_PETROPAVLOVSK,
	str_RIYADH,
	str_SAMARA,
	str_SAMOA,
	str_SYDNEY,
	str_TASMANIA,
	str_TEHRAN,
	str_TOKYO,
	str_US_ALASKA,
	str_US_ARIZONA,
	str_US_ATLANTIC,
	str_US_CENTRAL,
	str_US_EASTERN,
	str_US_HAWAII,
	str_US_MOUNTAIN,
	str_US_PACIFIC,
	str_VLADIVOSTOK,
	str_WINDHOEK,
    
    /* Secret Sensor output menu */ 
	str_SENSOR_OUTPUT,
    str_PRESSURE,
    str_DEPTH,
    str_EYE,
    str_ROS_1,
    str_ROS_2,
    str_TILT,

  NUM_STRINGS 
} SP2_STRING_T;


/* String data structure */
typedef struct
{
  /* Maximum string length */
  uint16_t const string_lens[NUM_LANGUAGES];

  /* Array of pointers to language-specific string arrays */
  const char* language_ptrs[NUM_LANGUAGES];

} sp2_string_struct_t;


/* Multi-language string array structure */
static const sp2_string_struct_t string_array[NUM_STRINGS] =
{
    /* str_SELECT */  
	{ {6,3,3,3,3},
      {		"SELECT",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      	// Spanish
    } },

    /* str_BACK */ 
    { {4,3,3,3,3},
      {     "BACK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
    } },

    /* str_NEXT */  
	{ {4,3,3,3,3},
      {		"NEXT",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },

    /* str_MENU */ 
    { {4,3,3,3,3},
      {     "MENU",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_OPTIONS */
    { {7,3,3,3,3},
      {     "OPTIONS",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DELETE */ 
    { {6,3,3,3,3},
      {     "DELETE",	  // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DISCARD */ 
    { {7,3,3,3,3},
      {     "DISCARD",	  // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DETAIL */
    { {6,3,3,3,3},
      {     "DETAIL",	  // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_GPS */
    { {3,3,3,3,3},
      {     "GPS",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_GPS_COLON */
    { {4,3,3,3,3},
      {     "GPS:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_SLOPE */
    { {5,3,3,3,3},
      {     "SLOPE",    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_FAVORITE */
    { {8,3,3,3,3},
      {     "FAVORITE",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_CANCEL */
    { {6,3,3,3,3},
      {     "CANCEL",	  // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_START */
	{ {5,3,3,3,3},
      {     "START", // English
			"FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} },

	/* str_RETRY */ 
	{ {5,3,3,3,3},
      {     "RETRY", // ENGLISH
			"FOO",	 // French
			"BAR",   // GERMAN
			"NOO", 	// Italian
			"BAZ"	 // Spanish
		} },
		
    /* str_ON */ 
    { {2,3,3,3,3},
      {     "ON",		    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_OFF */
    { {3,3,3,3,3},
      {     "OFF",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_OK */
    { {2,3,3,3,3},
      {     "OK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_NOT_APPLICABLE */
    { {3,3,3,3,3},
      {     "N/A",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_SAVE*/
    { {4,3,3,3,3},
      {     "SAVE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

/*#######################################################################*
 *  UI_MAINMENU_LIST menu items                                          * 
 *#######################################################################*/
    /* str_NEW_TEST */
    { {8,3,3,3,3},
      {     "NEW TEST",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_SNOW_PROFILES */
    { {13,3,3,3,3},
      {     "SNOW PROFILES",	// English 
            "FOO",	    			// French
            "BAR",      			// German 
            "NOO",      			// Italian
            "BAZ"      			// Spanish
		} }, 

    /* str_FAVORITES */
    { {15,3,3,3,3},
      {     "FAVORITES", 	// English 
            "FOO",	    	// French
            "BAR",      	// German 
            "NOO",      	// Italian
            "BAZ"      	// Spanish
		} }, 

    /* str_SETTINGS */
    { {8,3,3,3,3},
      {     "SETTINGS",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

		
	/* str_MASS_STORAGE */ 
    { {12,3,3,3,3},
      {     "MASS STORAGE",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_BLUETOOTH_TRANSFER */ 
    { {18,3,3,3,3},
      {     "BLUETOOTH TRANSFER",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
           
    /* str_NEW_SNOW_PROFILE */
    { {16,3,3,3,3},
      {     "NEW SNOW PROFILE",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_SLOPE_MEASUREMENT*/
    { {17,3,3,3,3},
      {     "SLOPE MEASUREMENT",	// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_SETTINGS_SEL */
    { {12,3,3,3,3},
      {     "SETTINGS SEL",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_CONFIG_SETTINGS*/
    { {15,3,3,3,3},
      {     "CONFIG SETTINGS",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_SETTINGS_MENU */
    { {13,3,3,3,3},
      {     "SETTINGS MENU",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

/*#######################################################################*
 *  File/Folder deletion prompts 
 *#######################################################################*/
    /* str_DELETE_TEST */
    { {12,3,3,3,3},
      {     "DELETE TEST?",	// English 
            "FOO",	    	// French
            "BAR",      	// German 
            "NOO",      	// Italian
            "BAZ"      	// Spanish
		} }, 

    /* str_DELETE_ALL */
    { {10,3,3,3,3},
      {     "DELETE ALL",	// English 
            "FOO",	    	// French
            "BAR",      	// German 
            "NOO",      	// Italian
            "BAZ"      	// Spanish
		} }, 

    /* str_DELETE_ALL_TESTS */
    { {16,3,3,3,3},
      {     "DELETE ALL TESTS",	// English 
            "FOO",	    	// French
            "BAR",      	// German 
            "NOO",      	// Italian
            "BAZ"      	// Spanish
		} }, 

    /* str_IN_THIS_FOLDER*/
    { {15,3,3,3,3},
      {     "IN THIS FOLDER?",	// English 
            "FOO",	    	// French
            "BAR",      	// German 
            "NOO",      	// Italian
            "BAZ"      	// Spanish
		} }, 


    /* str_DELETE_FILE_PROMPT */
    { {12,3,3,3,3},
      {     "DELETE FILE?",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

    /* str_DELETE_ALL_IN_FOLDER_PROMPT */
    { {21,3,3,3,3},
      {     "DELETE ALL IN FOLDER?",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DELETING_FOLDER_PROMPT */
    { {18,3,3,3,3},
      {     "DELETING FOLDER...",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 


/*#######################################################################*
 * USER TESTING STRINGS
 *#######################################################################*/
	/* str_ALIGN_PROBE */ 
	{ {6,3,3,3,3},
      {     "ALIGN PROBE", 	// english
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
	} },  
	
	/* str_PRESS */ 
	{ {5,3,3,3,3},
      {     "PRESS", // ENGLISH
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
	} },
	
	/* str_TO_BEGIN*/ 
	{ {8,3,3,3,3},
      {     "TO BEGIN", // ENGLISH
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
	} },
	
	/* str_CALIBRATING */
	{ {13,3,3,3,3},
      {     "  CALIBRATING", // ENGLISH
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
	} },

	/* str_COLLECTING_DATA */ 
	{ {8,3,3,3,3},
      {     "COLLECTING DATA", // ENGLISH
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
	} },

/*#######################################################################*
 *  Calibration screens                                                  * 
 *#######################################################################*/	
	/* str_COMPASS_CALIBRATION */
	{ {19,3,3,3,3},
      {     "COMPASS CALIBRATION",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_GPS_LOCK_ACQUIRED */
	{ {18,3,3,3,3},
      {     "GPS LOCK ACQUIRED!",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_GPS_INFORMATION */
	{ {15,3,3,3,3},
      {     "GPS INFORMATION",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_ACQUIRED*/
	{ {9,3,3,3,3},
      {     "ACQUIRED!",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_PLEASE_ENTER_THE */
	{ {16,3,3,3,3},
      {     "PLEASE ENTER THE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_ENTER */
	{ {5,3,3,3,3},
      {     "ENTER",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_MANUAL_ENTRY */
	{ {12,3,3,3,3},
      {     "MANUAL ENTRY",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_PLEASE_ENTER_THE */
	{ {6,3,3,3,3},
      {     "ASPECT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },


/*#######################################################################*
 *  Test errors, warning messages, and user feedback                     *  
 *#######################################################################*/ 
	/* str_ERROR */
	{ {5,3,3,3,3},
      {     "ERROR",  // English 
	        "FOO",	    			// French
	        "BAR",      			// German 
	        "NOO",      			// Italian
	        "BAZ"      			// Spanish
	} }, 

	/* str_REMOVE_SDCARD*/
	{ {13,3,3,3,3},
      {     "REMOVE SDCARD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_PLEASE_INSERT */
	{ {13,3,3,3,3},
      {     "PLEASE INSERT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_A_VALID_SDCARD */
	{ {14,3,3,3,3},
      {     "A VALID SDCARD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_TO_THE_DEVICE */
	{ {13,3,3,3,3},
      {     "TO THE DEVICE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },    

	/* str_REBOOTING*/
	{ {9,3,3,3,3},
      {     "REBOOTING",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },


	/* str_REBOOTING_ELIPSES*/
	{ {12,3,3,3,3},
      {     "REBOOTING...",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_REBOOT*/
	{ {6,3,3,3,3},
      {     "REBOOT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_SW_REBOOT*/
	{ {9,3,3,3,3},
      {     "SW REBOOT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_FIRMWARE_UPDATE */ 
	{ {15,3,3,3,3},
      {     "FIRMWARE UPDATE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_FAILED */
	{ {8,3,3,3,3},
      {     "  FAILED",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_PLEASE */
	{ {8,3,3,3,3},
      {     "  PLEASE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_RECONNECT_TO_PC */
	{ {15,3,3,3,3},
      {     "RECONNECT TO PC",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_AND_TRY_AGAIN */
	{ {14,3,3,3,3},
      {     " AND TRY AGAIN",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_NEW_FIRMWARE */
	{ {12,3,3,3,3},
      {     "NEW FIRMWARE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

    /* str_DETECTED */
	{ {10,3,3,3,3},
      {     "  DETECTED",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_PRESS_SELECT */
	{ {12,3,3,3,3},
      {     "PRESS SELECT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_TO_REBOOT */
	{ {11,3,3,3,3},
      {     "  TO REBOOT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_VALIDATING */
	{ {12,3,3,3,3},
      {     "  VALIDATING",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },	    
	
	/* str_GRAPH_CUT_AT_PAUSE */ 
	{ {18,3,3,3,3},
      {     "GRAPH CUT AT PAUSE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_ARE_YOU_SURE_YOU */
	{ {16,3,3,3,3},
      {     "ARE YOU SURE YOU",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_WANT_TO_DELETE */
	{ {14,3,3,3,3},
      {     "WANT TO DELETE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	/* str_WANT_TO_DISCARD */
	{ {15,3,3,3,3},
      {     "WANT TO DISCARD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
    
	/* str_THIS_TEST */
	{ {10,3,3,3,3},
      {     "THIS TEST?",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

   /* str_PROCESSING_DATA */
	{ {15,3,3,3,3},
      {     "PROCESSING DATA",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
	
	/* str_PLEASE_WAIT_ELIPSES */
	{ {14,3,3,3,3},
      {     "PLEASE WAIT...",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

  /*  str_PLEASE_WAIT */
	{ {11,3,3,3,3},
      {     "PLEASE WAIT",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

  /*  str_WHILE_READING */
	{ {13,3,3,3,3},
      {     "WHILE READING",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

  /*  str_THE_RECORD */
	{ {10,3,3,3,3},
      {     "THE RECORD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

  /*  str_READING_RECORD */
	{ {14,3,3,3,3},
      {     "READING RECORD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

  /*  str_LINK */
	{ {4,3,3,3,3},
      {     "LINK",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
 
  /*  str_LINK_SNOW_PROFILE */
	{ {17,3,3,3,3},
      {     "LINK SNOW PROFILE",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },
 
  /*  str_ENTER_PASSWORD */
	{ {14,3,3,3,3},
      {     "ENTER PASSWORD",  // English 
			"FOO",	    			// French
		    "BAR",      			// German 
		    "NOO",      			// Italian
		    "BAZ"      			// Spanish
	} },

	
    /* str_DAILY_TEST_LIMIT */  
	{ {16,3,3,3,3},
      {		"DAILY TEST LIMIT",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },

    /* str_OF_DT_NUM_REACHED */  
	{ {17,3,3,3,3},
      {		"OF 254 REACHED!!!",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },

    /* str_FAVORITE_LIMIT_OF*/  
	{ {17,3,3,3,3},
      {		"FAVORITE LIMIT OF",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },

    /* str_FAV_NUM_REACHED */  
	{ {11,3,3,3,3},
      {		"64 REACHED!",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },

    /* str_EDITING_DISABLED */  
	{ {16,3,3,3,3},
      {		"EDITING DISABLED ",	// English 
    		"FOO",  	// French
    		"BAR",      // German 
    		"NOO",      // Italian 
    		"BAZ"      // Spanish
    } },
     //TODO 

     //TODO 

/*#######################################################################*
 * UI_SETTINGS menu items  
 *#######################################################################*/ 
    /* str_DATE_AND_TIME */
    { {13,3,3,3,3},
      {     "DATE AND TIME",  // English 
            "FOO",	    			// French
            "BAR",      			// German 
            "NOO",      			// Italian
            "BAZ"      			// Spanish
		} }, 

    /* str_BLUETOOTH */
    { {9,3,3,3,3},
      {     "BLUETOOTH",// English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_INITIALIZING_BLUETOOTH */
    { {22,3,3,3,3},
      {     "INITIALIZING BLUETOOTH",  // English 
            "FOO",	    						   // French
            "BAR",      						   // German 
            "NOO",      						   // Italian
            "BAZ"      						   // Spanish
		} }, 

    /* str_GRAPH_DETAIL */
    { {12,3,3,3,3},
      {     "GRAPH DETAIL",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
		
	/* str_GRAPH_DETAIL_0 */
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 0",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

    /* str_GRAPH_DETAIL 1*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 1",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 2 */
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 2",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 3*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 3",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 4*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 4",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

    /* str_LANGUAGE */
    { {8,3,3,3,3},
      {     "LANGUAGE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
    
    /* str_TESTS_REQUIRE_SLOPE */
    { {14,3,3,3,3},
      {     "REQUIRE SLOPE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
    
	/* str_ABOUT_DEVICE */
    { {12,3,3,3,3},
      {     "ABOUT DEVICE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

/*#######################################################################*
* Bluetooth main content 												 *
/*#######################################################################*/     
	/* str_INITIALIZING */
    { {12,3,3,3,3},
      {     "INITIALIZING",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_THE_DEVICE_IS_NOW */
    { {17,3,3,3,3},
      {     "THE DEVICE IS NOW",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_DISCOVERABLE */
    { {12,3,3,3,3},
      {     "DISCOVERABLE.",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_PLEASE_CONNECT */
    { {14,3,3,3,3},
      {     "PLEASE CONNECT",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_YOUR_DEVICE */
    { {11,3,3,3,3},
      {     "YOUR DEVICE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_CONNECTED */
    { {9,3,3,3,3},
      {     "CONNECTED",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_PREPARING_TO_SYNC */
    { {17,3,3,3,3},
      {     "PREPARING TO SYNC",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_SYNCING */
    { {7,3,3,3,3},
      {     "SYNCING",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
		
	/* str_SYNC_COMPLETE */
    { {14,3,3,3,3},
      {     "SYNC COMPLETE!",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_SYNC_FAILED */
    { {12,3,3,3,3},
      {     "SYNC FAILED!",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_PLEASE_TRY_AGAIN */
    { {16,3,3,3,3},
      {     "PLEASE TRY AGAIN",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_PLEASE_TURN */
    { {11,3,3,3,3},
      {     "PLEASE TURN",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_ON_BLUETOOTH */
    { {12,3,3,3,3},
      {     "ON BLUETOOTH",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_TO_SEND_THE_FILE */
    { {16,3,3,3,3},
      {     "TO SEND THE FILE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_NO_TESTS_AVAILABLE */
    { {18,3,3,3,3},
      {     "NO TESTS AVAILABLE",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 

	/* str_TO_SYNC */
    { {8,3,3,3,3},
      {     "TO SYNC!",	    // English 
            "FOO",	    				// French
            "BAR",      				// German 
            "NOO",      				// Italian
            "BAZ"      				// Spanish
		} }, 
		
		
/*#######################################################################*
 * UI_DATE_AND_TIME
 *#######################################################################*/     
 /* str_DATE */
    { {4,3,3,3,3},
      {     "DATE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
    /* str_TIME_FORMAT */
    { {11,3,3,3,3},
      {     "TIME FORMAT",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
    /* str_TIME_ZONE */
    { {9,3,3,3,3},
      {     "TIME ZONE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_TIME */
    { {4,3,3,3,3},
      {     "TIME",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_ZONE */
    { {4,3,3,3,3},
      {     "ZONE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DAYLIGHT_SAVINGS_TIME_1 */
    { {8,3,3,3,3},
      {     "DAYLIGHT",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DAYLIGHT_SAVINGS_TIME_2 */
    { {12,3,3,3,3},
      {     "SAVINGS TIME",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
    
/*#######################################################################*
 * TIME ZONE lists                                                       *
 *#######################################################################*/     
 /* str_ADELAIDE */
    { {8,3,3,3,3},
      {     "ADELAIDE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_ALMATY */
    { {6,3,3,3,3},
      {     "ALMATY",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_AUCKLAND */
    { {8,3,3,3,3},
      {     "AUCKLAND",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_BANGKOK */
    { {7,3,3,3,3},
      {     "BANGKOK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_BOMBAY */
    { {6,3,3,3,3},
      {     "BOMBAY",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_BRASILIA */
    { {8,3,3,3,3},
      {     "BRASILIA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_BRISBANE */
    { {8,3,3,3,3},
      {     "BRISBANE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_CAIRO */
    { {5,3,3,3,3},
      {     "CAIRO",	  // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_CAPE_TOWN */
    { {9,3,3,3,3},
      {     "CAPE TOWN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_CAPE_VERDE */
    { {10,3,3,3,3},
      {     "CAPE VERDE",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_CHITA */
    { {5,3,3,3,3},
      {     "CHITA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_DARWIN */
    { {6,3,3,3,3},
      {     "DARWIN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_EKATERINBURG */
    { {12,3,3,3,3},
      {     "EKATERINBURG",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_EU_CENTRAL */
    { {10,3,3,3,3},
      {     "EU-CENTRAL",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
	/* str_EU_EASTERN */
    { {10,3,3,3,3},
      {     "EU-EASTERN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_EU_WESTERN */
    { {10,3,3,3,3},
      {     "EU_WESTERN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_FIJI */ 
    { {4,3,3,3,3},
      {     "FIJI",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_HONG_KONG */
    { {9,3,3,3,3},
      {     "HONG KONG",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_ICELAND */
    { {7,3,3,3,3},
      {     "ICELAND",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_ISLAMABAD */
    { {9,3,3,3,3},
      {     "ISLAMABAD",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_JAKARTA */
    { {7,3,3,3,3},
      {     "JAKARTA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
	/* str_KABUL */
    { {5,3,3,3,3},
      {     "KABUL",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_KALININGRAD */
    { {11,3,3,3,3},
      {     "KALININGRAD",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
	/* str_KATHMANDU */
    { {9,3,3,3,3},
      {     "KATHMANDU",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_KRASNOYARSK */
    { {11,3,3,3,3},
      {     "KRASNOYARSK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_LAGOS */
    { {5,3,3,3,3},
      {     "LAGOS",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_MAGADAN */
    { {7,3,3,3,3},
      {     "MAGADAN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_MEX_CENTRAL */
    { {11,3,3,3,3},
      {     "MEX-CENTRAL",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_MEX_MOUNTAIN */
    { {12,3,3,3,3},
      {     "MEX-MOUNTAIN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
		
	/* str_MEX_PACIFIC */
    { {11,3,3,3,3},
      {     "MEX-PACIFIC",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_MOSCOW */
    { {6,3,3,3,3},
      {     "MOSCOW",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_MUSCAT */
    { {6,3,3,3,3},
      {     "MUSCAT",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_NEWFOUNDLAND */
    { {12,3,3,3,3},
      {     "NEWFOUNDLAND",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_NOVOSIBIRSK */
    { {11,3,3,3,3},
      {     "NOVOSIBIRSK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_PERTH */
    { {5,3,3,3,3},
      {     "PERTH",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_PETROPAVLOVSK */
    { {14,3,3,3,3},
      {     "PETROPAVLOVSK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_RIYADH */
    { {6,3,3,3,3},
      {     "RIYADH",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_SAMARA */ 
    { {6,3,3,3,3},
      {     "SAMARA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_SAMOA */
    { {5,3,3,3,3},
      {     "SAMOA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_SYDNEY */
    { {6,3,3,3,3},
      {     "SYDNEY",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_TASMANIA */
    { {8,3,3,3,3},
      {     "TASMANA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_TEHRAN */
    { {6,3,3,3,3},
      {     "TEHRAN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_TOKYO */
    { {5,3,3,3,3},
      {     "TOKYO",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_ALASKA */ 
    { {6,3,3,3,3},
      {     "US-ALASKA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_ARIZONA */
    { {10,3,3,3,3},
      {     "US-ARIZONA",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_ATLANTIC */
    { {11,3,3,3,3},
      {     "US-ATLANTIC",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_CENTRAL */
    { {10,3,3,3,3},
      {     "US-CENTRAL",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_EASTERN */
    { {10,3,3,3,3},
      {     "US-EASTERN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_HAWAII */
    { {9,3,3,3,3},
      {     "US-HAWAII",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_US_MOUNTAIN */
    { {11,3,3,3,3},
      {     "US-MOUNTAIN",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
	
	/* str_US_PACIFIC */
    { {10,3,3,3,3},
      {     "US-PACIFIC",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_VLADIVOSTOK */
    { {11,3,3,3,3},
      {     "VLADIVOSTOK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

	/* str_WINDHOEK */
    { {8,3,3,3,3},
      {     "WINDHOEK",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

/*#######################################################################*
 * Secret Sensor output menu                                             *
 *#######################################################################*/
    /* str_SENSOR_OUTPUT*/
    { {13,3,3,3,3},
      {     "SENSOR OUTPUT",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_PRESSURE */
    { {9,3,3,3,3},
      {     "PRESSURE:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_DEPTH */
    { {6,3,3,3,3},
      {     "DEPTH:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_EYE */
    { {4,3,3,3,3},
      {     "EYE:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 


    /* str_ROS_1 */
    { {6,3,3,3,3},
      {     "ROS 1:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_ROS_2 */
    { {6,3,3,3,3},
      {     "ROS 2:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 

    /* str_TILT */
    { {5,3,3,3,3},
      {     "TILT:",	    // English 
            "FOO",	    // French
            "BAR",      // German 
            "NOO",      // Italian
            "BAZ"      // Spanish
		} }, 
}; // end string_array[]


char const* getString(SP2_STRING_T string_index);
uint16_t const getStringSize(SP2_STRING_T string_index);
void stringTest(void);



#endif // SP2_STRING_H_
