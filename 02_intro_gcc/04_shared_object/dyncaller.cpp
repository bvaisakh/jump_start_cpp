#include <stdio.h>
#include <dlfcn.h>

// TODO: Get the program working
// Steps tried
// g++ -c second.cpp
// g++ -c third.cpp
// g++ -shared -fPIC -o libArith.so second.o third.o
// g++ dyncaller.cpp -ldl
// ./a.out
// Program output: Failed to retrive the function ... (Line no: 33)
// Understand the following
//   1. Function pointer
//   2. dlfcn.h header file
//   3. dlopen, dlsym and dlclose functions

typedef int (*BIN_FUNCTION)(int, int);

int main(int argc, char **argv)
{
    void *handle = dlopen("./libArith.so", RTLD_LAZY);

    if (handle = 0)
    {
        printf("Failed to load the program ...\n");
        return 0;
    }

    BIN_FUNCTION bn = (BIN_FUNCTION)dlsym(handle, "Add");

    if (bn == 0)
    {
        printf("Failed to retrive the function ... \n");
        return 0;
    }

    int nc = (*bn)(10, 15);
    printf("Sum is %d \n", nc);
    dlclose(handle);
}