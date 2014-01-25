//
//  ViewController.m
//  utils-repo
//
//  Created by xian on 14-1-25.
//  Copyright (c) 2014年 feibo. All rights reserved.
//

#import "ViewController.h"
#import "utils.h"

@interface ViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) UITableView *tabView;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.tabView = [[[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain] doto:^(UITableView *it) {
        [it setDelegate:self];
        [it setDataSource:self];

        [it setTableHeaderView:[[[UILabel alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.frame), 64)] doto:^(UILabel *l) {
            [l setBackgroundColor:RGB(156, 89, 184)];
            [l setTextColor:GRAY_WITH_SCALE(0xcc)];
            [l setText:@"This is header"];
            [l setTextAlignment:NSTextAlignmentCenter];
        }]];

        [it setTableFooterView:[[[UILabel alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(self.view.frame), 64)] doto:^(UILabel *l) {
            [l setBackgroundColor:RGB(47, 204, 113)];
            [l setTextColor:GRAY_WITH_SCALE(0xcc)];
            [l setText:@"This is footer"];
            [l setTextAlignment:NSTextAlignmentCenter];
        }]];
    }];

    [self.view addSubview:self.tabView];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UITableView Delegate & DataSource Methods

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 5;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    // ehmmm, clean & tidy indeed!
    return [[UITableViewCell cell4TableView:tableView] doto:^(UITableViewCell *it) {
        [it.textLabel setText:[NSString stringWithFormat:@"%d", indexPath.row]];
    }];
}

@end
