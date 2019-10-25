//
//  MusicModel.h
//  MusicPlayerDemo
//
//  Created by Heaton on 2018/1/22.
//  Copyright © 2019年 WangMingDeveloper. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class MPMediaItem;

typedef NS_ENUM(NSInteger, MusicSourceType) {
    MusicSourceTypeITunes = 0,// 本地音乐库
    MusicSourceTypeBundle = 1 // app自带音乐库
};



@interface MusicModel : NSObject
@property(nonatomic,copy)   NSString *musicName;// 音乐名称
@property(nonatomic,copy)   NSURL    *url;// 播放地址
@property(nonatomic,copy)   NSString *artist;// 歌手
@property(nonatomic,copy)   NSString *albumName;//专辑名
@property(nonatomic,copy)   NSString *fileSize;//文件大小
@property(nonatomic,copy)   NSString *voiceStyle;//音质类型
@property(nonatomic,copy)   NSString *fileStyle;//文件类型
@property(nonatomic,copy)   NSString *creatDate;//创建日期
@property(nonatomic,copy)   NSString *savePath; //存储路径
@property(nonatomic,strong) UIImage  *musicImage;// 专辑图片

@property(nonatomic,assign) NSTimeInterval  totalTime;// 时长
@property(nonatomic,assign) NSInteger       playCount;// 播放次数
@property(nonatomic,assign) NSInteger       sortIndex;
@property(nonatomic,assign) NSInteger       persistentID;// 音乐ID,ipod音乐库每首音乐的id
@property(nonatomic,assign) MusicSourceType sourceType;// 文件来源
@property(nonatomic,assign) BOOL playing;// 是否正在播放
+ (instancetype)musicWithMediaItem:(MPMediaItem *)mediaItem;
+ (instancetype)musicWithFilepath:(NSString *)filePath;
@end
