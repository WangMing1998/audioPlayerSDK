//
//  WMAudiouints.h
//  AudioDemo
//
//  Created by Heaton on 2019/10/10.
//  Copyright © 2019 adu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#define kBufferSize 1024
NS_ASSUME_NONNULL_BEGIN
@class WMAudiouints;
@protocol WMAudiouintsDelegate <NSObject>
@optional
-(void)audioPlayerPlaying:(WMAudiouints *)player
                 progress:(NSTimeInterval)progress;
-(void)audioPlayerPlayEnd:(WMAudiouints *)player
             successfully:(BOOL)flag;

-(void)audioPlayerDidStop:(WMAudiouints *)player;

-(void)audioPlayer:(WMAudiouints *)player
        buffer_fft:(int16_t *)buffer
        bufferSize:(int16_t)bufferSize
          maxLevel:(int16_t)maxLevel
          minLevel:(int16_t)maxLevel;

- (void) audioPlayer:(WMAudiouints *)audioPlayer
         playedAudio:(float * __nonnull const * __nullable)buffer
      withBufferSize:(UInt32)bufferSize;

@end


@interface WMAudiouints : NSObject

@property(nonatomic,assign) CGFloat volume;
@property(nonatomic,assign) CGFloat pan;
@property(nonatomic,assign) NSTimeInterval currentTime;
@property(nonatomic,strong) NSURL *url;
@property(nonatomic,assign, getter=isPlaying) BOOL playing;
@property(nonatomic,weak) id<WMAudiouintsDelegate> delegate;
@property(nonatomic,assign) BOOL needFFT;
@property(nonatomic,assign) NSInteger ffBufferSize;

- (instancetype)initWithContentsOfURL:(NSURL *)url
                                  pan:(CGFloat)pan
                               volume:(CGFloat)volume
                                error:(NSError * _Nullable __autoreleasing *)outError ;
- (void)play;
- (void)pause;
- (void)stop;
@end


@interface NSTimer (XDCategory)

// block回调，别用ios9没有的scheduledTimerWithTimeInterval:repeats:block:
+ (NSTimer *)xd_scheduledTimerWithTimeInterval:(NSTimeInterval)interval repeats:(BOOL)repeats block:(void (^)(NSTimer *timer))block;

@end

NS_ASSUME_NONNULL_END
