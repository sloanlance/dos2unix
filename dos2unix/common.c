#if defined(D2U_UNICODE) && defined(WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#endif
 -m, --add-bom         add UTF-8 Byte Order Mark\n\
#ifdef D2U_UNICODE
  fprintf(stderr, "%s", _("With Unicode UTF-16 support.\n"));
#else
  fprintf(stderr, "%s", _("Without Unicode UTF-16 support.\n"));
#endif
#ifdef ENABLE_NLS
  fprintf(stderr, "%s", _("With native language support.\n"));
#else
  fprintf(stderr, "%s", "Without native language support.\n");
#endif
FILE *read_bom (FILE *f, int *bomtype)
{
  int bom[3];
  /* BOMs
   * UTF16-LE  ff fe
   * UTF16-BE  fe ff
   * UTF-8     ef bb bf
   */

  *bomtype = FILE_MBS;

   /* Check for BOM */
   if  (f != NULL)
   {
      if ((bom[0] = fgetc(f)) == EOF)
      {
         ungetc(bom[0], f);
         *bomtype = FILE_MBS;
         return(f);
      }
      if ((bom[0] != 0xff) && (bom[0] != 0xfe) && (bom[0] != 0xef))
      {
         ungetc(bom[0], f);
         *bomtype = FILE_MBS;
         return(f);
      }
      if ((bom[1] = fgetc(f)) == EOF)
      {
         ungetc(bom[1], f);
         ungetc(bom[0], f);
         *bomtype = FILE_MBS;
         return(f);
      }
      if ((bom[0] == 0xff) && (bom[1] == 0xfe)) /* UTF16-LE */
      {
         *bomtype = FILE_UTF16LE;
         return(f);
      }
      if ((bom[0] == 0xfe) && (bom[1] == 0xff)) /* UTF16-BE */
      {
         *bomtype = FILE_UTF16BE;
         return(f);
      }
      if ((bom[2] = fgetc(f)) == EOF)
      {
         ungetc(bom[2], f);
         ungetc(bom[1], f);
         ungetc(bom[0], f);
         *bomtype = FILE_MBS;
         return(f);
      }
      if ((bom[0] == 0xef) && (bom[1] == 0xbb) && (bom[2]== 0xbf)) /* UTF-8 */
      {
         *bomtype = FILE_UTF8;
         return(f);
      }
      ungetc(bom[2], f);
      ungetc(bom[1], f);
      ungetc(bom[0], f);
      *bomtype = FILE_MBS;
      return(f);
   }
  return(f);
}


#ifdef D2U_UNICODE
wint_t d2u_getwc(FILE *f, int bomtype)
{
   int c_high, c_low;
   wint_t wc;

   if (((c_low=fgetc(f)) == EOF)  || ((c_high=fgetc(f)) == EOF))
      return(WEOF);

   if (bomtype == FILE_UTF16LE)  /* UTF16 little endian */
   {
      c_high <<=8;
      wc = (wint_t)(c_high + c_low) ;
   } else {                              /* UTF16 big endian */
      c_low <<=8;
      wc = (wint_t)(c_high + c_low) ;
   }
   return(wc);
}

wint_t d2u_ungetwc(wint_t wc, FILE *f, int bomtype)
{
   int c_high, c_low;

   if (bomtype == FILE_UTF16LE)  /* UTF16 little endian */
   {
      c_high = (int)(wc & 0xff00);
      c_high >>=8;
      c_low  = (int)(wc & 0xff);
   } else {                              /* UTF16 big endian */
      c_low = (int)(wc & 0xff00);
      c_low >>=8;
      c_high  = (int)(wc & 0xff);
   }

   /* push back in reverse order */
   if ((ungetc(c_high,f) == EOF)  || (ungetc(c_low,f) == EOF))
      return(WEOF);
   return(wc);
}

/* Put wide character */
wint_t d2u_putwc(wint_t wc, FILE *f)
{
   static char mbs[8];
   int i,len;

#if defined(WIN32) && !defined(__CYGWIN__)
   /* On Windows we convert UTF-16 always to UTF-8 */
   wchar_t wstr[2];
   
   wstr[0] = (wchar_t)wc;
   wstr[1] = L'\0';

   len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, mbs, sizeof(mbs), NULL, NULL) -1;
#else
   /* On Unix we convert UTF-16 to the locale encoding */
   len = wctomb(mbs, (wchar_t)wc);
#endif

   if ( len < 0 )
   {  /* Character cannot be represented in current locale. Put a dot `.' */
      fputc(0x2e, f);
   } else {
      for (i=0; i<len; i++)
      {
         if (fputc(mbs[i], f) == EOF)
            return(WEOF);
      }
   }
   return(wc);
}
#endif