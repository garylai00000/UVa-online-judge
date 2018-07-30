#include <bits/stdc++.h>

using namespace std;

/*
array l and r denotes the closest index of element that has the same value
*/
int arr[200000+5], l[200000+5], r[200000+5];
int n;
unordered_map<int, int> m;

void init(){
    // input
    for(int i = 0;i < n;i++){
        scanf("%d", &arr[i]);
    }
    // left
    m.clear();
    for(int i = 0;i < n;i++){
        if(!m.count(arr[i])){
            l[i] = -1;
        }
        else{
            l[i] = m[arr[i]];
        }
        m[arr[i]] = i;
    }
    // right
    m.clear();
    for(int i = n-1;i >= 0;i--){
        if(!m.count(arr[i])){
            r[i] = n;
        }
        else{
            r[i] = m[arr[i]];
        }
        m[arr[i]] = i;
    }
}

int dc(int a, int b){
    if(a >= b)
        return 1;
    /*
    for(int i = a;i <= b;i++){
        if(l[i] < a && r[i] > b)
            return dc(a, i-1) && dc(i+1, b);
    }
    */

    int mid = (a+b)/2;
    for(int i = 0;i <= mid;i++){
        if(b-i >= a && l[b-i] < a && r[b-i] > b)
            return dc(a, b-i-1) && dc(b-i+1, b);
        if(a+i <= b && l[a+i] < a && r[a+i] > b)
            return dc(a, a+i-1) && dc(a+i+1, b);
    }

    return 0;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int T;

	scanf("%d", &T);
	while(scanf("%d", &n) != EOF){
        init();
        if(dc(0, n-1))
            printf("non-boring\n");
        else
            printf("boring\n");
	}
    return 0;
}
