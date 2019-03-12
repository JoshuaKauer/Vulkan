#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>

#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"
#include "Buffer.h"

class RenderEngine
{
public:
	void Run();

private:
	GLFWwindow * window;

	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkDevice device;

	VkQueue graphicsQueue;
	VkQueue presentQueue;

	VkSurfaceKHR surface;

	VkSwapchainKHR swapChain;
	std::vector<VkImage> swapChainImages;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;
	std::vector<VkImageView> swapChainImageViews;

	VkRenderPass renderPass;
	VkDescriptorSetLayout descriptorSetLayout;
	VkPipelineLayout pipelineLayout;

	VkPipeline graphicsPipeline;

	std::vector<VkFramebuffer> swapChainFramebuffers;

	VkCommandPool commandPool;

	std::vector<VkCommandBuffer> commandBuffers;

	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	size_t currentFrame = 0;

	Buffer vertexBuffer;
	Buffer indexBuffer;

	std::vector<Buffer> uniformBuffers;

	VkDescriptorPool descriptorPool;
	std::vector<VkDescriptorSet> descriptorSets;

	VkImage textureImage;
	VkDeviceMemory textureImageMemory;

	VkImageView textureImageView;
	VkSampler textureSampler;

	bool framebufferResized = false;

	void InitWindow();
	void InitVulkan();
	void MainLoop();
	void Cleanup();

	void DrawFrame();
	void CreateInstance();
	void SetupDebugMessenger();
	void CreateSurface();
	void PickPhysicalDevice();
	void CreateLogicalDevice();
	void CreateSwapChain();
	void CreateImageViews();
	void CreateRenderPass();
	void CreateGraphicsPipeline();
	void CreateFramebuffers();
	void CreateCommandPool();
	void CreateCommandBuffers();
	void CreateSyncObjects();
	void CreateDescriptorSetLayout();
	void CreateUniformBuffers();
	void CreateDescriptorPool();
	void CreateDescriptorSets();

	void CreateTextureImage();
	void CreateTextureImageView();
	VkImageView CreateImageView(VkImage image, VkFormat format);
	void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
	void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
	void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
	void CreateTextureSampler();

	void UpdateUniformBuffer(uint32_t currentImage);

	void RecreateSwapChain();
	void CleanupSwapChain();
	std::vector<const char*> GetRequiredExtensions();
	bool CheckValidationLayerSupport();
	bool IsDeviceSuitable(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	VkShaderModule CreateShaderModule(const std::vector<char>& code);

	static void FramebufferResizeCallback(GLFWwindow* window, int width, int height);
	static std::vector<char> ReadFile(const std::string& filename);
	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};

