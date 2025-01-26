#ifndef KASA_SIMULASYONU_H
#define KASA_SIMULASYONU_H

typedef struct Urun {
    char urun_adi[25];
    int urun_kodu;
    int stok_adedi;
    float fiyat;
}Urun;

struct SatinAlinan {
    char urun_adi[25];
    int adet;
    float fiyat;
}alisveris[50];

int stok_kontrol(Urun *urun, int satis_adedi);
int stoktan_dus(Urun *urun, int satis_adedi);
void fise_kaydet(Urun *urun, int satis_adedi);
void toplama_ekle(Urun *urun, int satis_adedi);
void fisi_yazdir();

#endif