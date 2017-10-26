#include <stdio.h>
#include <stdlib.h>

struct Dugum {
	int veri;
	struct Dugum *sonraki;
	
};


void bastanekle(struct Dugum **bas_referansi, int yeni_veri){
	
	struct Dugum*  yeni_dugum = (struct Dugum*)malloc(sizeof(struct Dugum));
	
	yeni_dugum -> veri = yeni_veri;
	yeni_dugum -> sonraki = *bas_referansi;
	(*bas_referansi) = yeni_dugum;
	
}


void yazdir(struct Dugum* dugum)
{
	while(dugum != NULL)
	{
		printf("%d",dugum -> veri);
		dugum = dugum -> sonraki;
		
	}
	
}

void dugumsil(struct Dugum **bas_referansi,int anahtar)
{
	
	//gecici olarak kullanacagimiz dugum olu�turulur ve onceki dugum ile bas dugum buna esitlenir.
	struct Dugum* gecici = *bas_referansi,*onceki;
	
	//gecici dugumumuz eger ki bos degil ve anahtari iceriyorsa bas dugum taramas� gibi dusunun.
	if(gecici != NULL && gecici->veri == anahtar)
	{
		(*bas_referansi) = gecici -> sonraki;
		free(gecici);
		//yukar�daki a��klamay� denetlemek i�in yazilmistir. Bas dugum yani 1 eleman yollarsak deneyelim.
		printf("bas dugum silme islemi bu bolumde gerceklesti.\n");
		return;
				
		
	}
	//silenecek eleman ba� dugum de�il ise dugum �zerinde anahtar tarama i�lemi yapl�l�r.
	while(gecici != NULL && gecici -> veri != anahtar)
	{
		onceki = gecici;
		gecici = gecici -> sonraki;
		
	}
	if(gecici == NULL)
	{
		return;
	}
	onceki -> sonraki = gecici -> sonraki;
	free(gecici);
	
	
	
}


int main()
{
	struct Dugum* basdugum = NULL;
	
	bastanekle(&basdugum,3);
	bastanekle(&basdugum,2);
	bastanekle(&basdugum,1);
	printf("Birinci Dugum yazdiriliyor.\n");
	yazdir(basdugum);
	printf("\nikinci Dugum yazdiriliyor.\n");
	dugumsil(&basdugum,1);
	yazdir(basdugum);
	
	
	
	
}