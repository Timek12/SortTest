#include "my_quicksort.h"
#include "types_utils.h"

int quicksort_asc(int l, int r, int tab[], int tabSize)
{

    if(tabSize <= 0 || r < l || r < 0 || l < 0 ){
        return 1;
    }


    int i = l - 1, j = r + 1;

    int pivot = tab[(l + r) / 2];
    if(r > l) {
        while (1) {
            while (pivot > tab[++i]);

            while (pivot < tab[--j]);

            if (i <= j) {
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            } else
                break;
        }

        if (j > l)
            quicksort_asc(l, j, tab, tabSize);
        if (i < r)
            quicksort_asc(i, r, tab, tabSize);

    }
    if(r-l+1 != tabSize)
        return 1;
    return 0;


}

int quicksort_desc(int l, int r, int tab[], int tabSize)
{
    if(tabSize <= 0 || r < l || r < 0 || l < 0)
    {
        return 1;
    }

    int i = l;
    int j = r;
    int temp = tab[i];


    if(l < r)
    {
        while(i < j)
        {
            while (tab[j] <= temp && i < j)
            {
                j--;
            }
            tab[i] = tab[j];
            while(tab[i] >= temp && i < j)
            {
                i++;
            }
            tab[j] = tab[i];
        }
        tab[i] = temp;
        quicksort_desc(l, i-1, tab, tabSize);
        quicksort_desc(j+1, r, tab, tabSize);
    }
    if(r-l+1 != tabSize)
        return 1;

    return 0;


}

int quicksort(int tab[], int size, enum direction dir)
{
    int x;
    if(dir == 1)
        x = quicksort_asc(0, size-1, tab, size);
    else
        x = quicksort_desc(0, size-1, tab, size);

    if(x == 1 || dir != 1 && dir != 2)
        return 1;
    return 0;
}

