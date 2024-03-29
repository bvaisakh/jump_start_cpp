#include <stdio.h>
#include <dlfcn.h>

typedef int (*BIN_FUNCTION)(int, int);

int main(int argc, char **argv)
{
    void *handle = dlopen("./libArith.a", RTLD_LAZY);

    if (handle == 0)
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