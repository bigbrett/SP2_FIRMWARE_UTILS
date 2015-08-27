#ifndef SP2_STRING_H_
#define SP2_STRING_H_

//#include "common_headers.h"
#include <mqx.h>
#include <bsp.h>
#include <fio.h>
#include "config.h"

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
    str_BACK_LIGHT,
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
    str_ROS1,
    str_ROS2,
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
    		"SELECTIONNER",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"ESCOGER"      // Spanish
    } },

    /* str_BACK */ 
    { {4,3,3,3,3},
      {     "BACK",	    // English 
            "RETOUR",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "REGRESAR"      // Spanish
    } },

    /* str_NEXT */  
	{ {4,3,3,3,3},
      {		"NEXT",	// English 
    		"SUIVANT",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"PROXIMO"      // Spanish
    } },

    /* str_MENU */ 
    { {4,3,3,3,3},
      {     "MENU",	    // English 
            "MENU",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "MENU"      // Spanish
		} }, 

    /* str_OPTIONS */
    { {7,3,3,3,3},
      {     "OPTIONS",	// English 
            "OPTIONS",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "OPCIONES"      // Spanish
		} }, 

    /* str_DELETE */ 
    { {6,3,3,3,3},
      {     "DELETE",	  // English 
            "SUPPRIMER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "BORRAR"      // Spanish
		} }, 

    /* str_DISCARD */ 
    { {7,3,3,3,3},
      {     "DISCARD",	  // English 
            "ABANDONNER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "DESECHAR"      // Spanish
		} }, 

    /* str_DETAIL */
    { {6,3,3,3,3},
      {     "DETAIL",	  // English 
            "DETAIL",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "DETALLE"      // Spanish
		} }, 

    /* str_GPS */
    { {3,3,3,3,3},
      {     "GPS",	    // English 
            "GPS",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "GPS"      // Spanish
		} }, 

    /* str_GPS_COLON */
    { {4,3,3,3,3},
      {     "GPS:",	    // English 
            "GPS:",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "GPS:"      // Spanish
		} }, 

    /* str_SLOPE */
    { {5,3,3,3,3},
      {     "SLOPE",    // English 
            "PENTE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "INCLINACION"      // Spanish
		} }, 

	/* str_FAVORITE */
    { {8,3,3,3,3},
      {     "FAVORITE",	// English 
            "FAVORI",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "FAVORITO"      // Spanish
		} }, 

    /* str_CANCEL */
    { {6,3,3,3,3},
      {     "CANCEL",	  // English 
            "ANNULER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "CANCELAR"      // Spanish
		} }, 

	/* str_START */
	{ {5,3,3,3,3},
      {     "START", // English
			"COMMENCER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "INICIAR"      // Spanish
		} },

	/* str_RETRY */ 
	{ {5,3,3,3,3},
      {     "RETRY", // ENGLISH
			"RE-ESSAYER",	 // French
			"DEU",   // GERMAN
			"ITA", 	// Italian
			"REINTENTAR"	 // Spanish
		} },
		
    /* str_ON */ 
    { {2,3,3,3,3},
      {     "ON",		    // English 
            "ALLUME",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "PRENDER"      // Spanish
		} }, 

    /* str_OFF */
    { {3,3,3,3,3},
      {     "OFF",	    // English 
            "ETEINT",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "APAGAR"      // Spanish
		} }, 

    /* str_OK */
    { {2,3,3,3,3},
      {     "OK",	    // English 
            "OK",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "OK"      // Spanish
		} }, 

    /* str_NOT_APPLICABLE */
    { {3,3,3,3,3},
      {     "N/A",	    // English 
            "S.O.",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "N/A"      // Spanish
		} }, 

    /* str_SAVE*/
    { {4,3,3,3,3},
      {     "SAVE",	    // English 
            "SAUVEGARDER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "GUARDAR"      // Spanish
		} }, 

/*#######################################################################*
 *  UI_MAINMENU_LIST menu items                                          * 
 *#######################################################################*/
    /* str_NEW_TEST */
    { {8,3,3,3,3},
      {     "NEW TEST",	// English 
            "NOUVEAU TEST",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "NUEVA PRUEBA"      // Spanish
		} }, 

    /* str_SNOW_PROFILES */
    { {13,3,3,3,3},
      {     "SNOW PROFILES",	// English 
            "PROFILS DE NEIGE",	    			// French
            "DEU",      			// German 
            "ITA",      			// Italian
            "PREFILES DE NIEVE"      			// Spanish
		} }, 

    /* str_FAVORITES */
    { {15,3,3,3,3},
      {     "FAVORITES", 	// English 
            "FAVORIS",	    	// French
            "DEU",      	// German 
            "ITA",      	// Italian
            "FAVORITOS"      	// Spanish
		} }, 

    /* str_SETTINGS */
    { {8,3,3,3,3},
      {     "SETTINGS",	// English 
            "REGLAGES",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "AJUSTES"      // Spanish
		} }, 

		
	/* str_MASS_STORAGE */ 
    { {12,3,3,3,3},
      {     "MASS STORAGE",	// English 
            "STOCKAGE DE MASSE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "ALMACENAMIENTO MASIVO"      // Spanish
		} }, 

	/* str_BLUETOOTH_TRANSFER */ 
    { {18,3,3,3,3},
      {     "BLUETOOTH TRANSFER",	// English 
            "TRANSFER BLUETOOTH",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "TRANSFERENCIA BLUETOOTH"      // Spanish
		} }, 
           
    /* str_NEW_SNOW_PROFILE */
    { {16,3,3,3,3},
      {     "NEW SNOW PROFILE",	// English 
            "NOUVEAU PROFIL DE NEIGE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "NUEVA PERFIL DE NIEVE"      // Spanish
		} }, 

    /* str_SLOPE_MEASUREMENT*/
    { {17,3,3,3,3},
      {     "SLOPE MEASUREMENT",	// English 
            "MESURE DE PENTE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "MEDICIÓN DE INCLINACION"      // Spanish
		} }, 

    /* str_SETTINGS_SEL */
    { {12,3,3,3,3},
      {     "SETTINGS SEL",	    // English 
            "SELECTION DES REGLAGES",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "AJUSTES SEL"      // Spanish
		} }, 

    /* str_CONFIG_SETTINGS*/
    { {15,3,3,3,3},
      {     "CONFIG SETTINGS",	    // English 
            "CONFIGURATION DES REGLAGES",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "CONFIGURAR LOS AJUSTES"      // Spanish
		} }, 

	/* str_SETTINGS_MENU */
    { {13,3,3,3,3},
      {     "SETTINGS MENU",	    // English 
            "MENU DES REGLAGES",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "MENU DE AJUSTES"      // Spanish
		} }, 

