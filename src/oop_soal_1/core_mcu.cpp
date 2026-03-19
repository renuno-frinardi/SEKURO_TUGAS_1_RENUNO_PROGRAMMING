#include "core_mcu.hpp"

Core_MCU::Core_MCU(float cpu_speed,int memory,string os,string nama,int volt) 
    : cpu_speed(cpu_speed), memory(memory), os(os), nama(nama), volt(volt) {
        printf("[Core_MCU] : MCU utama yang bernama %s telah dibuat\n", nama.c_str());
    showSpek();
}

Core_MCU::~Core_MCU() {
    printf("[Core_MCU] : MCU utama yang bernama %s telah dihapus\n", nama.c_str());
}

void Core_MCU::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
    printf("[Core_MCU] : MCU utama yang bernama %s telah ditambah voltasenya menjadi = %d\n", 
        nama.c_str(), volt);
}

void Core_MCU::ganti_os(string new_os) {
    os = new_os;
    printf("[Core_MCU] : MCU utama yang bernama %s telah diganti OS nya menjadi = %s\n", 
        nama.c_str(), os.c_str());
}

string Core_MCU::get_os() {
    return os;
}

void Core_MCU::showSpek() {
    printf("[SPEK DEVICE] : [NAMA_DEVICE]: %s | [CPU_CLOCK] : %.1f | [MEMORY] : %d | [OS] : %s\n",
        nama.c_str(), cpu_speed, memory, os.c_str());
}