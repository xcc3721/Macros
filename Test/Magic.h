//
//  Magic.h
//  Test
//
//  Created by Erick Xi on 8/9/15.
//  Copyright © 2015 Erick Xi. All rights reserved.
//

#pragma once

#define CAT(a, ...) PRIMITIVE_CAT(a, __VA_ARGS__)
#define PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#define PREFIXNAME(a) CAT(__, a)
#define MERGENAME(a, b) CAT(a, CAT(_, b))

#define PROPERTY(genericType, propertyName) PROPERTYDEAIL(genericType, propertyName, nonatomic, strong)

#if __has_feature(objc_generics)
#define PROPERTYDEAIL(genericType, propertyName, ...) \
@property (__VA_ARGS__) NSArray <genericType *> *propertyName; \
@property (nonatomic, assign) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));
#else
#define PROPERTYDEAIL(genericType, propertyName, ...) \
@property (__VA_ARGS__) NSArray *propertyName; \
@property (nonatomic, assign) BOOL PREFIXNAME(MERGENAME(propertyName, genericType));
#endif


#if __has_feature(objc_generics)
/** Inserts a type specifier for a pointer to a lightweight generic with the given collection and object classes. Use a `*` for any non-`id` object classes but no `*` for the collection class. */
#define NS_ARRAY_OF(ObjectClass...)                 NSArray <ObjectClass>
#define NS_MUTABLE_ARRAY_OF(ObjectClass...)         NSMutableArray <ObjectClass>
#define NS_SET_OF(ObjectClass...)                   NSSet <ObjectClass>
#define NS_MUTABLE_SET_OF(ObjectClass...)           NSMutableSet <ObjectClass>
#define NS_DICTIONARY_OF(ObjectClass...)            NSDictionary <ObjectClass>
#define NS_MUTABLE_DICTIONARY_OF(ObjectClass...)    NSMutableDictionary <ObjectClass>
#else
#define NS_ARRAY_OF(ObjectClass...)                 NSArray
#define NS_MUTABLE_ARRAY_OF(ObjectClass...)         NSMutableArray
#define NS_SET_OF(ObjectClass...)                   NSSet
#define NS_MUTABLE_SET_OF(ObjectClass...)           NSMutableSet
#define NS_DICTIONARY_OF(ObjectClass...)            NSDictionary
#define NS_MUTABLE_DICTIONARY_OF(ObjectClass...)    NSMutableDictionary
#endif
