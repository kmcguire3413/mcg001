#include <iostream>
#include <iomanip>

using namespace std;

template <typename T> void print_ary(T *ary, int count, int a, int b) {
	for (int i = 0; i < count; ++i) {
		if (i == a || i == b) {
			cout << "(" << ary[i] << ")" << " ";
		} else {
			cout << " " << ary[i] << "  ";
		}
	}

	cout << setw(0);
}

template <typename T> void exchange(T &a, T & b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T> void stooge_sort(T *ary, int start, int end, int debugcount) {
	cout << "call: " << start << "<-->" << end << endl;

	if (ary[start] > ary[end]) {
		cout << "swap    : ";
		print_ary(ary, debugcount, start, end);
		cout << endl;
		exchange(ary[start], ary[end]);
	}

	if (start + 1 >= end) {
		return;
	}

	int k = (end - start + 1) / 3; // c

	stooge_sort(ary, start, end - k, debugcount); // f
	stooge_sort(ary, start + k, end, debugcount); // f
	stooge_sort(ary, start, end - k, debugcount); // f
}

int main(int argc, char *argv[]) {
	int ary[] = {0, -3, 4, 8, 10, -5, -10, 8, 3};

	int count = sizeof(ary) / sizeof(int);

	stooge_sort(ary, 0, count - 1, count);

	cout << "state: ";

	print_ary(ary, count, 0, count - 1);

	cout << endl;
}