/*#######################################################################*
 *  File/Folder deletion prompts 
 *#######################################################################*/
    /* str_DELETE_TEST */
    { {12,3,3,3,3},
      {     "DELETE TEST?",	// English 
            "EFFACER LE TEST?",	    	// French
            "DEU",      	// German 
            "ITA",      	// Italian
            "BORRAR PRUEBA?"      	// Spanish
		} }, 

    /* str_DELETE_ALL */
    { {10,3,3,3,3},
      {     "DELETE ALL",	// English 
            "TOUT EFFACER",	    	// French
            "DEU",      	// German 
            "ITA",      	// Italian
            "BORRAR TODOS"      	// Spanish
		} }, 

    /* str_DELETE_ALL_TESTS */
    { {16,3,3,3,3},
      {     "DELETE ALL TESTS",	// English 
            "EFFACER TOUS LES TESTS",	    	// French
            "DEU",      	// German 
            "ITA",      	// Italian
            "BORRAR TODAS PRUEBAS"      	// Spanish
		} }, 

    /* str_IN_THIS_FOLDER*/
    { {15,3,3,3,3},
      {     "IN THIS FOLDER?",	// English 
            "DANS CE REPERTOIRE?",	    	// French
            "DEU",      	// German 
            "ITA",      	// Italian
            "EN ESTA CARPETA?"      	// Spanish
		} }, 


    /* str_DELETE_FILE_PROMPT */
    { {12,3,3,3,3},
      {     "DELETE FILE?",	    // English 
            "EFFACER LE FICHIER?",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "BORRAR CARPETA?"      				// Spanish
		} }, 

    /* str_DELETE_ALL_IN_FOLDER_PROMPT */
    { {21,3,3,3,3},
      {     "DELETE ALL IN FOLDER?",	    // English 
            "TOUT EFFACER DANS LE REPERTOIRE?",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "BORRAR TODO EN CARPETA?"      // Spanish
		} }, 

    /* str_DELETING_FOLDER_PROMPT */
    { {18,3,3,3,3},
      {     "DELETING FOLDER...",	    // English 
            "EFFACEMENT DU REPERTOIRE…",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "BORRANDO CARPETA"      // Spanish
		} }, 


/*#######################################################################*
 * USER TESTING STRINGS
 *#######################################################################*/
	/* str_ALIGN_PROBE */ 
	{ {6,3,3,3,3},
      {     "ALIGN PROBE", 	// english
            "ALIGNER LA SONDE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "ALINEAR EXPLORADOR"      // Spanish
	} },  
	
	/* str_PRESS */ 
	{ {5,3,3,3,3},
      {     "PRESS", // ENGLISH
            "APPUYER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "PRESIONAR"      // Spanish
	} },
	
	/* str_TO_BEGIN*/ 
	{ {8,3,3,3,3},
      {     "TO BEGIN", // ENGLISH
            "POUR COMMENCER A CALIBRER",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "EMPEZAR"      // Spanish
	} },
	
	/* str_CALIBRATING */
	{ {13,3,3,3,3},
      {     "  CALIBRATING", // ENGLISH
            "  CALIBRAGE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "  CALIBRACION"      // Spanish
	} },

	/* str_COLLECTING_DATA */ 
	{ {8,3,3,3,3},
      {     "COLLECTING DATA", // ENGLISH
            "COLLECTION DES DONNEES",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "COLECTANDO DATOS"      // Spanish
	} },

/*#######################################################################*
 *  Calibration screens                                                  * 
 *#######################################################################*/	
	/* str_COMPASS_CALIBRATION */
	{ {19,3,3,3,3},
      {     "COMPASS CALIBRATION",  // English 
			"CALIBREMENT DE LA BOUSSOLE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "CALIBRACION DE LA BRÚJULA"      			// Spanish
	} },

	/* str_GPS_LOCK_ACQUIRED */
	{ {18,3,3,3,3},
      {     "GPS LOCK ACQUIRED!",  // English 
			"SATELLITES GPS ACQUIS",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "GPS ADQUIRIDO"      			// Spanish
	} },
	
	/* str_GPS_INFORMATION */
	{ {15,3,3,3,3},
      {     "GPS INFORMATION",  // English 
			"INFORMATION GPS",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "INFORMACION GPS"      			// Spanish
	} },
	
	/* str_ACQUIRED*/
	{ {9,3,3,3,3},
      {     "ACQUIRED!",  // English 
			"ACQUIS!",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ADQUIRIDO"      			// Spanish
	} },
	
	/* str_PLEASE_ENTER_THE */
	{ {16,3,3,3,3},
      {     "PLEASE ENTER THE",  // English 
			"SVP ENTRER LE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "FAVOR DE ENTRAR"      			// Spanish
	} },

	/* str_ENTER */
	{ {5,3,3,3,3},
      {     "ENTER",  // English 
			"ENTRER ",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ENTRAR"      			// Spanish
	} },

	/* str_MANUAL_ENTRY */
	{ {12,3,3,3,3},
      {     "MANUAL ENTRY",  // English 
			"MANUELLE ENTRER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ENTRADA MANUAL"      			// Spanish
	} },

	/* str_ASPECT */
	{ {6,3,3,3,3},
      {     "ASPECT",  // English 
			"ASPECT",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ASPECTO"      			// Spanish
	} },

