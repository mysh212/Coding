#include"all.h"
int main() {

	// I'm so stupid

	// Battle(1,1,*new vector<Character>({Character('M',1,new GoblinMonster()),Character('P',1,new NovicePlayer()),Character('P',1,new NovicePlayer())}));



	cerr<<"===Making 10 Monsters and Players battle with each others===\n";
	{
		Character* tmp[20];
		for(int i = 0;i<10;i++) tmp[i] = new Character('P',1,new NovicePlayer());
		for(int i = 0;i<10;i++) tmp[i + 10] = new Character('M',1,new GoblinMonster());
		Battle(10,10,tmp);
	}

	cerr<<"===Making 100 unknown Monsters and Players battle with each others===\n";
	Battle(100,100);

	cerr<<"===Making 100 Monsters and Players battle with each others by team===\n";
	{
		Character* tmp[200];
		int t = 0;
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new KnightPlayer());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new OrcPlayer());
		for(int i = 0;i<10;i++) tmp[t++] = new Character('M',1,new JWMonster());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new MagicianPlayer());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new NovicePlayer());
		for(int i = 0;i<10;i++) tmp[t++] = new Character('M',1,new GoblinMonster());
		for(int i = 0;i<10;i++) tmp[t++] = new Character('M',1,new ZombieMonster());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new MagicianPlayer());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new NovicePlayer());
		for(int i = 0;i<10;i++) tmp[t++] = new Character('M',1,new GoblinMonster());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new KnightPlayer());
		for(int i = 0;i<20;i++) tmp[t++] = new Character('P',1,new OrcPlayer());
		Battle(100,100,tmp);
	}




	// NovicePlayer player_novice(8, "novice");
	// string str_save_novice;						 
	// str_save_novice = player_novice.serialize();
	// NovicePlayer* ptr_player_novice_resume;								
	// ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice);
	// // NovicePlayer
	// cout << ">>> NovicePlayer player_novice(8, \"novice\")" << endl << endl;
	// // NovicePlayer player_novice(8, "novice");				//實體化 player
	// player_novice.setHp(player_novice.getHp() - 1);
	// cout << player_novice << endl;							//輸出 player

	// cout << ">>> str_save_novice = player_novice.serialize()" << endl << endl;
	// // string str_save_novice;						 //宣告一 string 用來接 serialize() 的輸出
	// str_save_novice = player_novice.serialize(); //將 player 當下的狀態存成 string
	// cout << str_save_novice << endl << endl;	 //輸出 str_save

	// cout << ">>> ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice)" << endl << endl;
	// // NovicePlayer* ptr_player_novice_resume;								   //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	// ptr_player_novice_resume = NovicePlayer::unserialize(str_save_novice); //將 str_save 讀至 ptr_player_resume
	// cout << *ptr_player_novice_resume << endl;							   //輸出 *ptr_player_resume

	// // OrcPlayer
	// cout << ">>> OrcPlayer player_orc(8, \"orc\")" << endl << endl;
	// OrcPlayer player_orc(8, "orc");				//實體化 player
	// player_orc.setHp(player_orc.getHp() - 1);
	// cout << player_orc << endl;							//輸出 player

	// cout << ">>> str_save_orc = player_orc.serialize()" << endl << endl;
	// string str_save_orc;						 //宣告一 string 用來接 serialize() 的輸出
	// str_save_orc = player_orc.serialize(); //將 player 當下的狀態存成 string
	// cout << str_save_orc << endl << endl;	 //輸出 str_save

	// cout << ">>> ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc)" << endl << endl;
	// NovicePlayer* ptr_player_orc_resume;						  //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	// ptr_player_orc_resume = OrcPlayer::unserialize(str_save_orc); //將 str_save 讀至 ptr_player_resume
	// cout << *ptr_player_orc_resume << endl;						  //輸出 *ptr_player_resume

	// // KnightPlayer
	// cout << ">>> KnightPlayer player_knight(8, \"knight\")" << endl << endl;
	// KnightPlayer player_knight(8, "knight");				//實體化 player
	// player_knight.setHp(player_knight.getHp() - 1);
	// cout << player_knight << endl;							//輸出 player

	// cout << ">>> str_save_knight = player_knight.serialize()" << endl << endl;
	// string str_save_knight;						 //宣告一 string 用來接 serialize() 的輸出
	// str_save_knight = player_knight.serialize(); //將 player 當下的狀態存成 string
	// cout << str_save_knight << endl << endl;	 //輸出 str_save

	// cout << ">>> ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight)" << endl << endl;
	// NovicePlayer* ptr_player_knight_resume;								   //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	// ptr_player_knight_resume = KnightPlayer::unserialize(str_save_knight); //將 str_save 讀至 ptr_player_resume
	// cout << *ptr_player_knight_resume << endl;							   //輸出 *ptr_player_resume

	// cout << ">>> ptr_player_knight_resume->setHp(1)" << endl << endl;
	// ptr_player_knight_resume->setHp(1);		  //設定 hp = 1
	// cout << *ptr_player_knight_resume << endl; //輸出 player_resume

	// cout << ">>> ptr_player_knight_resume->specialSkill()" << endl << endl;
	// ptr_player_knight_resume->specialSkill();  //使用 specialSkill 將 mp 轉化成 hp
	// cout << *ptr_player_knight_resume << endl; //輸出 player_resume
	
	// // MagicianPlayer
	// cout << ">>> MagicianPlayer player_magician(8, \"magician\")" << endl << endl;
	// MagicianPlayer player_magician(8, "magician"); //實體化 player
	// player_magician.setHp(player_magician.getHp() - 1);
	// cout << player_magician << endl;			   //輸出 player

	// cout << ">>> str_save_magician = player_magician.serialize()" << endl << endl;
	// string str_save_magician;						 //宣告一 string 用來接 serialize() 的輸出
	// str_save_magician = player_magician.serialize(); //將 player 當下的狀態存成 string
	// cout << str_save_magician << endl << endl;		 //輸出 *ptr_player_resume

	// cout << ">>> ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician)" << endl << endl;
	// NovicePlayer* ptr_player_magician_resume;								     //宣告 type 為 NovicePlayer* 的 pointer 來接 unserialize 的輸出
	// ptr_player_magician_resume = MagicianPlayer::unserialize(str_save_magician); //將 str_save 讀至 ptr_player_resume
	// cout << *ptr_player_magician_resume << endl;								 //輸出 player_resume

	// cout << ">>> ptr_player_magician_resume->setMP(1)" << endl << endl;
	// ptr_player_magician_resume->setMp(1);		 //設定 mp = 1
	// cout << *ptr_player_magician_resume << endl; //輸出 player_resume

	// cout << ">>> ptr_player_magician_resume->specialSkill()" << endl << endl;
	// ptr_player_magician_resume->specialSkill();	 //使用 specialSkill 將 hp 轉化成 mp
	// cout << *ptr_player_magician_resume << endl; //輸出 player_resume
	

	// cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	// cout << BaseMonster::getInstanceCount() << endl << endl;

	// cout << ">>> GoblinMonster goblin" << endl << endl;
	// GoblinMonster goblin;

	// // goblin().getHp();
	// goblin.setHp(goblin.getHp() - 1);
	// cout << goblin << endl;

	// cout << ">>> str_save_goblin = goblin.serialize()" << endl << endl;
	// string str_save_goblin;					 //宣告一 string 用來接 serialize() 的輸出
	// str_save_goblin = goblin.serialize();	 //將 monster 當下的狀態存成 string
	// cout << str_save_goblin << endl << endl; //輸出 str_save

	// cout << ">>> ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin)" << endl << endl;
	// BaseMonster* ptr_goblin_resume;									 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	// ptr_goblin_resume = GoblinMonster::unserialize(str_save_goblin); //將 str_save 讀至 ptr_monster_resume
	// cout << *ptr_goblin_resume << endl;								 //輸出 *ptr_monster_resume

	// cout << ">>> ZombieMonster zombie" << endl << endl;
	// ZombieMonster zombie;
	// zombie.setHp(zombie.getHp() - 1);
	// cout << zombie << endl;

	// cout << ">>> str_save_zombie = zombie.serialize()" << endl << endl;
	// string str_save_zombie;					 //宣告一 string 用來接 serialize() 的輸出
	// str_save_zombie = zombie.serialize();	 //將 monster 當下的狀態存成 string
	// cout << str_save_zombie << endl << endl; //輸出 str_save

	// cout << ">>> ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie)" << endl << endl;
	// BaseMonster* ptr_zombie_resume;									 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	// ptr_zombie_resume = ZombieMonster::unserialize(str_save_zombie); //將 str_save 讀至 ptr_monster_resume
	// cout << *ptr_zombie_resume << endl;								 //輸出 *ptr_monster_resume

	// cout << ">>> JWMonster JW" << endl << endl;
	// JWMonster JW;
	// JW.setHp(JW.getHp() - 1);
	// cout << JW << endl;

	// cout << ">>> str_save_JW = JW.serialize()" << endl << endl;
	// string str_save_JW;					 //宣告一 string 用來接 serialize() 的輸出
	// str_save_JW = JW.serialize();		 //將 monster 當下的狀態存成 string
	// cout << str_save_JW << endl << endl; //輸出 str_save

	// cout << ">>> ptr_JW_resume = JWMonster::unserialize(str_save_JW)" << endl << endl;
	// BaseMonster* ptr_JW_resume;							 //宣告 type 為 BaseMonster* 的 pointer 來接 unserialize 的輸出
	// ptr_JW_resume = JWMonster::unserialize(str_save_JW); //將 str_save 讀至 ptr_monster_resume
	// cout << *ptr_JW_resume << endl;					 //輸出 *ptr_monster_resume
	// delete ptr_JW_resume;

	// cout << ">>> BaseMonster::getInstanceCount()" << endl << endl;
	// cout << BaseMonster::getInstanceCount() << endl;


	// return 0;
}