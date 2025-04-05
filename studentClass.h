#ifndef MANO_LIB_H
#define MANO_LIB_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <ctime>
#include <sstream>
#include <chrono>
#include <unordered_set>
#include <limits>
#include <ios>
#include "timer.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::accumulate;
using std::ifstream;
using std::istringstream;

class Studentas {

    private:
        std::string vardas;
        std::string pavarde;
        double egzaminas;
        double galutinisMed;
        double galutinisVid;
        double pazymiuVidurkis;
        std::vector<int> pazymiai;
    
    public:
        Studentas(string var, string pav, vector<double> paz, double egz) :  vardas{var}, pavarde{pav}, pazymiai{paz}, egzaminas{egz} {}
        Studentas() : egzaminas(0) { } 
        Studentas(std::istream& is);

        //get'eriai
        inline std::string vardas() const { return vardas; }    
        inline std::string pavarde() const { return pavarde; } 
        inline double galutinisMed() const { return galutinisMed;}
        inline double galutinisVid() const { return galutinisVid;}
        inline vector<int> pazymiai() const { return pazymiai;}
        inline int egzaminas() const { return egzaminas; }

        //set'eriai
        inline void setVardas(string vardas) { this->vardas = vardas; }
        inline void setPavarde(string pavarde) { this->pavarde = pavarde; }
        inline void setGalutinisV(double galutinisVid) { this->galutinisVid = galutinisVid; }
        inline void setGalutinisM(double galutinisMed) { this->galutinisMed = galutinisMed; }
        inline void setEgzaminas(int egzaminas) {this-> egzaminas = egzaminas; }

        //member funkcijos
        void skaiciuotiGalutiniSuVid();
        void skaiciuotiGalutiniSuMed();

};

bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalEgza(const Studentas&, const Studentas&);

void rodytiRezultatus(vector<Studentas> studentuSarasas);
void generuotiPazymius(vector<Studentas> &studentuSarasas);
void generuotiStudentus(vector<Studentas> &studentuSarasas);
void generuotiFailus(int studentuSkaicius);
string pasirinktiFaila();
void nuskaitytiFaila(string fail, vector<Studentas> &studentuSarasas);
void rodytiVisusRezultatus(vector<Studentas> studentuSarasas);
void testuotiFailuNuskaityma(vector<Studentas> studentuSarasas, int kartai);

//rikiavimo funkcijos
void rikiuotiPagalVarda(vector<Studentas> &studentuSarasas);
void rikiuotiPagalPavarde(vector<Studentas> &studentuSarasas);
void rikiuotiPagalGalutiniMed(vector<Studentas> &studentuSarasas);
void rikiuotiPagalGalutiniVid(vector<Studentas> &studentuSarasas);

void pasirinktiRikiavima(vector<Studentas> studentuSarasas);
void skirstytiStudentus(vector<Studentas> &studentuSarasas);

bool vardoTikrinimas(const string &vard);
void isvestiDuFailus(vector<Studentas> grupe1, vector<Studentas> grupe2);
void rikiavimasIrIrasymasVargsiukamsIrKietekams(vector<Studentas> vargsiukai, vector<Studentas> kietekai);

#endif
