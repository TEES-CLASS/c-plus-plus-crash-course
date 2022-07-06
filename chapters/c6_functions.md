# Chapter 6: Functions

## Objectives:
- To learn the basic syntax of a function
- To understand the different ways of passing parameters to a function
- To understand how a function can return a value/object, or be used to mutate data

## 6.1 The basic function syntax
The most basic function can be defined as:
```c++
double MultiplyAB(double a, double b)
{
    return a*b;
}
```

The syntax is `ReturnType FunctionName(Param1Type param1, Param2Type param2)`.

Only a single type can be returned, in other words: only 1 "thing" can be returned. A function also has a fixed number of parameters, or as some might call it, arguments.

Example usage:
```c++
#include <iostream>

double MultiplyAB(double a, double b)
{
    return a*b;
}

int main()
{
    double x = 2.0;
    double y = 5.0;

    double c = MultiplyAB(x, y);

    std::cout << "c: " << c << "\n";

    return 0;
}
```
Output:
```
c: 10
```

## 6.2 Passing parameters by value and by reference
If the parameters are passed as just `ParamType` then a copy of the value is made to be used by the function. For example, let us see what happens to `a` if we define the function `MultiplyAB` a little different:
```c++
#include <iostream>

double MultiplyAB(double a, double b)
{
    a *= 5;
    return a;
}

int main()
{
    double x = 2.0;
    double y = 5.0;

    double c = MultiplyAB(x, y);

    std::cout << "c: " << c << "\n";
    std::cout << "x: " << x << "\n";

    return 0;
}
```
Output:
```
c: 10
x: 2
```
Here we can see that the value of `x` has not changed. This is because the function made a copy of `x` into `a` and then operated on `a` as a new variable.

If we defined `ParamType` as a reference, which requires the syntax `ParamType&`, we get the following behavior:
```c++
#include <iostream>

double MultiplyAB(double& a, double b)
{
    a *= 5;
    return a;
}

int main()
{
    double x = 2.0;
    double y = 5.0;

    double c = MultiplyAB(x, y);

    std::cout << "c: " << c << "\n";
    std::cout << "x: " << x << "\n";

    return 0;
}
```
Output:
```
c: 10
x: 10
```
Note here that the `MultiplyAB` function passes the first parameter as a `reference` to a `double`, i.e., `double&`. Therefore `a`, in the scope of the function, actually operates on `x`.

### Important to note:
For this example we used the trivially copied primitive type `double` as a parameter type, so making a copy is not really expensive. Passing a large datastructure by value could, however, result in a large amount of data being copied for no reason. In the realm of scientific computing, imagine passing a vector with millions of values. If we passed the vector by value, it will be copied, but specifying it as a reference does not make a copy.

## 6.3 No return-value functions
A function does not necessarily HAVE to return a value. In this case one can mark the `ReturnType` as `void`. For example the program below just prints the result of multiplying its two parameters:
```c++
#include <iostream>

void PrintATimesB(double a, double b)
{
    std::cout << a*b;
}

int main()
{
    double x = 3.3;
    double y = 2.0;

    PrintATimesB(x,y);
    return 0;
}
```
Output:
```
6.6
```

## 6.4 Mutator functions
On the same note as functions returning `void` is mutator-functions. Such functions are used to mutate a given parameter. For example:
```c++
#include <iostream>

void MultiplyAB(double& a, double b)
{
    a *= b;
}

int main()
{
    double x = 3.3;
    double y = 2.0;

    std::cout << "x before: " << x << "\n";

    MultiplyAB(x,y);

    std::cout << "x after: " << x << "\n";
    return 0;
}
```
Output:
```
x before: 3.3
x after: 6.6
```

## 6.5 Using parameters by reference but distinguishing what may change and what may not
Here are a couple of example:
```c++
#include <iostream>

struct AVeryLargeVector
{
    //With lots of data
};

double DotProduct(const AVeryLargeVector& a, const AVeryLargeVector& b)
{
    double dot_product = 0.0;
    //Do the dot product
    return dot_product;
}

int main()
{
    AVeryLargeVector x; //Maybe size 1 million, filled with random values
    AVeryLargeVector y; //Same size as x but with different values

    double x_dot_y = DotProduct(a, b);
    return 0;
}
```

Forgive me for using the `struct` keyword here. We will be discussing `struct`s later, but for now just assume that it is an object with a lot of data.

We do not want to make a copy of the vectors used in the arguments, therefore we marked them as being passed by reference, i.e., `AVeryLargeVector&`. But we also do not intend on mutating them. Therefore, we marked them `const`. 

Marking a parameter as `const` allows the compiler to save us from ourselves. This is because the compiler will not allow us to accidentally mutate a parameter that we passed by reference.

One can also use the `const` specifier if the parameters are passed by value. We usually do this if we know a parameter is and must remain a constant.