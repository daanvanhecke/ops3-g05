#include <config.h>
/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 26 "src/p.y" /* yacc.c:339  */


/*
 * DESCRIPTION
 *   Simple context-free grammar for parsing the control file.
 *
 */

#include "config.h"

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_CTYPE_H
#include <ctype.h>
#endif

#ifdef HAVE_PWD_H
#include <pwd.h>
#endif

#ifdef HAVE_GRP_H
#include <grp.h>
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#ifdef HAVE_TIME_H
#include <time.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_ASM_PARAM_H
#include <asm/param.h>
#endif

#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif

#ifdef HAVE_NETDB_H
#include <netdb.h>
#endif

#ifdef HAVE_SYSLOG_H
#include <syslog.h>
#endif

#ifdef HAVE_NETINET_IN_SYSTM_H
#include <netinet/in_systm.h>
#endif

#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif

#ifdef HAVE_NETINET_IP_H
#include <netinet/ip.h>
#endif

#ifdef HAVE_NETINET_IP_ICMP_H
#include <netinet/ip_icmp.h>
#endif

#ifdef HAVE_REGEX_H
#include <regex.h>
#endif

#include "net.h"
#include "monit.h"
#include "protocol.h"
#include "engine.h"
#include "alert.h"
#include "process.h"
#include "device.h"

// libmonit
#include "io/File.h"
#include "util/Str.h"
#include "thread/Thread.h"


/* ------------------------------------------------------------- Definitions */


struct IHavePrecedence {
        boolean_t daemon;
        boolean_t logfile;
        boolean_t pidfile;
};


struct myrate {
        unsigned count;
        unsigned cycles;
};


/* yacc interface */
void  yyerror(const char *,...);
void  yyerror2(const char *,...);
void  yywarning(const char *,...);
void  yywarning2(const char *,...);

/* lexer interface */
int yylex(void);
extern FILE *yyin;
extern int lineno;
extern int arglineno;
extern char *yytext;
extern char *argyytext;
extern char *currentfile;
extern char *argcurrentfile;
extern int buffer_stack_ptr;

/* Local variables */
static int cfg_errflag = 0;
static Service_T tail = NULL;
static Service_T current = NULL;
static Request_T urlrequest = NULL;
static command_t command = NULL;
static command_t command1 = NULL;
static command_t command2 = NULL;
static Service_T depend_list = NULL;
static struct myuid uidset;
static struct mygid gidset;
static struct mypid pidset;
static struct mypid ppidset;
static struct myfsflag fsflagset;
static struct mynonexist nonexistset;
static struct mystatus statusset;
static struct myperm permset;
static struct mysize sizeset;
static struct myuptime uptimeset;
static struct mylinkstatus linkstatusset;
static struct mylinkspeed linkspeedset;
static struct mylinksaturation linksaturationset;
static struct mybandwidth bandwidthset;
static struct mymatch matchset;
static struct myicmp icmpset;
static struct mymail mailset;
static struct SslOptions_T sslset;
static struct myport portset;
static struct mymailserver mailserverset;
static struct mymmonit mmonitset;
static struct myfilesystem filesystemset;
static struct myresource resourceset;
static struct mychecksum checksumset;
static struct mytimestamp timestampset;
static struct myactionrate actionrateset;
static struct IHavePrecedence ihp = {false, false, false};
static struct myrate rate1 = {1, 1};
static struct myrate rate2 = {1, 1};
static char * htpasswd_file = NULL;
static Digest_Type digesttype = Digest_Cleartext;

#define BITMAP_MAX (sizeof(long long) * 8)


/* -------------------------------------------------------------- Prototypes */

static void  preparse();
static void  postparse();
static void  addmail(char *, Mail_T, Mail_T *);
static Service_T createservice(Service_Type, char *, char *, State_Type (*)(Service_T));
static void  addservice(Service_T);
static void  adddependant(char *);
static void  addservicegroup(char *);
static void  addport(Port_T *, Port_T);
static void  addhttpheader(Port_T, const char *);
static void  addresource(Resource_T);
static void  addtimestamp(Timestamp_T, boolean_t);
static void  addactionrate(ActionRate_T);
static void  addsize(Size_T);
static void  adduptime(Uptime_T);
static void  addpid(Pid_T);
static void  addppid(Pid_T);
static void  addfsflag(Fsflag_T);
static void  addnonexist(Nonexist_T);
static void  addlinkstatus(Service_T, LinkStatus_T);
static void  addlinkspeed(Service_T, LinkSpeed_T);
static void  addlinksaturation(Service_T, LinkSaturation_T);
static void  addbandwidth(Bandwidth_T *, Bandwidth_T);
static void  addfilesystem(Filesystem_T);
static void  addicmp(Icmp_T);
static void  addgeneric(Port_T, char*, char*);
static void  addcommand(int, unsigned);
static void  addargument(char *);
static void  addmmonit(Mmonit_T);
static void  addmailserver(MailServer_T);
static boolean_t addcredentials(char *, char *, Digest_Type, boolean_t);
#ifdef HAVE_LIBPAM
static void  addpamauth(char *, int);
#endif
static void  addhtpasswdentry(char *, char *, Digest_Type);
static uid_t get_uid(char *, uid_t);
static gid_t get_gid(char *, gid_t);
static void  addchecksum(Checksum_T);
static void  addperm(Perm_T);
static void  addmatch(Match_T, int, int);
static void  addmatchpath(Match_T, Action_Type);
static void  addstatus(Status_T);
static Uid_T adduid(Uid_T);
static Gid_T addgid(Gid_T);
static void  addeuid(uid_t);
static void  addegid(gid_t);
static void  addeventaction(EventAction_T *, Action_Type, Action_Type);
static void  prepare_urlrequest(URL_T U);
static void  seturlrequest(int, char *);
static void  setlogfile(char *);
static void  setpidfile(char *);
static void  reset_sslset();
static void  reset_mailset();
static void  reset_mailserverset();
static void  reset_mmonitset();
static void  reset_portset();
static void  reset_resourceset();
static void  reset_timestampset();
static void  reset_actionrateset();
static void  reset_sizeset();
static void  reset_uptimeset();
static void  reset_pidset();
static void  reset_ppidset();
static void  reset_fsflagset();
static void  reset_nonexistset();
static void  reset_linkstatusset();
static void  reset_linkspeedset();
static void  reset_linksaturationset();
static void  reset_bandwidthset();
static void  reset_checksumset();
static void  reset_permset();
static void  reset_uidset();
static void  reset_gidset();
static void  reset_statusset();
static void  reset_filesystemset();
static void  reset_icmpset();
static void  reset_rateset();
static void  check_name(char *);
static int   check_perm(int);
static void  check_exec(char *);
static int   cleanup_hash_string(char *);
static void  check_depend();
static void  setsyslog(char *);
static command_t copycommand(command_t);
static int verifyMaxForward(int);


#line 336 "src/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 296 "src/p.y" /* yacc.c:355  */

        URL_T url;
        float real;
        int   number;
        char *string;

#line 867 "src/y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 882 "src/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  217
/* YYNRULES -- Number of rules.  */
#define YYNRULES  674
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1232

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   497

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   245,     2,
       2,     2,     2,     2,   246,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   247,     2,   248,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   243,     2,   244,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   343,   343,   344,   347,   348,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     377,   378,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   403,   404,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   426,   427,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   447,   448,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   467,   468,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   485,   486,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   504,   505,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   519,   520,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     539,   540,   543,   544,   545,   546,   547,   548,   549,   550,
     551,   554,   558,   561,   567,   577,   578,   581,   588,   593,
     598,   606,   609,   614,   617,   621,   627,   632,   637,   645,
     648,   649,   652,   658,   659,   662,   665,   666,   667,   668,
     671,   672,   677,   694,   697,   700,   701,   704,   708,   712,
     716,   720,   723,   733,   745,   757,   763,   764,   767,   781,
     788,   797,   798,   801,   805,   809,   813,   821,   829,   833,
     839,   848,   855,   864,   865,   868,   877,   888,   889,   892,
     895,   898,   899,   900,   901,   904,   908,   914,   915,   918,
     919,   920,   921,   924,   925,   928,   929,   932,   935,   948,
     949,   952,   953,   954,   957,   958,   961,   962,   965,   968,
     973,   974,   977,   978,   981,   986,   991,   998,  1003,  1006,
    1014,  1018,  1022,  1026,  1030,  1030,  1037,  1037,  1044,  1044,
    1051,  1051,  1058,  1065,  1066,  1069,  1075,  1076,  1079,  1082,
    1085,  1092,  1101,  1106,  1109,  1114,  1119,  1124,  1132,  1138,
    1150,  1155,  1162,  1171,  1174,  1179,  1182,  1188,  1191,  1196,
    1197,  1200,  1201,  1204,  1207,  1212,  1216,  1220,  1223,  1228,
    1231,  1236,  1241,  1244,  1249,  1258,  1259,  1260,  1263,  1264,
    1265,  1266,  1267,  1268,  1269,  1270,  1271,  1274,  1281,  1282,
    1285,  1286,  1287,  1288,  1289,  1290,  1293,  1299,  1300,  1301,
    1304,  1305,  1306,  1307,  1310,  1316,  1321,  1326,  1333,  1334,
    1337,  1338,  1339,  1342,  1345,  1350,  1355,  1361,  1364,  1369,
    1372,  1376,  1381,  1382,  1385,  1386,  1389,  1392,  1395,  1398,
    1401,  1404,  1407,  1412,  1415,  1420,  1423,  1426,  1429,  1432,
    1435,  1438,  1441,  1445,  1448,  1451,  1456,  1459,  1462,  1467,
    1470,  1473,  1476,  1479,  1482,  1485,  1488,  1491,  1494,  1497,
    1502,  1505,  1508,  1511,  1516,  1517,  1520,  1523,  1526,  1529,
    1534,  1535,  1538,  1546,  1551,  1554,  1559,  1564,  1565,  1568,
    1571,  1576,  1577,  1580,  1581,  1582,  1583,  1584,  1587,  1593,
    1599,  1604,  1610,  1611,  1616,  1621,  1622,  1625,  1630,  1631,
    1634,  1638,  1642,  1646,  1650,  1654,  1658,  1662,  1666,  1670,
    1676,  1683,  1689,  1695,  1702,  1707,  1712,  1717,  1720,  1725,
    1728,  1733,  1736,  1741,  1746,  1751,  1757,  1765,  1771,  1772,
    1775,  1779,  1782,  1786,  1791,  1794,  1797,  1798,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,
    1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,
    1823,  1824,  1825,  1826,  1827,  1828,  1829,  1832,  1833,  1836,
    1837,  1840,  1841,  1842,  1843,  1846,  1850,  1854,  1860,  1863,
    1866,  1872,  1879,  1882,  1883,  1886,  1889,  1896,  1905,  1911,
    1912,  1915,  1916,  1917,  1918,  1921,  1927,  1928,  1931,  1932,
    1933,  1934,  1937,  1942,  1949,  1956,  1957,  1958,  1959,  1962,
    1967,  1972,  1977,  1984,  1989,  1996,  2003,  2010,  2011,  2012,
    2015,  2016,  2019,  2025,  2032,  2033,  2034,  2035,  2036,  2037,
    2040,  2041,  2042,  2043,  2044,  2045,  2048,  2049,  2050,  2052,
    2053,  2055,  2056,  2057,  2058,  2059,  2060,  2061,  2064,  2073,
    2082,  2083,  2089,  2099,  2100,  2106,  2116,  2119,  2122,  2125,
    2130,  2134,  2141,  2147,  2148,  2149,  2152,  2159,  2166,  2173,
    2182,  2191,  2198,  2207,  2216,  2222,  2223,  2224,  2225,  2226,
    2229,  2234,  2241,  2248,  2254,  2261,  2269,  2272,  2278,  2284,
    2291,  2297,  2304,  2310,  2317,  2323,  2330,  2336,  2341,  2349,
    2357,  2365,  2373,  2381,  2389,  2399,  2407,  2415,  2423,  2431,
    2439,  2449,  2452,  2453,  2454
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "THEN", "OR", "FAILED",
  "SET", "LOGFILE", "FACILITY", "DAEMON", "SYSLOG", "MAILSERVER", "HTTPD",
  "ALLOW", "REJECTOPT", "ADDRESS", "INIT", "READONLY", "CLEARTEXT",
  "MD5HASH", "SHA1HASH", "CRYPT", "DELAY", "PEMFILE", "ENABLE", "DISABLE",
  "SSL", "CLIENTPEMFILE", "ALLOWSELFCERTIFICATION", "SELFSIGNED", "VERIFY",
  "CERTIFICATE", "CACERTIFICATEFILE", "CACERTIFICATEPATH", "VALID",
  "INTERFACE", "LINK", "PACKET", "BYTEIN", "BYTEOUT", "PACKETIN",
  "PACKETOUT", "SPEED", "SATURATION", "UPLOAD", "DOWNLOAD", "TOTAL",
  "IDFILE", "STATEFILE", "SEND", "EXPECT", "EXPECTBUFFER", "CYCLE",
  "COUNT", "REMINDER", "PIDFILE", "START", "STOP", "PATHTOK", "HOST",
  "HOSTNAME", "PORT", "IPV4", "IPV6", "TYPE", "UDP", "TCP", "TCPSSL",
  "PROTOCOL", "CONNECTION", "ALERT", "NOALERT", "MAILFORMAT", "UNIXSOCKET",
  "SIGNATURE", "TIMEOUT", "RETRY", "RESTART", "CHECKSUM", "EVERY",
  "NOTEVERY", "DEFAULT", "HTTP", "HTTPS", "APACHESTATUS", "FTP", "SMTP",
  "SMTPS", "POP", "POPS", "IMAP", "IMAPS", "CLAMAV", "NNTP", "NTP3",
  "MYSQL", "DNS", "WEBSOCKET", "SSH", "DWP", "LDAP2", "LDAP3", "RDATE",
  "RSYNC", "TNS", "PGSQL", "POSTFIXPOLICY", "SIP", "LMTP", "GPS", "RADIUS",
  "MEMCACHE", "REDIS", "MONGODB", "SIEVE", "STRING", "PATH", "MAILADDR",
  "MAILFROM", "MAILREPLYTO", "MAILSUBJECT", "MAILBODY", "SERVICENAME",
  "STRINGNAME", "NUMBER", "PERCENT", "LOGLIMIT", "CLOSELIMIT", "DNSLIMIT",
  "KEEPALIVELIMIT", "REPLYLIMIT", "REQUESTLIMIT", "STARTLIMIT",
  "WAITLIMIT", "GRACEFULLIMIT", "CLEANUPLIMIT", "REAL", "CHECKPROC",
  "CHECKFILESYS", "CHECKFILE", "CHECKDIR", "CHECKHOST", "CHECKSYSTEM",
  "CHECKFIFO", "CHECKPROGRAM", "CHECKNET", "CHILDREN", "STATUS", "ORIGIN",
  "VERSIONOPT", "RESOURCE", "MEMORY", "TOTALMEMORY", "LOADAVG1",
  "LOADAVG5", "LOADAVG15", "SWAP", "MODE", "ACTIVE", "PASSIVE", "MANUAL",
  "CPU", "TOTALCPU", "CPUUSER", "CPUSYSTEM", "CPUWAIT", "GROUP", "REQUEST",
  "DEPENDS", "BASEDIR", "SLOT", "EVENTQUEUE", "SECRET", "HOSTHEADER",
  "UID", "EUID", "GID", "MMONIT", "INSTANCE", "USERNAME", "PASSWORD",
  "TIMESTAMP", "CHANGED", "SECOND", "MINUTE", "HOUR", "DAY", "MONTH",
  "SSLAUTO", "SSLV2", "SSLV3", "TLSV1", "TLSV11", "TLSV12", "CERTMD5",
  "AUTO", "BYTE", "KILOBYTE", "MEGABYTE", "GIGABYTE", "INODE", "SPACE",
  "TFREE", "PERMISSION", "SIZE", "MATCH", "NOT", "IGNORE", "ACTION",
  "UPTIME", "EXEC", "UNMONITOR", "PING", "PING4", "PING6", "ICMP",
  "ICMPECHO", "NONEXIST", "EXIST", "INVALID", "DATA", "RECOVERED",
  "PASSED", "SUCCEEDED", "URL", "CONTENT", "PID", "PPID", "FSFLAG",
  "REGISTER", "CREDENTIALS", "URLOBJECT", "TARGET", "TIMESPEC",
  "HTTPHEADER", "MAXFORWARD", "FIPS", "GREATER", "LESS", "EQUAL",
  "NOTEQUAL", "'{'", "'}'", "':'", "'@'", "'['", "']'", "$accept",
  "cfgfile", "statement_list", "statement", "optproclist", "optproc",
  "optfilelist", "optfile", "optfilesyslist", "optfilesys", "optdirlist",
  "optdir", "opthostlist", "opthost", "optnetlist", "optnet",
  "optsystemlist", "optsystem", "optfifolist", "optfifo", "optstatuslist",
  "optstatus", "setalert", "setdaemon", "startdelay", "setexpectbuffer",
  "setinit", "setfips", "setlog", "seteventqueue", "setidfile",
  "setstatefile", "setpid", "setmmonits", "mmonitlist", "mmonit",
  "mmonitoptlist", "mmonitopt", "credentials", "setssl", "ssl",
  "ssloptionlist", "ssloption", "sslexpire", "expireoperator",
  "sslchecksum", "checksumoperator", "sslversion", "certmd5",
  "setmailservers", "setmailformat", "mailserverlist", "mailserver",
  "mailserveroptlist", "mailserveropt", "sethttpd", "httpdnetlist",
  "httpdnetoption", "httpdunixlist", "httpdunixoption", "sslserver",
  "optssllist", "optssl", "sslenable", "ssldisable", "signature",
  "sigenable", "sigdisable", "bindaddress", "pemfile", "clientpemfile",
  "allowselfcert", "allow", "$@1", "$@2", "$@3", "$@4", "allowuserlist",
  "allowuser", "readonly", "checkproc", "checkfile", "checkfilesys",
  "checkdir", "checkhost", "checknet", "checksystem", "checkfifo",
  "checkprogram", "start", "stop", "restart", "argumentlist",
  "useroptionlist", "argument", "useroption", "username", "password",
  "hostname", "connection", "connectionoptlist", "connectionopt",
  "connectionurl", "connectionurloptlist", "connectionurlopt",
  "connectionunix", "connectionuxoptlist", "connectionuxopt", "icmp",
  "icmpoptlist", "icmpopt", "host", "port", "unixsocket", "ip", "type",
  "typeoptlist", "typeopt", "protocol", "sendexpectlist", "sendexpect",
  "websocketlist", "websocket", "mysqllist", "mysql", "target",
  "maxforward", "siplist", "sip", "httplist", "http", "status", "request",
  "responsesum", "hostheader", "httpheaderlist", "secret", "radiuslist",
  "radius", "apache_stat_list", "apache_stat", "exist", "pid", "ppid",
  "uptime", "icmpcount", "icmpsize", "icmptimeout", "exectimeout",
  "programtimeout", "nettimeout", "connectiontimeout", "retry",
  "actionrate", "urloption", "urloperator", "alert", "alertmail",
  "noalertmail", "eventoptionlist", "eventoption", "formatlist",
  "formatoptionlist", "formatoption", "every", "mode", "group", "depend",
  "dependlist", "dependant", "statusvalue", "resourceprocess",
  "resourceprocesslist", "resourceprocessopt", "resourcesystem",
  "resourcesystemlist", "resourcesystemopt", "resourcecpuproc",
  "resourcecpu", "resourcecpuid", "resourcemem", "resourceswap",
  "resourcechild", "resourceload", "resourceloadavg", "value", "timestamp",
  "operator", "time", "totaltime", "currenttime", "action", "action1",
  "action2", "rate1", "rate2", "recovery", "checksum", "hashtype", "inode",
  "space", "fsflag", "unit", "permission", "match", "matchflagnot", "size",
  "uid", "euid", "gid", "linkstatus", "linkspeed", "linksaturation",
  "upload", "download", "icmptype", "reminder", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   123,   125,    58,    64,    91,    93
};
# endif

#define YYPACT_NINF -653

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-653)))

