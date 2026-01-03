//just including packages
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "common.h"
#include <assert.h>

int main (int argc, char *argv[]) //main function of the code, takes argument 
{
    //asks the heap for enough space for 1 int (4bytes) and returns the pointer to that memory - p lives in the stack, p* in the heap 
    int *p = malloc(sizeof(int));
    //each process gets their own virtual adress space
    
    assert(p != NULL); // verifies that malloc succeded, if allocation fails - abort  
    
    //returns the process id - each process has its own PID
    //%p prints the memory adress, virtual adress in the heap memory 
    printf("(%d) adress pointed to by p: %p\n", getpid(), p);
    
    *p = 0; //initialize memory writing 0, the value the pointer points to (p -value; *p - adress)
    
    while (1) { //infinite loop, 1 is always 1
        Spin(1);
        *p = *p +1; //reads the value at the heap and adress and increases it by one
        printf("(%d) p: %d\n", getpid(), *p);

    }
    return 0;
}  
