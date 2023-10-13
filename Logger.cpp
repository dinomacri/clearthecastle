#include <iostream>
#include <curses.h>

#include "Logger.h"

Logger::Logger()
{
    debug = false;
}

Logger::Logger(bool _debug)
{
    debug = _debug;
}

// ANSI escape codes for text color
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define RESET_TEXT "\033[0m"

void Logger::print(const std::string& message) {
    std::cout << message << std::endl;
}

void Logger::print_debug(const std::string& message) {
    if (debug) {
        std::cout << YELLOW_TEXT << "DEBUG: " << message << RESET_TEXT << std::endl;
    }
}
void Logger::print_error(const std::string& message) {
        endwin();
        std::cout << RED_TEXT << "ERROR: " << message << RESET_TEXT << std::endl;
        exit(1);

}