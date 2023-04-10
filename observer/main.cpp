#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers_;

public:
    void attach(Observer* observer) {
        observers_.push_back(observer);
    }

    void detach(Observer* observer) {
        auto it = std::find(observers_.begin(), observers_.end(), observer);
        if (it != observers_.end()) {
            observers_.erase(it);
        }
    }

    void notify(const std::string& message) {
        for (Observer* observer : observers_) {
            observer->update(message);
        }
    }
};

class HardwareStore : public Subject {
public:
    void sendAd(const std::string& adMessage) {
        std::cout << "Sending advertisement: " << adMessage << std::endl;
        notify(adMessage);
    }
};

class Customer : public Observer {
private:
    std::string name_;

public:
    Customer(const std::string& name) : name_(name) {}

    void update(const std::string& message) override {
        std::cout << "Customer " << name_ << " received advertisement: " << message << std::endl;
    }
};

int main() {
    HardwareStore hardwareStore;

    Customer customer1("John");
    Customer customer2("Alice");

    hardwareStore.attach(&customer1);
    hardwareStore.attach(&customer2);

    hardwareStore.sendAd("New tools sale!");
    hardwareStore.sendAd("Spring clearance!");
    
    hardwareStore.detach(&customer2);

    hardwareStore.sendAd("Limited time offer!");
}
