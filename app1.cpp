// variables and functions and scope
//   primitive types
//   local, global, static variables
//   free, member, static functions
//   function return types

//#include <stdio.h>

#include <iostream>

int main(int argc, char* argv[])
{
    printf("Application Name: %s\n", argv[0]);
    for(int i=1; i<argc; ++i) {
//        printf("Argument #%d: %s\n", i, argv[i]);
        std::cout << "Argument #" << i << ": " << argv[i] << "\n";
    }

//    int i=1;
//    while(i<argc) {
//        printf("Argument #%d: %s\n", i, argv[i]);
//        ++i;
//    }

    return 0;
}
