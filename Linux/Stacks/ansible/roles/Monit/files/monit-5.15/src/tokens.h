/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    THEN = 260,
    OR = 261,
    FAILED = 262,
    SET = 263,
    LOGFILE = 264,
    FACILITY = 265,
    DAEMON = 266,
    SYSLOG = 267,
    MAILSERVER = 268,
    HTTPD = 269,
    ALLOW = 270,
    REJECTOPT = 271,
    ADDRESS = 272,
    INIT = 273,
    READONLY = 274,
    CLEARTEXT = 275,
    MD5HASH = 276,
    SHA1HASH = 277,
    CRYPT = 278,
    DELAY = 279,
    PEMFILE = 280,
    ENABLE = 281,
    DISABLE = 282,
    SSL = 283,
    CLIENTPEMFILE = 284,
    ALLOWSELFCERTIFICATION = 285,
    SELFSIGNED = 286,
    VERIFY = 287,
    CERTIFICATE = 288,
    CACERTIFICATEFILE = 289,
    CACERTIFICATEPATH = 290,
    VALID = 291,
    INTERFACE = 292,
    LINK = 293,
    PACKET = 294,
    BYTEIN = 295,
    BYTEOUT = 296,
    PACKETIN = 297,
    PACKETOUT = 298,
    SPEED = 299,
    SATURATION = 300,
    UPLOAD = 301,
    DOWNLOAD = 302,
    TOTAL = 303,
    IDFILE = 304,
    STATEFILE = 305,
    SEND = 306,
    EXPECT = 307,
    EXPECTBUFFER = 308,
    CYCLE = 309,
    COUNT = 310,
    REMINDER = 311,
    PIDFILE = 312,
    START = 313,
    STOP = 314,
    PATHTOK = 315,
    HOST = 316,
    HOSTNAME = 317,
    PORT = 318,
    IPV4 = 319,
    IPV6 = 320,
    TYPE = 321,
    UDP = 322,
    TCP = 323,
    TCPSSL = 324,
    PROTOCOL = 325,
    CONNECTION = 326,
    ALERT = 327,
    NOALERT = 328,
    MAILFORMAT = 329,
    UNIXSOCKET = 330,
    SIGNATURE = 331,
    TIMEOUT = 332,
    RETRY = 333,
    RESTART = 334,
    CHECKSUM = 335,
    EVERY = 336,
    NOTEVERY = 337,
    DEFAULT = 338,
    HTTP = 339,
    HTTPS = 340,
    APACHESTATUS = 341,
    FTP = 342,
    SMTP = 343,
    SMTPS = 344,
    POP = 345,
    POPS = 346,
    IMAP = 347,
    IMAPS = 348,
    CLAMAV = 349,
    NNTP = 350,
    NTP3 = 351,
    MYSQL = 352,
    DNS = 353,
    WEBSOCKET = 354,
    SSH = 355,
    DWP = 356,
    LDAP2 = 357,
    LDAP3 = 358,
    RDATE = 359,
    RSYNC = 360,
    TNS = 361,
    PGSQL = 362,
    POSTFIXPOLICY = 363,
    SIP = 364,
    LMTP = 365,
    GPS = 366,
    RADIUS = 367,
    MEMCACHE = 368,
    REDIS = 369,
    MONGODB = 370,
    SIEVE = 371,
    STRING = 372,
    PATH = 373,
    MAILADDR = 374,
    MAILFROM = 375,
    MAILREPLYTO = 376,
    MAILSUBJECT = 377,
    MAILBODY = 378,
    SERVICENAME = 379,
    STRINGNAME = 380,
    NUMBER = 381,
    PERCENT = 382,
    LOGLIMIT = 383,
    CLOSELIMIT = 384,
    DNSLIMIT = 385,
    KEEPALIVELIMIT = 386,
    REPLYLIMIT = 387,
    REQUESTLIMIT = 388,
    STARTLIMIT = 389,
    WAITLIMIT = 390,
    GRACEFULLIMIT = 391,
    CLEANUPLIMIT = 392,
    REAL = 393,
    CHECKPROC = 394,
    CHECKFILESYS = 395,
    CHECKFILE = 396,
    CHECKDIR = 397,
    CHECKHOST = 398,
    CHECKSYSTEM = 399,
    CHECKFIFO = 400,
    CHECKPROGRAM = 401,
    CHECKNET = 402,
    CHILDREN = 403,
    STATUS = 404,
    ORIGIN = 405,
    VERSIONOPT = 406,
    RESOURCE = 407,
    MEMORY = 408,
    TOTALMEMORY = 409,
    LOADAVG1 = 410,
    LOADAVG5 = 411,
    LOADAVG15 = 412,
    SWAP = 413,
    MODE = 414,
    ACTIVE = 415,
    PASSIVE = 416,
    MANUAL = 417,
    CPU = 418,
    TOTALCPU = 419,
    CPUUSER = 420,
    CPUSYSTEM = 421,
    CPUWAIT = 422,
    GROUP = 423,
    REQUEST = 424,
    DEPENDS = 425,
    BASEDIR = 426,
    SLOT = 427,
    EVENTQUEUE = 428,
    SECRET = 429,
    HOSTHEADER = 430,
    UID = 431,
    EUID = 432,
    GID = 433,
    MMONIT = 434,
    INSTANCE = 435,
    USERNAME = 436,
    PASSWORD = 437,
    TIMESTAMP = 438,
    CHANGED = 439,
    SECOND = 440,
    MINUTE = 441,
    HOUR = 442,
    DAY = 443,
    MONTH = 444,
    SSLAUTO = 445,
    SSLV2 = 446,
    SSLV3 = 447,
    TLSV1 = 448,
    TLSV11 = 449,
    TLSV12 = 450,
    CERTMD5 = 451,
    AUTO = 452,
    BYTE = 453,
    KILOBYTE = 454,
    MEGABYTE = 455,
    GIGABYTE = 456,
    INODE = 457,
    SPACE = 458,
    TFREE = 459,
    PERMISSION = 460,
    SIZE = 461,
    MATCH = 462,
    NOT = 463,
    IGNORE = 464,
    ACTION = 465,
    UPTIME = 466,
    EXEC = 467,
    UNMONITOR = 468,
    PING = 469,
    PING4 = 470,
    PING6 = 471,
    ICMP = 472,
    ICMPECHO = 473,
    NONEXIST = 474,
    EXIST = 475,
    INVALID = 476,
    DATA = 477,
    RECOVERED = 478,
    PASSED = 479,
    SUCCEEDED = 480,
    URL = 481,
    CONTENT = 482,
    PID = 483,
    PPID = 484,
    FSFLAG = 485,
    REGISTER = 486,
    CREDENTIALS = 487,
    URLOBJECT = 488,
    TARGET = 489,
    TIMESPEC = 490,
    HTTPHEADER = 491,
    MAXFORWARD = 492,
    FIPS = 493,
    GREATER = 494,
    LESS = 495,
    EQUAL = 496,
    NOTEQUAL = 497
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define THEN 260
#define OR 261
#define FAILED 262
#define SET 263
#define LOGFILE 264
#define FACILITY 265
#define DAEMON 266
#define SYSLOG 267
#define MAILSERVER 268
#define HTTPD 269
#define ALLOW 270
#define REJECTOPT 271
#define ADDRESS 272
#define INIT 273
#define READONLY 274
#define CLEARTEXT 275
#define MD5HASH 276
#define SHA1HASH 277
#define CRYPT 278
#define DELAY 279
#define PEMFILE 280
#define ENABLE 281
#define DISABLE 282
#define SSL 283
#define CLIENTPEMFILE 284
#define ALLOWSELFCERTIFICATION 285
#define SELFSIGNED 286
#define VERIFY 287
#define CERTIFICATE 288
#define CACERTIFICATEFILE 289
#define CACERTIFICATEPATH 290
#define VALID 291
#define INTERFACE 292
#define LINK 293
#define PACKET 294
#define BYTEIN 295
#define BYTEOUT 296
#define PACKETIN 297
#define PACKETOUT 298
#define SPEED 299
#define SATURATION 300
#define UPLOAD 301
#define DOWNLOAD 302
#define TOTAL 303
#define IDFILE 304
#define STATEFILE 305
#define SEND 306
#define EXPECT 307
#define EXPECTBUFFER 308
#define CYCLE 309
#define COUNT 310
#define REMINDER 311
#define PIDFILE 312
#define START 313
#define STOP 314
#define PATHTOK 315
#define HOST 316
#define HOSTNAME 317
#define PORT 318
#define IPV4 319
#define IPV6 320
#define TYPE 321
#define UDP 322
#define TCP 323
#define TCPSSL 324
#define PROTOCOL 325
#define CONNECTION 326
#define ALERT 327
#define NOALERT 328
#define MAILFORMAT 329
#define UNIXSOCKET 330
#define SIGNATURE 331
#define TIMEOUT 332
#define RETRY 333
#define RESTART 334
#define CHECKSUM 335
#define EVERY 336
#define NOTEVERY 337
#define DEFAULT 338
#define HTTP 339
#define HTTPS 340
#define APACHESTATUS 341
#define FTP 342
#define SMTP 343
#define SMTPS 344
#define POP 345
#define POPS 346
#define IMAP 347
#define IMAPS 348
#define CLAMAV 349
#define NNTP 350
#define NTP3 351
#define MYSQL 352
#define DNS 353
#define WEBSOCKET 354
#define SSH 355
#define DWP 356
#define LDAP2 357
#define LDAP3 358
#define RDATE 359
#define RSYNC 360
#define TNS 361
#define PGSQL 362
#define POSTFIXPOLICY 363
#define SIP 364
#define LMTP 365
#define GPS 366
#define RADIUS 367
#define MEMCACHE 368
#define REDIS 369
#define MONGODB 370
#define SIEVE 371
#define STRING 372
#define PATH 373
#define MAILADDR 374
#define MAILFROM 375
#define MAILREPLYTO 376
#define MAILSUBJECT 377
#define MAILBODY 378
#define SERVICENAME 379
#define STRINGNAME 380
#define NUMBER 381
#define PERCENT 382
#define LOGLIMIT 383
#define CLOSELIMIT 384
#define DNSLIMIT 385
#define KEEPALIVELIMIT 386
#define REPLYLIMIT 387
#define REQUESTLIMIT 388
#define STARTLIMIT 389
#define WAITLIMIT 390
#define GRACEFULLIMIT 391
#define CLEANUPLIMIT 392
#define REAL 393
#define CHECKPROC 394
#define CHECKFILESYS 395
#define CHECKFILE 396
#define CHECKDIR 397
#define CHECKHOST 398
#define CHECKSYSTEM 399
#define CHECKFIFO 400
#define CHECKPROGRAM 401
#define CHECKNET 402
#define CHILDREN 403
#define STATUS 404
#define ORIGIN 405
#define VERSIONOPT 406
#define RESOURCE 407
#define MEMORY 408
#define TOTALMEMORY 409
#define LOADAVG1 410
#define LOADAVG5 411
#define LOADAVG15 412
#define SWAP 413
#define MODE 414
#define ACTIVE 415
#define PASSIVE 416
#define MANUAL 417
#define CPU 418
#define TOTALCPU 419
#define CPUUSER 420
#define CPUSYSTEM 421
#define CPUWAIT 422
#define GROUP 423
#define REQUEST 424
#define DEPENDS 425
#define BASEDIR 426
#define SLOT 427
#define EVENTQUEUE 428
#define SECRET 429
#define HOSTHEADER 430
#define UID 431
#define EUID 432
#define GID 433
#define MMONIT 434
#define INSTANCE 435
#define USERNAME 436
#define PASSWORD 437
#define TIMESTAMP 438
#define CHANGED 439
#define SECOND 440
#define MINUTE 441
#define HOUR 442
#define DAY 443
#define MONTH 444
#define SSLAUTO 445
#define SSLV2 446
#define SSLV3 447
#define TLSV1 448
#define TLSV11 449
#define TLSV12 450
#define CERTMD5 451
#define AUTO 452
#define BYTE 453
#define KILOBYTE 454
#define MEGABYTE 455
#define GIGABYTE 456
#define INODE 457
#define SPACE 458
#define TFREE 459
#define PERMISSION 460
#define SIZE 461
#define MATCH 462
#define NOT 463
#define IGNORE 464
#define ACTION 465
#define UPTIME 466
#define EXEC 467
#define UNMONITOR 468
#define PING 469
#define PING4 470
#define PING6 471
#define ICMP 472
#define ICMPECHO 473
#define NONEXIST 474
#define EXIST 475
#define INVALID 476
#define DATA 477
#define RECOVERED 478
#define PASSED 479
#define SUCCEEDED 480
#define URL 481
#define CONTENT 482
#define PID 483
#define PPID 484
#define FSFLAG 485
#define REGISTER 486
#define CREDENTIALS 487
#define URLOBJECT 488
#define TARGET 489
#define TIMESPEC 490
#define HTTPHEADER 491
#define MAXFORWARD 492
#define FIPS 493
#define GREATER 494
#define LESS 495
#define EQUAL 496
#define NOTEQUAL 497

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 296 "src/p.y" /* yacc.c:1909  */

        URL_T url;
        float real;
        int   number;
        char *string;

#line 545 "src/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
