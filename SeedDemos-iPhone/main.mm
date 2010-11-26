//  Created by Danny Grein on 10/13/08.
//  Copyright TechFront Studios 2008. All rights reserved.

#import <UIKit/UIKit.h>

#include <Seed.h>
#include "BI_GameFlow.h"

using namespace Seed;

ISceneNode *pRenderer;
ISceneNode *pRendererStatic;
BI_Sound *pSound;

int main(int argc, char *argv[])
{ 
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	
	//cBI_GameFlow app;
	Seed::SetGameApp(pBI_GameFlow, argc, argv);
	
    int retVal = UIApplicationMain(argc, argv, nil, @"SeedDelegate");
    [pool release];
    return retVal;
}
