/* /////////////////////////////////////////////////////////////////////////////
 * File:    openrj/openrj.h
 *
 * Purpose: Root header file for the Open-RJ library
 *
 * Created: 11th June 2004
 * Updated: 8th August 2005
 *
 * Home:    http://openrj.org/
 *
 * Copyright 2004-2005, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the names of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////////// */


/** \file openrj/openrj.h This is the root file of the Open-RJ C-API
 *
 */

#ifndef OPENRJ_INCL_H_OPENRJ
#define OPENRJ_INCL_H_OPENRJ

/* /////////////////////////////////////////////////////////////////////////////
 * Version information
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_H_OPENRJ_MAJOR      1
# define OPENRJ_VER_H_OPENRJ_MINOR      15
# define OPENRJ_VER_H_OPENRJ_REVISION   1
# define OPENRJ_VER_H_OPENRJ_EDIT       45
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** \def OPENRJ_VER_MAJOR
 * The major version number of Open-RJ
 */

/** \def OPENRJ_VER_MINOR
 * The minor version number of Open-RJ
 */

/** \def OPENRJ_VER_REVISION
 * The revision version number of Open-RJ
 */

/** \def OPENRJ_VER
 * The current composite version number of Open-RJ
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# define OPENRJ_VER_1_0_1       0x01000100
# define OPENRJ_VER_1_1_1       0x01010100
# define OPENRJ_VER_1_1_2       0x01010200
# define OPENRJ_VER_1_2_1       0x01020100
# define OPENRJ_VER_1_2_2       0x01020200
# define OPENRJ_VER_1_3_1       0x01030100
# define OPENRJ_VER_1_3_2       0x01030200
# define OPENRJ_VER_1_3_3       0x01030300
# define OPENRJ_VER_1_3_4       0x01030400
# define OPENRJ_VER_1_4_1       0x01040100
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

#define OPENRJ_VER_MAJOR    1
#define OPENRJ_VER_MINOR    4
#define OPENRJ_VER_REVISION 1

#define OPENRJ_VER  OPENRJ_VER_1_4_1

/* /////////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <stddef.h>     /* for size_t */

/* /////////////////////////////////////////////////////////////////////////////
 * Documentation
 */

/** \mainpage What is Open-RJ?
 *
 * \htmlonly
 <table width = "100%"><tr><td align="center">
 * \endhtmlonly
 * \ref section_what_is_openrj "Intro" | \ref section_format |
 * \ref page_gettingstarted "Getting Started"
 * \htmlonly
 </td></tr></table>
 * \endhtmlonly
 *
 * \section section_what_is_openrj What is Open-RJ?
 *
 * This is a simple library to support the Record-Jar format (so named in the
 * excellent
 * <a href = "http://awprofessional.com/title/0131429019">The Art Of UNIX Programming</a>),
 * which is a simple, loosely structured format supporting multiple records
 * with variable fields.
 *
 * \section section_format The Open-RJ format
 *
 * Each \c ORJFieldA field is a name value pair, where the
 * name is the whitespace-trimmed leftmost portion of the line, preceeding the
 * colon separator. The value is the white-space trimmed remainder of the line.
 * Values may extend over multiple lines by use the the \c \
 * line continuation character.
 *
 * It has the following features:
 *
 * - \c %% starts a comment line
 * - blank lines are ignored
 * - \c \ continues the line onto the next
 * - whitespace is trimmed from the beginning and end of all lines, except prior to the
 *    line continuation character
 * - there is no requirement for records to have the same number of fields, or fields
 *   with the same names
 * - records may contain more than one field with the same name
 *
 * The format looks like the following:
 *
 * \htmlonly
 * <pre>
 *     %% Books data 
 *     %% Created:   28th June 2004
 *     %% Updated:   29th June 2004
 *     Author:       Donald E. Knuth
 *     Title:        Art of Computer Programming, The, Volume 1: Fundamental Algorithms
 *     Publisher:    Addison-Wesley
 *     Year:         1997
 *     Description:
 *     %% 
 *     Author:       Eric Raymond
 *     Title:        Art of UNIX Programming, The 
 *     Url:          http://www.awprofessional.com/title/0131429019
 *     Publisher:    Addison-Wesley
 *     Year:         2003
 *     Description:  This is a great book if you want to learn about the \
 *                   history of UNIX. It inspired the \
 *                   &lt;a href = "../libraries/index.html#openrj">Open-RJ&lt;/a> project
 *     %% 
 *     Author:       Rector and Sells
 *     Title:        ATL Internals
 *     Publisher:    Addison-Wesley
 *     Year:         1999
 *     Description:
 *     %% 
 * </pre>
 * \endhtmlonly
 *
 * Hence, the value of the <b>Description</b> field in the second non-empty record (which
 * is the fifth record of any type), is:
 *
 * <b>This is a great book if you want to learn about the history of UNIX. It inspired the &lt;a href = "../libraries/index.html#openrj">Open-RJ&lt;/a> project</b>
 *
 *
 * \section section_mainpage_gettingstarted Getting Started
 * 
 * This section guides you to finding sample programs for your chosed language.
 * Just click on the language below, to be taken to the example programs:
 *
 * \ref section_sample_C | \ref section_sample_Ch |
 * \ref section_sample_Cpp | \ref section_sample_Python | 
 * \ref section_sample_Ruby
 *
 */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(__cplusplus) && \
    !defined(OPENRJ_DOCUMENTATION_SKIP_SECTION) && \
    !defined(ORJ_NO_NAMESPACE)
