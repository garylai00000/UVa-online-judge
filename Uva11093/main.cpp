#include <iostream>
#include <cstdio>

using namespace std;

int p[100005];

int main(){
    //freopen("test.in", "r", stdin);
    int T, N;
    int sum, cur, st, tmp;

    scanf("%d", &T);
    for(int k = 1;k <= T;k++){
        printf("Case %d: ", k);
        scanf("%d", &N);
        // input first sequence
        for(int i = 0;i < N;i++)
            scanf("%d", &p[i]);
        st = sum = cur = 0;
        // input second sequence and calculate answer at same time
        for(int i = 0;i < N;i++){
            scanf("%d", &tmp);
            p[i] -= tmp;
            sum += p[i]; // sum of both sequence
            // check current fuel left
            if(cur < 0){
                st = i; // set start position to current station
                cur = 0;
            }
            cur += p[i];
        }
        if(sum < 0)
            printf("Not possible\n");
        else
            printf("Possible from station %d\n", st+1);
    }
    return 0;
}
