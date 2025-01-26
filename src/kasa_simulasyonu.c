/**
 * Market Simulasyonu
 * @brief Bu program cok basit bir sekilde bir market kasasini simule eder
 * @author AlgoRogue
 * @date 24.01.2025
 * @version 1.7
 */

#include <stdio.h>
#include <string.h>
#include "../include/kasa_simulasyonu.h"

int alisveris_sayisi = 0;
float genel_toplam = 0;
struct SatinAlinan alisveris[50];

/**
 * @brief stok kontrolunun yapildigi fonksiyon
 * @param Urun urunler: uzerinde islem yapilacak urun kalemi
 * @param satis_adedi stokta bu deger urun olmali
 * @return stokta yeterli urun varsa 1 yoksa 0 dondurur
 */
int stok_kontrol(Urun *urun, int satis_adedi) {
    return urun->stok_adedi >= satis_adedi;
}

/**
 * @brief satilan urunu stoktan dusen fonksiyon
 * @param Urun urun: uzerinde islem yapilacak urun kalemi
 * @param satis_adedi stoktan dusulecek adet
 * @return islem basarili olursa 1 olmazsa 0 dondurur
 */
int stoktan_dus(Urun *urun, int satis_adedi) {
    if(stok_kontrol(urun, satis_adedi)){
        urun->stok_adedi -= satis_adedi;
        printf("%d Adet %s: %.2f TL\n", satis_adedi, urun->urun_adi, urun->fiyat * satis_adedi);
        return 1;
    } else {
        printf("Stokta yeterli sayida %s yok\n", urun->urun_adi);
        return 0;
    }
}

/**
 * @brief satilan urunlerin fise basilmadan once saklanmasini saglan fonksiyon
 * @param Urun urun: fise basilacak urun
 * @param satis_adedi fise basilacak urun sayisi
 */
void fise_kaydet(Urun *urun, int satis_adedi) {
    strcpy(alisveris[alisveris_sayisi].urun_adi, urun->urun_adi);
    alisveris[alisveris_sayisi].adet = satis_adedi;
    alisveris[alisveris_sayisi].fiyat = urun->fiyat;
    alisveris_sayisi++;
}

void toplama_ekle(Urun *urun, int satis_adedi) {
    genel_toplam += urun->fiyat * satis_adedi;
}

void fisi_yazdir() {
    printf("===================================\n");
    printf("        CanKardesler Market        \n");
    printf("===================================\n\n");

    for(int i = 0; i < alisveris_sayisi; i++) {
        printf("%d Adet %s\n", alisveris[i].adet, alisveris[i].urun_adi);
        printf("Birim Fiyat: %.2f TL\n", alisveris[i].fiyat);
        printf("Toplam: %.2f TL\n", alisveris[i].fiyat * alisveris[i].adet);
        printf("-----------------------------------\n");
    }

    printf("\nGENEL TOPLAM: %.2f TL\n", genel_toplam);
    printf("===================================\n");
    printf("      Bizi Tercih Ettiginiz        \n");
    printf("         Icin Tesekkurler          \n");
    printf("===================================\n");   
}