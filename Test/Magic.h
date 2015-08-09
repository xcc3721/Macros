//
//  Magic.h
//  Test
//
//  Created by Erick Xi on 8/9/15.
//  Copyright © 2015 Erick Xi. All rights reserved.
//

#ifndef Magic_h
#define Magic_h

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define PREFIXNAME(a) CAT(__, a)
#define MERGENAME(a, b) CAT(a, CAT(_, b))

#define PROPERTY(genericType, propertyName) PROPERTYDEAIL(genericType, propertyName, nonatomic, strong)

#define PROPERTYDEAIL(genericType, propertyName, ...) \
@property (__VA_ARGS__) NSArray <genericType *> *propertyName; \
@property (nonatomic, assign) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));


#endif /* Magic_h */
