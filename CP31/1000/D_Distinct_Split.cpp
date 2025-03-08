#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> mp1, mp2;

        // Populate mp2 with the frequency of each character in s
        for (int i = 0; i < n; i++) {
            mp2[s[i]]++;
        }

        int res = 0;

        // Iterate through the string, moving characters from mp2 to mp1
        for (int i = 0; i < n - 1; i++) {
            // Add the character to mp1
            mp1[s[i]]++;

            // Remove it from mp2
            mp2[s[i]]--;
            if (mp2[s[i]] == 0) {
                mp2.erase(s[i]);
            }

            // Calculate f(a) + f(b) as the sum of distinct characters in mp1 and mp2
            int distinct_count = mp1.size() + mp2.size();
            res = max(res, distinct_count);
        }

        // Output the result for this test case
        cout << res << endl;
    }

    return 0;
}
