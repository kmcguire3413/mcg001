




fn sort_insertion(ary: &mut Vec<i32>) {
    for j in 1..ary.len() {
        let key = ary[j];
        let mut i = (j - 1) as isize;
        while i > -1 && ary[i as usize] > key {
            ary[i as usize + 1] = ary[i as usize];
            i = i - 1;
        }

        ary[(i + 1) as usize] = key;
    }
}

fn main() {
    let mut ary: Vec<i32> = Vec::new();

    // {5, 2, 4, 6, 1, 3};

    ary.push(5i32);
    ary.push(2i32);
    ary.push(4i32);
    ary.push(6i32);
    ary.push(1i32);
    ary.push(3i32);

    sort_insertion(&mut ary);

    println!("{:?}", ary);
}