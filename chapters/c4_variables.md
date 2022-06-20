# Chapter 4: Variables in C++

## Objectives:
- To understand the basic primitive types in c++
- To understand the strong typing requirements of c++

## 4.1 Primitive types in c++
Consider the following:
```c++
#include <iostream>

int main()
{
    //Single byte types
    bool flag        = false; //or true
    char c           = 101;   //-128 to 127 and ASCII chars 0-127
    unsigned char uc = 101;   //0 to 255
    char c2 = 'a';

    //Two byte types
    short     kort       = 122; //-32,768 to 32,767
    short int kort2      = 121; //Same as short
    unsigned short ukort = 120; //

    //Four byte types
    int               integer  = 25432; //-2,147,483,648 to 2,147,483,647
    unsigned int      integer3 = 27432; //0 to 4,294,967,295
    float             float1   = 0.0;

    //Eight byte types
    unsigned long int integer4 = 28432; //Same as unsigned int but 8 bytes
    long int          integer2 = 26432; //Same as int but 8 bytes
    long long int          linteger  = 29432; //-(2^63) to (2^63)-1
    unsigned long long int linteger2 = 30432; //0 to 18,446,744,073,709,551,615
    double                 float2    = 0.0;

    std::cout << "c : " << c << "\n";
    std::cout << "uc: " << uc << "\n";
    std::cout << "c2: " << c2 << "\n";

    std::cout << "Size of bool             : " << sizeof(bool) << "\n";  
    std::cout << "Size of char             : " << sizeof(char) << "\n";  
    std::cout << "Size of unsigned char    : " << sizeof(unsigned char) << "\n";  

    std::cout << "Size of short            : " << sizeof(short) << "\n";  
    std::cout << "Size of short int        : " << sizeof(short int) << "\n";  
    std::cout << "Size of unsigned short   : " << sizeof(unsigned short) << "\n";  

    std::cout << "Size of int              : " << sizeof(int              ) << "\n";  
    std::cout << "Size of unsigned int     : " << sizeof(unsigned int     ) << "\n";
    std::cout << "Size of float            : " << sizeof(float            ) << "\n";
      
    std::cout << "Size of long int         : " << sizeof(long int         ) << "\n";  
    std::cout << "Size of unsigned long int: " << sizeof(unsigned long int) << "\n"; 
    std::cout << "Size of double           : " << sizeof(double           ) << "\n"; 

    
    return 0;
}
```

## 4.2 Typing requirements
In c++ ALL variables must be associated with a type. These types can be any of the following:
- Primitive data types, i.e., `bool, int, float, double, etc.`
- Derived data types, i.e., `function, array, pointer*, reference&`
- Custom defined, i.e., `class, struct, union, enum, typedef`

## 4.3 Initialization of variables
The primitive variables in c++ always need initialization. For example the variables in the following example contains garbage:
```c++
#include <iostream>

int main()
{
    int a;
    float b;
    double c;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
}
```
Output:
```
a: -482443263
b: 2.66031e-36
c: 3.01491e-314
```

It is therefore required to always initialize variables.
```c++
#include <iostream>

int main()
{
    int a=0;
    float b=0.0f;
    double c=0.0;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << "c: " << c << "\n";
}
```
Output:
```
a: 0
b: 0
c: 0
```
## CAUTION: Integer division
Notice the `literal 0.0f`. Literals have types associated with them, for example:
- `000`, numerical values denote `int`
- `123'456'768`, numerical values with `'` separators denote `int`
- `000u`, denotes `unsigned int`
- `000L`, denotes `long int`
- `000ul`, denotes `unsigned long int`
- `0.0f` and `0.f`, the `f` denotes `float`.
- `0.0` and `0.` denotes a `double`

Why am I telling you this: because `(123/246)` is not `0.5` but either `1` or `0` because the compiler assumes you want an `int`. The type deduction happens here because both the numerator and denominator is `int`. If either the numerator or the denominator is `double` then this is avoided because the literal will take the type of the highest order type. There we use `(123.0/246)` to avoid `integer division errors`.