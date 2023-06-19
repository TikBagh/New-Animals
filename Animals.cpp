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
    virtual animals* type() const = 0;

    virtual ~animals() {}
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

    virtual ~terrestrial() {}

    void what_they_can_do() override final {
        std::cout << "They can walk" << std::endl;
        std::cout << "The name of animal is " << name << std::endl;
    }

    animals* type() const override final {
        return new terrestrial(*this);
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

    void what_they_can_do() override final{
        std::cout << "They can fly" << std::endl;
        std::cout << "The name of bird is " << name << std::endl;
    }

    animals* type() const override final {
        return new bird(*this);
    }

    virtual ~bird() {}
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

    void what_they_can_do() override final {
        std::cout << "They can swim" << std::endl;
        std::cout << "The name of sea_animal is " << name << std::endl;
    }

    animals* type() const override final {
        return new sea_animals(*this);
    }

    virtual ~sea_animals() 
    {
      
    }
};

int main() {
    bird falcon("Falcon", "Black");
    sea_animals kit("Kit", "Blue");
    terrestrial land("Tiger", "Yellow and Red");

    animals* ptr[] = { &falcon, &kit, &land };
    const int Lenght = sizeof(ptr) / sizeof(ptr[0]);

   
    for (int i = 0; i < Lenght; ++i)
    {
        animals* anim = ptr[i];
      

        animals* new_anim = anim->type() ;
        new_anim->what_they_can_do();

        delete new_anim;
    }


    bird falcon2(" ", " ");
    falcon2 = falcon;

    bird falcon3(falcon);

    std::cout << std::endl;
    std::cout << std::endl;
    
    falcon2.what_they_can_do();
    falcon3.what_they_can_do();

   

    return 0;
}
