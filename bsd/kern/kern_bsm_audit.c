 * Copyright (c) 2003 Apple Computer, Inc. All rights reserved.
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
#include <sys/vnode.h>
#include <sys/audit.h>
#include <sys/kern_audit.h>
#include <sys/bsm_token.h>
#include <sys/bsm_kevents.h>
#include <sys/bsm_klib.h>
	bsm_audit_mutex = mutex_alloc(ETAP_NO_TRACE);
		kmem_alloc(kernel_map, &rec, sizeof(*rec));
		kmem_alloc(kernel_map, &rec->data, 
			   MAX_AUDIT_RECORD_SIZE * sizeof(u_char));
			kmem_free(kernel_map, rec, sizeof(*rec));
int kau_close(struct au_record *rec, struct timespec *ctime, short event)
		kmem_free(kernel_map, tok->t_data, tok->len);
		kmem_free(kernel_map, tok, sizeof(struct au_token));
#define KPATH1_VNODE1_TOKENS	\
			fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
			tok = au_to_attr32(&vattr);		\
#define KPATH1_VNODE1_OR_UPATH1_TOKENS	\
		} else {					\
			UPATH1_TOKENS;				\
			fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
			tok = au_to_attr32(&vattr);		\
			fill_vattr(&vattr, &ar->ar_arg_vnode2);	\
			tok = au_to_attr32(&vattr);		\
				fill_vattr(&vattr, &ar->ar_arg_vnode1);	\
				tok = au_to_attr32(&vattr);		\
	struct vattr vattr;
	int sorf;
	/*
	 * Decide whether to create the BSM audit record by checking the
	 * error value from the system call and using the appropriate
	 * user audit mask. 
	 */
	if (ar->ar_errno) 
		sorf = AU_PRS_FAILURE;
	else
		sorf = AU_PRS_SUCCESS;

	if (au_preselect(ar->ar_event, &ar->ar_subj_amask, sorf) == 0)
		return (BSM_NOAUDIT);

		tok = au_to_arg32(1,"domain", ar->ar_arg_sockinfo.sodomain);
		tok = au_to_arg32(2,"type", ar->ar_arg_sockinfo.sotype);
		tok = au_to_arg32(3,"protocol", ar->ar_arg_sockinfo.soprotocol);
		/* fall through */
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
/*
 * XXXAUDIT: Close is not audited in the kernel yet. 
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
*/
		if (ar->ar_arg_cmd == F_GETLK || ar->ar_arg_cmd == F_SETLK ||
			ar->ar_arg_cmd == F_SETLKW) {
			tok = au_to_arg32(2, "cmd", ar->ar_arg_cmd);
			kau_write(rec, tok);
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
		if (ar->ar_arg_text != NULL) {
	case AUE_UMOUNT:
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
	case AUE_OPEN_R:
	case AUE_OPEN_RWC:
	case AUE_OPEN_RWTC:
	case AUE_OPEN_WC:
	case AUE_OPEN_WTC:
		/* The open syscall always writes a OPEN_R event; convert the
		 * file flags to the proper type of event.
		 */
		ar->ar_event = flags_to_openevent(ar->ar_arg_fflags);
		UPATH1_TOKENS;		/* Save the user space path */
		KPATH1_VNODE1_TOKENS;	/* Audit the kernel path as well */
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
				tok = au_to_arg32(1, "setgroups", 							ar->ar_arg_groups.gidset[ctr]);
		KPATH1_VNODE1_OR_UPATH1_TOKENS;
bsm_rec_verify(caddr_t rec)
	if ( ((char)*rec != AU_HEADER_32_TOKEN) && 
		((char)*rec != AU_HEADER_EX_32_TOKEN) && 
		((char)*rec != AU_HEADER_64_TOKEN) && 
		((char)*rec != AU_HEADER_EX_64_TOKEN) ) {