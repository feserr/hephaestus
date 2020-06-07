/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#ifndef PROXY_UTILS_LOG_H_
#define PROXY_UTILS_LOG_H_

#include <inttypes.h>
#include <string.h>

enum LogLevel { info = 0, warning = 1, error = 2 };

/**
 * @brief Extracts the file name from __FILE__
 */
#define __FILENAME__ \
  (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/**
 * @brief Call Log_ with the file and line where it is call.
 */
#define Log(LogLevel, ...) Log_(LogLevel, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * @brief Prints the message as printf and adds the log level, file and line
 * where it was called.
 *
 * @param log_level The log level of the message.
 * @param file_name The file name where it was called.
 * @param line      The line where it was called.
 * @param format    Format of the message.
 * @param ...       Variables use in the message.
 */
void Log_(enum LogLevel log_level, const char* file_name, uint32_t line,
          const char* format, ...);

#endif  // PROXY_UTILS_LOG_H_
