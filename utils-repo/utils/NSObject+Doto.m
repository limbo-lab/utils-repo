//
//  NSObject+Doto.m
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

#import "NSObject+Doto.h"
#include "utils_block_safe.h"

@implementation NSObject (Doto)

- (id)doto:(SelfYieldBlock)dotoBlock
{
    YIELD(dotoBlock, self);

    return self;
}

@end
