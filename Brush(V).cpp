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

        int dis[node+1][node+1],ans[node+1];
        vector<int> graph[node+1];
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

        source=1;
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

                if((dis[cur][des]+ans[cur])<=ans[des])
                {
                    ans[des]=dis[cur][des]+ans[cur];
                    q.push(des);
                }
            }
        }
        if(ans[node]==INT_MAX)
            printf("Case %d: Impossible\n",ca++);
        else
            printf("Case %d: %d\n",ca++,ans[node]);
    }
}
///Alhamdulillah
