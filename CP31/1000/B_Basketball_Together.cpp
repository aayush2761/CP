#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size(); // Number of roads (or N+1 cities)
    unordered_map<int, vector<pair<int, bool>>> graph; // Stores the graph and direction

    // Create the bidirectional graph
    for (int i = 0; i < N; i++) {
        graph[A[i]].push_back({B[i], true});  // True means original direction A -> B
        graph[B[i]].push_back({A[i], false}); // False means reverse direction B -> A
    }

    // BFS or DFS from city 0 to calculate the number of roads to reorient
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(0);
    visited[0] = true;
    int reorientCount = 0;

    while (!q.empty()) {
        int city = q.front();
        q.pop();

        for (auto &neighbor : graph[city]) {
            int nextCity = neighbor.first;
            bool isOriginalDirection = neighbor.second;

            if (!visited[nextCity]) {
                visited[nextCity] = true;
                if (isOriginalDirection) {
                    // If the road is in the original direction, we need to reorient it
                    reorientCount++;
                }
                q.push(nextCity);
            }
        }
    }

    return reorientCount;
}

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

int slv(vector<int>& A, vector<int>& B, int N) {
    unordered_map<int, vector<pair<int, int>>> adj;

    // Build adjacency list
    for (int i = 0; i < N; ++i) {
        adj[A[i]].push_back({B[i], 1});
        adj[B[i]].push_back({A[i], 0});
    }

    int r = 0;
    vector<bool> vis(N + 1, false);
    stack<pair<int, int>> st;
    st.push({0, -1});
    vis[0] = true;

    // DFS traversal
    while (!st.empty()) {
        auto [n, p] = st.top();
        st.pop();
        for (auto& [nei, d] : adj[n]) {
            if (!vis[nei]) {
                vis[nei] = true;
                if (d == 1) {
                    r += 1;
                }
                st.push({nei, n});
            }
        }
    }

    return r;
}


int main() {
    vector<int> A1 = {0, 2, 2, 3};  // Example 1
    vector<int> B1 = {1, 1, 4, 4};
    cout << "Result for Example 1: " << slv(A1, B1, 4) << endl; // Should print 2

    vector<int> A2 = {1, 6, 6, 3, 0, 5};  // Example 2
    vector<int> B2 = {6, 2, 0, 0, 4, 0};
    cout << "Result for Example 2: " << slv(A2, B2, 6) << endl; // Should print 2

    vector<int> A3 = {0, 1, 1, 1, 1, 1};  // Example 3
    vector<int> B3 = {1, 2, 3, 4, 5, 6};
    cout << "Result for Example 3: " << slv(A3, B3, 6) << endl; // Should print 5

    return 0;
}
