#include <iostream>

class Animal {
public:
    Animal(const std::string& name) : name(name) {}

    void eat() {
        std::cout << name << " is eating." << std::endl;
    }

    void sleep() {
        std::cout << name << " is sleeping." << std::endl;
    }

private:
    std::string name;
};

class Bird : public virtual Animal {
public:
    Bird(const std::string& name) : Animal(name) {}

    void fly() {
        std::cout << "Bird " << name << " is flying." << std::endl;
    }
};

class Mammal : public virtual Animal {
public:
    Mammal(const std::string& name) : Animal(name) {}

    void run() {
        std::cout << "Mammal " << name << " is running." << std::endl;
    }
};

class Bat : public Bird, public Mammal {
public:
    Bat(const std::string& name) : Animal(name), Bird(name), Mammal(name) {}

    void glide() {
        std::cout << "Bat " << name << " is gliding." << std::endl;
    }
};

int main() {
    Bat bat("Batty");

    // Since we used virtual inheritance, there is only one 'Animal' instance in 'Bat'.
    bat.eat();
    bat.sleep();
    bat.fly();
    bat.run();
    bat.glide();

    return 0;
}
