#include <iostream>
#include <memory>
#include <string>

class Database {
public:
    virtual void query(const std::string& sql) = 0;
};

class RealDatabase : public Database {
public:
    void query(const std::string& sql) override {
        std::cout << "Executing query: " << sql << " in real database." << std::endl;
    }
};

class DatabaseProxy : public Database {
private:
    std::unique_ptr<RealDatabase> realDatabase_;

public:
    void query(const std::string& sql) override {
        // Create real database on-demand
        if (realDatabase_ == nullptr) {
            realDatabase_ = std::make_unique<RealDatabase>();
        }

        std::cout << "Executing query: " << sql << " in proxy database." << std::endl;
        // Perform additional operations on proxy database
        // ...

        // Delegate query to real database
        realDatabase_->query(sql);
    }
};

int main() {
    // Client code
    DatabaseProxy databaseProxy;
    databaseProxy.query("SELECT * FROM users");
}
