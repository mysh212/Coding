


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
};






#endif