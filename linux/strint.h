class strint{
    public:
    string itos(int a) {
        if(a == 0) return "0";
        string s;
        while(a != 0) {
            s = (char) ((char) (a % 10) + '0') + s;
            a = a / 10;
        }
        return s;
    }
    string itos(long long a) {
        if(a == 0) return "0";
        string s;
        while(a != 0) {
            s = (char) ((char) (a % 10) + '0') + s;
            a = a / 10;
        }
        return s;
    }
    string operator() (int x) {
        return itos(x);
    }
    string operator() (long long x) {
        return itos(x);
    }
}str;