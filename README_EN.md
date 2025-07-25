[简体中文](README.md)| English | [日本語](README_JP.md)

# **FaceBeauty**

<br/>

## **Quick Integration**
### **Windows**
#### **1. Prerequisites**
- It is recommended to use VS2019 or a higher version
- For license, FaceBeautyBundle, and ThirdParty, please contact the business department.

#### **2. Installation**
**Example Demo**

- Place the relevant files of **FaceBeautyPC** in the ThirdParty and FaceBeautyBundle folders respectively.
- The **target file name** needs to be changed to the name registered with the business department.

**File Composition**

- **FaceBeautyBundle** Resource package
- **FaceBeauty** SDK library
    - include
    - lib
        - win64
            - Release
                - FaceBeauty.lib
                - FaceBeauty.dll
- **DLL** Other dependent libraries used
    - Release
        - TNN.dll
    - libcrypto.dll
    - libcurl.dll
    - libssl.dll
    - ncnn.dll
    - onnxruntime.dll
- **common**
    - glad.c OpenGL dependency file
    - gl3w.c OpenGL dependency file

**Other Recommended Libraries**

- opencv 

#### **3. Interfaces**
- For interface descriptions, you can also refer to the header file
```c++
/**
 * Enum for skin beautification types
 */
enum FB_W_BeautyTypes {
    FB_W_BeautySkinWhitening = 0, //!< Skin whitening, range 0~100, 0 means no effect
    FB_W_BeautyClearSmoothing = 1, //!< Fine skin smoothing, range 0~100, 0 means no effect
    FB_W_BeautySkinRosiness = 2, //!< Skin rosiness, range 0~100, 0 means no effect
    FB_W_BeautyImageSharpness = 3, //!< Image sharpness, range 0~100, 0 means no effect
    FB_W_BeautyImageBrightness = 4, //!< Image brightness, range -50~50, 0 means no effect
    FB_W_BeautyDarkCircleLessening = 5, //!< Dark circle reduction, range 0~100, 0 means no effect
    FB_W_BeautyNasolabialLessening = 6,  //!< Nasolabial fold reduction, range 0~100, 0 means no effect
    FB_W_BeautyToothWhitening = 7, // Tooth whitening, range 0～100, 0 means no effect
    FB_W_BeautyEyeBrightening = 8, // Eye brightening, range 0～100, 0 means no effect
    FB_W_BeautyWhiteBalance = 9, // White balance, range -50-50, 0 means no effect
    FB_W_BeautyImageClarity = 10, // Image clarity, range 0-100, 0 means no effect
    FB_W_BeautyFaceContouring = 11 // Facial contouring, range 0-100, 0 means no effect
};

/**
 *  Enum for face reshaping types
 */
enum FB_W_ReshapeTypes {
    //! Eyes
    FB_W_HTReshapeEyeEnlarging = 10, //!< Eye enlargement, range 0-100, 0 means no effect
    FB_W_ReshapeEyeRounding = 11, //!< Eye rounding, range 0-100, 0 means no effect
    FB_W_ReshapeEyeSpaceTrimming = 12, //!< Eye spacing adjustment, range -50-50, 0 means no effect
    FB_W_ReshapeEyeCornerTrimming = 13, //!< Eye corner adjustment, range -50-50, 0 means no effect
    FB_W_ReshapeEyeCornerEnlarging = 14, //!< Eye corner enlargement, range 0-100, 0 means no effect
    //! Face contour
    FB_W_ReshapeCheekThinning = 20, //!< Cheek thinning, range 0-100, 0 means no effect
    FB_W_ReshapeCheekVShaping = 21, //!< V-shaped face shaping, range 0-100, 0 means no effect
    FB_W_ReshapeCheekNarrowing = 22, //!< Face narrowing, range 0-100, 0 means no effect
    FB_W_ReshapeCheekboneThinning = 23, //!< Cheekbone thinning, range 0-100, 0 means no effect
    FB_W_ReshapeJawboneThinning = 24, //!< Jawbone thinning, range 0-100, 0 means no effect
    FB_W_ReshapeTempleEnlarging = 25, //!< Temple enlargement, range 0-100, 0 means no effect
    FB_W_ReshapeHeadLessening = 26, //!< Head size reduction, range 0-100, 0 means no effect
    FB_W_ReshapeFaceLessening = 27, //!< Face size reduction, range 0-100, 0 means no effect
    FB_W_ReshapeCheekShortening = 28, //!< Cheek shortening, range 0-100, 0 means no effect
    //! Nose
    FB_W_ReshapeNoseEnlarging = 30, //!< Nose lengthening
    FB_W_ReshapeNoseThinning = 31, //!< Nose thinning, range 0-100, 0 means no effect
    FB_W_ReshapeNoseApexLessening = 32, //!< Nose tip adjustment, range 0-100, 0 means no effect
    FB_W_ReshapeNoseRootEnlarging = 33, //!< Nasal bridge heightening, range 0-100, 0 means no effect
    //! Mouth
    FB_W_ReshapeMouthTrimming = 40, //!< Mouth shape adjustment, range -50-50, 0 means no effect
    FB_W_ReshapeMouthSmiling = 41, //!< Smiling mouth corner, range 0-100, 0 means no effect
    //! Others
    FB_W_ReshapeChinTrimming = 0,  //!< Chin adjustment, range -50-50, 0 means no effect
    FB_W_ReshapeForeheadTrimming = 1,  //!< Hairline adjustment, range -50-50, 0 means no effect
    FB_W_ReshapePhiltrumTrimming = 2   //!< Philtrum shortening, range -50-50, 0 means no effect
};

/**
 * Enum for filter types
 *
 * Filter types are divided into style filters, special effect filters, and distorting mirrors.
 */
enum FB_W_FilterTypes {
    FB_W_FilterBeauty = 0, //!< Style filters
    FB_W_FilterEffect = 1, //!< Special effect filters
    FB_W_FilterFunny = 2  //!< Distorting mirrors
};

/**
 * Enum for AR prop types
 *
 * Currently, AR prop types support 2D stickers, masks, gifts, and watermarks.
 */
enum FB_W_ARItemTypes {
    FB_W_ItemSticker = 0, //!< 2D stickers
    FB_W_ItemMask = 1, //!< Masks
    FB_W_ItemGift = 2, //!< Gifts
    FB_W_ItemWatermark = 3  //!< Watermarks
};

/**
 * Enum for body beautification types
 *
 * Body beautification types are divided into long legs and body slimming.
 */
enum FB_W_BodyBeautyTypes {
    FB_W_BodyBeautyLegSlimming = 0, //!< Long legs
    FB_W_BodyBeautyBodyThinning = 1, //!< Body slimming
    FB_W_BodyBeautyWaistSlimming = 2, //!< Waist slimming
    FB_W_BodyBeautyShoulderSlimming = 3, //!< Shoulder beautification
    FB_W_BodyBeautyHipTrimming = 4, //!< Hip adjustment
    FB_W_BodyBeautyThighThinning = 5, //!< Thigh slimming
    FB_W_BodyBeautyNeckSlimming = 6, //!< Swan neck
    FB_W_BodyBeautyChestEnlarging = 7 //!< Chest enlargement
};

/**
 * Enum for video frame formats
 *
 * Supports rendering video frames in RGB, RGBA, BGR, BGRA, NV12, NV21, and I420 formats.
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
 * Enum for video frame orientations
 *
 */
enum FB_W_RotationEnum {
    FB_W_RotationClockwise0 = 0,
    FB_W_RotationClockwise90 = 90,
    FB_W_RotationClockwise180 = 180,
    FB_W_RotationClockwise270 = 270
};

/**
* authorizeSDK Authentication interface for initializing the SDK
* 
* @param license License text
* @param resDir Resource path
* 
* @return Authentication return value, @see InitCode description
*		2 - Initialization successful, test license
*		1 - Initialization successful, formal license
*		0 - Not initialized
*		-1 - Invalid license
*		-2 - Invalid package name
*		-3 - Invalid application name
*		-4 - Expired license
*		-5 - Invalid path
*		-6 - Invalid model
*/
int authorizeSDK(const char* license, std::string resDir);

/**
* setRenderEnable Rendering switch
* 
* @param enable Switch
*/
void setRenderEnable(bool enable);

/**
* initTextureRenderer Initialize texture rendering, not available on PC for now
* 
* @param width Texture width
* @param height Texture height
* @param rotation Texture orientation (i.e., the clockwise rotation angle to make the orientation positive)
* @param isMirror Whether the texture is mirrored
* @param maxFaces Maximum number of detected faces (affects performance, range [1, 5])
* 
* @return Initialization result
*/
bool initTextureRenderer(int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processTexture Texture rendering interface, not available on PC for now
* 
* @param textureId Texture ID
* 
* @return Rendered texture ID
*/
int processTexture(int textureId);

/**
* releaseTextureRenderer Release texture rendering resources
*/
void releaseTextureRenderer();

/**
* initBufferRenderer Initialize video frame rendering
*
* @param format Video frame format
* @param width Video frame width
* @param height Video frame height
* @param rotation Video frame orientation (i.e., the clockwise rotation angle to make the orientation positive)
* @param isMirror Whether the video frame is mirrored
* @param maxFaces Maximum number of detected faces (affects performance, range [1, 5])
*
* @return Initialization result
*/
bool initBufferRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processBuffer Video frame rendering interface
*
* @param buffer Video frame data
*
*/
void processBuffer(unsigned char* buffer);

/**
* releaseBufferRenderer Release video frame rendering resources
*/
void releaseBufferRenderer();

/**
* initImageRenderer Initialize image rendering
*
* @param format Image format
* @param width Image width
* @param height Image height
* @param rotation Image orientation (i.e., the clockwise rotation angle to make the orientation positive)
* @param isMirror Whether the image is mirrored
* @param maxFaces Maximum number of detected faces (affects performance, range [1, 5])
*
* @return Initialization result
*/
bool initImageRenderer(int format, int width, int height, int rotation, bool isMirror, int maxFaces);

/**
* processImage Image rendering interface
*
* @param buffer Image data
*
*/
void processImage(unsigned char* buffer);

/**
* releaseImageRenderer Release image rendering resources
*/
void releaseImageRenderer();

/**
* setBeauty Set skin beautification
* 
* @param type Special effect category, @see FB_W_BeautyTypes
* @param value Special effect parameter
*/
void setBeauty(int type, int value);

/**
* setReshape Set face reshaping
*
* @param type Special effect category, @see FB_W_ReshapeTypes
* @param value Special effect parameter
*/
void setReshape(int type, int value);

/**
* setFilter Set filters
* 
* @param type Filter category, @see FB_W_FilterTypes
* @param name Filter name
*/
void setFilter(int type, std::string name);

/**
* setARItem Set AR props
* 
* @param type Prop category, @see FB_W_ARItemTypes
* @param name Prop name
*/
void setARItem(int type, std::string name);

/**
 * setWatermarkParam Set AR prop - watermark parameters, enabled after v2.0
 * The watermark parameters are the coordinate values of the four vertices of the watermark image relative to the video frame on the mobile screen, obtained in conjunction with the external operation frame.
 *
 * @param x1 X-coordinate of the top-left vertex
 * @param y1 Y-coordinate of the top-left vertex
 * @param x2 X-coordinate of the bottom-left vertex
 * @param y2 Y-coordinate of the bottom-left vertex
 * @param x3 X-coordinate of the bottom-right vertex
 * @param y3 Y-coordinate of the bottom-right vertex
 * @param x4 X-coordinate of the top-right vertex
 * @param y4 Y-coordinate of the top-right vertex
 */
void setWatermarkParam(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

/**
 * setBodyBeauty Set body beautification special effects
 *
 * @param type Body beautification category, @see FB_W_BodyBeautyTypes
 * @param value Body beautification parameter
 */
void setBodyBeauty(int type, int value);

/**
 * isTracking Determine whether a face is detected
 *
 * @return Number of detected faces, returns 0 if no face is detected
 */
int isTracking();

/**
 * setExtremeLimitEnable Set the switch for parameter extreme value limit, enabled by default
 */
void setExtremeLimitEnable(bool enable);

/**
 * getVersionString Get the current SDK version information
 *
 * @return Version information
 */
std::string getVersionString();
```

#### **4.  **Usage****
****Initialization****

- Call the initialization interface
```c++
/**
* Online authentication initialization method
* Add APPID in license.h
*/
FB::initFaceBeautyOnline(appId.c_str(), ".\\..\\FaceBeautyBundle");
```

****Rendering****

- Call the rendering interface in the video frame callback
```c++
/**
* Video frame
*/
// Initialize the renderer
if (!isInitFaceBeauty) {
    isInitFaceBeauty = FB::initBufferRenderer(3, frame.cols, frame.rows, 0, false, 5);
}
// Set rendering special effects
FB::setBeauty(0, 100); //! Skin whitening
FB::setARItem(0, "ht_sticker_effect_angel"); //! Dynamic sticker
// Set other rendering effects

// Render
FB::processBuffer(frame.data);
```

**Destruction**

- When ending the rendering, call the corresponding release method according to the video format
```c++
FB::releaseBufferRenderer();
```
<br/>

----
