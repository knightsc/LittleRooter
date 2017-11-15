//
//  mac_policy_hooks.h
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#ifndef mac_policy_hooks_h
#define mac_policy_hooks_h

#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/kern_event.h>
#include <libkern/libkern.h>
#include <mach/mach_types.h>
#include <security/mac.h>
#include <security/mac_policy.h>
#include <security/mac_framework.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    int _mac_policy_register_internal(struct mac_policy_conf *mpc, mac_policy_handle_t *handlep);
    int _mac_policy_unregister_internal(mac_policy_handle_t handlep);
    
#ifdef __cplusplus
}
#endif

#endif /* mac_policy_hooks_h */
