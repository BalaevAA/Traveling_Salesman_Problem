#include <bits/stdc++.h>

using namespace std;

#define V 4


int solve(int graph[][V], int s) {
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);


    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}


int main() {
    // матричное представление графа
    int graph[][V] = { { 0, 1, 4, 6 },
                       { 1, 0, 5, 2 },
                       { 4, 5, 0, 3 },
                       { 6, 2, 3, 0 } };

    int s = 0;
    cout << solve(graph, s) << endl;
    return 0;
}
