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

int gp[1000+5][1000+5], bp[1000+5][1000+5];
int gchoice[1000+5], bchoice[1000+5], bnext[1000+5];
int N;

void init(){
    cin >> N;
    // bp[i][j] indicates the j'th preference of the i'th boy
    for(int i = 1;i <= N;i++){
        bnext[i] = 1;
        bchoice[i] = 0;
        for(int j = 1;j <= N;j++){
            scanf("%d", &bp[i][j]);
        }
    }
    // gp[i][j] indicates the j'th boy's priority to the i'th girl
    int tmp;
    for(int i = 1;i <= N;i++){
        gchoice[i] = 0;
        for(int j = 1;j <= N;j++){
            scanf("%d", &tmp);
            gp[i][tmp] = j;
        }
    }
    return;
}

void solve(){
    queue<int> q;

    for(int i = 1;i <= N;i++)
        q.push(i);

    while(!q.empty()){
        int boy = q.front();
        q.pop();
        int girl = bp[boy][bnext[boy]++];
        if(!gchoice[girl]){
            gchoice[girl] = boy;
            bchoice[boy] = girl;
        }
        else if(gp[girl][boy] < gp[girl][gchoice[girl]]){
            q.push(gchoice[girl]);
            gchoice[girl] = boy;
            bchoice[boy] = girl;
        }
        else{
            q.push(boy);
        }
    }

    for(int i = 1;i <= N;i++)
        printf("%d\n", bchoice[i]);
    return;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int T;

	cin >> T;
	for(int k = 0;k < T;k++){
        init();
        solve();
        if(k != T-1) putchar('\n');
	}
    return 0;
}
