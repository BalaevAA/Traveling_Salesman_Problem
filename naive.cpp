#include<bits/stdc++.h>
#include<chrono>

using namespace std;
using namespace std::chrono;

#define V 6


int solve(int graph[][V], int start) {

    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != start)
            vertex.push_back(i);


    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = start;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][start];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}


int main() {
    int graph[][V] = {	{ 0, 1, 7, 7, 7, 1 },
                        { 1, 0, 1, 7, 5, 5 },
                        { 7, 1, 0, 1, 5, 5 },
                        { 7, 7, 1, 0, 1, 7 },
                        { 7, 5, 5, 1, 0, 1 },
                        { 1, 5, 5, 7, 1, 0 } 	};

    int start = 0;
    auto startTime = steady_clock::now();
    int res = solve(graph, start);
    auto finishTime = steady_clock::now();

    cout << res << "\n";
    cout << "Time : " << duration_cast<microseconds>(finishTime - startTime).count() << " microsecond";
    return 0;
}
