#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Component {
public:
    virtual void Add(std::shared_ptr<Component> component) = 0;
    virtual void Remove(std::shared_ptr<Component> component) = 0;
    virtual void Display() = 0;
};

class Leaf : public Component {
private:
    std::string name_;

public:
    explicit Leaf(const std::string& name) : name_(name) {}

    void Add(std::shared_ptr<Component> component) override {
        std::cout << "Cannot add to a leaf component." << std::endl;
    }

    void Remove(std::shared_ptr<Component> component) override {
        std::cout << "Cannot remove from a leaf component." << std::endl;
    }

    void Display() override {
        std::cout << "Component: " << name_ << std::endl;
    }
};

class Composite : public Component {
private:
    std::string name_;
    std::vector<std::shared_ptr<Component>> components_;

public:
    explicit Composite(const std::string& name) : name_(name) {}

    void Add(std::shared_ptr<Component> component) override {
        components_.push_back(component);
    }

    void Remove(std::shared_ptr<Component> component) override {
        for (auto it = components_.begin(); it != components_.end(); ++it) {
            if (*it == component) {
                components_.erase(it);
                break;
            }
        }
    }

    void Display() override {
        std::cout << "Component: " << name_ << std::endl;
        std::cout << "Composite Components: " << std::endl;
        for (const auto& component : components_) {
            component->Display();
        }
    }
};

int main() {
    auto engine1 = std::make_shared<Leaf>("Engine 1");
    auto engine2 = std::make_shared<Leaf>("Engine 2");
    auto battery1 = std::make_shared<Leaf>("Battery 1");
    auto battery2 = std::make_shared<Leaf>("Battery 2");

    auto spacecraft = std::make_shared<Composite>("Spacecraft");
    auto propulsionSystem = std::make_shared<Composite>("Propulsion System");
    auto powerSystem = std::make_shared<Composite>("Power System");

    // Build the composite structure
    propulsionSystem->Add(engine1);
    propulsionSystem->Add(engine2);

    powerSystem->Add(battery1);
    powerSystem->Add(battery2);

    spacecraft->Add(propulsionSystem);
    spacecraft->Add(powerSystem);

    spacecraft->Display();

    return 0;
}
