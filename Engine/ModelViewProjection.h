#pragma once
#include "glm\glm.hpp"

struct ModelViewProjection
{
	alignas(16) glm::mat4 model;
	alignas(16) glm::mat4 view;
	alignas(16) glm::mat4 proj;
};