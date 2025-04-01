// Author : ysh
// 2024/10/03 Thu 21:25:10
#include<stdio.h>
#include<stdlib.h>
#define T box
#define swap(i,j) (i ^= j ^= i ^= j)

const int xx[] = {0,1,0,-1};
const int yy[] = {1,0,-1,0};

struct box{
    int l;
    int x,y;
    
    box(int l = 0, int x = 0, int y = 0):
        l(l), x(x), y(y) {};
    
    inline bool operator<(const box a) const {
        if(l == a.l and x == a.x) return y < a.y;
        if(l == a.l) return x < a.x;
        return l < a.l;
    }

    inline bool operator==(const box a) const {
        return (x == a.x) and (y == a.y) and (l == a.l);
    }
    
    inline bool operator>(const box a) const {
        return !(a < *this) and not (*this == a);
    }

    box operator^=(const box a) {
        x ^= a.x;
        y ^= a.y;
        l ^= a.l;
        return *this;
    }
};

struct node{
    node *left, *right;
    T n;
    int _size;

    node(T n, node* left = nullptr, node* right = nullptr,int _size = 1):
        n(n), left(left), right(right), _size(_size) {};
};

struct heap{
    node* root;
    int _size;

    heap(node *root = nullptr):
        root(root), _size(get__size(root)) {};

    int get__size(node *root) {
        if(!root) return 0;
        return (root->_size = get__size(root->left) + get__size(root->right) + 1);
    }

    void push(T x, node* &root) {
        if(!root) return root = new node(x), void();

        root -> _size++;

        int l = (root -> left ? root -> left -> _size : 0);
        int r = (root -> right ? root -> right -> _size : 0);

        node* ans = nullptr;

        if(l <= r) push(x, root -> left), ans = root -> left;
        else push(x, root -> right), ans = root -> right;

        if((root -> n > ans -> n)) swap(root -> n, ans -> n);
    }
    void push(T x) {_size++; return push(x, root);}

    inline bool empty() {
        return !root;
    }

    bool pop(node *root) {
        if(!root -> left and !root -> right) {
            return delete root, 1;
        }
        if(!root -> right) {
            swap(root -> left -> n, root -> n);
            if(pop(root -> left)) root -> left = nullptr;
            return 0;
        }
        if(!root -> left) {
            swap(root -> right -> n, root -> n);
            if(pop(root -> right)) root -> right = nullptr;
            return 0;
        }
        T l = root -> left -> n;
        T r = root -> right -> n;
        if((l < r)) {
            swap(root -> left -> n, root -> n);
            if(pop(root -> left)) root -> left = nullptr;
        } else {
            swap(root -> right -> n, root -> n);
            if(pop(root -> right)) root -> right = nullptr;
        }
        return 0;
    }
    void pop() {_size--; return (_size == 0 ? delete root, root = nullptr, true : pop(root)), void();}

    // void print(node* root, std::ostream& out) {
    //     if(!root) return;

    //     out<<root -> n<<", [";
    //     print(root -> left, out);
    //     out<<"], [";
    //     print(root -> right, out);
    //     out<<"]";
        
    //     return;
    // }
    // void print(std::ostream& out = std::cout) {out<<"["; return print(root, out),out<<"]\n",void();}

    inline int size() {
        return _size;
    }

    inline T top() {
        return root -> n;
    }

    // friend std::ostream& operator<<(std::ostream& out, heapx) {
    //     x.print(out);
    //     return out;
    // }
};
int main() {
    int n;scanf("%d", &n);
    while(n--) {
        int a,b;scanf("%d %d", &a, &b);
        int f[a][b] = {};
        bool mark[a][b] = {};
        for(int i = 0;i<a;i++) {
            for(int j = 0;j<b;j++) {
                scanf("%d",&f[i][j]);
            }
        }

        heap t;
        t.push(box(f[0][0],0,0));
        while(!t.empty()) {
            box now = t.top();t.pop();
            int l = now.l;
            int x = now.x;
            int y = now.y;

            if(x == a - 1 and y == b - 1) {
                printf("%d\n", l);
                break;
            }

            if(mark[x][y]) continue;
            mark[x][y] = 1;
            
            for(int i = 0;i<=3;i++) {
                int nx = x + xx[i];
                int ny = y + yy[i];

                if(nx < 0 || ny < 0 || nx >= a || ny >= b) continue;
                t.push(box(l + f[nx][ny], nx, ny));
            }
        }
    }
    return 0;
}