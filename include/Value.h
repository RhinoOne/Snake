#ifndef VALUE_H
#define VALUE_H

#include <windows.h>
#include <vector>
#include <string>

namespace foregroundcolors
{
    enum
    {
        BLACK = 0,
        DARKBLUE = FOREGROUND_BLUE,
        DARKGREEN = FOREGROUND_GREEN,
        DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
        DARKRED = FOREGROUND_RED,
        DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
        DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
        DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        GRAY = FOREGROUND_INTENSITY,
        BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
        GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
        CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
        RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
        MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
        YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
        WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    };
}

namespace  backgroundcolors
{
    enum
    {
        BLACK = 0,
        DARKBLUE = BACKGROUND_BLUE,
        DARKGREEN = BACKGROUND_GREEN,
        DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
        DARKRED = BACKGROUND_RED,
        DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
        DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
        DARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
        GRAY = BACKGROUND_INTENSITY,
        BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
        GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
        CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
        RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
        MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
        YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
        WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    };
}

namespace menuitems
{
    extern const std::vector<std::string> menuItem;
}

namespace settingitems
{
    extern std::vector<std::vector<std::string>> settingItem;
}

namespace windowstype
{
    enum class windowType
    {
        Menu,
        Game,
        Setting,
        GameOver
    };
}

namespace buttons
{
    enum windowChanges
    {
        GO_TO_GAME = 49,
        GO_TO_SETTING = 50,
        RETURN_TO_MENU = 27
    };
    enum class snakeControl
    {
        UP = 72,
        DOWN = 80,
        LEFT = 75,
        RIGHT = 77
    };
}

namespace direction
{
    enum
    {
        Vertical,
        Horizontal
    };
}

namespace constants
{
	extern const int WINDOW_W_S;
	extern const int WINDOW_H_S;
}

#endif 