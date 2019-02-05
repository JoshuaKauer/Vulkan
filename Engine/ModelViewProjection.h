#pragma once
#include "glm\glm.hpp"

struct ModelViewProjection
{
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 proj;
};