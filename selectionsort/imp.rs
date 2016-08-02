

/*
    The major complication is duplicate elements. This should 
*/
fn sort_getsmaller(ary: &mut Vec<i32>, small: Option<(i32, usize)>) -> Option<(i32, usize)> {
    let mut found: Option<(i32, usize)> = Option::None;                                     // c0

    for j in 0..ary.len() {                                                                 // c1*n (best)
        found = match small {                                                               // c2*n (best)
            Option::None => {
                match found {                                                               // c3
                    Option::None => Option::Some((ary[j], j)),                              // c4
                    Option::Some((v, i)) => {               
                        if ary[j] < v {                                                     // c5
                            Option::Some((ary[j], j))                                       // c6
                        } else {            
                            Option::Some((v, i))                                            // c7
                        }
                    }
                }
            },
            Option::Some((sv, si)) => {
                match found {                                                               // c8*n   (worst)
                    Option::None => {
                        if (ary[j] > sv) || (ary[j] == sv && j > si) {                      // c9*? (proba)
                            Option::Some((ary[j], j))                                       // c10*? (proba)
                        } else {    
                            Option::None                                                    // c11*? (proba)
                        }
                    },
                    Option::Some((v, i)) => {
                        if ary[j] < v && ((ary[j] > sv) || (ary[j] == sv && j > si)) {      // c12*n
                            Option::Some((ary[j], j))                                       // c13*?
                        } else {        
                            Option::Some((v, i))                                            // c14*n (proba)
                        }
                    }
                }
            },
        }
    }

    /*
        c1*n + c2*n + c8*n + c12*n + c14*n

        n + n + n + 4n + n = n

        worst-case = o(n)
        best-case = o(n)
    */

    found
}

fn sort_selection(ary: &mut Vec<i32>) {
    let mut small: Option<(i32, usize)> = Option::None;

    for j in 0..ary.len() - 1 {                     // c0
        small = sort_getsmaller(ary, small);        // c1
        // The exchange.
        match small {                               // c2
            Option::None => return (),
            Option::Some(v) => {
                let tmp = ary[j];                   // c3
                ary[j] = v.0;                       // c4
                ary[v.1] = tmp;                     // c5
            },
        };
    }

    /*
        c0*n + c1*n + c2*n + c3*n + c4*n + c5*n

        n + n*n + n + n + n + n = 5n + n^2

        worst-case = o(n^2)
        best-case = o(n^2)
    */
}

fn main() {
    let mut ary: Vec<i32> = Vec::new();

    // Add duplicates to prove it can handle them.
    ary.push(5i32);
    ary.push(2i32);
    ary.push(4i32);
    ary.push(6i32);
    ary.push(1i32);
    ary.push(3i32);
    ary.push(6i32);
    ary.push(1i32);
    ary.push(2i32);

    sort_selection(&mut ary);

    println!("{:?}", ary);
}