class Solution {
public:
    class DSU {
    public:

    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unions(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b)  return;
        if(size[a] < size[b])  swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};
    int countComponents(int n, vector<vector<int>>& edges) {
        int comp=n;
        DSU dsu(n);
        for(auto e:edges){
             if(dsu.find(e[0])!=dsu.find(e[1])){ comp--; dsu.unions(e[0],e[1]);}
        }
        return comp;
    }
};
