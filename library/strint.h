class strint{
    public:
    std::string itos(int a) {
        if(a == 0) return "0";
        std::string s;
        while(a != 0) {
            s = (char) ((char) (a % 10) + '0') + s;
            a = a / 10;
        }
        return s;
    }
    std::string itos(long long a) {
        if(a == 0) return "0";
        std::string s;
        while(a != 0) {
            s = (char) ((char) (a % 10) + '0') + s;
            a = a / 10;
        }
        return s;
    }
    std::string operator() (int x) {
        return itos(x);
    }
    std::string operator() (long long x) {
        return itos(x);
    }
}str;
class ip{
    public:
    string input() {
        string a;cin>>a;
        return a;
    }
    string operator()() {
        return input();
    }
}input;
class pt{
    public:
    void print(int a,string end = "\n") {
        cout<<a<<end;
    }
    void print(long long a,string end = "\n") {
        cout<<a<<end;
    }
    void print(string a,string end = "\n") {
        cout<<a<<end;
    }
    void print(char a,string end = "\n") {
        cout<<a<<end;
    }
    void operator() (int a,string end = "\n") {
        cout<<a<<end;
    }
    void operator() (long long a,string end = "\n") {
        cout<<a<<end;
    }
    void operator() (string a,string end = "\n") {
        cout<<a<<end;
    }
    void operator() (char a,string end = "\n") {
        cout<<a<<end;
    }
}print;