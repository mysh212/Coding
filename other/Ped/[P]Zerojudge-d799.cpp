#include<iostream>
#define MAX 1048576
#define left node*2+1
#define right node*2+2
using namespace std;
long long tree[MAX] = {};
long long trees[MAX] = {};
long long a[500000] = {};
void build(long long*,long long*,int,int,int);
void update(long long*,long long*,long long*,int,int,int,int,int,int);
void down(long long*,long long*,long long*,int,int,int);
long long query(long long*,long long*,long long*,int,int,int,int,int);
void show_tree(long long*);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i = 0;i<n;i++) {
        cin>>a[i];
    }
    build(a,tree,0,0,n - 1);
    int m;cin>>m;
    while(m--) {
        int tmp;cin>>tmp;
        if(tmp == 1) {
            int x,y,z;cin>>x>>y>>z;
            update(a,tree,trees,0,0,n - 1,x - 1,y - 1,z);
        }
        if(tmp == 2) {
            int x,y;cin>>x>>y;
            cout<<query(a,tree,trees,0,0,n - 1,x - 1,y - 1)<<"\n";
        }
    }
    return 0;
}
int main_bkp() {
    build(a,tree,0,0,5);
    show_tree(tree);
    show_tree(trees);
    update(a,tree,trees,0,0,5,2,4,3);
    show_tree(tree);
    show_tree(trees);
    cout<<query(a,tree,trees,0,0,5,3,4)<<"\n";
    show_tree(tree);
    show_tree(trees);
    return 0;
}
void build(long long *a,long long *tree,int node,int start,int end) {
    if(start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(a,tree,left,start,mid);
    build(a,tree,right,mid+1,end);
    tree[node] = tree[left] + tree[right];
    return;
}
void update(long long *a,long long *tree,long long *trees,int node,int start,int end,int L,int R,int val) {
    if(L > end || R < start) return;
    if(start == end) {
        tree[node] += val;
        //cout<<node<<" ";
        return;
    }
    if(L <= start&&R >= end) {
        trees[node] += val;
        tree[node]  += val * (end - start + 1);
        return;
    }
    int mid = (start+end) / 2;
    update(a,tree,trees,right,mid+1,end,L,R,val);
    update(a,tree,trees,left,start,mid,L,R,val);
    tree[node] = tree[left] + tree[right];
    return;
}
void down(long long *a,long long *tree,long long *trees,int node,int start,int end) {
    //cout<<"//"<<start<<" "<<end<<"\n";
    int mid = (end - start) / 2;
    trees[left]  += trees[node];
    trees[right] += trees[node];
    tree[left]  += trees[node] * (mid - start + 1);
    tree[right] += trees[node] * (end - (mid + 1) + 1);
    trees[node] = 0;
    return;
}
long long query(long long *a,long long *tree,long long *trees,int node,int start,int end,int L,int R) {
    //cout<<start<<" "<<end<<"\n";
    if(end < L||start > R) return 0;
    if(start == end) {
        return tree[node];
    }
    if(L <= start&&R >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    down(a,tree,trees,node,start,end);
    return query(a,tree,trees,left,start,mid,L,R) + query(a,tree,trees,right,mid + 1,end,L,R);
    /*
    if(L == start&&R == end) {
        return tree[node];
    } else if(L <= mid&&mid<R) {
        return query(a,tree,left,start,mid,L,R) + query(a,tree,right,mid + 1,end,L,R);
    } else if(L<=mid&&R<=mid) {
        return query(a,tree,left,start,mid,L,R);
    } else if(L>mid&&R>mid) {
        return query(a,tree,right,mid + 1,end,L,R);
    }
    */
}
void show_tree(long long *tree) {
    for(int i = 0;i<=20;i++) {
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
    return;
}