#ifndef _PE_LOG_MANAGER_H__
#define _PE_LOG_MANAGER_H__

#define PE_LOG_MANAGER PalmEngine::LogManager::GetSingletonPtr()

#include <PalmEngineSingleton.h>
#include <PalmEngineManager.h>
#include <string>
#include <source_location>

namespace PalmEngine
{
	class LogManager : PalmEngineManager, PalmEngineSingleton<LogManager>
	{
	public:
		LogManager();
		~LogManager();

		virtual void StartUp() override;
		virtual void ShutDown() override;

		void LogInfo(std::string const message,
			std::source_location const source = std::source_location::current());

		void LogWarning(std::string const message,
			std::source_location const source = std::source_location::current());

		void LogError(std::string const message,
			std::source_location const source = std::source_location::current());

		static LogManager& GetSingleton(void);
		static LogManager* GetSingletonPtr(void);
	};
}

#endif