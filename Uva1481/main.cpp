#include <bits/stdc++.h>

using namespace std;

int arr1[3000+5], pos[3000+5];

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;

	while(scanf("%d", &n) != EOF && n){
        for(int i = 0;i < n;i++){
            scanf("%d", &arr1[i]);
        }

        // transfer second array to correspondent position
        int tmp;
        for(int i = 0;i < n;i++){
            scanf("%d", &tmp);
            pos[tmp] = i;
        }
        int l, r, ans = 0;
        for(int i = 0;i < n;i++){
            l = r = pos[arr1[i]];
            for(int j = i+1;j < n;j++){
                // maintain the most left and most right index in second array
                l = min(l, pos[arr1[j]]);
                r = max(r, pos[arr1[j]]);
                if(j - i == r - l)
                    ans++;
            }
        }
        printf("%d\n", ans);
	}
    return 0;
}
