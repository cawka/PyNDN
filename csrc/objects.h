/*
 * Copyright (c) 2011, Regents of the University of California
 * BSD license, See the COPYING file for more information
 * Written by: Derek Kulinski <takeda@takeda.tk>
 *             Jeff Burke <jburke@ucla.edu>
 */

#ifndef OBJECTS_H
#  define	OBJECTS_H

#  if 0

struct completed_closure {
	PyObject *closure;
	struct completed_closure *next;
};
#  endif

enum _ndn_capsules {
	CLOSURE = 1,
	CONTENT_OBJECT,
	EXCLUSION_FILTER,
	HANDLE,
	INTEREST,
	KEY_LOCATOR,
	NAME,
	PKEY_PRIV,
	PKEY_PUB,
	SIGNATURE,
	SIGNED_INFO,
	SIGNING_PARAMS,
#  ifdef NAMECRYPTO
	NAMECRYPTO_STATE,
#  endif
};

struct content_object_data {
	struct ccn_parsed_Data *pco;
	struct ccn_indexbuf *comps;
};

struct interest_data {
	struct ccn_parsed_interest *pi;
};

PyObject *CCNObject_New(enum _ndn_capsules type, void *pointer);
PyObject *CCNObject_Borrow(enum _ndn_capsules type, void *pointer);
int CCNObject_ReqType(enum _ndn_capsules type, PyObject *capsule);
int CCNObject_IsValid(enum _ndn_capsules type, PyObject *capsule);
void *CCNObject_Get(enum _ndn_capsules type, PyObject *capsule);

PyObject *CCNObject_New_Closure(struct ccn_closure **closure);
PyObject *CCNObject_New_charbuf(enum _ndn_capsules type,
		struct ccn_charbuf **p);

#endif	/* OBJECTS_H */