/*#######################################################################*
/*#######################################################################*
 *  Test errors, warning messages, and user feedback                     *  
 *#######################################################################*/ 
	/* str_ERROR */
	{ {5,3,3,3,3},
      {     "ERROR",  // English 
	        "ERREUR",	    			// French
	        "DEU",      			// German 
	        "ITA",      			// Italian
	        "ERROR"      			// Spanish
	} }, 

	/* str_REMOVE_SDCARD*/
	{ {13,3,3,3,3},
      {     "REMOVE SDCARD",  // English 
			"RETIRER LA SDCARD",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "RETIRAR LA TARJETA SD"      			// Spanish
	} },

    /* str_PLEASE_INSERT */
	{ {13,3,3,3,3},
      {     "PLEASE INSERT",  // English 
			"SVP INSERER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "FAVOR DE INSERTAR"      			// Spanish
	} },

    /* str_A_VALID_SDCARD */
	{ {14,3,3,3,3},
      {     "A VALID SDCARD",  // English 
			"UNE SDCARD VALIDE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "VALIDO TARJETA SD"      			// Spanish
	} },

    /* str_TO_THE_DEVICE */
	{ {13,3,3,3,3},
      {     "TO THE DEVICE",  // English 
			"DANS L’APPAREIL",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "AL APARATO"      			// Spanish
	} },    

	/* str_REBOOTING*/
	{ {9,3,3,3,3},
      {     "REBOOTING",  // English 
			"REDEMARRAGE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "REINICIENDO"      			// Spanish
	} },


	/* str_REBOOTING_ELIPSES*/
	{ {12,3,3,3,3},
      {     "REBOOTING...",  // English 
			"REDEMARRAGE...",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "REINICIENDO..."      			// Spanish
	} },

	/* str_REBOOT*/
	{ {6,3,3,3,3},
      {     "REBOOT",  // English 
			"REDEMARRER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "REINICIO"      			// Spanish
	} },
	
	/* str_SW_REBOOT*/
	{ {9,3,3,3,3},
      {     "SW REBOOT",  // English 
			"REDEMARRAGE DU LOGICIEL",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "REINICIO DE SOFTWARE"      			// Spanish
	} },
	
	/* str_FIRMWARE_UPDATE */ 
	{ {15,3,3,3,3},
      {     "FIRMWARE UPDATE",  // English 
			"MISE A JOUR DU FIRMWARE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "FIRMWARE ACTUALIZADA"      			// Spanish
	} },

    /* str_FAILED */
	{ {8,3,3,3,3},
      {     "  FAILED",  // English 
			"  ECHOUE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "  FALTA"      			// Spanish
	} },

    /* str_PLEASE */
	{ {8,3,3,3,3},
      {     "  PLEASE",  // English 
			"  SVP",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "  POR FAVOR"      			// Spanish
	} },

    /* str_RECONNECT_TO_PC */
	{ {15,3,3,3,3},
      {     "RECONNECT TO PC",  // English 
			"RECONNECTER AU PC",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "VOLVER DE CONECTAR AL PC"      			// Spanish
	} },

    /* str_AND_TRY_AGAIN */
	{ {14,3,3,3,3},
      {     " AND TRY AGAIN",  // English 
			"ET ESSAYER DE NOUVEAU",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "INTENTAR OTRA VEZ"      			// Spanish
	} },

	/* str_NEW_FIRMWARE */
	{ {12,3,3,3,3},
      {     "NEW FIRMWARE",  // English 
			"NOUVEAU FIRMWARE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "FIRMWARE NUEVA"      			// Spanish
	} },

    /* str_DETECTED */
	{ {10,3,3,3,3},
      {     "  DETECTED",  // English 
			"  DETECTE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "  DETECTADO"      			// Spanish
	} },

	/* str_PRESS_SELECT */
	{ {12,3,3,3,3},
      {     "PRESS SELECT",  // English 
			"PRESSE SELECTIONNER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "PRESIONAR ESCOGER"      			// Spanish
	} },

	/* str_TO_REBOOT */
	{ {11,3,3,3,3},
      {     "  TO REBOOT",  // English 
			"  POUR REDEMARRER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "  REINICIAR"      			// Spanish
	} },

	/* str_VALIDATING */
	{ {12,3,3,3,3},
      {     "  VALIDATING",  // English 
			"  VALIDATION",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "  VALIDANDO"      			// Spanish
	} },	    
	
	/* str_GRAPH_CUT_AT_PAUSE */ 
	{ {18,3,3,3,3},
      {     "GRAPH CUT AT PAUSE",  // English 
			"FOO",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "RECORTA GRAFICO EN PAUSA"      			// Spanish
	} },
	
	/* str_ARE_YOU_SURE_YOU */
	{ {16,3,3,3,3},
      {     "ARE YOU SURE YOU",  // English 
			"ETES VOUS SUR",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ESTAS SEGURO DE"      			// Spanish
	} },

	/* str_WANT_TO_DELETE */
	{ {14,3,3,3,3},
      {     "WANT TO DELETE",  // English 
			"DE VOULOIR EFFACER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "QUIERES BORRAR"      			// Spanish
	} },

	/* str_WANT_TO_DISCARD */
	{ {15,3,3,3,3},
      {     "WANT TO DISCARD",  // English 
			"DE VOULOIR ABANDONNER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "QUIERES DESECHAR"      			// Spanish
	} },
    
	/* str_THIS_TEST */
	{ {10,3,3,3,3},
      {     "THIS TEST?",  // English 
			"CE TEST?",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ESTA PRUEBA"      			// Spanish
	} },

   /* str_PROCESSING_DATA */
	{ {15,3,3,3,3},
      {     "PROCESSING DATA",  // English 
			"TRAITEMENT DES DONNEES",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "PROCESANDO DATOS"      			// Spanish
	} },
	
	/* str_PLEASE_WAIT_ELIPSES */
	{ {14,3,3,3,3},
      {     "PLEASE WAIT...",  // English 
			"ATTENDEZ SVP",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ESPERA POR FAVOR..."      			// Spanish
	} },

  /*  str_PLEASE_WAIT */
	{ {11,3,3,3,3},
      {     "PLEASE WAIT",  // English 
			"ATTENDER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ESPERA POR FAVOR"      			// Spanish
	} },

  /*  str_WHILE_READING */
	{ {13,3,3,3,3},
      {     "WHILE READING",  // English 
			"QUE LES DONNEES SOIENT LUES",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "MIENTRAS LEYENDO"      			// Spanish
	} },

  /*  str_THE_RECORD */
	{ {10,3,3,3,3},
      {     "THE RECORD",  // English 
			"LE RECORD",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "EL RECORD"      			// Spanish
	} },

  /*  str_READING_RECORD */
	{ {14,3,3,3,3},
      {     "READING RECORD",  // English 
			"LECTURE DES RECORD ",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "LEYENDO RECORD "      			// Spanish
	} },

  /*  str_LINK */
	{ {4,3,3,3,3},
      {     "LINK",  // English 
			"LIER",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ENLAZAR "      			// Spanish
	} },
 
  /*  str_LINK_SNOW_PROFILE */
	{ {17,3,3,3,3},
      {     "LINK SNOW PROFILE",  // English 
			"LIER LE PROFILE DE NEIGE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ENLAZAR PERFIL DE NIEVE"      			// Spanish
	} },
 
  /*  str_ENTER_PASSWORD */
	{ {14,3,3,3,3},
      {     "ENTER PASSWORD",  // English 
			"ENTRER LE MOT DE PASSE",	    			// French
		    "DEU",      			// German 
		    "ITA",      			// Italian
		    "ENTRAR CONTRASENA"      			// Spanish
	} },

	
    /* str_DAILY_TEST_LIMIT */  
	{ {16,3,3,3,3},
      {		"DAILY TEST LIMIT",	// English 
    		"LIMITE DE 254 ",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"LIMITE DE PRUEBAS"      // Spanish
    } },

    /* str_OF_DT_NUM_REACHED */  
	{ {17,3,3,3,3},
      {		"OF 254 REACHED!!!",	// English 
    		"TESTS JOURNALIER ATTEINTE",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"DE 254 ALCANZADO"      // Spanish
    } },

    /* str_FAVORITE_LIMIT_OF*/  
	{ {17,3,3,3,3},
      {		"FAVORITE LIMIT OF",	// English 
    		"LIMITE DE 64",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"LIMITE DE FAVORITOS"      // Spanish
    } },

    /* str_FAV_NUM_REACHED */  
	{ {11,3,3,3,3},
      {		"64 REACHED!",	// English 
    		"TESTS JOURNALIER ATTEINTE",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"64 ALCANZADO"      // Spanish
    } },

    /* str_EDITING_DISABLED */  
	{ {16,3,3,3,3},
      {		"EDITING DISABLED ",	// English 
    		"EDITION DESACTIVEE",  	// French
    		"DEU",      // German 
    		"ITA",      // Italian 
    		"EDITACION APAGADO"      // Spanish
    } },
     //TODO 

     //TODO 