# define ORJ_NO_NAMESPACE
#endif /* __cplusplus, etc. */

#if !defined(ORJ_NO_NAMESPACE)
/** \brief The Open-RJ root namespace - \c openrj.
 *
 * This the the root namespace for Open-RJ, and contains the C-API functions, along
 * with 
 */
namespace openrj
{
#endif /* !ORJ_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////////
 * Macros and symbols
 */

#if defined(_CH_)
# define OPENRJ_NO_STRUCT_TAG_PREFIX
#endif /* OPENRJ_DOCUMENTATION_SKIP_SECTION || _CH_ */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
# if defined(OPENRJ_NO_STRUCT_TAG_PREFIX)
#  define ORJ_TAG_NAME(x)                   x
# else /* ? OPENRJ_NO_STRUCT_TAG_PREFIX */
#  define ORJ_TAG_NAME(x)                   tag ## x
# endif /* OPENRJ_NO_STRUCT_TAG_PREFIX */
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* OPENRJ_NO_STDIO */

/* OPENRJ_NO_FILE_HANDLING */

#if defined(OPENRJ_NO_FILE_HANDLING)
# define OPENRJ_NO_STDIO
#endif /* OPENRJ_NO_FILE_HANDLING */

/* /////////////////////////////////////////////////////////////////////////////
 * Ch
 */

#ifdef _CH_
# include <chdl.h>
LOAD_CHDL_CODE(openrjch, OpenRJ)
#endif /* _CH_ */

/* /////////////////////////////////////////////////////////////////////////////
 * Types
 */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef unsigned char           orj_byte_t;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** Character type used by Open-RJ
 *
 * \note As of the current implementation, this is always defined to char
 */
typedef char                    orj_char_t;
/* typedef wchar_t           orj_char_t; */

#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION

# ifdef __cplusplus
#  define ORJ_EXTERN_C_         extern "C"
# else /* ? __cplusplus */
#  define ORJ_EXTERN_C_         extern
# endif /* !__cplusplus */
# define ORJ_CALL(rt)           ORJ_EXTERN_C_ rt

#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** \brief The flags passed to the database creation functions
 */
enum ORJ_TAG_NAME(ORJ_FLAG)
{
        ORJ_FLAG_ORDERFIELDS        =   0x0001  /*!< Arranges the fields in alphabetical order */
    ,   ORJ_FLAG_ELIDEBLANKRECORDS  =   0x0002  /*!< Causes blank records to be ignored */
#ifdef __cplusplus
    ,   ORDER_FIELDS                =   ORJ_FLAG_ORDERFIELDS
    ,   ELIDE_BLANK_RECORDS         =   ORJ_FLAG_ELIDEBLANKRECORDS
#endif /* __cplusplus */
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef enum ORJ_TAG_NAME(ORJ_FLAG)         ORJ_FLAG;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** \brief The return code type of the Open-RJ API
 */
enum ORJ_TAG_NAME(ORJRC)
{
/*[OPENRJ:Errors-start]*/
        ORJ_RC_SUCCESS              =   0       /*!< Operation was successful                                   */
    ,   ORJ_RC_CANNOTOPENJARFILE                /*!< The given file does not exist, or cannot be accessed       */
    ,   ORJ_RC_NORECORDS                        /*!< The database file contained no records                     */
    ,   ORJ_RC_OUTOFMEMORY                      /*!< The API suffered memory exhaustion                         */
    ,   ORJ_RC_BADFILEREAD                      /*!< A read operation failed                                    */
    ,   ORJ_RC_PARSEERROR                       /*!< Parsing of the database file failed due to a syntax error  */
    ,   ORJ_RC_INVALIDINDEX                     /*!< An invalid index was specified                             */
    ,   ORJ_RC_UNEXPECTED                       /*!< An unexpected condition was encountered                    */
    ,   ORJ_RC_INVALIDCONTENT                   /*!< The database file contained invalid content                */
/*[OPENRJ:Errors-end]*/
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef enum ORJ_TAG_NAME(ORJRC)            ORJRC;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** \brief Parsing error constants
 */
enum ORJ_TAG_NAME(ORJ_PARSE_ERROR)
{
/*[OPENRJ:ParseErrors-start]*/
        ORJ_PARSE_SUCCESS           =   0       /*!< Parsing was successful                                                         */
    ,   ORJ_PARSE_RECORDSEPARATORINCONTINUATION /*!< A record separator was encountered during a content line continuation          */
    ,   ORJ_PARSE_UNFINISHEDLINE                /*!< The last line in the database was not terminated by a line-feed                */
    ,   ORJ_PARSE_UNFINISHEDFIELD               /*!< The last record in the database file was not terminated by a record separator  */
    ,   ORJ_PARSE_UNFINISHEDRECORD              /*!< The last record in the database file was not terminated by a record separator  */
/*[OPENRJ:ParseErrors-end]*/
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef enum ORJ_TAG_NAME(ORJ_PARSE_ERROR)  ORJ_PARSE_ERROR;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */


/** \brief Allocator interface for Open-RJ
 */
struct ORJ_TAG_NAME(IORJAllocator)
{
    /** Defines the "member" function for allocating memory */
    void *(*pfnAlloc)(struct ORJ_TAG_NAME(IORJAllocator) *ator, size_t cb);
    /** Defines the "member" function for reallocating memory */
    void *(*pfnRealloc)(struct ORJ_TAG_NAME(IORJAllocator) *ator, void *pv, size_t cb);
    /** Defines the "member" function for freeing memory */
    void (*pfnFree)(struct ORJ_TAG_NAME(IORJAllocator) *ator, void *pv);
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(IORJAllocator)  IORJAllocator;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/** \brief The string type (for ANSI coding)
 */
struct ORJ_TAG_NAME(ORJStringA)
{
    size_t      len;        /*!< \brief The number of characters in the string     */
    char const  *ptr;       /*!< \brief Pointer to the first element in the string */
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(ORJStringA)     ORJStringA;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

typedef ORJStringA                          ORJString;
/* typedef ORJStringW                         ORJString; */

/** \brief The field type (for ANSI coding)
 *
 * \note This structure definition is subject to change, and is not guaranteed
 * to be available in future versions. You are advised to use the Field
 * manipulation functions.
 */
struct ORJ_TAG_NAME(ORJFieldA)
{
    size_t      mbz0;       /*!< \brief Reserved: must be 0 */
    ORJStringA  name;       /*!< \brief The field name */
    ORJStringA  value;      /*!< \brief The field value */
    void        *reserved0; /*!< \brief Reserved: cannot be used by client code */

};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(ORJFieldA)      ORJFieldA;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

typedef ORJFieldA                           ORJField;
/* typedef ORJFieldW                          ORJField; */

/** \brief The record type (for ANSI coding)
 *
 * \note This structure definition is subject to change, and is not guaranteed
 * to be available in future versions. You are advised to use the Record
 * manipulation functions.
 */

struct ORJ_TAG_NAME(ORJRecordA)
{
    size_t      mbz0;       /*!< \brief Reserved: must be 0 */
    size_t      numFields;  /*!< \brief The number of fields in the record */
    ORJFieldA   *fields;    /*!< \brief The field array */
    void        *reserved0; /*!< \brief Reserved: cannot be used by client code */
    ORJStringA  comment;    /*!< \brief The record comment */

};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(ORJRecordA)     ORJRecordA;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

typedef ORJRecordA                          ORJRecord;
/* typedef ORJRecordW                         ORJRecord; */


/** \brief The database type (for ANSI coding)
 *
 * \note This structure definition is subject to change, and is not guaranteed
 * to be available in future versions. You are advised to use the Database
 * manipulation functions.
 */

struct ORJ_TAG_NAME(ORJDatabaseA)
{
    size_t          mbz0;       /*!< \brief Reserved: must be 0 */
    size_t          flags;      /*!< \brief Holds the flags passed to the function used to create the database */
    size_t          numLines;   /*!< \brief The number of lines in the database */
    size_t          numFields;  /*!< \brief The number of fields in the database */
    ORJFieldA       *fields;    /*!< \brief The record array */
    size_t          numRecords; /*!< \brief The number of records in the database */
    ORJRecordA      *records;   /*!< \brief The record array */
    IORJAllocator   *ator;      /*!< \brief The allocator */

};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(ORJDatabaseA)   ORJDatabaseA;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

typedef ORJDatabaseA                        ORJDatabase;
/* typedef ORJDatabaseW                       ORJDatabase; */

/** \brief Parsing error structure
 */

struct ORJ_TAG_NAME(ORJError)
{
    size_t          reserved0;      /*!< \brief Reserved: must not be accessed                         */
    unsigned        invalidLine;    /*!< \brief The line on which the parsing error was encountered    */
    unsigned        invalidColumn;  /*!< \brief The column on which the parsing error was encountered  */
    ORJ_PARSE_ERROR parseError;     /*!< \brief The type of the parsing error                          */
};
#ifndef OPENRJ_DOCUMENTATION_SKIP_SECTION
typedef struct ORJ_TAG_NAME(ORJError)       ORJError;
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////////
 * API
 */

/***************************************
 * Database manipulation functions
 */

/** \name Database manipulation functions
 *
 * \ingroup group_openrj
 */
/** @{ */

#ifndef OPENRJ_NO_FILE_HANDLING
/** \brief Reads the records from the given file into an Open-RJ databsae
 *
 * \param jarName Name of the Record-JAR file. May not be NULL
 * \param ator The allocator to use for allocating memory, May be NULL, in which case CRT malloc() / realloc() / free() are used
 * \param flags Combination of the \link #ORJ_FLAG ORJ_FLAG \endlink enumeration
 * \param error Pointer to an error structure, which is filled out with information if a parsing error is encountered
 * \param pdatabase Pointer to a database pointer, in which will be returned the database. May not be NULL. The returned pointer
 * must be freed using ORJ_FreeDatabaseA().
 */
ORJ_CALL(ORJRC) ORJ_ReadDatabaseA(  /* [in] */ char const           *jarName
                                ,   /* [in] */ IORJAllocator        *ator
                                ,   /* [in] */ unsigned             flags
                                ,   /* [out] */ ORJDatabaseA const  **pdatabase
                                ,   /* [out] */ ORJError            *error);
#endif /* !OPENRJ_NO_FILE_HANDLING */

/** \brief Reads the records from the memory block into an Open-RJ databsae
 *
 * \param contents Pointer to the base of the memory contents to parse. May not be NULL
 * \param cbContents Number of bytes in the memory contents to parse
 * \param ator The allocator to use for allocating memory, May be NULL, in which case CRT malloc() / realloc() / free() are used
 * \param flags Combination of the ORJ_FLAG enumeration
 * \param error Pointer to an error structure, which is filled out with information if a parsing error is encountered
 * \param pdatabase Pointer to a database pointer, in which will be returned the database. May not be NULL. The returned pointer
 * must be freed using ORJ_FreeDatabaseA().
 */
ORJ_CALL(ORJRC) ORJ_CreateDatabaseFromMemoryA(  /* [in] */ char const           *contents
                                            ,   /* [in] */ size_t               cbContents
                                            ,   /* [in] */ IORJAllocator        *ator
                                            ,   /* [in] */ unsigned             flags
                                            ,   /* [out] */ ORJDatabaseA const  **pdatabase
                                            ,   /* [out] */ ORJError            *error);


/** \brief Frees the resources associated with the database
 *
 * \param database The database. May not be NULL
 */
ORJ_CALL(ORJRC) ORJ_FreeDatabaseA(/* [in] */ ORJDatabaseA const     *database);


/** \brief Gives the number of lines in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
ORJ_CALL(size_t) ORJ_Database_GetNumLinesA(/* [in] */ ORJDatabaseA const    *database);

/** \brief Gives the number of fields in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
ORJ_CALL(size_t) ORJ_Database_GetNumFieldsA(/* [in] */ ORJDatabaseA const   *database);

/** \brief Gives the number of records in a database
 *
 * \param database The database. May not be NULL
 * \note The database is assumed valid. There is no error return
 */
ORJ_CALL(size_t) ORJ_Database_GetNumRecordsA(/* [in] */ ORJDatabaseA const  *database);

/** \brief Gives the number of records in a database
 *
 * \param database The database from which the record is to be retrieved
 * \param iRecord Index of the record to be retrieved
 * \param precord Pointer to a record pointer. The returned value points at the requested record stucture
 */
ORJ_CALL(ORJRC) ORJ_Database_GetRecordA(/* [in] */ ORJDatabaseA const   *database
                                    ,   /* [in] */ size_t               iRecord
                                    ,   /* [in] */ ORJRecordA const     **precord);


/** @} */

/***************************************
 * Record manipulation functions
 */

/** \name Record manipulation functions
 *
 * These functions may be used instead of direct manipulation of the data
 * structures, which may be necessary when mapping the API to other languages
 * which can only deal in opaque values and function calls (e.g. JNI).
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the number of fields in a record
 *
 * \param record The record. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
ORJ_CALL(size_t) ORJ_Record_GetNumFieldsA(  /* [in] */ ORJRecordA const *record);

/** \brief Gives the number of field in a record
 *
 * \param record The record from which to retrieve the field
 * \param iField Index of the field to be retrieved
 * \param pfield Pointer to a field pointer. The returned value points at the requested field stucture
 */
ORJ_CALL(ORJRC) ORJ_Record_GetFieldA(       /* [in] */ ORJRecordA const *record
                                        ,   /* [in] */ size_t           iField
                                        ,   /* [in] */ ORJFieldA const  **pfield);

/** \brief Finds a field in a record, based on the name and, optionally, the value
 *
 * \param record The record from which to retrieve the field
 * \param fieldName The name of the field
 * \param fieldValue The value of the field. May be NULL, in which case the first record with the given
 * name will be returned, irrespective of its value.
 */
ORJ_CALL(ORJFieldA const*) ORJ_Record_FindFieldByNameA( /* [in] */ ORJRecordA const *record
                                                    ,   /* [in] */ char const       *fieldName
                                                    ,   /* [in] */ char const       *fieldValue);

/** \brief Finds a field in a record, relative to a specified field, based on optional name and/or value
 *
 * \param record The record from which to retrieve the field
 * \param fieldAfter The field to start the search from. NULL to get the first field.
 * \param fieldName The name of the field. May be NULL for no filtering on name
 * \param fieldValue The value of the field. May be NULL for no filtering on value
 */
ORJ_CALL(ORJFieldA const*) ORJ_Record_FindNextFieldA(   /* [in] */ ORJRecordA const *record
                                                    ,   /* [in] */ ORJFieldA const  *fieldAfter /* = NULL */
                                                    ,   /* [in] */ char const       *fieldName  /* = NULL */
                                                    ,   /* [in] */ char const       *fieldValue /* = NULL */);

/** \brief Gives the database associated with the record
 *
 * \param record The record. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
ORJ_CALL(ORJDatabaseA const*) ORJ_Record_GetDatabaseA(  /* [in] */ ORJRecordA const *record);


/** \brief Gives the record comment
 *
 * \param record The record from which to retrieve the field
 * \param pcomment Pointer to a comment pointer. The returned value points at the comment
 */
ORJ_CALL(ORJRC) ORJ_Record_GetCommentA(     /* [in] */ ORJRecordA const *record
                                        ,   /* [in] */ ORJStringA const **pcomment);


/** @} */

/***************************************
 * Field manipulation functions
 */

/** \name Field manipulation functions
 *
 * These functions may be used instead of direct manipulation of the data
 * structures, which may be necessary when mapping the API to other languages
 * which can only deal in opaque values and function calls (e.g. JNI).
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the name of a field
 *
 * \param field The field whose name is to be retrieved
 * \param pname Pointer to a string pointer. The returned value points at a string
 * structure representing the name
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJ_CALL(ORJRC) ORJ_Field_GetNameA(         /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname);

/** \brief Gives the value of a field
 *
 * \param field The field whose value is to be retrieved
 * \param pvalue Pointer to a string pointer. The returned value points at a string
 * structure representing the value
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJ_CALL(ORJRC) ORJ_Field_GetValueA(        /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pvalue);

/** \brief Gives the name and value of a field
 *
 * \param field The field whose value is to be retrieved
 * \param pname Pointer to a string pointer. The returned value points at a string
 * structure representing the name
 * \param pvalue Pointer to a string pointer. The returned value points at a string
 * structure representing the value
 * \note In the current implementation, the field is assumed valid, and the return value
 * is always ORJ_RC_SUCCESS
 */
ORJ_CALL(ORJRC) ORJ_Field_GetNameAndValueA( /* [in] */ ORJFieldA const  *field
                                        ,   /* [in] */ ORJStringA const **pname
                                        ,   /* [in] */ ORJStringA const **pvalue);

/** \brief Gives the record associated with the field
 *
 * \param field The field. May not be NULL
 * \note The record is assumed valid. There is no error return
 */
ORJ_CALL(ORJRecordA const*) ORJ_Field_GetRecordA(  /* [in] */ ORJFieldA const *field);

/** @} */


/***************************************
 * Error functions
 */

/** \name Error functions
 *
 * \ingroup group_openrj
 */
/** @{ */

/** \brief Gives the name of the error
 *
 * \param errorCode The error whose name is to be retrieved
 * \note If the error is not recognised, the function returns the empty string ("")
 */
ORJ_CALL(char const *) ORJ_GetErrorStringA( /* [in] */ ORJRC            errorCode);

/** \brief Gives the length of the error string returned by ORJ_GetErrorStringA()
 *
 * \param errorCode The error whose name is to be retrieved
 * \note If the error is not recognised, the function returns 0
 */
ORJ_CALL(size_t) ORJ_GetErrorStringLengthA( /* [in] */ ORJRC            errorCode);

/** \brief Gives the name of the parse-error
 *
 * \param errorCode The parse-error whose name is to be retrieved
 * \note If the error is not recognised, the function returns the empty string ("")
 */
ORJ_CALL(char const *) ORJ_GetParseErrorStringA( /* [in] */ ORJ_PARSE_ERROR errorCode);

/** \brief Gives the length of the error string returned by ORJ_GetParseErrorStringA()
 *
 * \param errorCode The error whose name is to be retrieved
 * \note If the error is not recognised, the function returns 0
 */
ORJ_CALL(size_t) ORJ_GetParseErrorStringLengthA( /* [in] */ ORJ_PARSE_ERROR errorCode);


/* \brief Formats an error string 
 *
 * Formats an error string, specifying information for error code and parse
 * error structure information.
 *
 * \param dest Pointer to a character buffer to receive the formatted results
 * \param cchDest Length of dest in characters
 * \param rc The Open-RJ result code
 * \param error The Open-RJ parsing error structure. Only consulted if 
 *   rc == ORJ_RC_PARSEERROR. May be NULL.
 * \param fmt Format string. May contain the special format specifier %E, which
 *   the formatted error string will replace. If the %E is not specified, then
 *   ": " and the formatted error string will be appended to the end of the
 *   string.
 *
 * \note Length of fmt string must be <= 768 characters
 *
 */

ORJ_CALL(int) ORJ_FormatErrorA( /* [in] */ char             *dest
                            ,   /* [in] */ size_t           cchDest
                            ,   /* [in] */ ORJRC            rc
                            ,   /* [in] */ ORJError const   *error  /* = NULL */
                            ,   /* [in] */ char const       *fmt
                            ,   /* [in] */ ...
                            );

/** @} */


# if !defined(OPENRJ_DOCUMENTATION_SKIP_SECTION) && \
     !defined(OPENRJ_PURE_API)
/***************************************
 * Implementation functions
 *
 * \note These are subject to change in a future version
 */

# ifndef __cplusplus
#  define ORJ_Database_GetNumLinesA(database)   ((size_t)(database)->numLines)
#  define ORJ_Database_GetNumFieldsA(database)  ((size_t)(database)->numFields)
#  define ORJ_Database_GetNumRecordsA(database) ((size_t)(database)->numRecords)
#  define ORJ_Record_GetNumFieldsA(record)      ((size_t)(record)->numFields)
#else /* ? __cplusplus */

#  define ORJ_Database_GetNumLinesA             ORJ_Database_GetNumLinesA_
inline size_t ORJ_Database_GetNumLinesA_(/* [in] */ ORJDatabaseA const *database)
{
    return database->numLines;
}

#  define ORJ_Database_GetNumFieldsA            ORJ_Database_GetNumFieldsA_
inline size_t ORJ_Database_GetNumFieldsA_(/* [in] */ ORJDatabaseA const *database)
{
    return database->numFields;
}
#  define ORJ_Database_GetNumRecordsA           ORJ_Database_GetNumRecordsA_
inline size_t ORJ_Database_GetNumRecordsA_(/* [in] */ ORJDatabaseA const *database)
{
    return database->numRecords;
}

#  define ORJ_Record_GetNumFieldsA              ORJ_Record_GetNumFieldsA_
inline size_t ORJ_Record_GetNumFieldsA_(/* [in] */ ORJRecordA const *record)
{
    return record->numFields;
}

# endif /* !__cplusplus */
#endif /* !OPENRJ_DOCUMENTATION_SKIP_SECTION && !OPENRJ_PURE_API */


#ifdef __cplusplus
# ifndef OPENRJ_NO_FILE_HANDLING
/** \brief Reads the records from the given file into an Open-RJ databsae
 *
 * \note An inline wrapper for ORJ_ReadDatabaseA()
 */
inline ORJRC ORJ_ReadDatabase(  /* [in] */ orj_char_t const     *jarName
                            ,   /* [in] */ IORJAllocator        *ator
                            ,   /* [in] */ unsigned             flags
                            ,   /* [out] */ ORJDatabase const   **pdatabase
                            ,   /* [out] */ ORJError            *error)
{
    return ORJ_ReadDatabaseA(jarName, ator, flags, pdatabase, error);
}
# endif /* !OPENRJ_NO_FILE_HANDLING */
/** \brief Reads the records from the memory block into an Open-RJ databsae
 *
 * \note An inline wrapper for ORJ_CreateDatabaseFromMemoryA()
 */
inline ORJRC ORJ_CreateDatabaseFromMemory(  /* [in] */ orj_char_t const     *contents
                                        ,   /* [in] */ size_t               cbContents
                                        ,   /* [in] */ IORJAllocator        *ator
                                        ,   /* [in] */ unsigned             flags
                                        ,   /* [out] */ ORJDatabaseA const  **pdatabase
                                        ,   /* [out] */ ORJError            *error)
{
    return ORJ_CreateDatabaseFromMemoryA(contents, cbContents, ator, flags, pdatabase, error);
}

/** \brief Frees the resources associated with the database
 *
 * \note An inline wrapper for ORJ_FreeDatabaseA()
 */
inline ORJRC ORJ_FreeDatabase(/* [in] */ ORJDatabase const *database)
{
    return ORJ_FreeDatabaseA(database);
}
#else /* ? __cplusplus */
# ifndef OPENRJ_NO_FILE_HANDLING
#  define ORJ_ReadDatabase                      ORJ_ReadDatabaseA
# endif /* !OPENRJ_NO_FILE_HANDLING */
# define ORJ_CreateDatabaseFromMemory           ORJ_CreateDatabaseFromMemoryA
# define ORJ_FreeDatabase                       ORJ_FreeDatabaseA
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////////
 * Shims
 */

#ifdef __cplusplus

/** \defgroup group_openrj_stringaccessshims String access shims
 *
 */

/** \name String access shims
 *
 * These functions are <a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">string access shims</a>
 * for injection into the <b>stlsoft</b> namespace, in order to facilitate
 * generalised manipulation of the \link ORJStringA \endlink, ORJRC and ORJ_PARSE_ERROR types.
 * 
 * @{
 */

/** Nul-terminated, possibly NULL, C-string representation of the given ORJStringA instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr_null(ORJStringA const &s)
{
    return (0 != s.len) ? s.ptr : NULL;
}

/** Nul-terminated C-string representation of the given ORJStringA instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr(ORJStringA const &s)
{
    return s.ptr;   /* This is ok, because Open-RJ guarantees that strings will be nul-terminated */
}

/** Nul-terminated C-string representation of the given ORJStringA instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_data(ORJStringA const &s)
{
    return s.ptr;
}

/** Length of the C-string representation of the given ORJStringA instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline size_t c_str_len(ORJStringA const &s)
{
    return s.len;
}

/** Nul-terminated, possibly NULL, C-string representation of the given ORJRC instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr_null(ORJRC rc)
{
    char const *s   =   ORJ_GetErrorStringA(rc);

    return ('\0' != s) ? s : NULL;
}

/** Nul-terminated C-string representation of the given ORJRC instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr(ORJRC rc)
{
    return ORJ_GetErrorStringA(rc);
}

/** Not necessarily nul-terminated C-string representation of the given ORJRC instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_data(ORJRC rc)
{
    return ORJ_GetErrorStringA(rc);
}

/** Length of the C-string representation of the given ORJRC instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline size_t c_str_len(ORJRC rc)
{
    return ORJ_GetErrorStringLengthA(rc);
}

/** Nul-terminated, possibly NULL, C-string representation of the given ORJ_PARSE_ERROR instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr_null(ORJ_PARSE_ERROR pe)
{
    char const *s   =   ORJ_GetParseErrorStringA(pe);

    return ('\0' != s) ? s : NULL;
}

/** Nul-terminated C-string representation of the given ORJ_PARSE_ERROR instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_ptr(ORJ_PARSE_ERROR pe)
{
    return ORJ_GetParseErrorStringA(pe);
}

/** Not necessarily nul-terminated C-string representation of the given ORJ_PARSE_ERROR instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline char const *c_str_data(ORJ_PARSE_ERROR pe)
{
    return ORJ_GetParseErrorStringA(pe);
}

/** Length of the C-string representation of the given ORJ_PARSE_ERROR instance
 *
 * \ingroup group_openrj_stringaccessshims
 */
inline size_t c_str_len(ORJ_PARSE_ERROR pe)
{
    return ORJ_GetParseErrorStringLengthA(pe);
}

/** @} String access shims */

/** \defgroup group_openrj_streaminsertionshimfunctiontemplates Stream insertion shim function templates
 *
 */

/** \name Stream insertion shims
 *
 * These functions are <a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">stream insertion shims</a>
 * for allowing the ORJStringA, ORJRC and ORJ_PARSE_ERROR types to be used
 * with stream instances, a la the IOStreams.
 *
 * For example:
 *
 * \htmlonly
 * <pre>
 *
 * ORJRecord *record = . . . ;
 *
 * std::cout << record->fields[0] << std::end; // Prints the value of the 0th field in the record
 *
 * ORJRC rc = ORJ_RC_INVALIDINDEX;
 *
 * std::cout << rc << std::end; // Prints "An invalid index was specified"
 *
 * ORJ_PARSE_ERROR pe = ORJ_PARSE_UNFINISHEDLINE;
 *
 * std::cout << pe << std::end; // Prints "The last line in the database was not terminated by a line-feed"
 *
 * </pre>
 * \endhtmlonly
 * 
 * @{
 */

/** Inserts an ORJStringA instance into a stream
 *
 * \ingroup group_openrj_streaminsertionshimfunctiontemplates
 *
 * \note stm may be of any type that supports a write(char const *str, size_t len); method
 */
template <class S>
inline S &operator <<(S &stm, ORJStringA const &s)
{
    stm.write(s.ptr, s.len);

    return stm;
}

/** Inserts an ORJRC instance into a stream
 *
 * \ingroup group_openrj_streaminsertionshimfunctiontemplates
 *
 * \note stm may be of any type that supports an insertion operator taking char const*
 */
template <class S>
inline S &operator <<(S &stm, ORJRC rc)
{
    return stm << c_str_ptr(rc);
}

/** Inserts an ORJ_PARSE_ERROR instance into a stream
 *
 * \ingroup group_openrj_streaminsertionshimfunctiontemplates
 *
 * \note stm may be of any type that supports an insertion operator taking char const*
 */
template <class S>
inline S &operator <<(S &stm, ORJ_PARSE_ERROR pe)
{
    return stm << c_str_ptr(pe);
}

/** @} String insertion shim function templates */

#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(ORJ_NO_NAMESPACE)
} /* namespace openrj */

#ifdef OPENRJ_DOCUMENTATION_SKIP_SECTION
/** The Open-RJ project inserts c_str_ptr, c_str_data and c_str_len 
 * <a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">string access shims</a> 
 * into the STLSoft namespace, for generalised manipulation of its ORJStringA, ORJRC
 * and ORJ_PARSE_ERROR types.
 */
#endif /* OPENRJ_DOCUMENTATION_SKIP_SECTION */
namespace stlsoft
{
    using ::openrj::c_str_ptr_null;
    using ::openrj::c_str_ptr;
    using ::openrj::c_str_data;
    using ::openrj::c_str_len;
}

#endif /* !ORJ_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////////// */

#endif /* !OPENRJ_INCL_H_OPENRJ */

/* ////////////////////////////////////////////////////////////////////////// */
