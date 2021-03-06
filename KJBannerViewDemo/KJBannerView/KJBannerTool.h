//
//  KJBannerTool.h
//  KJBannerViewDemo
//
//  Created by 杨科军 on 2019/7/30.
//  Copyright © 2019 杨科军. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
#define KJBannerLoadImages [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/KJLoadImages"];
typedef NS_ENUM(NSInteger, KJBannerImageType) {
    KJBannerImageTypeUnknown = 0, /// 未知
    KJBannerImageTypeJpeg    = 1, /// jpg
    KJBannerImageTypePng     = 2, /// png
    KJBannerImageTypeGif     = 3, /// gif
    KJBannerImageTypeTiff    = 4, /// tiff
    KJBannerImageTypeWebp    = 5, /// webp
};
/// 图片的几种类型
typedef NS_ENUM(NSInteger, KJBannerImageInfoType) {
    KJBannerImageInfoTypeLocality, /// 本地图片
    KJBannerImageInfoTypeNetIamge, /// 网络图片
    KJBannerImageInfoTypeGIFImage, /// 网络GIF图片
};
/// 滚动方法
typedef NS_ENUM(NSInteger, KJBannerViewRollDirectionType) {
    KJBannerViewRollDirectionTypeRightToLeft = 0, /// 默认，从右往左
    KJBannerViewRollDirectionTypeLeftToRight,    /// 从左往右
};
/// 图片的几种类型
typedef NS_ENUM(NSInteger, KJBannerViewImageType) {
    KJBannerViewImageTypeMix = 0,  /// 混合，本地图片、网络图片、网络GIF
    KJBannerViewImageTypeGIFAndNet,/// 网络GIF图片和网络图片混合
    KJBannerViewImageTypeLocality, /// 本地图片
    KJBannerViewImageTypeNetIamge, /// 网络图片
    KJBannerViewImageTypeGIFImage, /// 网络GIF图片
};
@interface KJBannerDatasInfo : NSObject
@property (nonatomic,strong) NSString *imageUrl;
@property (nonatomic,assign) KJBannerImageInfoType type;
@property (nonatomic,strong) UIImage *image;
@property (nonatomic,assign) NSInteger superType;
@end

@interface KJBannerTool : NSObject

/// 存放数据
@property(nonatomic,strong) NSArray *imageTemps;

/* 单例 */
+ (instancetype)sharedInstance;

/** 判断该字符串是不是一个有效的URL */
+ (BOOL)kj_bannerValidUrl:(NSString*)url;

/** 根据图片名 判断是否是gif图 */
+ (BOOL)kj_bannerIsGifImageWithImageName:(NSString*)imageName;

/** 根据图片url 判断是否是gif图 */
+ (BOOL)kj_bannerIsGifWithURL:(id)url;

/** 根据image的data 判断图片类型
 @param data 图片data
 @return 图片类型(png、jpg...)
 */
+ (KJBannerImageType)contentTypeWithImageData:(NSData*)data;

/// 判断是网络图片还是本地
+ (BOOL)kj_bannerImageWithImageUrl:(NSString*)imageUrl;

/// 播放网络GIF  
+ (NSTimeInterval)kj_bannerPlayGifWithImageView:(UIImageView*)imageView URL:(id)url;

// 得到Gif
+ (UIImage*)kj_bannerGetImageWithURL:(id)url;

/// 保存gif在本地
//+ (void)kj_bannerSaveWithImage:(UIImage*)image URL:(id)url;

/// 从 File 当中获取Gif文件
//+ (UIImage*)kj_bannerGetImageInFileWithURL:(id)url;

/// md5加密
+ (NSString*)kj_bannerMD5WithString:(NSString*)string;

@end

NS_ASSUME_NONNULL_END
