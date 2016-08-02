


class Alg {
    public static void sort_insertion(int[] ary) {
        for (int j = 1; j < ary.length; ++j) {
            int key = ary[j];
            int i = j - 1;

            while (i > -1 && ary[i] > key) {
                ary[i + 1] = ary[i];
                --i;
            }

            ary[i + 1] = key;
        }
    }

    public static void main(String[] args) {
        int[] a = new int[] {5, 2, 4, 6, 1, 3};

        Alg.sort_insertion(a);

        for (int x = 0; x < a.length; ++x) {
            System.out.printf("%s ", a[x]);
        }

        System.out.println("");
    }
}