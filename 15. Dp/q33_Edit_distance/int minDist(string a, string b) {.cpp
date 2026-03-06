int minDist(string a, string b) {
    int n = a.size(), m = b.size();
    if (n < m) return minDist(b, a);
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j <= m; j++) prev[j] = j;
    for (int i = 1; i <= n; i++) {
        curr[0] = i; 
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                curr[j] = prev[j - 1]; // Match
            } else {
                curr[j] = 1 + min({
                    prev[j],    // Delete
                    curr[j - 1], // Insert
                    prev[j - 1]  // Replace
                });
            }
        }
        prev = curr; // Move current row to previous for next iteration
    }
    return prev[m];
}