#include "..\include\Value.h"

namespace menuitems
{
    extern const std::vector<std::string> menuItem
    { "MENU", "START GAME", "SETTINGS"};
}

namespace settingitems
{
    extern std::vector<std::vector<std::string>> settingItem
    {
        {"1. Sound", "1. Yes", "2. No"},
        {"2. COMING SOON", "In developing"}
    };
}

namespace constants
{
	extern const int WINDOW_W_S = 118;
    extern const int WINDOW_H_S = 27;
}