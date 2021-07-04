// ☕ Привет
#pragma once

#include <iostream>

namespace
{
	#include <windows.h>
}

enum class Color : WORD
{
	Black = 0,
	Grey = FOREGROUND_INTENSITY,
	LightGrey = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Blue = FOREGROUND_BLUE,
	Green = FOREGROUND_GREEN,
	Cyan = FOREGROUND_GREEN | FOREGROUND_BLUE,
	Red = FOREGROUND_RED,
	Purple = FOREGROUND_RED | FOREGROUND_BLUE,
	LightBlue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	LightGreen = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	LightCyan = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	LightRed = FOREGROUND_RED | FOREGROUND_INTENSITY,
	LightPurple = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	Orange = FOREGROUND_RED | FOREGROUND_GREEN,
	Yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
};

class ConsoleHelper {
	HANDLE _console_handle;
	CONSOLE_CURSOR_INFO info;

	ConsoleHelper() {
		_console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		info.bVisible = false;
		info.dwSize = 100;
		SetConsoleCursorInfo(_console_handle, &info);
	}

public:
	void SetPosition(short x, short y)
	{
		SetConsoleCursorPosition(_console_handle, { x, y });
	}

	void SetConsolePositionAndSize(short l, short t, short w, short h)
	{
		HWND hwnd = GetConsoleWindow();
		RECT rect = { l, t, l + w, t + h };
		MoveWindow(hwnd, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);

		//SetConsoleScreenBufferSize(_console_handle, { w,h });
		//SMALL_RECT size{ w - 1, h - 1 };
		//SetConsoleWindowInfo(_console_handle, TRUE, &size);
	}

	ConsoleHelper(const ConsoleHelper&) = delete;

	static ConsoleHelper& Get()
	{
		static ConsoleHelper object;
		return object;
	}

	void Print(short x, short y, char ch)
	{
		SetPosition(x, y);
		std::cout.put(ch);
	}

	void PrintInt(short x, short y, int a)
	{
		SetPosition(x, y);
		std::cout << a;
	}

	void Print(short x, short y, char ch, Color color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), static_cast<WORD>(color));
		Print(x, y, ch);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f); // вернем обратно
	}
};

static auto& Console = ConsoleHelper::Get();