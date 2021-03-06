//
//  GKAchievement.h
//  GameKit
//
//  Copyright 2010 Apple Inc. All rights reserved.
//
#import <Foundation/Foundation.h>

// GKAchievement represents a game achievement that the player has started or completely achieved.
NS_CLASS_AVAILABLE(10_8, 4_1)
@interface GKAchievement : NSObject <NSCoding, NSSecureCoding>

// Asynchronously load all achievements for the local player
+ (void)loadAchievementsWithCompletionHandler:(void(^)(NSArray *achievements, NSError *error))completionHandler;

// Reset the achievements progress for the local player. All the entries for the local player are removed from the server. Error will be nil on success.
//Possible reasons for error:
// 1. Local player not authenticated
// 2. Communications failure
+ (void)resetAchievementsWithCompletionHandler:(void(^)(NSError *error))completionHandler;

// Designate initializer
- (id)initWithIdentifier:(NSString *)identifier;

// Will initialize the achievement for a player. Can be used for submitting participant achievements when ending a turn-based match.
- (id)initWithIdentifier:(NSString *)identifier forPlayer:(NSString *)playerID __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);


// Report an array of achievements to the server. Percent complete is required. Points, completed state are set based on percentComplete. isHidden is set to NO anytime this method is invoked. Date is optional. Error will be nil on success.
// Possible reasons for error:
// 1. Local player not authenticated
// 2. Communications failure
// 3. Reported Achievement does not exist
+ (void)reportAchievements:(NSArray *)achievements withCompletionHandler:(void(^)(NSError *error))completionHandler __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_6_0);


// Report this achievement to the server. Percent complete is required. Points, completed state are set based on percentComplete. isHidden is set to NO anytime this method is invoqued. Date is optional. Error will be nil on success.
// Possible reasons for error:
// 1. Local player not authenticated
// 2. Communications failure
// 3. Reported Achievement does not exist
- (void)reportAchievementWithCompletionHandler:(void(^)(NSError *error))completionHandler __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_8,__MAC_NA,__IPHONE_4_1,__IPHONE_7_0);

@property(copy, NS_NONATOMIC_IOSONLY) NSString *identifier;                     // Achievement identifier
@property(assign, NS_NONATOMIC_IOSONLY) double percentComplete;                 // Required, Percentage of achievement complete.
@property(readonly, getter=isCompleted, NS_NONATOMIC_IOSONLY) BOOL completed;   // Set to NO until percentComplete = 100.
@property(assign, getter=isHidden, readonly, NS_NONATOMIC_IOSONLY) BOOL hidden __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_8,__MAC_NA,__IPHONE_4_1,__IPHONE_6_0);    // Set to NO when a report for that achievement is made. Note: to only unhide an achievement, report it with percentComplete = 0
@property(copy, readonly, NS_NONATOMIC_IOSONLY) NSDate *lastReportedDate;       // Date the achievement was last reported. Read-only. Created at initialization

@property(assign, NS_NONATOMIC_IOSONLY) BOOL showsCompletionBanner __OSX_AVAILABLE_STARTING(__MAC_10_8,__IPHONE_5_0);             // A banner will be momentarily displayed after reporting a completed achievement

// The identifier of the player that earned the achievement.
@property(readonly, copy, NS_NONATOMIC_IOSONLY) NSString *playerID __OSX_AVAILABLE_STARTING(__MAC_NA,__IPHONE_7_0);

@end
