# Chapter 7: Conditional programming with `if` and `switch`

## Objectives:
- To learn the basic syntax of `if`, `else`, statements as well as the `switch` construct  
  
## 7.1 The `if` conditional
The basic syntax for an `if` construct is:
```c++
if (condition)
{
    //Then do everything in here (if condition is true)
}
```

The `if` construct can also have a fall back, using the `else` statement:
```c++
if (condition)
{
    //Do this if the condition is true
}
else
{
    //Do this if the condition is false
}
```

And multiple `if` statements can be chained together:
```c++
if (conditionA)
{
    //Do this if condition A is true
}
else if (conditionB)
{
    //Do this if condition A is false but condition B is true
}
else if (conditionC)
{
    //Do this if conditions A and B is false but condition C is true
}
else
{
    //Do this if all the conditions are false
}
```
↓  
↓  
## 7.2 The need for the scope clarifiers `{}`
The span of an `if` statement terminates one statement passed the condition, i.e., after `if (cond) one_statement;`. We can fold a whole set of statements into this span by supplying the scope clarifiers `{}` so that the `if` construct becomes `if (cond) {statementA; statementB; //etc.}` and therefore supports multiple statements.

In summary, the `{}` are not required if only a single statement is made:
```c++
double a = 2.0;
if (a < 1.0)
  std::cout << "Smaller than one\n";
else 
  std::cout << "Greater than one\n";

//Other code  
```

The following syntax is also allowed:
```c++
double a = 2.0;
if (a < 1.0) std::cout << "Smaller than one\n";
else         std::cout << "Greater than one\n";

//Other code  
```
Note that this is allowed because c++ is not line-based but statement based, with statements ending in a semicolon `;`.

This is also allowed:
```c++
double a = 2.0;
if (a < 1.0) {std::cout << "Smaller than one\n";}
else         {std::cout << "Greater than one\n";}

//Other code  
```
And so is this:
```c++
double a = 2.0;
double b = 0.0;
if (a < 1.0) 
{
    std::cout << "Smaller than one\n";
    b = 1.0;
}
else         
{
    std::cout << "Greater than one\n";
    b = 2.0;
}

//Other code  
```
↓  
↓  
## 7.3 C++ Relational- and logical operators
C++ has the following operators all resulting in a `bool` value of either `true` or `false`.

Relational operators:
| Operation | Meaning               |
|-----------|-----------------------|
| `a==b`    | Equals                |
| `a!=b`    | Not equals            |
| `a<b`     | Smaller than          |
| `a>b`     | Greater than          |
| `a<=b`    | Smaller than or equal |
| `a>=b`    | Greater than or equal |

Logical operators:
| Operation              | Meaning                                          |
|------------------------|--------------------------------------------------|
| `a and b`  or `a && b` | `true` if `a` and `b` are both `true`            |
| `a or b` or `a \|\| b` | `true` if either `a` or `b` is `true`            |
| `not a` or `!a`        | `true` if `a` is false, `false` if `a` is `true` |

Example:
```c++
double a = 2.0;
double b = 0.0;
if (a >= 0.0 and a < 1.0) 
{
    b = 1.0;
}

//Other code  
```
Here `b` is `1.0` only if `a` is greater or equal to `0.0` and smaller than `1.0`.  
↓  
↓  


## 7.4 The `switch` statement
The basic syntax for a `switch` construct is
```c++
switch(expression) 
{
  case x:
    // code block
    break;
  case y:
    // code block
    break;
  default:
    // code block
}
```
The `switch` evaluates the expression and then jumps to a `labeled statement`
that matches the evaluated value of the expression. Because the switch body uses 
labeled statements one has to use the `break` jump-statement to prevent the 
statements, that follow a labeled statement, from executing. For example,
```c++
#include <iostream>

int main() 
{
    int a=0, b=12;
    
    switch (b)
    {
        case 11: a = 1;
        case 12: a = 2;
        case 13: a = 3;
        default: a = 4;
    }
    printf("a=%d\n",a);
    
    return 0;
}
```
Output:
```
a=4
```
The code above outputs `a=4` regardless of the value of `b`. In order for the 
`switch` to perform uniquely for specific values of `b`, i.e., 11, 12 or 13, we 
need to add `break` jump-statement like this
```c++
#include <iostream>

int main() 
{
    int a=0, b=12;
    
    switch (b)
    {
        case 11: a = 1; break;
        case 12: a = 2; break;
        case 13: a = 3; break;
        default: a = 4;
    }
    printf("%d\n",a);
    
    return 0;
}
```
Output:
```
a=2
```
The `switch` statement here will assign a unique value for `a` if `b` is 11, 12 
or 13 and `a=4` otherwise.  
↓    
↓    

## Concluding remark on `switch`

The `switch` construct can be replecated by a combination of `if` constructs.
So where would one use a switch? The quick answer is: to reduce the evaluation 
of expressions. For example the program above coded with `if` constructs would 
look like this:
```c++
#include <iostream>

int main() 
{
    int a=0, b=12;
    
    if (b==11) a = 1;
    else if (b==12) a = 2;
    else if (b==13) a = 3;
    else a = 4;
    printf("%d\n",a);
    
    return 0;
}
```
Here we had to evaluate 3 different logical expressions, whereas the switch 
statement did that once. Whilst this example is fairly small, it is easy to see
that we can save a lot of computing when the list of possible options grow large.