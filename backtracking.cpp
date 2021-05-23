#include <bits/stdc++.h>

using namespace std;

#define V 4

void tsp(int graph[][V], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){
    // ≈сли достигнут последний узел и есть ссылка
    // к начальному узлу, т.е. к источнику
    // сохранить минимальное значение от общей стоимости
    // прохождени€ и "ответ"
    // Ќаконец возвращаемс€, чтобы проверить больше возможных значений
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }
    // BACKTRACKING STEP
    // ÷икл дл€ обхода списка смежности
    // узла currPos и увеличение количества
    // на 1 и стоимость по графику [currPos] [i] значение
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
            // ѕометить как посещенные
            v[i] = true;
            tsp(graph, v, i, n, count + 1,
                cost + graph[currPos][i], ans);
            // ѕометить i-й узел как не посещенный
            v[i] = false;
        }
    }
};


//  од драйвера

int main(){
    // n - количество узлов, т. е. V
    int n = 4;
    int graph[][V] = { { 0, 1, 4, 6 },
                       { 1, 0, 5, 2 },
                       { 4, 5, 0, 3 },
                       { 6, 2, 3, 0 } };
    // логический массив дл€ проверки наличи€ узла
    // посещали или нет
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;
    // ѕометить 0-й узел как посещенный
    v[0] = true;
    int ans = INT_MAX;
    // Ќаходим минимальный вес гамильтонова цикла
    tsp(graph, v, 0, n, 1, 0, ans);
    // ans - гамильтонов цикл
    cout << ans;
    return 0;

}
