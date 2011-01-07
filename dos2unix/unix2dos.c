 *  Copyright (C) 2009-2011 Erwin Waterlander
#define CONVMODE_ASCII  0
#define CONVMODE_7BIT   1
#define CONVMODE_437    2
#define CONVMODE_850    3
#define CONVMODE_1252   4

#define FROMTO_UNIX2DOS 0
#define FROMTO_UNIX2MAC 1

  int ConvMode;                         /* 0: ascii, 1: 7bit, 2: iso */  
  int FromToMode;                       /* 0: unix2dos, 1: unix2mac */  
 -1252            conversion mode iso cp1252\n\
 -437             conversion mode iso cp437\n\
 -7               conversion mode 7bit\n\
 -850             conversion mode iso cp850\n\
 -ascii           conversion mode ascii\n\
 -iso             conversion mode iso cp437\n\
Copyright (C) 2009-2011 Erwin Waterlander\n\
    int *ConvTable;
    switch (ipFlag->ConvMode)
    {
      case CONVMODE_ASCII: /* ascii */
        ConvTable = U2DAsciiTable;
        break;
      case CONVMODE_7BIT: /* 7bit */
        ConvTable = U2D7BitTable;
        break;
      case CONVMODE_437: /* iso */
        ConvTable = U2DIso437Table;
        break;
      case CONVMODE_850: /* iso */
        ConvTable = U2DIso850Table;
        break;
      case CONVMODE_1252: /* iso */
        ConvTable = U2DIso1252Table;
        break;
      default: /* unknown convmode */
        ConvTable = U2DAsciiTable;
    }

    switch (ipFlag->FromToMode)
      case FROMTO_UNIX2DOS: /* unix2dos */
             {
               else
               {
               }
             }
          }
          if (putc(ConvTable[TempChar], ipOutF) == EOF)
      case FROMTO_UNIX2MAC: /* unix2mac */
              if(putc(ConvTable[TempChar], ipOutF) == EOF){
      default: /* unknown FromToMode */
         fprintf(stderr, "%s", _("unix2dos: error: Value of environment variable DOS2UNIX_LOCALEDIR is too long.\n"));
  pFlag->ConvMode = CONVMODE_ASCII;  /* default ascii */
  pFlag->FromToMode = FROMTO_UNIX2DOS;  /* default unix2dos */
    pFlag->FromToMode = FROMTO_UNIX2MAC;
      else if (strcmp(argv[ArgIdx],"-ascii") == 0)  /* SunOS compatible options */
      {
        pFlag->ConvMode = CONVMODE_ASCII;
        pFlag->FromToMode = FROMTO_UNIX2DOS;
      }
      else if (strcmp(argv[ArgIdx],"-7") == 0)
        pFlag->ConvMode = CONVMODE_7BIT;
      else if ((strcmp(argv[ArgIdx],"-iso") == 0) || (strcmp(argv[ArgIdx],"-437") == 0))
        pFlag->ConvMode = CONVMODE_437;
      else if (strcmp(argv[ArgIdx],"-850") == 0)
        pFlag->ConvMode = CONVMODE_850;
      else if (strcmp(argv[ArgIdx],"-1252") == 0)
        pFlag->ConvMode = CONVMODE_1252;
          if (strcmpi(argv[ArgIdx],"ascii") == 0)  /* Benjamin Lin's legacy options */
          {
            pFlag->ConvMode = CONVMODE_ASCII;
            pFlag->FromToMode = FROMTO_UNIX2DOS;
          }
            pFlag->ConvMode = CONVMODE_7BIT;
            pFlag->ConvMode = CONVMODE_437;
            pFlag->FromToMode = FROMTO_UNIX2MAC;
              if (pFlag->FromToMode == FROMTO_UNIX2MAC)
            if (pFlag->FromToMode == FROMTO_UNIX2MAC)