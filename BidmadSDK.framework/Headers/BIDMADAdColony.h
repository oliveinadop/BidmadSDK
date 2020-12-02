//
//  BIDMADAdx.h
//  BidmadSDK
//
//  Created by 김선정 on 2017. 6. 19..
//  Copyright © 2017년 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "BIDMADRewardVideo.h"
#import "BIDMADSetting.h"
#import "BIDMADUtil.h"
#import "BIDMADLabelView.h"
#import "UIButton+circle.h"
#import <AdColony/AdColony.h>


@class BIDMADRewardVideo;

@interface BIDMADAdColony : NSObject<AdColonyInterstitialDelegate>

@property (strong,nonatomic) BIDMADRewardVideo* rewardVideo;
@property (nonatomic, weak) AdColonyInterstitial *ad;
@property (nonatomic) bool  isRewardComplte;

- (id)  initWithRewardVideo:(NSDictionary *)dic bidmadReward:(BIDMADRewardVideo *)rewardVideo userId:(NSString *)userId;
- (void)showAdColonyRewardVideo:(UIViewController *)pvc;
- (void)gogoRewardVideo;
- (void)setCompleteBoolValue:(BOOL) isComplete;
- (void)setGDPRData;

@end
