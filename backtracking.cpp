#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

#define V 6

void tsp(int graph[][V], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){

    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            v[i] = true;
            tsp(graph, v, i, n, count + 1,
                cost + graph[currPos][i], ans);
            v[i] = false;
        }
    }
};


int main(){
    int n = 6;
    int graph[][V] = {	{ 0, 1, 0, 0, 0, 1 },
                        { 1, 0, 1, 0, 5, 5 },
                        { 0, 1, 0, 1, 5, 5 },
                        { 0, 0, 1, 0, 1, 0 },
                        { 0, 5, 5, 1, 0, 1 },
                        { 1, 5, 5, 0, 1, 0 } 	};

    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;

    v[0] = true;
    int ans = INT_MAX;

    auto startTime = steady_clock::now();
    tsp(graph, v, 0, n, 1, 0, ans);
    auto finishTime = steady_clock::now();

    cout << ans << "\n";
    cout << "Time : " << duration_cast<microseconds>(finishTime - startTime).count() << " microsecond";
    return 0;

}
