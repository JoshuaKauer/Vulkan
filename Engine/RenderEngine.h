#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW\glfw3.h>

#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"
#include "Buffer.h"
#include "Texture.h"
#include "RenderComponent.h"

class RenderEngine
{
public:
	void Run();

private:
	GLFWwindow * window;

	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;
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

	/*std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;*/

	RenderComponent renderComponent;

	Buffer vertexBuffer;
	Buffer indexBuffer;

	std::vector<Buffer> uniformBuffers;

	VkDescriptorPool descriptorPool;
	std::vector<VkDescriptorSet> descriptorSets;

	Texture texture;

	VkImage depthImage;
	VkDeviceMemory depthImageMemory;
	VkImageView depthImageView;

	VkImage colorImage;
	VkDeviceMemory colorImageMemory;
	VkImageView colorImageView;

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

	void CreateColorResources();

	void CreateDepthResources();
	VkFormat FindDepthFormat();
	VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
	bool HasStencilComponent(VkFormat format);

	VkSampleCountFlagBits GetMaxUsableSampleCount();

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

