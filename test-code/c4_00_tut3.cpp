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