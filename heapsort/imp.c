#include <stdio.h>
#include <malloc.h>

int merge(int *ary, int start, int middle, int end) {
	int leftsz = (middle - start);
	int rightsz = (end - middle);

	int *left = (int*)malloc(sizeof(int) * leftsz);
	int *right = (int*)malloc(sizeof(int) * rightsz);

	for (int k = 0; k < leftsz; ++k) {
		left[k] = ary[start + k];
	}

	for (int k = 0; k < rightsz; ++k) {
		right[k] = ary[middle + k];
	}

	int leftndx = 0;
	int rightndx = 0;

	for (int k = start; k < end; ++k) {
		/*
			(1) If the rightndx shows the right side is empty then choose the left.
			(2) If the leftndx shows the left side is not empty then compare.
		*/
		if (rightndx == rightsz || (leftndx != leftsz && left[leftndx] < right[rightndx])) {
			ary[k] = left[leftndx++];
		} else {
			ary[k] = right[rightndx++];
		}
	}

	/*
		The segment specified from start (inclusive) to end (exclusive)
		is now sorted.
	*/

	free(left);
	free(right);
}

int merge_sort(int *ary, int start, int end, int debug_size) {
	/* The `q` computation if pulled out the loop for understanding. */
	int q = (start + end) / 2;
	
	printf("start=%i q=%i end=%i\n", start, q, end);

	if (start < end - 1) {

		merge_sort(ary, start, q, debug_size);
		merge_sort(ary, q, end, debug_size);
		
		printf("would sort %i -> %i -> %i\n", start, q, end);

		merge(ary, start, q, end);

		printf("debug: ");
		for (int i = 0; i < debug_size; ++i) {
			printf("%i ", ary[i]);
		}

		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int ary[] = {5, 2, 1, 7, -4, 10, -5};

	/* exclusive index (count) */
	int cnt = sizeof(ary) / sizeof(int);

	merge_sort(&ary[0], 0, cnt, cnt);

	return 0;
}