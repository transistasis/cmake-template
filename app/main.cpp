#include "my_library.h"
#include "config.h"
#include "nlohmann/json.hpp"

int main() {
  std::cout << project_name << " " << project_version << "\n\n";

  std::cout << "JSON Library Version: "
            << NLOHMANN_JSON_VERSION_MAJOR << "."
            << NLOHMANN_JSON_VERSION_MINOR << "."
            << NLOHMANN_JSON_VERSION_PATCH << "\n";

  print_string();

  return 0;
}
