#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

#define N 10100
#define M 100100
#define INF 0x3f3f3f3f
using namespace std;

struct node{
    int dis,id;
    bool friend operator <(const node &a,const node &b){
        return a.dis>b.dis;
    }
}a[N];
struct edge{
    int u,v,w;
    int nxt;
}e[M];
int f[N],head[N],dis[N];
int n,m,b,l=INF,r=-INF;
bool vis[N];
priority_queue<node> q;

void addedge(int u,int v,int w,int id){
    e[id].u=u;e[id].v=v;e[id].w=w;
    e[id].nxt=head[u];
    head[u]=id;
}
void init(){
    int u,v,w;
    scanf("%d%d%d",&n,&m,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",f+i);
        l=min(l,f[i]);r=max(r,f[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w,i);addedge(v,u,w,m+i);
    }
}
void Dijkstra(int cost){
    memset(vis,false,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    node from;
    from.dis=0;from.id=1;q.push(from);
    dis[1]=0;
    while(!q.empty()){
        node t=q.top();
        q.pop();
        vis[t.id]=true;
        for(int i=head[t.id];i!=0;i=e[i].nxt)
            if(vis[e[i].v]==false&&f[e[i].v]<=cost&&dis[e[i].u]+e[i].w<dis[e[i].v]){
                dis[e[i].v]=dis[e[i].u]+e[i].w;
                node t;
                t.dis=dis[e[i].v];t.id=e[i].v;
                q.push(t);
            }
    }
}
void solve(){
    init();
    int ans=INF,mid;
    while(l<=r){
        mid=(l+r)>>1;
        Dijkstra(mid);
        if(dis[n]<b) ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(ans==INF) puts("AFK");
    else printf("%d\n",ans);
}
int main(){
    solve();
    return 0;
}