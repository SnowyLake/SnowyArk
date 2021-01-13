#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define IMGUI_IMPL_OPENGL_LOADER_GLAD

#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"../ImGui/imgui.h"
#include"../ImGui/impl/imgui_impl_glfw.h"
#include"../ImGui/impl/imgui_impl_opengl3.h"

#include <GLCamera.h>
#include <GLShader.h>
#include "../include/CreateWindow.h"
#include "../include/Model.h"
#include "../include/Lamp.h"
#include "../include/SnowyArkGui.h"

#include<iostream>

//setting
const unsigned int SCR_WIDTH = 1440;
const unsigned int SCR_HEIGHT = 960;

bool showSnowyArkGui = true;

int main()
{
	CreateWindow MainWindow(SCR_WIDTH, SCR_HEIGHT, "SnowyArk Ver0.0.1 Bate", nullptr, nullptr, false);
	MainWindow.SetCallback();

	//set ImGui
	//--------------------------------
	//set ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	ImFont* font1 = io.Fonts->AddFontFromFileTTF(u8"fonts\\微软雅黑.ttc", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());
	ImFont* font2 = io.Fonts->AddFontFromFileTTF(u8"fonts\\庞门正道标题体.TTF", 18.0f, NULL, io.Fonts->GetGlyphRangesChineseFull());

	//setup ImGui style
	//ImGui::StyleColorsDark();		//DarkStyle
	ImGui::StyleColorsLight();	//LightStyle
	//ImGui::StyleColorsClassic();	//ClassicStyle

	//setup platform/renderer bindings
	const char* glsl_version = "#version 330";	//OpenGL3.3

	ImGui_ImplGlfw_InitForOpenGL(MainWindow.window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);

	//set up vertex data (and buffer(s)) and configure vertex attributes
	float vertices[] = {
		// positions
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  // top 
	};

	unsigned int VBO, VAO;
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//glfwSetWindowPos(MainWindow.window, 600, 100);
	glfwShowWindow(MainWindow.window);

	//render loop
	while(!glfwWindowShouldClose(MainWindow.window))
	{
		//input
		MainWindow.ProcessInput();

		//start the ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//Create ImGui
		if(showSnowyArkGui)
			ShowSnowyArkWindow(&showSnowyArkGui);

		//render
		glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, backgroundColor.w);
		glClear(GL_COLOR_BUFFER_BIT);

		//render the triangle
		//shader.SetVec4("triangleColor", glm::vec4(triangleColor.x, triangleColor.y, triangleColor.z, triangleColor.w));
		//shader.use();
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		glfwSwapBuffers(MainWindow.window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();
	return 0;
}

#endif // !STB_IMAGE_IMPLEMENTATION

