/**
* FaceBeautyInterfaceWin.h
*
* Interface of FaceBeauty SDK for Windows
* 
* Created by FaceBeauty on 2025/07/02.
* Copyright © 2025 TexeJoy Tech. All rights reserved. 
*/

#ifndef FACE_BEAUTY_INTERFACE_WIN_H
#define FACE_BEAUTY_INTERFACE_WIN_H

#include <Windows.h>
#include <string>

namespace FB {

#ifdef _WIN32
#define FB_API extern "C" __declspec(dllexport)
#endif

	/**
	 * 鉴权状态码
	 */
	enum FB_W_AuthStatusCode {
		FB_W_INIT_FREE_VERSION = 3,    // 初始化成功，免费证书
		FB_W_INIT_TEST = 2,    // 初始化成功，正式证书
		FB_W_INIT_OK = 1,    // 初始化成功，测试证书
		FB_W_INIT_NONE = 0,    // 未初始化
		FB_W_INIT_INVALID_LICENSE = -1,   // 无效证书
		FB_W_INIT_INVALID_PACKAGE = -2,   // 无效包名
		FB_W_INIT_INVALID_APP_NAME = -3,   // 无效应用名称
		FB_W_INIT_OVERDUE_LICENSE = -4,   // 过期证书
		FB_W_INIT_INVALID_PERMISSION = -5,   // 无效路径
		FB_W_INIT_INVALID_MODEL = -6,   // 无效模型文件
		FB_W_INIT_INEFFECTIVE_LICENSE = -7,   // 失效证书
		FB_W_INIT_VERSION_TOO_LOW = -8,   // 版本号过低
	};

	/**
	 * 美肤类型枚举
	 */
	enum FB_W_BeautyTypes {
		FB_W_BeautySkinWhitening = 0, //!< 美白，0~100，0为无效果
		FB_W_BeautyClearSmoothing = 1, //!< 精细磨皮，0~100，0为无效果
		FB_W_BeautySkinRosiness = 2, //!< 红润，0~100，0为无效果
		FB_W_BeautyImageSharpness = 3, //!< 锐化，0~100，0为无效果
		FB_W_BeautyImageBrightness = 4, //!< 亮度，-50~50，0为无效果
		FB_W_BeautyDarkCircleLessening = 5, //!< 去黑眼圈，0~100，0为无效果
		FB_W_BeautyNasolabialLessening = 6,  //!< 去法令纹，0~100，0为无效果
		FB_W_BeautyToothWhitening = 7, // 美牙，0～100，0为无效果
		FB_W_BeautyEyeBrightening = 8, // 亮眼，0～100，0为无效果
		FB_W_BeautyWhiteBalance = 9, // 白平衡，-50-50，0为无效果
		FB_W_BeautyImageClarity = 10, // 清晰，0-100，0为无效果
		FB_W_BeautyFaceContouring = 11 // 五官立体，0-100，0为无效果
	};

