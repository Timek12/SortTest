#include <stdio.h>
#include "bubble_sort_2d.h"

int test_function(int **tab, int size){
    if(tab == NULL || size <= 0)
        return 1;

    for(int i=0; i < size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size-j-1; k++){
                if(*(*(tab + i) + k) > *(*(tab + i) + k + 1)){
                    int temp = *(*(tab + i) + k);
                    *(*(tab + i) + k) = *(*(tab + i) + k + 1);
                    *(*(tab + i) + k + 1) = temp;
                }
            }
        }
    }

    return 0;
}