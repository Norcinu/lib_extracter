#ifndef _bo_h
#define _bo_h

#include <windef.h>
#include "dpci_core_api.h"
#include "dpci_sram_api.h"

//----Release Data
#define BOLIBRELEASE	27
#define SHELLRELEASE	 1

#define RELEASEx	0x1B01

#define	FILE_READ (_O_CREAT | _O_BINARY | _O_RDWR)
#define	FILE_WRITE (_O_CREAT | _O_BINARY | _O_RDWR)

#define	CLOSING			1
#define	CLOSED			2

#define PRINT_TICKET_ON_RETURN 0x03

//NEW COLLECT ROUTINE DEFINES
#define ERR_NOCOLLECT	 0
#define NOCOLLECT		 1
#define PRINTER_COLL	 2
#define HANDPAY_COLL	 3
#define HOPPER_COLL		 4
#define HANDPAY_COLL_ALL 5

//TOURNAMENT PLAY DESCRIPTION FLAGS
#define TOURNAMENT_PLAY_STARTED 0
#define TOURNAMENT_PLAY_ENDED 1
#define TPLAY_SESSION_STARTED 2
#define TPLAY_SESSION_CLEARED 3
#define TPLAY_SESSION_ENDED 4
#define TPLAY_SESSION_HAND_PAID 5
#define TPLAY_SESSION_PAYOUT_ERROR 6

//TOURNAMENT PLAY DATABASE RELEASE CODES
#define TOURNAMENT_PLAY_START_ID (unsigned long) 1000000000
#define TOURNAMENT_PLAY_END_ID   (unsigned long) 1010000000
#define TPLAY_SESSION_START_ID   (unsigned long) 1020000000
#define TPLAY_SESSION_END_ID     (unsigned long) 1030000000

//COUNTRY CODES
#define CC_UKB3	0
#define	CC_UKC	1 
#define CC_EURO	2
#define CC_CZ   3
#define CC_ARG  4
#define CC_UKR  5
#define CC_COLM 6
#define CC_NI   7
#define CC_UKB  8

//COUNTRY CODE COUNT
#define CC_CNT  9


//LANGUAGES SUPPORT  USE International 3 Character country codes.
#define L_GBR 0
#define L_EUR 1 
#define L_CZE 2  
#define L_ESP 3  

#define LANGUAGES 4   //To stop tables growing too large.

#define DEDICATED_GAME 1

//Cabinet Types
#define VEGAS 0
#define SLANT 1
#define TS22  2

//CPU Types
#define DPX_S410 0
#define DPX_S430 1

//Payout Formats
#define HOPPER		   0
#define PRINTER        1
#define COMBINED       2

#define PRINT_LINES 18
#define ERROR_CNT   55

//ERROR BYTE ARRAY
#define MAX_ERR_BYTE 50

//ERROR DEFINES
#define ERR_UNKNOWN						0
#define ERR_COMMS_BUF_FULL				1 //Can Self Clear
#define ERR_COMMS_BARCODE				2	
#define ERR_COMMS_NETWORK				3
#define ERR_COMMS_RNG_EMPTY				4 //Can Self Clear
#define ERR_NVR_CORRUPT					5
#define ERR_COMPENSATOR_DATA_RESET		6
#define ERR_REEL_DATA_RESET				7
#define ERR_CREDIT_DATA_RESET			8
#define ERR_WINBANK_DATA_RESET			9
#define ERR_SERIAL_PRINTER_NOT_FOUND	10
#define ERR_PRINTER_FAILURE				11
#define ERR_PRINTER_NO_PAPER			12
#define ERR_GAME_DATA_RESET				13
#define ERR_MAX_WINBANK_EXCEEDED		19
#define ERR_MAX_CREDITS_EXCEEDED		20
#define ERR_MAX_WIN_EXCEEDED			21
#define ERR_COMMS_REMOTE_CREDIT			22  //Warning Only
#define ERR_COMMS_SEND_TIMEOUT			23	//Warning Only
#define ERR_COMMS_SEND_LINK_LOST		24  //Warning Only
#define ERR_COMMS_SEND_DATA_INVALID		25	//Warning Only
#define ERR_COMMS_FAIL_OPEN_SOCKET1		26  //Warning Only
#define ERR_COMMS_FAIL_OPEN_SOCKET2 	27  //Warning Only
#define ERR_COMMS_WINSOCK_WRONG_VRN 	28  //Warning Only
#define ERR_COMMS_RNG_SLOW_FILL 		29  //Warning Only
#define ERR_COMMS_BO_FAILED_BARCODE		30
#define ERR_NV_LRC_REMOVED				89
#define ERR_NV_STACKER_FULL				90
#define ERR_NV_SAFE_JAM					91
#define ERR_NV_UNSAFE_JAM				92 //Warning Only
#define ERR_NV_FRAUD_ATTEMPT			93 
#define ERR_NV_SOFTWARE					94 
#define ERR_NV_NOTE_REJECTED			95 //Warning Only
#define ERR_HOPPER_OPTO_FRAUD			96
#define ERR_HOPPER_LEFT_OPTO_FAIL		97
#define ERR_HOPPER_RIGHT_OPTO_FAIL		98
#define ERR_HOPPER_SHORT_PAY			99
#define ERR_HOPPER_COIN_DENOMINATION	100
#define ERR_EDC_COMMS_FAIL				101 //Can Self Clear
#define ERR_HOPPER_LEFT_TAMPER_DETECT   102
#define ERR_HOPPER_RIGHT_TAMPER_DETECT	103
#define ERR_HOPPER_PAYOUT_INTERRUPTED	104
#define ERR_PRINTER_PAYOUT_INTERRUPTED	105
#define ERR_REMOTE_CREDIT_TOO_LARGE		106	//Warning Only
#define ERR_NV_COMMAND					110 //Warning Only
#define ERR_NV_WNGNOPARAM				111 //Warning Only
#define ERR_NV_PARAM_RANGE				112 //Warning Only
#define ERR_NV_CMDNBPRSED				113 //Warning Only
#define ERR_NV_SWERROR					114
#define ERR_NV_SSPFAIL					115
#define ERR_NV_KEY_NOT_SET				116
#define ERR_EDC_SEND_LATENCY			117	//Can Self Clear
#define ERR_NV_RECYCLER_REMOVED			118 //Can Self Clear but will set 116
#define ERR_NV_RECYCLER_EMPTIED			119