/*#######################################################################*
 * UI_SETTINGS menu items  
 *#######################################################################*/ 
    /* str_DATE_AND_TIME */
    { {13,3,3,3,3},
      {     "DATE AND TIME",  // English 
            "DATE ET HEURE",	    			// French
            "DEU",      			// German 
            "ITA",      			// Italian
            "FECHA Y HORA"      			// Spanish
		} }, 

    /* str_BLUETOOTH */
    { {9,3,3,3,3},
      {     "BLUETOOTH",// English 
            "BLUETOOTH",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "BLUETOOTH"      // Spanish
		} }, 

    /* str_INITIALIZING_BLUETOOTH */
    { {22,3,3,3,3},
      {     "INITIALIZING BLUETOOTH",  // English 
            "INITIALISATION BLUETOOTH",	    						   // French
            "DEU",      						   // German 
            "ITA",      						   // Italian
            "INICIANDO BLUETOOTH"      						   // Spanish
		} }, 

	    /* str_BACK_LIGHT */
	    { {10,3,3,3,3},
	      {     "BACK LIGHT",	    // English 
	            "poop",	    				// French
	            "poop",      				// German 
	            "poop",      				// Italian
	            "LUZ"      				// Spanish
			} },
			
    /* str_GRAPH_DETAIL */
    { {12,3,3,3,3},
      {     "GRAPH DETAIL",	    // English 
            "DETAIL GRAPHE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO"      				// Spanish
		} }, 
		
		
		
	/* str_GRAPH_DETAIL_0 */
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 0",	    // English 
            "DETAIL GRAPHE 0",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO 0"      				// Spanish
		} }, 

    /* str_GRAPH_DETAIL 1*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 1",	    // English 
            "DETAIL GRAPHE 1",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO 1"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 2 */
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 2",	    // English 
            "DETAIL GRAPHE 2",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO 2"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 3*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 3",	    // English 
            "DETAIL GRAPHE 3",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO 3"      				// Spanish
		} }, 
    /* str_GRAPH_DETAIL 4*/
    { {14,3,3,3,3},
      {     "GRAPH DETAIL 4",	    // English 
            "DETAIL GRAPHE 4",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETALLE GRAFICO 4"      				// Spanish
		} }, 

    /* str_LANGUAGE */
    { {8,3,3,3,3},
      {     "LANGUAGE",	    // English 
            "LANGUE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "IDIOMA"      				// Spanish
		} }, 
    
    /* str_TESTS_REQUIRE_SLOPE */
    { {14,3,3,3,3},
      {     "REQUIRE SLOPE",	    // English 
            "PENTE OBLIGATOIRE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "EXIGIR INCLINACION"      				// Spanish
		} }, 
    
	/* str_ABOUT_DEVICE */
    { {12,3,3,3,3},
      {     "ABOUT DEVICE",	    // English 
            "A PROPOS DE L'APPAREIL",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "INFORMACION DEL APARATO"      				// Spanish
		} }, 

