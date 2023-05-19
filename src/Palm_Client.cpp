#include <GLFW/glfw3.h>

#include "ModuleManager.h"
#include <palm_engine/logger/Logger.h>

void framebuffer_size_callback(GLFWwindow* pWindow, int width, int height);

// Settings
const unsigned int kScreenWidth = 800;
const unsigned int kScreenHeight = 600;

int main()
{
    // Initialize and configure glfw
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create window
    GLFWwindow* pWindow = glfwCreateWindow(kScreenWidth, kScreenHeight, "Palm Engine", NULL, NULL);
    if (pWindow == NULL)
    {
        Logger::Log(SEVERITY_ERROR, "Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(pWindow);
    glfwSetFramebufferSizeCallback(pWindow, framebuffer_size_callback);

    MODULE_MANAGER.StartEngine(pWindow);

    glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* pWindow, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}