//
//  FoundationRaise.h
//  iOS equivalent of NSRaise.h in AppKit
//
//  Created by Dan Zinngrabe on 1/3/13.
//  Copyright (c) 2013 Dan Zinngrabe. All rights reserved.
//

#ifndef __FOUNDATIONRAISE_H__
#define __FOUNDATIONRAISE_H__

#ifdef CLANG_ENABLE_MODULES
@import CoreFoundation;
@import Foundation;
#else
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#endif

#if PRAGMA_ONCE
#pragma once
#endif

#ifdef __cplusplus
extern "C" {
#endif
    
#pragma mark Function prototypes
    
    /**
     *  Raises an exception for an abstract class or method.
     */
    
    void NSInvalidAbstractInvocation(void) __attribute__((weak));
    
    /**
     *  Raises an exception for an unimplemented method.
     */
    
    void NSUnimplementedMethod(void) __attribute__((weak));
    
    /**
     *  Raise an exception for an unimplemented function.
     */
    
    void NSUnimplementedFunction(void) __attribute__((weak));
    
#pragma mark Macros
    
#ifndef NSInvalidAbstractInvocation
#define NSInvalidAbstractInvocation() \
_NSInvalidAbstractInvocation(_cmd,self,__FILE__,__LINE__)
#endif
    
#ifndef NSUnimplementedMethod
#define NSUnimplementedMethod() \
_NSUnimplementedMethod(_cmd,self,__FILE__,__LINE__)
#endif
    
#ifndef NSUnimplementedFunction
#define NSUnimplementedFunction() \
_NSUnimplementedFunction(__PRETTY_FUNCTION__,__FILE__,__LINE__)
#endif
    
#pragma mark Inline functions
    
    static inline void _NSInvalidAbstractInvocation(SEL selector,id object,const char *file,int line) {
        [NSException raise:NSInvalidArgumentException
                    format:@"-%s only defined for abstract class. Define -[%@ %s] in %s:%d!",
         sel_getName (selector),[object class], sel_getName (selector),file,line];
    }
    
    static inline void _NSUnimplementedMethod(SEL selector,id object,const char *file,int line) {
        NSLog(@"-[%@ %s] unimplemented in %s at %d",[object class],sel_getName(selector),file,line);
    }
    
    static inline void _NSUnimplementedFunction(const char *function,const char *file,int line) {
        NSLog(@"%s() unimplemented in %s at %d",function,file,line);
    }
    
#ifdef __cplusplus
}

#endif

#endif