/*#######################################################################*
* Bluetooth main content 												 *
/*#######################################################################*/     
	/* str_INITIALIZING */
    { {12,3,3,3,3},
      {     "INITIALIZING",	    // English 
            "INITIALISATION",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "INICIANDO"      				// Spanish
		} }, 

	/* str_THE_DEVICE_IS_NOW */
    { {17,3,3,3,3},
      {     "THE DEVICE IS NOW",	    // English 
            "L'APPAREIL EST MAINTENANT DECOUVRABLE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "EL APARATO ESTA "      				// Spanish
		} }, 

	/* str_DISCOVERABLE */
    { {12,3,3,3,3},
      {     "DISCOVERABLE.",	    // English 
            "FOO",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "DETECTABLE"      				// Spanish
		} }, 

	/* str_PLEASE_CONNECT */
    { {14,3,3,3,3},
      {     "PLEASE CONNECT",	    // English 
            "CONNECTER VOTRE ",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "FAVOR DE CONECTAR"      				// Spanish
		} }, 

	/* str_YOUR_DEVICE */
    { {11,3,3,3,3},
      {     "YOUR DEVICE",	    // English 
            "APPAREIL SVP",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "TU APARATO"      				// Spanish
		} }, 

	/* str_CONNECTED */
    { {9,3,3,3,3},
      {     "CONNECTED",	    // English 
            "CONNECTE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "CONECTADO"      				// Spanish
		} }, 

	/* str_PREPARING_TO_SYNC */
    { {17,3,3,3,3},
      {     "PREPARING TO SYNC",	    // English 
            "PREPARATION DE LA SYNCHRONISATION",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "PREPARANDO PARA SINCRONIZAR"      				// Spanish
		} }, 

	/* str_SYNCING */
    { {7,3,3,3,3},
      {     "SYNCING",	    // English 
            "SYNCHRONISATION",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "SINCRONIZANDO"      				// Spanish
		} }, 
		
	/* str_SYNC_COMPLETE */
    { {14,3,3,3,3},
      {     "SYNC COMPLETE!",	    // English 
            "SYNCHRONISATION COMPLETEE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "SINCRONIZADO!"      				// Spanish
		} }, 

	/* str_SYNC_FAILED */
    { {12,3,3,3,3},
      {     "SYNC FAILED!",	    // English 
            "SYNCHRONISATION ECHOUEE",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "SYNC FALLO!"      				// Spanish
		} }, 

	/* str_PLEASE_TRY_AGAIN */
    { {16,3,3,3,3},
      {     "PLEASE TRY AGAIN",	    // English 
            "ESSAYER DE NOUVEAU SVP",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "FAVOR DE INTENTAR OTRA VEZ"      				// Spanish
		} }, 

	/* str_PLEASE_TURN */
    { {11,3,3,3,3},
      {     "PLEASE TURN",	    // English 
            "ALLUMER BLUETOOTH ",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "FAVOR DE "      				// Spanish
		} }, 

	/* str_ON_BLUETOOTH */
    { {12,3,3,3,3},
      {     "ON BLUETOOTH",	    // English 
            "POUR ENVOYER",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "APAGAR BLUETOOTH"      				// Spanish
		} }, 

	/* str_TO_SEND_THE_FILE */
    { {16,3,3,3,3},
      {     "TO SEND THE FILE",	    // English 
            "LE FICHIER",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "PARA ENVIAR LA CARPETA"      				// Spanish
		} }, 

	/* str_NO_TESTS_AVAILABLE */
    { {18,3,3,3,3},
      {     "NO TESTS AVAILABLE",	    // English 
            "A SYNCHRONISER",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "NO HAY PRUEBAS DISPONIBLES"      				// Spanish
		} }, 

	/* str_TO_SYNC */
    { {8,3,3,3,3},
      {     "TO SYNC!",	    // English 
            "AUCUN TEST ",	    				// French
            "DEU",      				// German 
            "ITA",      				// Italian
            "PARA SINCRONIZAR!"      				// Spanish
		} }, 
		
		
/*#######################################################################*
 * UI_DATE_AND_TIME
 *#######################################################################*/     
 /* str_DATE */
    { {4,3,3,3,3},
      {     "DATE",	    // English 
            "DATE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "FECHA"      // Spanish
		} }, 
		
    /* str_TIME_FORMAT */
    { {11,3,3,3,3},
      {     "TIME FORMAT",	    // English 
            "FORMAT DE LHEURE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "FORMATO HORARIO"      // Spanish
		} }, 
		
    /* str_TIME_ZONE */
    { {9,3,3,3,3},
      {     "TIME ZONE",	    // English 
            "FUSEAU HORAIRE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "ZONA HORARIA"      // Spanish
		} }, 

    /* str_TIME */
    { {4,3,3,3,3},
      {     "TIME",	    // English 
            "HEURE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "HORA"      // Spanish
		} }, 

    /* str_ZONE */
    { {4,3,3,3,3},
      {     "ZONE",	    // English 
            "FUSEAU",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "ZONA"      // Spanish
		} }, 

    /* str_DAYLIGHT_SAVINGS_TIME_1 */
    { {8,3,3,3,3},
      {     "DAYLIGHT",	    // English 
            "L'HEURE ",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "EL HORARIO"      // Spanish
		} }, 

    /* str_DAYLIGHT_SAVINGS_TIME_2 */
    { {12,3,3,3,3},
      {     "SAVINGS TIME",	    // English 
            "D'ETE",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "DE VERANO "      // Spanish
		} }, 
    
