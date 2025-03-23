#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
using namespace std;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i, int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}
void bfs(int si, int sj,int n,int m,vector<vector<bool>> &vis,vector<vector<int>> &grid,vector<vector<bool>> &tra)
{
    if(si==0||sj==0)tra[si][sj]=true;
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0;i<4;i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj,n,m) && !vis[ci][cj] && grid[ci][cj]==1)
            {
                if(ci==0||cj==0)tra[si][sj]=true;
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(ll j=0;j<m;j++)
            {
                grid[i][j]=s[j]-'0';
            }
        }
        vector<vector<bool>> vis(n, vector<bool>(m, false)); 
        vector<vector<bool>> tra(n, vector<bool>(m, false));
        bool flag=true;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    bfs(i,j,n,m,vis,grid,tra);
                    if(tra[i][j]==false)flag=false;
                }
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
        // for(ll i=0;i<n;i++)
        // {
        //     for(ll j=0;j<m;j++)
        //     {
        //         if(tra[i][j])
        //         {
        //             cout<<"T";
        //         }
        //         else cout<<"F";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

    }
}
