#include "InputModule.h"

InputModule::InputModule() {};
InputModule::~InputModule() {};

void InputModule::Init()
{
	m_InputCollector.EnableLowLevelHooks();
}

void InputModule::Update() {};

void InputModule::Shutdown()
{

}

void InputModule::OnEvent(ModuleEvent* i_CSystemEvent)
{

}