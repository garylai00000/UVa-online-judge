#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int dp[200005];

struct seg{
    int l, u, p;
};

bool cmp(seg s1, seg s2){
    if(s1.l != s2.l)
        return s1.l < s2.l;
    else
        return s1.u < s2.u;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int T, N;

	cin >> T;
	for(int k = 1;k <= T;k++){
        cin >> N;
        vector<seg> v(N);
        int A, B, C;
        for(int i = 0;i < N;i++){
            cin >> A >> B >> C;
            v[i].l = A;
            v[i].u = A + B;
            v[i].p = C;
        }
        sort(v.begin(), v.end(), cmp);
        memset(dp, 0, sizeof(dp));
        int cur = 0;
        for(int i = 0;i <= 200000;i++){
            if(i != 0)
                dp[i] = max(dp[i], dp[i-1]);
            while(cur < (int)v.size() && v[cur].l == i){
                dp[v[cur].u] = max(dp[v[cur].u], dp[i] + v[cur].p);
                cur++;
            }
        }
        printf("Case %d: %d\n", k, dp[200000]);
	}
    return 0;
}
