#pragma once
#include "bits/stdc++.h"

using namespace std;

class Core_MCU{
    private:
        float cpu_speed;
        int memory;
        string os;
        string nama;
        int volt;
    public:
        Core_MCU(float cpu_speed,int memory,string os,string nama,int volt);
        void showSpek();
        ~Core_MCU();
        void nambah_volt(int penambahan_voltase);
        void ganti_os(string new_os);
        string get_os();
};

