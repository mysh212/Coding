#include<iostream>
#define MAX 1000
#define left node*2+1
#define right node*2+2
using namespace std;
void build(int*,int*,int,int,int);
void update(int*,int*,int,int,int,int,int);
int query(int*,int*,int,int,int,int,int);
void show_tree(int*);
int main() {
    int a[] = {1, 3, 5, 7 , 9, 11};
    int s = 6;
    int tree[MAX] = {};
    build(a,tree,0,0,s - 1);
    show_tree(tree);
    update(a,tree,0,0,s - 1,4,6);
    show_tree(tree);
    cout<<query(a,tree,0,0,s - 1,2,5);
    return 0;
}
void build(int *a,int *tree,int node,int start,int end) {
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
void update(int *a,int *tree,int node,int start,int end,int idx,int val) {
    if(start == end) {
        tree[node] = val;
        return;
    }
    int mid = (start+end) / 2;
    if(idx>mid) {
        update(a,tree,right,mid+1,end,idx,val);
    } else {
        update(a,tree,left,start,mid,idx,val);
    }
    tree[node] = tree[left] + tree[right];
    return;
}
int query(int *a,int *tree,int node,int start,int end,int L,int R) {
    cout<<start<<" "<<end<<"\n";
    if(end < L||start > R) return 0;
    if(start == end) {
        return tree[node];
    }
    if(L <= start&&R >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(a,tree,left,start,mid,L,R) + query(a,tree,right,mid + 1,end,L,R);
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
void show_tree(int *tree) {
    for(int i = 0;i<=14;i++) {
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
    return;
}