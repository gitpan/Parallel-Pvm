/*
 * This file was generated automatically by xsubpp version 1.933 from the 
 * contents of Pvm.xs. Don't edit this file, edit Pvm.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#ifdef __cplusplus
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifdef __cplusplus
}
#endif

/* MY EXTENSION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "pvm3.h"
 
#define MAXPROCS	100
#define MAXHOSTS	100
#define MAXSTR		100000

#define STRING          1
#define INTEGER         2
#define DOUBLE          3
 
static char g_buffer[MAXSTR];
static SV *recvf_callback = (SV *)NULL;
static int (*olmatch)();

static int
recvf_foo( int bufid, int tid, int tag )
{
dSP ;
int count;
int compare_val;

ENTER ;
SAVETMPS ;

PUSHMARK(sp) ;
XPUSHs(sv_2mortal(newSViv(bufid)));
XPUSHs(sv_2mortal(newSViv(tid)));
XPUSHs(sv_2mortal(newSViv(tag)));
PUTBACK ;

count = perl_call_sv(recvf_callback,G_SCALAR);

SPAGAIN ;

if ( count != 1 )
   croak("pvm_recvf: comparison function must return only one scalar\n");

compare_val = POPi;

PUTBACK ;
FREETMPS ;
LEAVE ;

return compare_val;

}


static HV *
derefHV( SV *node )
{
HV *hv_tmp;
 
if ( SvROK(node) ){
   if ( SvTYPE(SvRV(node)) == SVt_PVHV ){
      hv_tmp = (HV *)SvRV(node);
      return hv_tmp;
   }
}
return 0;
}

static int
string_byte_cnt( char *str )
{
int cnt=0;

   while( str[cnt] != '\0' ){
      cnt++;
   }
   /* add 1 for the byte holding the '\0' */
   return cnt+1;
}

static int
string_type( char *str )
{
int i=0;
int could_be_double=0;
int must_be_double=0;
 
    while ( str[i] != '\0' ){
        /* */
        if ( ! isdigit(str[i]) ){
             if ( str[i] == '.' && could_be_double == 0 ){
                could_be_double = 1;
             }else{
                return STRING;
             }
        }
        /* else{
             if ( could_be_double ){
                if ( str[i] != '0' ){
                   must_be_double = 1;
                }
             }
        } */
        i++;
    }
    if ( could_be_double ) return DOUBLE;
    return INTEGER;
}

static char *
buffer_string( char *str, int new_flag )
{
static int cnt;
int i;
 
   if ( new_flag ){
      cnt=0;
      for (i=0;str[i] && cnt<MAXSTR-1;i++) g_buffer[cnt++] = str[i];
      if (cnt == MAXSTR-1) croak("Warning: message truncated. Try increasing MAXSTR");
      g_buffer[cnt] = '\0';
   }else{
      /* use vertical tab as token separator */
      g_buffer[cnt++] = '\v';
      for (i=0;str[i] && cnt<MAXSTR-1;i++) g_buffer[cnt++] = str[i];
      if (cnt == MAXSTR-1) croak("Warning: message truncated. Try increasing MAXSTR");
      g_buffer[cnt] = '\0';
   }
   return g_buffer;
}

/*****/

static int
not_here(s)
char *s;
{
    croak("%s not implemented on this architecture", s);
    return -1;
}

