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

struct Trie{
    int ch[400005][26];
    int val[400005];
    int sz;
    Trie(){
        sz = 1;
        val[0] = 0;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    inline void isrt(char* s, int v){ // insert string to Trie
        int u = 0;
        int l = strlen(s)-1;

        for(int i = 0;i < l;i++){
            int c = s[i] - 'a';
            if(!ch[u][c]){
                memset(ch[sz], 0, sizeof(ch[sz]));
                val[sz] = 0;
                ch[u][c] = sz++;
            }
            u = ch[u][c];
        }
        val[u] = v;
        return;
    }
    inline void clr(){ // clear Trie
        sz = 1;
        val[0] = 0;
        memset(ch[0], 0, sizeof(ch[0]));
    }
}trie;

char str[300005], tmp[105];
int len[300005], k = 1;
int dp[300005];

int main(){
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int S;
	while(fgets(str, 300005, stdin)){
        scanf("%d\n", &S);
        trie.clr();
        // input strings into Trie
        for(int i = 1;i <= S;i++){
            fgets(tmp, 105, stdin);
            len[i] = strlen(tmp)-1;
            trie.isrt(tmp, i);
        }
        int l = strlen(str)-1;
        memset(dp, 0, sizeof(dp));
        dp[l] = 1;
        for(int i = l-1;i >= 0;i--){
            int u = 0;
            for(int j = i;j < l;j++){ // check each string starts from str[i]
                if(!trie.ch[u][str[j]-'a']) // reach leaf of Trie
                    break;
                else{ // go to next node
                    u = trie.ch[u][str[j]-'a'];
                    if(trie.val[u]){ // if matches a word
                        dp[i] = (dp[i] + dp[i+len[trie.val[u]]])%20071027;
                    }
                }
            }
        }
        printf("Case %d: %d\n", k++, dp[0]);
	}
    return 0;
}
