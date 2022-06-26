# Chapter 5: Simple mathematics in c++

## Objectives:
- To learn about the basic arithmetic operators in c++
- To learn about the basic mathematical functions available in c++

## 5.1 Arithmetic operators
C++ has the following basic arithmetic operators:
- `+` add
- `-` subtract
- `*` multiply
- `/` divide
- `%` modulus division (aka `mod`), i.e., 3%2 = 1 is the remainder after 3 is divided by 2

Any of these can be combined with an `=` to assign a number after the first operation is done (i.e. `a += 3`).
- `+=` add and assign
- `-=` subtract and assign
- `*=` multiply and assign
- `/=` divide and assign
- `%=` modulus assign

All of these operations can also be grouped using parentheses `()`. For example `(2+4)*2 = 12` and `2+4*2 = 10`. In fact, c++, follows the `PEMDAS` principle without the `E` (which is replaced with function calls). Therefore the order of operations is generally left-to-right:
- P - Parentheses
- E - Function calls
- MD - Multiply or Divide
- AS - Add or Subtract

Example:
```c++
#include <iostream>

using namespace std;

int main()
{
    int myInt = 100;

    myInt = myInt / 10; //myInt is now 10
    myInt = myInt * 10; //myInt is back to 100
    myInt = myInt + 50; //myInt is up to 150
    myInt = myInt - 50; //myInt is back to where it started

    myInt = myInt + 100 * 2; // myInt is now 300 because multiplication takes precedence over addition
    myInt = (myInt + 100) * 2; // myInt is now 800 because we have changed the precedence using parentheses

    myInt -= 10; // myInt is now 790 because this line is the short-hand for myInt = myInt - 10;
    myInt = myInt % 100; // myInt is now 90 because % is modulus operator

    std::cout << myInt << endl;
    
    return 0;
}
```


There are also the following special operations on variables, supposing `int a=2`,
- `a++` increments a by 1, i.e., `a = a + 1`
- `++a` also increments a by 1
- `a--` decrements a by 1, i.e., `a = a - 1`
- `--a` also decrements a by 1

The difference between `++a` and `a++` is very subtle. These operations are technically function calls. `++a` returns the value of `a` AFTER the increment whereas `a++` returns the value of `a` BEFORE the increment.

### CAUTION: Get in the habit to always use `++a` instead of `a++`. This is because the `a++` temporarily stores the value of `a` which is additional work. Not normally a huge issue but if you are squeezing out performance then this could be an unnecessary inefficiency.  
↓  
↓  
## 5.2 C++ basic math library
To use the c++ math library we need to put `#include <cmath>` at the top of any source code that wants to use functions like the following:
- `sqrt`, `pow`, `log`, `exp`, `log`,
- `cos`, `sin`, `tan`, `acos`, `asin`, `atan`
- `floor`,`ceil`,
- `fmax`, `fmin`,
- `erf`

For other functions in the library consults the full [c++ math library](https://cplusplus.com/reference/cmath/).

Example:
```c++
#include <iostream>
#include <cmath>

int main()
{
    double a = 2.0; 
    
    std::cout << "sqrt(a): " << sqrt(a) << "\n";
    std::cout << "a^(4.3): " << pow(a,4.3) << "\n";
    std::cout << "e^a    : " << exp(a) << "\n";
    std::cout << "ln(a)  : " << log(a) << "\n";
    std::cout << "sin(a) : " << sin(a) << "\n";
    //etc.

    return 0;
}
```