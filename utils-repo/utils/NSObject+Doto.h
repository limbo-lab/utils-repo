//
//  NSObject+Doto.h
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

// 思想借鉴 ruby 可以在方法后面附一个 block 与 self yield
// 命名来自 clojure, doto = do something to it
// NSObject 不持有这个 block, 因此在 block 中不用担心循环引用的问题
#import <Foundation/Foundation.h>

typedef void (^SelfYieldBlock)(id obj);

@interface NSObject (Doto)

- (id)doto:(SelfYieldBlock)dotoBlock;

@end
