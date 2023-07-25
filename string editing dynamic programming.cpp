#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringEdit(string s, string t) {
    /*
     * Returns the minimum number of insertions, deletions, and substitutions
     * required to convert string s into string t.
     */
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s = "kitten";
    string t = "sitting";
    int distance = stringEdit(s, t);
    cout << "Levenshtein distance between " << s << " and " << t << " is " << distance << endl;
    return 0;
}
