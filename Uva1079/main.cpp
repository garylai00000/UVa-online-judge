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

int n;
pair<double, double> p[10];

int sol(double L){ // check if can be solved with gap length L
    double cur = p[0].first + L;
    for(int i = 1;i < n;i++){
        if(p[i].second < cur)
            return 0;
        cur = max(cur, p[i].first) + L;
    }
    return 1;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
    int k = 1;

	while(cin >> n && n){
        // input
        for(int i = 0;i < n;i++){
            cin >> p[i].first >> p[i].second;
            p[i].first *= 60;
            p[i].second *= 60;
        }
        double ans = 0.0;
        // try all permutations
        sort(p, p+n);
        do{
            // binary search
            double l = 0.0, r = 1440.0*60;
            while(r - l > 1e-2){
                double mid = (l+r)/2;
                if(sol(mid))
                    l = mid;
                else
                    r = mid;
            }
            ans = max(ans, l);
        }while(next_permutation(p, p+n));
        int sec = (int)round(ans);
        printf("Case %d: %d:%02d\n", k++, sec/60, sec%60);
	}
    return 0;
}
