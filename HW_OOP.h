#pragma once

#include <vector>

using namespace std;

template<typename T>
class TArray
{
public:
    TArray()
    {
        Arr = new T[BaseCapacity];
    }
    
    virtual ~TArray()
    {
        delete[] Arr;
    }
    
    T& operator[](int Idx)
    {
        return Arr[Idx];
    }

    int Num()
    {
        return Size;
    }
    
public:
    void Reserve(int NewCapacity)
    {
        if(ChangeCapacity(NewCapacity))
        {
            if(Size > Capacity)
            {
                Size = Capacity;
            }
            
            T* NewArr = new T[NewCapacity];
            
            for(int i = 0; i < Size; ++i)
            {
                NewArr[i] = Arr[i];
            }
            delete[] Arr;
            Arr = NewArr;
        }
    }
    
    void Resize(int NewSize ,const T& Val)
    {
        if(ChangeCapacity(NewSize))
        {
            T* NewArr = new T[Capacity];
            for(int i = 0; i < min(NewSize, Size); ++i)
            {
                NewArr[i] = Arr[i];
            }

            delete[] Arr;

            for(int i = min(NewSize, Size); i < NewSize; ++i)
            {
                NewArr[i] = Val;
            }

            Arr = NewArr;
        }
        else
        {
            for(int i = Size; i <NewSize; ++i)
            {
                Arr[i] = Val;
            }
            Size = NewSize;
        }
    }
    
    void PushBack(const T& Elem)
    {
        if(Size != Capacity)
        {
            Arr[Size++] = Elem;
        }
        else
        {
            if(ChangeCapacity(Capacity*2))
            {
                T* NewArr = new T[Capacity];
                for(int i = 0; i < Size; ++i)
                {
                    NewArr[i] = Arr[i];
                }

                delete[] Arr;

                Arr = NewArr;
                Arr[Size++] = Elem;
            }
        }
    }
    

private:
    T* Arr;
    int Size = 0;
    int Capacity = 5;
    int BaseCapacity = 5;
    
    bool ChangeCapacity(int NewCapacity)
    {
        bool Ret = false;
        if(NewCapacity > Capacity)
        {
            while(Capacity < NewCapacity)
            {
                Capacity *= 2;
            }
            Ret = true;
        }
        else if(NewCapacity < Capacity)
        {
            while(Capacity > NewCapacity)
            {
                Capacity /= 2;
                if(Capacity <= BaseCapacity)
                {
                    Capacity = BaseCapacity;
                }
            }
            Ret = true;
        }

        return Ret;
    }
};

class Animal;
Animal* CreateAnimal();

namespace EAnimalType
{
    enum Type
    {
        Dog,
        Cat,
        Cow,
        End
    };
}

class Animal
{
public:
    
    virtual void MakeSound() = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    void MakeSound() override { cout << "Woops!\n"; } 
};

class Cat : public Animal
{
public:
    void MakeSound() override { cout << "Meow!\n"; } 
};

class Cow : public Animal
{
public:
    void MakeSound() override { cout << "Moo!\n"; } 
};

class Zoo
{
private:
    TArray<Animal*> Animals;
    
public:
    Zoo(int n)
    {
        for(int i = 0; i < n; ++i)
        {
            AddAnimal(CreateAnimal());
        }
    };
    
    ~Zoo()
    {
        for(int i = 0 ; i < Animals.Num(); i++)
        {
            delete Animals[i];
            Animals[i] = nullptr;
        }
    };
    
    
    void AddAnimal(Animal* InAnimal)
    {
        Animals.PushBack(InAnimal);
    };
    

    void PerformActions()
    {
        for(int i = 0; i < Animals.Num(); i++)
        {
            Animals[i]->MakeSound();
        }
    }
};

inline Animal* CreateAnimal()
{
    EAnimalType::Type Type = (EAnimalType::Type)(rand() % EAnimalType::End);
    switch (Type)
    {
    case EAnimalType::Cat : return new Cat();
    case EAnimalType::Dog : return new Dog();
    case EAnimalType::Cow : return new Cow();
    }
    
    return nullptr;
}


