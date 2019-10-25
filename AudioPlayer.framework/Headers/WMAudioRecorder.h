//
//  AudioRecorder.h
//  AudioDemo
//
//  Created by user on 2019/5/21.
//  Copyright © 2019 adu. All rights reserved.
//

#import <Foundation/Foundation.h>
#define bufferLength 2048
NS_ASSUME_NONNULL_BEGIN

@class WMAudioRecorder;

@protocol WMAudioRecorderDelegate <NSObject>

- (void)audioRecord:(WMAudioRecorder *)recorder
bufferSize:(int16_t)bufferSize
    buffer_fft:(int16_t *)buffer;

- (void)audioRecord:(WMAudioRecorder *)recorder
bufferSize:(int16_t)bufferSize
             buffer:(float * _Nullable const *_Nonnull)buffer;
@end

@interface WMAudioRecorder: NSObject

@property(nonatomic, weak) id <WMAudioRecorderDelegate> delegate;
@property(nonatomic,assign) BOOL needFFT;
@property(nonatomic,assign) NSInteger ffBufferSize;
- (void)startRecord;
- (void)stop;
@end

NS_ASSUME_NONNULL_END
