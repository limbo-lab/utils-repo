//
//  utils_block_safe.h
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

#ifndef utils_repo_utils_block_safe_h
#define utils_repo_utils_block_safe_h

#if __has_feature(objc_arc)

#define WEAK(src, dest) __weak typeof(src) dest = src

#else

#define WEAK(src, dest) __block typeof(src) dest = src

#endif

#define WEAK_SELF(name) WEAK(self, name)

#define BLOCK_CALL(blk, ...) if (blk) blk(__VA_ARGS__)
#define YIELD BLOCK_CALL

#endif
