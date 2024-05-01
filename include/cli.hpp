/**
 * @file cli.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Header file for the command line interface (CLI) functionalities.
 *
 * This header file defines functions for parsing command line arguments
 * and selecting the appropriate stack implementation based on user input.
 * @version 0.1
 * @date 2024-05-01
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "stack_interface.hpp"
#include <string>

namespace cli {

/**
 * @brief Generates the help message string based on the provided arguments.
 * @param argv An array of character pointers representing the command line
 * arguments.
 * @return A string containing the help message.
 */
std::string help_str(char *argv[]);

/**
 * @brief Checks if the user has requested help based on the arguments provided.
 *
 * This function iterates through the arguments and checks for flags  "--help",
 * "-h".
 *
 * @param argc The number of command line arguments (including the program
 * name).
 * @param argv An array of character pointers representing the command line
 * arguments.
 * @return True if the user requested help, false otherwise.
 */
bool needs_help(int argc, char *argv[]);

/**
 * @brief Parses the command line arguments and selects the appropriate stack
 * implementation.
 *
 * This function analyzes the provided arguments and selects the desired stack
 * type based on the specified options (e.g., "-f" for fixed array stack, "-d"
 * for dynamic stack , "-r" for dynamic rezizable stack).
 *
 * @param argc The number of command line arguments (including the program
 * name).
 * @param argv An array of character pointers representing the command line
 * arguments.
 * @return A pointer to a newly created Stack object of the appropriate type.
 */
Stack *parse_args(int argc, char *argv[]);

} // namespace cli
