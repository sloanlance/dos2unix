 *   Copyright (C) 2009-2012 Erwin Waterlander
#include <wchar.h>
#if defined(__WATCOMC__) && defined(__I86__) /* Watcom C, 16 bit Intel */
#define MSDOS
#endif

#if defined(__WATCOMC__) && defined(__DOS__) /* Watcom C, 32 bit DOS */
#define MSDOS
#endif

#define LOCALE_NOT_UTF8 0x40
#define FILE_MBS     0  /* Multi-byte string or 8-bit char */
#define FILE_UTF16LE 1  /* UTF-16 Little Endian */
#define FILE_UTF16BE 2  /* UTF-16 Big Endian */
#define FILE_UTF8    3  /* UTF-8 */

  int bomtype;                          /* byte order mark */
  int add_bom;                          /* 1: write BOM */
FILE *read_bom (FILE *f, int *bomtype);
#ifdef D2U_UNICODE
wint_t d2u_getwc(FILE *f, int bomtype);
wint_t d2u_ungetwc(wint_t wc, FILE *f, int bomtype);
wint_t d2u_putwc(wint_t wc, FILE *f);
#endif