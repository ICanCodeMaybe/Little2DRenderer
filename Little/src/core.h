#include <iostream>

#define LIL_ERROR(x) std::cout << "\033[1;31mLITTLE ERROR: " << "\033[;31m" << x  << "\033[0m\n"; //red bold text(\033 starts definig colors and styles [1 - bold; 31 - red, m - message)
#define LIL_WARNING(x) std::cout << "\033[1;33mLITTLE WARNING: " << "\033[;33m" << x  << "\033[0m\n"; //yellow bold text(\033 starts definig colors and styles)
#define LIL_INFO(x) std::cout << "\033[1;37mLITTLE INFO: " << "\033[;37m" << x  << "\033[0m\n"; //white bold text(\033 starts definig colors and styles)

namespace lil{


}