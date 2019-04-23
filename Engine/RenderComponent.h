#pragma once

#include <vector>

#include <glm/glm.hpp>

#include "Vertex.h"
#include "Texture.h"
#include "Buffer.h"

class RenderComponent
{
public:
	std::string MODEL_PATH = "Models/chalet.obj";

	glm::vec3 pos;
	glm::vec3 lookAt;

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;

	Texture texture;

	VkDevice* device;
	VkCommandPool* commandPool;
	VkQueue* graphicsQueue;
	VkPhysicalDevice* physicalDevice;

public:
	void Initialize();
	void LoadModel();
	void CleanUp();
};

