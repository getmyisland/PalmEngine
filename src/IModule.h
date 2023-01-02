#ifndef I_MODULE_H
#define I_MODULE_H
#ifdef _WIN32
#pragma once
#endif

#include "ModuleEvent.h"

class IModule
{
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;
	virtual void OnEvent(ModuleEvent* i_CSystemEvent) = 0;
};

#endif // I_MODULE_H