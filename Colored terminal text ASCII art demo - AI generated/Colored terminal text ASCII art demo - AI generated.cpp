#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

void sleep(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int main() {
    std::vector<std::string> colors = {
        "\033[31m", // Red
        "\033[33m", // Yellow
        "\033[32m", // Green
        "\033[36m", // Cyan
        "\033[34m", // Blue
        "\033[35m", // Magenta
    };

    std::string art = R"(
  _   _      _ _         __        __         _     _ 
 | | | | ___| | | ___    \ \      / /__  _ __| | __| |
 | |_| |/ _ \ | |/ _ \    \ \ /\ / / _ \| '__| |/ _` |
 |  _  |  __/ | | (_) |    \ V  V / (_) | |  | | (_| |
 |_| |_|\___|_|_|\___( )    \_/\_/ \___/|_|  |_|\__,_|
                      |/                              
)";

    for (int i = 0; i < 3'000'000; ++i) {
        clearScreen();
        std::cout << colors[i % colors.size()] << art << "\033[0m";
        sleep(150);
    }

    return 0;
}
