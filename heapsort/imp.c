#include <stdio.h>
#include <malloc.h>

/*
	The heap-sort has two stages. The first stage orders all
	numbers by their tree level but the actual leaf nodes are
	not assured to be in order. The second stage works up the
	largest number of the root node and two leafs then fixes
	the tree back up.

	In the first stage, it can be visually seen that the tree
	is in a type of ordering. However, because the links between
	the nodes are fixed in the array it makes it problematic to
	simply swap the leafs of each parent without performing many
	operations. Therefore, the second stage begins.

	The problem of swapping the leaf nodes is addressed in the
	second stage but instead of actually swapping them the fact
	that the root node contains the largest number if exploited.
	This number is swapped with the last element of the heap. Then
	the heap size is decreased by one and the tree is partially
	reordered to account for the change.

	Each time the second stage if executed the size of the heap
	decreases by one and the end of the array towards the beginning
	is filled in descending order.
*/

#define PARENT(x) ((x) / 2)
#define LEFT(x) ((x) * 2)
#define RIGHT(x) ((x) * 2 + 1)

int heap_sort_maxify(int *ary, int i, int heapsize) {
	// int ary[] = {5, 2, 1, 7, -4, 10, -5};
	int left = LEFT(i + 1) - 1;
	int right = RIGHT(i + 1) - 1;

	int largest;

	printf("i=%i[%i] left=%i[%i] right=%i[%i]\n", 
		i, ary[i],
		left, ary[left],
		right, ary[right]
	);

	if (left < heapsize && ary[left] > ary[i]) {
		largest = left;
	} else { 
		largest = i;
	}

	if (right < heapsize && ary[right] > ary[largest]) {
		largest = right;
	}

	if (largest != i) {
		printf("moving down the edge.. largest=%i[%i]\n", largest, ary[largest]);

		int tmp = ary[i];
	
		ary[i] = ary[largest];
		ary[largest] = tmp;
	
		heap_sort_maxify(ary, largest, heapsize);
	} else {
		printf("current node is larger than leaf nodes\n");
	}
}

int heap_sort_max_build(int *ary, int cnt) {
	/*
		The reason for the `cnt / 2` is because
		going any higher in index will have no 
		effect since there are no leaf nodes due
		to the size of the array.
	*/
	for (int i = cnt / 2; i > -1; --i) {
		heap_sort_maxify(ary, i, cnt);

		printf("ITERATION: ");
		for (int x = 0; x < cnt; ++x) {
			printf("%i ", ary[x]);
		}
		printf("\n");		
	}
}

int heap_sort(int *ary, int cnt) {
	int heapsize = cnt;

	printf("INITIAL-STATE: ");
	for (int x = 0; x < cnt; ++x) {
		printf("%i ", ary[x]);
	}
	printf("\n");

	heap_sort_max_build(ary, cnt);

	printf("AFTER-MAX-BUILD: ");
	for (int x = 0; x < cnt; ++x) {
		printf("%i ", ary[x]);
	}
	printf("\n");

	for (int i = cnt - 1; i > 0; --i) {
		int tmp = ary[0];
		
		ary[0] = ary[i];
		ary[i] = tmp;

		heapsize--;

		heap_sort_maxify(ary, 0, heapsize);

		printf("debug: ");
		for (int x = 0; x < cnt; ++x) {
			printf("%i ", ary[x]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int ary[] = {5, 2, 1, 7, -4, 10, -5};

	/* exclusive index (count) */
	int cnt = sizeof(ary) / sizeof(int);

	heap_sort(&ary[0], cnt);

	return 0;
}