//*********************
//電機一甲 412241080 張靖妍
//*********************
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int physical_attack, magic_attack, qigong_attack;

bool AttackResult(int RandomAttack, int PlayerAttack);

int main(void)
{
	srand(time(NULL));
	int round = 1;

	// if (round == 1) {
		printf("出現了敵人\n");  // 在這裡執行的話一定是第一次
	// }
	// else {
	// 	printf("又出現了敵人\n");
	// }
	while (1) {
        if(round != 1) printf("又出現了敵人\n"); // 每次開始新的一輪前都確認是不是第一輪
		int RandomAttack, PlayerAttack;
		RandomAttack = 1 + (rand() % 3);
		PlayerAttack = rand() % 4;

		switch (RandomAttack) {
		case 1:
			printf("敵人使出了物理攻擊\n");
			break;

		case 2:
			printf("敵人使出了魔法攻擊\n");
			break;

		case 3:
			printf("敵人使出了氣功攻擊\n");
			break;
		}
		printf("你必須使用三種攻擊應對(命中率皆為75%):物理攻擊(1)、魔法攻擊(2)、氣功攻擊(3)、結束遊戲(-1):");
		scanf("%d", &PlayerAttack);
		switch (PlayerAttack) {
		case 1:
			printf("你使出了物理攻擊\n");
			break;

		case 2:
			printf("你使出了魔法攻擊\n");
			break;

		case 3:
			printf("你使出了氣功攻擊\n");
			break;
		}

		if (PlayerAttack == -1) {
			printf("退出遊戲，遊戲結束\n");
			break;
		}
		if(AttackResult(RandomAttack, PlayerAttack)) return 0; // 如果可以結束就直接結束
	    round++;                                // 每次結束前都要加一
	}
	return 0;

}

	bool AttackResult(int RandomAttack, int PlayerAttack) { // 這裡回傳要不要結束遊戲
		switch (PlayerAttack) {
		case 1:                     /*你使出了物理攻擊*/
			switch (RandomAttack) {
			case 1:                 /*敵人使出了物理攻擊*/
				printf("雙方都使出了物理攻擊，互相抵銷了\n");    
				return false;

			case 2:                 /*敵人使出了魔法攻擊*/
				printf("物理攻擊克制魔法攻擊，你擊敗了敵人\n");
				printf("\n");
				printf("你擊敗了敵人，你獲得了勝利\n");
				break;

			case 3:                /*敵人使出了氣功攻擊*/
				printf("你被擊敗了\n");
				break;
			}
            break;                  // 大switch也要結束啦
		case 2:                     /*你使出了魔法攻擊*/
			switch (RandomAttack) {
			case 1:                 /*敵人使出了物理攻擊*/
				printf("你被擊敗了\n");
				break;

			case 2:                 /*敵人使出了魔法攻擊*/
				printf("雙方都使出了魔法攻擊，互相抵銷了\n");
				return false;

			case 3:                /*敵人使出了氣功攻擊*/
				printf("你擊敗了敵人，你獲得了勝利\n");
				break;
			}
            break;                  // 大switch也要結束啦拉拉
		case 3:                     /*你使出了氣功攻擊*/
			switch (RandomAttack) {
			case 1:                 /*敵人使出了物理攻擊*/
				printf("你擊敗了敵人，你獲得了勝利\n");
				break;

			case 2:                /*敵人使出了魔法攻擊*/
				printf("你被擊敗了\n");
				break;

			case 3:                 /*敵人使出了氣功攻擊*/
				printf("雙方都使出了氣功攻擊，互相抵銷了\n");
				return false;
			}
			break;
		}
        return true;                        // 放心結束
	}

