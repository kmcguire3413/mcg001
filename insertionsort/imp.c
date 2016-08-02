/*
    NP-complete
        No efficient solution known. If one is found then there is one for all NP-complete problems even if unknown.
    loop invariant


*/
#include <stdio.h>

void sort_insertion(int *ary, int arycnt) {
    int j;
    int key;
    int i;

    for (j = 1; j < arycnt; ++j) {
        key = ary[j];
        i = j - 1;
        while (i > -1 && ary[i] > key) {
            ary[i + 1] = ary[i];
            --i;
        }

        ary[i + 1] = key;
    }
}

int main(int argc, char *argv) {
    int x;
    int ary[] = {5, 2, 4, 6, 1, 3};

    sort_insertion(&ary[0], sizeof(ary) / sizeof(int));

    for (x = 0; x < sizeof(ary) / sizeof(int); ++x) {
        printf("%i ", ary[x]);
    }
    printf("\n");

    return 0;
}