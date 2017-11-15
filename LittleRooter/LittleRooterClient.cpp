//
//  LittleFlockerClient.cpp
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#include "LittleRooterClient.hpp"

#define super IOUserClient
OSDefineMetaClassAndStructors(LittleRooterDriverClient, IOUserClient)

bool LittleRooterDriverClient::initWithTask(task_t owningTask, void *securityToken, UInt32 type, OSDictionary *properties)
{    
    if (!owningTask)
        return false;
    
    if (! super::initWithTask(owningTask, securityToken, type, properties))
        return false;

    m_task = owningTask;
    m_taskIsAdmin = false;
    
    IOReturn ret = clientHasPrivilege(securityToken, kIOClientPrivilegeAdministrator);
    if (ret == kIOReturnSuccess)
        m_taskIsAdmin = true;
    
    return true;
}

bool LittleRooterDriverClient::start(IOService *provider)
{
    if (! super::start(provider))
        return false;
    
    m_driver = OSDynamicCast(LittleRooterDriver, provider);
    if (!m_driver)
        return false;
    return true;
}

void LittleRooterDriverClient::stop(IOService *provider)
{
    super::stop(provider);
}

void LittleRooterDriverClient::free(void)
{
    super::free();
}

