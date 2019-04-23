#pragma once

#include <vulkan/vulkan.h>
#include <iostream>

class Texture
{
public:
	std::string TEXTURE_PATH = "Textures/chalet.jpg";
	
	uint32_t mipLevels;
	VkImage textureImage;
	VkDeviceMemory textureImageMemory;

	VkImageView textureImageView;
	VkSampler textureSampler;

public:

	void CreateTextureImage(VkDevice& device, VkPhysicalDevice& physicalDevice, VkCommandPool& commandPool, VkQueue& graphicsQueue);
	void CreateTextureImageView(VkDevice& device);
	static VkImageView CreateImageView(VkDevice& device, VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
	void CopyBufferToImage(VkDevice& device, VkCommandPool& commandPool, VkQueue& graphicsQueue, VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
	void CreateTextureSampler(VkDevice& device);
	void GenerateMipmaps(VkDevice& device, VkPhysicalDevice& physicalDevice, VkCommandPool& commandPool, VkQueue& graphicsQueue, VkImage image, VkFormat imageFormat, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
	void Cleanup(VkDevice& device);

	static bool HasStencilComponent(VkFormat format);
	static void CreateImage(VkDevice& device, VkPhysicalDevice& physicalDevice, uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
	static void TransitionImageLayout(VkDevice& device, VkCommandPool& commandPool, VkQueue& graphicsQueue, VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
};