/*#######################################################################*
 * TIME ZONE lists                                                       *
 *#######################################################################*/     
 /* str_ADELAIDE */
    { {8,3,3,3,3},
      {     "ADELAIDE",	    // English 
            "ADELAIDE",	    // French
            "ADELAIDE",      // German 
            "ADELAIDE",      // Italian
            "ADELAIDE"      // Spanish
		} }, 

	/* str_ALMATY */
    { {6,3,3,3,3},
      {     "ALMATY",	    // English 
            "ALMATY",	    // French
            "ALMATY",      // German 
            "ALMATY",      // Italian
            "ALMATY"      // Spanish
		} }, 

	/* str_AUCKLAND */
    { {8,3,3,3,3},
      {     "AUCKLAND",	    // English 
            "AUCKLAND",	    // French
            "AUCKLAND",      // German 
            "AUCKLAND",      // Italian
            "AUCKLAND"      // Spanish
		} }, 

	/* str_BANGKOK */
    { {7,3,3,3,3},
      {     "BANGKOK",	    // English 
            "BANGKOK",	    // French
            "BANGKOK",      // German 
            "BANGKOK",      // Italian
            "BANGKOK"      // Spanish
		} }, 

	/* str_BOMBAY */
    { {6,3,3,3,3},
      {     "BOMBAY",	    // English 
            "BOMBAY",	    // French
            "BOMBAY",      // German 
            "BOMBAY",      // Italian
            "BOMBAY"      // Spanish
		} }, 

	/* str_BRASILIA */
    { {8,3,3,3,3},
      {     "BRASILIA",	    // English 
            "BRASILIA",	    // French
            "BRASILIA",      // German 
            "BRASILIA",      // Italian
            "BRASILIA"      // Spanish
		} }, 

	/* str_BRISBANE */
    { {8,3,3,3,3},
      {     "BRISBANE",	    // English 
            "BRISBANE",	    // French
            "BRISBANE",      // German 
            "BRISBANE",      // Italian
            "BRISBANE"      // Spanish
		} }, 

	/* str_CAIRO */
    { {5,3,3,3,3},
      {     "CAIRO",	  // English 
            "CAIRO",	    // French
            "CAIRO",      // German 
            "CAIRO",      // Italian
            "CAIRO"      // Spanish
		} }, 

	/* str_CAPE_TOWN */
    { {9,3,3,3,3},
      {     "CAPE TOWN",	    // English 
            "CAPE TOWN",	    // French
            "CAPE TOWN",      // German 
            "CAPE TOWN",      // Italian
            "CAPE TOWN"      // Spanish
		} }, 

	/* str_CAPE_VERDE */
    { {10,3,3,3,3},
      {     "CAPE VERDE",	    // English 
            "CAPE VERDE",	    // French
            "CAPE VERDE",      // German 
            "CAPE VERDE",      // Italian
            "CAPE VERDE"      // Spanish
		} }, 

	/* str_CHITA */
    { {5,3,3,3,3},
      {     "CHITA",	    // English 
            "CHITA",	    // French
            "CHITA",      // German 
            "CHITA",      // Italian
            "CHITA"      // Spanish
		} }, 

	/* str_DARWIN */
    { {6,3,3,3,3},
      {     "DARWIN",	    // English 
            "DARWIN",	    // French
            "DARWIN",      // German 
            "DARWIN",      // Italian
            "DARWIN"      // Spanish
		} }, 

	/* str_EKATERINBURG */
    { {12,3,3,3,3},
      {     "EKATERINBURG",	    // English 
            "EKATERINBURG",	    // French
            "EKATERINBURG",      // German 
            "EKATERINBURG",      // Italian
            "EKATERINBURG"      // Spanish
		} }, 

	/* str_EU_CENTRAL */
    { {10,3,3,3,3},
      {     "EU-CENTRAL",	    // English 
            "EU-CENTRAL",	    // French
            "EU-CENTRAL",      // German 
            "EU-CENTRAL",      // Italian
            "EU-CENTRAL"      // Spanish
		} }, 
		
	/* str_EU_EASTERN */
    { {10,3,3,3,3},
      {     "EU-EASTERN",	    // English 
            "EU-EASTERN",	    // French
            "EU-EASTERN",      // German 
            "EU-EASTERN",      // Italian
            "EU-EASTERN"      // Spanish
		} }, 

	/* str_EU_WESTERN */
    { {10,3,3,3,3},
      {     "EU-WESTERN",	    // English 
            "EU-WESTERN",	    // French
            "EU-WESTERN",      // German 
            "EU-WESTERN",      // Italian
            "EU-WESTERN"      // Spanish
		} }, 

	/* str_FIJI */ 
    { {4,3,3,3,3},
      {     "FIJI",	    // English 
            "FIJI",	    // French
            "FIJI",      // German 
            "FIJI",      // Italian
            "FIJI"      // Spanish
		} }, 

	/* str_HONG_KONG */
    { {9,3,3,3,3},
      {     "HONG KONG",	    // English 
            "HONG KONG",	    // French
            "HONG KONG",      // German 
            "HONG KONG",      // Italian
            "HONG KONG"      // Spanish
		} }, 

	/* str_ICELAND */
    { {7,3,3,3,3},
      {     "ICELAND",	    // English 
            "ICELAND",	    // French
            "ICELAND",      // German 
            "ICELAND",      // Italian
            "ICELAND"      // Spanish
		} }, 

	/* str_ISLAMABAD */
    { {9,3,3,3,3},
      {     "ISLAMABAD",	    // English 
            "ISLAMABAD",	    // French
            "ISLAMABAD",      // German 
            "ISLAMABAD",      // Italian
            "ISLAMABAD"      // Spanish
		} }, 

	/* str_JAKARTA */
    { {7,3,3,3,3},
      {     "JAKARTA",	    // English 
            "JAKARTA",	    // French
            "JAKARTA",      // German 
            "JAKARTA",      // Italian
            "JAKARTA"      // Spanish
		} }, 
		
	/* str_KABUL */
    { {5,3,3,3,3},
      {     "KABUL",	    // English 
            "KABUL",	    // French
            "KABUL",      // German 
            "KABUL",      // Italian
            "KABUL"      // Spanish
		} }, 

	/* str_KALININGRAD */
    { {11,3,3,3,3},
      {     "KALININGRAD",	    // English 
            "KALININGRAD",	    // French
            "KALININGRAD",      // German 
            "KALININGRAD",      // Italian
            "KALININGRAD"      // Spanish
		} }, 
		
	/* str_KATHMANDU */
    { {9,3,3,3,3},
      {     "KATHMANDU",	    // English 
            "KATHMANDU",	    // French
            "KATHMANDU",      // German 
            "KATHMANDU",      // Italian
            "KATHMANDU"      // Spanish
		} }, 

	/* str_KRASNOYARSK */
    { {11,3,3,3,3},
      {     "KRASNOYARSK",	    // English 
            "KRASNOYARSK",	    // French
            "KRASNOYARSK",      // German 
            "KRASNOYARSK",      // Italian
            "KRASNOYARSK"      // Spanish
		} }, 

	/* str_LAGOS */
    { {5,3,3,3,3},
      {     "LAGOS",	    // English 
            "LAGOS",	    // French
            "LAGOS",      // German 
            "LAGOS",      // Italian
            "LAGOS"      // Spanish
		} }, 

	/* str_MAGADAN */
    { {7,3,3,3,3},
      {     "MAGADAN",	    // English 
            "MAGADAN",	    // French
            "MAGADAN",      // German 
            "MAGADAN",      // Italian
            "MAGADAN"      // Spanish
		} }, 

	/* str_MEX_CENTRAL */
    { {11,3,3,3,3},
      {     "MEX-CENTRAL",	    // English 
            "MEX-CENTRAL",	    // French
            "MEX-CENTRAL",      // German 
            "MEX-CENTRAL",      // Italian
            "MEX-CENTRAL"      // Spanish
		} }, 

	/* str_MEX_MOUNTAIN */
    { {12,3,3,3,3},
      {     "MEX-MOUNTAIN",	    // English 
            "MEX-MOUNTAIN",	    // French
            "MEX-MOUNTAIN",      // German 
            "MEX-MOUNTAIN",      // Italian
            "MEX-MOUNTAIN"      // Spanish
		} }, 
		
	/* str_MEX_PACIFIC */
    { {11,3,3,3,3},
      {     "MEX-PACIFIC",	    // English 
            "MEX-PACIFIC",	    // French
            "MEX-PACIFIC",      // German 
            "MEX-PACIFIC",      // Italian
            "MEX-PACIFIC"      // Spanish
		} }, 

	/* str_MOSCOW */
    { {6,3,3,3,3},
      {     "MOSCOW",	    // English 
            "MOSCOW",	    // French
            "MOSCOW",      // German 
            "MOSCOW",      // Italian
            "MOSCOW"      // Spanish
		} }, 

	/* str_MUSCAT */
    { {6,3,3,3,3},
      {     "MUSCAT",	    // English 
            "MUSCAT",	    // French
            "MUSCAT",      // German 
            "MUSCAT",      // Italian
            "MUSCAT"      // Spanish
		} }, 

	/* str_NEWFOUNDLAND */
    { {12,3,3,3,3},
      {     "NEWFOUNDLAND",	    // English 
            "NEWFOUNDLAND",	    // French
            "NEWFOUNDLAND",      // German 
            "NEWFOUNDLAND",      // Italian
            "NEWFOUNDLAND"      // Spanish
		} }, 

	/* str_NOVOSIBIRSK */
    { {11,3,3,3,3},
      {     "NOVOSIBIRSK",	    // English 
            "NOVOSIBIRSK",	    // French
            "NOVOSIBIRSK",      // German 
            "NOVOSIBIRSK",      // Italian
            "NOVOSIBIRSK"      // Spanish
		} }, 

	/* str_PERTH */
    { {5,3,3,3,3},
      {     "PERTH",	    // English 
            "PERTH",	    // French
            "PERTH",      // German 
            "PERTH",      // Italian
            "PERTH"      // Spanish
		} }, 

	/* str_PETROPAVLOVSK */
    { {14,3,3,3,3},
      {     "PETROPAVLOVSK",	    // English 
            "PETROPAVLOVSK",	    // French
            "PETROPAVLOVSK",      // German 
            "PETROPAVLOVSK",      // Italian
            "PETROPAVLOVSK"      // Spanish
		} }, 

	/* str_RIYADH */
    { {6,3,3,3,3},
      {     "RIYADH",	    // English 
            "RIYADH",	    // French
            "RIYADH",      // German 
            "RIYADH",      // Italian
            "RIYADH"      // Spanish
		} }, 

	/* str_SAMARA */ 
    { {6,3,3,3,3},
      {     "SAMARA",	    // English 
            "SAMARA",	    // French
            "SAMARA",      // German 
            "SAMARA",      // Italian
            "SAMARA"      // Spanish
		} }, 

	/* str_SAMOA */
    { {5,3,3,3,3},
      {     "SAMOA",	    // English 
            "SAMOA",	    // French
            "SAMOA",      // German 
            "SAMOA",      // Italian
            "SAMOA"      // Spanish
		} }, 

	/* str_SYDNEY */
    { {6,3,3,3,3},
      {     "SYDNEY",	    // English 
            "SYDNEY",	    // French
            "SYDNEY",      // German 
            "SYDNEY",      // Italian
            "SYDNEY"      // Spanish
		} }, 

	/* str_TASMANIA */
    { {8,3,3,3,3},
      {     "TASMANIA",	    // English 
            "TASMANIA",	    // French
            "TASMANIA",      // German 
            "TASMANIA",      // Italian
            "TASMANIA"      // Spanish
		} }, 

	/* str_TEHRAN */
    { {6,3,3,3,3},
      {     "TEHRAN",	    // English 
            "TEHRAN",	    // French
            "TEHRAN",      // German 
            "TEHRAN",      // Italian
            "TEHRAN"      // Spanish
		} }, 

	/* str_TOKYO */
    { {5,3,3,3,3},
      {     "TOKYO",	    // English 
            "TOKYO",	    // French
            "TOKYO",      // German 
            "TOKYO",      // Italian
            "TOKYO"      // Spanish
		} }, 

	/* str_US_ALASKA */ 
    { {6,3,3,3,3},
      {     "US-ALASKA",	    // English 
            "US-ALASKA",	    // French
            "US-ALASKA",      // German 
            "US-ALASKA",      // Italian
            "US-ALASKA"      // Spanish
		} }, 

	/* str_US_ARIZONA */
    { {10,3,3,3,3},
      {     "US-ARIZONA",	    // English 
            "US-ARIZONA",	    // French
            "US-ARIZONA",      // German 
            "US-ARIZONA",      // Italian
            "US-ARIZONA"      // Spanish
		} }, 

	/* str_US_ATLANTIC */
    { {11,3,3,3,3},
      {     "US-ATLANTIC",	    // English 
            "US-ATLANTIC",	    // French
            "US-ATLANTIC",      // German 
            "US-ATLANTIC",      // Italian
            "US-ATLANTIC"      // Spanish
		} }, 

	/* str_US_CENTRAL */
    { {10,3,3,3,3},
      {     "US-CENTRAL",	    // English 
            "US-CENTRAL",	    // French
            "US-CENTRAL",      // German 
            "US-CENTRAL",      // Italian
            "US-CENTRAL"      // Spanish
		} }, 

	/* str_US_EASTERN */
    { {10,3,3,3,3},
      {     "US-EASTERN",	    // English 
            "US-EASTERN",	    // French
            "US-EASTERN",      // German 
            "US-EASTERN",      // Italian
            "US-EASTERN"      // Spanish
		} }, 

	/* str_US_HAWAII */
    { {9,3,3,3,3},
      {     "US-HAWAII",	    // English 
            "US-HAWAII",	    // French
            "US-HAWAII",      // German 
            "US-HAWAII",      // Italian
            "US-HAWAII"      // Spanish
		} }, 

	/* str_US_MOUNTAIN */
    { {11,3,3,3,3},
      {     "US-MOUNTAIN",	    // English 
            "US-MOUNTAIN",	    // French
            "US-MOUNTAIN",      // German 
            "US-MOUNTAIN",      // Italian
            "US-MOUNTAIN"      // Spanish
		} }, 
	
	/* str_US_PACIFIC */
    { {10,3,3,3,3},
      {     "US-PACIFIC",	    // English 
            "US-PACIFIC",	    // French
            "US-PACIFIC",      // German 
            "US-PACIFIC",      // Italian
            "US PACIFIC"      // Spanish
		} }, 

	/* str_VLADIVOSTOK */
    { {11,3,3,3,3},
      {     "VLADIVOSTOK",	    // English 
            "VLADIVOSTOK",	    // French
            "VLADIVOSTOK",      // German 
            "VLADIVOSTOK",      // Italian
            "VLADIVOSTOK"      // Spanish
		} }, 

	/* str_WINDHOEK */
    { {8,3,3,3,3},
      {     "WINDHOEK",	    // English 
            "WINDHOEK",	    // French
            "WINDHOEK",      // German 
            "WINDHOEK",      // Italian
            "WINDHOEK"      // Spanish
		} }, 

