
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
	int a, b, c, d, e, f, g, h, i, j;/*設a為頭等艙-1, b為頭等艙-2, c為商務艙-1, d為商務艙-2, e為商務艙-3, f為經濟艙-1, g為經濟艙-2, h為經濟艙-3, i為經濟艙-4, j為經濟艙-5*/
	a = b = c = d = e = f = g = h = i = j = 0;
	while (1) {
		scanf("%d", &seat_class);
		if (seat_class == -1)
			printf("(程式結束)\n");
		if (seat_class < 1 || seat_class>3)
			printf("X\n");
	}
	scanf("%d", &seat_number);
	if (seat_class == 1 && seat_number > 0 && seat_number <= 2)
		printf("S\n");
	if (seat_class == 2 && seat_number > 0 && seat_number <= 3)
		printf("S\n");
	if (seat_class == 3 && seat_number > 0 && seat_number <= 5)
		printf("S\n");
	while (scanf("%d", &seat_number)) /*輸入1為頭等艙，輸入2為商務艙，輸入3為經濟艙*/
	{
	    if (seat_class == 1 && seat_number == 1)           /*成功則訂位並佔據該位置，失敗則跳出*/ 
	    {             
		    if (a)
				printf("N\n"); 
		    else 
				printf("S\n");
			printf("%d", firstclass);
			firstclass = firstclass - 1;
	    } 
	    if (seat_class == 1 && seat_number == 2)
	    {
		    if (b)
				printf("X\n"); 
		    else
				printf("S\n"); 
			printf("%d", firstclass);
			firstclass = firstclass - 1;
	    }
	    if (seat_class == 2 && seat_number == 1) 
	    {
		    if (c)
				printf("X\n"); 
		    else 
				printf("S\n"); 
			printf("%d", businessclass);
			businessclass = businessclass- 1;
	    }
	    if (seat_class == 2 && seat_number == 2) 
	    {
		    if (d) 
				printf("X\n"); 
		    else 
				printf("S\n");
			printf("%d", businessclass);
			businessclass = businessclass - 1;
	    }
	    if (seat_class == 2 && seat_number == 3)
	    {
		    if (e) 
				printf("X\n");
	        else
				printf("S\n");
			printf("%d", businessclass);
			businessclass = businessclass - 1;
	    }
	    if (seat_class == 3 && seat_number == 1)
	    {
			if (f)
				printf("X\n");
		    else 
				printf("S\n");
			printf("%d", economyclass);  
			economyclass = economyclass - 1; 
	    }
	    if (seat_class == 3 && seat_number == 2)
	    { 
		    if (g)
				printf("X\n");
		    else
				printf("S\n");
			printf("%d", economyclass); 
			economyclass = economyclass - 1; 
	    }
	    if (seat_class == 3 && seat_number == 3)
	    {
		    if (h)
				printf("X\n"); 
		    else
				printf("S\n"); 
			printf("%d", economyclass); 
			economyclass = economyclass - 1; 
	    }
	    if (seat_class == 3 && seat_number == 4) 
	    { 
		    if (i) 
				printf("X\n");
		    else 
				printf("S\n");
			printf("%d", economyclass); 
			economyclass = economyclass - 1; 
	    }
	    if (seat_class == 3 && seat_number == 5)
	    { 
		    if (j) 
				printf("X\n"); 
		    else 
				printf("S\n"); 
			printf("%d", economyclass); 
			economyclass = economyclass - 1; 
	    }
	    break;
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
	if (firstclass == 0 && businessclass == 0 && economyclass == 0)
		printf("N\n");
	system("pause");
	return 0;
}
