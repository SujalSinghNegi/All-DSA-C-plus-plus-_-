/*
Quick Formula Explanation:

If n % 4 == 0: The result is n

If n % 4 == 1: The result is 1

If n % 4 == 2: The result is n + 1

If n % 4 == 3: The result is 0


*/
int xorUptoN(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}
