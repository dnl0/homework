#include <iostream>
#include <memory>

#include "animal.hpp"

auto main() -> int {
#ifdef NOT
    std::cout << "Error: specify animal when running make command\n";
#endif // NOT

#ifdef DOG
    auto animal_client = std::make_unique <AnimalClient> (new DogFactory);
    animal_client->createAnimal();
    animal_client->makeAnimalSound();
#endif // DOG

#ifdef CAT
    auto animal_client = std::make_unique <AnimalClient> (new CatFactory);
    animal_client->createAnimal();
    animal_client->makeAnimalSound();
#endif // CAT

#ifdef BIRD
    auto animal_client = std::make_unique <AnimalClient> (new BirdFactory);
    animal_client->createAnimal();
    animal_client->makeAnimalSound();
#endif // BIRD
}