	/**
	 * 美型类型枚举
	 */
	enum FB_W_ReshapeTypes {
		//! 眼睛
		FB_W_HTReshapeEyeEnlarging = 10, //!< 大眼，0-100，0为无效果
		FB_W_ReshapeEyeRounding = 11, //!< 圆眼，0-100，0为无效果
		FB_W_ReshapeEyeSpaceTrimming = 12, //!< 眼间距，-50-50， 0为无效果
		FB_W_ReshapeEyeCornerTrimming = 13, //!< 眼睛角度，-50-50， 0为无效果
		FB_W_ReshapeEyeCornerEnlarging = 14, //!< 开眼角，0-100， 0为无效果
		//! 脸廓
		FB_W_ReshapeCheekThinning = 20, //!< 瘦脸，0-100，0为无效果
		FB_W_ReshapeCheekVShaping = 21, //!< V脸，0-100，0为无效果
		FB_W_ReshapeCheekNarrowing = 22, //!< 窄脸，0-100，0为无效果
		FB_W_ReshapeCheekboneThinning = 23, //!< 瘦颧骨，0-100，0为无效果
		FB_W_ReshapeJawboneThinning = 24, //!< 瘦下颌骨，0-100，0为无效果
		FB_W_ReshapeTempleEnlarging = 25, //!< 丰太阳穴，0-100，0为无效果
		FB_W_ReshapeHeadLessening = 26, //!< 小头，0-100，0为无效果
		FB_W_ReshapeFaceLessening = 27, //!< 小脸，0-100，0为无效果
		FB_W_ReshapeCheekShortening = 28, //!< 短脸，0-100，0为无效果
		//! 鼻部
		FB_W_ReshapeNoseEnlarging = 30, //!< 长鼻
		FB_W_ReshapeNoseThinning = 31, //!< 瘦鼻，0-100，0为无效果
		FB_W_ReshapeNoseApexLessening = 32, //!< 鼻头，0-100，0为无效果
		FB_W_ReshapeNoseRootEnlarging = 33, //!< 山根，0-100，0为无效果
		//! 嘴部
		FB_W_ReshapeMouthTrimming = 40, //!< 嘴型，-50-50， 0为无效果
		FB_W_ReshapeMouthSmiling = 41, //!< 微笑嘴角，0-100，0为无效果
		//! 其它
		FB_W_ReshapeChinTrimming = 0,  //!< 下巴，-50-50， 0为无效果
		FB_W_ReshapeForeheadTrimming = 1,  //!< 发际线，-50-50， 0为无效果
		FB_W_ReshapePhiltrumTrimming = 2   //!< 缩人中，-50-50， 0为无效果
	};

	/**
	 * 美发类型枚举
	 */
	enum FB_W_HairTypes {
		FB_W_HairTypeNone = 0,  //!< 无美发效果
		FB_W_HairType1 = 1,  //!< 美发类型1，FaceBeauty UI显示名称为"神秘紫"
		FB_W_HairType2 = 2,  //!< 美发类型2，FaceBeauty UI显示名称为"巧克力"
		FB_W_HairType3 = 3,  //!< 美发类型3，FaceBeauty UI显示名称为"青木棕"
		FB_W_HairType4 = 4,  //!< 美发类型4，FaceBeauty UI显示名称为"焦糖棕"
		FB_W_HairType5 = 5,  //!< 美发类型5，FaceBeauty UI显示名称为"落日橘"
		FB_W_HairType6 = 6,  //!< 美发类型6，FaceBeauty UI显示名称为"复古玫瑰"
		FB_W_HairType7 = 7,  //!< 美发类型7，FaceBeauty UI显示名称为"深玫瑰"
		FB_W_HairType8 = 8,  //!< 美发类型8，FaceBeauty UI显示名称为"雾霾香芋"
		FB_W_HairType9 = 9,  //!< 美发类型9，FaceBeauty UI显示名称为"孔雀蓝"
		FB_W_HairType10 = 10, //!< 美发类型10，FaceBeauty UI显示名称为"雾霾蓝灰"
		FB_W_HairType11 = 11, //!< 美发类型11，FaceBeauty UI显示名称为"亚麻灰棕"
		FB_W_HairType12 = 12  //!< 美发类型12，FaceBeauty UI显示名称为"亚麻浅灰"
	};

	/**
	 * 滤镜类型枚举
	 *
	 * 滤镜类型分为风格滤镜，特效滤镜，哈哈镜
	 */
	enum FB_W_FilterTypes {
		FB_W_FilterBeauty = 0, //!< 风格滤镜
		FB_W_FilterEffect = 1, //!< 特效滤镜
		FB_W_FilterFunny = 2  //!< 哈哈镜
	};

