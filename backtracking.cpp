#include <bits/stdc++.h>

using namespace std;

#define V 4

void tsp(int graph[][V], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){
    // ���� ��������� ��������� ���� � ���� ������
    // � ���������� ����, �.�. � ���������
    // ��������� ����������� �������� �� ����� ���������
    // ����������� � "�����"
    // ������� ������������, ����� ��������� ������ ��������� ��������
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }
    // BACKTRACKING STEP
    // ���� ��� ������ ������ ���������
    // ���� currPos � ���������� ����������
    // �� 1 � ��������� �� ������� [currPos] [i] ��������
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            // �������� ��� ����������
            v[i] = true;
            tsp(graph, v, i, n, count + 1,
                cost + graph[currPos][i], ans);
            // �������� i-� ���� ��� �� ����������
            v[i] = false;
        }
    }
};


// ��� ��������

int main(){
    // n - ���������� �����, �. �. V
    int n = 4;
    int graph[][V] = { { 0, 1, 4, 6 },
                       { 1, 0, 5, 2 },
                       { 4, 5, 0, 3 },
                       { 6, 2, 3, 0 } };
    // ���������� ������ ��� �������� ������� ����
    // �������� ��� ���
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;
    // �������� 0-� ���� ��� ����������
    v[0] = true;
    int ans = INT_MAX;
    // ������� ����������� ��� ������������ �����
    tsp(graph, v, 0, n, 1, 0, ans);
    // ans - ����������� ����
    cout << ans;
    return 0;

}