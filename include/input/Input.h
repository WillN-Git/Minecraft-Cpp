#ifndef MINECRAFT_INPUT_H
#define MINECRAFT_INPUT_H
#include "core.h"

namespace Minecraft
{
	namespace Input
	{
		extern float mouseX;
		extern float mouseY;
		extern float lastMouseX;
		extern float lastMouseY;
		extern float mouseScreenX;
		extern float mouseScreenY;
		extern float deltaMouseX;
		extern float deltaMouseY;
		extern float mouseScrollX;
		extern float mouseScrollY;
		extern bool keyPressed[GLFW_KEY_LAST];
		extern bool keyBeginPressData[GLFW_KEY_LAST];
		extern bool mousePressed[GLFW_MOUSE_BUTTON_LAST];
		extern bool mouseBeginPressData[GLFW_MOUSE_BUTTON_LAST];

		void setProjectionMatrix(const glm::mat4& projectionMatrix);
		void setWindowSize(const glm::vec2& windowSize);
		void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
		void mouseCallback(GLFWwindow* window, double xpos, double ypos);
		void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
		void charCallback(GLFWwindow* window, unsigned int codepoint);
		void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void endFrame();
		
		void processKeyEvent(int key, int action);
		void processMouseEvent(float xpos, float ypos);
		void processMouseButton(int button, int action);
		void processChar(unsigned int codepoint);
		void processMouseScroll(float xoffset, float yoffset);

		bool isKeyPressed(int key);
		bool keyBeginPress(int key);
		bool isMousePressed(int mouseButton);
		bool mouseBeginPress(int mouseButton);
		uint32 lastCharPressed();
	}
}

#endif