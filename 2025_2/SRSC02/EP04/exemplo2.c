#include <stdio.h>
#include <omp.h>

int main(void) {
    int ID = 0;

    #pragma omp parallel 
    {
        printf(" hello (%d) ", ID);
        printf(" world (%d) \n", ID);
    }

    return 0;
}
