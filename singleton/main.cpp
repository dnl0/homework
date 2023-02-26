#include <iostream>
#include <memory>

#include "database_manager.hpp"

auto main() -> int {
    DatabaseManager* dbman1 = DatabaseManager::getInstance();
    DatabaseManager* dbman2 = DatabaseManager::getInstance();

    // these have the same addresses
    std::cout << dbman1 << "\n";
    std::cout << dbman2 << "\n";
}