#define YYTABLE_NINF -291

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     612,    27,   -31,   -14,    14,    44,    88,   104,   130,   144,
     147,   163,   612,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,    48,    97,
     203,   224,  -653,   -45,   218,   247,   244,   271,   273,   155,
     324,   173,  -653,    16,    72,   368,   379,   384,   447,  -653,
     407,   415,    42,  -653,  -653,   332,    63,   449,   512,   530,
     632,   691,   512,   850,   480,  -653,   446,   408,    -3,  -653,
     388,   426,  -653,  -653,  -653,   526,  -653,  -653,   701,   439,
     440,  -653,   173,   331,   340,   347,  1076,   545,   486,   492,
     418,   455,   508,   516,   534,   539,   519,   542,   544,   262,
     519,   519,   558,   519,   -68,   428,   625,   574,   557,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,    24,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,    36,   498,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,   124,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,    32,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,    26,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   101,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,   662,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     416,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   595,   698,  -653,   603,   -10,   608,  -653,   674,  -653,
    -653,    18,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   225,  -653,   610,  -653,   289,   331,   567,  -653,   701,
    1076,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     768,  -653,   675,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,   183,  -653,  -653,  -653,
      99,   728,   374,   374,   374,  -653,  -653,  -653,   374,   374,
     411,   594,   374,   931,  -653,  -653,  -653,  -653,  -653,   374,
     221,   221,  -653,   221,   784,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,   557,  -653,   597,  1076,   545,     0,   374,    75,
     374,   594,   647,  -653,   653,    79,  -130,   356,   468,    81,
     114,   833,   374,   374,   374,   621,   835,   374,  -653,  -653,
    -653,  -653,   709,  -653,  -653,   374,  -653,  -653,  -653,   374,
     729,  -653,   759,  -653,   657,   827,   355,   794,  -653,  -653,
    -653,  -653,  -653,  -653,   801,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,   741,   804,  -653,   430,   552,   685,   697,
     707,   711,   713,   716,  -653,  -653,  -653,  -653,   842,   843,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,   311,   839,   880,
    -653,   916,   845,     8,    47,     1,  -653,  -653,  -653,   855,
     857,    91,   156,   216,   743,   914,   602,   856,  -653,  -653,
    -653,  -653,  -653,   858,   180,   234,   860,   866,   868,   868,
     868,   874,    11,  -653,   976,   394,   875,   193,  -653,   193,
    -653,   193,  -653,  -653,  -653,  1076,   922,  -653,  -653,  -653,
     885,   903,   887,   868,   868,   868,   934,   890,   575,   585,
     868,   374,   895,   374,   413,  -653,  -653,  -653,   966,   868,
     913,   915,   917,   374,   374,   868,   454,  -653,  1035,   920,
     921,   868,  -653,   -10,  -653,    -5,  -653,  -653,  -653,  -653,
    -653,  -653,     6,   925,    54,    74,   689,   712,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,   972,   977,  -653,
    -653,  -653,   936,   828,   864,   941,   944,  1048,  -653,   870,
    -653,   880,   545,  -653,   878,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,   868,   868,   868,   868,   868,   868,  -653,
     926,   602,   948,   955,   592,   602,  -653,  1021,  -653,   949,
    -653,   526,   950,   526,   951,   953,  1077,  1084,  1085,   556,
    -653,  1027,   285,  -653,  -653,   906,  -653,  -653,  -653,   993,
     880,   868,    31,   556,  1087,  1088,  1092,   868,   526,   868,
     868,  -653,  -653,  1094,   970,   767,   461,   974,   526,   148,
     148,   148,   886,  -653,  1098,   988,   112,   195,   996,   997,
    1120,   999,   526,   285,  1002,   868,  1125,    60,   883,   883,
    -653,  1014,  1017,  1018,  1019,   893,  1023,  1029,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,   436,   436,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   545,  -653,
    -653,  1143,  1149,  1150,  1160,  1162,  1165,    29,  -653,    39,
     602,  -653,  -653,   736,  1224,  1042,  1046,  -653,  -653,  -653,
    -653,  -653,  1169,  -653,  1170,  -653,  -653,  -653,  -653,  -653,
    -653,   285,   285,   285,  -653,  -653,  -653,  -653,  -653,   868,
    -653,  -653,  -653,  -653,  -653,   519,  -653,  -653,  1189,  -653,
     880,   545,  1190,  1079,  1192,   868,   285,   285,   285,  1195,
     868,  1196,  1197,   285,   779,   868,  1201,  1067,   526,   868,
     868,  1081,  1082,  1083,  -653,  -653,  -653,  -653,  1206,  1208,
    1211,  -653,   148,   285,   868,  1032,  1032,  1032,  1032,   202,
     222,   285,  -653,  -653,  1189,  -653,  1213,   285,  -653,  1102,
    1107,  -653,  1109,  1110,  1127,  1129,  1130,  1229,  1131,  1132,
    -653,  -653,  -653,  -653,  -653,  -653,   285,   285,   285,   285,
     285,   285,    90,   671,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  1246,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  1248,  -653,  -653,  -653,  -653,  -653,
    -653,   661,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,   290,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  1070,  -653,   285,    82,  -653,  -653,  1189,  1252,
     399,  1255,  -653,   545,  -653,   285,   868,   285,  1256,  -653,
    1189,  -653,   285,  1257,   285,   285,  -653,   868,  1258,  1259,
     285,   868,   868,  1260,  1261,  -653,  1075,  -653,   285,   285,
     285,  1262,  1189,  1263,  -653,   868,   868,   868,   868,     2,
     301,   325,   366,  1189,  -653,   285,  -653,  -653,  -653,  1130,
    1130,  1130,  1229,  -653,  1130,  -653,  -653,  -653,  -653,  -653,
    1189,  1189,  1189,  1189,  1189,  1189,  1030,  -653,  -653,  1153,
     285,   285,   584,   134,   134,   374,   374,   374,   374,   374,
     374,   374,   374,   374,   374,  1265,  -653,   733,  1155,  1156,
    1148,  1157,   290,  -653,   -30,  1103,  -653,  1189,  -653,  -653,
    -653,   285,   323,   607,  -653,  1189,  1271,  1189,   285,  -653,
    -653,   285,  -653,  -653,  1273,   285,   285,  1189,  1274,  1275,
     285,   285,  -653,  1189,  1189,  1189,   285,  -653,   285,  1278,
    1279,  1280,  1284,   670,  -653,  -653,  -653,   868,   670,   868,
     670,   868,   670,   868,  -653,  1189,  1130,  1130,  1130,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  1164,  -653,
    1189,  1189,  -653,  -653,  -653,  1174,   374,  1176,  1175,  -653,
    -653,  -653,  -653,  -653,  -653,  1173,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1223,   661,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,   488,  1225,  -653,  -653,  -653,  1179,
    -653,  -653,  -653,  1189,  1226,  1226,  1226,  -653,   285,  -653,
    1189,  1189,   285,  1189,  1189,  -653,   285,   285,  1189,  1189,
    -653,  -653,  -653,  1189,  1189,   285,   285,   285,   285,   868,
    1295,   868,  1296,   868,  1297,   868,  1345,  -653,  1166,  -653,
    -653,  -653,  1227,  -653,  -653,   370,  1228,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1237,  1238,  -653,  -653,  -653,  -653,
    -653,  -653,    17,  1351,  1361,  1362,  1189,  -653,  -653,  1189,
    -653,  -653,  1189,  1189,  -653,  -653,  -653,  -653,  1189,  1189,
    1189,  1189,  1363,   285,  1364,   285,  1365,   285,  1366,   285,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  1318,   285,   285,   285,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,   285,  1189,   285,
    1189,   285,  1189,   285,  1189,  -653,  -653,  -653,  -653,  -653,
    1189,  -653,  1189,  -653,  1189,  -653,  1189,  -653,  -653,  -653,
    -653,  -653
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     6,     8,    18,    19,    20,     9,
      10,    16,    17,    15,    11,     7,    12,    13,    14,    30,
      52,    71,    88,   104,   118,   133,   144,   160,     0,     0,
       0,     0,   178,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   527,     0,     0,     0,     0,     0,   309,
       0,     0,     0,     1,     5,    21,    22,    23,    24,    25,
      29,    26,    27,    28,   181,   180,   175,   237,   481,   233,
       0,     0,   205,   186,   187,   635,   188,   494,     0,     0,
       0,   193,   189,   200,     0,     0,     0,   672,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    42,    43,    44,    35,    36,    37,    41,
      45,    46,   527,   493,    47,    48,    49,    50,    51,    38,
      39,    40,   646,   646,    53,    54,    55,    56,    57,    59,
      61,    60,    68,    69,    70,    58,    65,    62,    67,    66,
      63,    64,     0,    72,    73,    74,    75,    76,    78,    77,
      82,    83,    84,    85,    86,    87,    79,    80,    81,     0,
      89,    90,    91,    92,    93,    95,    97,    96,   101,   102,
     103,    94,    98,    99,   100,     0,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     119,   120,   121,   122,   128,   130,   129,   131,   132,   123,
     124,   125,   126,   127,     0,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   145,   146,   147,   148,   149,
     151,   153,   152,   157,   158,   159,   150,   154,   155,   156,
       0,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,     0,     0,   174,     0,   235,     0,   234,   332,   247,
     253,     0,   636,   637,   638,   639,   177,   531,   532,   533,
     534,     0,   529,   183,   185,   192,   200,     0,   190,     0,
       0,   511,   499,   500,   513,   514,   521,   519,   502,   523,
     501,   522,   518,   525,   507,   509,   524,   515,   520,   498,
     526,   505,   508,   512,   510,   504,   503,   516,   517,   506,
       0,   496,     0,   171,   298,   299,   300,   301,   304,   303,
     302,   305,   306,   310,   323,   324,   479,   319,   307,   308,
     373,     0,   584,   584,   584,   577,   578,   579,   584,   584,
       0,     0,   584,   610,   549,   551,   552,   553,   554,   584,
     477,   477,   495,   477,     0,   536,   537,   538,   539,   540,
     541,   545,   542,   543,     0,     0,   672,   623,   584,   623,
     584,   647,     0,   647,     0,     0,     0,   584,   584,     0,
     373,     0,   584,   584,   584,     0,     0,   584,   568,   565,
     566,   567,   610,   556,   561,   584,   559,   560,   558,   584,
       0,   182,     0,   237,   203,     0,     0,     0,   228,   223,
     224,   225,   226,   227,     0,   229,   241,   242,   243,   244,
     238,   239,   240,     0,     0,   231,   245,   246,     0,     0,
       0,     0,     0,     0,   202,   206,   232,   530,     0,     0,
     194,   196,   197,   198,   199,   191,   201,     0,     0,   527,
     497,   673,     0,     0,     0,   479,   320,   321,   311,     0,
       0,     0,     0,     0,     0,     0,   357,     0,   589,   585,
     586,   587,   588,     0,     0,     0,     0,     0,   610,   610,
     610,     0,     0,   550,     0,     0,     0,   477,   313,   477,
     315,   477,   317,   535,   544,     0,     0,   490,   624,   625,
       0,     0,     0,   610,   610,   610,     0,     0,     0,     0,
     610,   584,     0,   584,     0,   368,   368,   368,     0,   610,
       0,     0,     0,   584,   584,   610,     0,   557,     0,     0,
       0,   610,   176,   236,   205,   221,   330,   329,   331,   230,
     482,   333,     0,     0,     0,     0,     0,     0,   248,   249,
     259,   259,   250,   268,   269,   251,   252,     0,     0,   254,
     255,   256,     0,     0,     0,     0,     0,     0,   184,     0,
     528,   527,   672,   674,     0,   325,   327,   326,   328,   322,
     312,   374,   376,   610,   610,   610,   610,   610,   610,   348,
       0,   335,     0,     0,   610,   359,   420,     0,   575,   581,
     580,   635,   581,   635,     0,     0,     0,     0,     0,   590,
     611,     0,     0,   581,   576,     0,   314,   316,   318,     0,
     527,   610,   610,   590,     0,     0,     0,   610,   635,   610,
     610,   645,   644,     0,     0,   610,     0,   581,   635,   610,
     610,   610,     0,   368,     0,     0,   635,   635,     0,     0,
       0,   581,   635,     0,     0,   610,     0,     0,   221,   221,
     222,     0,     0,     0,     0,   292,   280,     0,   274,   265,
     271,   267,   273,   264,   266,   270,   272,   258,   257,   212,
     209,   210,   207,   208,   213,   214,   211,   195,   672,   172,
     480,     0,     0,     0,     0,     0,     0,   610,   375,   610,
     337,   422,   423,     0,     0,     0,     0,   358,   360,   361,
     362,   363,     0,   421,     0,   570,   569,   572,   571,   562,
     563,     0,     0,     0,   591,   592,   593,   594,   595,   610,
     612,   605,   606,   601,   604,     0,   607,   608,   616,   478,
     527,   672,     0,     0,     0,   610,     0,     0,     0,     0,
     610,     0,     0,     0,   610,   610,     0,   581,   635,   610,
     610,     0,     0,     0,   369,   370,   371,   372,     0,     0,
       0,   671,   610,     0,   610,   599,   599,   599,   599,   635,
     635,     0,   574,   573,   616,   564,     0,     0,   204,     0,
       0,   218,   281,   282,   283,     0,     0,   296,     0,     0,
     277,   260,   261,   262,   263,   173,     0,     0,     0,     0,
       0,     0,     0,     0,   353,   355,   354,   349,   351,   352,
     350,     0,   377,   378,   344,   346,   345,   336,   338,   339,
     340,   342,   343,   341,     0,   381,   379,   382,   387,   441,
     441,     0,   390,   407,   408,   404,   405,   393,   394,   395,
     401,   402,   430,   388,     0,   409,   389,   396,   397,   410,
     412,   413,   414,   403,   437,   415,   416,   455,   418,   411,
     398,   406,     0,   484,     0,     0,   471,   472,   616,     0,
     602,     0,   548,   672,   491,     0,   610,     0,     0,   583,
     616,   649,     0,     0,     0,     0,   634,   610,     0,     0,
       0,   610,   610,     0,     0,   474,     0,   475,     0,     0,
       0,     0,   616,     0,   600,   610,   610,   610,   610,     0,
       0,     0,     0,   616,   555,     0,   547,   219,   220,     0,
       0,     0,   296,   295,   285,   293,   297,   279,   275,   276,
     616,   616,   616,   616,   616,   616,   216,   488,   489,     0,
       0,     0,   380,   391,   392,   584,   584,   584,   584,   584,
     584,   584,   584,   584,   584,   386,   458,   399,     0,     0,
       0,     0,   419,   424,   400,   417,   483,   616,   486,   485,
     470,     0,   603,     0,   492,   616,     0,   616,     0,   641,
     622,     0,   643,   642,     0,     0,     0,   616,     0,     0,
       0,     0,   476,   616,   616,   616,     0,   656,     0,     0,
       0,     0,     0,     0,   596,   597,   598,   610,     0,   610,
       0,   610,     0,   610,   657,   616,   287,   289,   291,   278,
     294,   650,   651,   652,   653,   654,   655,   217,     0,   487,
     616,   616,   384,   385,   383,     0,   584,     0,     0,   452,
     442,   445,   443,   444,   446,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   432,   433,   431,   428,
     426,   429,   427,   425,     0,     0,   439,   440,   438,     0,
     457,   456,   356,   616,   613,   613,   613,   640,     0,   620,
     616,   616,     0,   616,   616,   626,     0,     0,   616,   616,
     365,   366,   367,   616,   616,     0,     0,     0,     0,   610,
       0,   610,     0,   610,     0,   610,     0,   546,     0,   347,
     334,   450,     0,   449,   451,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,   435,   434,   436,
     454,   473,     0,     0,     0,     0,   616,   582,   648,   616,
     628,   627,   616,   616,   631,   630,   364,   658,   616,   616,
     616,   616,     0,     0,     0,     0,     0,     0,     0,     0,
     215,   448,   453,   447,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   614,     0,     0,     0,     0,   621,
     629,   633,   632,   662,   659,   668,   665,     0,   616,     0,
     616,     0,   616,     0,   616,   615,   609,   617,   618,   619,
     616,   663,   616,   660,   616,   669,   616,   666,   664,   661,
     670,   667
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -653,  -653,  -653,  1367,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,  -653,  -653,  -653,  -653,  1281,  -653,  -653,  1089,  -653,
    -272,   830,  -653,   667,  -653,  -271,   256,  -284,  -283,  -653,
    -653,  -653,  1299,   965,  -653,  -653,  -653,  -653,  -653,  -653,
    -653,   819,  -653,  -653,  -653,   945,  -653,  -653,  -653,  -653,
    -653,  -653,   946,  -653,  -653,  -653,  -653,   -71,  -652,   442,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,   867,
     937,   957,  -107,  -352,  -329,  -455,   404,   409,  -653,  1316,
    -653,  -653,  1319,  -653,  -653,  -653,  -653,  -653,  -653,  -407,
    -653,  -653,  -653,  -653,  -653,   678,  -653,  -653,   680,   789,
    -554,  -653,   410,  -653,  -653,  -653,  -653,  -653,  -653,   541,
    -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,  -653,
     318,   284,  -653,  -653,  -653,  -653,  -653,  -653,    46,   929,
    -653,   -85,   -77,  1040,   686,  -653,  1091,  1395,  -653,  -260,
    -305,  -127,  1108,  -244,  1111,   783,  1119,  1163,  -653,  1026,
    -653,  -653,  -653,  1047,  -653,  -653,  1000,  -653,  -653,  -653,
    -176,  -653,  -653,  -163,  -653,  -112,   251,  -324,   766,  -482,
     100,  -299,  -442,  -270,  -402,  -146,  -267,  -653,  1022,  -653,
    -653,  -653,  -360,   514,  -653,  1264,  -653,   629,  -653,   694,
    -653,  -653,  -653,  -653,  -653,  -653,  -364
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    65,   119,    66,   144,    67,   163,
      68,   180,    69,   196,    70,   210,    71,   225,    72,   235,
      73,   251,    14,    15,   263,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    92,    93,   285,   450,   288,    25,
     426,   271,   445,   825,  1048,   427,   671,   428,   429,    26,
      27,    78,    79,   265,   430,    28,   436,   558,   437,   569,
     559,   687,   811,   560,   561,   562,   563,   564,   565,   812,
     813,   814,   566,   806,   939,   940,   941,   944,   945,   947,
      29,    30,    31,    32,    33,    34,    35,    36,    37,   120,
     121,   122,   336,   465,   337,   467,   431,   432,   435,   123,
     709,   837,   124,   707,   827,   125,   604,   717,   202,   649,
     774,   475,   601,   476,   838,   718,   962,  1054,   719,   605,
     606,   982,   983,   977,  1078,  1086,  1087,   984,  1088,   963,
    1060,  1061,  1062,  1063,  1064,  1135,  1090,   985,  1091,   975,
     976,   126,   127,   128,   129,   775,   776,   777,   498,   468,
     268,   720,   721,   130,   830,   959,   131,   132,   133,   320,
     321,    97,   281,   282,   134,   135,   136,   137,   372,   373,
     260,   138,   353,   354,   234,   402,   403,   355,   404,   405,
     356,   407,   357,   358,   359,   611,   155,   483,   739,  1027,
     925,   747,   748,  1217,   494,  1153,   892,   156,   511,   173,
     174,   175,   276,   157,   158,   382,   159,   139,   140,   141,
     219,   220,   221,   222,   223,   653,   323
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     538,   453,   454,   360,   361,   376,   363,   466,   497,   499,
     589,   501,   507,   451,   452,   460,   668,   669,   414,   484,
     485,   508,   509,   415,   486,   487,   672,   673,   491,   674,
     458,   466,   466,   390,   466,   495,    38,   447,    39,   385,
      40,    41,   589,   377,   589,    42,   589,   438,   406,   439,
     440,   723,   441,   442,   512,    43,   517,   414,   364,   107,
      74,   408,   822,   522,   524,   620,   142,   414,   530,   531,
     532,  1194,   822,   536,   266,   514,    44,    45,   462,   108,
      46,   539,   679,   753,    47,   540,   616,   617,   618,   438,
      94,   439,   440,    54,   441,   442,   508,   509,    94,    48,
     520,    49,   681,   832,   833,   713,   715,   716,   391,   714,
      55,   634,   635,   636,    77,   506,   715,   716,   643,   650,
     651,   110,   111,   675,   676,   585,   956,   654,  1023,    98,
     680,   385,    99,   660,   586,    48,   112,   621,    56,   666,
     741,   742,   113,  1195,   114,   115,   392,   393,   394,   395,
     682,   785,   341,   460,   743,   492,   723,   492,   341,   988,
     469,   744,   341,    63,   587,   492,    75,   365,    57,   443,
     545,   416,   417,   588,   470,   469,   471,   463,   473,   464,
     418,   419,   420,   421,   422,   423,   424,   425,  1024,  1025,
    1026,   701,   702,   703,   704,   705,   706,   644,    82,   646,
      50,   460,   722,   771,  1084,   510,    51,  1085,   593,   658,
     659,   443,    58,   447,  1055,   378,   389,   594,   699,   378,
     379,   794,   116,    76,    95,   772,   406,   341,    59,   752,
     754,   117,   374,   118,   787,   759,   670,   761,   762,   408,
     351,   929,   380,   766,   381,   629,   782,   778,   779,   780,
     341,   726,   677,   728,    60,   471,   823,   473,   513,    96,
     462,   931,   444,   796,   513,    52,   823,   375,    61,   340,
     496,    62,   143,   595,   492,   471,   472,   473,   760,   100,
     514,   515,   596,  1056,   510,   396,   514,    80,   770,   886,
     887,   888,  1040,   696,   745,   746,   786,   788,   496,    81,
     334,   335,   793,  1057,   798,   831,   609,   844,   386,  1058,
     272,   273,   274,   275,   899,   900,   901,   414,   610,   191,
      77,   906,   415,   246,   460,   474,   387,   388,   525,   526,
     527,   528,   582,   597,   815,   109,    83,   889,   334,   335,
     474,   922,   598,   741,   742,   277,   278,   279,   280,   933,
     148,   978,   184,   898,   773,   936,   239,   743,   903,   463,
     612,   464,   908,   909,   744,    84,   449,   913,   914,   463,
      85,   464,   610,   613,   950,   951,   952,   953,   954,   955,
     921,  1059,   923,   624,  1040,  1040,  1040,   894,   341,    86,
     110,   111,    87,   272,   273,   274,   275,   463,    88,   464,
     272,   273,   274,   275,    48,   112,    91,   500,   912,   502,
     342,   113,   648,   114,   115,   343,   344,   345,   346,   347,
     272,   273,   274,   275,   662,   348,   349,  1028,   101,   930,
     932,   277,   278,   279,   280,   824,   826,   834,   836,   102,
     979,   980,   987,   989,   103,   552,   350,   553,  1029,  1031,
    1033,  1030,   162,   995,   698,   997,   554,   555,   556,   981,
    1000,   808,  1002,  1003,   104,   809,   810,   105,  1007,   446,
     351,   264,   546,   352,   547,   106,  1013,  1014,  1015,   418,
     419,   420,   421,   422,   423,   424,   425,  1024,  1025,  1026,
     261,   116,  1032,  1035,   996,    89,    90,   745,   746,   463,
     117,   464,   118,   751,   262,  1004,   557,   110,   111,  1008,
    1009,  1024,  1025,  1026,   269,   179,   334,   335,  1050,  1051,
     623,    48,   112,  1019,  1020,  1021,  1022,   934,   113,   994,
     114,   115,   610,   195,   768,   326,   327,   589,   992,   647,
     478,  1119,   341,   626,   270,   627,  1121,   628,  1123,  1093,
    1125,   610,  1024,  1025,  1026,   580,  1100,   283,   478,  1101,
     521,   466,   287,  1103,  1104,   409,   284,   552,  1108,  1109,
     110,   111,   328,   329,  1113,   463,  1114,   464,   567,   568,
     661,   176,   192,   289,    48,   112,   247,   767,   110,   111,
     290,   113,   610,   114,   115,   479,   480,   481,   482,   610,
     410,   322,    48,   112,   324,  1147,  1182,  1148,   116,   113,
     325,   114,   115,   479,   480,   481,   482,   117,  1183,   118,
       1,   990,   828,   893,   841,  1120,   330,  1122,   557,  1124,
     829,  1126,   842,   999,   331,   209,   334,   335,   890,   488,
     489,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,   332,   478,   602,   603,  1017,  1156,   333,   713,   338,
    1159,   339,   714,   366,  1162,  1163,  1034,   533,   534,   715,
     716,   116,   523,  1168,  1169,  1170,  1171,   362,  1052,  1053,
     117,   371,   118,  1041,  1042,  1043,  1044,  1045,  1046,   116,
     110,   111,   639,   640,   224,   160,   177,   193,   117,   370,
     118,   248,   641,   642,    48,   112,   383,   479,   480,   481,
     482,   113,   411,   114,   115,   683,   684,  1172,   492,  1174,
    1092,  1176,   412,  1178,   272,   273,   274,   275,  1097,   413,
    1099,  1208,  1132,  1210,   433,  1212,   434,  1214,   685,   686,
    1105,   734,   735,   736,   737,   738,  1110,  1111,  1112,   110,
     111,     2,     3,     4,     5,     6,     7,     8,     9,    10,
     161,   178,   194,    48,   112,  1220,   249,  1222,  1127,  1224,
     113,  1226,   114,   115,   418,   419,   420,   421,   422,   423,
     424,   425,   448,  1129,  1130,   367,   368,   369,   341,   965,
     966,   967,   968,   969,   970,   971,   972,   973,   974,   456,
     117,   461,   118,   845,   846,   847,   291,   477,   292,   293,
     294,   295,   296,   297,   490,   343,   344,   345,   346,   347,
     397,   277,   278,   279,   280,   398,  1151,   399,   400,   401,
    1094,  1095,  1096,  1157,  1158,   492,  1160,  1161,   503,   298,
     505,  1164,  1165,   690,   691,   299,  1166,  1167,   300,   152,
     170,   188,   206,   250,   518,   243,  1024,  1025,  1026,   117,
     519,   118,   343,   344,   345,   346,   347,   397,  1036,  1037,
    1038,   529,   398,   535,   399,   400,   401,   291,   541,   292,
     293,   294,   295,   296,   297,   542,   926,   927,   928,  1199,
     692,   693,  1200,   492,   765,  1201,  1202,  1216,  1216,  1216,
     544,  1203,  1204,  1205,  1206,   492,   907,   545,   110,   111,
     298,   548,   957,   958,   416,   417,   299,   301,   549,   300,
     302,   551,    48,   112,   799,   800,   550,  1218,  1219,   113,
     572,   114,   115,   145,   164,   181,   197,   211,   226,   236,
     252,  1221,   573,  1223,   303,  1225,   304,  1227,   305,  1154,
    1155,   306,   574,  1228,    94,  1229,   575,  1230,   576,  1231,
     291,   577,   292,   293,   294,   295,   296,   297,   578,   579,
     583,   584,   591,   307,   308,   592,   599,   600,   309,   310,
     311,   622,   607,   632,   608,   312,   614,   313,   301,   314,
     315,   302,   615,   298,   492,   316,   317,   318,   319,   299,
     619,   625,   300,   146,   165,   182,   198,   212,   227,   237,
     253,   631,   459,   633,   637,   303,   638,   304,   117,   305,
     118,   645,   306,   147,   166,   183,   199,   213,   228,   238,
     254,   291,   652,   292,   293,   294,   295,   296,   297,   655,
     663,   656,   678,   657,   307,   308,   664,   665,   680,   309,
     310,   311,   708,   682,   689,   697,   312,   492,   313,   694,
     314,   315,   695,   700,   298,   711,   316,   317,   318,   319,
     299,   301,   712,   300,   302,   724,   725,   727,   729,   342,
     730,   740,   731,   581,   343,   344,   345,   346,   347,   732,
     733,   749,   756,   757,   348,   349,   764,   758,   303,   763,
     304,   769,   305,   783,   781,   306,   149,   167,   185,   203,
     214,   229,   240,   255,   291,   784,   292,   293,   294,   295,
     296,   297,   789,   790,   670,   791,   792,   307,   308,   795,
     797,   801,   309,   310,   311,   802,   803,   804,   805,   312,
    -284,   313,   301,   314,   315,   302,   807,   298,   816,   316,
     317,   318,   319,   299,   817,   818,   300,   150,   168,   186,
     204,   215,   230,   241,   256,   819,   630,   820,   882,   303,
     821,   304,   883,   305,   884,   885,   306,   151,   169,   187,
     205,   216,   231,   242,   257,   153,   171,   189,   207,   217,
     232,   244,   258,   891,   911,   895,   896,   897,   307,   308,
     902,   904,   905,   309,   310,   311,   910,   915,   916,   917,
     312,   918,   313,   919,   314,   315,   920,   924,   935,   937,
     316,   317,   318,   319,   938,   301,  -286,  -288,   302,   154,
     172,   190,   208,   218,   233,   245,   259,   750,   418,   419,
     420,   421,   422,   423,  -290,   425,   942,   943,   946,   948,
     949,   960,   303,   961,   304,   986,   305,   991,   993,   306,
    1012,   998,  1001,  1005,  1006,  1010,  1011,  1016,  1018,  1047,
    1049,  1075,  1079,  1080,  1081,  1082,  1098,  1089,  1102,  1106,
    1107,   307,   308,  1115,  1116,  1117,   309,   310,   311,  1118,
    1128,  1131,  1134,   312,  1133,   313,  1150,   314,   315,  1136,
    1173,  1175,  1177,   316,   317,   318,   319,   848,   849,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   876,   877,   878,   879,   880,
     881,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1179,  1149,  1152,  1181,  1180,  1184,  1196,  1185,  1186,  1187,
    1188,  1189,  1190,  1191,  1192,  1193,  1197,  1198,  1207,  1209,
    1211,  1213,  1215,   286,   667,   455,   835,   267,   543,    64,
     688,  1076,   570,   571,  1039,   200,  1077,   839,   201,   840,
     710,   964,  1083,  1146,   590,   843,    53,   457,   504,   755,
     493,   516,   537,     0,     0,     0,     0,   384
};

