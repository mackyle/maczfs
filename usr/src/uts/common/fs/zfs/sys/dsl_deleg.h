/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_SYS_DSL_DELEG_H
#define	_SYS_DSL_DELEG_H

#pragma ident	"%Z%%M%	%I%	%E% SMI"

#include <sys/dmu.h>
#include <sys/dsl_pool.h>
#include <sys/zfs_context.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define	ZFS_DELEG_PERM_NONE		""
#define	ZFS_DELEG_PERM_CREATE		"create"
#define	ZFS_DELEG_PERM_DESTROY		"destroy"
#define	ZFS_DELEG_PERM_SNAPSHOT		"snapshot"
#define	ZFS_DELEG_PERM_ROLLBACK		"rollback"
#define	ZFS_DELEG_PERM_CLONE		"clone"
#define	ZFS_DELEG_PERM_PROMOTE		"promote"
#define	ZFS_DELEG_PERM_RENAME		"rename"
#define	ZFS_DELEG_PERM_MOUNT		"mount"
#define	ZFS_DELEG_PERM_SHARE		"share"
#define	ZFS_DELEG_PERM_SEND		"send"
#define	ZFS_DELEG_PERM_RECEIVE		"receive"
#define	ZFS_DELEG_PERM_ALLOW		"allow"
#define	ZFS_DELEG_PERM_USERPROP		"userprop"

/*
 * Note: the names of properties that are marked delegatable are also
 * valid delegated permissions
 */

int dsl_deleg_get(const char *ddname, nvlist_t **nvp);
int dsl_deleg_set(const char *ddname, nvlist_t *nvp, boolean_t unset);
int dsl_deleg_access(const char *ddname, const char *perm, cred_t *cr);
void dsl_deleg_set_create_perms(dsl_dir_t *dd, dmu_tx_t *tx, cred_t *cr);
int dsl_deleg_can_allow(char *ddname, nvlist_t *nvp, cred_t *cr);
int dsl_deleg_can_unallow(char *ddname, nvlist_t *nvp, cred_t *cr);
int dsl_deleg_destroy(objset_t *os, uint64_t zapobj, dmu_tx_t *tx);
boolean_t dsl_delegation_on(objset_t *os);

#ifdef	__cplusplus
}
#endif

#endif	/* _SYS_DSL_DELEG_H */
