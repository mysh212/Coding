
//****************
//電機一甲_412241080_張靖妍
//****************
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

int main() {
	int firstclass, businessclass, economyclass;  /*設為firstclass為頭等艙, 為businessclass為商務艙, 為economyclass為經濟艙*/
	firstclass = 2, businessclass = 3, economyclass = 5;/*firstclass 有兩個座位 , businessclass有三個座位, economyclass有五個座位*/
	int seat_class, seat_number; /*設seat_class為艙等, seat_number為座位編號*/
	int a, b, c, d, e, f, g, h, i, j, ok;/*設a為頭等艙-1, b為頭等艙-2, c為商務艙-1, d為商務艙-2, e為商務艙-3, f為經濟艙-1, g為經濟艙-2, h為經濟艙-3, i為經濟艙-4, j為經濟艙-5*/
	a = b = c = d = e = f = g = h = i = j = ok = 0;
	while(1) {											// 因為要訂很多次，所以讓它一直執行
		ok = 0;											// 先情除掉上次的訂票狀態
		while (1) {
			scanf("%d", &seat_class);					// 一直輸入
			if (seat_class == -1) {						// 跳出來
				printf("(程式結束)\n");
				return 0;								// 記得結束掉程式
			}
			if (seat_class < 1 || seat_class>3) {
				printf("X\n");
				continue;								// 要進行下一次輸入
			}
			break;										// 輸入沒問題的話就跳出去
		}
		// scanf("%d", &seat_number);						// 這裡多打了一次
		// if (seat_class == 1 && seat_number > 0 && seat_number <= 2)
		// 	printf("S\n");
		// if (seat_class == 2 && seat_number > 0 && seat_number <= 3)
		// 	printf("S\n");
		// if (seat_class == 3 && seat_number > 0 && seat_number <= 5)
		// 	printf("S\n");																		 // 這裡在尬麻
		while (scanf("%d", &seat_number)) /*輸入1為頭等艙，輸入2為商務艙，輸入3為經濟艙*/			// 這裡是輸入座位啦
		{
			if (seat_class == 1 && seat_number == 1)           /*成功則訂位並佔據該位置，失敗則跳出*/
			{             
				if (a)
					printf("X\n");								// 為啥這裡是N ^_^
				else 
					printf("S\n"),ok = 1,firstclass = firstclass - 1;;						// 讓 ok = 1 代表訂票成功 而且只有訂票成功才需要減少剩餘座位
				a = 1;											// 記得佔位置
				
				break;											// 因為不用繼續輸入座位編號，所以跳出去
			} 
			if (seat_class == 1 && seat_number == 2)
			{
				if (b)
					printf("X\n"); 
				else
					printf("S\n"),ok = 1,firstclass = firstclass - 1;; 
				b = 1;											// 這裡也是
				
				break;
			}
			if (seat_class == 2 && seat_number == 1) 
			{
				if (c)
					printf("X\n"); 
				else 
					printf("S\n"),ok = 1,businessclass = businessclass- 1;; 
				c = 1;
				
				break;
			}
			if (seat_class == 2 && seat_number == 2) 
			{
				if (d) 
					printf("X\n"); 
				else 
					printf("S\n"),ok = 1,businessclass = businessclass - 1;;
				d = 1;
				
				break;
			}
			if (seat_class == 2 && seat_number == 3)
			{
				if (e) 
					printf("X\n");
				else
					printf("S\n"),ok = 1,businessclass = businessclass - 1;;
				e = 1;
				
				break;
			}
			if (seat_class == 3 && seat_number == 1)
			{
				if (f)
					printf("X\n");
				else 
					printf("S\n"),ok = 1,economyclass = economyclass - 1;;
				f = 1;
				
				break;
			}
			if (seat_class == 3 && seat_number == 2)
			{ 
				if (g)
					printf("X\n");
				else
					printf("S\n"),ok = 1,economyclass = economyclass - 1;;
				g = 1;
				
				break;
			}
			if (seat_class == 3 && seat_number == 3)
			{
				if (h)
					printf("X\n"); 
				else
					printf("S\n"),ok = 1,economyclass = economyclass - 1;; 
				h = 1;
				
				break;
			}
			if (seat_class == 3 && seat_number == 4) 
			{ 
				if (i) 
					printf("X\n");
				else 
					printf("S\n"),ok = 1,economyclass = economyclass - 1;;
				i = 1;
				
				break;
			}
			if (seat_class == 3 && seat_number == 5)
			{ 
				if (j) 
					printf("X\n"); 
				else 
					printf("S\n"),ok = 1,economyclass = economyclass - 1;; 
				j = 1;
				
				break;
			}
			printf("X\n");
			// break;											// 如果執行到這裡都還沒結束，代表輸入有問題，所以要繼續輸入
		}

		if(ok) {												// 如果訂票成功的話就輸出剩下座位，然後直接進入下一次迴圈
			if(seat_class == 1) printf("%d\n",firstclass);
			if(seat_class == 2) printf("%d\n",businessclass);
			if(seat_class == 3) printf("%d\n",economyclass);
			continue;
		}
		
		switch (seat_class) {
		case 1:
			if (firstclass == 0)
				printf("F\n");
				break;
		case 2:
			if (businessclass == 0)
				printf("F\n");
				break;
		case 3:
			if (economyclass == 0)
				printf("F\n");
				break;
		}
		if (firstclass == 0 && businessclass == 0 && economyclass == 0) {
			printf("N\n");
			return 0;															// 沒有座位的話得結束程式
		}
	}
	system("pause");
	return 0;
}