/*#######################################################################*
 * Secret Sensor output menu                                             *
 *#######################################################################*/
    /* str_SENSOR_OUTPUT*/
    { {13,3,3,3,3},
      {     "SENSOR OUTPUT",	    // English 
            "SORTIE DU CAPTEUR",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "PRODUCCION DEL SENSOR"      // Spanish
		} }, 

    /* str_PRESSURE */
    { {9,3,3,3,3},
      {     "PRESSURE:",	    // English 
            "PRESSION",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "PRESION:"      // Spanish
		} }, 

    /* str_DEPTH */
    { {6,3,3,3,3},
      {     "DEPTH:",	    // English 
            "PROFONDEUR:",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "ANCHO:"      // Spanish
		} }, 

    /* str_EYE */
    { {4,3,3,3,3},
      {     "EYE:",	    // English 
            "OEIL",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "OJO:"      // Spanish
		} }, 
    
    /* str_ROS1 */
    { {6,3,3,3,3},
      {     "ROS 1:",	    // English 
            "ROS 1:",	    // French
            "ROS 1:",      // German 
            "ROS 1:",      // Italian
            "ROS 1:"      // Spanish
		} }, 

    /* str_ROS2 */
    { {6,6,6,6,6},
      {     "ROS 2:",	    // English 
            "ROS 2:",	    // French
            "ROS 2:",      // German 
            "ROS 2:",      // Italian
            "ROS 2:"      // Spanish
		} }, 

    /* str_TILT */
    { {5,3,3,3,3},
      {     "TILT:",	    // English 
            "INCLINAISON:",	    // French
            "DEU",      // German 
            "ITA",      // Italian
            "INCLINACION:"      // Spanish
		} } 

}; // end string_array[]


char const* getString(SP2_STRING_T string_index);
uint16_t const getStringSize(SP2_STRING_T string_index);
void stringTest(void);



#endif // SP2_STRING_H_