static const yytype_int16 yycheck[] =
{
     402,   285,   285,   110,   111,   132,   113,   336,   360,   361,
     465,   363,   376,   285,   285,   320,    21,    22,    28,   343,
     344,    21,    22,    33,   348,   349,    20,    21,   352,    23,
     290,   360,   361,     7,   363,   359,     9,   281,    11,     7,
      13,    14,   497,     7,   499,    18,   501,    29,   224,    31,
      32,   605,    34,    35,   378,    28,   380,    28,   126,    17,
      12,   224,    33,   387,   388,    54,     3,    28,   392,   393,
     394,    54,    33,   397,    77,   205,    49,    50,    77,    37,
      53,   405,    28,    52,    57,   409,   488,   489,   490,    29,
      74,    31,    32,   124,    34,    35,    21,    22,    74,    72,
     230,    74,    28,    64,    65,    66,    77,    78,     7,    70,
     124,   513,   514,   515,   117,   375,    77,    78,   520,   526,
     527,    58,    59,   117,   118,   117,    36,   529,   126,    57,
      76,     7,    60,   535,   126,    72,    73,   126,   124,   541,
      58,    59,    79,   126,    81,    82,    45,    46,    47,    48,
      76,    39,   126,   458,    72,   126,   710,   126,   126,    77,
      61,    79,   126,     0,   117,   126,   118,   235,   124,   151,
      80,   181,   182,   126,    75,    61,   176,   176,   178,   178,
     190,   191,   192,   193,   194,   195,   196,   197,   186,   187,
     188,   593,   594,   595,   596,   597,   598,   521,   243,   523,
     173,   506,   604,    55,   234,   205,   179,   237,   117,   533,
     534,   151,   124,   457,    80,   183,   184,   126,   582,   183,
     184,   663,   159,   126,   208,    77,   402,   126,   124,   631,
     632,   168,   208,   170,    39,   637,   241,   639,   640,   402,
     208,    39,   206,   645,   208,   505,   653,   649,   650,   651,
     126,   611,   246,   613,   124,   176,   227,   178,   183,   243,
      77,    39,   244,   665,   183,   238,   227,   243,   124,     7,
      77,   124,   209,   117,   126,   176,   177,   178,   638,   207,
     205,   206,   126,   149,   205,   184,   205,    63,   648,   731,
     732,   733,   944,   577,   212,   213,   656,   657,    77,    75,
     117,   118,   662,   169,   244,   707,   126,   709,   184,   175,
     198,   199,   200,   201,   756,   757,   758,    28,   138,    68,
     117,   763,    33,    72,   629,   226,   202,   203,   214,   215,
     216,   217,   459,   117,   698,     3,   118,   739,   117,   118,
     226,   783,   126,    58,    59,   120,   121,   122,   123,   791,
      66,    61,    68,   755,   206,   797,    72,    72,   760,   176,
     126,   178,   764,   765,    79,   118,    77,   769,   770,   176,
     126,   178,   138,   485,   816,   817,   818,   819,   820,   821,
     782,   247,   784,   495,  1036,  1037,  1038,   751,   126,   118,
      58,    59,   119,   198,   199,   200,   201,   176,   243,   178,
     198,   199,   200,   201,    72,    73,   233,   361,   768,   363,
     148,    79,   524,    81,    82,   153,   154,   155,   156,   157,
     198,   199,   200,   201,   536,   163,   164,   126,    60,   789,
     790,   120,   121,   122,   123,   707,   707,   709,   709,    60,
     150,   151,   884,   885,    60,    15,   184,    17,   930,   931,
     932,   126,     3,   895,   581,   897,    26,    27,    28,   169,
     902,    25,   904,   905,    17,    29,    30,    60,   910,   244,
     208,    63,   117,   211,   119,    60,   918,   919,   920,   190,
     191,   192,   193,   194,   195,   196,   197,   186,   187,   188,
      10,   159,   126,   935,   896,   171,   172,   212,   213,   176,
     168,   178,   170,   630,    58,   907,    76,    58,    59,   911,
     912,   186,   187,   188,   126,     3,   117,   118,   960,   961,
     126,    72,    73,   925,   926,   927,   928,   794,    79,   893,
      81,    82,   138,     3,   646,   117,   118,   992,   890,   126,
     184,  1023,   126,   497,   118,   499,  1028,   501,  1030,   991,
    1032,   138,   186,   187,   188,   244,   998,   118,   184,  1001,
     204,   890,   231,  1005,  1006,   149,   126,    15,  1010,  1011,
      58,    59,   117,   118,  1016,   176,  1018,   178,    26,    27,
     126,    67,    68,   243,    72,    73,    72,   126,    58,    59,
     243,    79,   138,    81,    82,   239,   240,   241,   242,   138,
     184,    56,    72,    73,   118,   117,   236,   119,   159,    79,
     118,    81,    82,   239,   240,   241,   242,   168,   248,   170,
       8,   888,   707,   750,   709,  1027,   118,  1029,    76,  1031,
     707,  1033,   709,   900,   118,     3,   117,   118,   745,   228,
     229,   965,   966,   967,   968,   969,   970,   971,   972,   973,
     974,   117,   184,    51,    52,   922,  1098,   118,    66,   117,
    1102,   117,    70,   235,  1106,  1107,   933,    46,    47,    77,
      78,   159,   204,  1115,  1116,  1117,  1118,   119,   962,   962,
     168,   124,   170,   950,   951,   952,   953,   954,   955,   159,
      58,    59,   117,   118,     3,    66,    67,    68,   168,   125,
     170,    72,   117,   118,    72,    73,   208,   239,   240,   241,
     242,    79,   117,    81,    82,    26,    27,  1119,   126,  1121,
     987,  1123,    24,  1125,   198,   199,   200,   201,   995,   126,
     997,  1173,  1056,  1175,   126,  1177,    62,  1179,    26,    27,
    1007,   185,   186,   187,   188,   189,  1013,  1014,  1015,    58,
      59,   139,   140,   141,   142,   143,   144,   145,   146,   147,
      66,    67,    68,    72,    73,  1207,    72,  1209,  1035,  1211,
      79,  1213,    81,    82,   190,   191,   192,   193,   194,   195,
     196,   197,   172,  1050,  1051,   160,   161,   162,   126,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   232,
     168,   126,   170,    67,    68,    69,    38,    79,    40,    41,
      42,    43,    44,    45,   220,   153,   154,   155,   156,   157,
     158,   120,   121,   122,   123,   163,  1093,   165,   166,   167,
     223,   224,   225,  1100,  1101,   126,  1103,  1104,    54,    71,
     243,  1108,  1109,    15,    16,    77,  1113,  1114,    80,    66,
      67,    68,    69,     3,   207,    72,   186,   187,   188,   168,
     207,   170,   153,   154,   155,   156,   157,   158,   939,   940,
     941,    38,   163,    38,   165,   166,   167,    38,   149,    40,
      41,    42,    43,    44,    45,   126,   786,   787,   788,  1156,
      26,    27,  1159,   126,   127,  1162,  1163,  1196,  1197,  1198,
     243,  1168,  1169,  1170,  1171,   126,   127,    80,    58,    59,
      71,   117,   241,   242,   181,   182,    77,   149,   117,    80,
     152,   117,    72,    73,   668,   669,   185,  1197,  1198,    79,
     245,    81,    82,    66,    67,    68,    69,    70,    71,    72,
      73,  1208,   245,  1210,   176,  1212,   178,  1214,   180,  1095,
    1096,   183,   245,  1220,    74,  1222,   245,  1224,   245,  1226,
      38,   245,    40,    41,    42,    43,    44,    45,   126,   126,
      54,   126,   117,   205,   206,   118,   233,    63,   210,   211,
     212,     5,   126,    80,   126,   217,   126,   219,   149,   221,
     222,   152,   126,    71,   126,   227,   228,   229,   230,    77,
     126,   126,    80,    66,    67,    68,    69,    70,    71,    72,
      73,   126,   244,   126,    80,   176,   126,   178,   168,   180,
     170,   126,   183,    66,    67,    68,    69,    70,    71,    72,
      73,    38,    66,    40,    41,    42,    43,    44,    45,   126,
       5,   126,   117,   126,   205,   206,   126,   126,    76,   210,
     211,   212,   126,    76,   118,   185,   217,   126,   219,   118,
     221,   222,   118,   185,    71,   117,   227,   228,   229,   230,
      77,   149,   117,    80,   152,    54,   127,   127,   127,   148,
     127,    54,     5,   244,   153,   154,   155,   156,   157,     5,
       5,   185,     5,     5,   163,   164,   126,     5,   176,     5,
     178,   127,   180,     5,   218,   183,    66,    67,    68,    69,
      70,    71,    72,    73,    38,   127,    40,    41,    42,    43,
      44,    45,   126,   126,   241,     5,   127,   205,   206,   127,
       5,   117,   210,   211,   212,   118,   118,   118,   245,   217,
     117,   219,   149,   221,   222,   152,   117,    71,     5,   227,
     228,   229,   230,    77,     5,     5,    80,    66,    67,    68,
      69,    70,    71,    72,    73,     5,   244,     5,   126,   176,
       5,   178,   126,   180,     5,     5,   183,    66,    67,    68,
      69,    70,    71,    72,    73,    66,    67,    68,    69,    70,
      71,    72,    73,     4,   127,     5,   117,     5,   205,   206,
       5,     5,     5,   210,   211,   212,     5,   126,   126,   126,
     217,     5,   219,     5,   221,   222,     5,   185,     5,   117,
     227,   228,   229,   230,   117,   149,   117,   117,   152,    66,
      67,    68,    69,    70,    71,    72,    73,   244,   190,   191,
     192,   193,   194,   195,   117,   197,   117,   117,    19,   118,
     118,     5,   176,     5,   178,   185,   180,     5,     3,   183,
     185,     5,     5,     5,     5,     5,     5,     5,     5,   239,
     117,     6,   117,   117,   126,   118,     5,   174,     5,     5,
       5,   205,   206,     5,     5,     5,   210,   211,   212,     5,
     126,   117,   117,   217,   118,   219,   117,   221,   222,   126,
       5,     5,     5,   227,   228,   229,   230,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   126,   126,   126,   126,   126,   126,   126,   126,   126,
       5,   126,   126,   126,   188,   127,     5,   127,   127,   127,
     127,   127,   127,   127,   127,   127,     5,     5,     5,     5,
       5,     5,    54,    92,   544,   286,   709,    78,   413,    12,
     561,   977,   437,   437,   942,    69,   977,   709,    69,   709,
     601,   850,   982,  1075,   465,   709,     1,   289,   372,   633,
     353,   379,   402,    -1,    -1,    -1,    -1,   143
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     8,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   250,   251,   252,   271,   272,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   288,   298,   299,   304,   329,
     330,   331,   332,   333,   334,   335,   336,   337,     9,    11,
      13,    14,    18,    28,    49,    50,    53,    57,    72,    74,
     173,   179,   238,   406,   124,   124,   124,   124,   124,   124,
     124,   124,   124,     0,   252,   253,   255,   257,   259,   261,
     263,   265,   267,   269,    12,   118,   126,   117,   300,   301,
      63,    75,   243,   118,   118,   126,   118,   119,   243,   171,
     172,   233,   283,   284,    74,   208,   243,   410,    57,    60,
     207,    60,    60,    60,    17,    60,    60,    17,    37,     3,
      58,    59,    73,    79,    81,    82,   159,   168,   170,   254,
     338,   339,   340,   348,   351,   354,   390,   391,   392,   393,
     402,   405,   406,   407,   413,   414,   415,   416,   420,   456,
     457,   458,     3,   209,   256,   338,   339,   340,   390,   402,
     405,   413,   414,   415,   416,   435,   446,   452,   453,   455,
     456,   458,     3,   258,   338,   339,   340,   402,   405,   413,
     414,   415,   416,   448,   449,   450,   452,   456,   458,     3,
     260,   338,   339,   340,   390,   402,   405,   413,   414,   415,
     416,   435,   452,   456,   458,     3,   262,   338,   339,   340,
     348,   351,   357,   402,   405,   413,   414,   415,   416,     3,
     264,   338,   339,   340,   402,   405,   413,   415,   416,   459,
     460,   461,   462,   463,     3,   266,   338,   339,   340,   402,
     405,   413,   415,   416,   423,   268,   338,   339,   340,   390,
     402,   405,   413,   414,   415,   416,   435,   452,   456,   458,
       3,   270,   338,   339,   340,   402,   405,   413,   415,   416,
     419,    10,    58,   273,    63,   302,    77,   301,   399,   126,
     118,   290,   198,   199,   200,   201,   451,   120,   121,   122,
     123,   411,   412,   118,   126,   285,   284,   231,   287,   243,
     243,    38,    40,    41,    42,    43,    44,    45,    71,    77,
      80,   149,   152,   176,   178,   180,   183,   205,   206,   210,
     211,   212,   217,   219,   221,   222,   227,   228,   229,   230,
     408,   409,    56,   465,   118,   118,   117,   118,   117,   118,
     118,   118,   117,   118,   117,   118,   341,   343,   117,   117,
       7,   126,   148,   153,   154,   155,   156,   157,   163,   164,
     184,   208,   211,   421,   422,   426,   429,   431,   432,   433,
     341,   341,   119,   341,   126,   235,   235,   160,   161,   162,
     125,   124,   417,   418,   208,   243,   410,     7,   183,   184,
     206,   208,   454,   208,   454,     7,   184,   202,   203,   184,
       7,     7,    45,    46,    47,    48,   184,   158,   163,   165,
     166,   167,   424,   425,   427,   428,   429,   430,   432,   149,
     184,   117,    24,   126,    28,    33,   181,   182,   190,   191,
     192,   193,   194,   195,   196,   197,   289,   294,   296,   297,
     303,   345,   346,   126,    62,   347,   305,   307,    29,    31,
      32,    34,    35,   151,   244,   291,   244,   412,   172,    77,
     286,   289,   294,   296,   297,   287,   232,   411,   408,   244,
     409,   126,    77,   176,   178,   342,   343,   344,   398,    61,
      75,   176,   177,   178,   226,   360,   362,    79,   184,   239,
     240,   241,   242,   436,   436,   436,   436,   436,   228,   229,
     220,   436,   126,   422,   443,   436,    77,   342,   397,   342,
     397,   342,   397,    54,   418,   243,   408,   465,    21,    22,
     205,   447,   436,   183,   205,   206,   447,   436,   207,   207,
     230,   204,   436,   204,   436,   214,   215,   216,   217,    38,
     436,   436,   436,    46,    47,    38,   436,   425,   443,   436,
     436,   149,   126,   302,   243,    80,   117,   119,   117,   117,
     185,   117,    15,    17,    26,    27,    28,    76,   306,   309,
     312,   313,   314,   315,   316,   317,   321,    26,    27,   308,
     314,   321,   245,   245,   245,   245,   245,   245,   126,   126,
     244,   244,   410,    54,   126,   117,   126,   117,   126,   344,
     398,   117,   118,   117,   126,   117,   126,   117,   126,   233,
      63,   361,    51,    52,   355,   368,   369,   126,   126,   126,
     138,   434,   126,   434,   126,   126,   443,   443,   443,   126,
      54,   126,     5,   126,   434,   126,   397,   397,   397,   408,
     244,   126,    80,   126,   443,   443,   443,    80,   126,   117,
     118,   117,   118,   443,   436,   126,   436,   126,   434,   358,
     358,   358,    66,   464,   443,   126,   126,   126,   436,   436,
     443,   126,   434,     5,   126,   126,   443,   290,    21,    22,
     241,   295,    20,    21,    23,   117,   118,   246,   117,    28,
      76,    28,    76,    26,    27,    26,    27,   310,   310,   118,
      15,    16,    26,    27,   118,   118,   296,   185,   410,   465,
     185,   443,   443,   443,   443,   443,   443,   352,   126,   349,
     368,   117,   117,    66,    70,    77,    78,   356,   364,   367,
     400,   401,   443,   369,    54,   127,   451,   127,   451,   127,
     127,     5,     5,     5,   185,   186,   187,   188,   189,   437,
      54,    58,    59,    72,    79,   212,   213,   440,   441,   185,
     244,   410,   443,    52,   443,   437,     5,     5,     5,   443,
     451,   443,   443,     5,   126,   127,   443,   126,   434,   127,
     451,    55,    77,   206,   359,   394,   395,   396,   443,   443,
     443,   218,   358,     5,   127,    39,   451,    39,   451,   126,
     126,     5,   127,   451,   441,   127,   443,     5,   244,   295,
     295,   117,   118,   118,   118,   245,   322,   117,    25,    29,
      30,   311,   318,   319,   320,   465,     5,     5,     5,     5,
       5,     5,    33,   227,   289,   292,   294,   353,   400,   401,
     403,   443,    64,    65,   289,   292,   294,   350,   363,   364,
     367,   400,   401,   403,   443,    67,    68,    69,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   126,   126,     5,     5,   441,   441,   441,   443,
     341,     4,   445,   410,   465,     5,   117,     5,   443,   441,
     441,   441,     5,   443,     5,     5,   441,   127,   443,   443,
       5,   127,   451,   443,   443,   126,   126,   126,     5,     5,
       5,   443,   441,   443,   185,   439,   439,   439,   439,    39,
     451,    39,   451,   441,   445,     5,   441,   117,   117,   323,
     324,   325,   117,   117,   326,   327,    19,   328,   118,   118,
     441,   441,   441,   441,   441,   441,    36,   241,   242,   404,
       5,     5,   365,   378,   378,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   388,   389,   372,    61,   150,
     151,   169,   370,   371,   376,   386,   185,   441,    77,   441,
     445,     5,   342,     3,   465,   441,   443,   441,     5,   445,
     441,     5,   441,   441,   443,     5,     5,   441,   443,   443,
       5,     5,   185,   441,   441,   441,     5,   445,     5,   443,
     443,   443,   443,   126,   186,   187,   188,   438,   126,   438,
     126,   438,   126,   438,   445,   441,   326,   326,   326,   328,
     327,   445,   445,   445,   445,   445,   445,   239,   293,   117,
     441,   441,   296,   297,   366,    80,   149,   169,   175,   247,
     379,   380,   381,   382,   383,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,     6,   345,   346,   373,   117,
     117,   126,   118,   371,   234,   237,   374,   375,   377,   174,
     385,   387,   445,   441,   223,   224,   225,   445,     5,   445,
     441,   441,     5,   441,   441,   445,     5,     5,   441,   441,
     445,   445,   445,   441,   441,     5,     5,     5,     5,   438,
     443,   438,   443,   438,   443,   438,   443,   445,   126,   445,
     445,   117,   436,   118,   117,   384,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   389,   117,   119,   126,
     117,   445,   126,   444,   444,   444,   441,   445,   445,   441,
     445,   445,   441,   441,   445,   445,   445,   445,   441,   441,
     441,   441,   443,     5,   443,     5,   443,     5,   443,     5,
     188,   126,   236,   248,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,    54,   126,     5,     5,     5,   445,
     445,   445,   445,   445,   445,   445,   445,     5,   441,     5,
     441,     5,   441,     5,   441,    54,   440,   442,   442,   442,
     441,   445,   441,   445,   441,   445,   441,   445,   445,   445,
     445,   445
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     253,   253,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   255,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   257,   257,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   263,   263,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   265,   265,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     269,   269,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   271,   271,   271,   272,   273,   273,   274,   275,   276,
     277,   277,   277,   278,   278,   278,   279,   280,   281,   282,
     283,   283,   284,   285,   285,   286,   286,   286,   286,   286,
     287,   287,   288,   289,   289,   290,   290,   291,   291,   291,
     291,   291,   291,   291,   291,   292,   293,   293,   294,   294,
     294,   295,   295,   296,   296,   296,   296,   296,   296,   296,
     297,   298,   299,   300,   300,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   304,   304,   305,   305,   306,
     306,   306,   306,   307,   307,   308,   308,   309,   309,   310,
     310,   311,   311,   311,   312,   312,   313,   313,   314,   314,
     315,   315,   316,   316,   317,   318,   319,   320,   321,   321,
     321,   321,   321,   321,   322,   321,   323,   321,   324,   321,
     325,   321,   321,   326,   326,   327,   328,   328,   329,   329,
     329,   329,   330,   331,   331,   332,   333,   334,   334,   335,
     336,   337,   337,   338,   338,   339,   339,   340,   340,   341,
     341,   342,   342,   343,   343,   344,   344,   344,   344,   345,
     345,   346,   347,   347,   348,   349,   349,   349,   350,   350,
     350,   350,   350,   350,   350,   350,   350,   351,   352,   352,
     353,   353,   353,   353,   353,   353,   354,   355,   355,   355,
     356,   356,   356,   356,   357,   357,   357,   357,   358,   358,
     359,   359,   359,   360,   360,   361,   362,   363,   363,   364,
     364,   364,   365,   365,   366,   366,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     368,   368,   369,   369,   370,   370,   371,   371,   371,   371,
     372,   372,   373,   373,   374,   374,   375,   376,   376,   377,
     377,   378,   378,   379,   379,   379,   379,   379,   380,   381,
     382,   383,   384,   384,   385,   386,   386,   387,   388,   388,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   397,   398,
     398,   399,   399,   400,   401,   402,   402,   403,   404,   404,
     405,   405,   405,   405,   406,   407,   408,   408,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   409,   409,   409,
     409,   409,   409,   409,   409,   409,   409,   410,   410,   411,
     411,   412,   412,   412,   412,   413,   413,   413,   414,   414,
     414,   415,   416,   417,   417,   418,   419,   419,   420,   421,
     421,   422,   422,   422,   422,   423,   424,   424,   425,   425,
     425,   425,   426,   426,   427,   428,   428,   428,   428,   429,
     429,   429,   429,   430,   430,   431,   432,   433,   433,   433,
     434,   434,   435,   435,   436,   436,   436,   436,   436,   436,
     437,   437,   437,   437,   437,   437,   438,   438,   438,   439,
     439,   440,   440,   440,   440,   440,   440,   440,   441,   442,
     443,   443,   443,   444,   444,   444,   445,   445,   445,   445,
     446,   446,   446,   447,   447,   447,   448,   448,   448,   448,
     449,   449,   449,   449,   450,   451,   451,   451,   451,   451,
     452,   452,   453,   453,   453,   453,   454,   454,   455,   455,
     456,   456,   457,   457,   458,   458,   459,   460,   461,   462,
     462,   462,   462,   462,   462,   463,   463,   463,   463,   463,
     463,   464,   465,   465,   465
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     7,     8,     4,     0,     3,     4,     2,     2,
       3,     3,     5,     4,     6,     4,     3,     3,     3,     3,
       2,     3,     2,     0,     2,     3,     1,     1,     1,     1,
       0,     2,     5,     1,     4,     0,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     5,     0,     1,     4,     5,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     5,     1,     2,     2,     4,     0,     2,     1,
       1,     1,     1,     1,     1,     5,     5,     0,     2,     1,
       1,     1,     1,     0,     2,     1,     1,     2,     2,     0,
       2,     1,     1,     1,     2,     2,     2,     2,     1,     1,
       2,     2,     2,     2,     2,     2,     2,     1,     5,     4,
       2,     3,     3,     3,     0,     4,     0,     5,     0,     5,
       0,     5,     2,     1,     2,     1,     0,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       4,     5,     6,     3,     4,     3,     4,     3,     4,     1,
       2,     1,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     0,     2,     9,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     9,     0,     2,
       1,     1,     1,     1,     1,     1,     8,     0,     2,     1,
       1,     1,     1,     1,     9,     8,     8,     8,     0,     2,
       1,     1,     1,     0,     2,     2,     2,     1,     1,     2,
       3,     2,     0,     2,     1,     1,     3,     2,     2,     2,
       2,     3,     3,     2,     2,     2,     2,     2,     2,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       1,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       0,     2,     1,     1,     2,     2,     2,     0,     2,     1,
       1,     0,     2,     1,     1,     1,     1,     3,     3,     2,
       2,     2,     0,     2,     2,     0,     2,     1,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       7,     6,     6,     9,     2,     2,     3,     0,     3,     0,
       3,     0,     3,     3,     2,     7,     7,     3,     1,     1,
       3,     6,     7,     1,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     1,
       2,     1,     1,     1,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     1,     8,     6,     6,     1,
       2,     1,     1,     1,     1,     6,     1,     2,     1,     1,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     3,     3,     1,     1,     1,
       1,     1,     9,     6,     0,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       0,     2,     3,     0,     2,     3,     0,     6,     6,     6,
       8,    10,     7,     0,     1,     1,     8,     9,     9,    10,
       9,     9,    10,    10,     6,     0,     1,     1,     1,     1,
       8,     7,     7,     7,     4,     4,     0,     1,     9,     6,
       8,     8,     8,     8,     8,     8,     7,     7,     9,    10,
      11,    12,    10,    11,    12,    10,    11,    12,    10,    11,
      12,     2,     0,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 171:
#line 554 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = Event_All;
                    addmail((yyvsp[-2].string), &mailset, &Run.maillist);
                  }
