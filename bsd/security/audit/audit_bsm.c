 * Copyright (c) 1999-2020 Apple Inc.  All rights reserved.
static void     audit_sys_auditon(struct audit_record *ar,
    struct au_record *rec);
static void     audit_sys_fcntl(struct kaudit_record *kar,
    struct au_record *rec);
	return rec;
	if (hdrsize != AUDIT_HEADER_SIZE) {
	} else {
	}
#define MAC_VNODE1_LABEL_TOKEN   do {                                     \
	if (ar->ar_vnode1_mac_labels != NULL &&                           \
	    strlen(ar->ar_vnode1_mac_labels) != 0) {                      \
	        tok = au_to_text(ar->ar_vnode1_mac_labels);               \
	        kau_write(rec, tok);                                      \
	}                                                                 \
#define MAC_VNODE2_LABEL_TOKEN  do {                                      \
	if (ar->ar_vnode2_mac_labels != NULL &&                           \
	    strlen(ar->ar_vnode2_mac_labels) != 0) {                      \
	        tok = au_to_text(ar->ar_vnode2_mac_labels);               \
	        kau_write(rec, tok);                                      \
	}                                                                 \
#define MAC_VNODE1_LABEL_TOKEN
#define MAC_VNODE2_LABEL_TOKEN
#define UPATH1_TOKENS do {                                              \
	if (ARG_IS_VALID(kar, ARG_UPATH1)) {                            \
	        tok = au_to_path(ar->ar_arg_upath1);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
} while (0)

