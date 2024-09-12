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

    string dump() {
        string ans = "";
        for(auto i : nowitem()) {
            ans += i + "|";
        }
        return ans;
    }

    // inline void load(string x) {
        // auto f = core::split(x,"|");
        // append(new Character('D',true,static_cast<drop*>(new fence(nx,ny,&backpack,static_cast<NovicePlayer*>(player.pointer)))))
    // }

    // friend ostream& operator<<(ostream& pout,pack x) {
    //     return x.print(pout),pout;
    // }
};

#endif