#include "my_library.h"
#include "config.h"
#include <cxxopts.hpp>
#include <fmt/format.h>
#include "nlohmann/json.hpp"
#include <spdlog/spdlog.h>

int main() {
  std::cout << project_name << " " << project_version << "\n\n";

  std::cout << "JSON Library Version: "
            << NLOHMANN_JSON_VERSION_MAJOR << "."
            << NLOHMANN_JSON_VERSION_MINOR << "."
            << NLOHMANN_JSON_VERSION_PATCH << "\n";

  std::cout << "FMT:" << FMT_VERSION << "\n";

  std::cout << "CXXOPTS:" << CXXOPTS__VERSION_MAJOR << "."
            << CXXOPTS__VERSION_MINOR << "." << CXXOPTS__VERSION_PATCH
            << "\n";

  std::cout << "SPDLOG:" << SPDLOG_VER_MAJOR << "." << SPDLOG_VER_MINOR << "."
            << SPDLOG_VER_PATCH << "\n";

  print_string();

  return 0;
}
