// Author : ysh
// 2024/05/22 Wed 23:26:59

#ifndef BACKPACK_H
#define BACKPACK_H
struct pack {
    vector<void*>f;

    pack():
        f() {};
    
    void start();

    void append(auto *x) {
        void* now = static_cast<void*> (x);
        f.push_back(now);
    }

    vector<string> nowitem();

    void print(ostream& pout = cout) {
        #define cout pout
        re(20) out('#');
        out(say(backpack));
        re(20) outt(#);
        nl;

        {
            int t = 0;
            for(auto i : nowitem()) {
                outs(++t);
                outl(i);
            }
        }

        re(20 + say(backpack).size() + 20) outt(#);
        nl;
        #undef cout
        return;
    }

    void select();

    friend ostream& operator<<(ostream& pout,pack x) {
        return x.print(pout),pout;
    }
};

#endif