#define IOU_ERROR    ERR_HOPPER_SHORT_PAY

//------ Hopper Error codes
#define HOPPER_OK					0x00
#define HOPPER_ERROR_SHORT			0x01  //Covered by Iou
#define HOPPER_OPTO_LEFT_ERROR		0x02
#define HOPPER_OPTO_RIGHT_ERROR		0x04
#define HOPPER_OPTO_FRAUD			0x08
#define HOPPER_ERROR_COIN_SIZE		0x10
#define MORE_COINS_IN_HOPPER		0x20

//------ NV11 Recycler Error Codes -------
#define RECYCLER_OK					0x00
#define RECYCLER_NOT_CONNECTED		0x01
#define RECYCLER_EMPTY				0x02
#define RECYCLER_BUSY				0x03
#define RECYCLER_DISABLED			0x04

//------ NV11 ROUTES ---------------------
#define PAYOUT_ROUTE		0x00
#define CASHBOX_ROUTE		0x01
#define UNKNOWN_ROUTE		0x02

//------ NOTE VALUE ------ CHANNEL
#define	NOTE_ONE	 		0x01
#define	NOTE_TWO  			0x02
#define	NOTE_THREE  		0x03
#define	NOTE_FOUR	 		0x04
#define	NOTE_FIVE	 		0x05
#define	NOTE_SIX	 		0x06

//------------ DataBase Codes ------------
#define NEW_DATA_DAY			0x01

#define TICKET_PAYOUT			0x02
#define HAND_PAYOUT				0x03

#define KEY_OPEN_CODE			0x09
#define KEY_CLOSED_CODE			0x0a

#define TERMINAL_CLOSED_CODE	0x0b
#define TERMINAL_OPEN_CODE		0x0c

#define ONEP_HAND_PAY			0x1a
#define TENP_HAND_PAY			0x1b
#define PND_HAND_PAY			0x1c

#define TENP_TO_HOPPER			0x21
#define POUND_TO_HOPPER			0x24

/* Door codes */
#define CASH_DOOR_OPEN_CODE		0x2b
#define CASH_DOOR_CLOSED_CODE	0x2c
#define BACK_DOOR_OPEN_CODE		0x2d
#define BACK_DOOR_CLOSED_CODE	0x2e

#define VTP_CODE				0x2f

/* Coin in codes */
#define FIVEP_COIN_IN_CODE		0x30
#define TENP_COIN_IN_CODE		0x31
#define TWENTYP_COIN_IN_CODE	0x32
#define FIFTYP_COIN_IN_CODE		0x33
#define PND_COIN_IN_CODE		0x34
#define TWO_PND_COIN_IN_CODE	0x35

//Note In Codes
#define NOTE_ONE_IN_CODE		0x36
#define NOTE_TWO_IN_CODE		0x37
#define NOTE_THREE_IN_CODE      0x27
#define	NOTE_FOUR_IN_CODE       0x28
#define	NOTE_FIVE_IN_CODE       0x29
#define	NOTE_SIX_IN_CODE        0x2a

#define	NOTE_FIVE_IN_CODE_ARG   0x34 
#define	NOTE_SIX_IN_CODE_ARG    0x35 

//Note Out Codes
#define NOTE_ONE_OUT_CODE		0x46    //£5
#define NOTE_TWO_OUT_CODE		0x47	//£10
#define NOTE_THREE_OUT_CODE		0x10	//£20
#define NOTE_FOUR_OUT_CODE		0x11	//£50
#define NOTE_FIVE_OUT_CODE		0x11	//£50 To Be Defined.
#define NOTE_SIX_OUT_CODE		0x11	//£50 To Be Defined


//codes added to allow for machine remote credit
#define FIVEP_TOKEN_IN_CODE		0x38
#define TENP_TOKEN_IN_CODE		0x39
#define TWENTYP_TOKEN_IN_CODE	0x3a
#define FIFTYP_TOKEN_IN_CODE	0x3b
#define PND_TOKEN_IN_CODE		0x3c
#define PND2_TOKEN_IN_CODE		0x3d
#define FIVE_PND_TOKEN_IN_CODE	0x3e
#define TEN_PND_TOKEN_IN_CODE	0x3f

/* Coin out codes */
#define PND_COIN_OUT_CODE		0x44
#define TENP_COIN_OUT_CODE		0x41

//Refill Codes
#define REFIL_PND_COIN_CODE		0x54
#define REFILL_PND_COIN_CODE	0x54

//Stake Match
#define STAKEMATCH_PND_IN		0x64

