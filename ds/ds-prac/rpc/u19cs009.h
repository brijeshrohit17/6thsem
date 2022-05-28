/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _U19CS009_H_RPCGEN
#define _U19CS009_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct input {
	int num;
};
typedef struct input input;

struct output {
	char str[100];
};
typedef struct output output;

#define EXEC_PROG 0x2f2f2f2f
#define EXEC_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define exec 1
extern  output * exec_1(input *, CLIENT *);
extern  output * exec_1_svc(input *, struct svc_req *);
extern int exec_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define exec 1
extern  output * exec_1();
extern  output * exec_1_svc();
extern int exec_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_input (XDR *, input*);
extern  bool_t xdr_output (XDR *, output*);

#else /* K&R C */
extern bool_t xdr_input ();
extern bool_t xdr_output ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_U19CS009_H_RPCGEN */
