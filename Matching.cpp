
//   EDUCATIONAL DP CONTEST.

// Question: I have to find that how much of the man are in compartible 
// with women . So, i have given the test case in binary 
// form . like    1   1    0
//                0   1    1
//                1   0    0
//   Means first row tells for the first man  and there 1,1,0 means first,
//   second woman is compartible with man while third is not.

//   Second row tells for man and there 0,1,1 tells that first women is 
//   not compartible with woman while second and third woman is compartible with man.

//   Third  row tell for man and there 1,0,0 tells that first woman is compartible 
//   with man while other two women  are not compartible with man. 


#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

// Use a vector for dynamic programming array
vector<vector<int>> dp;

// DP function
int f(int i, int mask, int n, vector<vector<int>>& c) {
    if (i == n + 1) {
        if (mask == 0) return 1; // All women are assigned
        return 0;
    }
    if (dp[i][mask] != -1) return dp[i][mask]; // Memoized result

    int ans = 0;
    for (int w = 1; w <= n; w++) {
        // Correct precedence of bit manipulation
        bool available = ((1 << (w - 1)) & mask) ? 1 : 0; 
        if (available && c[i][w]) { // Check if woman `w` is available and compatible
            ans = (ans + f(i + 1, mask ^ (1 << (w - 1)), n, c)) % mod;
        }
    }
    return dp[i][mask] = ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    // Compatibility matrix (note: input should be 0-indexed or adjust later)
    vector<vector<int>> c(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    // Initialize DP table
    dp = vector<vector<int>>(n + 1, vector<int>(1 << n, -1));

    // Start the DP from first man, and all women are available (mask = 2^n - 1)
    cout << f(1, (1 << n) - 1, n, c) << endl;

    return 0;
}

// 3 
// 0 1 1
// 1 0 1  // My input
// 1 1 1

// 3   // My output
