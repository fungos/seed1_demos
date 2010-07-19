//
//  Basic1AppDelegate.m
//  Basic1
//
//  Created by Danny Grein on 2/17/09.
//  Copyright TechFront Studios 2009. All rights reserved.
//

#import "SeedAppDelegate.h"
#import <Seed.h>

@implementation SeedAppDelegate

@synthesize window;
@synthesize view;


- (void)applicationDidFinishLaunching:(UIApplication *)application 
{
	//[application setStatusBarStyle:UIStatusBarStyleBlackTranslucent animated:NO];
	[application setStatusBarHidden:YES animated:NO];

	f32 time = 1.0f / (f32)pConfiguration->GetFrameRate();
	[view SetUpdateRate: time];
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
