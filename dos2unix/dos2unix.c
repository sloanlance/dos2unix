#ifndef __TURBOC__
#endif
#ifdef __TURBOC__
#define __FLAT__
#endif
  int ConvMode;                         /* 0: ascii, 1: 7bit, 2: iso, 3: mac */  
   convmode       ascii, 7bit, iso, mac, default to ascii\n\
 -L --license     display software license\n\
 -l --newline     add additional newline\n\
      case 0: /* ascii */
      case 1: /* 7bit */
      case 2: /* iso */
            /* TempChar is a CR */
            if (putc('\x0a', ipOutF) == EOF) /* MAC line end (CR). Put LF */
            if (ipFlag->NewLine) {  /* add additional LF? */
              putc('\x0a', ipOutF);
            }
#ifdef __TURBOC__
char *dirname(char *path)
{
  char *ptr;

  if (( path == NULL) || (((ptr=strrchr(path,'/')) == NULL) && ((ptr=strrchr(path,'\\')) == NULL)) )
    return ".";
  else
  {
    *ptr = '\0';
    return(path);
  }
}
#endif

#ifndef NO_FCHMOD
#endif
#ifndef NO_FCHMOD
#endif
  char *ptr;
  if ( ((ptr=strrchr(argv[0],'/')) == NULL) && ((ptr=strrchr(argv[0],'\\')) == NULL) )
    ptr = argv[0];
  else
    ptr++;

  if ((strcmpi("mac2unix", ptr) == 0) || (strcmpi("mac2unix.exe", ptr) == 0))
    pFlag->ConvMode = 3;
          if (strcmpi(argv[ArgIdx],"ascii") == 0)
          else if (strcmpi(argv[ArgIdx], "7bit") == 0)
          else if (strcmpi(argv[ArgIdx], "iso") == 0)
          else if (strcmpi(argv[ArgIdx], "mac") == 0)