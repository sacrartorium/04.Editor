#pragma once

/**
 @file
 @brief Заголовочный файл, содержащий простую систему журналирования.
 */

#include <string>

struct logger {
  static void log(const std::string &where, const std::string &message);
};
