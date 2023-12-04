/*
 * Author: Muhammad Xayrullayev
 * Date: 04.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int task_1() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        int remainingSum = accumulate(A.begin(), A.end(), 0);

        for (int i = 0; i < N - 2; ++i) {
            vector<int> medians;

            for (int j = i; j < min(i + 3, N); ++j) {
                for (int k = j; k < min(j + 3, N); ++k) {
                    if ((k - j + 1) % 2 == 1) {
                        vector<int> subarray(A.begin() + j, A.begin() + k + 1);
                        sort(subarray.begin(), subarray.end());
                        medians.push_back(subarray[subarray.size() / 2]);
                    }
                }
            }

            int minMedian = *min_element(medians.begin(), medians.end());
            auto minMedianIter = find(A.begin(), A.end(), minMedian);
            A.erase(minMedianIter);

            remainingSum = accumulate(A.begin(), A.end(), 0);
        }

        cout << remainingSum << endl;
    }

    return 0;
}
