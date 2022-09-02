# Chapter 8: Loops

## Objectives:
- To learn the basic syntax of the `for` and `while` loops
- To understand the use of jump-statements

## 8.1 The basic `for` loop
Here is the basic syntax of a `for` loop
```c++
for (statement 1; statement 2; statement 3) 
{
  // code block to be executed
}
```
- Statement 1 is executed once at the start of the loop.  
- Statement 2 is executed **before** every attempted execution of the code block 
(only if it evaluates to `true` will the block execute).  
- Statement 3 will be executed every time
the code block has been executed.

The simplest use case of a `for` loop is 
```c++
for (int i=0; i<10; ++i)
{
    //code block i goes from 0 to 9
}
```

## 8.2 The basic `while` loop
Here is the basic syntax of a `while` loop
```c++
while (statement)
{
    //code block to be executed
}
```
The statement is executed before the loop starts and after every execution of the
code block. The code block is only executed if the statement evaluates to `true`.

The simplest use case of a `while` loop is
```c++
int i=0;
while (i<10)
{
    //code block
    ++i;
}
```
The loop above is equivalent to that of the `for` loop.

## 8.3 Jump-statements
Some jump-statements have already been encountered in previous chapters, e.g.,
`return` and `break`. An additional jump-statement, that is often useful 
within loops is the `continue` jump-statement.

Whilst `break` exits the loop completely, the `continue` statement simply exits
the execution of the current code block. For example,
```c++
for (int i=0; i<10; ++i)
{
    if (i==3) continue;
    //code block i goes from 0 to 9, but i=3 is skipped
}
```
One can also use the `continue` statement in `while`-loops, however, that can be
tricky. For `while`-loops it is more natural to use `break` statements
```c++
int i=0;
while (i<10)
{
    if (some_condition) break;
    //code block
    ++i;
}
```
Think for example about an iteration scheme that has to terminate when a 
certain convergence criteria is met.