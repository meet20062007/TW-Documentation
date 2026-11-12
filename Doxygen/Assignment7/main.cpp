/**
 * @file main.cpp
 * @brief Contains the entry point of the application.
 *
 * This file demonstrates the use of Logger and CalculationEngine.
 *
 * @mainpage Simple C++ Calculation Project
 *
 * @section introduction Introduction
 *
 * This project demonstrates how to organize a small C++ application
 * into multiple files and document it using Doxygen.
 *
 * @section components Project Components
 *
 * - Logger.h defines logging functionality and logging levels.
 * - CalculationEngine.h defines the mathematical calculation engine.
 * - main.cpp contains the application entry point.
 *
 * @section documentation Documentation
 *
 * Doxygen processes specially formatted comments to generate
 * documentation in HTML and LaTeX formats.
 */
#include "Logger.h"
#include "CalculationEngine.h"

#include <iostream>

/**
 * @brief Starts the application.
 *
 * Creates a calculation engine, performs a power calculation,
 * and displays the result.
 *
 * @return 0 when the application completes successfully.
 */
int main()
{
    CalculationEngine engine(LogLevel::INFO);

    double result = engine.power(2.0, 3);

    std::cout << "Result: " << result << '\n';

    return 0;
}