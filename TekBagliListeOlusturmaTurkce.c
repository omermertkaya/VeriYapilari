#include<stdio.h>
#include<stdlib.h>
	
		
struct Dugum{
int veri;
	struct Dugum *sonraki;
};

void dugumyazdir(struct Dugum *n)
{
	while(n != NULL){
		printf("%d",n->veri);
		n = n->sonraki;
	}
}






int main()
{
	struct Dugum *birinci = NULL;
	struct Dugum *ikinci = NULL;
	struct Dugum *ucuncu = NULL;
	
	
	birinci = (struct Dugum*)malloc(sizeof(struct Dugum));
	ikinci = (struct Dugum*)malloc(sizeof(struct Dugum));
	ucuncu = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	birinci -> veri =1;
	birinci -> sonraki = ikinci;
	
	ikinci -> veri = 2;
	ikinci -> sonraki = ucuncu;
	
	ucuncu -> veri = 3;
	ucuncu -> sonraki = NULL;
	
	dugumyazdir(birinci);
	return 0;
	
	
	
	
}