#if defined(DJGPP) || defined(__TURBOC__) /* DJGPP */
#if  defined(__TURBOC__) || defined(DJGPP) || defined(__MINGW32__)
 * BORLANDC, DJGPP, MINGW32 */
#endif

#ifdef MSDOS
 * BORLANDC, DJGPP, MINGW32, OPENWATCOM */
  int stdio_mode;                       /* if TRUE, stdio mode */
  pFlag->stdio_mode = 1;
      {
        return(0);
      }
      else if ((strcmp(argv[ArgIdx],"-k") == 0) || (strcmp(argv[ArgIdx],"--keepdate") == 0))
      else if ((strcmp(argv[ArgIdx],"-f") == 0) || (strcmp(argv[ArgIdx],"--force") == 0))
      else if ((strcmp(argv[ArgIdx],"-q") == 0) || (strcmp(argv[ArgIdx],"--quiet") == 0))
      else if ((strcmp(argv[ArgIdx],"-l") == 0) || (strcmp(argv[ArgIdx],"--newline") == 0))
      else if ((strcmp(argv[ArgIdx],"-V") == 0) || (strcmp(argv[ArgIdx],"--version") == 0))
        return(0);
      else if ((strcmp(argv[ArgIdx],"-L") == 0) || (strcmp(argv[ArgIdx],"--license") == 0))
      {
        return(0);
      }
      else if ((strcmp(argv[ArgIdx],"-c") == 0) || (strcmp(argv[ArgIdx],"--convmode") == 0))
      else if ((strcmp(argv[ArgIdx],"-o") == 0) || (strcmp(argv[ArgIdx],"--oldfile") == 0))
      else if ((strcmp(argv[ArgIdx],"-n") == 0) || (strcmp(argv[ArgIdx],"--newfile") == 0))
      else { /* wrong option */
        PrintUsage();
        return(0);
      }
      pFlag->stdio_mode = 0;
  /* no file argument, use stdin and stdout */
  if (pFlag->stdio_mode)
  {
    exit(ConvertUnixToDosStdio(pFlag));
  }