#line 2971 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 558 "src/p.y" /* yacc.c:1646  */
    {
                    addmail((yyvsp[-5].string), &mailset, &Run.maillist);
                  }
#line 2979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 561 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[-6].string), &mailset, &Run.maillist);
                  }
#line 2988 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 567 "src/p.y" /* yacc.c:1646  */
    {
                    if (! (Run.flags & Run_Daemon) || ihp.daemon) {
                      ihp.daemon     = true;
                      Run.flags      |= Run_Daemon;
                      Run.polltime   = (yyvsp[-1].number);
                      Run.startdelay = (yyvsp[0].number);
                    }
                  }
#line 3001 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 577 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = START_DELAY; }
#line 3007 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 578 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[0].number); }
#line 3013 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 581 "src/p.y" /* yacc.c:1646  */
    {
                    Run.expectbuffer = (yyvsp[-1].number) * (yyvsp[0].number);
                    if (Run.expectbuffer > EXPECT_BUFFER_MAX)
                        yyerror("Maximum value for expect buffer is 100 KB");
                  }
#line 3023 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 588 "src/p.y" /* yacc.c:1646  */
    {
                    Run.flags |= Run_Foreground;
                  }
#line 3031 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 593 "src/p.y" /* yacc.c:1646  */
    {
                    Run.flags |= Run_FipsEnabled;
                  }
#line 3039 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 598 "src/p.y" /* yacc.c:1646  */
    {
                   if (! Run.files.log || ihp.logfile) {
                     ihp.logfile = true;
                     setlogfile((yyvsp[0].string));
                     Run.flags &= ~Run_UseSyslog;
                     Run.flags |= Run_Log;
                   }
                  }
#line 3052 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 606 "src/p.y" /* yacc.c:1646  */
    {
                    setsyslog(NULL);
                  }
#line 3060 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 609 "src/p.y" /* yacc.c:1646  */
    {
                    setsyslog((yyvsp[0].string)); FREE((yyvsp[0].string));
                  }
#line 3068 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 614 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = (yyvsp[0].string);
                  }
#line 3076 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 617 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = (yyvsp[-2].string);
                    Run.eventlist_slots = (yyvsp[0].number);
                  }
#line 3085 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 621 "src/p.y" /* yacc.c:1646  */
    {
                    Run.eventlist_dir = Str_dup(MYEVENTLISTBASE);
                    Run.eventlist_slots = (yyvsp[0].number);
                  }
#line 3094 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 627 "src/p.y" /* yacc.c:1646  */
    {
                    Run.files.id = (yyvsp[0].string);
                  }
#line 3102 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 632 "src/p.y" /* yacc.c:1646  */
    {
                    Run.files.state = (yyvsp[0].string);
                  }
#line 3110 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 637 "src/p.y" /* yacc.c:1646  */
    {
                   if (! Run.files.pid || ihp.pidfile) {
                     ihp.pidfile = true;
                     setpidfile((yyvsp[0].string));
                   }
                 }
#line 3121 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 652 "src/p.y" /* yacc.c:1646  */
    {
                        mmonitset.url = (yyvsp[-1].url);
                        addmmonit(&mmonitset);
                  }
#line 3130 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 662 "src/p.y" /* yacc.c:1646  */
    {
                        mmonitset.timeout = (yyvsp[-1].number) * 1000; // net timeout is in milliseconds internally
                  }
#line 3138 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 672 "src/p.y" /* yacc.c:1646  */
    {
                    Run.flags &= ~Run_MmonitCredentials;
                  }
#line 3146 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 677 "src/p.y" /* yacc.c:1646  */
    {
                        Run.ssl.use_ssl = true;
                        Run.ssl.verify = sslset.verify;
                        Run.ssl.allowSelfSigned = sslset.allowSelfSigned;
                        Run.ssl.version = sslset.version;
                        Run.ssl.minimumValidDays = sslset.minimumValidDays;
                        Run.ssl.checksumType = sslset.checksumType;
                        Run.ssl.checksum = sslset.checksum;
                        Run.ssl.clientpemfile = sslset.clientpemfile;
                        Run.ssl.CACertificateFile = sslset.CACertificateFile;
                        Run.ssl.CACertificatePath = sslset.CACertificatePath;
                        if (Run.ssl.allowSelfSigned == true)
                                Run.httpd.flags |= Httpd_AllowSelfSignedCertificates;
                        reset_sslset();
                  }
#line 3166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 694 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                  }
#line 3174 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 704 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.verify = true;
                  }
#line 3183 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 708 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.verify = false;
                  }
#line 3192 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 712 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.allowSelfSigned = true;
                  }
#line 3201 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 716 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.allowSelfSigned = false;
                  }
#line 3210 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 720 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                  }
#line 3218 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 723 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.clientpemfile = (yyvsp[0].string);
                        if (! File_exist(sslset.clientpemfile))
                                yyerror2("SSL client PEM file doesn't exist");
                        else if (! File_isFile(sslset.clientpemfile))
                                yyerror2("SSL client PEM file is not a file");
                        else if (! File_isReadable(sslset.clientpemfile))
                                yyerror2("Cannot read SSL client PEM file");
                  }
#line 3233 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 733 "src/p.y" /* yacc.c:1646  */
    {
                        if (sslset.CACertificateFile)
                                yyerror2("Duplicate SSL CA certificates file doesn't exist");
                        sslset.use_ssl = true;
                        sslset.CACertificateFile = (yyvsp[0].string);
                        if (! File_exist(sslset.CACertificateFile))
                                yyerror2("SSL CA certificates file doesn't exist");
                        else if (! File_isFile(sslset.CACertificateFile))
                                yyerror2("SSL CA certificates file is not a file");
                        else if (! File_isReadable(sslset.CACertificateFile))
                                yyerror2("Cannot read CA certificates file");
                  }
#line 3250 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 745 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.CACertificatePath = (yyvsp[0].string);
                        if (! File_exist(sslset.CACertificatePath))
                                yyerror2("SSL CA certificates directory doesn't exist");
                        else if (! File_isDirectory(sslset.CACertificatePath))
                                yyerror2("SSL CA certificates path is not directory");
                        else if (! File_isReadable(sslset.CACertificatePath))
                                yyerror2("Cannot read CA certificates directory");
                  }
#line 3265 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 757 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.minimumValidDays = (yyvsp[-1].number);
                  }
#line 3274 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 767 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.checksum = (yyvsp[0].string);
                        switch (cleanup_hash_string(sslset.checksum)) {
                                case 32:
                                        sslset.checksumType = Hash_Md5;
                                        break;
                                case 40:
                                        sslset.checksumType = Hash_Sha1;
                                        break;
                                default:
                                        yyerror2("Unknown checksum type: [%s] is not MD5 nor SHA1", sslset.checksum);
                        }
                  }
#line 3293 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 781 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 32)
                                yyerror2("Unknown checksum type: [%s] is not MD5", sslset.checksum);
                        sslset.checksumType = Hash_Md5;
                  }
#line 3305 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 788 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 40)
                                yyerror2("Unknown checksum type: [%s] is not SHA1", sslset.checksum);
                        sslset.checksumType = Hash_Sha1;
                  }
#line 3317 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 801 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.version = SSL_V2;
                  }
#line 3326 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 805 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.version = SSL_V3;
                  }
#line 3335 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 809 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.version = SSL_TLSV1;
                  }
#line 3344 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 814 "src/p.y" /* yacc.c:1646  */
    {
#ifndef HAVE_TLSV1_1
                        yyerror("Your SSL Library does not support TLS version 1.1");
#endif
                        sslset.use_ssl = true;
                        sslset.version = SSL_TLSV11;
                }
#line 3356 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 822 "src/p.y" /* yacc.c:1646  */
    {
#ifndef HAVE_TLSV1_2
                        yyerror("Your SSL Library does not support TLS version 1.2");
#endif
                        sslset.use_ssl = true;
                        sslset.version = SSL_TLSV12;
                }
#line 3368 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 829 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.version = SSL_Auto;
                  }
#line 3377 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 833 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        sslset.version = SSL_Auto;
                  }
#line 3386 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 230:
#line 839 "src/p.y" /* yacc.c:1646  */
    { // Backward compatibility
                        sslset.use_ssl = true;
                        sslset.checksum = (yyvsp[0].string);
                        if (cleanup_hash_string(sslset.checksum) != 32)
                                yyerror2("Unknown checksum type: [%s] is not MD5", sslset.checksum);
                        sslset.checksumType = Hash_Md5;
                  }
#line 3398 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 231:
#line 848 "src/p.y" /* yacc.c:1646  */
    {
                   if (((yyvsp[-1].number)) > SMTP_TIMEOUT)
                        Run.mailserver_timeout = (yyvsp[-1].number);
                   Run.mail_hostname = (yyvsp[0].string);
                  }
#line 3408 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 232:
#line 855 "src/p.y" /* yacc.c:1646  */
    {
                   Run.MailFormat.from    = mailset.from    ?  mailset.from    : Str_dup(ALERT_FROM);
                   Run.MailFormat.replyto = mailset.replyto ?  mailset.replyto : NULL;
                   Run.MailFormat.subject = mailset.subject ?  mailset.subject : Str_dup(ALERT_SUBJECT);
                   Run.MailFormat.message = mailset.message ?  mailset.message : Str_dup(ALERT_MESSAGE);
                   reset_mailset();
                 }
#line 3420 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 235:
#line 868 "src/p.y" /* yacc.c:1646  */
    {
                        /* Restore the current text overriden by lookahead */
                        FREE(argyytext);
                        argyytext = Str_dup((yyvsp[-1].string));

                        mailserverset.host = (yyvsp[-1].string);
                        mailserverset.port = PORT_SMTP;
                        addmailserver(&mailserverset);
                  }
#line 3434 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 236:
#line 877 "src/p.y" /* yacc.c:1646  */
    {
                        /* Restore the current text overriden by lookahead */
                        FREE(argyytext);
                        argyytext = Str_dup((yyvsp[-3].string));

                        mailserverset.host = (yyvsp[-3].string);
                        mailserverset.port = (yyvsp[-1].number);
                        addmailserver(&mailserverset);
                  }
#line 3448 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 892 "src/p.y" /* yacc.c:1646  */
    {
                        mailserverset.username = (yyvsp[0].string);
                  }
#line 3456 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 895 "src/p.y" /* yacc.c:1646  */
    {
                        mailserverset.password = (yyvsp[0].string);
                  }
#line 3464 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 904 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Net;
                        Run.httpd.socket.net.port = (yyvsp[-1].number);
                 }
#line 3473 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 246:
#line 908 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Unix;
                        Run.httpd.socket.unix.path = (yyvsp[-1].string);
                 }
#line 3482 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 932 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags &= ~Httpd_Ssl;
                  }
#line 3490 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 258:
#line 935 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Ssl;
#ifdef HAVE_OPENSSL
                        if (! Run.httpd.socket.net.ssl.pem)
                                yyerror("SSL server PEM file is required (pemfile option)");
                        else if (! file_checkStat(Run.httpd.socket.net.ssl.pem, "SSL server PEM file", S_IRWXU))
                                yyerror("SSL server PEM file permissions check failed");
#else
                        yyerror("SSL is not supported");
#endif
                  }
#line 3506 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 268:
#line 965 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_Signature;
                  }
#line 3514 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 269:
#line 968 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags &= ~Httpd_Signature;
                  }
#line 3522 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 274:
#line 981 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.address = (yyvsp[0].string);
                  }
#line 3530 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 275:
#line 986 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.ssl.pem = (yyvsp[0].string);
                  }
#line 3538 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 276:
#line 991 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.socket.net.ssl.clientpem = (yyvsp[0].string);
                        if (! file_checkStat(Run.httpd.socket.net.ssl.clientpem, "SSL client PEM file", S_IRWXU | S_IRGRP | S_IROTH))
                                yyerror2("SSL client PEM file has too loose permissions");
                  }
#line 3548 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 277:
#line 998 "src/p.y" /* yacc.c:1646  */
    {
                        Run.httpd.flags |= Httpd_AllowSelfSignedCertificates;
                  }
#line 3556 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1003 "src/p.y" /* yacc.c:1646  */
    {
                        addcredentials((yyvsp[-3].string), (yyvsp[-1].string), Digest_Cleartext, (yyvsp[0].number));
                  }
#line 3564 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1006 "src/p.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBPAM
                        addpamauth((yyvsp[-1].string), (yyvsp[0].number));
#else
                        yyerror("PAM is not supported");
                        FREE((yyvsp[-1].string));
#endif
                  }
#line 3577 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1014 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Cleartext);
                        FREE((yyvsp[0].string));
                  }
#line 3586 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1018 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Cleartext);
                        FREE((yyvsp[0].string));
                  }
