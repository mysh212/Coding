// Author : ysh
// 10/13/2022 Thu 18:03:29.15
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cout<<"limit=";int n;cin>>n;
    int s = 0,r = 0;
    while(1) {
        srand(time(NULL));
        clock_t t = clock();
        int a = rand() % n + 1;
        int b = rand() % n + 1;
        cout<<a<<" + "<<b<<" = ";int ans;cin>>ans;
        r++;
        if(ans == a + b) {
            s++;
            cout<<"Solving duration: "<<(clock() - t)/1000.0<<"s\n";
            cout<<"Correct.\nContinue?";char tmp;cin>>tmp;if(tmp == 'n') break;
            continue;
        }
        cout<<"No,the answer is "<<a + b<<" .\nContinue?";char tmp;cin>>tmp;if(tmp == 'n') break;
    }
    cout<<"\nGame Over,Your score is: "<<s<<"/"<<r<<".";
    return 0;
}