#include <stdio.h>
#include "sort.h"

int bubble_sort_asc(int tab[], int size)
{
    if(size <= 0){
        return 1;
    }
    int flag = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(tab[j] > tab[j+1]){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
            else{
                flag++;
            }
        }
        if(flag == size-1){
            return 0;
        }

        flag = 0;
    }
    return 0;
}

int bubble_sort_desc(int tab[], int size)
{
    if(size <= 0){
        return 1;
    }
    int flag = 0;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-1; j++){
            if(tab[j] < tab[j+1]){
                int temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
            else{
                flag++;
            }
        }
        if(flag == size-1){
            return 0;
        }
        flag = 0;
    }
    return 0;
}



int bubble_sort(int tab[], int size, enum direction dir)
{
    int x;
    if(dir % 2 != 0){
        x = bubble_sort_asc(tab, size);
    }
    else{
        x = bubble_sort_desc(tab, size);
    }

    if(x == 1 || dir != 1 && dir != 2)
        return 1;
    return 0;
}


int selection_sort_asc(int tab[], int size)
{
    if(size <= 0)
        return 1;

    for(int step=0; step<size-1; step++){
        int min = step;
        for(int i=step + 1;  i <size; i++){
            if(tab[i] < tab[min]){
                min = i;
            }
        }
        int temp = tab[min];
        tab[min] = tab[step];
        tab[step] = temp;

    }

    return 0;
}

int selection_sort_desc(int tab[], int size)
{
    if(size <= 0)
        return 1;

    for(int step=0; step< size-1; step++){
        int max = step;
        for(int i=step + 1;  i <size; i++){
            if(tab[i] > tab[max]){
                max = i;
            }
        }
        int temp = tab[max];
        tab[max] = tab[step];
        tab[step] = temp;
    }

    return 0;
}

int selection_sort(int tab[], int size, enum direction dir)
{
    int x;
    if(dir == 1)
        x = selection_sort_asc(tab, size);
    else
        x = selection_sort_desc(tab, size);
    if(x == 1 || dir != 1 && dir != 2)
        return 1;
    return 0;
}

int insertion_sort_asc(int tab[], int size)
{
    if(size <= 0)
        return 1;
    int j, elem;
    for(int i=1; i<size; i++){
        elem = tab[i];
        j = i - 1;
        while(j >= 0 && tab[j] > elem){
            tab[j+1] = tab[j];
            j = j - 1;
        }
        tab[j+1] = elem;

    }
    return 0;
}

int insertion_sort_desc(int tab[], int size)
{
    if(size <= 0)
        return 1;
    int j, elem;

    for(int i=1; i<size; i++){
        elem = tab[i];
        j = i - 1;
        while(j >= 0 && tab[j] < elem){
            tab[j+1] = tab[j];
            j = j - 1;
        }
        tab[j+1] = elem;

    }

    return 0;
}

int insertion_sort(int tab[], int size, enum direction dir)
{
    int x;
    if(dir == 1)
        x = insertion_sort_asc(tab, size);
    else
        x = insertion_sort_desc(tab, size);
    if(x == 1 || dir != 1 && dir != 2){
        return 1;
    }
    return 0;
}

int sort(int tab[], int size, enum direction dir, enum algorithm alg)
{
    int x;
    if(alg == 1){
        x = bubble_sort(tab, size, dir);
    }
    else if(alg == 2){
        x = selection_sort(tab, size, dir);
    }
    else
        x = insertion_sort(tab, size, dir);
    if(x == 1 || alg != 1 && alg != 2 && alg != 3 || dir != 1 && dir != 2){
        return 1;
    }
    return 0;
}