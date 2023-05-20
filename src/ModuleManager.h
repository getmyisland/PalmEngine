#ifndef MODULE_MANAGER_H
#define MODULE_MANAGER_H

#define MODULE_MANAGER ModuleManager::GetInstance()

#include <GLFW/glfw3.h>

class ModuleManager
{
public:
	static ModuleManager& GetInstance()
	{
		static ModuleManager s_instance;

		return s_instance;
	}

	ModuleManager(ModuleManager const&) = delete;
	void operator=(ModuleManager const&) = delete;

private:
	ModuleManager() {};

	// The main window of the application
	GLFWwindow* _pWindow = nullptr;

	void InitModules();
	void GameLoop();
	void UpdateModules();
	void RenderModules();
	void ShutdownModules();

public:
	GLFWwindow* GetApplicationWindow();

	void StartEngine(GLFWwindow* pWindow);
	void KillGameLoop();
};

#endif