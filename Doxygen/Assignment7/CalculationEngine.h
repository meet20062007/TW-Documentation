/**
 * @file CalculationEngine.h
 * @brief Declares the CalculationEngine class.
 *
 * This file contains the CalculationEngine class, which performs
 * mathematical operations and uses the Logger class to record
 * information about calculations.
 */

#ifndef CALCULATION_ENGINE_H
#define CALCULATION_ENGINE_H

#include "Logger.h"

/**
 * @class CalculationEngine
 * @brief Performs mathematical calculations.
 *
 * @details
 * The CalculationEngine class provides mathematical operations.
 * It uses a Logger object to report information about calculations.
 *
 * The class separates mathematical operations from logging,
 * making the code easier to understand and maintain.
 */
class CalculationEngine
{
private:
    Logger logger;

public:
    /**
     * @brief Constructs a CalculationEngine object.
     *
     * @param logLevel The logging level used by the calculation engine.
     */
    explicit CalculationEngine(LogLevel logLevel)
        : logger(logLevel)
    {
    }

    /**
     * @brief Calculates the power of a number.
     *
     * @param base The number to be raised to a power.
     * @param exponent The exponent applied to the base.
     *
     * @return The result of raising base to exponent.
     *
     * @todo Review the handling of zero raised to a negative exponent.
     */
    double power(double base, int exponent)
    {
        logger.log("Starting power calculation.");

        double result = 1.0;

        if (exponent >= 0)
        {
            for (int i = 0; i < exponent; ++i)
            {
                result *= base;
            }
        }
        else
        {
            if (base == 0.0)
            {
                logger.log(
                    "Error: zero cannot be raised to a negative exponent."
                );

                return 0.0;
            }

            for (int i = 0; i > exponent; --i)
            {
                result /= base;
            }
        }

        logger.log("Power calculation completed.");

        return result;
    }
};

#endif // CALCULATION_ENGINE_H