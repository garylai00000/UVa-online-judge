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

int main(){
    int T, n;

    cin >> T;
    while(T--){
        cin >> n;
        int ans = -2e9, max_so_far, cur;

        // initialize set the first score as maximum score so far
        cin >> max_so_far;
        for(int i = 1;i < n;i++){
            cin >> cur;
            // update ans if getting a larger difference
            if(ans < max_so_far - cur)
                ans = max_so_far - cur;
            // update maximum score so for
            if(max_so_far < cur)
                max_so_far = cur;
        }
        cout << ans << endl;
    }
    return 0;
}