	/**
	 * AR道具类型枚举
	 *
	 * AR道具类型目前支持2D贴纸，面具，礼物，水印
	 */
	enum FB_W_ARItemTypes {
		FB_W_ItemSticker = 0, //!< 2D贴纸
		FB_W_ItemMask = 1, //!< 面具
		FB_W_ItemGift = 2, //!< 礼物
		FB_W_ItemWatermark = 3  //!< 水印
	};

	/**
	 * 推荐妆容推荐类型枚举
	 * 3.0版本后，将风格推荐效果改为妆容推荐；
	 *
	 * 在调用妆容推荐设置接口时，设置类型
	 */
	enum FB_W_StyleTypes {
		FB_W_StyleTypeNone = 0,  //!< 无，FaceBeauty UI显示名称为"无"
		FB_W_StyleTypeOne = 1,  //!< 妆容一，FaceBeauty UI显示名称为"清纯白花"
		FB_W_StyleTypeTwo = 2,  //!< 妆容二，FaceBeauty UI显示名称为"狐系美人"
		FB_W_StyleTypeThree = 3,  //!< 妆容三，FaceBeauty UI显示名称为"清甜妆"
		FB_W_StyleTypeFour = 4,  //!< 妆容四，FaceBeauty UI显示名称为"白露"
		FB_W_StyleTypeFive = 5,  //!< 妆容五，FaceBeauty UI显示名称为"冷调"
		FB_W_StyleTypeSix = 6,  //!< 妆容六，FaceBeauty UI显示名称为"元气少女"
		FB_W_StyleTypeSeven = 7,  //!< 妆容七，FaceBeauty UI显示名称为"女团"
		FB_W_StyleTypeEight = 8  //!< 妆容八，FaceBeauty UI显示名称为"纯欲妆"
	};

	/**
	 * 美妆类型枚举
	 *
	 * 美妆类型分为口红、眉毛，腮红、眼影、眼线、睫毛、美瞳
	 */
	enum FB_W_MakeupTypes {
		FB_W_MakeupLipstick = 0, //!< 口红
		FB_W_MakeupEyebrow = 1, //!< 眉毛
		FB_W_MakeupBlush = 2,  //!< 腮红
		FB_W_MakeupEyeshadow = 3, //!< 眼影
		FB_W_MakeupEyeline = 4, //!< 眼线
		FB_W_MakeupEyelash = 5, //!< 睫毛
		FB_W_MakeupPupils = 6 //!< 美瞳
	};

	/**
	 * 美体类型枚举
	 *
	 * 美体类型分为长腿、瘦身
	 */
	enum FB_W_BodyBeautyTypes {
		FB_W_BodyBeautyLegSlimming = 0, //!< 长腿
		FB_W_BodyBeautyBodyThinning = 1, //!< 瘦身
		FB_W_BodyBeautyWaistSlimming = 2, //!< 细腰
		FB_W_BodyBeautyShoulderSlimming = 3, //!< 美肩
		FB_W_BodyBeautyHipTrimming = 4, //!< 修胯
		FB_W_BodyBeautyThighThinning = 5, //!< 瘦大腿
		FB_W_BodyBeautyNeckSlimming = 6, //!< 天鹅颈
		FB_W_BodyBeautyChestEnlarging = 7 //!< 丰胸

	};

	/**
	 * 视频帧格式
	 *
	 * 支持对RGB、RGBA、BGR、BGRA、NV12、NV21、I420格式的视频帧进行渲染
	 */
	enum FB_W_FormatEnum {
		FB_W_FormatRGB = 0, //!< RGB
		FB_W_FormatRGBA = 1, //!< RGBA
		FB_W_FormatBGR = 2, //!< BGR
		FB_W_FormatBGRA = 3, //!< BGRA
		FB_W_FormatNV12 = 4, //!< NV12
		FB_W_FormatNV21 = 5, //!< NV21
		FB_W_FormatI420 = 6  //!< I420
	};

