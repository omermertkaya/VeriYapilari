#include <stdio.h>
#include <stdlib.h>

struct Dugum{
	int veri;
	struct Dugum* sonraki;
};

void bastanekle(struct Dugum** bas_referansi, int yeni_veri)
{
	struct Dugum* yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	yeni_dugum -> veri = yeni_veri;
	yeni_dugum -> sonraki = *bas_referansi;
	(*bas_referansi) = yeni_dugum;
	
}


int saydirYaz(struct Dugum *basdugum)
{
	int saydir = 0;
	struct Dugum* simdiki = basdugum;
	while(simdiki != NULL)
	{
		saydir++;
		simdiki= simdiki->sonraki;
	}
	return saydir;
}



int ekranaYazdirmaylaSay(struct Dugum *dugum)
{
	int digerYontemSay= 0;
	while(dugum != NULL)
	{
		digerYontemSay++;
		dugum = dugum->sonraki;
	}
	return digerYontemSay;
}

void ekranaYazdirmaylaSay2(struct Dugum *dugum)
{
	int digerYontemSay= 0;
	while(dugum != NULL)
	{
		digerYontemSay++;
		dugum = dugum->sonraki;
	}
	printf("\nEkrana yazdirma ile sayin ikinci yontemi toplam:%d",digerYontemSay);
}





int main()
{
	struct Dugum* basdugum = NULL;
	bastanekle(&basdugum,3);
	bastanekle(&basdugum,2);
	bastanekle(&basdugum,1);
	printf("Toplam dugum sayisi = %d\n",saydirYaz(basdugum));
	printf("Ekrana yazdirma ile toplam dugum sayisi = %d",ekranaYazdirmaylaSay(basdugum));
	ekranaYazdirmaylaSay2(basdugum);
	
		
}


