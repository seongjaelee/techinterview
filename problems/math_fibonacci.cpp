// for n \in {0, 1}, fib(n) = 1
// for n > 2, fib(n) = fib(n-1) + fib(n-2)
// for other values, undefined
// int fib(int n) {
//     if (i < 0) {
//         throw -1;
//     }
//     if (i < 2) {
//         return 1;
//     }
//     else {
//         return fib(n-1) + fib(n-2);
//     }
// }

int fib_internal(int n, int cache *) {
    if (n < 2) {
        return 1;
    }
    if (cache[n] == -1) {
        cache[n] = fib_internal[n-1] + fib_internal[n-2];
    }
    return cache[n];
}

int fib(int n) {
    if (n < 0) {
        throw -1;
    }
    int * cache = new int[n];
    for (int i = 0; i < n; ++i) {
        cache[i] = -1;
    }
    fib_internal(n);
}

// f(i+1) = /gamma * f(i)
// x^2 = x + 1
// x^2 - x - 1 = 0
// x = \frac{1 \pm \sqrt{5}}{2} and x > 0
// x = \frac{1 + \sqrt{5}}{2}
// therefore, f(i) ~ x^i
// floor
// round
// ceil