	/**
	 * 视频帧朝向
	 *
	 */
	enum FB_W_RotationEnum {
		FB_W_RotationClockwise0 = 0,
		FB_W_RotationClockwise90 = 90,
		FB_W_RotationClockwise180 = 180,
		FB_W_RotationClockwise270 = 270
	};

	enum FB_W_AITypes {
		FB_W_AIFace106				= 0,
		FB_W_AIFace278				= 1,
		FB_W_AIHairParser			= 2,
		FB_W_AIPortraitMatting   = 3,
		FB_W_AIHand					= 4,
		FB_W_AIPose						= 5
	};

	/**
	 * @brief 设置鉴权相关节点
	 * 
	 * @param node 节点名称，默认"cn"，国内节点
	 *							"sg"，海外节点-新加坡
	 */
	void setAuthNetworkNode(LPCSTR node);

	/**
	 * @brief 虹图人像人体特效系列SDK网络鉴权接口，用于初始化SDK
	 * 
	 * 	@param license 证书文本
	 *	@param resDir 资源路径
	 * 
	 * @return 鉴权返回值，@see FB_W_AuthStatusCode 说明
	 */
	FB_API int initFaceBeautyOnline(LPCSTR appId, LPCSTR resDir);

	/**
	* authorizeSDK 鉴权接口，用于初始化SDK
	* 
	* @param license 证书文本
	* @param resDir 资源路径
	* 
	* @return 鉴权返回值，@see FB_W_AuthStatusCode 说明
	*/
	FB_API int initFaceBeautyOffline(LPCSTR license, LPCSTR resDir);

	/**
	* authOffline 鉴权接口，用于SDK鉴权
	*
	* @param license 证书文本
	* @param resDir 资源路径
	*
	* @return 鉴权返回值，@see FB_W_AuthStatusCode 说明
	*/
	FB_API int authOffline(LPCSTR license, LPCSTR resDir);

	/**
	* setRenderEnable 渲染开关
	* 
	* @param enable 开关
	*/
	FB_API void setRenderEnable(bool enable);

	/**
	* initTextureRenderer 初始化纹理渲染，PC端暂未开放
	* 
	* @param width 纹理宽度
	* @param height 纹理高度
	* @param rotation 纹理朝向（即顺时针旋转至朝向为正的角度）
	* @param isMirror 纹理是否有镜像
	* @param maxFaces 最大检测人脸数量（影响性能，区间为[1, 5]）
	* 
	* @return 初始化结果
	*/
	FB_API bool initTextureRenderer(int width, int height, int rotation, bool isMirror, int maxFaces);

	/**
	* processTexture 纹理渲染接口，PC端暂未开放
	* 
	* @param textureId 纹理ID
	* 
	* @return 渲染后的纹理ID
	*/
	FB_API int processTexture(int textureId);

	/**
	* releaseTextureRenderer 释放纹理渲染资源
	*/
	FB_API void releaseTextureRenderer();

	/**
	* initBufferRenderer 初始化视频帧渲染
	*
	* @param format 视频帧格式
	* @param width 视频帧宽度
	* @param height 视频帧高度
	* @param rotation 视频帧朝向（即顺时针旋转至朝向为正的角度）
	* @param isMirror 视频帧是否有镜像
	* @param maxFaces 最大检测人脸数量（影响性能，区间为[1, 5]）
	*
	* @return 初始化结果
	*/
	FB_API bool initBufferRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

	/**
	* processBuffer 视频帧渲染接口
	*
	* @param buffer 视频帧数据
	*
	*/
	FB_API void processBuffer(unsigned char* buffer);

	/**
	* releaseBufferRenderer 释放视频帧渲染资源
	*/
	FB_API void releaseBufferRenderer();

