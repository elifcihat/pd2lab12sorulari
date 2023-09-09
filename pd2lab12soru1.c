#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define N 4


/*
1) ��renci bilgilerinden (��renci no, isim, b�l�m) olu�an s�ral� eri�imli bir
dosya olu�turan ve bu dosya i�erisinde isme g�re arama yapan program�
yaz�n�z. Program men� �eklinde haz�rlanmal�d�r. Dosya olu�turma, kay�t
ekleme gibi gerekli t�m fonksiyonlar yaz�lmal�d�r.
*/

struct ogrenci{
    int no;
    char ad[20];
    char bolum[50];
};

typedef struct ogrenci ogr;

void dosyaolusturma(char dosyaadi[])
{

    FILE *dosya;

    if((dosya=fopen(dosyaadi,"w"))==NULL)
    {
        printf("dosya olusturulamadi...");
    }

    printf("%s adinda bir dosya olusturuldu",dosyaadi);//DOSYA AD�N� MA�N DE AL UNUTMA
    fclose(dosya);
}


void kayitekleme(char dosyaadi[])//MA�NDEN YEN� KAY�T ALMAY� UNUTMA
{
    FILE *dosya;
    dosya=fopen(dosyaadi,"a");
    ogr yenikayit;

    if(dosya==NULL)
    {
        printf("dosya acilamadi mlsf ki...");
    }
    else
    {
        printf("ogrenci numarasi, isim ve bolum giriniz \n");
        printf("?");
        scanf("%d%s%s",&yenikayit.no,yenikayit.ad,yenikayit.bolum);


        while(!feof(stdin))
        {
            fprintf(dosya,"%d %s %s\n",yenikayit.no,yenikayit.ad,yenikayit.bolum);
            printf("?");
            scanf("%d%s%s",&yenikayit.no,yenikayit.ad,yenikayit.bolum);


        }
        fclose(dosya);

    }
}

void ismegorearama(char dosyaadi[],char ad[])
{

    FILE *dosya;
    ogr isim;
    dosya=fopen(dosyaadi,"r");
    if(dosya==NULL)
    {
        printf("dosya olusuturulamadi...");
    }
    else
    {
        char baslik[200];
        fgets(baslik, sizeof(baslik), dosya);
        while (fscanf(dosya, "%d %s %s", &isim.no, isim.ad, isim.bolum) != EOF)
        {
            if (strcmp(isim.ad, ad) == 0)
            {
                printf("%d %s %s\n", isim.no, isim.ad, isim.bolum);
            }

        }
        fclose(dosya);
    }
}



int main()
{

    char dosyaadi[50];
    ogr isimm;
    char ad[20];
    char dosyaadi1[50];

    printf("dosya adini giriniz: ");
    scanf("%s",dosyaadi);

    int secim;


        while(1)
        {
        printf("1. secim: dosya olusturma,\n");
        printf("2. secim: kayit ekleme,\n");
        printf("3. secim: isme gore ara,\n");
        printf("4. secim: cikis\n");
        printf("secim:  ");
        scanf("%d",&secim);
        switch(secim)
            {
            case 1:
                printf("yeni dosya adini giriniz: ");
                scanf("%s",dosyaadi1);
                dosyaolusturma(dosyaadi1);
                break;

            case 2:
                kayitekleme(dosyaadi);
                printf("yeni kayit basariyla eklendi...\n");
                break;

            case 3:
                printf("aradiginiz adi girin: ");
                scanf("%s",ad);
                ismegorearama(dosyaadi,ad);
                break;

            case 4:
                printf("cikisiniz yapildi\n");
                exit(0);


            default:
                printf("yanlis deger girildi");


            }
        }



    return 0;
}

