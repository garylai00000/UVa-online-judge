#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> interval;

long long pre_sum[500000+5];
int max_pre[1000000+5], max_suf[1000000+5];
interval max_sub[1000000+5];
int a, b;

// compare two intervals, return better one
interval cmp(interval i1, interval i2){
    long long sum1 = pre_sum[i1.second] - pre_sum[i1.first-1];
    long long sum2 = pre_sum[i2.second] - pre_sum[i2.first-1];
    if(sum1 != sum2)
        return sum1 > sum2 ? i1 : i2;
    else
        return i1 < i2 ? i1 : i2;
        /*
        if(i1.first != i2.first)
            return i1.first < i2.first ? i1 : i2;
        else
            return i1.second < i2.second ? i1 : i2;
        */
}

void build_st(int o, int l, int r){
    if(l == r){ // length 1, ground case
        max_pre[o] = max_suf[o] = l;
        max_sub[o] = make_pair(l, r);
    }
    else{
        int mid = (l+r)/2;
        int lc = o*2, rc = o*2+1;
        // build child first
        build_st(lc, l, mid);
        build_st(rc, mid+1, r);
        max_sub[o] = cmp(max_sub[lc], max_sub[rc]); // on one side
        max_sub[o] = cmp(max_sub[o], make_pair(max_suf[lc], max_pre[rc])); // cross middle
        max_pre[o] = cmp(make_pair(l, max_pre[lc]), make_pair(l, max_pre[rc])).second;
        max_suf[o] = cmp(make_pair(max_suf[rc], r), make_pair(max_suf[lc], r)).first;
    }
    return;
}

int query_pre(int o, int l, int r){ // query max prefix
    if(b >= max_pre[o])
        return max_pre[o];
    int mid = (l+r)/2;
    int lc = o*2, rc = o*2+1;
    if(b <= mid)
        return query_pre(lc, l, mid);
    else
        return cmp(make_pair(l, query_pre(rc, mid+1, r)), make_pair(l, query_pre(lc, l, mid))).second;
}

int query_suf(int o, int l, int r){ // query max suffix
    if(a <= max_suf[o])
        return max_suf[o];
    int mid = (l+r)/2;
    int lc = o*2, rc = o*2+1;
    if(a >= mid+1)
        return query_suf(rc, mid+1, r);
    else
        return cmp(make_pair(query_suf(rc, mid+1, r), r), make_pair(query_suf(lc, l, mid), r)).first;
}

interval query(int o, int l, int r){
    if(a <= l && r <= b)
        return max_sub[o];
    else{
        int mid = (l+r)/2;
        int lc = o*2, rc = o*2+1;
        if(b <= mid) return query(lc, l, mid);
        if(a >= mid+1) return query(rc, mid+1, r);
        return cmp(make_pair(query_suf(lc, l, mid), query_pre(rc, mid+1, r)), cmp(query(lc, l, mid), query(rc, mid+1, r)));
    }
}

int main(){
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    int n, m, k = 1;

    while(scanf("%d%d", &n, &m) != EOF){
        // input
        pre_sum[0] = 0;
        for(int i = 1;i <= n;i++){
            scanf("%lld", &pre_sum[i]);
            pre_sum[i] += pre_sum[i-1];
        }
        // build segment tree
        build_st(1, 1, n);
        // query and output
        printf("Case %d:\n", k++);
        interval ans;
        for(int i = 0;i < m;i++){
            scanf("%d%d", &a, &b);
            ans = query(1, 1, n);
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}