#define UPATH2_TOKENS do {                                              \
	if (ARG_IS_VALID(kar, ARG_UPATH2)) {                            \
	        tok = au_to_path(ar->ar_arg_upath2);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
#define KPATH2_TOKENS do {                                              \
	if (ARG_IS_VALID(kar, ARG_KPATH2)) {                            \
	        tok = au_to_path(ar->ar_arg_kpath2);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
#define VNODE1_TOKENS do {                                              \
	if (ARG_IS_VALID(kar, ARG_KPATH1)) {                            \
	        tok = au_to_path(ar->ar_arg_kpath1);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
	if (ARG_IS_VALID(kar, ARG_VNODE1)) {                            \
	        tok = au_to_attr32(&ar->ar_arg_vnode1);                 \
	        kau_write(rec, tok);                                    \
	        MAC_VNODE1_LABEL_TOKEN;                                 \
	}                                                               \
#define UPATH1_VNODE1_TOKENS do {                                       \
	if (ARG_IS_VALID(kar, ARG_UPATH1)) {                            \
	        tok = au_to_path(ar->ar_arg_upath1);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
	if (ARG_IS_VALID(kar, ARG_KPATH1)) {                            \
	        tok = au_to_path(ar->ar_arg_kpath1);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
	if (ARG_IS_VALID(kar, ARG_VNODE1)) {                            \
	        tok = au_to_attr32(&ar->ar_arg_vnode1);                 \
	        kau_write(rec, tok);                                    \
	        MAC_VNODE1_LABEL_TOKEN;                                 \
	}                                                               \
#define VNODE2_TOKENS do {                                              \
	if (ARG_IS_VALID(kar, ARG_VNODE2)) {                            \
	        tok = au_to_attr32(&ar->ar_arg_vnode2);                 \
	        kau_write(rec, tok);                                    \
	        MAC_VNODE2_LABEL_TOKEN;                                 \
	}                                                               \
#define VNODE2_PATH_TOKENS do {                                 \
	if (ARG_IS_VALID(kar, ARG_KPATH2)) {                            \
	        tok = au_to_path(ar->ar_arg_kpath2);                    \
	        kau_write(rec, tok);                                    \
	}                                                               \
	if (ARG_IS_VALID(kar, ARG_VNODE2)) {                            \
	        tok = au_to_attr32(&ar->ar_arg_vnode2);                 \
	        kau_write(rec, tok);                                    \
	        MAC_VNODE2_LABEL_TOKEN;                                 \
	}                                                               \
#define FD_VNODE1_TOKENS do {                                           \
	if (ARG_IS_VALID(kar, ARG_VNODE1)) {                            \
	        if (ARG_IS_VALID(kar, ARG_KPATH1)) {                    \
	                tok = au_to_path(ar->ar_arg_kpath1);            \
	                kau_write(rec, tok);                            \
	        }                                                       \
	        if (ARG_IS_VALID(kar, ARG_FD)) {                        \
	                tok = au_to_arg32(1, "fd", ar->ar_arg_fd);      \
	                kau_write(rec, tok);                            \
	                MAC_VNODE1_LABEL_TOKEN;                         \
	        }                                                       \
	        tok = au_to_attr32(&ar->ar_arg_vnode1);                 \
	        kau_write(rec, tok);                                    \
	} else {                                                        \
	        if (ARG_IS_VALID(kar, ARG_FD)) {                        \
	                tok = au_to_arg32(1, "fd",                      \
	                    ar->ar_arg_fd);                             \
	                kau_write(rec, tok);                            \
	                MAC_VNODE1_LABEL_TOKEN;                         \
	        }                                                       \
	}                                                               \
#define PROCESS_PID_TOKENS(argn) do {                                   \
	if ((ar->ar_arg_pid > 0) /* Reference a single process */       \
	    && (ARG_IS_VALID(kar, ARG_PROCESS))) {                      \
	        tok = au_to_process32_ex(ar->ar_arg_auid,               \
	            ar->ar_arg_euid, ar->ar_arg_egid,                   \
	            ar->ar_arg_ruid, ar->ar_arg_rgid,                   \
	            ar->ar_arg_pid, ar->ar_arg_asid,                    \
	            &ar->ar_arg_termid_addr);                           \
	        kau_write(rec, tok);                                    \
	} else if (ARG_IS_VALID(kar, ARG_PID)) {                        \
	        tok = au_to_arg32(argn, "process", ar->ar_arg_pid);     \
	        kau_write(rec, tok);                                    \
	}                                                               \
#define EXTATTR_TOKENS do {                                             \
	if (ARG_IS_VALID(kar, ARG_VALUE32)) {                           \
	        switch (ar->ar_arg_value32) {                           \
	        case EXTATTR_NAMESPACE_USER:                            \
	                tok = au_to_text(EXTATTR_NAMESPACE_USER_STRING);\
	                break;                                          \
	        case EXTATTR_NAMESPACE_SYSTEM:                          \
	                tok = au_to_text(EXTATTR_NAMESPACE_SYSTEM_STRING);\
	                break;                                          \
	        default:                                                \
	                tok = au_to_arg32(3, "attrnamespace",           \
	                    ar->ar_arg_value32);                        \
	                break;                                          \
	        }                                                       \
	        kau_write(rec, tok);                                    \
	}                                                               \
	/* attrname is in the text field */                             \
	if (ARG_IS_VALID(kar, ARG_TEXT)) {                              \
	        tok = au_to_text(ar->ar_arg_text);                      \
	        kau_write(rec, tok);                                    \
	}                                                               \
#define EXTENDED_TOKENS(n) do {                                         \
	/* ACL data */                                          \
	        if (ARG_IS_VALID(kar, ARG_OPAQUE)) {                    \
	                tok = au_to_opaque(ar->ar_arg_opaque,           \
	                    ar->ar_arg_opq_size);                       \
	                kau_write(rec, tok);                            \
	        }                                                       \
	        if (ARG_IS_VALID(kar, ARG_MODE)) {                      \
	                tok = au_to_arg32(n+2, "mode", ar->ar_arg_mode);\
	                kau_write(rec, tok);                            \
	        }                                                       \
	        if (ARG_IS_VALID(kar, ARG_GID)) {                       \
	                tok = au_to_arg32(n+1, "gid", ar->ar_arg_gid);  \
	                kau_write(rec, tok);                            \
	        }                                                       \
	        if (ARG_IS_VALID(kar, ARG_UID)) {                       \
	                tok = au_to_arg32(n, "uid", ar->ar_arg_uid);    \
	                kau_write(rec, tok);                            \
	        }                                                       \
} while (0)

#define PROCESS_MAC_TOKENS do {                                         \
	if (ar->ar_valid_arg & ARG_MAC_STRING) {                        \
	        tok = au_to_text(ar->ar_arg_mac_string);                \
	        kau_write(rec, tok);                                    \
	}                                                               \
		OS_FALLTHROUGH;
		OS_FALLTHROUGH;
		OS_FALLTHROUGH;
#ifdef  F_SETSIZE
#ifdef  F_PATHPKG_CHECK
		    ar->ar_subj_egid,   /* eff group id */
		    ar->ar_subj_ruid,   /* real uid */
		    ar->ar_subj_rgid,   /* real group id */
		    ar->ar_subj_pid,    /* process id */
		    ar->ar_subj_asid,   /* session ID */
	switch (ar->ar_event) {
		OS_FALLTHROUGH;
			    &ar->ar_arg_sockaddr);
			tok = au_to_arg32(1, "domain",
			tok = au_to_arg32(2, "type",
			tok = au_to_arg32(3, "protocol",
			switch (ar->ar_arg_termid_addr.at_type) {
			case AU_IPv6:
				kau_write(rec, tok);
				break;
			case AU_IPv4:
				kau_write(rec, tok);
				break;
			}
		OS_FALLTHROUGH;
		if (ARG_IS_VALID(kar, ARG_AUDITON)) {
		}
#if 0
		OS_FALLTHROUGH;
		VNODE2_PATH_TOKENS;
		if (ARG_IS_VALID(kar, ARG_DATA)) {
			tok = au_to_data(AUP_HEX, ar->ar_arg_data_type,
			    ar->ar_arg_data_count, ar->ar_arg_data);
			kau_write(rec, tok);
		}
	 */
	case AUE_FSTAT:         /* XXX Need to handle sockets and shm */
	case AUE_PREADV:
	case AUE_PWRITEV:
		if (ARG_IS_VALID(kar, ARG_CMD)) {
		}
		if (ARG_IS_VALID(kar, ARG_VNODE1)) {
		} else {
					ar->ar_arg_sockinfo.sai_domain,
					ar->ar_arg_sockinfo.sai_type,
					(struct sockaddr *)
					&ar->ar_arg_sockinfo.sai_laddr,
					(struct sockaddr *)
					&ar->ar_arg_sockinfo.sai_faddr);
		KPATH2_TOKENS;
		if (ar->ar_event == AUE_MMAP) {
		}
		OS_FALLTHROUGH;
		OS_FALLTHROUGH;
	case AUE_FMOUNT:
		if (ARG_IS_VALID(kar, ARG_FD)) {
			tok = au_to_arg32(2, "dir fd", ar->ar_arg_fd);
			kau_write(rec, tok);
		}
		if (ARG_IS_VALID(kar, ARG_FFLAGS)) {
			tok = au_to_arg32(3, "flags", ar->ar_arg_fflags);
			kau_write(rec, tok);
		}
		if (ARG_IS_VALID(kar, ARG_TEXT)) {
			tok = au_to_text(ar->ar_arg_text);
			kau_write(rec, tok);
		}
		break;
		OS_FALLTHROUGH;
	case AUE_SETATTRLISTAT:
	case AUE_CLONEFILEAT:
		if (ARG_IS_VALID(kar, ARG_FD)) {
			tok = au_to_arg32(1, "src dir fd", ar->ar_arg_fd);
			kau_write(rec, tok);
		}
		UPATH1_VNODE1_TOKENS;
		if (ARG_IS_VALID(kar, ARG_FD2)) {
			tok = au_to_arg32(1, "dst dir fd", ar->ar_arg_fd2);
			kau_write(rec, tok);
		}
		UPATH2_TOKENS;
		if (ARG_IS_VALID(kar, ARG_VALUE32)) {
			tok = au_to_arg32(1, "flags", ar->ar_arg_value32);
			kau_write(rec, tok);
		}
		break;

	case AUE_FCLONEFILEAT:
		FD_VNODE1_TOKENS;
		if (ARG_IS_VALID(kar, ARG_FD2)) {
			tok = au_to_arg32(1, "dst dir fd", ar->ar_arg_fd2);
			kau_write(rec, tok);
		}
		UPATH2_TOKENS;
		if (ARG_IS_VALID(kar, ARG_VALUE32)) {
			tok = au_to_arg32(1, "flags", ar->ar_arg_value32);
			kau_write(rec, tok);
		}
		break;

		OS_FALLTHROUGH;
			break;  /* We will audit a bad command */
		OS_FALLTHROUGH;
		OS_FALLTHROUGH;
		OS_FALLTHROUGH;
	case AUE_FSGETPATH_EXTENDED:
	* Mach system calls    *
	************************/
		return BSM_NOAUDIT;
				tok = au_to_data(AUP_BINARY, AUR_BYTE,
				    mar->length,
				    (const char *)mar->data);
				break;
			case MAC_AUDIT_TEXT_TYPE:
				tok = au_to_text((char*) mar->data);
				break;
			default:
				/*
				 * XXX: we can either continue,
				 * skipping this particular entry,
				 * or we can pre-verify the list and
				 * abort before writing any records
				 */
				printf("kaudit_to_bsm(): "
				    "BSM conversion requested for"
				    "unknown mac_audit data type %d\n",
				    mar->type);
	if (ARG_IS_VALID(kar, ARG_IDENTITY)) {
		struct au_identity_info *id = &ar->ar_arg_identity;
		tok = au_to_identity(id->signer_type, id->signing_id,
		    id->signing_id_trunc, id->team_id, id->team_id_trunc,
		    id->cdhash, id->cdhash_len);
		kau_write(rec, tok);
	}

	return BSM_SUCCESS;
 * Verify that a record is a valid BSM record. Return 1 if the
bsm_rec_verify(void *rec, int length, boolean_t kern_events_allowed)
	/* Used to partially deserialize the buffer */
	struct hdr_tok_partial *hdr;
	struct trl_tok_partial *trl;
	/* A record requires a complete header and trailer token */
	if (length < (AUDIT_HEADER_SIZE + AUDIT_TRAILER_SIZE)) {
		return 0;
	}

	hdr = (struct hdr_tok_partial*)rec;

	/* Ensure the provided length matches what the record shows */
	if ((uint32_t)length != ntohl(hdr->len)) {
		return 0;
	}

	trl = (struct trl_tok_partial*)(rec + (length - AUDIT_TRAILER_SIZE));

	/* Ensure the buffer contains what look like header and trailer tokens */
	if (((hdr->type != AUT_HEADER32) && (hdr->type != AUT_HEADER32_EX) &&
	    (hdr->type != AUT_HEADER64) && (hdr->type != AUT_HEADER64_EX)) ||
	    (trl->type != AUT_TRAILER)) {
		return 0;
	}

	/* Ensure the header and trailer agree on the length */
	if (hdr->len != trl->len) {
		return 0;
	}

	/* Ensure the trailer token has a proper magic value */
	if (ntohs(trl->magic) != AUT_TRAILER_MAGIC) {
		return 0;
	}

	if (!kern_events_allowed && AUE_IS_A_KEVENT(ntohs(hdr->e_type))) {
		return 0;
	}

	return 1;