//
//  LittleFlockerClient.hpp
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 by Jonathan Zdziarski. For Educational Use Only.
//

#include <IOKit/IOService.h>
#include <IOKit/IOUserClient.h>
#include <IOKit/IOLib.h>
#include "LittleRooter.hpp"

#ifndef LittleRooterClient_hpp
#define LittleRooterClient_hpp

class LittleRooterDriverClient : public IOUserClient
{
    OSDeclareDefaultStructors(LittleRooterDriverClient)
    
private:
    task_t m_task;
    bool m_taskIsAdmin;
    LittleRooterDriver *m_driver;
    
public:
    virtual bool initWithTask(task_t owningTask, void *securityToken, UInt32 type, OSDictionary *properties) override;
    virtual bool start(IOService *provider) override;
    virtual void stop(IOService *provider) override;
    virtual void free(void) override;
};

#endif /* LittleFlockerClient_hpp */
