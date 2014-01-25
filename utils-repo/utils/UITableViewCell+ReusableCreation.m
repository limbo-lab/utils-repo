//
//  UITableViewCell+ReusableCreation.m
//  etmt
//
//  Created by xian on 13-10-3.
//  Copyright (c) 2013年 feibo. All rights reserved.
//

#import "UITableViewCell+ReusableCreation.h"
#import "utils_block_safe.h"

@implementation UITableViewCell (ReusableCreation)

+ (id)cell4TableView:(UITableView *)tableView
{
    return [self cell4TableView:tableView style:UITableViewCellStyleDefault];
}

+ (id)cell4TableView:(UITableView *)tableView style:(UITableViewCellStyle)style
{
    NSString *identifier = [self cellIdentifier];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    
    if (!cell) {
        cell = [[self alloc] initWithStyle:style reuseIdentifier:identifier];
    }
    
    return cell;
}

+ (NSString *)cellIdentifier
{
    return NSStringFromClass(self);
}

@end
