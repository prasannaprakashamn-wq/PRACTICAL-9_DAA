#include <iostream>
using namespace std;

int main() {
    int n = 4;

    int cost[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    int visited[4] = {1, 0, 0, 0};
    int edges = 0, total = 0;

    cout << "Edges in MST:\n";

    while (edges < n - 1) {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] != 0 &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            cout << "Graph is disconnected!\n";
            return 0;
        }

        cout << u + 1 << " - " << v + 1
             << " : " << min << endl;

        visited[v] = 1;
        total += min;
        edges++;
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}
