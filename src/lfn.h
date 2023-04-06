/********************************************************************

   lfn.h

   declaration of lfn aware functions

   Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License.

********************************************************************/

#define CCHMAXFILE      MAXPATHLEN         // max size of a long name
#define CCHMAXPATHCOMP  256
#define LFNCANON_MASK           1
#define PATHLEN1_1 13

#define FILE_83_CI  0
#define FILE_83_CS  1
#define FILE_LONG   2

#define ERROR_OOM   8
#ifndef SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE
#define SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE    0x2
#endif
typedef int(__stdcall* GetLocaleInfoEx_)(LPCWSTR lpLocaleName, LCTYPE LCType, LPWSTR lpLCData, int cchData);
typedef LCID(__stdcall* LocaleNameToLCID_)(LPCWSTR lpName, DWORD dwFlags);

#ifndef IO_REPARSE_TAG_CLOUD
#define IO_REPARSE_TAG_CLOUD                    (0x9000001AL)
#endif // IO_REPARSE_TAG_CLOUD

#ifndef IO_REPARSE_TAG_CLOUD_1
#define IO_REPARSE_TAG_CLOUD_1                  (0x9000101AL)
#endif // IO_REPARSE_TAG_CLOUD_1

#ifndef IO_REPARSE_TAG_CLOUD_2
#define IO_REPARSE_TAG_CLOUD_2                  (0x9000201AL)
#endif // IO_REPARSE_TAG_CLOUD_2

#ifndef IO_REPARSE_TAG_CLOUD_3
#define IO_REPARSE_TAG_CLOUD_3                  (0x9000301AL)
#endif // IO_REPARSE_TAG_CLOUD_3

#ifndef IO_REPARSE_TAG_CLOUD_4
#define IO_REPARSE_TAG_CLOUD_4                  (0x9000401AL)
#endif // IO_REPARSE_TAG_CLOUD_4

#ifndef IO_REPARSE_TAG_CLOUD_5
#define IO_REPARSE_TAG_CLOUD_5                  (0x9000501AL)
#endif // IO_REPARSE_TAG_CLOUD_5

#ifndef IO_REPARSE_TAG_CLOUD_6
#define IO_REPARSE_TAG_CLOUD_6                  (0x9000601AL)
#endif // IO_REPARSE_TAG_CLOUD_6

#ifndef IO_REPARSE_TAG_CLOUD_7
#define IO_REPARSE_TAG_CLOUD_7                  (0x9000701AL)
#endif // IO_REPARSE_TAG_CLOUD_7

#ifndef IO_REPARSE_TAG_CLOUD_8
#define IO_REPARSE_TAG_CLOUD_8                  (0x9000801AL)
#endif // IO_REPARSE_TAG_CLOUD_8

#ifndef IO_REPARSE_TAG_CLOUD_9
#define IO_REPARSE_TAG_CLOUD_9                  (0x9000901AL)
#endif // IO_REPARSE_TAG_CLOUD_9

#ifndef IO_REPARSE_TAG_CLOUD_A
#define IO_REPARSE_TAG_CLOUD_A                  (0x9000A01AL)
#endif // IO_REPARSE_TAG_CLOUD_A

#ifndef IO_REPARSE_TAG_CLOUD_B
#define IO_REPARSE_TAG_CLOUD_B                  (0x9000B01AL)
#endif // IO_REPARSE_TAG_CLOUD_B

#ifndef IO_REPARSE_TAG_CLOUD_C
#define IO_REPARSE_TAG_CLOUD_C                  (0x9000C01AL)
#endif // IO_REPARSE_TAG_CLOUD_C

#ifndef IO_REPARSE_TAG_CLOUD_D
#define IO_REPARSE_TAG_CLOUD_D                  (0x9000D01AL)
#endif // IO_REPARSE_TAG_CLOUD_D

#ifndef IO_REPARSE_TAG_CLOUD_E
#define IO_REPARSE_TAG_CLOUD_E                  (0x9000E01AL)
#endif // IO_REPARSE_TAG_CLOUD_E

#ifndef IO_REPARSE_TAG_CLOUD_F
#define IO_REPARSE_TAG_CLOUD_F                  (0x9000F01AL)
#endif // IO_REPARSE_TAG_CLOUD_F


// we need to add an extra field to distinguish DOS vs. LFNs

typedef struct {
   HANDLE hFindFile;           // handle returned by FindFirstFile()
   DWORD dwAttrFilter;         // search attribute mask.
   DWORD err;                  // error info if failure.
   WIN32_FIND_DATA fd;         // FindFirstFile() data structure;
   INT   nSpaceLeft;           // Space left for deeper paths
} LFNDTA, *LPLFNDTA, * PLFNDTA;

VOID  LFNInit( VOID );
VOID  InvalidateVolTypes( VOID );

DWORD  GetNameType(LPTSTR);
BOOL  IsLFN(LPTSTR pName);
// BOOL  IsLFNDrive(LPTSTR);

BOOL  WFFindFirst(LPLFNDTA lpFind, LPTSTR lpName, DWORD dwAttrFilter);
BOOL  WFFindNext(LPLFNDTA);
BOOL  WFFindClose(LPLFNDTA);


DWORD  I_LFNCanon( USHORT CanonType, LPTSTR InFile, LPTSTR OutFile );
DWORD  LFNParse(LPTSTR,LPTSTR,LPTSTR);
WORD I_LFNEditName( LPTSTR lpSrc, LPTSTR lpEd, LPTSTR lpRes, INT iResBufSize );

BOOL  WFIsDir(LPTSTR);
BOOL  LFNMergePath(LPTSTR,LPTSTR);

BOOL  IsLFNSelected(VOID);


