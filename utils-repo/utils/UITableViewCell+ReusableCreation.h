//
//  UITableViewCell+ReusableCreation.h
//  etmt
//
//  Created by xian on 13-10-3.
//  Copyright (c) 2013年 feibo. All rights reserved.
//

#import <UIKit/UIKit.h>

// This category enables us to extract and purify these code:
//
// static NSString *identifier = @"Identifier"
//
// UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
//
// if (!cell) {
//     cell = [[UITableViewCell alloc] initWithStyle:style reuseIdentifier:identifier];
// }
//
// return cell;
//
// INTO:
//
// UITableViewCell *cell = [[UITableViewCell cell4TableView:tableview] doto:^(UITableViewCell *it) {
//     do something to setup cell
// }];

typedef void (^CellSetupBlkType) (UITableViewCell *cell);

@interface UITableViewCell (ReusableCreation)

+ (id)cell4TableView:(UITableView *)tableView;  // default UITableViewCellStyleDefault
+ (id)cell4TableView:(UITableView *)tableView style:(UITableViewCellStyle)style;

+ (NSString *)cellIdentifier;

@end