//Reset Codes
#define WIN_DEPOSIT_RESET_CODE	0xa9
#define FULL_NVR_RESET_CODE		0xaa
#define ADD_CD_RESET_CODE		0xab
#define ADD_WIN_RESET_CODE		0xac
#define SUB_CD_RESET_CODE		0xad
#define ZERO_CD_RESET_CODE		0xae
#define GET_CD_RESET_CODE		0xaf

//Codes for starting each module
#define HOME_PAGE_START_CODE		0xb0
#define GAME_ONE_START_CODE			0xb1
#define GAME_TWO_START_CODE			0xb2
#define GAME_THREE_START_CODE		0xb3
#define GAME_FOUR__START_CODE		0xb4
#define GAME_FIVE__START_CODE		0xb5
#define GAME_SIX_START_CODE			0xb6
#define GAME_SEVEN_START_CODE		0xb7
#define GAME_EIGHT_START_CODE		0xb8
#define GAME_NINE_START_CODE		0xb9
#define GAME_TEN_START_CODE			0xba
#define UTILITIES_START_CODE		0xbb




#define EXIT_CODE1					0xbe
#define EXIT_CODE2					0xbf

//Minimum bet codes
#define MINIMUM_BET_50P			0xE0
#define MINIMUM_BET_1PND		0xE1
#define MINIMUM_BET_2PND		0xE2
#define MINIMUM_BET_5PND		0xE3
#define MINIMUM_BET_10PND		0xE4
#define MINIMUM_BET_20PND		0xE5
#define MINIMUM_BET_INVALID		0xEF

#define HANDPAY_CONFIRM			0xf1
#define HANDPAY_CANCEL			0xf2

#define FTP_REBOOT_CODE			0xf8
#define DAILY_REBOOT_CODE		0xf9
#define SRAM_DAT_FILE_CODE		0xfa

//GamCare Codes
#define GAMCARE_LIMIT_SET		0xFB
#define GAMCARE_TIMED_OUT		0xFC
#define GAMCARE_LIMIT_CANCEL	0xFD


//Poll Code
#define SHELL_POLL_CODE			0xfd
#define CLOSED_IDLE_CODE		0xfe
#define MACHINE_IDLE_CODE		0xff

//--------------  Inputs

#define COIN_IN_1			0,0x01	//	 White/Orange.
#define COIN_IN_2			0,0x02	//	 White/Brown.
#define COIN_IN_3			0,0x04	//	 White/Green.
#define COIN_IN_4			0,0x08	//	 White/Yellow.
#define COIN_IN_5			0,0x10	//	 White/Blue.
#define COIN_IN_6			0,0x20	//	 White/Red.
#define HOPPER_LEFT_OPTIC   0,0x40	//	 Orange/Blue.
#define HOPPER_RIGHT_OPTIC	0,0x80	//	 Orange/Red.


//--------------  Button deck  ------------------

#define LH1_BUTTON			1,0x80  //Print Ticket			White/Black
#define LH2_BUTTON			1,0x40	//						White/Orange
#define LH3_BUTTON			1,0x20	//						White/Brown
#define LH4_BUTTON			1,0x10	//						White/White
#define LH5_BUTTON			1,0x08	//						White/Green
#define LH6_BUTTON			1,0x04  //Return to Home Page.	White/Yellow
#define LH7_BUTTON			1,0x02  //Repeat Bet			White/Blue
#define LH8_BUTTON			1,0x01  //Start					White/Red.

//-------------  Other switches  ----------------

#define CASHDOOR			2,0x01 //	 Grey/Red.
#define MAINDOOR			2,0x02 //    Grey/Blue
//							2,0x04 //	 Grey/Yellow
//			                2,0x04 //    Grey/Yellow
//							2,0x08 //	 Grey/Green
#define REFILL_KEY			2,0x10 //    Grey/White
#define HOPPER_DUMP_SW 		2,0x20 //    Grey/Brown
//							2,0x40 //    Grey/Orange
//							2,0x80 //    Grey/Black

//				    		3,0x01 
//							3,0x02 
//							3,0x04 
//				    		3,0x08 
//							3,0x10 
//							3,0x20 
//							3,0x40 
//							3,0x80 

//--------------  Dil switches  -----------------

#define	DIL_SWITCH_1		4,0x01 //On:  Display Float Door Closed
#define	DIL_SWITCH_2		4,0x02 //On:  Note Validator Active
#define DIL_SWITCH_3		4,0x04 //On:  HandPay Active
#define DIL_SWITCH_4		4,0x08 //On:  £ Floats: C = £480 B3 = £1000 
								   //Off: £ Floats: C = £230 B3 = £500	


//------------LAMP RELATED DEFINES

#define LAMP_OFF	0x00
#define LAMP_ON	    0x01
#define	LAMP_FLASH	0x02
#define	LAMP_ANTI	0x04

#define LH1_LAMP					1
#define LH2_LAMP					2
#define LH3_LAMP					3
#define LH4_LAMP					4
#define LH5_LAMP					5
#define LH6_LAMP					6
#define LH7_LAMP					7
#define LH8_LAMP					8
#define NOTE_VALIDATOR1_LAMP		9
#define NOTE_VALIDATOR2_LAMP		10
#define NOTE_VALIDATOR3_LAMP		11
#define NOTE_VALIDATOR4_LAMP		12
#define COIN_MECH_LAMP				13


#define OP_ON		1
#define OP_OFF		0

#define COIN_MECH_PORT		0x00
#define COIN_MECH_STROBE	0x08

//--------------- Bonus Box Masks ----------------
#define BONUS_BOX_TRIG_ON  1,0x04,OP_ON
#define BONUS_BOX_TRIG_OFF 1,0x04,OP_OFF
#define BONUS_BOX_READ_IN  2,0x04


