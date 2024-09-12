
#ifndef PACK_LATE
#define PACK_LATE
#include"pack.cpp"

void pack::start() {
    outt(ok);
}

vector<string> pack::nowitem() {
    vector<string>ans;
    for(auto &i : f) {
        ans.push_back(static_cast<drop*>(i)->name);
    }
    return ans;
}

void pack::select() {
    outl(say(select_hello));
    int tmp;cin>>tmp;
    if(tmp > f.size()) return outl(say(choice_invalid)),select();
    if(tmp == 0) return;
    static_cast<drop*>(f.at(tmp - 1))->use();
    f.erase(f.begin() + (tmp - 1));
    return;
}

#endif