#pragma once
#include <vector>

class QuickUnion
{
private:
    std::vector<int> id;
    int n;
public:
    QuickUnion(int N) {
        n = N;
        id.resize(n);
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int find(int i) {
        while(id[i] != i) i = id[i];
        return i;
    }

    void union_sets(int i, int j) {
        int u = find(i);
        int v = find(j);

        if (u == v) return;

        id[u] = v;
    }
};
