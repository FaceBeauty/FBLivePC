简体中文 | [English](README_EN.md) | [日本語](README_JP.md)

# **FaceBeauty**

<br/>

## **快速集成**
### **Windows**
#### **1. 前提条件**
- 建议使用VS2019及以上版本
- license、FaceBeautyBundle、ThirdParty，请联系商务获取

#### **2. 安装**
**示例Demo**
- **FaceBeautyPC** 相关文件分别放在ThirdParty和FaceBeautyBundle文件夹中
- **目标文件名**需更改为和商务备案的名称

**文件组成**
- **FaceBeautyBundle** 资源包
- **FaceBeauty** SDK库
    - include
    - lib
        - win64
            - Release
                - FaceBeauty.lib
                - FaceBeauty.dll
- **DLL** 使用到的其它依赖库
    - Release
        - TNN.dll
    - libcrypto.dll
    - libcurl.dll
    - libssl.dll
    - ncnn.dll
    - onnxruntime.dll
- **common**
    - glad.c OpenGL文件依赖文件
    - gl3w.c OpenGL文件依赖文件

**其它推荐库**
- opencv 

#### **3. 接口**
- 接口说明，也可以参考头文件
```c++
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

/**
* authorizeSDK 鉴权接口，用于初始化SDK
* 
* @param license 证书文本
* @param resDir 资源路径
* 
* @return 鉴权返回值，@see InitCode 说明
*		2 - 初始化成功，测试证书
*		1 - 初始化成功，正式证书
*		0 - 未初始化
*		-1 - 无效证书
*		-2 - 无效包名
*		-3 - 无效应用名
*		-4 - 过期证书
*		-5 - 无效路径
*		-6 - 无效模型
*/
int authorizeSDK(const char* license, std::string resDir);

/**
* setRenderEnable 渲染开关
* 
* @param enable 开关
*/
void setRenderEnable(bool enable);

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
bool initTextureRenderer(int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processTexture 纹理渲染接口，PC端暂未开放
* 
* @param textureId 纹理ID
* 
* @return 渲染后的纹理ID
*/
int processTexture(int textureId);

/**
* releaseTextureRenderer 释放纹理渲染资源
*/
void releaseTextureRenderer();

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
bool initBufferRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processBuffer 视频帧渲染接口
*
* @param buffer 视频帧数据
*
*/
void processBuffer(unsigned char* buffer);

/**
* releaseBufferRenderer 释放视频帧渲染资源
*/
void releaseBufferRenderer();

/**
* initImageRenderer 初始化图片渲染
*
* @param format 图片格式
* @param width 图片宽度
* @param height 图片高度
* @param rotation 图片朝向（即顺时针旋转至朝向为正的角度）
* @param isMirror 图片是否有镜像
* @param maxFaces 最大检测人脸数量（影响性能，区间为[1, 5]）
*
* @return 初始化结果
*/
bool initImageRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processImage 图片渲染接口
*
* @param buffer 图片数据
*
*/
void processImage(unsigned char* buffer);

/**
* releaseImageRenderer 释放图片渲染资源
*/
void releaseImageRenderer();

/**
* setBeauty 设置美肤
* 
* @param type 特效类别，@see FB_W_BeautyTypes
* @param value 特效参数
*/
void setBeauty(int type, int value);

/**
* setReshape 设置美型
*
* @param type 特效类别，@see FB_W_ReshapeTypes
* @param value 特效参数
*/
void setReshape(int type, int value);


/**
* setFilter 设置滤镜
* 
* @param type 滤镜类别，@see FB_W_FilterTypes
* @param name 滤镜名称
*/
void setFilter(int type, std::string name);

/**
* setARItem 设置AR道具
* 
* @param type 道具类别， @see FB_W_ARItemTypes
* @param name 道具名称
*/
void setARItem(int type, std::string name);

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
void setWatermarkParam(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

/**
 * setBodyBeauty 设置美体特效
 *
 * @param type 美体类别，@see FB_W_BodyBeautyTypes
 * @param value 美体名称
 */
void setBodyBeauty(int type, int value);

/**
 * isTracking 判断是否检测到人脸
 *
 * @return 检测到的人脸个数，返回 0 代表没有检测到人脸
 */
int isTracking();

/**
 * setExtremeLimitEnable 设置参数极值限制开关，默认为开
 */
void setExtremeLimitEnable(bool enable);

/**
 * getVersionString 获取当前 SDK 版本信息
 *
 * @return 版本信息
 */
std::string getVersionString();
```

#### **4. 使用**
**初始化**
- 调用初始化接口
```c++
/**
* 在线鉴权初始化方法
*/
FB::initFaceBeautyOnline(appId.c_str(), ".\\..\\FaceBeautyBundle");
```

**渲染**
- 在视频帧回调里调用渲染接口
```c++
/**
* 视频帧
*/
// 初始化渲染器
if (!isInitFaceBeauty) {
    isInitFaceBeauty = FB::initBufferRenderer(3, frame.cols, frame.rows, 0, false, 5);
}
// 渲染特效设置
FB::setBeauty(0, 100); //! 美白
FB::setARItem(0, "ht_sticker_effect_angel"); //！动态贴纸
// 其它渲染效果设置

// 渲染
FB::processBuffer(frame.data);

```

**销毁**
- 结束渲染时，需根据视频格式，调用对应的释放方法
```c++
FB::releaseBufferRenderer();
```
<br/>

----
