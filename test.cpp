#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> pii;

class num
{
    public:
        LL a[2005];
        bool neg=0;
        num(){}
        num(string s){
            memset(a, 0, sizeof(a));
            for(int i=s.size()-1, p=0; i>=0; i--, p++){
                a[p] = s[i] - '0';
            }
        }
        bool operator==(const num& n2) const{
            for(int i=2000; i>=0; i--){
                if(a[i] != n2.a[i]){
                    return 0;
                }
            }
            return 1;
        }
        bool operator>(const num& n2) const{
            for(int i=2000; i>=0; i--){
                if(a[i] != n2.a[i]){
                    return a[i] > n2.a[i];
                }
            }
            return 0;
        }
        bool operator<(const num& n2) const{
            for(int i=2000; i>=0; i--){
                if(a[i] != n2.a[i]){
                    return a[i] < n2.a[i];
                }
            }
            return 0;
        }
        bool operator<=(const num& n2) const {
            return !(*this > n2);
        }
        bool operator>=(const num& n2) const {
            return !(*this < n2);
        }
        void shiftl(){
            for(int i=0; i<2000; i++){
                a[i] = a[i+1];
            }
        }
        num operator+(const num& n2) const{
            num n3("0");
            for(int i=0; i<=2000; i++){
                n3.a[i] = a[i] + n2.a[i];
            }
            return n3.tidy();
        }
        num operator-(const num& nin) const{
            num n1=*this, n2=nin, n3("0");
            if(n1 < n2){
                n3.neg = 1;
                swap(n1, n2);
            }
            for(int i=0; i<=2000; i++){
                if(n1.a[i] < n2.a[i]){
                    n1.a[i] += 10;
                    n1.a[i+1] -= 1;
                }
                n3.a[i] = n1.a[i] - n2.a[i];
            }
            return n3.tidy();
        }
        num operator*(const num& n2) const{
            num n1=*this, n3("0");
            for(int i=0; i<=1000; i++){
                for(int j=0; j<=1000; j++){
                    n3.a[i+j] += n1.a[i] * n2.a[j];
                }
            }
            return n3.tidy();
        }
        num operator/(const num& nin) const{
            num n1=*this, n2=nin, n3("0"), ten("10"), zero("0"), one("1");
            LL cnt=1;
            while(n2*ten <= n1){
                n2 = n2 * ten;
                cnt++;
            }
            while(cnt--){
                n3 = n3 * ten;
                while(n2 <= n1){
                    n1 = n1 - n2;
                    n3 = n3 + one;
                }
                n2.shiftl();
            }
            return n3.tidy();
        }
        num operator%(const num& n2) const{
            num n1=*this;
            return n1 - (n1/n2) * n2;
        }
        num& tidy(){
            for(int i=0; i<=2000; i++){
                if(a[i] >= 10){
                    a[i+1] += a[i] / 10;
                    a[i] %= 10;
                }
            }
            return *this;
        }
        void print(){
            if(neg){
                cout << '-';
            }
            bool first = 1;
            for(int i=2000; i>=0; i--){
                if(first && a[i]){
                    first = 0;
                }
                if(!first){
                    cout << a[i];
                }
            }
            cout << (first ? "0" : "") << ' ';
        }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    string s1, s2;
    cin >> t;
    while(t--){
        cin >> s1 >> s2;
        num n1(s1), n2(s2);
        (n1 + n2).print();
        (n1 - n2).print();
        (n1 * n2).print();
        (n1 / n2).print();
        (n1 % n2).print();
        cout << '\n';
    }
    return 0;
}