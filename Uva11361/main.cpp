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

int solve(int N, int K){
    int ret = 0;


    return ret;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int T, A, B, K;

	cin >> T;
	while(T--){
        cin >> A >> B >> K;

        cout << solve(B, K) - solve(A-1, K) << endl;
	}
    return 0;
}
