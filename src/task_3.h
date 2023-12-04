/*
 * Author: Muhammad Xayrullayev
 * Date: 04.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int task_3() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N), B(M), result(N + M);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < M; ++i) {
            cin >> B[i];
        }

        merge(A.begin(), A.end(), B.begin(), B.end(), result.begin(), greater<int>());

        for (const int& num : result) {
            cout << num << " ";
        }

        cout << endl;
    }

    return 0;
}
