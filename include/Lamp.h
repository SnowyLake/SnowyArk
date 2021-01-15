#pragma once
#include<vector>
#include<string>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<gl_camera.h>
#include<gl_shader.h>

class Lamp
{
public:
	std::vector<float> pointLightVertices;
	std::vector<glm::vec3> pointLightPositions;

	Lamp(std::vector<float> pointLightVertices, std::vector<glm::vec3> pointLightPositions);
	~Lamp();

	//set basic uniform of render
	void LightRenderConfigInit(GLShader& shader, const GLCamera& camera);

	//set directional light uniform
	void DirLightRenderConfig(GLShader& shader);

	//set point lights uniform
	void PointLightRenderConfig(GLShader& shader);

	//set spotlight uniform
	void SpotLightRenderConfig(GLShader& shader, const GLCamera& camera);

	//render lights
	void RenderPointLights(GLShader& shader, const glm::mat4 view, const glm::mat4 projection);

private:
	unsigned int lampVAO;
	unsigned int lampVBO;
	void SetLampsVAO();
};








