#include<iostream>
#include<string.h>
#include<vector>
#include<sstream>
#include<iomanip>
#include<sstream>
#include<math.h>
using namespace std;
#include "NovicePlayer.cpp"
#include "OrcPlayer.cpp"
#include "KnightPlayer.cpp"
#include "MagicianPlayer.cpp"
#include "BaseMonster.cpp"
#include "GoblinMonster.cpp"
#include "ZombieMonster.cpp"
#include "JWMonster.cpp"

// Operator overloading 輸出 player 所有參數
ostream& operator<<(ostream& os, const NovicePlayer& player) {
	os << "name:    " << player.getName() << endl;
	os << "level:   " << player.getLevel() << endl;
	os << "attack:  " << player.getAttack() << endl;
	os << "defense: " << player.getDefense() << endl;
	os << "hp:      " << player.getHp() << " / " << player.getMaxHP() << endl;
	os << "mp:      " << player.getMp() << " / " << player.getMaxMP() << endl;
	os << "exp:     " << player.getExp() << " / " << player.getLvupExp() << endl;
	os << "money:   " << player.getMoney() << endl;
	return os;
}

//Operator overloading 輸出 monster 所有參數
ostream& operator<<(ostream& os, BaseMonster& monster) {
	os << "name:    " << monster.name << endl;
	os << "attack:  " << monster.attack << endl;
	os << "defense: " << monster.defense << endl;
	os << "hp:      " << monster.getHp() << " / " << monster.maxhp << endl;
	os << "mp:      " << monster.getMp() << " / " << monster.maxhp << endl;
	os << "exp:     " << monster.exp << endl;
	os << "money:   " << monster.money << endl;
	return os;
}

