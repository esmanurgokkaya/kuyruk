#include <stdio.h>
#include <stdlib.h>

// uygun deðiþkenler ile kuyruk tanýmlanýr
struct node {
	int data;
	struct node* next;
} *bas, *son, *yeni, *temp;

// kuyruða ekleme yapabilmek için ilgili fonksiyon tanýmlanýr
void ekleme(int veri) {
	yeni = (struct node*)malloc(sizeof(struct node));	// eklenecek deðiþken için bellekten yer ayrýlýr
	yeni-> data = veri;	// deðiþkene eklenmek istenen deðer aktarýlýr
	yeni-> next = NULL;		//diðerinin son eleman olduðunu tutar
	
	// ilk elemanýn  boþ olup olmadýðý kontrol edilir ve deðer atanýr
	if(bas == NULL){
		bas = yeni;
		son = yeni;
		
	}
	// ilk eleman doluysa diðerine ekleme yapýlýr
	else{
	
		son -> next = yeni;
		son = yeni;
}
	// kuyruða sayýnýn eklendiðini kullanýcýya bildirir 
	printf("%d sayisi kuyruga eklendi\n\n",veri);	
}

// kuyruktan silme yapabilmek için ilgili fonksiyon tanýmlanýr
void silme(){
	// temp deðiþkenine bas deðiþkeni eþitlenir
	temp = bas;
	
	// bas deðiþkeninin dolu olup olmadýðýna bakýlýr ve böylece kuyruðun dolu olup olmadýðý anlaþýlýr
	if(bas == NULL){
		printf("Kuyruk  bos\n\n");
		}
	else{	//  kuyruðun boþ olmadýðý anlaþýldýysa tekrar if bloklarýna girerek uygun þekilde baþýndan silme yapýlýr
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
// kuyruðu görüntüleyebilmek için ilgili fonksiyon tanýmlanýr

void goruntuleme(){
	// temp deðiþkenþ bas deðiþkenine aktarýllýr
	temp = bas;
	// kuyruðun boþ olup olmadýðý kontrol edilir
	if (bas == NULL){
		printf("Kuyruk bos\n\n");
	}
	else {
		// kuyruk dolu ise temp deðiþkeni null olana kadar elemanlar yazdýrýlýr
		while (temp != NULL){
		printf("%d  ", temp->data);	
		temp = temp -> next;
		}	
		printf("\n\n");
	}
}
int main(i) {
	// gerekli tanýmlamalar ve kullanýcý bildirimleri yapýlýr
	int secim, deger;
	
	printf("**********KUYRUK ISLEMLERI**********\n\n");
	
	while(1){
		// kullanýcýdan seçim yapmasý istenir
		printf("1.EKLEME\n2.SILME\n3.GORUNTULEME\n4.CIKIS\n");
		printf("\nSeciminizi giriniz: ");
		scanf("%d",&secim);
		// yapýlan seçime göre case içine girilir
		switch(secim){
			case 1 : // ekleme yaparken kullanýcýdan deðer istenir
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
