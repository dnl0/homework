class Database {
public:
    static Database* getInstance() {
        static Database* instance = new Database;
        return instance;
    }
    void connect() {
        std::cout << "connected\n";
    }
    void disconnect() {
        std::cout << "disconnected\n";
    }
    void query(const std::string& sql) {
        std::cout << "query sent\n";
    }
private:
    Database() {}
    Database(const Database&) = delete;
    Database& operator=(const Database&) = delete;
};

class DatabaseManager {
public:
    static DatabaseManager* getInstance() {
        static DatabaseManager* instance = new DatabaseManager;
        return instance;
    }
    void connect() {
        database_->connect();
    }
    void disconnect() {
        database_->disconnect();
    }
    void query(const std::string& sql) {
        database_->query(sql);
    }
private:
    DatabaseManager() {}
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
    Database* database_ = Database::getInstance();
};