#line 3595 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1022 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Md5);
                        FREE((yyvsp[0].string));
                  }
#line 3604 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1026 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry((yyvsp[0].string), NULL, Digest_Crypt);
                        FREE((yyvsp[0].string));
                  }
#line 3613 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1030 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Cleartext;
                  }
#line 3622 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1034 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3630 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1037 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Cleartext;
                  }
#line 3639 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1041 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3647 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1044 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Md5;
                  }
#line 3656 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1048 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3664 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1051 "src/p.y" /* yacc.c:1646  */
    {
                        htpasswd_file = (yyvsp[0].string);
                        digesttype = Digest_Crypt;
                  }
#line 3673 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 291:
#line 1055 "src/p.y" /* yacc.c:1646  */
    {
                        FREE(htpasswd_file);
                  }
#line 3681 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1058 "src/p.y" /* yacc.c:1646  */
    {
                        if (! (Engine_addNetAllow((yyvsp[0].string)) || Engine_addHostAllow((yyvsp[0].string))))
                                yyerror2("Erroneous network or host identifier %s", (yyvsp[0].string));
                        FREE((yyvsp[0].string));
                  }
#line 3691 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1069 "src/p.y" /* yacc.c:1646  */
    {
                        addhtpasswdentry(htpasswd_file, (yyvsp[0].string), digesttype);
                        FREE((yyvsp[0].string));
                  }
#line 3700 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1075 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = false; }
#line 3706 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1076 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = true; }
#line 3712 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1079 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                  }
#line 3720 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1082 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                  }
#line 3728 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1085 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[0].string));
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 3740 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1092 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Process, (yyvsp[-2].string), (yyvsp[0].string), check_process);
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = Str_dup((yyvsp[0].string));
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 3752 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1101 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_File, (yyvsp[-2].string), (yyvsp[0].string), check_file);
                  }
#line 3760 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1106 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Filesystem, (yyvsp[-2].string), (yyvsp[0].string), check_filesystem);
                  }
#line 3768 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1109 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Filesystem, (yyvsp[-2].string), (yyvsp[0].string), check_filesystem);
                  }
#line 3776 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1114 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Directory, (yyvsp[-2].string), (yyvsp[0].string), check_directory);
                  }
#line 3784 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1119 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Host, (yyvsp[-2].string), (yyvsp[0].string), check_remote_host);
                  }
#line 3792 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1124 "src/p.y" /* yacc.c:1646  */
    {
                    if (Link_isGetByAddressSupported()) {
                        createservice(Service_Net, (yyvsp[-2].string), (yyvsp[0].string), check_net);
                        current->inf->priv.net.stats = Link_createForAddress((yyvsp[0].string));
                    } else {
                        yyerror("Network monitoring by IP address is not supported on this platform, please use 'check network <foo> with interface <bar>' instead");
                    }
                  }
#line 3805 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1132 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Net, (yyvsp[-2].string), (yyvsp[0].string), check_net);
                    current->inf->priv.net.stats = Link_createForInterface((yyvsp[0].string));
                  }
#line 3814 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1138 "src/p.y" /* yacc.c:1646  */
    {
                    char hostname[STRLEN];
                    if (Util_getfqdnhostname(hostname, sizeof(hostname))) {
                      LogError("Cannot get system hostname\n");
                      cfg_errflag++;
                    }
                    char *servicename = (yyvsp[0].string);
                    Util_replaceString(&servicename, "$HOST", hostname);
                    Run.system = createservice(Service_System, servicename, Str_dup(""), check_system); // The name given in the 'check system' statement overrides system hostname
                  }
#line 3829 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1150 "src/p.y" /* yacc.c:1646  */
    {
                    createservice(Service_Fifo, (yyvsp[-2].string), (yyvsp[0].string), check_fifo);
                  }
#line 3837 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1155 "src/p.y" /* yacc.c:1646  */
    {
                        command_t c = command; // Current command
                        check_exec(c->arg[0]);
                        createservice(Service_Program, (yyvsp[-3].string), Str_dup(c->arg[0]), check_program);
                        current->program->timeout = (yyvsp[0].number);
                        current->program->output = StringBuffer_create(64);
                 }
#line 3849 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1162 "src/p.y" /* yacc.c:1646  */
    {
                        command_t c = command; // Current command
                        check_exec(c->arg[0]);
                        createservice(Service_Program, (yyvsp[-4].string), Str_dup(c->arg[0]), check_program);
                        current->program->timeout = (yyvsp[-1].number);
                        current->program->output = StringBuffer_create(64);
                 }
#line 3861 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1171 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(START, (yyvsp[0].number));
                  }
#line 3869 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1174 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(START, (yyvsp[0].number));
                  }
#line 3877 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1179 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(STOP, (yyvsp[0].number));
                  }
#line 3885 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1182 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(STOP, (yyvsp[0].number));
                  }
#line 3893 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1188 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(RESTART, (yyvsp[0].number));
                  }
#line 3901 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1191 "src/p.y" /* yacc.c:1646  */
    {
                    addcommand(RESTART, (yyvsp[0].number));
                  }
#line 3909 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1204 "src/p.y" /* yacc.c:1646  */
    {
                        addargument((yyvsp[0].string));
                  }
#line 3917 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1207 "src/p.y" /* yacc.c:1646  */
    {
                        addargument((yyvsp[0].string));
                  }
#line 3925 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1212 "src/p.y" /* yacc.c:1646  */
    {
                        addeuid(get_uid((yyvsp[0].string), 0));
                        FREE((yyvsp[0].string));
                  }
#line 3934 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1216 "src/p.y" /* yacc.c:1646  */
    {
                        addegid(get_gid((yyvsp[0].string), 0));
                        FREE((yyvsp[0].string));
                  }
#line 3943 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1220 "src/p.y" /* yacc.c:1646  */
    {
                        addeuid(get_uid(NULL, (yyvsp[0].number)));
                  }
#line 3951 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1223 "src/p.y" /* yacc.c:1646  */
    {
                        addegid(get_gid(NULL, (yyvsp[0].number)));
                  }
#line 3959 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1228 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 3967 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1231 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 3975 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1236 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 3983 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1241 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = NULL;
                  }
#line 3991 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1244 "src/p.y" /* yacc.c:1646  */
    {
                        (yyval.string) = (yyvsp[0].string);
                  }
#line 3999 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1249 "src/p.y" /* yacc.c:1646  */
    {
                    /* This is a workaround to support content match without having to create an URL object. 'urloption' creates the Request_T object we need minus the URL object, but with enough information to perform content test.
                     TODO: Parser is in need of refactoring */
                    portset.url_request = urlrequest;
                    addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addport(&(current->portlist), &portset);
                  }
#line 4011 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1274 "src/p.y" /* yacc.c:1646  */
    {
                    prepare_urlrequest((yyvsp[-5].url));
                    addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addport(&(current->portlist), &portset);
                  }
#line 4021 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1293 "src/p.y" /* yacc.c:1646  */
    {
                        addeventaction(&(portset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addport(&(current->socketlist), &portset);
                  }
#line 4030 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1310 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip;
                        icmpset.type = (yyvsp[-5].number);
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                  }
#line 4041 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1316 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4051 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1321 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip4;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4061 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1326 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.family = Socket_Ip6;
                        addeventaction(&(icmpset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addicmp(&icmpset);
                 }
#line 4071 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1342 "src/p.y" /* yacc.c:1646  */
    {
                        portset.hostname = Str_dup(current->type == Service_Host ? current->path : LOCALHOST);
                  }
#line 4079 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1345 "src/p.y" /* yacc.c:1646  */
    {
                        portset.hostname = (yyvsp[0].string);
                  }
#line 4087 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1350 "src/p.y" /* yacc.c:1646  */
    {
                        portset.target.net.port = (yyvsp[0].number);
                  }
#line 4095 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1355 "src/p.y" /* yacc.c:1646  */
    {
                        portset.family = Socket_Unix;
                        portset.target.unix.pathname = (yyvsp[0].string);
                  }
#line 4104 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1361 "src/p.y" /* yacc.c:1646  */
    {
                    portset.family = Socket_Ip4;
                  }
#line 4112 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1364 "src/p.y" /* yacc.c:1646  */
    {
                    portset.family = Socket_Ip6;
                  }
#line 4120 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1369 "src/p.y" /* yacc.c:1646  */
    {
                    portset.type = Socket_Tcp;
                  }
#line 4128 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1372 "src/p.y" /* yacc.c:1646  */
    { // The typelist is kept for backward compatibility (replaced by ssloptionlist)
                    portset.type = Socket_Tcp;
                    sslset.use_ssl = true;
                  }
#line 4137 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1376 "src/p.y" /* yacc.c:1646  */
    {
                    portset.type = Socket_Udp;
                  }
#line 4145 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1389 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_APACHESTATUS);
                  }
#line 4153 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1392 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DEFAULT);
                  }
#line 4161 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1395 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DNS);
                  }
#line 4169 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1398 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_DWP);
                  }
#line 4177 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1401 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_FTP);
                  }
#line 4185 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1404 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_HTTP);
                  }
#line 4193 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1407 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_HTTP);
                 }
#line 4203 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 393:
#line 1412 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_IMAP);
                  }
#line 4211 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 394:
#line 1415 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_IMAP);
                  }
#line 4221 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 395:
#line 1420 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_CLAMAV);
                  }
#line 4229 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 396:
#line 1423 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LDAP2);
                  }
#line 4237 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 397:
#line 1426 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LDAP3);
                  }
#line 4245 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 398:
#line 1429 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MONGODB);
                  }
#line 4253 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 399:
#line 1432 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MYSQL);
                  }
#line 4261 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 400:
#line 1435 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SIP);
                  }
#line 4269 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 401:
#line 1438 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_NNTP);
                  }
#line 4277 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 402:
#line 1441 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_NTP3);
                        portset.type = Socket_Udp;
                  }
#line 4286 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 403:
#line 1445 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_POSTFIXPOLICY);
                  }
#line 4294 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 404:
#line 1448 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_POP);
                  }
#line 4302 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 405:
#line 1451 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_POP);
                  }
#line 4312 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 406:
#line 1456 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SIEVE);
                  }
#line 4320 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 407:
#line 1459 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SMTP);
                  }
#line 4328 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 408:
#line 1462 "src/p.y" /* yacc.c:1646  */
    {
                        sslset.use_ssl = true;
                        portset.type = Socket_Tcp;
                        portset.protocol = Protocol_get(Protocol_SMTP);
                 }
#line 4338 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 409:
#line 1467 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_SSH);
                  }
#line 4346 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 410:
#line 1470 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RDATE);
                  }
#line 4354 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 411:
#line 1473 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_REDIS);
                  }
#line 4362 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 412:
#line 1476 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RSYNC);
                  }
#line 4370 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 413:
#line 1479 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_TNS);
                  }
#line 4378 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 414:
#line 1482 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_PGSQL);
                  }
#line 4386 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 415:
#line 1485 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_LMTP);
                  }
#line 4394 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 416:
#line 1488 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_GPS);
                  }
#line 4402 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 417:
#line 1491 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_RADIUS);
                  }
#line 4410 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 418:
#line 1494 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_MEMCACHE);
                  }
#line 4418 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 419:
#line 1497 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_WEBSOCKET);
                  }
#line 4426 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 420:
#line 1502 "src/p.y" /* yacc.c:1646  */
    {
                        portset.protocol = Protocol_get(Protocol_GENERIC);
                  }
#line 4434 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 422:
#line 1508 "src/p.y" /* yacc.c:1646  */
    {
                    addgeneric(&portset, (yyvsp[0].string), NULL);
                  }
#line 4442 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 423:
#line 1511 "src/p.y" /* yacc.c:1646  */
    {
                    addgeneric(&portset, NULL, (yyvsp[0].string));
                  }
#line 4450 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 426:
#line 1520 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.origin = (yyvsp[0].string);
                  }
#line 4458 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 427:
#line 1523 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.request = (yyvsp[0].string);
                  }
#line 4466 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 428:
#line 1526 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.host = (yyvsp[0].string);
                  }
#line 4474 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 429:
#line 1529 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.websocket.version = (yyvsp[0].number);
                  }
#line 4482 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 432:
#line 1538 "src/p.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[0].string)) {
                                if (strlen((yyvsp[0].string)) > 16)
                                        yyerror2("Username too long -- Maximum MySQL username lengh is 16 characters");
                                else
                                        portset.parameters.mysql.username = (yyvsp[0].string);
                        }
                  }
#line 4495 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 433:
#line 1546 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.mysql.password = (yyvsp[0].string);
                  }
#line 4503 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 434:
#line 1551 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4511 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 435:
#line 1554 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4519 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 436:
#line 1559 "src/p.y" /* yacc.c:1646  */
    {
                     (yyval.number) = verifyMaxForward((yyvsp[0].number));
                  }
#line 4527 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 439:
#line 1568 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.sip.target = (yyvsp[0].string);
                  }
#line 4535 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 440:
#line 1571 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.sip.maxforward = (yyvsp[0].number);
                  }
#line 4543 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 448:
#line 1587 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.operator = (yyvsp[-1].number);
                    portset.parameters.http.status = (yyvsp[0].number);
                  }
#line 4552 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 449:
#line 1593 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.request = Util_urlEncode((yyvsp[0].string));
                    FREE((yyvsp[0].string));
                  }
#line 4561 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 450:
#line 1599 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.http.checksum = (yyvsp[0].string);
                  }
#line 4569 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 451:
#line 1604 "src/p.y" /* yacc.c:1646  */
    {
                    addhttpheader(&portset, Str_cat("Host:%s", (yyvsp[0].string)));
                    FREE((yyvsp[0].string));
                  }
#line 4578 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 453:
#line 1611 "src/p.y" /* yacc.c:1646  */
    {
                        addhttpheader(&portset, (yyvsp[0].string));
                 }
#line 4586 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 454:
#line 1616 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.string) = (yyvsp[0].string);
                  }
#line 4594 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 457:
#line 1625 "src/p.y" /* yacc.c:1646  */
    {
                        portset.parameters.radius.secret = (yyvsp[0].string);
                  }
#line 4602 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 460:
#line 1634 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.loglimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.loglimit = (yyvsp[-1].number);
                  }
#line 4611 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 461:
#line 1638 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.closelimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.closelimit = (yyvsp[-1].number);
                  }
#line 4620 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 462:
#line 1642 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.dnslimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.dnslimit = (yyvsp[-1].number);
                  }
#line 4629 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 463:
#line 1646 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.keepalivelimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.keepalivelimit = (yyvsp[-1].number);
                  }
#line 4638 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 464:
#line 1650 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.replylimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.replylimit = (yyvsp[-1].number);
                  }
#line 4647 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 465:
#line 1654 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.requestlimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.requestlimit = (yyvsp[-1].number);
                  }
#line 4656 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 466:
#line 1658 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.startlimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.startlimit = (yyvsp[-1].number);
                  }
#line 4665 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 467:
#line 1662 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.waitlimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.waitlimit = (yyvsp[-1].number);
                  }
#line 4674 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 468:
#line 1666 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.gracefullimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.gracefullimit = (yyvsp[-1].number);
                  }
#line 4683 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 469:
#line 1670 "src/p.y" /* yacc.c:1646  */
    {
                    portset.parameters.apachestatus.cleanuplimitOP = (yyvsp[-2].number);
                    portset.parameters.apachestatus.cleanuplimit = (yyvsp[-1].number);
                  }
#line 4692 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 470:
#line 1676 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(nonexistset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addnonexist(&nonexistset);
                  }
#line 4701 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 471:
#line 1683 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(pidset).action, (yyvsp[0].number), Action_Ignored);
                    addpid(&pidset);
                  }
#line 4710 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 472:
#line 1689 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(ppidset).action, (yyvsp[0].number), Action_Ignored);
                    addppid(&ppidset);
                  }
#line 4719 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 473:
#line 1695 "src/p.y" /* yacc.c:1646  */
    {
                    uptimeset.operator = (yyvsp[-6].number);
                    uptimeset.uptime = ((unsigned long long)(yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(uptimeset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    adduptime(&uptimeset);
                  }
#line 4730 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 474:
#line 1702 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.count = (yyvsp[0].number);
                 }
#line 4738 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 475:
#line 1707 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.size = (yyvsp[0].number);
                 }
#line 4746 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 476:
#line 1712 "src/p.y" /* yacc.c:1646  */
    {
                        icmpset.timeout = (yyvsp[-1].number) * 1000; // timeout is in milliseconds internally
                    }
#line 4754 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 477:
#line 1717 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = EXEC_TIMEOUT;
                  }
#line 4762 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 478:
#line 1720 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number);
                  }
#line 4770 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 479:
#line 1725 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = PROGRAM_TIMEOUT; // Default program status check timeout is 5 min
                  }
#line 4778 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 480:
#line 1728 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number);
                  }
#line 4786 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 481:
#line 1733 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = NET_TIMEOUT; // timeout is in milliseconds
                  }
#line 4794 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 482:
#line 1736 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[-1].number) * 1000; // net timeout is in milliseconds internally
                  }
#line 4802 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 483:
#line 1741 "src/p.y" /* yacc.c:1646  */
    {
                        portset.timeout = (yyvsp[-1].number) * 1000; // timeout is in milliseconds internally
                    }
#line 4810 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 484:
#line 1746 "src/p.y" /* yacc.c:1646  */
    {
                   (yyval.number) = (yyvsp[0].number);
                  }
#line 4818 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 485:
#line 1751 "src/p.y" /* yacc.c:1646  */
    {
                   actionrateset.count = (yyvsp[-5].number);
                   actionrateset.cycle = (yyvsp[-3].number);
                   addeventaction(&(actionrateset).action, (yyvsp[0].number), Action_Alert);
                   addactionrate(&actionrateset);
                 }
#line 4829 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 486:
#line 1757 "src/p.y" /* yacc.c:1646  */
    {
                   actionrateset.count = (yyvsp[-5].number);
                   actionrateset.cycle = (yyvsp[-3].number);
                   addeventaction(&(actionrateset).action, Action_Unmonitor, Action_Alert);
                   addactionrate(&actionrateset);
                 }
#line 4840 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 487:
#line 1765 "src/p.y" /* yacc.c:1646  */
    {
                    seturlrequest((yyvsp[-1].number), (yyvsp[0].string));
                    FREE((yyvsp[0].string));
                  }
#line 4849 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 488:
#line 1771 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 4855 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 489:
#line 1772 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_NotEqual; }
#line 4861 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 490:
#line 1775 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = Event_All;
                   addmail((yyvsp[-2].string), &mailset, &current->maillist);
                  }
#line 4870 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 491:
#line 1779 "src/p.y" /* yacc.c:1646  */
    {
                   addmail((yyvsp[-5].string), &mailset, &current->maillist);
                  }
#line 4878 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 492:
#line 1782 "src/p.y" /* yacc.c:1646  */
    {
                   mailset.events = ~mailset.events;
                   addmail((yyvsp[-6].string), &mailset, &current->maillist);
                  }
#line 4887 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 493:
#line 1786 "src/p.y" /* yacc.c:1646  */
    {
                   addmail((yyvsp[0].string), &mailset, &current->maillist);
                  }
#line 4895 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 494:
#line 1791 "src/p.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 4901 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 495:
#line 1794 "src/p.y" /* yacc.c:1646  */
    { (yyval.string) = (yyvsp[0].string); }
#line 4907 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 498:
#line 1801 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Action; }
#line 4913 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 499:
#line 1802 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_ByteIn; }
#line 4919 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 500:
#line 1803 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_ByteOut; }
#line 4925 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 501:
#line 1804 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Checksum; }
#line 4931 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 502:
#line 1805 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Connection; }
#line 4937 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 503:
#line 1806 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Content; }
#line 4943 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 504:
#line 1807 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Data; }
#line 4949 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 505:
#line 1808 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Exec; }
#line 4955 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 506:
#line 1809 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Fsflag; }
#line 4961 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 507:
#line 1810 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Gid; }
#line 4967 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 508:
#line 1811 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Icmp; }
#line 4973 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 509:
#line 1812 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Instance; }
#line 4979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 510:
#line 1813 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Invalid; }
#line 4985 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 511:
#line 1814 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Link; }
#line 4991 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 512:
#line 1815 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Nonexist; }
#line 4997 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 513:
#line 1816 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PacketIn; }
#line 5003 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 514:
#line 1817 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PacketOut; }
#line 5009 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 515:
#line 1818 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Permission; }
#line 5015 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 516:
#line 1819 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Pid; }
#line 5021 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 517:
#line 1820 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_PPid; }
#line 5027 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 518:
#line 1821 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Resource; }
#line 5033 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 519:
#line 1822 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Saturation; }
#line 5039 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 520:
#line 1823 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Size; }
#line 5045 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 521:
#line 1824 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Speed; }
#line 5051 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 522:
#line 1825 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Status; }
#line 5057 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 523:
#line 1826 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Timeout; }
#line 5063 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 524:
#line 1827 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Timestamp; }
#line 5069 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 525:
#line 1828 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Uid; }
#line 5075 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 526:
#line 1829 "src/p.y" /* yacc.c:1646  */
    { mailset.events |= Event_Uptime; }
#line 5081 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 531:
#line 1840 "src/p.y" /* yacc.c:1646  */
    { mailset.from = (yyvsp[0].string); }
#line 5087 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 532:
#line 1841 "src/p.y" /* yacc.c:1646  */
    { mailset.replyto = (yyvsp[0].string); }
#line 5093 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 533:
#line 1842 "src/p.y" /* yacc.c:1646  */
    { mailset.subject = (yyvsp[0].string); }
#line 5099 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 534:
#line 1843 "src/p.y" /* yacc.c:1646  */
    { mailset.message = (yyvsp[0].string); }
#line 5105 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 535:
#line 1846 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_SkipCycles;
                   current->every.spec.cycle.number = (yyvsp[-1].number);
                 }
#line 5114 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 536:
#line 1850 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_Cron;
                   current->every.spec.cron = (yyvsp[0].string);
                 }
