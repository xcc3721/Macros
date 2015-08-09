//
//  NSObject+AutoElementClass.m
//  Test
//
//  Created by Erick Xi on 8/9/15.
//  Copyright © 2015 Erick Xi. All rights reserved.
//

#import <objc/runtime.h>

#import "NSObject+AutoElementClass.h"

@implementation NSObject (AutoElementClass)

+ (Class)elementClassForProperty:(SEL)selector {
    unsigned int count = 0;
    
    objc_property_t *propertyList = class_copyPropertyList([self class], &count);
    
    NSString *target = NSStringFromSelector(selector);
    NSString *genericType = nil;
    
    for (int i = 0; i < count; i++) {
        NSString *propertyName = @(property_getName(propertyList[i]));
        if ([propertyName hasPrefix:[NSString stringWithFormat:@"__%@_", target]])
        {
            genericType = [propertyName substringFromIndex:[target length] + 3];
            break;
        }
    }
    
    return NSClassFromString(genericType);
}

+ (Class)elementClassForProperty:(SEL)selector recursive:(BOOL)recursive {
    Class ret = nil;
    
    ret = [self elementClassForProperty:selector];
    if (ret == nil && recursive) {
        ret = [[self superclass] elementClassForProperty:selector recursive:recursive];
    }
    return ret;
}

@end
