#include <Windows.h>
#include "../SystemManager.h"

char ConvertKeyInputToHex(wchar_t wchar) {
	return printf("0x%x", wchar);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_SYSKEYDOWN:
	{
		// Send an input event to the input manager
		SystemManager::getInstance().getInputSystem().ProcessKeyInput(KeyInput(KeyInput::KeyInputType::INPUT_KEYBOARD_KEY_DOWN, ConvertKeyInputToHex(wParam)));

		break;
	}
	case WM_SYSKEYUP:
	{
		// Send an input event to the input manager
		SystemManager::getInstance().getInputSystem().ProcessKeyInput(KeyInput(KeyInput::KeyInputType::INPUT_KEYBOARD_KEY_UP, ConvertKeyInputToHex(wParam)));

		break;
	}
	case WM_SYSCHAR:
	{
		break;
	}
	case WM_KEYDOWN:
	{
		// Send an input event to the input manager
		SystemManager::getInstance().getInputSystem().ProcessKeyInput(KeyInput(KeyInput::KeyInputType::INPUT_KEYBOARD_KEY_DOWN, ConvertKeyInputToHex(wParam)));

		break;
	}
	case WM_KEYUP:
	{
		// Send an input event to the input manager
		SystemManager::getInstance().getInputSystem().ProcessKeyInput(KeyInput(KeyInput::KeyInputType::INPUT_KEYBOARD_KEY_UP, ConvertKeyInputToHex(wParam)));

		break;
	}
	case WM_CHAR:
	{

		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);

		break;
	}
	default: { return DefWindowProc(hwnd, uMsg, wParam, lParam); }
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}