#define LEFTHOPPER			0x00
#define MIDDLEHOPPER		0x01
#define RIGHTHOPPER			0x02
#define HOPPER_LEFT_MASK	0x10	//value of left motor mask

//--------------OUTPUTS ----------------------

#define ALL_METERS_OFF			0,0x07,OP_OFF
#define HOPPER_ALL_MOTOR_OFF    0,0x30
#define HOPPER_RELAYS_OFF		0,0xc0
#define HOPPER_ALL_OFF			0,0xf0


#define METER_1_ON			 0,0x01,OP_ON	//Brown/Black
#define METER_1_OFF			 0,0x01,OP_OFF
#define METER_2_ON			 0,0x02,OP_ON	//Brown/Red
#define METER_2_OFF			 0,0x02,OP_OFF
#define METER_3_ON			 0,0x04,OP_ON	//Brown/Orange
#define METER_3_OFF			 0,0x04,OP_OFF
#define HOPPER_OPTIC_POWER	 0,0x08			//Brown/Yellow
#define HOPPER_LEFT_MOTOR	 0,0x10			//Brown/Green
#define HOPPER_RIGHT_MOTOR	 0,0x20			//Brown/Blue
#define HOPPER_LEFT_RELAY    0,0x40			//Brown/White
#define HOPPER_RIGHT_RELAY	 0,0x80			//Brown/Grey


#define LH1_LAMP_ON 1,0x80,LAMP_ON			//Yellow/Grey
#define LH2_LAMP_ON 1,0x40,LAMP_ON			//Yellow/Black
#define LH3_LAMP_ON 1,0x20,LAMP_ON			//Yellow/Orange
#define LH4_LAMP_ON 1,0x10,LAMP_ON			//Yellow/Brown
#define LH5_LAMP_ON 1,0x08,LAMP_ON			//Yellow/White
#define LH6_LAMP_ON 1,0x04,LAMP_ON			//Yellow/Pink
#define LH7_LAMP_ON 1,0x02,LAMP_ON			//Yellow/Blue
#define LH8_LAMP_ON 1,0x01,LAMP_ON			//Yellow/Red

#define LH1_LAMP_OFF 1,0x80,LAMP_OFF		//Yellow/Grey
#define LH2_LAMP_OFF 1,0x40,LAMP_OFF		//Yellow/Black
#define LH3_LAMP_OFF 1,0x20,LAMP_OFF		//Yellow/Orange
#define LH4_LAMP_OFF 1,0x10,LAMP_OFF		//Yellow/Brown
#define LH5_LAMP_OFF 1,0x08,LAMP_OFF		//Yellow/White
#define LH6_LAMP_OFF 1,0x04,LAMP_OFF		//Yellow/Pink
#define LH7_LAMP_OFF 1,0x02,LAMP_OFF		//Yellow/Blue
#define LH8_LAMP_OFF 1,0x01,LAMP_OFF		//Yellow/Red


#define INHIBIT_COIN_1_ON	2,0x01,OP_ON	//Brown/Black
#define INHIBIT_COINS_ON	2,0x02,OP_ON	//Orange/Black
#define COIN_MECH_LAMP_ON	2,0x04,LAMP_ON	//Brown/Red
#define DIVERT_B_ON			2,0x08,OP_ON	//Orange/Brown
#define DIVERT_C_ON			2,0x10,OP_ON	//Orange/Red
#define DIVERT_D_ON			2,0x20,OP_ON	//Grey/Black
//							2,0x40,OP_ON
//							2,0x80,OP_ON

#define INHIBIT_COIN_1_OFF	2,0x01,OP_OFF 
#define INHIBIT_COINS_OFF	2,0x02,OP_OFF 
#define COIN_MECH_LAMP_OFF	2,0x04,LAMP_OFF
#define DIVERT_B_OFF		2,0x08,OP_OFF
#define DIVERT_C_OFF		2,0x10,OP_OFF
#define DIVERT_D_OFF		2,0x20,OP_OFF
//							2,0x40,OP_OFF
//							2,0x80,OP_OFF

//							3,0x01,OP_ON
//							3,0x02,OP_ON
//							3,0x04,OP_ON
//							3,0x08,OP_ON
//							3,0x10,OP_ON
//							3,0x20,OP_ON
//							3,0x40,OP_ON
//							3,0x80,OP_ON

//							3,0x01,OP_OFF
//							3,0x02,OP_OFF
//							3,0x04,OP_OFF
//							3,0x08,OP_OFF
//							3,0x10,OP_OFF
//							3,0x20,OP_OFF
//							3,0x40,OP_OFF
//							3,0x80,OP_OFF



//------------------------RUN MODE DEFINES ----------
//Door open set bit 0 allows for quick tests in modules
#define RUN_DOOR_OPEN		 (unsigned char)0x01
#define RUN_NORMAL			 (unsigned char)0x02
#define RUN_TEST			 (unsigned char)0x05
#define RUN_REFILL			 (unsigned char)0x08
#define RUN_REFILL_DOOROPEN	 (unsigned char)0x09
#define RUN_OPTIONS			 (unsigned char)0x10
#define RUN_OPTIONS_DOOROPEN (unsigned char)0x11


#define DISABLE_NOTE_VALIDATOR 0x01
#define ENABLE_NOTE_VALIDATOR  0x02

//---- MAX VALUES

//Defines to index VariableValueArray

