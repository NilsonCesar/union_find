#pragma once
#include <vector>

// Optimized with path compression and weighted union heuristics
class UnionFindOptimized
{
private:
    std::vector<int> id;
    std::vector<int> sz;
    int n;
public:
    UnionFindOptimized(int N) {
        n = N;
        id.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            id[i] = i;
    }

    int find(int i) {
        if (id[i] == i) return i;
        return id[i] = find(id[i]);
    }

    void union_sets(int i, int j) {
        int u = find(i);
        int v = find(j);

        if (u == v) return;

        if (sz[u] < sz[v]) {
            id[u] = v;
            sz[v] += sz[u];
        } else {
            id[v] = u;
            sz[u] += sz[v];
        }
    }
};
