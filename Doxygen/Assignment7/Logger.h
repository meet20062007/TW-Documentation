/**
 * @file Logger.h
 * @brief Declares the Logger class and logging levels.
 *
 * This file contains the LogLevel enumeration and the Logger class,
 * which can be used to represent logging levels and log messages.
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

/**
 * @enum LogLevel
 * @brief Defines the available logging levels.
 *
 * These levels classify messages according to their purpose
 * and severity.
 */
enum class LogLevel
{
    DEBUG,   ///< Detailed information useful for debugging.
    INFO,    ///< General information about program execution.
    WARNING, ///< Information about a potentially problematic situation.
    ERROR    ///< Information about an error.
};

/**
 * @class Logger
 * @brief Provides basic logging functionality.
 *
 * The Logger class records messages associated with a logging level.
 * In this example, messages are written to the standard output stream.
 */
class Logger
{
private:
    LogLevel level;

public:
    /**
     * @brief Constructs a Logger object.
     *
     * @param logLevel The logging level associated with this logger.
     */
    explicit Logger(LogLevel logLevel)
        : level(logLevel)
    {
    }

    /**
     * @brief Writes a message to the standard output stream.
     *
     * @param message The message to be logged.
     */
    void log(const std::string& message) const
    {
        switch (level)
        {
            case LogLevel::DEBUG:
                std::cout << "[DEBUG] ";
                break;

            case LogLevel::INFO:
                std::cout << "[INFO] ";
                break;

            case LogLevel::WARNING:
                std::cout << "[WARNING] ";
                break;

            case LogLevel::ERROR:
                std::cout << "[ERROR] ";
                break;
        }

        std::cout << message << '\n';
    }
};

#endif // LOGGER_H