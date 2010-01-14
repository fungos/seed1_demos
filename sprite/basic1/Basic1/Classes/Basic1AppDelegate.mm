//
//  Basic1AppDelegate.m
//  Basic1
//
//  Created by Danny Grein on 2/17/09.
//  Copyright TechFront Studios 2009. All rights reserved.
//

#import "Basic1AppDelegate.h"
#import "IphoneView.h"
#import <Seed.h>

@implementation Basic1AppDelegate

@synthesize window;
@synthesize view;


- (void)applicationDidFinishLaunching:(UIApplication *)application 
{
	//[application setStatusBarStyle:UIStatusBarStyleBlackTranslucent animated:NO];
	[application setStatusBarHidden:YES animated:NO];

	[view SetUpdateRate:(1.0/60.0)];
	[view Start];
}


- (void)applicationWillResignActive:(UIApplication *)application 
{
	[view Pause];
}


- (void)applicationDidBecomeActive:(UIApplication *)application 
{
}


- (void)applicationWillTerminate:(UIApplication *)application
{
	[view Stop];
}


- (void)dealloc {
	[window release];
	[view release];
	[super dealloc];
}

@end
