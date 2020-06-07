/*
 * Copyright 2020 feserr. All rights reserved.
 * License: https://github.com/feserr/proxy-vulkan#license
 */

#include "hephaestus/log.h"

#include <stdarg.h>
#include <stdio.h>

static const char* loglevel_string[] = {
    "INFO",
    "WARNING",
    "ERROR",
};

void Log_(enum LogLevel log_level, const char* file_name, uint32_t line,
          const char* format, ...) {
  if (log_level == 0) {
    printf("[%s] (%s:%u): ", loglevel_string[log_level], file_name, line);
  }
#ifndef NDEBUG
  else {
    printf("[%s] (%s:%u): ", loglevel_string[log_level], file_name, line);
  }
#endif
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
}
