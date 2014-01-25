//
//  utils_color.h
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

#ifndef utils_repo_utils_color_h
#define utils_repo_utils_color_h

// UIColor macro definitions that are easy to use.
#define RGBA(r, g, b, a) [UIColor colorWithRed:(r) / 255.0 \
                                           green:(g) / 255.0 \
                                            blue:(b) / 255.0 \
                                           alpha:(a) / 255.0]

#define RGB(r, g, b) RGBA((r), (g), (b), 255)

// usage example:
//   HEX_RGBA(0xCCCCCCFF)
//   HEX_RGB(0xCCCCCC)
#define HEX_RGBA(rgba) RGBA((rgb & 0xff000000) >> 24, \
                            (rgb & 0x00ff0000) >> 16, \
                            (rgb & 0x0000ff00) >> 8, \
                            (rgb & 0x000000ff) >> 0)

#define HEX_RGB(rgb) HEX_RGBA((rgb << 8) + 0xff)

#define GRAY_WITH_SCALE(scale) RGB(scale, scale, scale)

#endif
