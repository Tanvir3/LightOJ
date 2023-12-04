///Bismillahir Rahmanir Rahim
///Author: Tanvir Ahmmad
///CSE,Islamic University,Bangladesh
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int tst,ca=1;
    scanf("%d",&tst);
    while(tst--)
    {
        int node,edge,u,v,w,source;
        scanf("%d%d",&node,&edge);

        int dis[node][node],ans[node];
        vector<int> graph[node];
        memset(dis,0,sizeof dis);
        for(int i=0; i<=node; i++)
            ans[i]=INT_MAX;

        while(edge--)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(dis[u][v])
                dis[u][v]=dis[v][u]=min(dis[u][v],w);
            else
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
                dis[u][v]=dis[v][u]=w;
            }
        }

        scanf("%d",&source);
        queue<int> q;
        q.push(source);
        ans[source]=0;

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            for(int i=0; i<graph[cur].size(); i++)
            {
                int des=graph[cur][i];

                int MaxCostFound=max(dis[cur][des],ans[cur]);

                if(MaxCostFound<ans[des])
                {
                    ans[des]=MaxCostFound;
                    q.push(des);
                }
            }
        }
        printf("Case %d:\n",ca++);
        for(int i=0;i<node;i++)
        {
            if(ans[i]==INT_MAX) printf("Impossible\n");
            else printf("%d\n",ans[i]);
        }
    }
}
///Alhamdulillah
