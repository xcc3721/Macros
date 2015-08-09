//
//  NSObject+AutoElementClass.h
//  Test
//
//  Created by Erick Xi on 8/9/15.
//  Copyright © 2015 Erick Xi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (AutoElementClass)

+ (Class)elementClassForProperty:(SEL)selector;
+ (Class)elementClassForProperty:(SEL)selector recursive:(BOOL)recursive;

@end
