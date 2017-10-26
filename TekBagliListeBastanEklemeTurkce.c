#include<stdio.h>
#include<stdlib.h>

struct Dugum {
	
	int veri;
	struct Dugum *sonraki;
	
};

void bastanekle(struct Dugum **bas_referansi, int yeni_veri)
{
	struct Dugum *yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	yeni_dugum -> veri = yeni_veri;
	//yeni eklenen dugumun sonraki göstergesini bas_referansi yapılır.
	yeni_dugum -> sonraki = (*bas_referansi);
	//yeni ekledigimiz baş dugum olacağı için bu referans yeni_dugum'e aktarilir.
	*bas_referansi = yeni_dugum;
	
}


void yazdir(struct Dugum *dugum)
{
	while( dugum != NULL)
	{
		printf("%d\n",dugum->veri);
		dugum = dugum -> sonraki;
	}
	
}	

	
int main()
{
	struct Dugum *bas_dugum = NULL;
	
	bastanekle(&bas_dugum,4);
	bastanekle(&bas_dugum,5);
	bastanekle(&bas_dugum,6);
	
	yazdir(bas_dugum);
	
}


//omermertkaya

	
	
	
	
	
	
	
