# Chapter 2: The "Hello World!" program

## Objectives:
 - To create your first c++ program.
 - To understand the basic layout of compiling then executing.
 - To understand the very basics of what a program needs.

For your first program we are going to simply write "Hello World" to the screen.

## 2.1 Creating, compiling and executing the program

 1. Open up VSCode and use its "Explorer" tab to the left to open directory where you store this tutorial.

 2. Once you have this folder open, go ahead and create a new file called `tut1.cpp`.

 3. In the editor view add the following text to the file
 ```c++
 #include <iostream>

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}
 ```
 4. Now open a terminal or use the VSCode builtin terminal. Navigate to the folder where you created this file. To check whether you are there or not execute `ls` to see if the folder contains `tut1.cpp`

 5. Now execute the following command to compile an executable from the source file.
 ```
 g++ tut1.cpp -o tut1.exe
 ```
 
 6. Now execute the created executable with the command ```./tut1.exe```  
 The output generated should look something like this:
 ```
 $ ./tut1.exe 
 Hello World!
 $ 
 ```

## 2.2 What are we looking at?
### The `main` function
Let us first strip down this program to its bare bones. We could have just defined the program as
```c++
int main()
{
    return 0;
}
```
and even though it would not do anything the program would still compile and execute.  
The first key aspect here is the definition of the `main` function. This is the entry-point for all terminal-based programs, and if one does not (at minimum) have this in one's code, it would not link into an executable. For example, let us say we wanted to name `main` something different, like `program_start`. The compiler will now have trouble compiling this file, however, the linker will tell us that the symbol `_main` is undefined. This is because it absolutely requires the function `main` to be defined, with matching case and return value of type `int`.

In conclusion, all c++ programs need a `int main()` function.

### What does ```#include <iostream>``` do?
When this program is linked together and executed, the operating system furnishes it with several input/output entities called "streams". One such stream is the output stream to the terminal. We need this stream to make the standard library call `std::cout`. By including the prototype code contained in `iostream` we effectively have all that we need to call the related functions.

### What does ```std::cout << ``` do?
This is a call to the output stream with the output streaming operator (`<<`). What this means is that we are streaming everything past the `<<`-operator to `stdout` (the terminal output). In this particular case we streamed the text `"Hello World!\n"` to the terminal. The `\n` character at the end was an ASCII line-feed character.

### What about the ```return 0;``` business?
Since the function is defined with an `int` return type we need to terminate this function with a return value of that type. This is achieved with the `return` statement.  
If a function has any return type other than `void` then it mush be terminated with a return-call.

It is customary for the `main` function to return an `int` since this normally represents an error code, with `0` being "No error" or "Success".


## Conclusion
This was your first c++ program.