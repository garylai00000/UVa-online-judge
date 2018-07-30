#include <bits/stdc++.h>

using namespace std;

string s;
int n, d[300+5][300+5];

int dp(int l, int r){
    if(l == r)
        return 1;
    if(d[l][r] != -1)
        return d[l][r];
    if(s[l] != s[r]){
        d[l][r] = 0;
        return 0;
    }

    int ret = 0;
    for(int i = l+2;i <= r;i++){
        if(s[i] == s[l]){ // find a mid point i where s[l] = s[i] = s[r]
            ret += (long long)dp(l+1, i-1) * dp(i, r) % 1000000000;
            ret %= 1000000000;
        }
    }
    d[l][r] = ret;
    return ret;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while(cin >> s){
        n = (int)s.length();

        for(int i = 0;i < n;i++){
            memset(d[i], -1, sizeof(d[i]));
        }

        cout << dp(0, n-1) << endl;
	}
    return 0;
}