#define MAX_POSSIBLE_WIN	  0
#define MAX_CREDITS			  1
#define MAX_POSSIBLE_BET	  2
#define MAX_REMOTE_CREDITS	  3
#define CORRUPT_CREDITS		  4
#define MAX_WIN_BANK		  5
#define CORRUPT_WIN_BANK      6
#define MAX_CASH_IN           7
#define PARTIAL_COLLECT_LIMIT 8
#define MAX_WBANK_TRANSFER    9
#define	MAX_HOPPER_COLLECT	  10
#define HANDPAY_THRESHOLD	  11
#define MAX_HANDPAY_THRESHOLD 12

#define QUERY_CNT			  13

#define METERUNITS			100 //meters in £ increments.
#define MAXMODELS			10


//-----------SOFT METER CODES -------

//CASH RECONCILIATION

#define COIN_CNT	10
#define NOTE_CNT	NOTE_SIX

// LONG TERM
#define NOTE_6_LT    0		//Not used UK
#define NOTE_5_LT    1		//Not used UK
#define NOTE_4_LT    2		//£50
#define NOTE_3_LT	 3		//£20
#define NOTE_2_LT	 4 		//£10
#define NOTE_1_LT	 5		//£5

#define COIN_8_LT	 6		//STAKE MATCH.
#define COIN_7_LT	 7		//Not Used was Token.
#define COIN_6_LT	 8		//£2.
#define COIN_5_LT	 9		//£1.
#define COIN_4_LT	 10		//£0.50.
#define COIN_3_LT	 11		//£0.20.
#define COIN_2_LT	 12		//£0.10.
#define COIN_1_LT	 13		//£0.05.

#define REFILL_L_LT  14		//£1
#define REFILL_R_LT  15		//£0.10.

#define NOTE_1_OUT_LT 16
#define NOTE_2_OUT_LT 17
#define NOTE_3_OUT_LT 18
#define NOTE_4_OUT_LT 19
#define NOTE_5_OUT_LT 20
#define NOTE_6_OUT_LT 21

#define COIN_6_OUT_LT 22		//£2.
#define COIN_5_OUT_LT 23		//£1.
#define COIN_4_OUT_LT 24		//£0.50.
#define COIN_3_OUT_LT 25		//£0.20.
#define COIN_2_OUT_LT 26		//£0.10.
#define TICKET_OUT_LT 27		//TicketsPrinted.


// SHORT TERM
#define NOTE_6_ST    28		//Not used UK
#define NOTE_5_ST	 29		//Not used UK
#define NOTE_4_ST    30		//£50
#define NOTE_3_ST	 31		//£20
#define NOTE_2_ST	 32 	//£10
#define NOTE_1_ST	 33		//£5

#define COIN_8_ST	 34		//STAKE MATCH.
#define COIN_7_ST	 35		//Not Used was token.
#define COIN_6_ST	 36		//£2.
#define COIN_5_ST	 37		//£1.
#define COIN_4_ST	 38		//£0.50.
#define COIN_3_ST	 39		//£0.20.
#define COIN_2_ST	 40		//£0.10.
#define COIN_1_ST	 41		//£0.05.

#define REFILL_L_ST  42		//£1
#define REFILL_R_ST  43		//£0.10.

#define NOTE_1_OUT_ST 44
#define NOTE_2_OUT_ST 45
#define NOTE_3_OUT_ST 46
#define NOTE_4_OUT_ST 47
#define NOTE_5_OUT_ST 48
#define NOTE_6_OUT_ST 49

#define COIN_6_OUT_ST 50		//£2.
#define COIN_5_OUT_ST 51		//£1.
#define COIN_4_OUT_ST 52		//£0.50.
#define COIN_3_OUT_ST 53		//£0.20.
#define COIN_2_OUT_ST 54		//£0.10.
#define TICKET_OUT_ST 55		//Tickets printed.

#define MAX_R_METERS  56
#define ST_OFFSET_R  (MAX_R_METERS/2)

// PERFORMANCE

#define MONEY_IN_LT  0
#define MONEY_OUT_LT 1
#define HAND_PAY_LT  2
#define CASHBOX_LT	 3
#define No_GAMES_LT	 4
#define WAGERED_LT	 5
#define WON_LT		 6

#define MONEY_IN_ST  7
#define MONEY_OUT_ST 8
#define HAND_PAY_ST  9
#define CASHBOX_ST	 10
#define No_GAMES_ST	 11
#define WAGERED_ST	 12
#define WON_ST		 13


#define MAX_P_METERS 14
#define ST_OFFSET_P  (MAX_P_METERS/2)

#define TPLAY_MONEY_OUT_LT 0
#define TPLAY_No_GAMES_LT  1
#define TPLAY_MONEY_IN_LT  2
#define TPLAY_MONEY_OUT_ST 3
#define TPLAY_No_GAMES_ST  4
#define TPLAY_MONEY_IN_ST  5

#define MAX_TPLAY_METERS 6
#define TPLAY_ST_OFFSET_P (MAX_TPLAY_METERS/2)

#define COINVALUELEFT				100
#define COINVALUERIGHT				10
#define SLANTFORCEHANDPAYVALUE		(200*COINVALUELEFT)

//----------join control
#define JOIN  0x01
#define LEAVE 0x02
#define CHECK 0x03

#define PRINTER_ERROR   0x01
#define PAPER_OUT       0x02
#define PRINTER_INIT	0x04
#define PRINTER_RUNNING 0x04

#define DEFAULT_PERCENTAGE 88
#define MINIMUM_PERCENTAGE 80
#define MAXIMUM_PERCENTAGE 96

