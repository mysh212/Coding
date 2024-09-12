


#ifndef CHARACTER_H
#define CHARACTER_H





struct Character{
    char type;
    bool alive;
    void* pointer;
    Character(char a = '\0',bool b = false,void* c = nullptr):
        type(a), alive(b), pointer(c) {};
    inline bool operator<(const Character a) const {
        return int(alive) < int(a.alive);
    }
    string dump() {
        string ans = "";
        ans += to_string(int(type)) + "|";
        ans += (alive ? "1|" : "0|");
        debug(2);
        if(type == 'P') ans += static_cast<NovicePlayer*>(pointer)->serialize();
        else if(type == 'M') {
            auto now = static_cast<BaseMonster*>(pointer)->dump();
            ans += now.second;
            ans += "|";
            ans += now.first;
            ans += "|";
        }
        return ans;
    }
    inline void load(string x) {
        auto f = (core::split(x,"|"));
        debug(f);
        type = char(stoi(f[0]));
        if(f[1] == "1") alive = 1;
        else alive = 0;
        debug(type,alive);
        if(type == 'M') {
            if(f[3] == "1") {
                GoblinMonster* now = new GoblinMonster();
                now = now->unserialize(f[2]);
                pointer = static_cast<void*>(now);
            }
            if(f[3] == "2") {
                JWMonster* now = new JWMonster();
                now = now->unserialize(f[2]);
                pointer = static_cast<void*>(now);
            }
            if(f[3] == "3") {
                ZombieMonster* now = new ZombieMonster();
                // f[2] = "150,30,Zombie,17,65,5,65,150,0";
                now = now->unserialize(f[2]);
                pointer = static_cast<void*>(now);
                debug(f[2],now->serialize());
            }
        }
        if(type == 'P') {
            NovicePlayer* now = new NovicePlayer();
        }
    }
};






#endif