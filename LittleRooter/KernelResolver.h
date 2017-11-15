//
//  KernelResolver.h
//  LittleRooter
//
//  Created by Jonathan Zdziarski on 2/7/17.
//  Copyright © 2017 Jonathan Zdziarski. All rights reserved.
//

#ifndef KernelResolver_h
#define KernelResolver_h

#include <mach/mach_types.h>
#include <mach-o/loader.h>
#include <sys/systm.h>
#include <sys/types.h>
#include <vm/vm_kern.h>
#include <sys/sysctl.h>

#ifdef __cplusplus
extern "C" {
#endif
    
void *lookup_symbol(const char *symbol);

#ifdef __cplusplus
}
#endif

#define IOLog printf

#endif /* KernelResolver_h */
