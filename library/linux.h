
inline bool exists_test3 (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}
string findtroad(string s) {
    if(s.find('/') != -1) {
        for(int i = s.size() - 1;i >= 0;i--) {
            if(s.at(i) == '/') {
                s = s.substr(i + 1);
                break;
            }
        }
    }
    return s;
}
string readnow() {
    auto f = fopen("now.tmp","r");
    string s;
    fscanf(f,"%s",&s);
    return s;
}
void writenow(string s) {
    auto f = fopen("now.tmp","w");
    fprintf(f,"%s\n",s);
    return;
}