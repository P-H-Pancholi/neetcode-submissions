class Solution {
public:
    vector<int> parents;
    vector<int> ranks;
    
    void DSU(int n){
        parents.resize(n+1);
        ranks.resize(n+1);
        for(int i = 0; i <= n; i++){
            parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int u){
        while(u != parents[u]){
            u = parents[u];
        }
        return u;
    }

    void DisJointUnion(int u, int v){
        int rootU = find(u);
        int rootV = find(v);
        if(ranks[rootU] >= ranks[rootV]){
            parents[rootV] = rootU;
            ranks[rootU] += ranks[rootV];
        }else{
            parents[rootU] = rootV;
            ranks[rootV] += ranks[rootU];
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU(edges.size());
        for(vector v : edges){
            if(find(v[0]) == find(v[1])){
                return {v[0], v[1]};
            }else{
               DisJointUnion(v[0], v[1]); 
            }
        }
        return {-1, -1};
    }
};
