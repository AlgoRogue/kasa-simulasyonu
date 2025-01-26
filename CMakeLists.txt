cmake_minimum_required(VERSION 3.10)
project(KasaSimulasyonu C)

# Ana uygulama için kaynak dosyaları
set(SOURCE_FILES
    src/main.c
    src/kasa_simulasyonu.c
)

# Ana uygulamayı oluştur
add_executable(kasa_simulasyonu ${SOURCE_FILES})
target_include_directories(kasa_simulasyonu PRIVATE include)

# Test uygulaması için kaynak dosyaları
set(TEST_FILES
    tests/test_stok.c
    src/kasa_simulasyonu.c
)

# Test uygulamasını oluştur
add_executable(run_tests ${TEST_FILES})
target_include_directories(run_tests PRIVATE include)