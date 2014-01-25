//
//  utils_singleton.h
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

#ifndef utils_repo_utils_singleton_h
#define utils_repo_utils_singleton_h

// Turn a class into a singleton class with class name.
// usage:
//  In .h file:
//    + (classname)instance;
//
//  In .m file:
//    SYNTHESIZE_SINGLETON(classname)

#if __has_feature(objc_arc) // ARC Version

#define SYNTHESIZE_SINGLETON(classname)   \
\
+ (classname *)instance \
{\
static classname *shared##classname = nil;\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
shared##classname = [[classname alloc] init];\
});\
return shared##classname;\
}

#else // Non-ARC Version

#define SYNTHESIZE_SINGLETON(classname) \
\
static classname *shared##classname = nil; \
+ (classname *)instance \
{ \
@synchronized(self) { \
if (shared##classname == nil) { \
shared##classname = [[self alloc] init]; \
} \
} \
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) { \
if (shared##classname == nil) { \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
} \
\
- (id)retain \
{ \
return self; \
} \
\
- (NSUInteger)retainCount \
{ \
return NSUIntegerMax; \
} \
\
- (oneway void)release \
{ \
} \
\
- (id)autorelease \
{ \
return self; \
}

#endif

#endif
