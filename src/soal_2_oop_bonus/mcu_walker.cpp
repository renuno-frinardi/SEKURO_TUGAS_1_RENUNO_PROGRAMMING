#include "mcu_walker.hpp"

mcu_walker::mcu_walker(float cpu_speed,int memory,string os,string nama,int volt,int motor_speed,int rotation)
    : MCU(cpu_speed, memory, os, nama, volt), motor_speed(motor_speed), rotation(rotation) {
        printf("[KONSTRUKTOR WALKER] : Sistem gerak %s telah diinisialisasi.\n", getName().c_str());
}

mcu_walker::~mcu_walker() {
    printf("[DESTRUKTOR] : Komponen walker %s telah dimatikan.\n", getName().c_str());
}

void mcu_walker::rotate(int rotation) {
    this->rotation = rotation;
    printf("[WALKER] : %s berputar ke arah %d derajat.\n", getName().c_str(), rotation);
}

void mcu_walker::increase_speed(int speed) {
    motor_speed += speed;
    printf("[WALKER] : Kecepatan motor %s naik menjadi %d RPM.\n", getName().c_str(), motor_speed);
}

void mcu_walker::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    printf("Voltase %s berhasil dinaikkan ke: %dV\n", getName().c_str(), volt);
}

void mcu_walker::ganti_os(string new_os) {
    os = new_os;
    printf("[WALKER UPDATE] : %s migrasi OS ke %s\n", getName().c_str(), os.c_str());
}

void mcu_walker::showSpek() {
    printf("[SPEK MCU_WALKER] : %s\n", getName().c_str());
    printf("- CPU       : %.1f GHz\n", getCPUSpeed());
    printf("- RAM       : %d MB\n", getMemory());
    printf("- OS        : %s\n", os.c_str());
    printf("- Volt      : %d V\n", volt);
    printf("- Speed     : %d RPM\n", motor_speed);
    printf("- Rotation  : %d Deg\n", rotation);
}