#line 5123 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 537:
#line 1854 "src/p.y" /* yacc.c:1646  */
    {
                   current->every.type = Every_NotInCron;
                   current->every.spec.cron = (yyvsp[0].string);
                 }
#line 5132 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 538:
#line 1860 "src/p.y" /* yacc.c:1646  */
    {
                    current->mode = Monitor_Active;
                  }
#line 5140 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 539:
#line 1863 "src/p.y" /* yacc.c:1646  */
    {
                    current->mode = Monitor_Passive;
                  }
#line 5148 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 540:
#line 1866 "src/p.y" /* yacc.c:1646  */
    {
                    current->mode = Monitor_Manual;
                    current->monitor = Monitor_Not;
                  }
#line 5157 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 541:
#line 1872 "src/p.y" /* yacc.c:1646  */
    {
                        addservicegroup((yyvsp[0].string));
                        FREE((yyvsp[0].string));
                  }
#line 5166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 545:
#line 1886 "src/p.y" /* yacc.c:1646  */
    { adddependant((yyvsp[0].string)); }
#line 5172 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 546:
#line 1889 "src/p.y" /* yacc.c:1646  */
    {
                        statusset.initialized = true;
                        statusset.operator = (yyvsp[-5].number);
                        statusset.return_value = (yyvsp[-4].number);
                        addeventaction(&(statusset).action, (yyvsp[-1].number), (yyvsp[0].number));
                        addstatus(&statusset);
                   }
#line 5184 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 547:
#line 1896 "src/p.y" /* yacc.c:1646  */
    {
                        statusset.initialized = false;
                        statusset.operator = Operator_Changed;
                        statusset.return_value = 0;
                        addeventaction(&(statusset).action, (yyvsp[0].number), Action_Ignored);
                        addstatus(&statusset);
                   }
#line 5196 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 548:
#line 1905 "src/p.y" /* yacc.c:1646  */
    {
                     addeventaction(&(resourceset).action, (yyvsp[-1].number), (yyvsp[0].number));
                     addresource(&resourceset);
                   }
#line 5205 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 555:
#line 1921 "src/p.y" /* yacc.c:1646  */
    {
                     addeventaction(&(resourceset).action, (yyvsp[-1].number), (yyvsp[0].number));
                     addresource(&resourceset);
                   }
#line 5214 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 562:
#line 1937 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_CpuPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5224 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 563:
#line 1942 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_CpuPercentTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5234 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 564:
#line 1949 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = (yyvsp[-3].number);
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5244 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 565:
#line 1956 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuUser; }
#line 5250 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 566:
#line 1957 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuSystem; }
#line 5256 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 567:
#line 1958 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuWait; }
#line 5262 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 568:
#line 1959 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_CpuPercent; }
#line 5268 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 569:
#line 1962 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryKbyte;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (int) ((yyvsp[-1].real) * ((yyvsp[0].number) / 1024.0));
                  }
#line 5278 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 570:
#line 1967 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5288 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 571:
#line 1972 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryKbyteTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (int) ((yyvsp[-1].real) * ((yyvsp[0].number) / 1024.0));
                  }
#line 5298 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 572:
#line 1977 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_MemoryPercentTotal;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5308 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 573:
#line 1984 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_SwapKbyte;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = (int) ((yyvsp[-1].real) * ((yyvsp[0].number) / 1024.0));
                  }
#line 5318 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 574:
#line 1989 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_SwapPercent;
                    resourceset.operator = (yyvsp[-2].number);
                    resourceset.limit = ((yyvsp[-1].number) * 10);
                  }
#line 5328 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 575:
#line 1996 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = Resource_Children;
                    resourceset.operator = (yyvsp[-1].number);
                    resourceset.limit = (int) (yyvsp[0].number);
                  }
#line 5338 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2003 "src/p.y" /* yacc.c:1646  */
    {
                    resourceset.resource_id = (yyvsp[-2].number);
                    resourceset.operator = (yyvsp[-1].number);
                    resourceset.limit = (int) ((yyvsp[0].real) * 10.0);
                  }
#line 5348 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2010 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage1m; }
#line 5354 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2011 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage5m; }
#line 5360 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2012 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Resource_LoadAverage15m; }
#line 5366 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2015 "src/p.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[0].real); }
#line 5372 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2016 "src/p.y" /* yacc.c:1646  */
    { (yyval.real) = (float) (yyvsp[0].number); }
#line 5378 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2019 "src/p.y" /* yacc.c:1646  */
    {
                    timestampset.operator = (yyvsp[-6].number);
                    timestampset.time = ((yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(timestampset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addtimestamp(&timestampset, false);
                  }
#line 5389 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2025 "src/p.y" /* yacc.c:1646  */
    {
                    timestampset.test_changes = true;
                    addeventaction(&(timestampset).action, (yyvsp[0].number), Action_Ignored);
                    addtimestamp(&timestampset, true);
                  }
#line 5399 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2032 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 5405 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2033 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Greater; }
#line 5411 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2034 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Less; }
#line 5417 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2035 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Equal; }
#line 5423 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2036 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_NotEqual; }
#line 5429 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2037 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Operator_Changed; }
#line 5435 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2040 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5441 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2041 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5447 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2042 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Minute; }
#line 5453 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2043 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Hour; }
#line 5459 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2044 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Day; }
#line 5465 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2045 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Month; }
#line 5471 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2048 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Minute; }
#line 5477 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2049 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Hour; }
#line 5483 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2050 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Day; }
#line 5489 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2052 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5495 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2053 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Time_Second; }
#line 5501 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2055 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Alert; }
#line 5507 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2056 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Exec; }
#line 5513 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2057 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Exec; }
#line 5519 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2058 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Restart; }
#line 5525 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2059 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Start; }
#line 5531 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2060 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Stop; }
#line 5537 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2061 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Action_Unmonitor; }
#line 5543 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2064 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                    if ((yyvsp[0].number) == Action_Exec && command) {
                      command1 = command;
                      command = NULL;
                    }
                  }
#line 5555 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2073 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                    if ((yyvsp[0].number) == Action_Exec && command) {
                      command2 = command;
                      command = NULL;
                    }
                  }
#line 5567 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2083 "src/p.y" /* yacc.c:1646  */
    {
                    rate1.count  = (yyvsp[-1].number);
                    rate1.cycles = (yyvsp[-1].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
#line 5578 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2089 "src/p.y" /* yacc.c:1646  */
    {
                    rate1.count  = (yyvsp[-2].number);
                    rate1.cycles = (yyvsp[-1].number);
                    if (rate1.cycles < 1 || rate1.cycles > BITMAP_MAX)
                      yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate1.count < 1 || rate1.count > rate1.cycles)
                      yyerror2("The number of events must be bigger then 0 and less than poll cycles");
                  }
#line 5591 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2100 "src/p.y" /* yacc.c:1646  */
    {
                    rate2.count  = (yyvsp[-1].number);
                    rate2.cycles = (yyvsp[-1].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                  }
#line 5602 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2106 "src/p.y" /* yacc.c:1646  */
    {
                    rate2.count  = (yyvsp[-2].number);
                    rate2.cycles = (yyvsp[-1].number);
                    if (rate2.cycles < 1 || rate2.cycles > BITMAP_MAX)
                      yyerror2("The number of cycles must be between 1 and %d", BITMAP_MAX);
                    if (rate2.count < 1 || rate2.count > rate2.cycles)
                      yyerror2("The number of events must be bigger then 0 and less than poll cycles");
                  }
#line 5615 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 616:
#line 2116 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = Action_Alert;
                  }
#line 5623 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 617:
#line 2119 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 5631 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 618:
#line 2122 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 5639 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 619:
#line 2125 "src/p.y" /* yacc.c:1646  */
    {
                    (yyval.number) = (yyvsp[0].number);
                  }
#line 5647 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 620:
#line 2130 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(checksumset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addchecksum(&checksumset);
                  }
