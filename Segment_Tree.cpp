#include <bits/stdc++.h>
using namespace std;

int a[100], seg4[00];

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2])
}

int query(int ind, int low, int high, int l, int r)
{
    if (low <= l && high >= r)
        return seg[ind];
    if (low > r || high < l)
        return INT_MIN;
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    build(0,0,n-1);
    query()
}