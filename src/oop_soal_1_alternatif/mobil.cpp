#include "mobil.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

// === Implementasi Class mobil ===

mobil::mobil(int kapasitas_mesin, string name, string merk, int top_speed, string bahan_bakar) 
    : kapasitas_mesin(kapasitas_mesin), name(name), merk(merk), top_speed(top_speed), bahan_bakar(bahan_bakar) {
    printf("%s keluar dari pabrik %s nih gaspol ah\n", name.c_str(), merk.c_str());
}

void mobil::jalan(int jarak) {
    printf("Mobil %s sedang jalan sejauh %d kilometer\n", name.c_str(), jarak);
}

void mobil::pamer_mesin() {
    if (kapasitas_mesin < 2000) printf("Yah %s kagak bisa ngeraung CC mesinnya kurang\n", name.c_str());
    else printf("WRAAAUR %s meraung dengan kerennya\n", name.c_str());
}

void mobil::cek_spesifikasi() {
    cout << "=== Spesifikasi Standar " << name << " ===" << endl;
    cout << "Merk: " << merk << " | Mesin: " << kapasitas_mesin << " CC" << endl;
    cout << "Top Speed: " << top_speed << " km/jam | BBM: " << bahan_bakar << endl;
}

mobil::~mobil() {
    printf("BOOM %s Dihancurin\n", name.c_str());
}

// === Implementasi Class mobil_sport (Inheritance) ===

mobil_sport::mobil_sport(int kapasitas_mesin, string name, string merk, int top_speed, string bahan_bakar)
    : mobil(kapasitas_mesin, name, merk, top_speed, bahan_bakar), turbo_aktif(false) {}

void mobil_sport::jalan(int jarak) {
    printf("Wuzzz! mobil_sport %s melesat sejauh %d km!\n", name.c_str(), jarak);
}

void mobil_sport::cek_spesifikasi() {
    printf("=== Spesifikasi High-Performance %s ===\n", name.c_str());
    printf("Merk: %s | Mesin: %d CC\n", merk.c_str(), kapasitas_mesin);
    printf("Kecepatan Maksimum: %d km/jam | BBM: %s\n", top_speed, bahan_bakar.c_str());
    printf("Status Turbo: %s\n", turbo_aktif ? "Aktif" : "Non-aktif");
}

void mobil_sport::aktifkan_turbo() {
    turbo_aktif = true;
    printf("Turbo diaktifkan! Power %s meningkat drastis!\n", name.c_str());
}
