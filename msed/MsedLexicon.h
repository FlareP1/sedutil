/* C:B**************************************************************************
This software is Copyright 2014,2015 Michael Romeo <r0m30@r0m30.com>

This file is part of msed.

msed is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

msed is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with msed.  If not, see <http://www.gnu.org/licenses/>.

 * C:E********************************************************************** */
#pragma once
/*
 * Define the structures and enums needed to map the
 * Opal SSC Pseudo code to procedures.
 *
 * no effort has been made to be complete, these are the values
 * that are required for the basic functionality provided in this
 * program.
 */

/** User IDs used in the TCG storage SSCs */
static const uint8_t OPALUID[][8]{
	// users
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff}, /**< session management  */
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }, /**< special "thisSP" syntax */
	{ 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x00, 0x01 }, /**< Administrative SP */
	{ 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x00, 0x02 }, /**< Locking SP */
	{ 0x00, 0x00, 0x02, 0x05, 0x00, 0x01, 0x00, 0x01 }, /**< ENTERPRISE Locking SP  */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x01 }, /**<anybody */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x06 }, /**< SID */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x01, 0x00, 0x01 }, /**< ADMIN1 */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x03, 0x00, 0x01 }, /**< USER1 */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x01, 0xff, 0x01 }, /**< PSID user */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x80, 0x01 }, /**< BandMaster 0 */
	{ 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x84, 0x01 }, /**< EraseMaster */
	// tables
	{ 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x00, 0x01 }, /**< Locking_GlobalRange */
	{ 0x00, 0x00, 0x08, 0x03, 0x00, 0x00, 0x00, 0x01 }, /**< MBR Control */
        { 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00 }, /**< Shadow MBR */
        { 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00}, /**< AUTHORITY_TABLE */
        { 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x00}, /**< C_PIN_TABLE */
		{ 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x01 }, /**< OPAL Locking Info */
		{ 0x00, 0x00, 0x08, 0x01, 0x00, 0x00, 0x00, 0x00 }, /**< Enterprise Locking Info */
        //C_PIN_TABLE object ID's
        { 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x84, 0x02}, /**< C_PIN_MSID */
        { 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x01}, /**< C_PIN_SID */
        { 0x00, 0x00, 0x00, 0x0B, 0x00, 0x01, 0x00, 0x01}, /**< C_PIN_ADMIN1 */
        // special value for omitted optional parameter
        { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /**< HEXFF for omitted */
};
/** Enum to index OPALUID array */
typedef enum _OPAL_UID {
    // users
    OPAL_SMUID_UID,
    OPAL_THISSP_UID,
    OPAL_ADMINSP_UID,
    OPAL_LOCKINGSP_UID,
	ENTERPRISE_LOCKINGSP_UID,
    OPAL_ANYBODY_UID,
    OPAL_SID_UID,
    OPAL_ADMIN1_UID,
    OPAL_USER1_UID,
    OPAL_PSID_UID,
	ENTERPRISE_BANDMASTER0_UID,
	ENTERPRISE_ERASEMASTER_UID,
    // tables
    OPAL_LOCKINGRANGE_GLOBAL,
    OPAL_MBRCONTROL,
    OPAL_MBR,
    OPAL_AUTHORITY_TABLE,
    OPAL_C_PIN_TABLE,
	OPAL_LOCKING_INFO_TABLE,
	ENTERPRISE_LOCKING_INFO_TABLE,
    //C_PIN_TABLE object ID's
    OPAL_C_PIN_MSID,
    OPAL_C_PIN_SID,
    OPAL_C_PIN_ADMIN1,
    // omitted optional parameter
    OPAL_UID_HEXFF,
} OPAL_UID;

/** TCG Storage SSC Methods.
 */
static const uint8_t OPALMETHOD[][8]{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01}, /**< Properties */
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x02}, /**<STARTSESSION */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x02}, /**< Revert */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x03}, /**< Activate */
	{ 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06 }, /**< Enterprise Get */
	{ 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07 }, /**< Enterprise Set */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08}, /**< NEXT */
	{ 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0c }, /**< Enterprise Authenticate */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x0d}, /**< GetACL */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x10}, /**< GenKey */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x11}, /**< revertSP */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x16}, /**<Get */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x17}, /**< Set */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x1c}, /**< Authenticate */
    { 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x06, 0x01}, /**< Random */
	{ 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x08, 0x03 }, /**< Erase */
};
/** Enum for indexing the OPALMETHOD array */
typedef enum _OPAL_METHOD {
    PROPERTIES,
    STARTSESSION,
    REVERT,
    ACTIVATE,
	EGET,
	ESET,
    NEXT,
	EAUTHENTICATE,
    GETACL,
    GENKEY,
    REVERTSP,
    GET,
    SET,
    AUTHENTICATE,
    RANDOM,
	ERASE,
} OPAL_METHOD;

