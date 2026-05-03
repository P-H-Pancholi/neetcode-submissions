class Solution
{
public:
    vector<int> Parents;
    vector<int> ranks;

    void DSU(int n)
    {
        Parents.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; i++)
        {
            Parents[i] = i;
            ranks[i] = 1;
        }
    }

    int find(int u)
    {
        while (u != Parents[u])
        {
            u = Parents[u];
        }
        return u;
    }

    void DisJointUnion(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (ranks[rootU] >= ranks[rootV])
        {
            Parents[rootV] = rootU;
            ranks[rootU] += ranks[rootV];
        }
        else
        {
            Parents[rootU] = rootV;
            ranks[rootV] += ranks[rootU];
        }
    }

    int countComponents(int n, vector<vector<int>> &edges)
    {
        DSU(n);
        int comp = n;
        for (vector v : edges)
        {
            if (find(v[0]) != find(v[1]))
            {
                DisJointUnion(v[0], v[1]);
                comp--;
            }
        }
        return comp;
    }
};
