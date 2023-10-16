#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
    private:
        bool debug;
    public:
        Logger();
        Logger(bool _debug);

        void print(const std::string& message);
        void print_bold(const std::string& message);
        void print_boss(const std::string& message);
        void print_player(const std::string& message);
        void print_debug(const std::string& message);
        void print_error(const std::string& message);
};
#endif