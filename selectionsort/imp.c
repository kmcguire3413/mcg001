/*
    NP-complete
        No efficient solution known. If one is found then there is one for all NP-complete problems even if unknown.
    loop invariant


*/
#include <stdio.h>

/*
    See /selectionsort/imp.rs for theta notation (computational complexity).
*/

void sort_getsmaller(int *ary, int arycnt, int *small_val, int *small_ndx, int *small) {
    int fnd_val;
    int fnd_ndx;
    int fnd = 0;
    int j;

    for (j = 0; j < arycnt; ++j) {
        if (*small) {
            if (fnd) {
                if (   
                    ((ary[j] == *small_val && j > *small_ndx) ||
                    (ary[j] > *small_val)) && (ary[j] < fnd_val)
                ) {
                    fnd_val = ary[j];
                    fnd_ndx = j;
                    fnd = 1;
                }                
            } else {
                if (   
                    (ary[j] == *small_val && j > *small_ndx) ||
                    (ary[j] > *small_val)
                ) {
                    fnd_val = ary[j];
                    fnd_ndx = j;
                    fnd = 1;
                }
            }
        } else {
            if (fnd) {
                if (fnd_val > ary[j]) {
                    fnd_val = ary[j];
                    fnd_ndx = j;
                    fnd = 1;
                }
            } else {
                fnd_val = ary[j];
                fnd_ndx = j;
                fnd = 1;
            }
        }
    }

    *small_val = fnd_val;
    *small_ndx = fnd_ndx;
    *small = fnd;
}

void sort_selection(int *ary, int arycnt) {
    int small_val = 0;
    int small_ndx = 0;
    int small = 0;
    int tmp;
    int j;

    for (j = 0; j < arycnt - 1; ++j) {
        sort_getsmaller(ary, arycnt, &small_val, &small_ndx, &small);
        if (!small) {
            break;
        }

        printf("small_val:%i small_ndx:%i small:%i\n", small_val, small_ndx, small);

        tmp = ary[j];
        ary[j] = ary[small_ndx];
        ary[small_ndx] = tmp;
    }
}

int main(int argc, char *argv) {
    int x;
    int ary[] = {5, 2, 4, 6, 1, 3, 6, 1, 2, 4, -5};

    sort_selection(&ary[0], sizeof(ary) / sizeof(int));

    for (x = 0; x < sizeof(ary) / sizeof(int); ++x) {
        printf("%i ", ary[x]);
    }
    printf("\n");

    return 0;
}