#include "class_Logger.h"
#include <iostream>
#include <ctime>

std::ofstream Logger::logFile;

void Logger::Init()
{ // Class's constructor
    try
    {
        Logger::logFile.open("gameErrors.log", std::ios::app);
    }
    catch (std::exception &e)
    {
        std::cerr << "logFile cannot be opened: " << e.what() << "\n";
    }
}

void Logger::logFileClose()
{
    if (logFile.is_open())
        logFile.close();
}

std::string Logger::time_toString()
{
    std::time_t t = std::time(nullptr);
    std::string stTime = ctime(&t);
    if (!stTime.empty() && stTime.back() == '\n')
    { // deleting '\n' in stTime
        stTime.pop_back();
    }
    return stTime;
}

void Logger::logError(std::string &message)
{
    if (!logFile)
    {
        std::cerr << "logFile isn't open: enable to log Error\n";
    }
    logFile << "[ERROR] "
            << time_toString()
            << ": "
            << message
            << "\n";
}