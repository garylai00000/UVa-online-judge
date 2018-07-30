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

struct Point{
    int x, y, black;
    double rad;
    Point(int a, int b, int c): x(a), y(b), black(c){}
    Point(){}
};

Point points[1000+5], tmp[1000+5];
Point pivot;

bool cmp(Point p1, Point p2){
    return p1.rad < p2.rad;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int N;

	while(cin >> N && N){
        // input points
        for(int i = 0;i < N;i++){
            cin >> points[i].x >> points[i].y >> points[i].black;
        }
        // solve
        int ans = 0;
        for(int i = 0;i < N;i++){ // use each point as pivot point
            pivot = points[i];
            int k = 0;
            // tmp is the translated array
            for(int j = 0;j < N;j++){
                if(points[j].x != pivot.x || points[j].y != pivot.y){
                    if(points[j].black){ // black to other side
                        tmp[k].x = pivot.x + (pivot.x - points[j].x);
                        tmp[k].y = pivot.y + (pivot.y - points[j].y);
                    }
                    else{
                        tmp[k].x = points[j].x;
                        tmp[k].y = points[j].y;
                    }
                    // calculate solar angel
                    tmp[k].rad = atan2(tmp[k].y - pivot.y, tmp[k].x - pivot.x);
                    k++;
                }
            }
            // sort by solar angel
            sort(tmp, tmp+k, cmp);
            // count
            int cnt = 0, l = 0, r = 0;
            for(;l < k;l++, cnt--){
                while(cnt < k && ((tmp[l].x-pivot.x)*(tmp[r].y-pivot.y)) -
                      ((tmp[r].x-pivot.x)*(tmp[l].y-pivot.y)) >= 0){
                    cnt++;
                    r = (r+1)%k;
                }
                ans = max(ans, cnt + N - k);
            }
        }
        cout << ans << '\n';
	}

    return 0;
}
