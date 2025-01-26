#include <stdio.h>
#include <assert.h>
#include "../include/kasa_simulasyonu.h"

void test_stok_kontrol() {
    // Test için örnek ürün oluştur
    Urun test_urun;
    test_urun.stok_adedi = 10;
    
    // Test 1: Stokta yeterli ürün var
    assert(stok_kontrol(&test_urun, 5) == 1);
    printf("Test 1 başarılı: Stok yeterli durumu\n");
    
    // Test 2: Stokta tam yeteri kadar ürün var
    assert(stok_kontrol(&test_urun, 10) == 1);
    printf("Test 2 başarılı: Stok tam yeteri kadar\n");
    
    // Test 3: Stokta yeterli ürün yok
    assert(stok_kontrol(&test_urun, 15) == 0);
    printf("Test 3 başarılı: Stok yetersiz durumu\n");
}

int main() {
    printf("Stok kontrol testleri başlıyor...\n");
    test_stok_kontrol();
    printf("Tüm testler başarıyla tamamlandı!\n");
    return 0;
}