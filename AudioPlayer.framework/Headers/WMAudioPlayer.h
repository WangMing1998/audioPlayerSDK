//
//  AudioPlayer.h
//  AudioDemo
//
//  Created by user on 2019/5/8.
//  Copyright © 2019 adu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MusicModel.h"
NS_ASSUME_NONNULL_BEGIN
@class WMAudioPlayer;
typedef NS_ENUM(NSInteger,playerStatus){
    playerStatusStop,
    playerStatusPlaying,
    playerStatusPause
};


@protocol AudioPlayerDelegate <NSObject>

@optional

/// 开始播放
/// @param audioPlayer audioPlayer
/// @param musicItem 播放的歌曲信息
/// @param currentIndex 歌曲序号
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
  playWithMusicItem:(MusicModel *)musicItem
              index:(NSInteger)currentIndex;


/// 播放失败
/// @param audioPlayer audioPlayer
/// @param error 失败原因
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer playWithError:(NSError *)error;


///  停止播放 有可能是站停或被打断
/// @param audioPlayer audioPlayer
/// @param musicItem 中断的歌曲信息
/// @param currentIndex 歌曲序号
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
        playDidStop:(MusicModel *)musicItem
              index:(NSInteger)currentIndex;

/// 播放完成音乐
/// @param audioPlayer audioPlayer
/// @param musicItem 播放完成的歌曲信息
/// @param currentIndex 歌曲序号

- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
finishWithMusicItem:(MusicModel *)musicItem
              index:(NSInteger)currentIndex;

/// 播放进度回调
/// @param audioPlayer audioPlayer
/// @param currentProgress 当前进度
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
    currentProgress:(NSTimeInterval)currentProgress;

/// 音乐列表发生变化
/// @param audioPlayer audioPlayer
/// @param musicList 新的音乐列表
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
   musicListChanged:(NSArray<MusicModel *> *)musicList;


/// 加载音乐完成
/// @param audioPlayer audioPlayer
/// @param list 音乐列表
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
  loadMusicListFish:(NSArray<MusicModel *>*)list;


///  音乐频谱回调
/// @param audioPlayer audioPlayer
/// @param buffer pcmData
- (void)audioPlayer:(WMAudioPlayer *)audioPlayer
         buffer_fft:(int16_t *)buffer
         bufferSize:(int16_t)bufferSize
           maxLevel:(int16_t)maxLevel
           minLevel:(int16_t)minLevel;


/// 原始数据回调
/// @param audioPlayer audioplayer
/// @param buffer 原始数据
/// @param bufferSize 数据长度
- (void) audioPlayer:(WMAudioPlayer *)audioPlayer
         playedAudio:(float * __nonnull const * __nullable)buffer
      withBufferSize:(UInt32)bufferSize;

@end

@interface WMAudioPlayer : NSObject
/// 音量 0.0 ~ 1.0
@property(nonatomic,assign) CGFloat volume;
/// 声道 -1.0 ，0, 1.0
@property(nonatomic,assign) CGFloat pan;
/// 是否开启FFT
@property (nonatomic,assign) BOOL needFFT;

@property (nonatomic, weak) id <AudioPlayerDelegate> delegate;
@property(nonatomic,assign) NSTimeInterval currentTime;
@property (readonly, nonatomic) BOOL hasSongPlay;
@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, assign,readonly) BOOL playing;
@property (nonatomic,assign,readonly) playerStatus playerState;
@property (nonatomic,strong) NSMutableArray *musicList;
@property(nonatomic,strong) MusicModel *playingMusicItem;
@property(nonatomic,assign) NSInteger currentPlayingIndex;
@property(nonatomic,assign) BOOL startAfterRestart;
@property(nonatomic,assign) NSInteger fftBufferSize;
+ (instancetype)sharedAudioPlayer;

-(void)loadMusicWithBundleName:(NSString *)bundleName completeCallBack:(void (^)(NSArray * musicList))completeCallBack;
// 从播放列表进入
- (void)playWithMuswicModel:(MusicModel *)musicItem;
- (void)play;
- (void)pause;
- (void)playOrPause;
- (void)playPrevious;
- (void)playNext;
@end

NS_ASSUME_NONNULL_END
