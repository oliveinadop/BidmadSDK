//
//  BIDMADRewardVideo.h
//  BidmadSDK
//
//  Created by 김선정 on 2018. 10. 29..
//  Copyright © 2018년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BIDMADUtil.h"
#import "BIDMADSetting.h"
#import "BIDMADFacebook.h"
#import "BIDMADAtomReward.h"
#import "BIDMADAdmob.h"
#import "BIDMADAdmanager.h"
#import "BIDMADUnityAds.h"
#import "BIDMADAppLoving.h"
#import "BIDMADAdColony.h"
//#import "BIDMADMoPub.h"
#import "BIDMADIronSource.h"
#import "BIDMADInterstitial.h"

@protocol BIDMADRewardVideoDelegate;

@protocol BIDMADRewardVideoInnerDelegate <NSObject>
@required

- (void)onVideoLoad:(BIDMADRewardVideo *)core       current:(NSDictionary*) currentDic;
- (void)onVideoError:(BIDMADRewardVideo *)core code:(NSString *)error failType:(NSString*) failType current:(NSDictionary*)currentDic passbackStr:(NSString*) passBackStr passback:(NSDictionary*) passbackDic;
- (void)onVideoShow:(BIDMADRewardVideo *)core       current:(NSDictionary*) currentDic;
- (void)onVideoClick:(BIDMADRewardVideo *)core      current:(NSDictionary*) currentDic;
- (void)onVideoSuccess:(BIDMADRewardVideo *)core    current:(NSDictionary*) currentDic;
- (void)onVideoSkipped:(BIDMADRewardVideo *) core   current:(NSDictionary*) currentDic;

@end

@interface BIDMADRewardVideo : NSObject <BIDMADRewardVideoInnerDelegate>

@property (nonatomic, strong) id<BIDMADRewardVideoDelegate> delegate;

@property (nonatomic, strong) id<BIDMADRewardVideoInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController*             parentViewController;

@property (strong, nonatomic) NSDictionary*                 ads_dic;

@property (strong, nonatomic) NSDictionary*                      ecmp_rev_info;
@property (strong, nonatomic) NSDictionary*                      area_info;

@property (strong, nonatomic) NSDictionary*                    change_info;
@property (strong, nonatomic) NSDictionary*                    date;
@property (strong, nonatomic) NSString*                        mediationType;

@property (nonatomic) int mediationNumber;

@property (nonatomic) BOOL isDirectLoad;

@property (nonatomic) NSString * zoneID;

@property (nonatomic, strong) NSString* userId;

@property (strong,nonatomic) NSString*                      isFBB;

@property (nonatomic) BOOL                       isLabelService;
@property (nonatomic) BOOL                       isLabelServiceAdmin;
@property (nonatomic) BOOL                       testMode;
@property (nonatomic) BOOL                       isComplete;
@property (nonatomic) BOOL                       isLoaded;

@property (nonatomic) NSString *                 realZoneId;


@property (nonatomic) BOOL isInterstitialBackfill;
@property (nonatomic, strong) BIDMADInterstitial* interstitial;


///inititalize
- (id)init;

///InterstitialView Load
- (void)loadRewardVideo;

///InterstitialView Show
- (void)showRewardVideo;

- (void)directShowRewardView;

- (void)selectAds:(NSDictionary *)lv_dic;

- (void) sendLog :(NSDictionary *) info :(NSString *) advertisementType :(NSString *) logType;

- (void) setTestDevice :(NSString *)deviceId;

- (void) releaseBidmadResource;


@end

@protocol BIDMADRewardVideoDelegate <NSObject>

@optional

- (void)BIDMADRewardVideoAllFail:(BIDMADRewardVideo *)core;

/// PREPARED INTERSTITIAL VIEW
- (void)BIDMADRewardVideoLoad:(BIDMADRewardVideo *)core;

/// For Display
- (void)BIDMADRewardVideoSuccessLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADRewardVideoErrorLoadLog:(NSDictionary*)currentDic;

- (void)BIDMADRewardVideoClose:(BIDMADRewardVideo *)core;

/// SHOW INTERSTITIAL VIEW
- (void)BIDMADRewardVideoShow:(BIDMADRewardVideo *)core;

/// COMPLETE REWARD VIDEO
- (void)BIDMADRewardVideoComplete:(BIDMADRewardVideo *)core;

/// CLICK REWARD VIDEO
- (void)BIDMADRewardVideoClick:(BIDMADRewardVideo *)core;

/// CLICK REWARD VIDEO
- (void)BIDMADRewardVideoSucceed:(BIDMADRewardVideo *)core;

/// SKIP RERWARD VIDEO
- (void)BIDMADRewardSkipped:(BIDMADRewardVideo *) core;

@end



