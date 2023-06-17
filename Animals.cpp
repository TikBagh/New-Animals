#include <iostream>
#include <string>

class animals {
protected:
    std::string name;
    std::string color;

public:
    animals(std::string name, std::string color) {
        this->name = name;
        this->color = color;
    }

    virtual void what_they_can_do() = 0;
};

class terrestrial : public animals {
public:
    terrestrial(std::string name, std::string color) : animals(name, color) {}

    terrestrial(const terrestrial& obj) : animals(obj) {}

    terrestrial& operator=(const terrestrial& obj) {
        if (this != &obj) {
            animals::operator=(obj);
        }
        return *this;
    }

    void what_they_can_do() override {
        std::cout << "They can walk" << std::endl;
        std::cout << "The name of animal is " << name << std::endl;
    }
};

class bird : public animals {
public:
    bird(std::string name, std::string color) : animals(name, color) {}

    bird(const bird& obj) : animals(obj) {}

    bird& operator=(const bird& obj) {
        if (this != &obj) {
            animals::operator=(obj);
        }
        return *this;
    }

    void what_they_can_do() override {
        std::cout << "They can fly" << std::endl;
        std::cout << "The name of bird is " << name << std::endl;
    }
};

class sea_animals : public animals {
public:
    sea_animals(std::string name, std::string color) : animals(name, color) {}

    sea_animals(const sea_animals& obj) : animals(obj) {}

    sea_animals& operator=(const sea_animals& obj) {
        if (this != &obj) {
            animals::operator=(obj);
        }
        return *this;
    }

    void what_they_can_do() override {
        std::cout << "They can swim" << std::endl;
        std::cout << "The name of sea_animal is " << name << std::endl;
    }
};

int main() {
    bird falcon("Falcon", "Black");
    sea_animals kit("Kit", "Blue");
    terrestrial land("Tiger", "Yellow and Red");

    bird falcon2(" ", " ");
    falcon2 = falcon;

    bird falcon3(falcon);

    land.what_they_can_do();
    falcon.what_they_can_do();
    kit.what_they_can_do();

    return 0;
}