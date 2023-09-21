/* POJ2652 HDU1146 ZOJ2550 UVA10901 Ferry Loading III */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int id, time, ans;
    friend bool operator <(Node a, Node b) { return a.id < b.id; }
    Node(int id = 0, int time = 0, int ans = -1) : id(id), time(time), ans(ans) {}
};

int main()
{
    int t, n, time, m, tm;
    char s[8];
    scanf("%d", &t);
    while(t--) {
        queue<Node> q[2];
        vector<Node> v;

        scanf("%d%d%d", &n, &time, &m);
        for(int i = 1; i <= m; i++) {
            scanf("%d%s", &tm, s);
            q[s[0] == 'l' ? 0 : 1].push(Node(i, tm, -1));
        }

        int start = 0, time2 = 0;
        while(!q[0].empty() || !q[1].empty()) {
            int cnt = 0;
            while(!q[start].empty() && q[start].front().time <= time2 && cnt < n) {
                cnt++;
                q[start].front().ans = time2 + time;
                v.push_back(q[start].front());
                q[start].pop();
            }

            if(cnt) {time2 += time; start = 1 - start;}     // 装车送对岸，换出发河岸
            else {
                if(q[1 - start].empty() || (!q[start].empty() && q[1 - start].front().time > q[start].front().time))
                    time2 = q[start].front().time;
                else if(!q[1 - start].empty() && q[1 - start].front().time <= time2) {
                    time2 += time;
                    start = 1 - start;
                } else if(!q[1 - start].empty() && q[1 - start].front().time > time2) {
                    time2 = q[1 - start].front().time + time;
                    start = 1 - start;
                }
            }
        }

        sort(v.begin(), v.end());
        for(int i = 0; i < (int)v.size(); i++)
            printf("%d\n", v[i].ans);
        if(t) printf("\n");
    }

    return 0;
}
