#include <stdio.h>
#include <string.h>
#include "../include/kasa_simulasyonu.h"


int main () {
    Urun urunler[3];
    /*Urun tanimlamalari*/
    strcpy(urunler[0].urun_adi, "Ekmek");
    urunler[0].urun_kodu = 1;
    urunler[0].stok_adedi = 30;
    urunler[0].fiyat = 10.00;

    strcpy(urunler[1].urun_adi, "Sut");
    urunler[1].urun_kodu = 2;
    urunler[1].stok_adedi = 10;
    urunler[1].fiyat = 25.90;

    strcpy(urunler[2].urun_adi, "Yumurta");
    urunler[2].urun_kodu = 3;
    urunler[2].stok_adedi = 30;
    urunler[2].fiyat = 7.50;

    int urun_kodu = -1;
    int satis_adedi = 0;

    printf("Hos Geldiniz!\n");

    while(urun_kodu != 0) {
        printf("Urun kodunu giriniz: ");
        if(scanf("%d", &urun_kodu) != 1) {
            printf("Gecersiz giris! Urun kodu bir tamsayi deger olmali.");
            continue;
        }
        printf("Adet sayisini giriniz: ");
        if(scanf("%d", &satis_adedi) != 1) {
            printf("Gecersiz giris! Urun adedi bir tamsayi deger olmali.");
            continue;
        }

        switch(urun_kodu) {
            case 1:
                if (!stoktan_dus(&urunler[0], satis_adedi)) { continue; }
                fise_kaydet(&urunler[0], satis_adedi);
                toplama_ekle(&urunler[0], satis_adedi);
                break;
            case 2:
                if (!stoktan_dus(&urunler[1], satis_adedi)) { continue; }
                fise_kaydet(&urunler[1], satis_adedi);
                toplama_ekle(&urunler[1], satis_adedi);
                break;
            case 3:
                if (!stoktan_dus(&urunler[2], satis_adedi)) { continue; }
                fise_kaydet(&urunler[2], satis_adedi);
                toplama_ekle(&urunler[2], satis_adedi);
                break;
            case 0:
                fisi_yazdir();
                return 0;
            default : 
                printf("Hatali bir urun kodu girdiniz! tekrar deneyiniz.");
                continue;
        }
    }
}