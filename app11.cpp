#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Animal
{
    string name;

    Animal(const string& name) : name{name} { }

    void printName() const
    {
        cout << "My name is " << name;
    }

    virtual string type() const = 0;
    virtual void jump() const = 0;
    virtual void fly() const = 0;
};

struct Cat : public Animal
{
    Cat(const string& name) : Animal{name} { }

    string type() const override { return "Cat"; }

    void jump() const override
    {
        printName();
        cout << " " << type() << " I jump very high!" << endl;
    }
    void fly() const override
    {
        printName();
        cout << " " << type() << " I cannot fly!" << endl;
    }
};

struct Dog : public Animal
{
    Dog(const string& name) : Animal{name} { }

    string type() const override { return "Dog"; }

    void jump() const override
    {
        printName();
        cout << " " << type() << " I like to jump!" << endl;
    }
    void fly() const override
    {
        printName();
        cout << " " << type() << " I cannot fly!" << endl;
    }

};

struct Bird : public Animal
{
    Bird(const string& name) : Animal{name} { }

    string type() const override { return "Bird"; }

    void jump() const override
    {
        printName();
        cout << " " << type() << " I cannot jump!" << endl;
    }
    void fly() const override
    {
        printName();
        cout << " " << type() << " I fly high!" << endl;
    }

};

struct Zoo
{
    vector<Animal*> animals;

    Zoo(const vector<Animal*>& animals) : animals{animals} { }
    Zoo(vector<Animal*>&& animals) : animals{move(animals)} { }

    void flyAllAnimals() const
    {
        for(auto animal_ptr : animals)
            animal_ptr->fly();
    }

    void jumpAllAnimals() const
    {
        for(auto animal_ptr : animals)
            animal_ptr->jump();
    }

    void runAllDogs() const
    {
        for(auto animal_ptr : animals)
        {
            auto dog_ptr = dynamic_cast<Dog*>(animal_ptr);
            if(dog_ptr)
            {
                dog_ptr->printName();
                cout << endl;
            }
        }
    }

    template<typename FUNC>
    void doForAllAnimals(FUNC func)
    {
        for(auto animal_ptr : animals)
            if(func(animal_ptr))
            {
                animal_ptr->printName();
                cout << endl;
            }
    }
};

int main(int argc, char* argv[])
{
    auto a1 = Bird{"Birdie"};
    auto a2 = Dog{"Karabas"};
    auto a3 = Dog{"Rintintin"};
    auto a4 = Cat{"Tom"};
    auto a5 = Cat{"Mirnav"};
    auto z = Zoo{{&a1, &a2, &a3, &a4, &a5}};
//    z.flyAllAnimals();
//    z.runAllDogs();

    z.doForAllAnimals([](Animal* a_ptr) {
        auto cat_ptr = dynamic_cast<Cat*>(a_ptr);
        return (bool)cat_ptr;
    });

    return 0;
}