	/**
	* initImageRenderer 初始化图片渲染
	*
	* @param format 图片格式
	* @param width 图片宽度
	* @param height 图片高度
	* @param rotation 图片朝向（即顺时针旋转至朝向为正的角度）
	* @param isMirror 图片是否有镜像
	* @param maxFaces 最大检测人脸数量（影响性能，建议区间为[1, 5]）
	*
	* @return 初始化结果
	*/
	FB_API bool initImageRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

	/**
	* processImage 图片渲染接口
	*
	* @param buffer 图片数据
	*
	*/
	FB_API void processImage(unsigned char* buffer);

	/**
	* releaseImageRenderer 释放图片渲染资源
	*/
	FB_API void releaseImageRenderer();

	/**
	* setBeauty 设置美肤
	* 
	* @param type 特效类别
	* @param value 特效参数
	*/
	FB_API void setBeauty(int type, int value);

	/**
	* setReshape 设置美型
	*
	* @param type 特效类别
	* @param value 特效参数
	*/
	FB_API void setReshape(int type, int value);

	/**
	* setHairStyling 设置美发
	*
	* @param type 特效类别
	* @param value 特效参数
	*/
	FB_API void setHairStyling(int type, int value);

	/**
	* setFilter 设置滤镜
	* 
	* @param type 滤镜类别
	* @param name 滤镜名称
	*/
	//extern "C" FB_API void setFilter(int type, std::string name);

	/**
	* setFilter 设置滤镜强度
	*
	* @param type 滤镜类别
	* @param name 滤镜名称
	* @param value 滤镜强度，仅对风格（美颜）滤镜生效
	*/
	FB_API void setFilter(int type, LPCSTR name, int value);

	/**
	* setStyle 设置妆容推荐
	*
	* @param name 风格名称
	* @param value 风格参数，参数范围0-100，默认为100
	*/
	FB_API void setStyle(LPCSTR name, int vlaue);

	/**
	 * @brief 获取AR道具素材网络路径
	 * 
	 * @param type AR道具类型
	 * @return 返回AR道具素材网络路径
	 */
	FB_API LPCSTR getARItemUrlBy(int type);

	/**
	* setARItem 设置AR道具
	* 
	* @param type 道具类别
	* @param name 道具名称
	*/
	FB_API void setARItem(int type, LPCSTR name);

