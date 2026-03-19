#include "mcu_cam_controller.hpp"

int mcu_cam_controller::count_detected_obj = 0;

mcu_cam_controller::mcu_cam_controller(float cpu_speed,int memory,string os,string nama,int volt,string obj_detected) 
    : MCU(cpu_speed, memory, os, nama, volt), obj_detected(obj_detected) {
        count_detected_obj = 1;
        printf("[KONSTRUKTOR CAM] : Komponen kamera untuk %s siap digunakan.\n", nama.c_str());
}

mcu_cam_controller::~mcu_cam_controller() {
    printf("[DESTRUKTOR] : Objek %s telah dihapus dari memori.\n", getName().c_str());
}

void mcu_cam_controller::showSpek() {
    printf("[SPEK MCU_CAM] : %s | [CPU] : %.1f GHz | [Memory] : %d MB | [OS] : %s | [Volt] : %dV | [Last Obj] : %s | [Total Detect] : %d\n", 
        getName().c_str(), getCPUSpeed(), getMemory(), os.c_str(), volt, obj_detected.c_str(), count_detected_obj);
}

void mcu_cam_controller::detect_other_object(string other, bool moving) {
    obj_detected = other;
    count_detected_obj++;
    printf("[CAM SYSTEM] : Terdeteksi %s (Status: %s)\n", other.c_str(), moving ? "Bergerak/Aktif" : "Diam/Statis");
}

void mcu_cam_controller::nambah_volt(int penambahan_voltase) {
    volt = volt + penambahan_voltase;
    printf("Voltase %s berhasil dinaikkan ke : %dV\n", getName().c_str(), volt);
}

void mcu_cam_controller::ganti_os(string new_os) {
    os = new_os;
    printf("[CAM UPDATE] : %s migrasi OS ke %s\n", getName().c_str(), os.c_str());
}