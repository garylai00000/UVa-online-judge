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

int N, T, grid[200][200], sum[200][200];

inline void method1(){
    int len = 2*N;
    // initialize sum[i][j] equals to the sum of the rectangle
    // that the up left is grid[0][0] and the bottom right is grid[i][j]
    sum[0][0] = grid[0][0];
    for(int i = 1;i < len;i++){
        sum[i][0] = grid[i][0] + sum[i-1][0];
        sum[0][i] = grid[0][i] + sum[0][i-1];
    }
    for(int i = 1;i < len;i++){
        for(int j = 1;j < len;j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + grid[i][j] - sum[i-1][j-1];
        }
    }
    // enumerate each possible rectangle with length not greater than N
    // by i, j, a, b where grid[i][j] denotes the up left corner
    // and grid[a][b] denotes the bottom right corner
    // and find the maximum sum
    int ans = grid[0][0];
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            for(int a = i;a < i+N;a++){
                for(int b = j;b < j+N;b++){
                    int tmp = sum[a][b];
                    if(i-1 >= 0)
                        tmp -= sum[i-1][b];
                    if(j-1 >= 0)
                        tmp -= sum[a][j-1];
                    if(i-1 >= 0 && j-1 >= 0)
                        tmp += sum[i-1][j-1];
                    if(ans < tmp)
                        ans = tmp;
                }
            }
        }
    }
    printf("%d\n", ans);
    return;
}

inline void method2(){
    int len = 2*N;
    // initialize sum[i][j] = sum[i-1][j] + grid[i][j] (column sum)
    sum[0][0] = grid[0][0];
    for(int i = 1;i < len;i++)
        sum[0][i] = grid[0][i];
    for(int i = 1;i < len;i++){
        for(int j = 0;j < len;j++){
            sum[i][j] = sum[i-1][j] + grid[i][j];
        }
    }
    // enumerate i, j be the left bound column index of the rectangle
    // find the maximum sub array for each i, j
    int s[200], ans = grid[0][0];
    for(int i = 0;i < len;i++){
        for(int j = i;j < i+N && j < len;j++){
            // s[k] = sum from sum[j][0] - sum[i-1][0] to sum[j][k] - sum[i-1][k]
            if(i)
                s[0] = sum[j][0] - sum[i-1][0];
            else
                s[0] = sum[j][0];
            for(int k = 1;k < len;k++){
                if(i)
                    s[k] = s[k-1] + sum[j][k] - sum[i-1][k];
                else
                    s[k] = s[k-1] + sum[j][k];
            }
            // use deque to calculate maximum sub array with length at most N
            // note that elements in deque are the indexes of s[]
            deque<int> d;
            for(int k = 0;k < len;k++){
                // delete first if length exceed N
                if(!d.empty() && k - d.front() > N)
                    d.pop_front();
                // delete elements with values smaller than s[k]
                // which make the values in deque become an increasing sequence
                while(!d.empty() && s[k] < s[d.back()])
                    d.pop_back();
                d.push_back(k);
                // k == d.front() denotes choosing none of the elements, which is prohibited
                if(k != d.front() && ans < s[k] - s[d.front()])
                    ans = s[k] - s[d.front()];
            }
        }
    }
    printf("%d\n", ans);
    return;
}

inline void method3(){
    int len = 2*N;
    // initialize sum[i][j] = sum[i-1][j] + grid[i][j] (column sum)
    sum[0][0] = grid[0][0];
    for(int i = 1;i < len;i++)
        sum[0][i] = grid[0][i];
    for(int i = 1;i < len;i++){
        for(int j = 0;j < N;j++){
            sum[i][j] = sum[i-1][j] + grid[i][j];
        }
    }
    // enumerate i, j be the left bound column index of the rectangle
    // find the maximum sub array for each i, j
    int s[200], ans = grid[0][0];
    for(int i = 0;i < len;i++){
        for(int j = i;j < i+N && j < len;j++){
            // s[k] stores the sum from grid[i][k] to grid[j][k]
            for(int k = 0;k < N;k++){
                if(i)
                    s[k] = sum[j][k] - sum[i-1][k];
                else
                    s[k] = sum[j][k];
            }
            // find the maximum and minimum sub array of s[]
            int _max = -2e9, _min = 2e9, cur1 = 0, cur2 = 0, tot = 0;
            for(int k = 0;k < N;k++){
                tot += s[k]; // total sum of s[]
                cur1 += s[k]; // current sum for finding maximum sub array
                cur2 += s[k]; // current sum for finding minimum sub array
                if(_max < cur1)
                    _max = cur1;
                if(_min > cur2)
                    _min = cur2;
                if(cur1 < 0)
                    cur1 = 0;
                if(cur2 > 0)
                    cur2 = 0;
            }
            // two cases of answer
            // 1. the ordinary maximum sub array, without crossing the left and right boundary
            // 2. crossing the left and right boundary, equals to total sum of s[] - minimum sub array
            // chose the larger one
            if(tot - _min) // must take one, tot - _min == 0 means take none
                ans = max(ans, max(_max, tot - _min));
            else
                ans = max(ans, _max);
        }
    }
    printf("%d\n", ans);
    return;
}

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
        scanf("%d\n", &N);
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                scanf("%d", &grid[i][j]);
                // expand the grid into 2N * 2N
                grid[i][j+N] = grid[i+N][j] = grid[i+N][j+N] = grid[i][j];
            }
        }
        // three methods to solve this problem
        //method1();
        //method2();
        method3();
	}
    return 0;
}
