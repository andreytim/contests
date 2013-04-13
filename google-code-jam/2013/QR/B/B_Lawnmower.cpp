#include <iostream>
#include <stdio.h>

using namespace std;

void solve() {
    
    int N, M;
    cin >> N >> M;
    int loan[N][M];    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> loan[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            int v = 0, h = 0;
            while (v < N && loan[v][j] <= loan[i][j]) v++;
            while (h < M && loan[i][h] <= loan[i][j]) h++;
            if (v != N && h != M) {
                cout << " NO";
                return;
            }
        }
    }
    cout << " YES";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i+1 << ":";
        solve();
        cout << endl;
    }
}
