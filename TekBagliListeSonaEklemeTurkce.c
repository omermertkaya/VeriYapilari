#include<stdio.h>
#include<stdlib.h>

struct Dugum{
	int veri;
	struct Dugum *sonraki;
	
};

//sona eklemek için bir fonksiyon oluþturuldu ve bu fonksiyonda 2 deðiþken türü alýndý.
//birincisi bas_dugumun iþaret ettiði yeri referans alýcak
//diðeri ise yeni verimizdir.

void sonaekle(struct Dugum **bas_referansi , int yeni_veri){
	//sona ekleme iþlemi yapýldýðý için yeni bir dugum oluþturulur.
	struct Dugum *yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	//burada bas_referansý sondugum ile tutuluyor ve dugumler üzerinde gezmemiz saglanýyor.
	struct Dugum *sondugum = *bas_referansi;
	
	yeni_dugum -> veri = yeni_veri;
	yeni_dugum -> sonraki = NULL;
	
	// hiç bagli liste yoksa ilk dugum ekleyecegimiz yeni dugum olur bas referansý o alýr.
	if( *bas_referansi == NULL)
	{
		*bas_referansi = yeni_dugum;
		return;
	}
	//son dugume kadar gezmemiz saðlanýr.
	while(sondugum -> sonraki != NULL)
	{
		sondugum = sondugum -> sonraki;
	}
	//son dugumun sonraki göstergesini yeni dugum yapar böylece son dugum yeni dugum olur.
	//sona ekleme tamamlanmýþ olur.
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