	/**
	 * setWatermarkParam 设置AR道具-水印参数，v2.0后启用
	 * 水印参数为水印图像在手机屏幕中相对视频帧的四个顶点的坐标值，配合外部操作框获取
	 *
	 * @param x1 左上角横坐标值
	 * @param y1 左上角纵坐标值
	 * @param x2 左下角横坐标值
	 * @param y2 左下角纵坐标值
	 * @param x3 右下角横坐标值
	 * @param y3 右下角纵坐标值
	 * @param x4 右下角横坐标值
	 * @param y4 右下角纵坐标值
	 */
	FB_API void setWatermarkParam(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

	/**
	 * setAISegmentation 设置AI抠图特效
	 *
	 * @param name AI抠图效果名称，如果传null或者空字符，则取消人像抠图效果
	 */
	FB_API void setAISegmentation(LPCSTR name);

	/**
	 * setChromaKeyingScene 设置色（键）值抠图特效场景
	 *
	 * @param name 场景名称
	 */
	FB_API void setChromaKeyingScene(LPCSTR name);

	/**
	 * setChromaKeyingCurtain 设置色（键）值抠图特效幕布颜色
	 *
	 * @param color 幕布颜色，传字符串类型16进制色值
	 *        目前仅支持绿幕 (#00ff00) 蓝幕(#0000ff)  白幕(#ffffff)三种幕布颜色和透明幕布，默认为绿幕
	 */
	FB_API void setChromaKeyingCurtain(LPCSTR color);

	/**
	 * setChromaKeyingParams 设置色（键）值抠图特效调节参数
	 *
	 * @param type 参数类型，0-相似度；1-平滑度；2-祛色度；3-精确度
	 * @param value 调节参数，参数范围0-100
	 */
	FB_API void setChromaKeyingParams(int type, int value);

	/**
	 * setGesture 设置手势识别特效
	 *
	 * @param name 手势识别效果名称，如果传null或者空字符，则取消手势识别效果
	 */
	FB_API void setGesture(LPCSTR name);

	/**
	 * setMakeup 设置美妆特效
	 *
	 * @param type 美妆类别
	 * @param name 美妆名称
	 * @param value 美妆参数
	 */
	FB_API void setMakeup(int type, LPCSTR key, LPCSTR value);

	/**
	 * setBodyBeauty 设置美体特效
	 *
	 * @param type 美体类别
	 * @param value 美体名称
	 */
	FB_API void setBodyBeauty(int type, int value);

	/**
	 * loadAIProcessor 加载AI驱动
	 *
	 * @param type AI驱动类型
	 * 
	 * @return AI驱动是否加载成功
	 */
	FB_API bool loadAIProcessor(int type);

	/**
	 * removeAIProcessor 卸载AI驱动
	 *
	 * @param type AI驱动类型
	 */
	FB_API void removeAIProcessor(int type);

	/**
	 * isTracking 判断是否检测到人脸
	 *
	 * @return 检测到的人脸个数，返回 0 代表没有检测到人脸
	 */
	FB_API int isTracking();

	/**
	 * 判断是否检测到全身人体
	 *
	 * @return 检测到的全身人体个数，返回 0 代表没有检测到全身人体
	 */
	FB_API int isFullBody();

	/**
	 * 设置人脸检测器类型，默认为0
	 *
	 * @param type 人脸检测器类型
	 */
	FB_API void setFaceDetectorType(int type);

	/**
	 * setExtremeLimitEnable 设置参数极值限制开关，默认为开
	 */
	FB_API void setExtremeLimitEnable(bool enable);

	/**
	 * 设置人脸检测算法CPU多核运算开关，默认为false
	 *
	 * @param enable 开关，默认为false
	 */
	FB_API void setFaceDetecionCPUPowersaveEnable(bool enable);

	/**
	 * 设置人脸检测距离级别，默认为1级，即能识别较近距离
	 * 此接口生效的前置条件是人脸检测算法Base模式为开启状态
	 *
	 * @param level 人脸检测距离级别，默认为1级
	 */
	FB_API void setFaceDetectionDistanceLevel(int level);

	/**
	 * setPortraitMattingUseGPUEnable 设置人像分割算法使用GPU，默认为关
	 */
	FB_API void setPortraitMattingUseGPUEnable(bool enable);

	/**
	 * setBodyDetectUseGPUEnable 设置人体检测算法使用GPU，默认为关
	 */
	FB_API void setBodyDetectUseGPUEnable(bool enable);

	/**
	 * setHairMattingUseGPUEnable 设置头发分割算法使用GPU，默认为关
	 */
	FB_API void setHairMattingUseGPUEnable(bool enable);

	/**
	 * setHandDetectUseGPUEnable 设置人手检测算法使用GPU，默认为关
	 */
	FB_API void setHandDetectUseGPUEnable(bool enable);

	/**
	 * setTransparencyRenderEnable 部分透明图渲染支持开关
	 * 
	 * @param enable 开启为true，关闭为false，默认关闭
	 */
	FB_API void setTransparencyRenderEnable(bool enable);

	/**
	 * setPerformancePriorityEnable 性能模式开关
	 * 
	 * @param enable 开启为true，关闭为false，默认关闭 
	 */
	FB_API void setPerformancePriorityEnable(bool enable);

	/**
	 * getVersionCode 获取当前 SDK 版本号
	 *
	 * @return 版本号
	 */
	FB_API LPCSTR getVersionCode();

	/**
	 * getVersion 获取当前 SDK 版本信息
	 *
	 * @return 版本信息
	 */
	FB_API LPCSTR getVersion();
}

#endif
