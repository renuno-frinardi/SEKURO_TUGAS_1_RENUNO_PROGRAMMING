#include "mcu.hpp"

MCU::MCU(float cpu_speed,int memory,string os,string name,int volt) 
    : cpu_speed(cpu_speed), memory(memory), os(os), name(name), volt(volt) {
        printf("[KONSTRUKTOR MCU] : Objek %s berhasil dibuat.\n", name.c_str());
};

MCU::~MCU() {
    printf("[DESTRUKTOR MCU] : Objek base %s dibersihkan.\n", name.c_str());
};

float MCU::getCPUSpeed() {
    return cpu_speed;
};

int MCU::getMemory() {
    return memory;
};

string MCU::getName() {
    return name;
};

void MCU::showSpek() {
    cout << "[BASE MCU] : " << name << " | CPU: " << cpu_speed 
         << "GHz | RAM: " << memory << "MB | OS: " << os 
         << " | Volt: " << volt << "V" << endl;
};

void MCU::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    printf("[BASE MCU] : Voltase %s berubah menjadi %dV\n", name.c_str(), volt);
};

void MCU::ganti_os(string new_os) {
    os = new_os;
    printf("[BASE MCU] : OS %s berhasil diganti ke %s\n", name.c_str(), os.c_str());
};