#line 5656 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 621:
#line 2135 "src/p.y" /* yacc.c:1646  */
    {
                    snprintf(checksumset.hash, sizeof(checksumset.hash), "%s", (yyvsp[-4].string));
                    FREE((yyvsp[-4].string));
                    addeventaction(&(checksumset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addchecksum(&checksumset);
                  }
#line 5667 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2141 "src/p.y" /* yacc.c:1646  */
    {
                    checksumset.test_changes = true;
                    addeventaction(&(checksumset).action, (yyvsp[0].number), Action_Ignored);
                    addchecksum(&checksumset);
                  }
#line 5677 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2147 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Unknown; }
#line 5683 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2148 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Md5; }
#line 5689 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2149 "src/p.y" /* yacc.c:1646  */
    { checksumset.type = Hash_Sha1; }
#line 5695 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2152 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Inode;
                    filesystemset.operator = (yyvsp[-5].number);
                    filesystemset.limit_absolute = (yyvsp[-4].number);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5707 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2159 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Inode;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (int)((yyvsp[-5].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5719 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2166 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_InodeFree;
                    filesystemset.operator = (yyvsp[-5].number);
                    filesystemset.limit_absolute = (yyvsp[-4].number);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5731 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2173 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_InodeFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (int)((yyvsp[-5].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5743 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2182 "src/p.y" /* yacc.c:1646  */
    {
                    if (! filesystem_usage(current))
                      yyerror2("Cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = Resource_Space;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_absolute = (long long)((double)(yyvsp[-5].real) / (double)current->inf->priv.filesystem.f_bsize * (double)(yyvsp[-4].number));
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5757 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2191 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_Space;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (int)((yyvsp[-5].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5769 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2198 "src/p.y" /* yacc.c:1646  */
    {
                    if (! filesystem_usage(current))
                      yyerror2("Cannot read usage of filesystem %s", current->path);
                    filesystemset.resource = Resource_SpaceFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_absolute = (long long)((double)(yyvsp[-5].real) / (double)current->inf->priv.filesystem.f_bsize * (double)(yyvsp[-4].number));
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5783 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2207 "src/p.y" /* yacc.c:1646  */
    {
                    filesystemset.resource = Resource_SpaceFree;
                    filesystemset.operator = (yyvsp[-6].number);
                    filesystemset.limit_percent = (int)((yyvsp[-5].number) * 10);
                    addeventaction(&(filesystemset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addfilesystem(&filesystemset);
                  }
#line 5795 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2216 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(fsflagset).action, (yyvsp[0].number), Action_Ignored);
                    addfsflag(&fsflagset);
                  }
#line 5804 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2222 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Byte; }
#line 5810 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2223 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Byte; }
#line 5816 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2224 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Kilobyte; }
#line 5822 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2225 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Megabyte; }
#line 5828 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2226 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = Unit_Gigabyte; }
#line 5834 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 640:
#line 2229 "src/p.y" /* yacc.c:1646  */
    {
                    permset.perm = check_perm((yyvsp[-4].number));
                    addeventaction(&(permset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addperm(&permset);
                  }
#line 5844 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 641:
#line 2234 "src/p.y" /* yacc.c:1646  */
    {
                    permset.test_changes = true;
                    addeventaction(&(permset).action, (yyvsp[-1].number), Action_Ignored);
                    addperm(&permset);
                  }
#line 5854 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 642:
#line 2241 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = false;
                    matchset.match_path = (yyvsp[-3].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, (yyvsp[0].number));
                    FREE((yyvsp[-3].string));
                  }
#line 5866 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 643:
#line 2248 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = false;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[-3].string);
                    addmatch(&matchset, (yyvsp[0].number), 0);
                  }
#line 5877 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 644:
#line 2254 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = true;
                    matchset.match_path = (yyvsp[0].string);
                    matchset.match_string = NULL;
                    addmatchpath(&matchset, Action_Ignored);
                    FREE((yyvsp[0].string));
                  }
#line 5889 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 645:
#line 2261 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.ignore = true;
                    matchset.match_path = NULL;
                    matchset.match_string = (yyvsp[0].string);
                    addmatch(&matchset, Action_Ignored, 0);
                  }
#line 5900 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2269 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = false;
                  }
#line 5908 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2272 "src/p.y" /* yacc.c:1646  */
    {
                    matchset.not = true;
                  }
#line 5916 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2278 "src/p.y" /* yacc.c:1646  */
    {
                    sizeset.operator = (yyvsp[-6].number);
                    sizeset.size = ((unsigned long long)(yyvsp[-5].number) * (yyvsp[-4].number));
                    addeventaction(&(sizeset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addsize(&sizeset);
                  }
#line 5927 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2284 "src/p.y" /* yacc.c:1646  */
    {
                    sizeset.test_changes = true;
                    addeventaction(&(sizeset).action, (yyvsp[0].number), Action_Ignored);
                    addsize(&sizeset);
                  }
#line 5937 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2291 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid((yyvsp[-4].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->uid = adduid(&uidset);
                    FREE((yyvsp[-4].string));
                  }
#line 5948 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2297 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid(NULL, (yyvsp[-4].number));
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->uid = adduid(&uidset);
                  }
#line 5958 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2304 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid((yyvsp[-4].string), 0);
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->euid = adduid(&uidset);
                    FREE((yyvsp[-4].string));
                  }
#line 5969 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2310 "src/p.y" /* yacc.c:1646  */
    {
                    uidset.uid = get_uid(NULL, (yyvsp[-4].number));
                    addeventaction(&(uidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->euid = adduid(&uidset);
                  }
#line 5979 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2317 "src/p.y" /* yacc.c:1646  */
    {
                    gidset.gid = get_gid((yyvsp[-4].string), 0);
                    addeventaction(&(gidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->gid = addgid(&gidset);
                    FREE((yyvsp[-4].string));
                  }
#line 5990 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2323 "src/p.y" /* yacc.c:1646  */
    {
                    gidset.gid = get_gid(NULL, (yyvsp[-4].number));
                    addeventaction(&(gidset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    current->gid = addgid(&gidset);
                  }
#line 6000 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 656:
#line 2330 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(linkstatusset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinkstatus(current, &linkstatusset);
                  }
#line 6009 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 657:
#line 2336 "src/p.y" /* yacc.c:1646  */
    {
                    addeventaction(&(linkspeedset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinkspeed(current, &linkspeedset);
                  }
#line 6018 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 658:
#line 2341 "src/p.y" /* yacc.c:1646  */
    {
                    linksaturationset.operator = (yyvsp[-6].number);
                    linksaturationset.limit = (unsigned long long)(yyvsp[-5].number);
                    addeventaction(&(linksaturationset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addlinksaturation(current, &linksaturationset);
                  }
#line 6029 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 659:
#line 2349 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6042 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 660:
#line 2357 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6055 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 661:
#line 2365 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-7].number) * (yyvsp[-6].number));
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadbyteslist), &bandwidthset);
                  }
#line 6068 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 662:
#line 2373 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6081 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 663:
#line 2381 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6094 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 664:
#line 2389 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-7].number);
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->uploadpacketslist), &bandwidthset);
                  }
#line 6107 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 665:
#line 2399 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6120 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 666:
#line 2407 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-6].number) * (yyvsp[-5].number));
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6133 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 667:
#line 2415 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = ((unsigned long long)(yyvsp[-7].number) * (yyvsp[-6].number));
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadbyteslist), &bandwidthset);
                  }
#line 6146 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 668:
#line 2423 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6159 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 669:
#line 2431 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-7].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-6].number);
                    bandwidthset.rangecount = 1;
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6172 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 670:
#line 2439 "src/p.y" /* yacc.c:1646  */
    {
                    bandwidthset.operator = (yyvsp[-8].number);
                    bandwidthset.limit = (unsigned long long)(yyvsp[-7].number);
                    bandwidthset.rangecount = (yyvsp[-5].number);
                    bandwidthset.range = (yyvsp[-4].number);
                    addeventaction(&(bandwidthset).action, (yyvsp[-1].number), (yyvsp[0].number));
                    addbandwidth(&(current->downloadpacketslist), &bandwidthset);
                  }
#line 6185 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 671:
#line 2449 "src/p.y" /* yacc.c:1646  */
    { (yyval.number) = ICMP_ECHO; }
#line 6191 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 672:
#line 2452 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = 0; }
#line 6197 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 673:
#line 2453 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = (yyvsp[0].number); }
#line 6203 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 674:
#line 2454 "src/p.y" /* yacc.c:1646  */
    { mailset.reminder = (yyvsp[-1].number); }
#line 6209 "src/y.tab.c" /* yacc.c:1646  */
    break;


#line 6213 "src/y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2457 "src/p.y" /* yacc.c:1906  */



/* -------------------------------------------------------- Parser interface */


/**
 * Syntactic error routine
 *
 * This routine is automatically called by the lexer!
 */
void yyerror(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogError("%s:%i: %s '%s'\n", currentfile, lineno, msg, yytext);
        cfg_errflag++;

        FREE(msg);

}

/**
 * Syntactical warning routine
 */
void yywarning(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogWarning("%s:%i: %s '%s'\n", currentfile, lineno, msg, yytext);

        FREE(msg);

}

/**
 * Argument error routine
 */
void yyerror2(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogError("%s:%i: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);
        cfg_errflag++;

        FREE(msg);

}

/**
 * Argument warning routine
 */
void yywarning2(const char *s, ...) {
        va_list ap;
        char *msg = NULL;

        ASSERT(s);

        va_start(ap,s);
        msg = Str_vcat(s, ap);
        va_end(ap);

        LogWarning("%s:%i: %s '%s'\n", argcurrentfile, arglineno, msg, argyytext);

        FREE(msg);

}

/*
 * The Parser hook - start parsing the control file
 * Returns true if parsing succeeded, otherwise false
 */
boolean_t parse(char *controlfile) {

        ASSERT(controlfile);

        servicelist = tail = current = NULL;

        if ((yyin = fopen(controlfile,"r")) == (FILE *)NULL) {
                LogError("Cannot open the control file '%s' -- %s\n", controlfile, STRERROR);
                return false;
        }

        currentfile = Str_dup(controlfile);

        /*
         * Creation of the global service list is synchronized
         */
        LOCK(Run.mutex)
        {
                preparse();
                yyparse();
                fclose(yyin);
                postparse();
        }
        END_LOCK;

        FREE(currentfile);

        if (argyytext != NULL)
                FREE(argyytext);

        /*
         * Secure check the monitrc file. The run control file must have the
         * same uid as the REAL uid of this process, it must have permissions
         * no greater than 700 and it must not be a symbolic link.
         */
        if (! file_checkStat(controlfile, "control file", S_IRUSR|S_IWUSR|S_IXUSR))
                return false;

        return cfg_errflag == 0;
}


/* ----------------------------------------------------------------- Private */


/**
 * Initialize objects used by the parser.
 */
static void preparse() {
        int i;

        /* Set instance incarnation ID */
        time(&Run.incarnation);
        /* Reset lexer */
        buffer_stack_ptr            = 0;
        lineno                      = 1;
        arglineno                   = 1;
        argcurrentfile              = NULL;
        argyytext                   = NULL;
        /* Reset parser */
        Run.mmonitcredentials       = NULL;
        Run.httpd.flags             = Httpd_Disabled | Httpd_Signature;
        Run.httpd.credentials       = NULL;
        memset(&(Run.httpd.socket), 0, sizeof(Run.httpd.socket));
        Run.mailserver_timeout      = SMTP_TIMEOUT;
        Run.eventlist               = NULL;
        Run.eventlist_dir           = NULL;
        Run.eventlist_slots         = -1;
        Run.system                  = NULL;
        Run.expectbuffer            = STRLEN;
        Run.mmonits                 = NULL;
        Run.maillist                = NULL;
        Run.mailservers             = NULL;
        Run.MailFormat.from         = NULL;
        Run.MailFormat.replyto      = NULL;
        Run.MailFormat.subject      = NULL;
        Run.MailFormat.message      = NULL;
        depend_list                 = NULL;
        Run.flags |= Run_HandlerInit | Run_MmonitCredentials;
        for (i = 0; i <= Handler_Max; i++)
                Run.handler_queue[i] = 0;
        /*
         * Initialize objects
         */
        reset_uidset();
        reset_gidset();
        reset_statusset();
        reset_sizeset();
        reset_mailset();
        reset_sslset();
        reset_mailserverset();
        reset_mmonitset();
        reset_portset();
        reset_permset();
        reset_icmpset();
        reset_linkstatusset();
        reset_linkspeedset();
        reset_linksaturationset();
        reset_bandwidthset();
        reset_rateset();
        reset_filesystemset();
        reset_resourceset();
        reset_checksumset();
        reset_timestampset();
        reset_actionrateset();
}


/*
 * Check that values are reasonable after parsing
 */
static void postparse() {
        if (cfg_errflag)
                return;

        /* If defined - add the last service to the service list */
        if (current)
                addservice(current);

        /* Check that we do not start monit in daemon mode without having a poll time */
        if (! Run.polltime && ((Run.flags & Run_Daemon) || (Run.flags & Run_Foreground))) {
                LogError("Poll time is invalid or not defined. Please define poll time in the control file\nas a number (> 0)  or use the -d option when starting monit\n");
                cfg_errflag++;
        }

        if (Run.files.log)
                Run.flags |= Run_Log;

        /* Add the default general system service if not specified explicitly: service name default to hostname */
        if (! Run.system) {
                char hostname[STRLEN];
                if (Util_getfqdnhostname(hostname, sizeof(hostname))) {
                        LogError("Cannot get system hostname -- please add 'check system <name>'\n");
                        cfg_errflag++;
                }
                if (Util_existService(hostname)) {
                        LogError("'check system' not defined in control file, failed to add automatic configuration (service name %s is used already) -- please add 'check system <name>' manually\n", hostname);
                        cfg_errflag++;
                } else {
                        Run.system = createservice(Service_System, Str_dup(hostname), Str_dup(""), check_system);
                        addservice(Run.system);
                }
        }

        if (Run.mmonits) {
                if (Run.httpd.flags & Httpd_Net) {
                        if (Run.flags & Run_MmonitCredentials) {
                                Auth_T c;
                                for (c = Run.httpd.credentials; c; c = c->next) {
                                        if (c->digesttype == Digest_Cleartext && ! c->is_readonly) {
                                                Run.mmonitcredentials = c;
                                                break;
                                        }
                                }
                                if (! Run.mmonitcredentials)
                                        LogWarning("M/Monit registration with credentials enabled, but no suitable credentials found in monit configuration file -- please add 'allow user:password' option to 'set httpd' statement\n");
                        }
                } else if (Run.httpd.flags & Httpd_Unix) {
                        LogWarning("M/Monit enabled but Monit httpd is using unix socket -- please change 'set httpd' statement to use TCP port in order to be able to manage services on Monit\n");
                } else {
                        LogWarning("M/Monit enabled but no httpd allowed -- please add 'set httpd' statement\n");
                }
        }

        /* Check the sanity of any dependency graph */
        check_depend();

#ifdef HAVE_OPENSSL
        Ssl_setFipsMode(Run.flags & Run_FipsEnabled);
#endif
}


/*
 * Create a new service object and add any current objects to the
 * service list.
 */
static Service_T createservice(Service_Type type, char *name, char *value, State_Type (*check)(Service_T s)) {
        ASSERT(name);
        ASSERT(value);

        check_name(name);

        if (current)
                addservice(current);

        NEW(current);

        current->type = type;

        NEW(current->inf);
        Util_resetInfo(current);

        if (type == Service_Program) {
                NEW(current->program);
                current->program->args = command;
                command = NULL;
                current->program->timeout = PROGRAM_TIMEOUT;
        }

        /* Set default values */
        current->monitor = Monitor_Init;
        current->mode    = Monitor_Active;
        current->name    = name;
        current->check   = check;
        current->path    = value;

        /* Initialize general event handlers */
        addeventaction(&(current)->action_DATA,     Action_Alert,     Action_Alert);
        addeventaction(&(current)->action_EXEC,     Action_Alert,     Action_Alert);
        addeventaction(&(current)->action_INVALID,  Action_Restart,   Action_Alert);

        /* Initialize internal event handlers */
        addeventaction(&(current)->action_MONIT_START,  Action_Start, Action_Ignored);
        addeventaction(&(current)->action_MONIT_STOP,   Action_Stop,  Action_Ignored);
        addeventaction(&(current)->action_MONIT_RELOAD, Action_Start, Action_Ignored);
        addeventaction(&(current)->action_ACTION,       Action_Alert, Action_Ignored);

        gettimeofday(&current->collected, NULL);

        return current;
}


/*
 * Add a service object to the servicelist
 */
static void addservice(Service_T s) {
        ASSERT(s);

        // Test sanity check
        switch (s->type) {
                case Service_Host:
                        // Verify that a remote service has a port or an icmp list
                        if (! s->portlist && ! s->icmplist) {
                                LogError("'check host' statement is incomplete: Please specify a port number to test\n or an icmp test at the remote host: '%s'\n", s->name);
                                cfg_errflag++;
                        }
                        break;
                case Service_Program:
                        // Verify that a program test has a status test
                        if (! s->statuslist) {
                                LogError("'check program %s' is incomplete: Please add an 'if status != n' test\n", s->name);
                                cfg_errflag++;
                        }
                        // Create the Command object
                        s->program->C = Command_new(s->path, NULL);
                        // Append any arguments
                        for (int i = 1; i < s->program->args->length; i++)
                                Command_appendArgument(s->program->C, s->program->args->arg[i]);
                        if (s->program->args->has_uid)
                                Command_setUid(s->program->C, s->program->args->uid);
                        if (s->program->args->has_gid)
                                Command_setGid(s->program->C, s->program->args->gid);
                        break;
                case Service_Net:
                        if (! s->linkstatuslist) {
                                // Add link status test if not defined
                                addeventaction(&(linkstatusset).action, Action_Alert, Action_Alert);
                                addlinkstatus(s, &linkstatusset);
                        }
                        break;
                case Service_Filesystem:
                        if (! s->fsflaglist) {
                                // Add filesystem flags change test if not defined
                                addeventaction(&(fsflagset).action, Action_Alert, Action_Ignored);
                                addfsflag(&fsflagset);
                        }
                        break;
                case Service_Directory:
                case Service_Fifo:
                case Service_File:
                case Service_Process:
                        if (! s->nonexistlist) {
                                // Add existence test if not defined
                                addeventaction(&(nonexistset).action, Action_Restart, Action_Alert);
                                addnonexist(&nonexistset);
                        }
                        break;
                default:
                        break;
        }

        /* Add the service to the end of the service list */
        if (tail != NULL) {
                tail->next = s;
                tail->next_conf = s;
        } else {
                servicelist = s;
                servicelist_conf = s;
        }
        tail = s;
}


/*
 * Add entry to service group list
 */
static void addservicegroup(char *name) {
        ServiceGroup_T g;

        ASSERT(name);

        /* Check if service group with the same name is defined already */
        for (g = servicegrouplist; g; g = g->next)
                if (IS(g->name, name))
                        break;

        if (! g) {
                NEW(g);
                g->name = Str_dup(name);
                g->members = List_new();
                g->next = servicegrouplist;
                servicegrouplist = g;
        }

        List_append(g->members, current);
}


/*
 * Add a dependant entry to the current service dependant list
 *
 */
static void adddependant(char *dependant) {
        Dependant_T d;

        ASSERT(dependant);

        NEW(d);

        if (current->dependantlist)
                d->next = current->dependantlist;

        d->dependant = dependant;
        current->dependantlist = d;

}


/*
 * Add the given mailaddress with the appropriate alert notification
 * values and mail attributes to the given mailinglist.
 */
static void addmail(char *mailto, Mail_T f, Mail_T *l) {
        Mail_T m;

        ASSERT(mailto);

        NEW(m);
        m->to       = mailto;
        m->from     = f->from;
        m->subject  = f->subject;
        m->message  = f->message;
        m->events   = f->events;
        m->reminder = f->reminder;

        m->next = *l;
        *l = m;

        reset_mailset();
}


/*
 * Add the given portset to the current service's portlist
 */
static void addport(Port_T *list, Port_T port) {
        ASSERT(port);

        if (port->protocol->check == check_radius && port->type != Socket_Udp)
                yyerror("Radius protocol test supports UDP only");

        Port_T p;
        NEW(p);
        p->type               = port->type;
        p->socket             = port->socket;
        p->family             = port->family;
        p->action             = port->action;
        p->timeout            = port->timeout;
        p->retry              = port->retry;
        p->protocol           = port->protocol;
        p->hostname           = port->hostname;
        p->url_request        = port->url_request;
        if (p->family == Socket_Unix) {
                p->target.unix.pathname = port->target.unix.pathname;
        } else {
                p->target.net.port = port->target.net.port;
                if (sslset.use_ssl == true) {
#ifdef HAVE_OPENSSL
                        p->target.net.ssl.use_ssl = true;
                        p->target.net.ssl.verify = sslset.verify;
                        p->target.net.ssl.allowSelfSigned = sslset.allowSelfSigned;
                        p->target.net.ssl.minimumValidDays = sslset.minimumValidDays;
                        p->target.net.ssl.version = sslset.version;
                        p->target.net.ssl.checksumType = sslset.checksumType;
                        p->target.net.ssl.checksum = sslset.checksum;
                        p->target.net.ssl.clientpemfile = sslset.clientpemfile;
                        p->target.net.ssl.CACertificateFile = sslset.CACertificateFile;
                        p->target.net.ssl.CACertificatePath = sslset.CACertificatePath;
#else
                        yyerror("SSL check cannot be activated -- SSL disabled");
#endif
                }
        }
        memcpy(&p->parameters, &port->parameters, sizeof(port->parameters));

        if (p->protocol->check == check_http) {
                if (p->parameters.http.checksum) {
                        cleanup_hash_string(p->parameters.http.checksum);
                        if (strlen(p->parameters.http.checksum) == 32)
                                p->parameters.http.hashtype = Hash_Md5;
                        else if (strlen(p->parameters.http.checksum) == 40)
                                p->parameters.http.hashtype = Hash_Sha1;
                        else
                                yyerror2("invalid checksum [%s]", p->parameters.http.checksum);
                } else {
                        p->parameters.http.hashtype = Hash_Unknown;
                }
        }

        p->next = *list;
        *list = p;

        reset_sslset();
        reset_portset();

}


static void addhttpheader(Port_T port, const char *header) {
        if (! port->parameters.http.headers)
                port->parameters.http.headers = List_new();
        List_append(port->parameters.http.headers, (char *)header);
}


/*
 * Add a new resource object to the current service resource list
 */
static void addresource(Resource_T rr) {
        Resource_T r;

        ASSERT(rr);

        NEW(r);
        if (! (Run.flags & Run_ProcessEngineEnabled))
                yyerror("Cannot activate service check. The process status engine was disabled. On certain systems you must run monit as root to utilize this feature)\n");
        r->resource_id = rr->resource_id;
        r->limit       = rr->limit;
        r->action      = rr->action;
        r->operator    = rr->operator;
        r->next        = current->resourcelist;

        current->resourcelist = r;
        reset_resourceset();
}


/*
 * Add a new file object to the current service timestamp list
 */
static void addtimestamp(Timestamp_T ts, boolean_t notime) {
        Timestamp_T t;

        ASSERT(ts);

        NEW(t);
        t->operator     = ts->operator;
        t->time         = ts->time;
        t->action       = ts->action;
        t->test_changes = ts->test_changes;

        if (t->test_changes || notime) {
                if (! File_exist(current->path))
                        DEBUG("The path '%s' used in the TIMESTAMP statement refer to a non-existing object\n", current->path);
                else if (! (t->timestamp = file_getTimestamp(current->path, S_IFDIR|S_IFREG)))
                        yyerror2("Cannot get the timestamp for '%s'", current->path);
        }

        t->next = current->timestamplist;
        current->timestamplist = t;

        reset_timestampset();
}


/*
 * Add a new object to the current service actionrate list
 */
static void addactionrate(ActionRate_T ar) {
        ActionRate_T a;

        ASSERT(ar);

        if (ar->count > ar->cycle)
                yyerror2("The number of restarts must be less than poll cycles");
        if (ar->count <= 0 || ar->cycle <= 0)
                yyerror2("Zero or negative values not allowed in a action rate statement");

        NEW(a);
        a->count  = ar->count;
        a->cycle  = ar->cycle;
        a->action = ar->action;

        a->next = current->actionratelist;
        current->actionratelist = a;

        reset_actionrateset();
}



/*
 * Add a new Size object to the current service size list
 */
static void addsize(Size_T ss) {
        Size_T s;
        struct stat buf;

        ASSERT(ss);

        NEW(s);
        s->operator     = ss->operator;
        s->size         = ss->size;
        s->action       = ss->action;
        s->test_changes = ss->test_changes;
        /* Get the initial size for future comparision, if the file exists */
        if (s->test_changes) {
                s->initialized = ! stat(current->path, &buf);
                if (s->initialized)
                        s->size = (unsigned long long)buf.st_size;
        }

        s->next = current->sizelist;
        current->sizelist = s;

        reset_sizeset();
}


/*
 * Add a new Uptime object to the current service uptime list
 */
static void adduptime(Uptime_T uu) {
        Uptime_T u;

        ASSERT(uu);

        NEW(u);
        u->operator = uu->operator;
        u->uptime = uu->uptime;
        u->action = uu->action;

        u->next = current->uptimelist;
        current->uptimelist = u;

        reset_uptimeset();
}


/*
 * Add a new Pid object to the current service pid list
 */
static void addpid(Pid_T pp) {
        ASSERT(pp);

        Pid_T p;
        NEW(p);
        p->action = pp->action;

        p->next = current->pidlist;
        current->pidlist = p;

        reset_pidset();
}


/*
 * Add a new PPid object to the current service ppid list
 */
static void addppid(Pid_T pp) {
        ASSERT(pp);

        Pid_T p;
        NEW(p);
        p->action = pp->action;

        p->next = current->ppidlist;
        current->ppidlist = p;

        reset_ppidset();
}


/*
 * Add a new Fsflag object to the current service fsflag list
 */
static void addfsflag(Fsflag_T ff) {
        ASSERT(ff);

        Fsflag_T f;
        NEW(f);
        f->action = ff->action;

        f->next = current->fsflaglist;
        current->fsflaglist = f;

        reset_fsflagset();
}


/*
 * Add a new Nonexist object to the current service list
 */
static void addnonexist(Nonexist_T ff) {
        ASSERT(ff);

        Nonexist_T f;
        NEW(f);
        f->action = ff->action;

        f->next = current->nonexistlist;
        current->nonexistlist = f;

        reset_nonexistset();
}


/*
 * Set Checksum object in the current service
 */
static void addchecksum(Checksum_T cs) {
        ASSERT(cs);

        cs->initialized = true;

        if (! *cs->hash) {
                if (cs->type == Hash_Unknown)
                        cs->type = Hash_Default;
                if (! (Util_getChecksum(current->path, cs->type, cs->hash, sizeof(cs->hash)))) {
                        /* If the file doesn't exist, set dummy value */
                        snprintf(cs->hash, sizeof(cs->hash), cs->type == Hash_Md5 ? "00000000000000000000000000000000" : "0000000000000000000000000000000000000000");
                        cs->initialized = false;
                        yywarning2("Cannot compute a checksum for file %s", current->path);
                }
        }

        int len = cleanup_hash_string(cs->hash);
        if (cs->type == Hash_Unknown) {
                if (len == 32) {
                        cs->type = Hash_Md5;
                } else if (len == 40) {
                        cs->type = Hash_Sha1;
                } else {
                        yyerror2("Unknown checksum type [%s] for file %s", cs->hash, current->path);
                        reset_checksumset();
                        return;
                }
        } else if ((cs->type == Hash_Md5 && len != 32) || (cs->type == Hash_Sha1 && len != 40)) {
                yyerror2("Invalid checksum [%s] for file %s", cs->hash, current->path);
                reset_checksumset();
                return;
        }

        Checksum_T c;
        NEW(c);
        c->type         = cs->type;
        c->test_changes = cs->test_changes;
        c->initialized  = cs->initialized;
        c->action       = cs->action;
        snprintf(c->hash, sizeof(c->hash), "%s", cs->hash);

        current->checksum = c;

        reset_checksumset();

}


/*
 * Set Perm object in the current service
 */
static void addperm(Perm_T ps) {
        ASSERT(ps);

        Perm_T p;
        NEW(p);
        p->action = ps->action;
        p->test_changes = ps->test_changes;
        if (p->test_changes) {
                if (! File_exist(current->path))
                        DEBUG("The path '%s' used in the PERMISSION statement refer to a non-existing object\n", current->path);
                else if ((p->perm = File_mod(current->path)) < 0)
                        yyerror2("Cannot get the timestamp for '%s'", current->path);
                else
                        p->perm &= 07777;
        } else {
                p->perm = ps->perm;
        }
        current->perm = p;
        reset_permset();
}


static void addlinkstatus(Service_T s, LinkStatus_T L) {
        ASSERT(L);
        
        LinkStatus_T l;
        NEW(l);
        l->action = L->action;
        
        l->next = s->linkstatuslist;
        s->linkstatuslist = l;
        
        reset_linkstatusset();
}


static void addlinkspeed(Service_T s, LinkSpeed_T L) {
        ASSERT(L);
        
        LinkSpeed_T l;
        NEW(l);
        l->action = L->action;
        
        l->next = s->linkspeedlist;
        s->linkspeedlist = l;
        
        reset_linkspeedset();
}


static void addlinksaturation(Service_T s, LinkSaturation_T L) {
        ASSERT(L);
        
        LinkSaturation_T l;
        NEW(l);
        l->operator = L->operator;
        l->limit = L->limit;
        l->action = L->action;
        
        l->next = s->linksaturationlist;
        s->linksaturationlist = l;
        
        reset_linksaturationset();
}


/*
 * Return Bandwidth object
 */
static void addbandwidth(Bandwidth_T *list, Bandwidth_T b) {
        ASSERT(list);
        ASSERT(b);

        if (b->rangecount * b->range > 24 * Time_Hour) {
                yyerror2("Maximum range for total test is 24 hours");
        } else if (b->range == Time_Minute && b->rangecount > 60) {
                yyerror2("Maximum value for [minute(s)] unit is 60");
        } else if (b->range == Time_Hour && b->rangecount > 24) {
                yyerror2("Maximum value for [hour(s)] unit is 24");
        } else if (b->range == Time_Day && b->rangecount > 1) {
                yyerror2("Maximum value for [day(s)] unit is 1");
        } else {
                if (b->range == Time_Day) {
                        // translate last day -> last 24 hours
                        b->rangecount = 24;
                        b->range = Time_Hour;
                }
                Bandwidth_T bandwidth;
                NEW(bandwidth);
                bandwidth->operator = b->operator;
                bandwidth->limit = b->limit;
                bandwidth->rangecount = b->rangecount;
                bandwidth->range = b->range;
                bandwidth->action = b->action;
                bandwidth->next = *list;
                *list = bandwidth;
        }
        reset_bandwidthset();
}


static void appendmatch(Match_T *list, Match_T item) {
        if (*list) {
                /* Find the end of the list (keep the same patterns order as in the config file) */
                Match_T last;
                for (last = *list; last->next; last = last->next)
                        ;
                last->next = item;
        } else {
                *list = item;
        }
}


/*
 * Set Match object in the current service
 */
static void addmatch(Match_T ms, int actionnumber, int linenumber) {
        Match_T m;
        int     reg_return;

        ASSERT(ms);

        NEW(m);
#ifdef HAVE_REGEX_H
        NEW(m->regex_comp);
#endif

        m->match_string = ms->match_string;
        m->match_path   = ms->match_path ? Str_dup(ms->match_path) : NULL;
        m->action       = ms->action;
        m->not          = ms->not;
        m->ignore       = ms->ignore;
        m->next         = NULL;

        addeventaction(&(m->action), actionnumber, Action_Ignored);

#ifdef HAVE_REGEX_H
        reg_return = regcomp(m->regex_comp, ms->match_string, REG_NOSUB|REG_EXTENDED);

        if (reg_return != 0) {
                char errbuf[STRLEN];
                regerror(reg_return, ms->regex_comp, errbuf, STRLEN);
                if (m->match_path != NULL)
                        yyerror2("Regex parsing error: %s on line %i of", errbuf, linenumber);
                else
                        yyerror2("Regex parsing error: %s", errbuf);
        }
#endif
        appendmatch(m->ignore ? &current->matchignorelist : &current->matchlist, m);
}


static void addmatchpath(Match_T ms, Action_Type actionnumber) {

        FILE *handle;
        command_t savecommand = NULL;
        char buf[2048];
        int linenumber = 0;

        ASSERT(ms->match_path);

        handle = fopen(ms->match_path, "r");
        if (handle == NULL) {
                yyerror2("Cannot read regex match file (%s)", ms->match_path);
                return;
        }

        while (! feof(handle)) {
                size_t len;

                linenumber++;

                if (! fgets(buf, 2048, handle))
                        continue;

                len = strlen(buf);

                if (len == 0 || buf[0] == '\n')
                        continue;

                if (buf[len-1] == '\n')
                        buf[len-1] = 0;

                ms->match_string = Str_dup(buf);

                /* The addeventaction() called from addmatch() will reset the
                 * command1 to NULL, but we need to duplicate the command for
                 * each line, thus need to save it here */
                if (actionnumber == Action_Exec) {
                        if (command1 == NULL) {
                                ASSERT(savecommand);
                                command1 = savecommand;
                        }
                        savecommand = copycommand(command1);
                }
                
                addmatch(ms, actionnumber, linenumber);
        }
        
        if (actionnumber == Action_Exec && savecommand)
                gccmd(&savecommand);
        
        fclose(handle);
}


/*
 * Set exit status test object in the current service
 */
static void addstatus(Status_T status) {
        Status_T s;
        ASSERT(status);
        NEW(s);
        s->initialized = status->initialized;
        s->return_value = status->return_value;
        s->operator = status->operator;
        s->action = status->action;
        s->next = current->statuslist;
        current->statuslist = s;

        reset_statusset();
}


/*
 * Set Uid object in the current service
 */
static Uid_T adduid(Uid_T u) {
        ASSERT(u);

        Uid_T uid;
        NEW(uid);
        uid->uid = u->uid;
        uid->action = u->action;
        reset_uidset();
        return uid;
}


/*
 * Set Gid object in the current service
 */
static Gid_T addgid(Gid_T g) {
        ASSERT(g);

        Gid_T gid;
        NEW(gid);
        gid->gid = g->gid;
        gid->action = g->action;
        reset_gidset();
        return gid;
}


/*
 * Add a new filesystem to the current service's filesystem list
 */
static void addfilesystem(Filesystem_T ds) {
        Filesystem_T dev;

        ASSERT(ds);

        NEW(dev);
        dev->resource           = ds->resource;
        dev->operator           = ds->operator;
        dev->limit_absolute     = ds->limit_absolute;
        dev->limit_percent      = ds->limit_percent;
        dev->action             = ds->action;

        dev->next               = current->filesystemlist;
        current->filesystemlist = dev;
        
        reset_filesystemset();

}


/*
 * Add a new icmp object to the current service's icmp list
 */
static void addicmp(Icmp_T is) {
        Icmp_T icmp;

        ASSERT(is);

        NEW(icmp);
        icmp->family       = is->family;
        icmp->type         = is->type;
        icmp->size         = is->size;
        icmp->count        = is->count;
        icmp->timeout      = is->timeout;
        icmp->action       = is->action;
        icmp->is_available = false;
        icmp->response     = -1;

        icmp->next         = current->icmplist;
        current->icmplist  = icmp;

        reset_icmpset();
}


/*
 * Set EventAction object
 */
static void addeventaction(EventAction_T *_ea, Action_Type failed, Action_Type succeeded) {
        EventAction_T ea;

        ASSERT(_ea);

        NEW(ea);
        NEW(ea->failed);
        NEW(ea->succeeded);

        ea->failed->id     = failed;
        ea->failed->count  = rate1.count;
        ea->failed->cycles = rate1.cycles;
        if (failed == Action_Exec) {
                ASSERT(command1);
                ea->failed->exec = command1;
                command1 = NULL;
        }

        ea->succeeded->id     = succeeded;
        ea->succeeded->count  = rate2.count;
        ea->succeeded->cycles = rate2.cycles;
        if (succeeded == Action_Exec) {
                ASSERT(command2);
                ea->succeeded->exec = command2;
                command2 = NULL;
        }
        *_ea = ea;
        reset_rateset();
}


/*
 * Add a generic protocol handler to
 */
static void addgeneric(Port_T port, char *send, char *expect) {
        Generic_T g = port->parameters.generic.sendexpect;
        if (! g) {
                NEW(g);
                port->parameters.generic.sendexpect = g;
        } else {
                while (g->next)
                        g = g->next;
                NEW(g->next);
                g = g->next;
        }
        if (send) {
                g->send = send;
                g->expect = NULL;
        } else if (expect) {
#ifdef HAVE_REGEX_H
                int reg_return;
                NEW(g->expect);
                reg_return = regcomp(g->expect, expect, REG_NOSUB|REG_EXTENDED);
                FREE(expect);
                if (reg_return != 0) {
                        char errbuf[STRLEN];
                        regerror(reg_return, g->expect, errbuf, STRLEN);
                        yyerror2("Regex parsing error: %s", errbuf);
                }
#else
                g->expect = expect;
#endif
                g->send = NULL;
        }
}


/*
 * Add the current command object to the current service object's
 * start or stop program.
 */
static void addcommand(int what, unsigned timeout) {

        switch (what) {
                case START:   current->start = command; break;
                case STOP:    current->stop = command; break;
                case RESTART: current->restart = command; break;
        }

        command->timeout = timeout;
        
        command = NULL;

}


/*
 * Add a new argument to the argument list
 */
static void addargument(char *argument) {

        ASSERT(argument);

        if (! command) {

                NEW(command);
                check_exec(argument);

        }

        command->arg[command->length++] = argument;
        command->arg[command->length] = NULL;

        if (command->length >= ARGMAX)
                yyerror("Exceeded maximum number of program arguments");

}


/*
 * Setup a url request for the current port object
 */
static void prepare_urlrequest(URL_T U) {

        ASSERT(U);

        /* Only the HTTP protocol is supported for URLs currently. See also the lexer if this is to be changed in the future */
        portset.protocol = Protocol_get(Protocol_HTTP);

        if (urlrequest == NULL)
                NEW(urlrequest);
        urlrequest->url = U;
        portset.hostname = Str_dup(U->hostname);
        portset.target.net.port = U->port;
        portset.url_request = urlrequest;
        portset.type = Socket_Tcp;
        portset.parameters.http.request = Str_cat("%s%s%s", U->path, U->query ? "?" : "", U->query ? U->query : "");
        if (IS(U->protocol, "https"))
                sslset.use_ssl = true;
}


/*
 * Set the url request for a port
 */
static void  seturlrequest(int operator, char *regex) {

        ASSERT(regex);

        if (! urlrequest)
                NEW(urlrequest);
        urlrequest->operator = operator;
        #ifdef HAVE_REGEX_H
        {
                int reg_return;
                NEW(urlrequest->regex);
                reg_return = regcomp(urlrequest->regex, regex, REG_NOSUB|REG_EXTENDED);
                if (reg_return != 0) {
                        char errbuf[STRLEN];
                        regerror(reg_return, urlrequest->regex, errbuf, STRLEN);
                        yyerror2("Regex parsing error: %s", errbuf);
                }
        }
        #else
        urlrequest->regex = Str_dup(regex);
        #endif

}


/*
 * Add a new data recipient server to the mmonit server list
 */
static void addmmonit(Mmonit_T mmonit) {
        ASSERT(mmonit->url);

        Mmonit_T c;
        NEW(c);
        c->url = mmonit->url;
        c->ssl.use_ssl = sslset.use_ssl;
        c->ssl.verify = sslset.verify;
        c->ssl.allowSelfSigned = sslset.allowSelfSigned;
        c->ssl.minimumValidDays = sslset.minimumValidDays;
        c->ssl.version = sslset.version;
        c->ssl.checksumType = sslset.checksumType;
        c->ssl.checksum = sslset.checksum;
        c->ssl.clientpemfile = sslset.clientpemfile;
        c->ssl.CACertificateFile = sslset.CACertificateFile;
        c->ssl.CACertificatePath = sslset.CACertificatePath;
        if (IS(c->url->protocol, "https")) {
#ifdef HAVE_OPENSSL
                c->ssl.use_ssl = true;
#else
                yyerror("SSL check cannot be activated -- SSL disabled");
#endif
        }
        c->timeout = mmonit->timeout;
        c->next = NULL;

        if (Run.mmonits) {
                Mmonit_T C;
                for (C = Run.mmonits; C->next; C = C->next)
                        /* Empty */ ;
                C->next = c;
        } else {
                Run.mmonits = c;
        }
        reset_sslset();
        reset_mmonitset();
}


/*
 * Add a new smtp server to the mail server list
 */
static void addmailserver(MailServer_T mailserver) {

        MailServer_T s;

        ASSERT(mailserver->host);

        NEW(s);
        s->host        = mailserver->host;
        s->port        = mailserver->port;
        s->username    = mailserver->username;
        s->password    = mailserver->password;

        s->ssl.use_ssl = sslset.use_ssl;
        s->ssl.verify = sslset.verify;
        s->ssl.allowSelfSigned = sslset.allowSelfSigned;
        s->ssl.minimumValidDays = sslset.minimumValidDays;
        s->ssl.version = sslset.version;
        s->ssl.checksumType = sslset.checksumType;
        s->ssl.checksum = sslset.checksum;
        s->ssl.clientpemfile = sslset.clientpemfile;
        s->ssl.CACertificateFile = sslset.CACertificateFile;
        s->ssl.CACertificatePath = sslset.CACertificatePath;
        reset_sslset();

        s->next = NULL;

        if (Run.mailservers) {
                MailServer_T l;
                for (l = Run.mailservers; l->next; l = l->next)
                        /* empty */;
                l->next = s;
        } else {
                Run.mailservers = s;
        }
        reset_mailserverset();
}


/*
 * Return uid if found on the system. If the parameter user is NULL
 * the uid parameter is used for looking up the user id on the system,
 * otherwise the user parameter is used.
 */
static uid_t get_uid(char *user, uid_t uid) {
        struct passwd *pwd;

        if (user) {
                pwd = getpwnam(user);

                if (! pwd) {
                        yyerror2("Requested user not found on the system");
                        return(0);
                }

        } else {

                if (! (pwd = getpwuid(uid))) {
                        yyerror2("Requested uid not found on the system");
                        return(0);
                }
        }

        return(pwd->pw_uid);

}


/*
 * Return gid if found on the system. If the parameter group is NULL
 * the gid parameter is used for looking up the group id on the system,
 * otherwise the group parameter is used.
 */
static gid_t get_gid(char *group, gid_t gid) {
        struct group *grd;

        if (group) {
                grd = getgrnam(group);

                if (! grd) {
                        yyerror2("Requested group not found on the system");
                        return(0);
                }

        } else {

                if (! (grd = getgrgid(gid))) {
                        yyerror2("Requested gid not found on the system");
                        return(0);
                }

        }

        return(grd->gr_gid);

}


/*
 * Add a new user id to the current command object.
 */
static void addeuid(uid_t uid) {
        if (! getuid()) {
                command->has_uid = true;
                command->uid = uid;
        } else {
                yyerror("UID statement requires root privileges");
        }
}


/*
 * Add a new group id to the current command object.
 */
static void addegid(gid_t gid) {
        if (! getuid()) {
                command->has_gid = true;
                command->gid = gid;
        } else {
                yyerror("GID statement requires root privileges");
        }
}


/*
 * Reset the logfile if changed
 */
static void setlogfile(char *logfile) {
        if (Run.files.log) {
                if (IS(Run.files.log, logfile)) {
                        FREE(logfile);
                        return;
                } else {
                        FREE(Run.files.log);
                }
        }
        Run.files.log = logfile;
}


/*
 * Reset the pidfile if changed
 */
static void setpidfile(char *pidfile) {
        if (Run.files.pid) {
                if (IS(Run.files.pid, pidfile)) {
                        FREE(pidfile);
                        return;
                } else {
                        FREE(Run.files.pid);
                }
        }
        Run.files.pid = pidfile;
}


/*
 * Read a apache htpasswd file and add credentials found for username
 */
static void addhtpasswdentry(char *filename, char *username, Digest_Type dtype) {
        char *ht_username = NULL;
        char *ht_passwd = NULL;
        char buf[STRLEN];
        FILE *handle = NULL;
        int credentials_added = 0;

        ASSERT(filename);

        handle = fopen(filename, "r");

        if ( handle == NULL ) {
                if (username != NULL)
                        yyerror2("Cannot read htpasswd (%s)", filename);
                else
                        yyerror2("Cannot read htpasswd", filename);
                return;
        }

        while (! feof(handle)) {
                char *colonindex = NULL;

                if (! fgets(buf, STRLEN, handle))
                        continue;

                Str_rtrim(buf);
                Str_curtail(buf, "#");

                if ( NULL == (colonindex = strchr(buf, ':')))
                continue;

                ht_passwd = Str_dup(colonindex+1);
                *colonindex = '\0';

                /* In case we have a file in /etc/passwd or /etc/shadow style we
                 *  want to remove ":.*$" and Crypt and MD5 hashed dont have a colon
                 */

                if ( (NULL != (colonindex = strchr(ht_passwd, ':'))) && ( dtype != Digest_Cleartext) )
                *colonindex = '\0';

                ht_username = Str_dup(buf);

                if (username == NULL) {
                        if (addcredentials(ht_username, ht_passwd, dtype, false))
                                credentials_added++;
                } else if (Str_cmp(username, ht_username) == 0)  {
                        if (addcredentials(ht_username, ht_passwd, dtype, false))
                                credentials_added++;
                } else {
                        FREE(ht_passwd);
                        FREE(ht_username);
                }
        }

        if (credentials_added == 0) {
                if ( username == NULL )
                        yywarning2("htpasswd file (%s) has no usable credentials", filename);
                else
                        yywarning2("htpasswd file (%s) has no usable credentials for user %s", filename, username);
        }
        fclose(handle);
}


#ifdef HAVE_LIBPAM
static void addpamauth(char* groupname, int readonly) {
        Auth_T prev = NULL;

        ASSERT(groupname);

        if (! Run.httpd.credentials)
                NEW(Run.httpd.credentials);

        Auth_T c = Run.httpd.credentials;
        do {
                if (c->groupname != NULL && IS(c->groupname, groupname)) {
                        yywarning2("PAM group %s was added already, entry ignored", groupname);
                        FREE(groupname);
                        return;
                }
                prev = c;
                c = c->next;
        } while (c != NULL);

        NEW(prev->next);
        c = prev->next;

        c->next        = NULL;
        c->uname       = NULL;
        c->passwd      = NULL;
        c->groupname   = groupname;
        c->digesttype  = Digest_Pam;
        c->is_readonly = readonly;

        DEBUG("Adding PAM group '%s'\n", groupname);

        return;
}
#endif


/*
 * Add Basic Authentication credentials
 */
static boolean_t addcredentials(char *uname, char *passwd, Digest_Type dtype, boolean_t readonly) {
        Auth_T c;

        ASSERT(uname);
        ASSERT(passwd);

        if (! Run.httpd.credentials) {
                NEW(Run.httpd.credentials);
                c = Run.httpd.credentials;
        } else {

                if (Util_getUserCredentials(uname) != NULL) {
                        yywarning2("Credentials for user %s were already added, entry ignored", uname);
                        FREE(uname);
                        FREE(passwd);
                        return false;
                }

                c = Run.httpd.credentials;

                while (c->next != NULL)
                        c = c->next;

                NEW(c->next);
                c = c->next;

        }

        c->next        = NULL;
        c->uname       = uname;
        c->passwd      = passwd;
        c->groupname   = NULL;
        c->digesttype  = dtype;
        c->is_readonly = readonly;

        DEBUG("Adding credentials for user '%s'\n", uname);

        return true;

}


/*
 * Set the syslog and the facilities to be used
 */
static void setsyslog(char *facility) {

        if (! Run.files.log || ihp.logfile) {
                ihp.logfile = true;
                setlogfile(Str_dup("syslog"));
                Run.flags |= Run_UseSyslog;
                Run.flags |= Run_Log;
        }

        if (facility) {
                if (IS(facility,"log_local0"))
                        Run.facility = LOG_LOCAL0;
                else if (IS(facility, "log_local1"))
                        Run.facility = LOG_LOCAL1;
                else if (IS(facility, "log_local2"))
                        Run.facility = LOG_LOCAL2;
                else if (IS(facility, "log_local3"))
                        Run.facility = LOG_LOCAL3;
                else if (IS(facility, "log_local4"))
                        Run.facility = LOG_LOCAL4;
                else if (IS(facility, "log_local5"))
                        Run.facility = LOG_LOCAL5;
                else if (IS(facility, "log_local6"))
                        Run.facility = LOG_LOCAL6;
                else if (IS(facility, "log_local7"))
                        Run.facility = LOG_LOCAL7;
                else if (IS(facility, "log_daemon"))
                        Run.facility = LOG_DAEMON;
                else
                        yyerror2("Invalid syslog facility");
        } else {
                Run.facility = LOG_USER;
        }

}


/*
 * Reset the current sslset for reuse
 */
static void reset_sslset() {
        memset(&sslset, 0, sizeof(struct SslOptions_T));
        sslset.version = sslset.verify = sslset.allowSelfSigned = sslset.minimumValidDays = -1;
}


/*
 * Reset the current mailset for reuse
 */
static void reset_mailset() {
        memset(&mailset, 0, sizeof(struct mymail));
}


/*
 * Reset the mailserver set to default values
 */
static void reset_mailserverset() {
        memset(&mailserverset, 0, sizeof(struct mymailserver));
        mailserverset.port = PORT_SMTP;
}


/*
 * Reset the mmonit set to default values
 */
static void reset_mmonitset() {
        memset(&mmonitset, 0, sizeof(struct mymmonit));
        mmonitset.timeout = NET_TIMEOUT;
}


/*
 * Reset the Port set to default values
 */
static void reset_portset() {
        memset(&portset, 0, sizeof(struct myport));
        portset.socket = -1;
        portset.type = Socket_Tcp;
        portset.family = Socket_Ip;
        portset.timeout = NET_TIMEOUT;
        portset.retry = 1;
        portset.protocol = Protocol_get(Protocol_DEFAULT);
        urlrequest = NULL;
}


/*
 * Reset the Proc set to default values
 */
static void reset_resourceset() {
        resourceset.resource_id = 0;
        resourceset.limit = 0;
        resourceset.action = NULL;
        resourceset.operator = Operator_Equal;
}


/*
 * Reset the Timestamp set to default values
 */
static void reset_timestampset() {
        timestampset.operator = Operator_Equal;
        timestampset.time = 0;
        timestampset.test_changes = false;
        timestampset.action = NULL;
}


/*
 * Reset the ActionRate set to default values
 */
static void reset_actionrateset() {
        actionrateset.count = 0;
        actionrateset.cycle = 0;
        actionrateset.action = NULL;
}


/*
 * Reset the Size set to default values
 */
static void reset_sizeset() {
        sizeset.operator = Operator_Equal;
        sizeset.size = 0;
        sizeset.test_changes = false;
        sizeset.action = NULL;
}


/*
 * Reset the Uptime set to default values
 */
static void reset_uptimeset() {
        uptimeset.operator = Operator_Equal;
        uptimeset.uptime = 0;
        uptimeset.action = NULL;
}


static void reset_linkstatusset() {
        linkstatusset.action = NULL;
}


static void reset_linkspeedset() {
        linkspeedset.action = NULL;
}


static void reset_linksaturationset() {
        linksaturationset.limit = 0.;
        linksaturationset.operator = Operator_Equal;
        linksaturationset.action = NULL;
}


/*
 * Reset the Bandwidth set to default values
 */
static void reset_bandwidthset() {
        bandwidthset.operator = Operator_Equal;
        bandwidthset.limit = 0ULL;
        bandwidthset.action = NULL;
}


/*
 * Reset the Pid set to default values
 */
static void reset_pidset() {
        pidset.action = NULL;
}


/*
 * Reset the PPid set to default values
 */
static void reset_ppidset() {
        ppidset.action = NULL;
}


/*
 * Reset the Fsflag set to default values
 */
static void reset_fsflagset() {
        fsflagset.action = NULL;
}


/*
 * Reset the Nonexist set to default values
 */
static void reset_nonexistset() {
        nonexistset.action = NULL;
}


/*
 * Reset the Checksum set to default values
 */
static void reset_checksumset() {
        checksumset.type         = Hash_Unknown;
        checksumset.test_changes = false;
        checksumset.action       = NULL;
        *checksumset.hash        = 0;
}


/*
 * Reset the Perm set to default values
 */
static void reset_permset() {
        permset.test_changes = false;
        permset.perm = 0;
        permset.action = NULL;
}


/*
 * Reset the Status set to default values
 */
static void reset_statusset() {
        statusset.initialized = false;
        statusset.return_value = 0;
        statusset.operator = Operator_Equal;
        statusset.action = NULL;
}


/*
 * Reset the Uid set to default values
 */
static void reset_uidset() {
        uidset.uid = 0;
        uidset.action = NULL;
}


/*
 * Reset the Gid set to default values
 */
static void reset_gidset() {
        gidset.gid = 0;
        gidset.action = NULL;
}


/*
 * Reset the Filesystem set to default values
 */
static void reset_filesystemset() {
        filesystemset.resource = 0;
        filesystemset.operator = Operator_Equal;
        filesystemset.limit_absolute = -1;
        filesystemset.limit_percent = -1;
        filesystemset.action = NULL;
}


/*
 * Reset the ICMP set to default values
 */
static void reset_icmpset() {
        icmpset.type = ICMP_ECHO;
        icmpset.size = ICMP_SIZE;
        icmpset.count = ICMP_ATTEMPT_COUNT;
        icmpset.timeout = NET_TIMEOUT;
        icmpset.action = NULL;
}


/*
 * Reset the Rate set to default values
 */
static void reset_rateset() {
        rate1.count  = 1;
        rate1.cycles = 1;

        rate2.count  = 1;
        rate2.cycles = 1;
}


/* ---------------------------------------------------------------- Checkers */


/*
 * Check for unique service name
 */
static void check_name(char *name) {
        ASSERT(name);

        if (Util_existService(name) || (current && IS(name, current->name)))
                yyerror2("Service name conflict, %s already defined", name);
        if (name && *name == '/')
                yyerror2("Service name '%s' must not start with '/' -- ", name);
}


/*
 * Permission statement semantic check
 */
static int check_perm(int perm) {
        int result;
        char *status;
        char buf[STRLEN];

        snprintf(buf, STRLEN, "%d", perm);

        result = (int)strtol(buf, &status, 8);

        if (*status != '\0' || result < 0 || result > 07777)
                yyerror2("Permission statements must have an octal value between 0 and 7777");

        return result;
}


/*
 * Check the dependency graph for errors
 * by doing a topological sort, thereby finding any cycles.
 * Assures that graph is a Directed Acyclic Graph (DAG).
 */
static void check_depend() {
        Service_T s;
        Service_T depends_on = NULL;
        Service_T* dlt = &depend_list; /* the current tail of it                                 */
        boolean_t done;                /* no unvisited nodes left?                               */
        boolean_t found_some;          /* last iteration found anything new ?                    */
        depend_list = NULL;            /* depend_list will be the topological sorted servicelist */

        do {
                done = true;
                found_some = false;
                for (s = servicelist; s; s = s->next) {
                        Dependant_T d;
                        if (s->visited)
                                continue;
                        done = false; // still unvisited nodes
                        depends_on = NULL;
                        for (d = s->dependantlist; d; d = d->next) {
                                Service_T dp = Util_getService(d->dependant);
                                if (! dp) {
                                        LogError("Depend service '%s' is not defined in the control file\n", d->dependant);
                                        exit(1);
                                }
                                if (! dp->visited) {
                                        depends_on = dp;
                                }
                        }

                        if (! depends_on) {
                                s->visited = true;
                                found_some = true;
                                *dlt = s;
                                dlt = &s->next_depend;
                        }
                }
        } while (found_some && ! done);

        if (! done) {
                ASSERT(depends_on);
                LogError("Found a depend loop in the control file involving the service '%s'\n", depends_on->name);
                exit(1);
        }

        ASSERT(depend_list);
        servicelist = depend_list;

        for (s = depend_list; s; s = s->next_depend)
                s->next = s->next_depend;
}


/*
 * Check if the executable exist
 */
static void check_exec(char *exec) {
        if (! File_exist(exec))
                yywarning2("Program does not exist:");
        else if (! File_isExecutable(exec))
                yywarning2("Program is not executable:");
}


/* Return a valid max forward value for SIP header */
static int verifyMaxForward(int mf) {
        if (mf >= 0 && mf <= 255)
                return mf;
        yywarning2("SIP max forward is outside the range [0..255]. Setting max forward to 70");
        return 70;
}


/* -------------------------------------------------------------------- Misc */


/*
 * Cleans up a hash string, tolower and remove byte separators
 */
static int cleanup_hash_string(char *hashstring) {
        int i = 0, j = 0;

        ASSERT(hashstring);

        while (hashstring[i]) {
                if (isxdigit((int)hashstring[i])) {
                        hashstring[j] = tolower((int)hashstring[i]);
                        j++;
                }
                i++;
        }
        hashstring[j] = 0;
        return j;
}


/* Return deep copy of the command */
static command_t copycommand(command_t source) {
        int i;
        command_t copy = NULL;

        NEW(copy);
        copy->length = source->length;
        copy->has_uid = source->has_uid;
        copy->uid = source->uid;
        copy->has_gid = source->has_gid;
        copy->gid = source->gid;
        copy->timeout = source->timeout;
        for (i = 0; i < copy->length; i++)
        copy->arg[i] = Str_dup(source->arg[i]);
        copy->arg[copy->length] = NULL;

        return copy;
}