//------------Progressive Jackpot

#define  LAN_PJ_TYPE 0x00
#define  WAN_PJ_TYPE 0x01
 
#define  LAN_PJ_WIN_IN_PROGRESS 0x0F 
#define  WAN_PJ_WIN_IN_PROGRESS 0xF0 

//-------------PJState
#define  NO_PJ_ACTIVE  0x0000
#define  WAN_PJ_ACTIVE 0x0001
#define  LAN_PJ_ACTIVE 0x0002
#define  LAN_PJ_WIN    0xFE00
#define  WAN_PJ_WIN    0xFD00

//-------------BNV_TYPES
#define NO_BNV		0
#define AUTO_BNV	1
#define NV9_BNV		2
#define MEI_BNV		3
#define JCM_BNV		4
#define NV11_BNV	5
#define LAST_BNV	6		//add new BNV's before this define

//-------------------- HEADERS -------------------
void		  AddVtpCount(unsigned int amount);
void		  AddToDemoCredits(unsigned long Value);
void		  AddWinToBank(unsigned long Value, unsigned int ModelNo);
void		  AddWinToCredits(unsigned long Value, unsigned int ModelNo);
void		  AddHopperFloatLevel(unsigned char Hopper, unsigned int value);
unsigned long add_cdeposit_rc(unsigned long value);
unsigned long AddToCdepositFromBank(unsigned long value);
unsigned long AddToBankDeposit(unsigned long value);
void		  AddToGamePerformanceMeters(unsigned int ModelNo , unsigned int Value, unsigned char Meter);
void		  AddToPerformanceMeters(unsigned char Meter,unsigned long tvalue);
void		  AddToReconciliationMeters(unsigned char Meter,unsigned long tvalue);
void		  AddToLastGameMeter(unsigned int GameModel, int Wager, int Win);
void		  AddCancelledBetToCredits(unsigned long Value, unsigned int ModelNo);
void		  AddToTPlayLog(unsigned long CreditValue, unsigned char Desc);
void		  AddToComsBuffer(char * mesg,unsigned long tn,bool AddMesgSeqNumber);

void		  ClearFileAction(void);
void		  ClearFullReset(void);
void		  ClearFirstTimeRun(void);
void		  ClearGameInProgress(void);
void		  ClearGameInProgress(void);
void		  ClearIouValue(void);
void		  ClearFreezePlay(void);
void		  ClearRefillCounters(void);
void		  ClearShortTermMeters(void);
void		  ClearEdcStatus(void);
void		  ClearGamePerformanceMeter(unsigned int Offset,unsigned int Metertype);
void		  ClearPrinterStatus(void);
void		  ClearTicketPrinting(void);
void		  ClearPartialCollectValue(void);
void		  ClearCriticalError(long errType);
void		  ClearProgressiveJackpotState(void);
void		  ClearProgressiveJackpotStateBitWise(unsigned int value);
void          ClearTPlaySessionActive();


void		  FillRandomNumberArray(void);
void		  FillSingleGameRandomNumberArray(void);

void		  GenerateBarcode(unsigned long tvalue);


unsigned char GetLocalCharRandomNumber(unsigned char val);
unsigned int  GetLocalIntRandomNumber(unsigned int val);
unsigned long GetLocalLongRandomNumber(void);
unsigned int  GetRemoteIntSingleGameRN(unsigned int val);
unsigned long GetRemoteLongRandomNumber(void);

unsigned int  GetCabinetType(void);

unsigned char GetCurrentState(void);
unsigned char GetGameInProgress(void);
BOOL		  GetDoorStatus(void);
unsigned long GetCredits(void);
unsigned long GetBankDeposit(void);		
BOOL          GetKeyswitchStatus(void);
unsigned long GetCreditsPrevious(void);
unsigned int  GetClosingTime(void);
unsigned char GetFullReset(void);
unsigned char GetFirstTimeRun(void);
unsigned int  GetRemoteMasterVolume(void);
unsigned int  GetLocalMasterVolume(void);
		 int  GetRunMode(void);
unsigned char GetCurrentState(void);
unsigned char GetGameInProgress(void);
unsigned int  GetIouValue(void);
unsigned char GetFreezePlay(void);
unsigned int  GetHopperFloatLevel(unsigned char Hopper);
unsigned int  GetHopperDivertLevel(unsigned char Hopper);
  signed int  GetRefillCtr(unsigned char Hopper);
