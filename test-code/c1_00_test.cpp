#include <iostream>

struct A
{
    std::string m_type = "A";
    virtual std::string Type() const {return m_type;}
};

struct B
{
    
};

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}