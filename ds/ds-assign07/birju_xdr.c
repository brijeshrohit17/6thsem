/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "birju.h"

bool_t
xdr_input (XDR *xdrs, input *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->choice))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str1, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str2, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, (3 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->year))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->num1);
			IXDR_PUT_LONG(buf, objp->num2);
			IXDR_PUT_LONG(buf, objp->year);
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->choice))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str1, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str2, 50,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, (3 +  100 )* BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->year))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			objp->num1 = IXDR_GET_LONG(buf);
			objp->num2 = IXDR_GET_LONG(buf);
			objp->year = IXDR_GET_LONG(buf);
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->choice))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->str1, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->str2, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->year))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_output (XDR *xdrs, output *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->flag))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->gcd))
			 return FALSE;
		 if (!xdr_float (xdrs, &objp->sqrt))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->min))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->num1);
		IXDR_PUT_LONG(buf, objp->num2);
		IXDR_PUT_LONG(buf, objp->max);
		IXDR_PUT_LONG(buf, objp->min);
		}
		 if (!xdr_float (xdrs, &objp->avg))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str, 100,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 100; ++i) {
					IXDR_PUT_LONG(buf, *genp++);
				}
			}
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->flag))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->gcd))
			 return FALSE;
		 if (!xdr_float (xdrs, &objp->sqrt))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->num1))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->num2))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->max))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->min))
				 return FALSE;

		} else {
		objp->num1 = IXDR_GET_LONG(buf);
		objp->num2 = IXDR_GET_LONG(buf);
		objp->max = IXDR_GET_LONG(buf);
		objp->min = IXDR_GET_LONG(buf);
		}
		 if (!xdr_float (xdrs, &objp->avg))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->str, 100,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( 100 ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
		} else {
			{
				register int *genp;

				for (i = 0, genp = objp->arr;
					i < 100; ++i) {
					*genp++ = IXDR_GET_LONG(buf);
				}
			}
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->flag))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->gcd))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->sqrt))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num2))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->max))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->min))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->avg))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->str, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->arr, 100,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	return TRUE;
}