BOOL		  GetSwitchStatus(unsigned char Offset, unsigned char Mask);
BOOL		  GetPhysicalDoorSwitchState(void);
unsigned long GetReconciliationMeter(unsigned char Offset);
unsigned long GetPerformanceMeter(unsigned char Offset);
unsigned long GetTPlayMeter(unsigned char Offset);
unsigned int  GetPercentage(void);
unsigned long GetGamePerformanceMeter(unsigned int Offset,unsigned int Metertype);
BOOL		  GetRequestEmptyLeftHopper(void);
BOOL		  GetRequestEmptyRightHopper(void);
BOOL		  GetRequestHopperPayout(void);
BOOL		  GetRedemptionUnitRunning(void);
BOOL		  GetHoppersRunning(void);
BOOL		  GetTicketPrinting(void);
unsigned char GetTerminalFormat(void);
unsigned char GetTerminalType(void);
unsigned int  GetHopperError(void);
unsigned char GetEdcStatus(void);
unsigned char GetDoorPrevious(void);
unsigned char GetGameNumber(unsigned int ModelNumber);
unsigned char GetShellRelease(void);
unsigned char GetWriteToSramFlag(void);
unsigned char GetMVersion(void);
unsigned long GetSerialNumber(void);
unsigned long GetVariableValue(int ValueIndex);
unsigned int  GetTicketDuplicateNumber(void);
unsigned long GetTicketFaceValue(void);
unsigned long GetPartialCollectValue(void);
unsigned int  GetHandPayThreshold(void);
unsigned long GetPrintPayThreshold(void);
char *		  GetErrorText(int errType);
long		  GetCurrentError(void);
unsigned char GetCountry(void);
unsigned char GetLanguage(void);
unsigned char GetPrinterStatus(void);
BOOL		  GetRebootRequired(void);	
int			  GetTotalSecondsBeforeClosing(void);
int			  GetTotalSecondsBeforeOpening(void);
unsigned int  GetLastNote(int Note);
BOOL		  GetMaxCreditReached(int ModelNr);
unsigned char GetStagePayoutActive(void);
unsigned char GetHandPayActive(void);
unsigned long GetMaxStagePayoutValue(void);
unsigned char GetBankAndCreditMeter(void);
unsigned int  GetMinPayoutValue(void);
unsigned char GetProgressiveJackpotWinInProgress(void);
unsigned char GetProgressiveJackpotWinCount(unsigned char Type);
unsigned int  GetProgressiveJackpotState(void);
unsigned long GetProgressiveJackpotValue(unsigned char Type);
float		  GetProgressiveJackpotPercentage(unsigned char Type);
unsigned int  GetProgressiveJackpotStake(unsigned char Type);
unsigned long GetProgressiveJackpotMaxValue(unsigned char Type);
unsigned char GetProgressiveJackpotCombination(unsigned long *Rng);
unsigned long GetLastProgressiveWinValue(unsigned char Type);
unsigned long GetLastProgressiveWinTime(unsigned char Type);
unsigned int  GetLastProgressiveWinSmId(unsigned char Type);
unsigned long GetSlaveDataIn(unsigned char Tracer);
unsigned long GetMasterDataIn(unsigned char Tracer);
int			  GetInTPlaySession();
int           GetInTournamentPlay();

int           GetTargetPercentage();

void		  GetInputs( LPBYTE inputs );
BOOL		  GetCashDoorStatus(void);
unsigned char GetEdcUnitPresent(void);
unsigned char GetHopperDumpSwitchActive(void);
int			  GetPendingComsMsgCount(void);
unsigned char GetUsesBackOffice(void);
unsigned char GetNewDataDay(void);
unsigned int  GetClosedTime(void);
unsigned int  GetOpenTime(void);
unsigned long GetASingleGameRN(void);
unsigned long GetANetworkRN(void);
unsigned long GetCurrentRN(void);
unsigned char GetCurrentNetworkRN(unsigned long *NewNumber);
unsigned char GetStakeMatchActive(void);
int           GetDynamicGameToLoad(void);
int			  GetDynamicDoNotQuitGame(unsigned int ModelNo);
unsigned char GetHardWareType(void);
int			  GetTerminalState(void);
char *		  GetCurrencyName(void);
unsigned char GetRecyclerChannel(void);
unsigned int  GetRecyclerChannelValue(void);
unsigned int  GetRecyclerFloatValue(void);
unsigned char GetBnvType(void);
unsigned int  GetMinimumBetValue(void);
unsigned char GetVolumeControlType(void);
unsigned char GetLastPayoutType(void);
unsigned char GetDynamicGameSelectionState(void);
unsigned int  GetDGSTargetGame(void);
unsigned int  GetNewGame2Promo(void);
unsigned int  GetNewGamePromoDays(void);
unsigned char GetActiveGameManagementState(void);



unsigned long prand(void);

unsigned long int SeedSingleGameRNWithNetworkRN(unsigned long int Range);
void		      SeedSingleGameRNWithNumber(unsigned long Rn_number);
void			  SeedLocalRNG(void);
void		      SeedStdRNWithTime(void);
void		      SeedStdRNWithExternalRN(void);

void		  SendGameOutcome2Server(unsigned long TotalBet,unsigned long RngUsed,unsigned long outcome,unsigned long game_id,unsigned long win);
void		  SendSelectedRN2Server(unsigned long value,unsigned long cdeposit_lib,unsigned long total_bets,unsigned long outcome,unsigned long game_id,unsigned long win);
void		  SendMachineID2Server(void);
void          SendAlarm2Server(unsigned char type);
void          SendCredit2Server(unsigned long value);
void          SendWin2Server(unsigned long winnings,unsigned long game_id);
void          SendPlayStatus2Server(unsigned char status);
void		  SendTSDCode2Server(unsigned char code);
BOOL          SendHeaderOnly(unsigned char, int);
void		  SendDataPacCode(unsigned char code);
void		  SendDataPacCode2(unsigned char code);
void		  SendDataPacCode4(unsigned char code);
void		  SendDataPacString(unsigned char type,unsigned char mlength,unsigned char * data);
void		  SendTPlayMessage2Server(unsigned long TotalBet,unsigned long RngUsed,unsigned long outcome,unsigned long game_id,unsigned long win);
void		  SendBarcode2Server(void);
void		  SendCollect2Server(unsigned int AmountPaidOut,unsigned int Release);
void		  SendHandPay2Server(unsigned int AmountPaidOut, unsigned int Release);
void		  SendGamePingToServer(void);
void		  SendBetValue2Server(unsigned long value);

