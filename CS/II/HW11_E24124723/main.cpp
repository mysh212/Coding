#include"all.h"
// #include "src/external/termios.h"
 
//  #define new nnew
// int getch(void){ 
// 	struct termios old, new; 
// 	tcgetattr(0, &old); 
// 	new=old; 
// 	new.c_lflag &= ~(ICANON | ECHO); 
// 	tcsetattr(0, TCSANOW, &new); 
// 	int ch=getchar(); 
// 	tcsetattr(0, TCSANOW, &old); 
// 	return ch; 
// } 
// #undef new
int main() {
	srand(time(NULL));

	field f(7,12,5);
	char tmp;

	map<char,int>m({
		{'W',3},
		{'D',0},
		{'S',1},
		{'A',2},
		{'3',3},
		{'0',0},
		{'1',1},
		{'2',2},
		{'U',3},
		{'R',0},
		{'D',1},
		{'L',2}
	});

	// f.print();
	
	while(f.print(),cerr<<"Input the key [0,1,2,3] to move [R,D,L,U] or [P] to open backpack: ",cin>>tmp) {
		if(isalpha(tmp) && 'a' <= tmp && tmp <= 'z') tmp = tmp + ('A' - 'a');

		if(tmp == 'Q') return outl(say(bye)),0;

		if(tmp == 'P') {
			f.backpack.print();
			f.backpack.select();
			continue;
		}

		if(m.find(tmp) == m.end()) {
			outl(say(key_not_defined));
			continue;
		}
		int now = m.find(tmp)->second;
		if(f.walk(now)) outl("Press any key to continue."),cin>>tmp;

		#ifndef LOCAL
		system("cls || clear");
		#endif
		// cout<<say(key_not_defined);
	}

}