static double
constant(name, arg)
char *name;
int arg;
{
    errno = 0;
    switch (*name) {
    case 'A':
	break;
    case 'B':
	break;
    case 'C':
	break;
    case 'D':
	break;
    case 'E':
	break;
    case 'F':
	break;
    case 'G':
	break;
    case 'H':
	break;
    case 'I':
	break;
    case 'J':
	break;
    case 'K':
	break;
    case 'L':
	break;
    case 'M':
	break;
    case 'N':
	break;
    case 'O':
	break;
    case 'P':
	if (strEQ(name, "PVM_BYTE"))
#ifdef PVM_BYTE
	    return PVM_BYTE;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_CPLX"))
#ifdef PVM_CPLX
	    return PVM_CPLX;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_DCPLX"))
#ifdef PVM_DCPLX
	    return PVM_DCPLX;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_DOUBLE"))
#ifdef PVM_DOUBLE
	    return PVM_DOUBLE;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_FLOAT"))
#ifdef PVM_FLOAT
	    return PVM_FLOAT;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_INT"))
#ifdef PVM_INT
	    return PVM_INT;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_LONG"))
#ifdef PVM_LONG
	    return PVM_LONG;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_SHORT"))
#ifdef PVM_SHORT
	    return PVM_SHORT;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_STR"))
#ifdef PVM_STR
	    return PVM_STR;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_UINT"))
#ifdef PVM_UINT
	    return PVM_UINT;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_ULONG"))
#ifdef PVM_ULONG
	    return PVM_ULONG;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PVM_USHORT"))
#ifdef PVM_USHORT
	    return PVM_USHORT;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmAllowDirect"))
#ifdef PvmAllowDirect
	    return PvmAllowDirect;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmAlready"))
#ifdef PvmAlready
	    return PvmAlready;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmAutoErr"))
#ifdef PvmAutoErr
	    return PvmAutoErr;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmBadMsg"))
#ifdef PvmBadMsg
	    return PvmBadMsg;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmBadParam"))
#ifdef PvmBadParam
	    return PvmBadParam;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmBadVersion"))
#ifdef PvmBadVersion
	    return PvmBadVersion;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmCantStart"))
#ifdef PvmCantStart
	    return PvmCantStart;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDSysErr"))
#ifdef PvmDSysErr
	    return PvmDSysErr;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDataDefault"))
#ifdef PvmDataDefault
	    return PvmDataDefault;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDataFoo"))
#ifdef PvmDataFoo
	    return PvmDataFoo;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDataInPlace"))
#ifdef PvmDataInPlace
	    return PvmDataInPlace;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDataRaw"))
#ifdef PvmDataRaw
	    return PvmDataRaw;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDebugMask"))
#ifdef PvmDebugMask
	    return PvmDebugMask;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDontRoute"))
#ifdef PvmDontRoute
	    return PvmDontRoute;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDupEntry"))
#ifdef PvmDupEntry
	    return PvmDupEntry;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDupGroup"))
#ifdef PvmDupGroup
	    return PvmDupGroup;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmDupHost"))
#ifdef PvmDupHost
	    return PvmDupHost;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmFragSize"))
#ifdef PvmFragSize
	    return PvmFragSize;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmHostAdd"))
#ifdef PvmHostAdd
	    return PvmHostAdd;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmHostCompl"))
#ifdef PvmHostCompl
	    return PvmHostCompl;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmHostDelete"))
#ifdef PvmHostDelete
	    return PvmHostDelete;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmHostFail"))
#ifdef PvmHostFail
	    return PvmHostFail;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmMismatch"))
#ifdef PvmMismatch
	    return PvmMismatch;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmMppFront"))
#ifdef PvmMppFront
	    return PvmMppFront;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoBuf"))
#ifdef PvmNoBuf
	    return PvmNoBuf;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoData"))
#ifdef PvmNoData
	    return PvmNoData;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoEntry"))
#ifdef PvmNoEntry
	    return PvmNoEntry;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoFile"))
#ifdef PvmNoFile
	    return PvmNoFile;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoGroup"))
#ifdef PvmNoGroup
	    return PvmNoGroup;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoHost"))
#ifdef PvmNoHost
	    return PvmNoHost;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoInst"))
#ifdef PvmNoInst
	    return PvmNoInst;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoMem"))
#ifdef PvmNoMem
	    return PvmNoMem;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoParent"))
#ifdef PvmNoParent
	    return PvmNoParent;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoSuchBuf"))
#ifdef PvmNoSuchBuf
	    return PvmNoSuchBuf;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNoTask"))
#ifdef PvmNoTask
	    return PvmNoTask;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNotImpl"))
#ifdef PvmNotImpl
	    return PvmNotImpl;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNotInGroup"))
#ifdef PvmNotInGroup
	    return PvmNotInGroup;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmNullGroup"))
#ifdef PvmNullGroup
	    return PvmNullGroup;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmOk"))
#ifdef PvmOk
	    return PvmOk;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmOutOfRes"))
#ifdef PvmOutOfRes
	    return PvmOutOfRes;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmOutputCode"))
#ifdef PvmOutputCode
	    return PvmOutputCode;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmOutputTid"))
#ifdef PvmOutputTid
	    return PvmOutputTid;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmOverflow"))
#ifdef PvmOverflow
	    return PvmOverflow;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmPollConstant"))
#ifdef PvmPollConstant
	    return PvmPollConstant;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmPollSleep"))
#ifdef PvmPollSleep
	    return PvmPollSleep;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmPollTime"))
#ifdef PvmPollTime
	    return PvmPollTime;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmPollType"))
#ifdef PvmPollType
	    return PvmPollType;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmResvTids"))
#ifdef PvmResvTids
	    return PvmResvTids;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmRoute"))
#ifdef PvmRoute
	    return PvmRoute;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmRouteDirect"))
#ifdef PvmRouteDirect
	    return PvmRouteDirect;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmSelfOutputCode"))
#ifdef PvmSelfOutputCode
	    return PvmSelfOutputCode;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmSelfOutputTid"))
#ifdef PvmSelfOutputTid
	    return PvmSelfOutputTid;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmSelfTraceCode"))
#ifdef PvmSelfTraceCode
	    return PvmSelfTraceCode;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmSelfTraceTid"))
#ifdef PvmSelfTraceTid
	    return PvmSelfTraceTid;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmShowTids"))
#ifdef PvmShowTids
	    return PvmShowTids;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmSysErr"))
#ifdef PvmSysErr
	    return PvmSysErr;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskArch"))
#ifdef PvmTaskArch
	    return PvmTaskArch;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskChild"))
#ifdef PvmTaskChild
	    return PvmTaskChild;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskDebug"))
#ifdef PvmTaskDebug
	    return PvmTaskDebug;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskDefault"))
#ifdef PvmTaskDefault
	    return PvmTaskDefault;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskExit"))
#ifdef PvmTaskExit
	    return PvmTaskExit;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskHost"))
#ifdef PvmTaskHost
	    return PvmTaskHost;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskSelf"))
#ifdef PvmTaskSelf
	    return PvmTaskSelf;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTaskTrace"))
#ifdef PvmTaskTrace
	    return PvmTaskTrace;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTraceCode"))
#ifdef PvmTraceCode
	    return PvmTraceCode;
#else
	    goto not_there;
#endif
	if (strEQ(name, "PvmTraceTid"))
#ifdef PvmTraceTid
	    return PvmTraceTid;
#else
	    goto not_there;
#endif
	break;
    case 'Q':
	break;
    case 'R':
	break;
    case 'S':
	break;
    case 'T':
	break;
    case 'U':
	break;
    case 'V':
	break;
    case 'W':
	break;
    case 'X':
	break;
    case 'Y':
	break;
    case 'Z':
	break;
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}


XS(XS_Parallel__Pvm_constant)
{
    dXSARGS;
    if (items != 2)
	croak("Usage: Parallel::Pvm::constant(name,arg)");
    {
	char *	name = (char *)SvPV(ST(0),na);
	int	arg = (int)SvIV(ST(1));
	double	RETVAL;

	RETVAL = constant(name, arg);
	ST(0) = sv_newmortal();
	sv_setnv(ST(0), (double)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_spawn)
{
    dXSARGS;
    if (items < 2 || items > 5)
	croak("Usage: Parallel::Pvm::spawn(task,ntask,flag=PvmTaskDefault,where=\"\",argvRef=0)");
    SP -= items;
    {
	char *	task = (char *)SvPV(ST(0),na);
	int	ntask = (int)SvIV(ST(1));
	int	flag;
	char *	where;
	SV *	argvRef;
	int tids[MAXPROCS];
	int info;
	int i;
	char ** argv = (char **)0;

	if (items < 3)
	    flag = PvmTaskDefault;
	else {
	    flag = (int)SvIV(ST(2));
	}

	if (items < 4)
	    where = "";
	else {
	    where = (char *)SvPV(ST(3),na);
	}

	if (items < 5)
	    argvRef = 0;
	else {
	    argvRef = ST(4);
	}
	if (argvRef)
	{
	    int   argc;
	    AV *  av;
	    SV ** a;

	    if (!SvROK(argvRef))
	        croak("Parallel::Pvm::spawn - non-reference passed for argv");

	    av = (AV *) SvRV( argvRef );
	    argc = av_len( av ) + 1;        /* number of elts in vector */
	    Newz( 0, argv, argc+1, char *); /* last one will be NULL */

	    for (i = 0; i < argc; i++)
	    {
	       if ( a = av_fetch( av, i, 0) )
	          argv[i] = (char *) SvPV( *a, na );
	    }
	}

	info = pvm_spawn(task,argv,flag,where,ntask,tids);

	Safefree( argv ); /* no harm done if argv is NULL */

	XPUSHs(sv_2mortal(newSViv(info)));
	for (i=0;i<info;i++){
	   XPUSHs(sv_2mortal(newSViv(tids[i])));
	}
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_initsend)
{
    dXSARGS;
    if (items < 0 || items > 1)
	croak("Usage: Parallel::Pvm::initsend(flag=PvmDataDefault)");
    {
	int	flag;
	int	RETVAL;

	if (items < 1)
	    flag = PvmDataDefault;
	else {
	    flag = (int)SvIV(ST(0));
	}
	RETVAL = pvm_initsend(flag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_send)
{
    dXSARGS;
    if (items != 2)
	croak("Usage: Parallel::Pvm::send(tid,tag)");
    {
	int	tid = (int)SvIV(ST(0));
	int	tag = (int)SvIV(ST(1));
	int	RETVAL;
	RETVAL = pvm_send(tid,tag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_psend)
{
    dXSARGS;
    if (items < 2)
	croak("Usage: Parallel::Pvm::psend(tid,tag,...)");
    {
	int	tid = (int)SvIV(ST(0));
	int	tag = (int)SvIV(ST(1));
	int i;
	char *str, *po;
	int	RETVAL;
	if ( items == 2 )
	   croak("Usage: Parallel::Pvm::pack(@argv)");
	for(i=2;i<items;i++){
	    po = (char *)SvPV(ST(i),na);
            if ( i == 2 ) {
               str = buffer_string(po,1);
            } else{
               str = buffer_string(po,0);
            }
	}
	RETVAL = pvm_psend(tid,tag,str,string_byte_cnt(str),PVM_BYTE);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_mcast)
{
    dXSARGS;
    {
	int i;
	int tag_num;
	int proc_num;
	int tids[MAXPROCS];
	int tag;
	int	RETVAL;
	if ( items < 2 )
	   croak("Usage: Parallel::Pvm::pvm_mcast(tids_list,tag)");
	for (i=0;i<items-1;i++){
	  tids[i] = SvIV(ST(i));
	}
	proc_num = tag_num = items-1;
	tag = SvIV(ST(tag_num));
	RETVAL = pvm_mcast(tids,proc_num,tag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_sendsig)
{
    dXSARGS;
    if (items != 2)
	croak("Usage: Parallel::Pvm::sendsig(tid,sig)");
    {
	int	tid = (int)SvIV(ST(0));
	int	sig = (int)SvIV(ST(1));
	int	RETVAL;
	RETVAL = pvm_sendsig(tid,sig);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_probe)
{
    dXSARGS;
    if (items < 0 || items > 2)
	croak("Usage: Parallel::Pvm::probe(tid=-1,tag=-1)");
    {
	int	tid;
	int	tag;
	int	RETVAL;

	if (items < 1)
	    tid = -1;
	else {
	    tid = (int)SvIV(ST(0));
	}

	if (items < 2)
	    tag = -1;
	else {
	    tag = (int)SvIV(ST(1));
	}
	RETVAL = pvm_probe(tid,tag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_recv)
{
    dXSARGS;
    if (items < 0 || items > 2)
	croak("Usage: Parallel::Pvm::recv(tid=-1,tag=-1)");
    {
	int	tid;
	int	tag;
	int	RETVAL;

	if (items < 1)
	    tid = -1;
	else {
	    tid = (int)SvIV(ST(0));
	}

	if (items < 2)
	    tag = -1;
	else {
	    tag = (int)SvIV(ST(1));
	}
	RETVAL = pvm_recv(tid,tag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_nrecv)
{
    dXSARGS;
    if (items < 0 || items > 2)
	croak("Usage: Parallel::Pvm::nrecv(tid=-1,tag=-1)");
    {
	int	tid;
	int	tag;
	int	RETVAL;

	if (items < 1)
	    tid = -1;
	else {
	    tid = (int)SvIV(ST(0));
	}

	if (items < 2)
	    tag = -1;
	else {
	    tag = (int)SvIV(ST(1));
	}
	RETVAL = pvm_nrecv(tid,tag);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_trecv)
{
    dXSARGS;
    if (items < 0 || items > 4)
	croak("Usage: Parallel::Pvm::trecv(tid=-1,tag=-1,sec=1,usec=0)");
    {
	int	tid;
	int	tag;
	int	sec;
	int	usec;
	struct timeval tmout;
	int	RETVAL;

	if (items < 1)
	    tid = -1;
	else {
	    tid = (int)SvIV(ST(0));
	}

	if (items < 2)
	    tag = -1;
	else {
	    tag = (int)SvIV(ST(1));
	}

	if (items < 3)
	    sec = 1;
	else {
	    sec = (int)SvIV(ST(2));
	}

	if (items < 4)
	    usec = 0;
	else {
	    usec = (int)SvIV(ST(3));
	}
	tmout.tv_sec = sec;
	tmout.tv_usec = usec;
	RETVAL = pvm_trecv(tid,tag,&tmout);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_precv)
{
    dXSARGS;
    if (items < 0 || items > 2)
	croak("Usage: Parallel::Pvm::precv(tid=-1,tag=-1)");
    SP -= items;
    {
	int	tid;
	int	tag;
	int info, src, stag, scnt;
	char str[MAXSTR];
	char *po;
	int type;

	if (items < 1)
	    tid = -1;
	else {
	    tid = (int)SvIV(ST(0));
	}

	if (items < 2)
	    tag = -1;
	else {
	    tag = (int)SvIV(ST(1));
	}
	info = pvm_precv(tid,tag,str,MAXSTR,PVM_BYTE,&src,&stag,&scnt);
	XPUSHs(sv_2mortal(newSViv(info)));
	XPUSHs(sv_2mortal(newSViv(src)));
	XPUSHs(sv_2mortal(newSViv(stag)));
	po = strtok(str,"\v");
        while ( po != NULL ){
           type = string_type(po); 
           switch(type){
                case STRING:
                        XPUSHs(sv_2mortal(newSVpv(po,0)));
                        break;
                case INTEGER:
                        XPUSHs(sv_2mortal(newSViv(atoi(po))));
                        break;
                case DOUBLE:
                        XPUSHs(sv_2mortal(newSVnv(atof(po))));
                        break;
           }
	   po = strtok(NULL,"\v");
        }
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_parent)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::parent()");
    {
	int	RETVAL;
	RETVAL = pvm_parent();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_mytid)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::mytid()");
    {
	int	RETVAL;
	RETVAL = pvm_mytid();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_pack)
{
    dXSARGS;
    {
	int i;
	char *str, *po;
	int	RETVAL;
	if ( items <= 0 )
	   croak("Usage: Parallel::Pvm::pack(@argv)");
        for (i=0;i<items;i++){
	    po = (char *)SvPV(ST(i),na);
            if ( i == 0 ) {
              str = buffer_string(po,1);
            } else{
              str = buffer_string(po,0);
            }
	}
        RETVAL = pvm_pkstr(str); 
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_unpack)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::unpack()");
    SP -= items;
    {
	char str[MAXSTR], *po;
	int type;
	pvm_upkstr(str); 
	po = strtok(str,"\v");
        while ( po != NULL ){
           type = string_type(po); 
           switch(type){
                case STRING:
                        XPUSHs(sv_2mortal(newSVpv(po,0)));
                        break;
                case INTEGER:
                        XPUSHs(sv_2mortal(newSViv(atoi(po))));
                        break;
                case DOUBLE:
                        XPUSHs(sv_2mortal(newSVnv(atof(po))));
                        break;
           }
	   po = strtok(NULL,"\v");
        }
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_exit)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::exit()");
    {
	int	RETVAL;
	RETVAL = pvm_exit();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_halt)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::halt()");
    {
	int	RETVAL;
	RETVAL = pvm_halt();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_catchout)
{
    dXSARGS;
    if (items < 0 || items > 1)
	croak("Usage: Parallel::Pvm::catchout(io=stdout)");
    {
	FILE *	io;
	int	RETVAL;

	if (items < 1)
	    io = stdout;
	else {
	    io = IoIFP(sv_2io(ST(0)));
	}
	RETVAL = pvm_catchout(io);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_tasks)
{
    dXSARGS;
    if (items < 0 || items > 1)
	croak("Usage: Parallel::Pvm::tasks(where=0)");
    SP -= items;
    {
	int	where;
	int ntask,i,info;
	struct pvmtaskinfo *taskp;
	int ti_tid,ti_ptid,ti_host,ti_flag,ti_pid;
	char ti_a_out[256];
	HV *hv_tmp;

	if (items < 1)
	    where = 0;
	else {
	    where = (int)SvIV(ST(0));
	}
	info = pvm_tasks(where,&ntask,&taskp);
	XPUSHs(sv_2mortal(newSViv(info)));
	for(i=0;i<ntask;i++){
	   strcpy(ti_a_out,taskp[i].ti_a_out);
	   ti_tid = taskp[i].ti_tid;
	   ti_ptid = taskp[i].ti_ptid;
	   ti_pid = taskp[i].ti_pid;
	   ti_host = taskp[i].ti_host;
	   ti_flag = taskp[i].ti_flag;
	   /* set up hash entry */
	   hv_tmp = newHV();
	   /* sv_2mortal((SV *)hv_tmp); */
	   hv_store(hv_tmp,"ti_a_out",8,newSVpv(ti_a_out,0),0);
	   hv_store(hv_tmp,"ti_tid",6,newSViv(ti_tid),0);
	   hv_store(hv_tmp,"ti_ptid",7,newSViv(ti_ptid),0);
	   hv_store(hv_tmp,"ti_pid",6,newSViv(ti_pid),0);
	   hv_store(hv_tmp,"ti_host",7,newSViv(ti_host),0);
	   hv_store(hv_tmp,"ti_flag",7,newSViv(ti_flag),0);
	   /* create reference and stick in on the stack */
	   XPUSHs(sv_2mortal(newRV((SV *)hv_tmp)));
	}
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_config)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::config()");
    SP -= items;
    {
	int nhosts, narch, info;
	struct pvmhostinfo *hostp;
	char hi_name[256], hi_arch[256];
	int hi_tid, hi_speed;
	int i;
	HV *hv_tmp;
	info = pvm_config(&nhosts,&narch,&hostp);
	XPUSHs(sv_2mortal(newSViv(info)));
	for (i=0;i<nhosts;i++){
	   hi_tid = hostp[i].hi_tid;
	   strcpy(hi_name,hostp[i].hi_name);
	   strcpy(hi_arch,hostp[i].hi_arch);
	   hi_speed = hostp[i].hi_speed; 
	   /* set up hash entry */
	   hv_tmp = newHV();
	   /* sv_2mortal((SV *)hv_tmp); */
	   hv_store(hv_tmp,"hi_tid",6,newSViv(hi_tid),0);
	   hv_store(hv_tmp,"hi_name",7,newSVpv(hi_name,0),0);
	   hv_store(hv_tmp,"hi_arch",7,newSVpv(hi_arch,0),0);
	   hv_store(hv_tmp,"hi_speed",8,newSViv(hi_speed),0);
	   /* create reference and stick in on the stack */
	   XPUSHs(sv_2mortal(newRV((SV *)hv_tmp)));
	}
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_addhosts)
{
    dXSARGS;
    SP -= items;
    {
	int i;
	int info;
	char *po;
	char *hosts[MAXHOSTS]; 
	int infos[MAXHOSTS];
	if ( items < 1 )
	   croak("Usage: Parallel::Pvm::pvm_addhosts(host_list)");
        for (i=0;i<items;i++){
	   hosts[i] = (char *)SvPV(ST(i),na);
	}
	info = pvm_addhosts(hosts,items,infos);
        XPUSHs(sv_2mortal(newSViv(info)));	
        for (i=0;i<items;i++){
	    XPUSHs(sv_2mortal(newSViv(infos[i])));
	}
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_delhosts)
{
    dXSARGS;
    SP -= items;
    {
	char *po;
	char *hosts[MAXHOSTS]; 
	int infos[MAXHOSTS];
	int info, i, nhost;
	if ( items < 1 )
	   croak("Usage: Parallel::Pvm::pvm_delhosts(host_list)");
        for (i=0;i<items;i++){
	   hosts[i] = (char *)SvPV(ST(i),na);
	}
	info = pvm_delhosts(hosts,items,infos);
        XPUSHs(sv_2mortal(newSViv(info)));	
        for (i=0;i<items;i++){
	    XPUSHs(sv_2mortal(newSViv(infos[i])));
	}
	/*
        for (i=0;i<items;i++){
	    free(hosts[i]);
	}
	*/
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_bufinfo)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::bufinfo(bufid)");
    SP -= items;
    {
	int	bufid = (int)SvIV(ST(0));
	int bytes, tag, tid, info;
	info = pvm_bufinfo(bufid,&bytes,&tag,&tid);
	XPUSHs(sv_2mortal(newSViv(info)));
	XPUSHs(sv_2mortal(newSViv(bytes)));
	XPUSHs(sv_2mortal(newSViv(tag)));
	XPUSHs(sv_2mortal(newSViv(tid)));
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_freebuf)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::freebuf(bufid)");
    {
	int	bufid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_freebuf(bufid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_getrbuf)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::getrbuf()");
    {
	int	RETVAL;
	RETVAL = pvm_getrbuf();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_getsbuf)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::getsbuf()");
    {
	int	RETVAL;
	RETVAL = pvm_getsbuf();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_mkbuf)
{
    dXSARGS;
    if (items < 0 || items > 1)
	croak("Usage: Parallel::Pvm::mkbuf(encode=PvmDataDefault)");
    {
	int	encode;
	int	RETVAL;

	if (items < 1)
	    encode = PvmDataDefault;
	else {
	    encode = (int)SvIV(ST(0));
	}
	RETVAL = pvm_mkbuf(encode);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_setrbuf)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::setrbuf(bufid)");
    {
	int	bufid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_setrbuf(bufid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_setsbuf)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::setsbuf(bufid)");
    {
	int	bufid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_setsbuf(bufid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_kill)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::kill(tid)");
    {
	int	tid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_kill(tid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_mstat)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::mstat(host)");
    {
	char *	host = (char *)SvPV(ST(0),na);
	int	RETVAL;
	RETVAL = pvm_mstat(host);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_pstat)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::pstat(tid)");
    {
	int	tid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_pstat(tid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_tidtohost)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::tidtohost(tid)");
    {
	int	tid = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_tidtohost(tid);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_getopt)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::getopt(what)");
    {
	int	what = (int)SvIV(ST(0));
	int	RETVAL;
	RETVAL = pvm_getopt(what);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_setopt)
{
    dXSARGS;
    if (items != 2)
	croak("Usage: Parallel::Pvm::setopt(what,val)");
    {
	int	what = (int)SvIV(ST(0));
	int	val = (int)SvIV(ST(1));
	int	RETVAL;
	RETVAL = pvm_setopt(what,val);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_reg_hoster)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::reg_hoster()");
    {
	int	RETVAL;
	RETVAL = pvm_reg_hoster();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_reg_tasker)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::reg_tasker()");
    {
	int	RETVAL;
	RETVAL = pvm_reg_tasker();
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_reg_rm)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::reg_rm()");
    {
	struct pvmhostinfo *hip;
	int	RETVAL;
	RETVAL = pvm_reg_rm(&hip);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_perror)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::perror(msg)");
    {
	char *	msg = (char *)SvPV(ST(0),na);
	int	RETVAL;
	RETVAL = pvm_perror(msg);
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_notify)
{
    dXSARGS;
    if (items < 2)
	croak("Usage: Parallel::Pvm::notify(what,tag,...)");
    {
	int	what = (int)SvIV(ST(0));
	int	tag = (int)SvIV(ST(1));
	int i, cnt, tids[MAXPROCS];
	int	RETVAL;
	switch(what){
	   case PvmTaskExit:
	   case PvmHostDelete:
	        if ( items < 3 )
	           croak("Usage: Parallel::Pvm::pvm_notify(what,tag,tid_list");
	        for (i=2;i<items;i++){
	           tids[i-2] = SvIV(ST(i));
	        }
	        RETVAL = pvm_notify(what,tag,items-2,tids);
	        break;
	   case PvmHostAdd:
	        if ( items < 2 )
	          croak("Usage:  Parallel::Pvm::pvm_notify(PvmHostAdd,tag [,cnt]");
	        if (2 == items )
	        cnt = -1;
	        else
	           cnt = SvIV(ST(2));
	        RETVAL = pvm_notify(what,tag, cnt, (int *)0 );
	        break;
	}
	ST(0) = sv_newmortal();
	sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_recv_notify)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::recv_notify(what)");
    SP -= items;
    {
	int	what = (int)SvIV(ST(0));
	int id,i,cnt;
	int tids[MAXPROCS];
	int	RETVAL;
	pvm_recv(-1,-1);
	switch (what )
	{
	   case PvmTaskExit:
	   case PvmHostDelete:
	        pvm_upkint(&id,1,1);
	        XPUSHs( sv_2mortal(newSViv(id)) );
	        break;
	   case PvmHostAdd:
	        pvm_upkint( &cnt, 1, 1 );
	        pvm_upkint( tids, cnt, 1 );
	   for ( i=0; i < cnt; i++)
	       XPUSHs(sv_2mortal(newSViv(tids[i])));
	}
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_hostsync)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::hostsync(hst)");
    SP -= items;
    {
	int	hst = (int)SvIV(ST(0));
	struct timeval rclk, delta;
	int info;
	int sec, usec;
	HV *hv_tmp;
	info = pvm_hostsync(hst,&rclk,&delta);
	XPUSHs(sv_2mortal(newSViv(info)));
	sec = rclk.tv_sec;
	usec = rclk.tv_usec;
	/* set up hash entry */
	hv_tmp = newHV();
	hv_store(hv_tmp,"tv_sec",6,newSViv(sec),0);
	hv_store(hv_tmp,"hi_usec",7,newSViv(usec),0);
	/* create reference and stick in on the stack */
	XPUSHs(sv_2mortal(newRV((SV *)hv_tmp)));
	sec = delta.tv_sec;
	usec = delta.tv_usec;
	/* set up hash entry */
	hv_tmp = newHV();
	hv_store(hv_tmp,"tv_sec",6,newSViv(sec),0);
	hv_store(hv_tmp,"hi_usec",7,newSViv(usec),0);
	/* create reference and stick in on the stack */
	XPUSHs(sv_2mortal(newRV((SV *)hv_tmp)));
	PUTBACK;
	return;
    }
}

XS(XS_Parallel__Pvm_recvf)
{
    dXSARGS;
    if (items != 1)
	croak("Usage: Parallel::Pvm::recvf(fn)");
    {
	SV *	fn = ST(0);
	if ( recvf_callback == (SV *)NULL ){
	   recvf_callback = newSVsv(fn);
	}else{
	   sv_setsv(recvf_callback,fn);
	}
	olmatch = pvm_recvf(recvf_foo);
    }
    XSRETURN(1);
}

XS(XS_Parallel__Pvm_recvf_old)
{
    dXSARGS;
    if (items != 0)
	croak("Usage: Parallel::Pvm::recvf_old()");
    {
	if ( olmatch !=  NULL ){
	   pvm_recvf(olmatch);
	}
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Parallel__Pvm)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXS("Parallel::Pvm::constant", XS_Parallel__Pvm_constant, file);
        newXSproto("Parallel::Pvm::spawn", XS_Parallel__Pvm_spawn, file, "$$;$$$");
        newXSproto("Parallel::Pvm::initsend", XS_Parallel__Pvm_initsend, file, ";$");
        newXSproto("Parallel::Pvm::send", XS_Parallel__Pvm_send, file, "$$");
        newXSproto("Parallel::Pvm::psend", XS_Parallel__Pvm_psend, file, "$$;@");
        newXSproto("Parallel::Pvm::mcast", XS_Parallel__Pvm_mcast, file, "@");
        newXSproto("Parallel::Pvm::sendsig", XS_Parallel__Pvm_sendsig, file, "$$");
        newXSproto("Parallel::Pvm::probe", XS_Parallel__Pvm_probe, file, ";$$");
        newXSproto("Parallel::Pvm::recv", XS_Parallel__Pvm_recv, file, ";$$");
        newXSproto("Parallel::Pvm::nrecv", XS_Parallel__Pvm_nrecv, file, ";$$");
        newXSproto("Parallel::Pvm::trecv", XS_Parallel__Pvm_trecv, file, ";$$$$");
        newXSproto("Parallel::Pvm::precv", XS_Parallel__Pvm_precv, file, ";$$");
        newXSproto("Parallel::Pvm::parent", XS_Parallel__Pvm_parent, file, "");
        newXSproto("Parallel::Pvm::mytid", XS_Parallel__Pvm_mytid, file, "");
        newXSproto("Parallel::Pvm::pack", XS_Parallel__Pvm_pack, file, "@");
        newXSproto("Parallel::Pvm::unpack", XS_Parallel__Pvm_unpack, file, "");
        newXSproto("Parallel::Pvm::exit", XS_Parallel__Pvm_exit, file, "");
        newXSproto("Parallel::Pvm::halt", XS_Parallel__Pvm_halt, file, "");
        newXSproto("Parallel::Pvm::catchout", XS_Parallel__Pvm_catchout, file, ";$");
        newXSproto("Parallel::Pvm::tasks", XS_Parallel__Pvm_tasks, file, ";$");
        newXSproto("Parallel::Pvm::config", XS_Parallel__Pvm_config, file, "");
        newXSproto("Parallel::Pvm::addhosts", XS_Parallel__Pvm_addhosts, file, "@");
        newXSproto("Parallel::Pvm::delhosts", XS_Parallel__Pvm_delhosts, file, "@");
        newXSproto("Parallel::Pvm::bufinfo", XS_Parallel__Pvm_bufinfo, file, "$");
        newXSproto("Parallel::Pvm::freebuf", XS_Parallel__Pvm_freebuf, file, "$");
        newXSproto("Parallel::Pvm::getrbuf", XS_Parallel__Pvm_getrbuf, file, "");
        newXSproto("Parallel::Pvm::getsbuf", XS_Parallel__Pvm_getsbuf, file, "");
        newXSproto("Parallel::Pvm::mkbuf", XS_Parallel__Pvm_mkbuf, file, "$");
        newXSproto("Parallel::Pvm::setrbuf", XS_Parallel__Pvm_setrbuf, file, "$");
        newXSproto("Parallel::Pvm::setsbuf", XS_Parallel__Pvm_setsbuf, file, "$");
        newXSproto("Parallel::Pvm::kill", XS_Parallel__Pvm_kill, file, "$");
        newXSproto("Parallel::Pvm::mstat", XS_Parallel__Pvm_mstat, file, "$");
        newXSproto("Parallel::Pvm::pstat", XS_Parallel__Pvm_pstat, file, "$");
        newXSproto("Parallel::Pvm::tidtohost", XS_Parallel__Pvm_tidtohost, file, "$");
        newXSproto("Parallel::Pvm::getopt", XS_Parallel__Pvm_getopt, file, "$");
        newXSproto("Parallel::Pvm::setopt", XS_Parallel__Pvm_setopt, file, "$$");
        newXSproto("Parallel::Pvm::reg_hoster", XS_Parallel__Pvm_reg_hoster, file, "");
        newXSproto("Parallel::Pvm::reg_tasker", XS_Parallel__Pvm_reg_tasker, file, "");
        newXSproto("Parallel::Pvm::reg_rm", XS_Parallel__Pvm_reg_rm, file, "");
        newXSproto("Parallel::Pvm::perror", XS_Parallel__Pvm_perror, file, "$");
        newXSproto("Parallel::Pvm::notify", XS_Parallel__Pvm_notify, file, "$$;@");
        newXSproto("Parallel::Pvm::recv_notify", XS_Parallel__Pvm_recv_notify, file, "$");
        newXS("Parallel::Pvm::hostsync", XS_Parallel__Pvm_hostsync, file);
        newXSproto("Parallel::Pvm::recvf", XS_Parallel__Pvm_recvf, file, "$");
        newXSproto("Parallel::Pvm::recvf_old", XS_Parallel__Pvm_recvf_old, file, "");
    ST(0) = &sv_yes;
    XSRETURN(1);
}