void          SetTargetPercentage(int Percentage);
void		  SetCabinetType(int Type);
BOOL		  SetBOCom(void);
void		  SetRunMode(int rm);
void		  SetFileAction(void);
void		  SetAutoCreditFlag(void);
void		  SetSharedMemory(void);
void		  SetCurrentState(unsigned char state);
void		  SetShellIssueNumber(unsigned char issue);
unsigned int  SetEnvironment(unsigned int release);
void		  SetGameInProgress(void);
void		  SetSoftOutMeters(unsigned long tvalue);
void		  SetCreditsPrevious(unsigned long amount);
void		  SetLampOn(unsigned char lamp);
void		  SetLampFlash(unsigned char lamp);
void		  SetLampAnti(unsigned char lamp);
void          SetLampOff(unsigned char lamp);
void          SetGameInProgress(void);
void          SetClosingTime(unsigned int CTime);
void		  SetOpeningTime(unsigned int CTime);
void		  SetOpenCloseStatus(void);
void          SetLampStatus(unsigned char offeset,unsigned char mask,unsigned char state);
void          SetOutputStatus(unsigned char offset,unsigned char mask,unsigned char state);
void          SetRemoteMasterVolume(unsigned int value);
void          SetLocalMasterVolume(unsigned int value);
void          SetHopperFloatLevel(unsigned char Hopper, unsigned int value);
void		  SetHopperDivertLevel(unsigned char Hopper, unsigned int value);
void		  SetHopperFloatZero(unsigned char Hopper);
void          SetRunMode(int rm);
void          SetCurrentState(unsigned char state);
void		  SetShellIssueNumber(unsigned char issue);
void		  SetGameInProgress(void);
void		  SetIouValue(unsigned int amount);
void		  SetFreezePlay(void);
void		  SetMeterPulses(unsigned char MeterNumber,unsigned int Count, unsigned int Value);
void		  SetAmountToPayout(signed long amount);
void		  SetRequestEmptyLeftHopper(void);
void		  SetRequestEmptyRightHopper(void);
void		  SetRequestHopperPayout(void);
void		  SetRequestRedemptionPayout(void);
void          SetPrinterStatus(unsigned char value);
void		  SetRequestTicketPrint(void);
void		  SetTicketValues(void);
void		  SetTerminalFormat(unsigned char value);
void		  SetTerminalType(unsigned char value);
void	      SetPartialCollectValue(unsigned long value, unsigned int ModelNo, unsigned char UpdateMeters);
void		  SetPartialPayoutValue(unsigned long value);
void		  SetCriticalError(long errType);
void		  SetWarningError(long errType);
void		  SetWriteToSramFlag(unsigned char value);
void		  SetProgressiveJackpotState(unsigned int value);
void		  SetProgressiveJackpotPercentage(unsigned char Type, unsigned int Value);
void		  SetProgressiveJackpotStake(unsigned char Type, unsigned int Value);
void		  SetProgressiveJackpotMaxValue(unsigned char Type, unsigned long Value);
void          SetTPlaySessionActive();
void          SetInTournamentPlay(int Value);
void		  SetHopperDumpSwitchActive(unsigned char Value);
void		  SetUsesBackOffice(unsigned char Value);
void		  SetNewDataDay(unsigned char Value);
void		  SetStakeMatchActive(unsigned char Value);
void		  SetHandPayThreshold(unsigned int Value);
void		  SetHardwareType(unsigned char Value);
void		  SetRecyclerChannel(unsigned char Value);
void		  SetRecyclerFloatValue(unsigned int Value);
void		  SetBnvType(unsigned char Value);
void		  SetMinimumBetValue(unsigned int Value);
void		  SetVolumeControlType(unsigned char Value);
void		  SetLastPayoutType(unsigned char Value);
void          SetDynamicGameSelectionState(unsigned char Value);
void		  SetDGSTargetGame(unsigned int Value);
void		  SetNewGame2Promo(unsigned int Value);
void		  SetNewGamePromoDays(unsigned int Value);
void          SetActiveGameManagementState(unsigned char Value);


BOOL		  SetOutputOn(unsigned char port_offset,unsigned char output_bit);
BOOL		  SetOutputOff(unsigned char port_offset,unsigned char output_bit);
void		  SetOutputs( LPBYTE outputs );

BOOL		  ShutDownBOComs();


void		  SocketThread( void * dummy);
void		  SubStakeFromCredits(unsigned int Value, unsigned int ModelNo);
unsigned long SubBankDeposit(unsigned long value);		//GV: NEW
void		  SubHopperFloatLevel(unsigned char Hopper, unsigned int value);
void          SubFromReconciliationMeters(unsigned char Meter,unsigned long tvalue);

unsigned long ZeroBankDeposit();

void	      CloseSharedMemory(void);
void		  DisableNoteValidator(void);
void		  EnableNoteValidator(void);
void          GroupRequest(char action);
void		  OutputKeySwitchStatus(void);
void		  output_door_status(void);

char          StartPayoutProcess(unsigned long value, 
								 bool PayInFull, 
								 unsigned int ModelNo, 
								 unsigned char ProgJackpotWin, 
								 unsigned char ForceType=0);

void		  StartPrintLoop(unsigned long value, unsigned int ModelNo, unsigned char ProgJackpotWin);
unsigned int  TransferFromBankToCredits(void);
int			  ProcessPrintQue(void);
int			  ProcessTestPrintQue(void);	



BOOL		  OpenBOSocket(char th);
BOOL		  CloseBOSocket(void);
void		  LoadPrintLogoIntoRam(unsigned int ModelNumber);

#endif






