#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the length of the longest common subsequence (LCS)
int longest_common_subsequence(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();

    // Create a 2D DP array to store the length of LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Calculate LCS
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

// Function to calculate the minimum possible length of the deleted subarray
int min_deleted_subarray_length(vector<int>& A, vector<int>& B) {
    // Calculate the length of the LCS
    int lcs_length = longest_common_subsequence(A, B);
    
    // Minimum possible length of deleted subarray
    return B.size() - lcs_length;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    for (int case_num = 1; case_num <= T; ++case_num) {
        int N;
        cin >> N; // Length of arrays A and B

        vector<int> A(N);
        vector<int> B(N);

        // Input array A
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Input array B
        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        // Calculate and output the minimum possible length of the deleted subarray
        cout << "Case " << case_num << ": " << min_deleted_subarray_length(A, B) << endl;
    }

    return 0;
}
