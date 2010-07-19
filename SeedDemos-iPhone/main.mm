//
//  main.m
//  Basic1
//
//  Created by Danny Grein on 2/17/09.
//  Copyright TechFront Studios 2009. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <Seed.h>
#include "mygame.h"

using namespace Seed;

ISceneNode *pScene = NULL;
ISceneNode *pSceneStatic = NULL;

int main(int argc, char *argv[]) 
{   
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	MyGame app;
	Seed::SetGameApp(&app, argc, argv);

    int retVal = UIApplicationMain(argc, argv, nil, nil);
    [pool release];
    return retVal;
}
