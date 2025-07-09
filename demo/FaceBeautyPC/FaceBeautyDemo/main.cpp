#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>
#include "FaceBeautyInterfaceWin.h"
#include <glfw3.h>
#include <glad/glad.h>
#include <tchar.h>
#include "license.h"
#include <iostream>

#define FB_VIDEO_API_TEST
//#define FB_IMAGE_API_TEST

#define LOG_TAG "FaceBeauty"
#define LOG_I(...) { fprintf(stdout,"%s%s",LOG_TAG," : "); fprintf(stdout,__VA_ARGS__); fprintf(stdout,"\n"); }
#define LOG_E(...) { fprintf(stderr,"%s%s",LOG_TAG," : "); fprintf(stderr,__VA_ARGS__); fprintf(stderr,"\n"); }

const int kFrameInterval = 1;

/**
* CurrentMillisecondTime
* get current millisecond time, to calculate execution time
*
* @return current millisecond time, double format
*/
double CurrentMillisecondTime() {
	return (double)GetTickCount64();
}

void DoFrameMirror(cv::Mat& image, bool is_mirror) {
	if (is_mirror) {
		cv::flip(image, image, 1);
	}
}

void DrawFrameInfo(cv::Mat& image) {
	cv::putText(image, "frame rate: " + std::to_string((int)(1000 / kFrameInterval)), cv::Point(30, 30), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0));

	cv::putText(image, "frame size: " + std::to_string(image.cols) + " " + std::to_string(image.rows), cv::Point(30, 60), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(255, 0, 0));
}

PIXELFORMATDESCRIPTOR pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),
	1u,
	PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_DRAW_TO_WINDOW,
	PFD_TYPE_RGBA,
	32u,
	0u, 0u, 0u, 0u, 0u, 0u,
	8u,
	0u,
	0u,
	0u, 0u, 0u, 0u,
	24u,
	8u,
	0u,
	PFD_MAIN_PLANE,
	0u,
	0u, 0u };

void InitOpenGL()
{

	HWND hw = CreateWindowExA(
		0, "EDIT", "", ES_READONLY,
		0, 0, 1, 1,
		NULL, NULL,
		GetModuleHandleA(NULL), NULL);
	HDC hgldc = GetDC(hw);
	int spf = ChoosePixelFormat(hgldc, &pfd);
	int ret = SetPixelFormat(hgldc, spf, &pfd);
	HGLRC hglrc = wglCreateContext(hgldc);
	wglMakeCurrent(hgldc, hglrc);
	printf("hw=%08x hgldc=%08x spf=%d ret=%d hglrc=%08x\n",
		hw, hgldc, spf, ret, hglrc);

	//Init GL and Window
}
//GLFWwindow* window;

int initStatus = 0;
void GetInitStatus(const int& status) {
	initStatus = status;
	LOG_I("FBffect init status: %d", initStatus);
}

void main() {
	InitOpenGL();
	//FB::setPortraitMattingUseGPUEnable(true);
	//FB::setHairMattingUseGPUEnable(true);
	//FB::setHandDetectUseGPUEnable(true);
	//int initStatus = FB::initFaceBeautyOffline(license_normal.c_str(), ".\\..\\FaceBeautyBundle");
	//FB::setAuthNetworkNode("sg");
	FB::initFaceBeautyOnline(appId.c_str(), ".\\..\\FaceBeautyBundle");

	//FB::setPerformancePriorityEnable(true);

	LOG_I("networkResUrl: %s", FB::getARItemUrlBy(0));

	// print opencv version string
	LOG_I("opencv version is : %s", cv::getVersionString().c_str());

	// init OpenGL

#ifdef FB_VIDEO_API_TEST
	cv::VideoCapture capture(0);
	//capture.set(cv::CAP_PROP_FPS, 30);
	//capture.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
	//capture.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
	bool isInitFaceBeauty = false;
	int i = 0;
	while (capture.isOpened()) {
		//glClear(GL_COLOR_BUFFER_BIT);
		//glClearColor(0.0f, 0.0f, 0.1f, 0.0f);

		cv::Mat frame;
		capture >> frame;

		if (frame.empty()) {
			break;
		}

		// process start

		cv::cvtColor(frame, frame, cv::COLOR_BGR2BGRA);
		if (!isInitFaceBeauty) {
			isInitFaceBeauty = FB::initBufferRenderer(FB::FB_W_FormatBGRA, frame.cols, frame.rows, 0, false, 5);
		}
		double st = CurrentMillisecondTime();

		FB::setBeauty(0, 100);
		FB::setBeauty(1, 100);
		FB::setBeauty(FB::FB_W_BeautyFaceContouring, 100);
		FB::setReshape(FB::FB_W_ReshapeCheekVShaping, 80);
		FB::setReshape(FB::FB_W_ReshapeCheekThinning, 80);

		FB::setARItem(0, "fb_sticker_effect_tuzi");

		FB::processBuffer(frame.data);
		double et = CurrentMillisecondTime();
		LOG_I("process cost time: %lf ms", et - st);

		cv::cvtColor(frame, frame, cv::COLOR_BGRA2BGR);
		// process end

		DoFrameMirror(frame, true);
		DrawFrameInfo(frame);

		const char* name = "Opencv Camera";
		cv::namedWindow(name, 1);
		cv::imshow(name, frame);
		cv::waitKey(kFrameInterval);
	}
#endif

#ifdef FB_IMAGE_API_TEST
	bool isInitFaceBeauty = false;

	cv::Mat image = cv::imread(".\\..\\resource\\image_test_02.jpeg");
	if (image.empty()) {                    // 检查图片对象是否是空数据
		std::cout << "Could not open or find the image" << std::endl;
		return;
	}

	double st = CurrentMillisecondTime();
	//cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);
	if (!isInitFBffect) {
		isInitFBEffect = FB::initImageRenderer(FB::FB_W_FormatBGR, image.cols, image.rows, 0, false, 20);
	}

	FB::setFaceDetectionDistanceLevel(4);
	FB::setBeauty(0, 100);
	FB::setBeauty(1, 100);
	//FB::setStyle(1);
	FB::setMakeup(0, "", 100);
	//FB::setFilter(0, "yuese");
	//FB::setBodyBeauty(0, 100);
	//FB::setBodyBeauty(1, 100);
	//FB::setARItem(FB::FB_W_ARItemTypes::FB_W_ItemMask, "ht_mask_fox");
	//FB::setARItem(0, "ht_sticker_effect_rabbit_bowknot");
	FB::processImage(image.data);

	//cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
	double et = CurrentMillisecondTime();
	LOG_I("process cost time: %lf ms", et - st);

	const char* name = "Opencv Image";
	cv::namedWindow(name, 1);
	cv::imshow(name, image);

	cv::waitKey(0);
#endif
}