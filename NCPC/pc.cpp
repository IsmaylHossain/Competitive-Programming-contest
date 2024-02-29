#include <bits/stdc++.h>
#include <vector>

using namespace std;

int min_deleted_subarray_length(vector<int>& A, vector<int>& B) {
    int n = A.size();

    int start = -1;
    int end = -1;
    int num = 0;

    for (int i = 0, j = n - 1; i < n; ++i, j--) {
        if (find(A.begin(), A.end(), B[i])==A.end()) {
            start = i;
            break;
        }
        num++;
    }
    
    if (start == -1) {
        return 0; // No deletion required
    }

    for (int i = n - 1; i >= num; i--) {
        if (find(A.begin(), A.end(), B[i])==A.end()) {
            end = i;
            break;
        }
    }

    int result = end - start + 1;

    return result;
}

int main() {
    int T;
    cin >> T;

    for (int case_num = 1; case_num <= T; ++case_num) {
        int N;
        cin >> N;

        vector<int> A(N);
        vector<int> B(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
        }

        cout << "Case " << case_num << ": " << min_deleted_subarray_length(A, B) << endl;
    }

    return 0;
}
