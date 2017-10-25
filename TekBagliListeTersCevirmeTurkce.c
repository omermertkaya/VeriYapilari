#include <stdio.h>
#include <stdlib.h>

struct Dugum 
{
	int veri;
	struct Dugum * sonraki;
	
};

static void terscevir(struct Dugum **bas_referansi){
	struct Dugum* oncekidugum = NULL;
	struct Dugum* simdikidugum = *bas_referansi;
	struct Dugum* sonrakidugum;
	
	while(simdikidugum != NULL )
	{
		sonrakidugum = simdikidugum -> sonraki;
		simdikidugum -> sonraki = oncekidugum;
		oncekidugum = simdikidugum;
		simdikidugum = sonrakidugum;
		
	}
	*bas_referansi = oncekidugum;	
}

void bastanekle(struct Dugum **bas_referansi, int yeni_veri){
	
	struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	yeni_dugum -> veri = yeni_veri;
	yeni_dugum -> sonraki = *bas_referansi;
	(*bas_referansi) = yeni_dugum;
	


	
}

void yazdir(struct Dugum *dugum){
	
	while(dugum != NULL)
	{
		printf("%d",dugum->veri);
		dugum = dugum->sonraki;
		
	}
}


int main()
{
	struct Dugum *bas_dugum = NULL;
	bastanekle(&bas_dugum,3);
	bastanekle(&bas_dugum,2);
	bastanekle(&bas_dugum,1);
	yazdir(bas_dugum);
	printf("\ntersten yazdirilmis hali;\n");
	terscevir(&bas_dugum);
	yazdir(bas_dugum);
	
}