//
//  LittleRooter.hpp
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#ifndef __LittleRooter_HPP_
#define __LittleRooter_HPP_

#include <IOKit/IOService.h>
#include <IOKit/IOLib.h>
#include <IOKit/IOLocks.h>
#include <sys/proc.h>
#include <sys/vnode.h>
#include <sys/kern_event.h>
#include <sys/kauth.h>
#include <sys/types.h>
#include <sys/kern_event.h>
#include <libkern/libkern.h>
#include <mach/mach_types.h>
#include <security/mac.h>
#include <security/mac_policy.h>
#include <security/mac_framework.h>
#include "KernelResolver.h"

class LittleRooterDriver : public IOService
{
    OSDeclareDefaultStructors(LittleRooterDriver)
    
public:
    bool init(OSDictionary *dictionary = NULL) override;
    bool start(IOService *provider) override;
    void stop(IOService *provider) override;
    void free(void) override;
    
    bool addPolicy();
    bool removePolicy();
private:
    mac_policy_handle_t policyHandle;
    struct mac_policy_ops policyOps;
    struct mac_policy_conf policyConf;
};

#endif
