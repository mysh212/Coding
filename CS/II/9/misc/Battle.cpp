// Author : ysh
// 2024/04/25 Thu 09:51:42

#ifndef BALLTE_HR
#define BATTLE_HR
#include"Battle.h"
#include"../all.h"

// template<typename T,S>
// void Battle attack()

Battle::Battle(int player,int monster,Character* v[] = nullptr) {
    function<bool(vector<Character>)> onealive = [&](vector<Character>f) {
        for(auto &i : f) if(i.alive)  return true;
        return false;
    };

    vector<Character>f;
    if(v != nullptr) {
        int n = player + monster;
        // cerr<<n;
        // exit(3);
        for(int i = 0;i<n;i++) {
            f.push_back(*v[i]);
        }
    }

    char last;
    if(v == nullptr || f.empty()) goto yes;
    last = f.at(1).type;
    for(auto &i : f) {
        // exit(3);
        if(i.type == last) goto no;
        last = i.type;
    }

    yes:
    battle(player,monster,f);
    return;

    no:
    vector<vector<Character>>pp,mm;
    last = '\0';
    for(auto &i : f) {
        if(i.type == last) {
            if(i.type == 'M') mm.back().push_back(i);
            else pp.back().push_back(i);
        } else {
            if(i.type == 'M') mm.push_back({i});
            else pp.push_back({i});
        }
    }

    int pc = pp.size(),mc = mm.size();
    int np,nm;np = nm = -1;
    int n = pp.size() + mm.size();
    bool ans = 0;
    while(!(n == 1)) {
        do {np = (np + 1) % pc;} while(!onealive(pp.at(np)));
        do {nm = (nm + 1) % mc;} while(!onealive(mm.at(nm)));

        vector<Character>tmp;
        for(auto &i : pp.at(np)) tmp.push_back(i);
        for(auto &j : mm.at(nm)) tmp.push_back(j);

        ans = battle(pp.at(np).size(),mm.at(nm).size(),tmp);
        n--;
    }
    cout<<"Overall Result: "<<(ans ? "Player" : "Monster")<<" Wins.\n";
}


vector<Character> Battle::autm(int x) {
    vector<Character> f;
    while(x--) {
        int now = rand() % MONSTER_COUNT;
        if(now == 0) f.push_back(Character('M',true,new GoblinMonster()));
        if(now == 1) f.push_back(Character('M',true,new JWMonster()));
        if(now == 2) f.push_back(Character('M',true,new ZombieMonster()));
    }
    return f;
}

vector<Character> Battle::autp(int x) {
    vector<Character> f;
    while(x--) {
        int now = rand() % PLAYER_COUNT;
        if(now == 0) f.push_back(Character('P',true,new KnightPlayer()));
        if(now == 1) f.push_back(Character('P',true,new MagicianPlayer()));
        if(now == 2) f.push_back(Character('P',true,new NovicePlayer()));
        if(now == 3) f.push_back(Character('P',true,new OrcPlayer()));
    }
    return f;
}

bool Battle::battle(int player,int monster,vector<Character>&f = *new vector<Character>(0)) {
    srand(time(NULL));
    function<void(Character,Character,int)> print = [&] (Character a,Character b,int t) {
        cout<<"The Result of Round #"<<t<<":\n";
        static_cast<NovicePlayer*>(a.pointer)->print();
        cout<<*static_cast<BaseMonster*>(b.pointer);
        if(!a.alive) cout<<"\n Player has no ability to fight.\n";
        if(!b.alive) cout<<"\n Monster has no ability to fight.\n";
    };

    vector<Character>mm,pp;
    if(f.empty()) mm = autm(monster), pp = autp(player);
    else {
        for(auto &i : f) {
            if(i.type == 'M') mm.push_back(i);
            else pp.push_back(i);
        }
    }
    int m,p;m = p = -1;
    int mc,pc;mc = pc = 0;
    for(auto &i : mm) if(i.alive) mc++;
    for(auto &i : pp) if(i.alive) pc++;
    int t = 0;
    while(!(mc == 0 || pc == 0)) {
        // cerr<<1;
        t++;
        do {m = (m + 1) % monster;} while(!mm.at(m).alive);
        do {p = (p + 1) % player;} while(!pp.at(p).alive);

        NovicePlayer* np = static_cast<NovicePlayer*>(pp.at(p).pointer);
        BaseMonster* nm = static_cast<BaseMonster*>(mm.at(m).pointer);

        np->specialSkill();
        int now = np->getHp() - nm->attack;
        if(now > 0) np->setHp(now);
        else {
            np->setHp(0);
            pp.at(p).alive = 0;
            pc--;
            print(pp.at(p),mm.at(m),t);
            continue;
        }

        np->specialSkill();
        now = nm->getHp() - np->getAttack();
        if(now > 0) nm->setHp(now);
        else {
            nm->setHp(0);
            mm.at(m).alive = 0;
            mc--;
        }
        print(pp.at(p),mm.at(m),t);
    }
    cout<<"Result: "<<(mc == 0 ? "Player" : "Monster")<<" Wins.\n";
    cout<<"Player remains: "<<pc<<"\n";
    cout<<"Monster remains: "<<mc<<"\n";
    return mc == 0;
}












#endif