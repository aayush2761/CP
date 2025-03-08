#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
typedef vector<int> vi;
typedef unordered_map<int, int> mii;

int main() {
    fastio();

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vi v1(n), v2(n);
        for (int i = 0; i < n; i++) cin >> v1[i];
        for (int i = 0; i < n; i++) cin >> v2[i];
        
        // Maps to store the maximum consecutive subarray length for each value in v1 and v2
        mii mp1, mp2;
        
        // Compute the maximum consecutive subarray length for v1
        int i = 0;
        while (i < n) {
            int j = i;
            while (i < n && v1[i] == v1[j]) i++;  // Keep incrementing until the value changes
            mp1[v1[j]] = max(mp1[v1[j]], i - j);  // Update the max length for the current value
        }
        
        // Compute the maximum consecutive subarray length for v2
        i = 0;
        while (i < n) {
            int j = i;
            while (i < n && v2[i] == v2[j]) i++;  // Same as above for v2
            mp2[v2[j]] = max(mp2[v2[j]], i - j);  // Update the max length for the current value
        }

        // Compute the result by combining the max lengths from both arrays for the same values
        int maxLength1 = 0;
        for (auto &entry : mp1) {
            int value = entry.first;
            int lengthFromV1 = entry.second;
            int lengthFromV2 = mp2[value];  // If value exists in both v1 and v2, add lengths
            maxLength1 = max(maxLength1, lengthFromV1 + lengthFromV2);
        }
         int maxLength2 = 0;
        for (auto &entry : mp2) {
            int value = entry.first;
            int lengthFromV1 = entry.second;
            int lengthFromV2 = mp1[value];  // If value exists in both v1 and v2, add lengths
            maxLength2 = max(maxLength2, lengthFromV1 + lengthFromV2);
        }

        cout << max(maxLength1,maxLength2) << endl;
    }

    return 0;
}
