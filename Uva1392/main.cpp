#include <bits/stdc++.h>

using namespace std;

int sum[150000+5], key[150000+5];

/*
sum[i] denotes the number of different elements from 1 to i

(sum[r]-sum[l-1]) / (r-l+1) <= p / 100
(sum[r]-sum[l-1]) * 100 <= (r-l+1) * p
p * (l-1) - sum[l-1] <= p * r - sum[r]

Let key[i] = p * i - sum[i]
if key[l-1] <= key[r]
the substrings from l to r could be a possible solution under the constraint of p
*/

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, p;
	string s1, s2;

	while(cin >> n && n){
        cin >> p >> s1 >> s2;
        s1 = " " + s1;
        s2 = " " + s2;

        key[0] = sum[0] = 0;
        for(int i = 1;i <= n;i++){
            sum[i] = sum[i-1];
            if(s1[i] != s2[i])
                sum[i]++;
            key[i] = p*i - 100*sum[i];
        }

        vector<pair<int, int>> v;
        v.push_back(make_pair(0, 0));
        for(int i = 1;i <= n;i++){
            if(key[i] < v.back().first){
                v.push_back(make_pair(key[i], i));
            }
        }

        int ans = 0;
        for(int i = 1;i <= n;i++){
            int l = 0, r = v.size()-1;
            while(l < r){
                int mid = (l+r)/2;
                if(key[i] >= v[mid].first)
                    r = mid;
                else
                    l = mid+1;
            }
            ans = max(ans, i - v[l].second);
        }
        if(ans == 0)
            cout << "No solution.\n";
        else
            cout << ans << '\n';
	}
    return 0;
}
