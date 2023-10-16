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
#define BOLD "\e[1;37m"
#define RED "\033[31m"
#define RED_BOLD "\e[1;31m"
#define BLUE "\e[0;34m"
#define BLUE_BOLD "\e[1;34m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

void Logger::print(const std::string& message) {
    std::cout << message << RESET;
}

void Logger::print_bold(const std::string& message) {
    std::cout << BOLD << message << RESET;
}

void Logger::print_boss(const std::string& message) {
    std::cout << RED_BOLD << message << RESET;
}

void Logger::print_player(const std::string& message) {
    std::cout << BLUE_BOLD << message << RESET;
}

void Logger::print_debug(const std::string& message) {
    if (debug) {
        std::cout << YELLOW << "DEBUG: " << message << RESET << std::endl;
    }
}
void Logger::print_error(const std::string& message) {
        endwin();
        std::cout << RED << "ERROR: " << message << RESET << std::endl;
        exit(1);

}