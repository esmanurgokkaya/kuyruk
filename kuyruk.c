#include <stdio.h>
#include <stdlib.h>

// uygun de�i�kenler ile kuyruk tan�mlan�r
struct node {
	int data;
	struct node* next;
} *bas, *son, *yeni, *temp;

// kuyru�a ekleme yapabilmek i�in ilgili fonksiyon tan�mlan�r
void ekleme(int veri) {
	yeni = (struct node*)malloc(sizeof(struct node));	// eklenecek de�i�ken i�in bellekten yer ayr�l�r
	yeni-> data = veri;	// de�i�kene eklenmek istenen de�er aktar�l�r
	yeni-> next = NULL;		//di�erinin son eleman oldu�unu tutar
	
	// ilk eleman�n  bo� olup olmad��� kontrol edilir ve de�er atan�r
	if(bas == NULL){
		bas = yeni;
		son = yeni;
		
	}
	// ilk eleman doluysa di�erine ekleme yap�l�r
	else{
	
		son -> next = yeni;
		son = yeni;
}
	// kuyru�a say�n�n eklendi�ini kullan�c�ya bildirir 
	printf("%d sayisi kuyruga eklendi\n\n",veri);	
}

// kuyruktan silme yapabilmek i�in ilgili fonksiyon tan�mlan�r
void silme(){
	// temp de�i�kenine bas de�i�keni e�itlenir
	temp = bas;
	
	// bas de�i�keninin dolu olup olmad���na bak�l�r ve b�ylece kuyru�un dolu olup olmad��� anla��l�r
	if(bas == NULL){
		printf("Kuyruk  bos\n\n");
		}
	else{	//  kuyru�un bo� olmad��� anla��ld�ysa tekrar if bloklar�na girerek uygun �ekilde ba��ndan silme yap�l�r
		if (bas == son)
		{
			bas = NULL;
			son = NULL;
			free(temp);
			temp = NULL;
		}
		else
		{
			bas = bas -> next; 
			temp -> next = NULL; 
			free(temp);
			temp = NULL;
		}
		printf("Kuyruktan silme yapildi\n\n");
		
	}
	
	
	
}
// kuyru�u g�r�nt�leyebilmek i�in ilgili fonksiyon tan�mlan�r

void goruntuleme(){
	// temp de�i�ken� bas de�i�kenine aktar�ll�r
	temp = bas;
	// kuyru�un bo� olup olmad��� kontrol edilir
	if (bas == NULL){
		printf("Kuyruk bos\n\n");
	}
	else {
		// kuyruk dolu ise temp de�i�keni null olana kadar elemanlar yazd�r�l�r
		while (temp != NULL){
		printf("%d  ", temp->data);	
		temp = temp -> next;
		}	
		printf("\n\n");
	}
}
int main(i) {
	// gerekli tan�mlamalar ve kullan�c� bildirimleri yap�l�r
	int secim, deger;
	
	printf("**********KUYRUK ISLEMLERI**********\n\n");
	
	while(1){
		// kullan�c�dan se�im yapmas� istenir
		printf("1.EKLEME\n2.SILME\n3.GORUNTULEME\n4.CIKIS\n");
		printf("\nSeciminizi giriniz: ");
		scanf("%d",&secim);
		// yap�lan se�ime g�re case i�ine girilir
		switch(secim){
			case 1 : // ekleme yaparken kullan�c�dan de�er istenir
			printf("Eklemek istediginiz degeri giriniz : ");
			scanf("%d",&deger);
			 ekleme(deger);
				break;
			case 2 : silme();
				break;
			case 3 : goruntuleme();
				break;
			case 4 : printf("\nCikis yapiliyor\n");
				goto bitis;
				break;
			default :
				printf("GECERSIZ DEGER GIRDINIZ!\n");
				break;
		}
	}
	bitis:
	return 0;
}
