#include "logger.hpp"

#include <iostream>

/**
 Логгировать сообщение.
*/
void logger::log(const std::string &where, const std::string &message) {
  static int index = 0;
  std::cout << std::to_string(++index) << ": (" << where << ") " << message
            << std::endl;
}
