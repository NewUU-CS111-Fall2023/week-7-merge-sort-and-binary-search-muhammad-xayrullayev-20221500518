/*
 * Author: Muhammad Xayrullayev
 * Date: 04.12.2023
 * Name: Muhammad Xayrullayev
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int task_2() {
    int n;
    cin >> n;

    vector<int> Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> Y[i];
    }

    vector<pair<int, int>> distances;

    for (int i = 0; i < n; ++i) {
        distances.push_back({abs(Y[i] - (i + 1)), i});
    }

    sort(distances.begin(), distances.end(), greater<pair<int, int>>());

    long long beautifulness = 0;

    for (int i = 0; i < n; ++i) {
        beautifulness += 1LL * abs(Y[i] - (i + 1));
    }

    for (int i = 0; i < 2; ++i) {
        int idx = distances[i].second;
        int targetIdx = i % 2 == 0 ? idx + 1 : idx - 1;

        if (targetIdx >= 0 && targetIdx < n) {
            long long newBeautifulness = beautifulness - distances[i].first + abs(Y[idx] - targetIdx) + abs(Y[targetIdx] - idx);
            beautifulness = max(beautifulness, newBeautifulness);
        }
    }

    cout << beautifulness << endl;

    return 0;
}
