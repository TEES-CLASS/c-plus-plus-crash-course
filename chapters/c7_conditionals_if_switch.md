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
