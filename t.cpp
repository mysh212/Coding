// Author : ysh
// 2024/10/03 Thu 16:11:01
#include<bits/stdc++.h>

std::ostream& operator<<(std::ostream& out, std::pair<int,int> a) {
    out<<"["<<a.first<<", "<<a.second<<"]";
    return out;
}
#include<heap>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    srand(time(NULL));

    // node<int> *a = new node<int>(10);
    // node *b = new node(20);
    // node *c = new node(30,a,b);

    // heap<int> now = heap<int>(new node<int>(10));

    // cout<<now.get_size(c)<<"\n";
    // cout<<c->size<<" "<<a->size<<" "<<b->size<<"\n";
    // now.push(5);
    // now.print();
    // cout<<"\n";

    // heap<int> now = heap<int>();
    // for(int i = 0;i<10;i++) {
    //     now.push(rand());
    //     now.print();
    // }
    // system("pause");
    // for(int i = 0;i<10;i++) {
    //     now.pop();
    //     now.print();
    //     cout<<"Now size = "<<now.size<<"\n";
    //     system("pause");
    // }

    heap<pair<int,int>> now;
    for(int i = 0;i<10;i++) {
        now.push({rand() % 10, rand() % 10});
        now.print();
    }
    for(int i = 0;i<10;i++) {
        now.pop();
        now.print();
        cout<<"Now size = "<<now.size()<<"\n";
    }
    cerr<<now;
    return 0;
}