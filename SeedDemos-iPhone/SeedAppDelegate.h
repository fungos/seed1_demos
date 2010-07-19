//
//  Basic1AppDelegate.h
//  Basic1
//
//  Created by Danny Grein on 2/17/09.
//  Copyright TechFront Studios 2009. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <platform/iphone/IphoneView.h>
#include <Seed.h>

@class EAGLView;

@interface SeedAppDelegate : NSObject <UIApplicationDelegate> {
    UIWindow *window;
	AppView  *view;
}

@property (nonatomic, retain) IBOutlet UIWindow *window;
@property (nonatomic, retain) IBOutlet UIView *view;

@end

