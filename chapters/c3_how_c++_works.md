# Chapter 3: How C++ works

## Objectives
- To understand the 4 stages of compiling
- To distinguish between compiler-errors and linking-errors

## 3.1 The hierarchy of a computer program
A long time ago in a galaxy far, far away....

Just kidding. Compiled computer programs can have the ability to execute computer instructions with as little overhead as possible. Of course the lowest level of programming would be to program in `binary`:
```
00001011 10100101 01010110 01100010
```
but if you ever encounter a person, boasting about their ability to code directly in binary, please do me a favor and feel very sorry for him/her/it because they seem to be bragging about something akin to counting all of the individual hair-strands on their heads.

Comprehending and manipulating binary-instructions or -values is not something a human being is supposed to do by hand. We are simply to slow and make mistakes too easily. Therefore, very quickly we gave names to common instructions in a fashion that we can read. We called this `assembly language` and it looks like this:
```as
mov     DWORD PTR [rbp-4], 96
```

Here you can at least decypher a little since it is somewhat more readible but it is still pretty aweful. Hence the next logical step was define this assembly language into something **even more readable**, finally arriving at a `low-level programming language`:
```c++
int a= 96;
```

## 3.2 The four stages of compiling an executable

### 3.2.1 Stage 1: Preprocessing
The basic compilation unit in c++ is a `source file` (a `.cpp` or `.cc` file), NOT a `header file` (`.h` or `.hpp`). Before a source file is compiled the preprocessor reads the source file and processes keywords/items called `preprocessor` directives. For example, the `#include` statement in the program below is a preprocessor directive.
```c++
#include <iostream>

int main()
{
    std::cout << "Hello world!\n";
    return 0;
}
```

After the preprocessor executes, a temporary source file is created with all preproccesor directives expanded. We don't have enough space in this text to show what this looks like. In `g++` one can use the `-E` switch to show the contents of a preprocessed file without compiling it further. I.e.,
```bash
g++ -E source_file.cpp
```
Yeah its nuts. `iostream` literally adds 30k lines of code.

### 3.2.2 Stage 2: "Compiling" text to assembly language
The confusingly named stage is where the low level language is translated to assembly. For example, the following source
```c++
int Minimum(int a, int b)
{
    if (a < b) 
    {
        return a;
    }
    else
    {
        return b;
    }
}
```
is transformed to commands that look like 
```as
\\etc.
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB0
	.long L$set$3
	.byte	0xe
	.uleb128 0x10
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xe
	.uleb128 0
\\etc.
```

To see what this looks like with `g++` we can use the `-S` switch. I.e.,
```bash
g++ -S source_file.cpp -o source_file.ass
```

### 3.2.3 Stage 3: Assembly to machine language
The next stage simply translates the human readible assembly language to machine language, which is not human readible. The symbols for addresses of executable code is contained in an `object`-file that is then said to contain "source objects". To compile a source file without linking we can use `g++` with the `-c` switch
```bash
g++ -c source_file.cpp
```
which will create `source_file.o`

### 3.2.4 Stage 4: Linking objects together
The final stage of compiling an executable is to link together all object files so that the executable instructions connect up into a single address space (which we call the program).

For example: consider the following two source files  
**SourceFile1.cpp**
```c++
#include <iostream>

int Minimum(int,int);

int main()
{   
    std::cout << Minimum(5,3) << "\n";
    return 0;
}
```

**SourceFile2.cpp**
```c++
int Minimum(int a, int b)
{
    if (a < b) 
    {
        return a;
    }
    else
    {
        return b;
    }
}
```

We can either automatically compile and link both these files with the command
```bash
g++ SourceFile1.cpp SourceFile2.cpp -o executable.exe
```
or we can do it manually
```bash
g++ -c SourceFile1.cpp  //creates SourceFile1.o
g++ -c SourceFile2.cpp  //creates SourceFile2.o
g++ SourceFile1.o SourceFile2.o -o executable.exe //Links them together
```

## Conclusion
c++ provides us with the flexibility to compile code in somewhat abstract form. That means that a source file does not necessarily need to include ALL of the code that it calls. This has many benefits:
- Allows us to write libraries of precompiled code,
- Allows for opportunities to reduce compile time (especially when code has not changed), and
- Allows the compiler to apply very intricate optimizations

Whenever you see something like this:
```
Undefined symbols for architecture arm64:
 "__Z7Minimumii", referenced from:
      _main in c3_00_tut2.o
ld: symbol(s) not found for architecture arm64
collect2: error: ld returned 1 exit status
```
this indicates a `linker error`.
Whereas something like this
```
c3_01_minimum.cpp: In function 'int Minimum(int, int)':
c3_01_minimum.cpp:9:17: error: expected ';' before '}' token
    9 |         return b
      |                 ^
      |                 ;
   10 |     }
      |     ~            
```
is a `compile error`.