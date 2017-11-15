//
//  LittleRooter.cpp
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//
#include <mach/task.h>
#include <sys/random.h>
#include <kern/clock.h>
#include <libkern/crypto/sha1.h>
#include <sys/fcntl.h>
#include <sys/kauth.h>

#include "mac_policy_hooks.h"
#include "mac_policy_callbacks.h"
#include "LittleRooter.hpp"

#define super IOService
OSDefineMetaClassAndStructors(LittleRooterDriver, IOService);

bool LittleRooterDriver::init(OSDictionary *dict)
{
    bool res = super::init(dict);
    if (res == false)
        return res;

    IOLog("LittleRooter: %s: init\n", __func__);
    return res;
}

bool LittleRooterDriver::start(IOService *provider)
{
    bool res = super::start(provider);
    if (res == false)
        return res;

    super::registerService();
    
    IOLog("LittleRooter: %s: started successfully\n", __func__);
    
    return addPolicy();
}

void LittleRooterDriver::stop(IOService *provider)
{
    removePolicy();
    super::stop(provider);
}

void LittleRooterDriver::free(void)
{
    super::free();
}

bool LittleRooterDriver::addPolicy()
{
    bool success = false;
    
    policyHandle = { 0 };
    policyOps = {
        .mpo_vnode_check_unlink = _macf_vnode_check_unlink_internal,
        .mpo_vnode_check_exec = _macf_vnode_check_exec_internal,
    };
    policyConf = {
        .mpc_name            = "Little Rooter",
        .mpc_fullname        = "Little Rooter Educational KEXT Example",
        .mpc_labelnames      = NULL,
        .mpc_labelname_count = 0,
        .mpc_ops             = &policyOps,
        .mpc_loadtime_flags  = MPC_LOADTIME_FLAG_UNLOADOK,
        .mpc_field_off       = NULL,
        .mpc_runtime_flags   = 0,
        .mpc_list            = NULL,
        .mpc_data            = NULL
    };
    
    int mpr = _mac_policy_register_internal(&policyConf, &policyHandle);
    if (!mpr) {
        success = true;
        IOLog("LittleRooter: %s: policy added\n", __func__);
    } else {
        IOLog("LittleRooter: %s: error %d occurred while adding policy\n", __func__, mpr);
    }
    
    return success;
}

bool LittleRooterDriver::removePolicy()
{
    bool success = false;
    
    kern_return_t kr = _mac_policy_unregister_internal(policyHandle);
    if (kr == KERN_SUCCESS) {
        success = true;
        IOLog("LittleRooter: %s: removed policy\n", __func__);
    } else {
        IOLog("LittleFlocker: %s: error %d occurred while removing policy\n", __func__, kr);
    }
    
    return success;
}
