// Author: Andrey Timoshpolsky (shpolsky), shpolsky@gmail.com

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int sqr_dist(int x1, int x2, int y1, int y2) {
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main(int argc, char *argv[]) {
    freopen(argv[1], "rt", stdin);
    string line;
    while (getline(cin, line)) {
        int points[8];
        int idx = 0;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                int n = line[i] - '0';
                if (n == 1 && i < line.length()-1 && line[i + 1] == '0') n = 10;
                points[idx++] = n;
            }
        }
        int dist[6];
        idx = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = i+1; j < 4; j++) {
                dist[idx++] = sqr_dist(points[2*i], points[2*j], 
                        points[2*i+1], points[2*j+1]);
            }
        }
        sort(dist, dist + 6);
        if (dist[0] != 0 && dist[0] == dist[1] && dist[1] == dist[2] && 
                dist[2] == dist[3] && dist[4] == dist[5])
            cout << "true" << endl;
        else cout << "false" << endl;
    }
}

