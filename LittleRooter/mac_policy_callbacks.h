//
//  mac_policy_callbacks.h
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#ifndef mac_policy_callbacks_h
#define mac_policy_callbacks_h

#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/kern_event.h>
#include <libkern/libkern.h>
#include <mach/mach_types.h>
#include <security/mac.h>
#include <security/mac_policy.h>
#include <security/mac_framework.h>

int _macf_vnode_check_exec_internal(kauth_cred_t cred, struct vnode *vp, struct vnode *scriptvp, struct label *vnodelabel,struct label *scriptlabel, struct label *execlabel, struct componentname *cnp, u_int *csflags, void *macpolicyattr, size_t macpolicyattrlen);
int _macf_vnode_check_unlink_internal(kauth_cred_t cred,struct vnode *dvp, struct label *dlabel, struct vnode *vp, struct label *label, struct componentname *cnp);

#endif /* mac_policy_callbacks_h */
