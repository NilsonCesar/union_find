#pragma once
#include <vector>

class QuickFind
{
private:
    std::vector<int> id;
    int n;
public:
    QuickFind(int N) {
        n = N;
        id.resize(n);
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int find(int i) {
        return id[i];
    }

    void union_sets(int i, int j) {
        int u = find(i);
        int v = find(j);

        if (u == v) return;

        for (int k = 0; k < n; k++) {
            if (id[k] == u) {
                id[k] = v;
            }
        }
    }
};
