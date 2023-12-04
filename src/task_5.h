/*
 * Author: Muhammad Xayrullayev
 * Date: 04.12.2023
 * Name: Muhammad Xayrullayev
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> kMostFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequencyMap;

    for (int num : nums) {
        frequencyMap[num]++;
    }

    auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);

    unordered_set<int> addedElements; 
    for (const auto& entry : frequencyMap) {
        minHeap.push(entry);

        // Keep the heap size <= k
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty()) {
        int element = minHeap.top().first;

        if (addedElements.find(element) == addedElements.end()) {
            result.push_back(element);
            addedElements.insert(element);
        }

        minHeap.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

int task_5() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    vector<int> result = kMostFrequent(nums, k);

    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
