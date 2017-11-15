//
//  mac_policy_hooks.c
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/kern_event.h>
#include <libkern/libkern.h>
#include <mach/mach_types.h>
#include <security/mac.h>
#include <security/mac_policy.h>
#include <security/mac_framework.h>

int _mac_policy_register_internal(struct mac_policy_conf *mpc, mac_policy_handle_t *handlep)
{
    return mac_policy_register(mpc, handlep, (void *)0);
}

int _mac_policy_unregister_internal(mac_policy_handle_t handlep)
{
    return mac_policy_unregister(handlep);
}
