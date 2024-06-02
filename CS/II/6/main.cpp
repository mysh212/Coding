#include <iostream>
#include<math.h>
#include<cstring>
#include<iomanip>

using namespace std;
#include "KnightPlayer.h"
#include "KnightPlayer.cpp"
#include "MagicianPlayer.h"
#include "MagicianPlayer.cpp"
#include "NovicePlayer.h"
#include "NovicePlayer.cpp"
#include "OrcPlayer.h"
#include "OrcPlayer.cpp"

int main()
{
	//NovicePlayer
	NovicePlayer novice1;
	NovicePlayer novice2(2);
	NovicePlayer novice3(3, "testNovice");
	NovicePlayer novice4(novice3);

	cout << "novice1:" << endl;
	novice1.print();
	cout << endl;

	cout << "novice2:" << endl;
	novice2.print();
	cout << endl;

	cout << "novice3:" << endl;
	novice3.print();
	cout << endl;

	cout << "novice4:" << endl;
	novice4.print();
	cout << endl;

	novice4.setLevel(novice4.getLevel() + 1);
	cout << "novice4 after upgrade:" << endl;
	novice4.print();
	cout << endl;

	//OrcPlayer
	OrcPlayer Orc1;
	OrcPlayer Orc2(2);
	OrcPlayer Orc3(3, "testOrc");
	OrcPlayer Orc4(Orc3);

	cout << "Orc1:" << endl;
	Orc1.print();
	cout << endl;

	cout << "Orc2:" << endl;
	Orc2.print();
	cout << endl;

	cout << "Orc3:" << endl;
	Orc3.print();
	cout << endl;

	cout << "Orc4:" << endl;
	Orc4.print();
	cout << endl;

	Orc4.setLevel(Orc4.getLevel() + 1);
	cout << "Orc4 after upgrade:" << endl;
	Orc4.print();
	cout << endl;

	//KnightPlayer
	KnightPlayer Knight1;
	KnightPlayer Knight2(2);
	KnightPlayer Knight3(3, "testKnight");
	KnightPlayer Knight4(Knight3);

	cout << "Knight1:" << endl;
	Knight1.print();
	cout << endl;

	cout << "Knight2:" << endl;
	Knight2.print();
	cout << endl;

	cout << "Knight3:" << endl;
	Knight3.print();
	cout << endl;

	cout << "Knight4:" << endl;
	Knight4.print();
	cout << endl;

	Knight4.setLevel(Knight4.getLevel() + 1);
	Knight4.setHp(Knight4.getHp() - 40);
	cout << "Knight4 after upgrade and losing hp:" << endl;
	Knight4.print();
	cout << endl;

	Knight4.heal();
	cout << "Knight4 after healing:" << endl;
	Knight4.print();
	cout << endl;

	//MagicianPlayer
	MagicianPlayer Magician1;
	MagicianPlayer Magician2(2);
	MagicianPlayer Magician3(3, "testMagician");
	MagicianPlayer Magician4(Magician3);

	cout << "Magician1:" << endl;
	Magician1.print();
	cout << endl;

	cout << "Magician2:" << endl;
	Magician2.print();
	cout << endl;

	cout << "Magician3:" << endl;
	Magician3.print();
	cout << endl;

	cout << "Magician4:" << endl;
	Magician4.print();
	cout << endl;

	Magician4.setLevel(Magician4.getLevel() + 1);
	Magician4.setMp(Magician4.getMp() - 30);
	cout << "Magician4 after upgrade and losing mp:" << endl;
	Magician4.print();
	cout << endl;

	Magician4.pray();
	cout << "Magician4 after praying:" << endl;
	Magician4.print();
	cout << endl;

	return 0;
}
