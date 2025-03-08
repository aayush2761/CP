#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pqCmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first < b.first; // Max-heap for modulo value
        } else {
            return a.second > b.second; // Min-heap for index if modulo values are same
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, pqCmp> pq;  // Custom priority queue

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x % k == 0) {
                cout << i + 1 << ' ';  // Output directly if divisible by k
            } else {
                pq.emplace(x % k, i + 1);  // Insert (modulo, index) into priority queue
            }
        }

        // Extract elements from priority queue and print their indices
        while (!pq.empty()) {
            cout << pq.top().second << ' ';
            pq.pop();
        }

        cout << endl;  // Newline after each test case
    }

    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// bool cmp(pair<int, int>& a, pair<int, int>& b) {
//     if (a.first != b.first) {
//         return a.first > b.first; // Sort based on descending order of modulo value
//     } else {
//         return a.second < b.second; // If modulo values are same, maintain the original order
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n, k;
//         cin >> n >> k;
//         vector<pair<int, int>> v;

//         for (int i = 0; i < n; ++i) {
//             int x;
//             cin >> x;
//             if (x % k == 0) {
//                 cout << i + 1 << ' ';  // Output the index directly if divisible by k
//             } else {
//                 v.emplace_back(x % k, i + 1);  // Store (modulo, index)
//             }
//         }

//         sort(v.begin(), v.end(), cmp);  // Sort based on custom comparator

//         for (auto& it : v) {
//             cout << it.second << ' ';  // Output the sorted indices
//         }

//         cout << endl;  // Newline after each test case
//     }

//     return 0;
// }


