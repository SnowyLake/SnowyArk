#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include<iostream>

#include<gl_camera.h>
//camera
extern GLCamera camera;

class CreateWindows
{
public:
	GLFWwindow* window;

	CreateWindows(unsigned int width, unsigned int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share, bool captureMouse);
	~CreateWindows();

	GLFWwindow* CreateMainWindow(GLFWmonitor* monitor, GLFWwindow* share, bool captureMouse);

	void SetCallback();
	void SetPerFrameTimeLogic();
	void ProcessInput();  

	unsigned int GetScrWidth();
	unsigned int GetScrHeight();
	std::string GetWindowTitle();

private:
	unsigned int scrWidth;
	unsigned int scrHeight;
	std::string windowTitle;

	//camera
	static float lastX;
	static float lastY;
	static bool firstMouse;
	//timing
	float deltaTime;	// time between current frame and last frame
	float lastTime;

	void GLFWInit();

	//framebuffer size callback function
	static CreateWindows* FBSCb;
	void FrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	static void FrameBufferSizeCallbackFunc(GLFWwindow* window, int width, int height);

	//mouse callback function
	static CreateWindows* MCb;
	void MouseCallback(GLFWwindow* window, double xPos, double yPos);
	static void MouseCallbackFunc(GLFWwindow* window, double xPos, double yPos);

	//scroll callback function
	static CreateWindows* SCb;
	void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
	static void ScrollCallbackFunc(GLFWwindow* window, double xOffset, double yOffset);
};

