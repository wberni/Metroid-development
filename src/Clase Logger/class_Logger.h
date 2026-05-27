#pragma once
#include <string>
#include <fstream>

class Logger {
    private:
        static std::ofstream logFile;
        static std::string time_toString();
    public:
        Logger();
        static void Init();
        static void logError(std::string& message);
        static void logFileClose();
};