/** Opal SSC TOKENS
 * Single byte non atom tokens used in Opal SSC psuedo code
 */
typedef enum _OPAL_TOKEN {
    //Boolean
	OPAL_TRUE = 0x01,
	OPAL_FALSE = 0x00,
	// cellblocks
	TABLE = 0x00,
	STARTROW = 0x01,
	ENDROW = 0x02,
	STARTCOLUMN = 0x03,
	ENDCOLUMN = 0x04,
	VALUES = 0x01,
	// authority table
	PIN = 0x03,
	// locking tokens
	RANGESTART = 0x03,
	RANGELENGTH = 0x04,
	READLOCKENABLED = 0x05,
	WRITELOCKENABLED = 0x06,
	READLOCKED = 0x07,
	WRITELOCKED = 0x08,
	ACTIVEKEY = 0x0A,
	//locking info table
	MAXRANGES = 0x04,
    // mbr control
    MBRENABLE = 0x01,
    MBRDONE = 0x02,
	// properties
	HOSTPROPERTIES =0x00,
    // response tokenis() returned values
    MSED_TOKENID_BYTESTRING = 0xe0,
    MSED_TOKENID_SINT = 0xe1,
    MSED_TOKENID_UINT = 0xe2,
    MSED_TOKENID_TOKEN = 0xe3, // actual token is returned
    // atoms
    STARTLIST = 0xf0,
    ENDLIST = 0xf1,
    STARTNAME = 0xf2,
    ENDNAME = 0xf3,
    CALL = 0xf8,
    ENDOFDATA = 0xf9,
    ENDOFSESSION = 0xfa,
    STARTTRANSACTON = 0xfb,
    ENDTRANSACTON = 0xfC,
    EMPTYATOM = 0xff,
    WHERE = 0x00,
} OPAL_TOKEN;

/** Useful tiny atoms.
 * Useful for table columns etc
 */
typedef enum _OPAL_TINY_ATOM {
    UINT_00 = 0x00,
    UINT_01 = 0x01,
    UINT_02 = 0x02,
    UINT_03 = 0x03,
    UINT_04 = 0x04,
    UINT_05 = 0x05,
    UINT_06 = 0x06,
    UINT_07 = 0x07,
    UINT_08 = 0x08,
    UINT_09 = 0x09,
    UINT_10 = 0x0a,
    UINT_11 = 0x0b,
    UINT_12 = 0x0c,
    UINT_13 = 0x0d,
    UINT_14 = 0x0e,
    UINT_15 = 0x0f,
} OPAL_TINY_ATOM;

/** Useful short atoms.
 */
typedef enum _OPAL_SHORT_ATOM {
    BYTESTRING8 = 0xa8,
} OPAL_SHORT_ATOM;
/** Locking state for a locking range */
typedef enum _OPAL_LOCKINGSTATE {
	READWRITE = 0x01,
	READONLY = 0x02,
	LOCKED = 0x03,
} OPAL_LOCKINGSTATE;
/*
 * Structures to build and decode the Opal SSC messages
 * fields that are NOT really numeric are defined as uint8_t[] to
 * help reduce the endianess issues
 */

/** method status codes.
 */
typedef enum _OPALSTATUSCODE {
    SUCCESS = 0x00,
    NOT_AUTHORIZED = 0x01,
    //	OBSOLETE = 0x02,
    SP_BUSY = 0x03,
    SP_FAILED = 0x04,
    SP_DISABLED = 0x05,
    SP_FROZEN = 0x06,
    NO_SESSIONS_AVAILABLE = 0x07,
    UNIQUENESS_CONFLICT = 0x08,
    INSUFFICIENT_SPACE = 0x09,
    INSUFFICIENT_ROWS = 0x0A,
	INVALID_FUNCTION = 0x0B, // defined in early specs, still used in some firmware
    INVALID_PARAMETER = 0x0C,
    INVALID_REFERENCE = 0x0D,
    //	OBSOLETE = 0x0E,
    TPER_MALFUNCTION = 0x0F,
    TRANSACTION_FAILURE = 0x10,
    RESPONSE_OVERFLOW = 0x11,
    AUTHORITY_LOCKED_OUT = 0x12,
    FAIL = 0x3f,
} OPALSTATUSCODE;
