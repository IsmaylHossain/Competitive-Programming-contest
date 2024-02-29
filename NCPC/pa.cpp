#include <iostream>
#include <vector>

using namespace std;

// Function to find the first and last differing indices between arrays A and B
pair<int, int> find_differing_indices(const vector<int>& A, const vector<int>& B) {
    int start_index = -1, end_index = -1;
    int n = A.size();

    // Find the first differing index
    for (int i = 0; i < n; ++i) {
        if (A[i] != B[i]) {
            start_index = i;
            break;
        }
    }

    // Find the last differing index
    for (int i = n - 1; i >= 0; --i) {
        if (A[i] != B[i]) {
            end_index = i;
            break;
        }
    }

    return make_pair(start_index, end_index);
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

        // Find the first and last differing indices
        pair<int, int> differing_indices = find_differing_indices(A, B);

        // Calculate the length of the smallest subarray
        int min_length = (differing_indices.first == -1) ? 0 : differing_indices.second - differing_indices.first + 1;

        cout << "Case " << case_num << ": " << min_length << endl;
    }

    return 0;
}
