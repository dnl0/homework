#pragma once

class Animal {
public:
    virtual ~Animal() {}
    virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
    void makeSound() {
        std::cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        std::cout << "Meow!\n";
    }
};

class Bird : public Animal {
public:
    void makeSound() {
        std::cout << "Quack?!\n";
    }
};

class AnimalFactory {
public:
    virtual ~AnimalFactory() {}
    virtual Animal* createAnimal() = 0;
};

class DogFactory : public AnimalFactory {
public:
    Animal* createAnimal() {
        return new Dog();
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal* createAnimal() {
        return new Cat();
    }
};

class BirdFactory : public AnimalFactory {
public:
    Animal* createAnimal() {
        return new Bird();
    }
};

class AnimalClient {
private:
    AnimalFactory* factory;
    Animal* animal;
public:
    AnimalClient(AnimalFactory* factory) : factory(factory) {}
    ~AnimalClient() {
        delete factory;
        delete animal;
    }
    void createAnimal() {
        animal = factory->createAnimal();
    }
    void makeAnimalSound() {
        animal->makeSound();
    }
};
