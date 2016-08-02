/*
    See /selectionsort/imp.rs for computational complexity analysis.
*/

class PickNextSmallest {
    public int val;
    public int ndx;
    public boolean have;
    private int[] ary;

    public PickNextSmallest(int[] ary) {
        this.ary = ary;
        this.have = false;
        this.val = 0;
        this.ndx = 0;
    }

    public void next() {
        int fnd_val = 0;
        int fnd_ndx = 0;
        boolean fnd = false;

        for (int j = 0; j < this.ary.length; ++j) {
            if (this.have) {
                if (fnd) {
                    if (
                        ((ary[j] > this.val) || (ary[j] == this.val && j > this.ndx)) && ary[j] < fnd_val
                    ) {
                        fnd_val = ary[j];
                        fnd_ndx = j;
                        fnd = true;
                    }
                } else {
                    if (
                        (ary[j] > this.val) || (ary[j] == this.val && j > this.ndx)
                    ) {
                        fnd_val = ary[j];
                        fnd_ndx = j;
                        fnd = true;
                    }
                }
            } else {
                if (fnd) {
                    if (ary[j] < fnd_val) {
                        fnd_val = ary[j];
                        fnd_ndx = j;
                        fnd = true;
                    }
                } else {
                    fnd_val = ary[j];
                    fnd_ndx = j;
                    fnd = true;
                }
            }
        }

        this.val = fnd_val;
        this.ndx = fnd_ndx;
        this.have = fnd;
    }
}

class Alg {
    public static void sort_selection(int[] ary) {
        PickNextSmallest pns = new PickNextSmallest(ary);

        for (int j = 0; j < ary.length - 1; ++j) {
            pns.next();

            if (!pns.have) {
                break;
            }

            int tmp = ary[j];
            ary[j] = ary[pns.ndx];
            ary[pns.ndx] = tmp;
        }
    }

    public static void main(String[] args) {
        int[] a = new int[] {5, 2, 4, 6, 1, 3, 6, 5, 1, 2, -4, 10, -100};

        Alg.sort_selection(a);

        for (int x = 0; x < a.length; ++x) {
            System.out.printf("%s ", a[x]);
        }

        System.out.println("");
    }
}