int main() {
	NovicePlayer player_novice(8, "novice");
	string str_save_novice;						 
	str_save_novice = player_novice.serialize();
	NovicePlayer* ptr_player_novice_resume;								
	ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice);
	// NovicePlayer
	cout << ">>> NovicePlayer player_novice(8, \"novice\")" << endl << endl;
	// NovicePlayer player_novice(8, "novice");				//實體化 player
	player_novice.setHp(player_novice.getHp() - 1);
	cout << player_novice << endl;							//輸出 player

	cout << ">>> str_save_novice = player_novice.serialize()" << endl << endl;
	// string str_save_novice;						 //宣告一 string 用來接 serialize() 的輸出
	str_save_novice = player_novice.serialize(); //將 player 當下的狀態存成 string
	cout << str_save_novice << endl << endl;	 //輸出 str_save

	cout << ">>> ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice)" << endl << endl;
	// NovicePlayer* ptr_player_novice_resume;								   //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice); //將 str_save 讀至 ptr_player_resume
	cout << *ptr_player_novice_resume << endl;							   //輸出 *ptr_player_resume

	// OrcPlayer
	cout << ">>> OrcPlayer player_orc(8, \"orc\")" << endl << endl;
	OrcPlayer player_orc(8, "orc");				//實體化 player
	player_orc.setHp(player_orc.getHp() - 1);
	cout << player_orc << endl;							//輸出 player

	cout << ">>> str_save_orc = player_orc.serialize()" << endl << endl;
	string str_save_orc;						 //宣告一 string 用來接 serialize() 的輸出
	str_save_orc = player_orc.serialize(); //將 player 當下的狀態存成 string
	cout << str_save_orc << endl << endl;	 //輸出 str_save

	cout << ">>> ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc)" << endl << endl;
	NovicePlayer* ptr_player_orc_resume;						  //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc); //將 str_save 讀至 ptr_player_resume
	cout << *ptr_player_orc_resume << endl;						  //輸出 *ptr_player_resume

	// KnightPlayer
	cout << ">>> KnightPlayer player_knight(8, \"knight\")" << endl << endl;
	KnightPlayer player_knight(8, "knight");				//實體化 player
	player_knight.setHp(player_knight.getHp() - 1);
	cout << player_knight << endl;							//輸出 player

	cout << ">>> str_save_knight = player_knight.serialize()" << endl << endl;
	string str_save_knight;						 //宣告一 string 用來接 serialize() 的輸出
	str_save_knight = player_knight.serialize(); //將 player 當下的狀態存成 string
	cout << str_save_knight << endl << endl;	 //輸出 str_save

	cout << ">>> ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight)" << endl << endl;
	NovicePlayer* ptr_player_knight_resume;								   //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight); //將 str_save 讀至 ptr_player_resume
	cout << *ptr_player_knight_resume << endl;							   //輸出 *ptr_player_resume

	cout << ">>> ptr_player_knight_resume->setHp(1)" << endl << endl;
	ptr_player_knight_resume->setHp(1);		  //設定 hp = 1
	cout << *ptr_player_knight_resume << endl; //輸出 player_resume

	cout << ">>> ptr_player_knight_resume->specialSkill()" << endl << endl;
	ptr_player_knight_resume->specialSkill();  //使用 specialSkill 將 mp 轉化成 hp
	cout << *ptr_player_knight_resume << endl; //輸出 player_resume
	
	// MagicianPlayer
	cout << ">>> MagicianPlayer player_magician(8, \"magician\")" << endl << endl;
	MagicianPlayer player_magician(8, "magician"); //實體化 player
	player_magician.setHp(player_magician.getHp() - 1);
	cout << player_magician << endl;			   //輸出 player

	cout << ">>> str_save_magician = player_magician.serialize()" << endl << endl;
	string str_save_magician;						 //宣告一 string 用來接 serialize() 的輸出
	str_save_magician = player_magician.serialize(); //將 player 當下的狀態存成 string
	cout << str_save_magician << endl << endl;		 //輸出 *ptr_player_resume

	cout << ">>> ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician)" << endl << endl;
	NovicePlayer* ptr_player_magician_resume;								     //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician); //將 str_save 讀至 ptr_player_resume
	cout << *ptr_player_magician_resume << endl;								 //輸出 player_resume

	cout << ">>> ptr_player_magician_resume->setMP(1)" << endl << endl;
	ptr_player_magician_resume->setMp(1);		 //設定 mp = 1
	cout << *ptr_player_magician_resume << endl; //輸出 player_resume

	cout << ">>> ptr_player_magician_resume->specialSkill()" << endl << endl;
	ptr_player_magician_resume->specialSkill();	 //使用 specialSkill 將 hp 轉化成 mp
	cout << *ptr_player_magician_resume << endl; //輸出 player_resume
	

	cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	cout << BaseMonster::getInstanceCount() << endl << endl;

	cout << ">>> GoblinMonster goblin" << endl << endl;
	GoblinMonster goblin;

	// goblin().getHp();
	goblin.setHp(goblin.getHp() - 1);
	cout << goblin << endl;

	cout << ">>> str_save_goblin = goblin.serialize()" << endl << endl;
	string str_save_goblin;					 //宣告一 string 用來接 serialize() 的輸出
	str_save_goblin = goblin.serialize();	 //將 monster 當下的狀態存成 string
	cout << str_save_goblin << endl << endl; //輸出 str_save

	cout << ">>> ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin)" << endl << endl;
	BaseMonster* ptr_goblin_resume;									 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin); //將 str_save 讀至 ptr_monster_resume
	cout << *ptr_goblin_resume << endl;								 //輸出 *ptr_monster_resume

	cout << ">>> ZombieMonster zombie" << endl << endl;
	ZombieMonster zombie;
	zombie.setHp(zombie.getHp() - 1);
	cout << zombie << endl;

	cout << ">>> str_save_zombie = zombie.serialize()" << endl << endl;
	string str_save_zombie;					 //宣告一 string 用來接 serialize() 的輸出
	str_save_zombie = zombie.serialize();	 //將 monster 當下的狀態存成 string
	cout << str_save_zombie << endl << endl; //輸出 str_save

	cout << ">>> ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie)" << endl << endl;
	BaseMonster* ptr_zombie_resume;									 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie); //將 str_save 讀至 ptr_monster_resume
	cout << *ptr_zombie_resume << endl;								 //輸出 *ptr_monster_resume

	cout << ">>> JWMonster JW" << endl << endl;
	JWMonster JW;
	JW.setHp(JW.getHp() - 1);
	cout << JW << endl;

	cout << ">>> str_save_JW = JW.serialize()" << endl << endl;
	string str_save_JW;					 //宣告一 string 用來接 serialize() 的輸出
	str_save_JW = JW.serialize();		 //將 monster 當下的狀態存成 string
	cout << str_save_JW << endl << endl; //輸出 str_save

	cout << ">>> ptr_JW_resume = JWMonster::unserialize(str_save_JW)" << endl << endl;
	BaseMonster* ptr_JW_resume;							 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	ptr_JW_resume = JWMonster::unserialize(str_save_JW); //將 str_save 讀至 ptr_monster_resume
	cout << *ptr_JW_resume << endl;					 //輸出 *ptr_monster_resume
	delete ptr_JW_resume;

	cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	cout << BaseMonster::getInstanceCount() << endl;


	return 0;
}