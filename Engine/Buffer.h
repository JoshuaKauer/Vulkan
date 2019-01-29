#pragma once

#include <vulkan/vulkan.h>

class Buffer
{
public:
	VkBuffer buffer;
	VkDeviceMemory bufferMemory;

	void InitializeBuffer(VkDevice& device, void* bufferData, VkDeviceSize size, VkBufferUsageFlags usage,
		VkMemoryPropertyFlags properties, VkCommandPool& commandPool, VkQueue& graphicsQueue, VkPhysicalDevice& physicalDevice);
	void Cleanup(VkDevice& device);

private:
	void CreateBuffer(VkDevice& device, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory &bufferMemory, VkPhysicalDevice& physicalDevice);
	void CopyBuffer(VkDevice& device, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size, VkCommandPool& commandPool, VkQueue& graphicsQueue);
	uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags  properties, VkPhysicalDevice& physicalDevice);
};