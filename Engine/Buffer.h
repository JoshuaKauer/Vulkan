#pragma once

#include <vulkan/vulkan.h>

class Buffer
{
public:
	VkBuffer buffer;
	VkDeviceMemory bufferMemory;

	void InitializeBuffer(VkDevice& device, void* bufferData, VkDeviceSize size, VkBufferUsageFlags usage,
		VkMemoryPropertyFlags properties, VkCommandPool& commandPool, VkQueue& graphicsQueue, VkPhysicalDevice& physicalDevice);
	void CreateBuffer(VkDevice& device, VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory &bufferMemory, VkPhysicalDevice& physicalDevice);
	void Cleanup(VkDevice& device);

	static uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags  properties, VkPhysicalDevice& physicalDevice);
	static VkCommandBuffer BeginSingleTimeCommands(VkDevice& device, VkCommandPool& commandPool);
	static void EndSingleTimeCommands(VkCommandBuffer commandBuffer, VkDevice& device, VkCommandPool& commandPool, VkQueue& graphicsQueue);

private:
	void CopyBuffer(VkDevice& device, VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size, VkCommandPool& commandPool, VkQueue& graphicsQueue);
};