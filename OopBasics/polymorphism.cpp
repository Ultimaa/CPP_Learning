#include <iostream>

class Animal
{
public:
    void virtual sound()
    {
        std::cout << "Animal sound \n";
    }
};

class Dog : public Animal
{
public:
    void sound()
    {
        std::cout << "Dog says: bow bow \n";
    }
};

class Cat : public Animal
{
public:
    void sound()
    {
        std::cout << "Cat says: Miau Miau \n";
    }
};

class Pig : public Animal
{
public:
    void sound()
    {
        std::cout << "Pig says: Hrum Hrum \n";
    }
};

int main()
{
    /** If we assign an inherited class to the base class and the base class has a virutal method we are able to keep the more specific classes in the generic one.  */
    Animal *animalsArray[3];
    animalsArray[0] = new Dog();
    animalsArray[1] = new Cat();
    animalsArray[2] = new Pig();

    for (auto animals : animalsArray)
    {
        animals->sound();
    }

    return 0;
}