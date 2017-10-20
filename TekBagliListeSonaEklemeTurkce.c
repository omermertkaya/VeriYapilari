#include<stdio.h>
#include<stdlib.h>

struct Dugum{
	int veri;
	struct Dugum *sonraki;
	
};

//sona eklemek i�in bir fonksiyon olu�turuldu ve bu fonksiyonda 2 de�i�ken t�r� al�nd�.
//birincisi bas_dugumun i�aret etti�i yeri referans al�cak
//di�eri ise yeni verimizdir.

void sonaekle(struct Dugum **bas_referansi , int yeni_veri){
	//sona ekleme i�lemi yap�ld��� i�in yeni bir dugum olu�turulur.
	struct Dugum *yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	//burada bas_referans� sondugum ile tutuluyor ve dugumler �zerinde gezmemiz saglan�yor.
	struct Dugum *sondugum = *bas_referansi;
	
	yeni_dugum -> veri = yeni_veri;
	yeni_dugum -> sonraki = NULL;
	
	// hi� bagli liste yoksa ilk dugum ekleyecegimiz yeni dugum olur bas referans� o al�r.
	if( *bas_referansi == NULL)
	{
		*bas_referansi = yeni_dugum;
		return;
	}
	//son dugume kadar gezmemiz sa�lan�r.
	while(sondugum -> sonraki != NULL)
	{
		sondugum = sondugum -> sonraki;
	}
	//son dugumun sonraki g�stergesini yeni dugum yapar b�ylece son dugum yeni dugum olur.
	//sona ekleme tamamlanm�� olur.
	 sondugum -> sonraki  = yeni_dugum;	
	
}


void yazdir(struct Dugum *dugum)
{
	while (dugum != NULL)
	{
		printf("%d\n",dugum->veri);
		dugum = dugum -> sonraki;
	}
}



int main()
{
	struct Dugum *bas_dugum = NULL;
	
	sonaekle(&bas_dugum,6);
	sonaekle(&bas_dugum,8);
	sonaekle(&bas_dugum,7);
	
	yazdir(bas_dugum);
	
}