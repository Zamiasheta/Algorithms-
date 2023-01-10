#include <bits/stdc++.h>
using namespace std;
long long G[100][100];
long long parent[100][100];

void path(int v, int u)
{
    if (parent[v][u] == v)
        return;
    cout << parent[v][u]+1 << "->";
    path(v, parent[v][u]);
}
void distance(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] && G[i][j] != INT_MAX && parent[i][j]!=-1)
            {
                cout <<"Path: "<< i+1 << "->";
                path(i,j);
                cout << j+1<<"   Distance: "<<G[i][j]<<endl;
            }
            else if(G[i][j]==INT_MAX)
            {
                cout <<"Error"<< endl;
            }
        }
    }
}
void floyd(int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                parent[i][j] = 0;
            }
            else if (G[i][j] != INT_MAX)
            {
                parent[i][j] = i;
            }
            else
            {
                parent[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((k != i || k != j) && G[i][j] > G[i][k] + G[k][j])
                {

                    G[i][j] = G[i][k] + G[k][j];
                    parent[i][j] = parent[k][j];
                }
            }
        }
    }
    distance(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int n, e, a, b, w;
    cin >> n >> e;
    cout<<"Enter the Graph"<<endl;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> w;
        G[a - 1][b - 1] = w;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && !G[i][j])
            {
                G[i][j] = INT_MAX;
            }
        }
    }
    floyd(n);
}

