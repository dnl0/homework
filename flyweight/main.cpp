#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

class Object
{
public:
    Object(const std::string& type) : type_(type) {}

    std::string getType() const { return type_; }

private:
    std::string type_;
};

class ObjectFactory
{
public:
    static std::shared_ptr<Object> getObject(const std::string& type)
    {
        if (objectMap_.count(type) == 0)
            objectMap_[type] = std::make_shared<Object>(type);

        return objectMap_[type];
    }

private:
    static std::unordered_map<std::string, std::shared_ptr<Object>> objectMap_;
};

std::unordered_map<std::string, std::shared_ptr<Object>> ObjectFactory::objectMap_;

int main()
{
    std::srand(std::time(nullptr));

    int boardSize = 0;
    std::cout << "Enter board size: ";
    std::cin >> boardSize;

    std::vector<std::vector<std::shared_ptr<Object>>> board(boardSize, std::vector<std::shared_ptr<Object>>(boardSize, nullptr));

    std::vector<std::string> objectTypes = { "1", "2", "3", "4", "5" };

    for (int i = 0; i < boardSize; ++i)
    {
        for (int j = 0; j < boardSize; ++j) {
            int randIndex = std::rand() % objectTypes.size();
            std::string randType = objectTypes[randIndex];
            board[i][j] = ObjectFactory::getObject(randType);
        }
    }

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j)
            std::cout << board[i][j]->getType() << " ";
        std::cout << std::endl;
    }
}
