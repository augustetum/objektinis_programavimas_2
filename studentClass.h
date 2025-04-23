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
        string vardas_;
        string pavarde_;
        int egzaminas_;
        double galutinisMed_;
        double galutinisVid_;
        double pazymiuVidurkis_;
        vector<int> pazymiai_;
    
    public:
        Studentas(string var, string pav, vector<int> paz, int egz) :  
        vardas_{var}, pavarde_{pav}, pazymiai_{paz}, egzaminas_{egz} {
            skaiciuotiGalutiniSuMed();
            skaiciuotiGalutiniSuVid();
        }

        Studentas(string var, string pav) : vardas_{var}, pavarde_{pav}, egzaminas_(0) {
        }
        Studentas() : egzaminas_(0) {} 
        Studentas(std::istream& is);

        //copy konstruktorius
        Studentas(const Studentas &s)
        : vardas_{s.vardas_}, pavarde_{s.pavarde_}, egzaminas_{s.egzaminas_}, 
        galutinisMed_{s.galutinisMed_}, galutinisVid_{s.galutinisVid_}, pazymiuVidurkis_{s.pazymiuVidurkis_},
        pazymiai_{s.pazymiai_}{}

        //move konstruktorius
        Studentas(Studentas&& s)
        : vardas_{std::move(s.vardas_)}, pavarde_{std::move(s.pavarde_)}, egzaminas_{s.egzaminas_}, 
        galutinisMed_{s.galutinisMed_}, galutinisVid_{s.galutinisVid_}, pazymiuVidurkis_{s.pazymiuVidurkis_},
        pazymiai_{std::move(s.pazymiai_)}{}

        //destruktorius
        ~Studentas(){
            cout << "Destruktorius iškviestas" << endl;
            pazymiai_.clear();
        };

        //get'eriai
        inline std::string vardas() const { return vardas_; }    
        inline std::string pavarde() const { return pavarde_; } 
        inline double galutinisMed() const { return galutinisMed_;}
        inline double galutinisVid() const { return galutinisVid_;}
        inline const vector<int>& pazymiai() const { return pazymiai_; }
        inline int egzaminas() const { return egzaminas_; }

        //set'eriai
        inline void setVardas(string var) { vardas_ = var; }
        inline void setPavarde(string pav) { pavarde_ = pav; }
        inline void setGalutinisV(double galutVid) { galutinisVid_ = galutVid; }
        inline void setGalutinisM(double galutMed) { galutinisMed_ = galutMed; }
        inline void setEgzaminas(int egz) {egzaminas_ = egz; }
        inline void setPazymiai(vector<int> paz) {pazymiai_ = paz;}

        //member funkcijos
        void skaiciuotiGalutiniSuVid();
        void skaiciuotiGalutiniSuMed();

        //copy assignment operatorius 
        Studentas& operator=(const Studentas& s){
            if (this == &s) return *this;

            vardas_ = s.vardas_;
            pavarde_ = s.pavarde_;
            egzaminas_ = s.egzaminas_;
            galutinisMed_ = s.galutinisMed_;
            galutinisVid_ = s.galutinisVid_;
            pazymiuVidurkis_ = s.pazymiuVidurkis_;
            pazymiai_ = s.pazymiai_;
            
            return *this;
        }

        //move assignment operatorius
        Studentas& operator =(Studentas&& s){
            if (this == &s) return *this;

            vardas_ = std::move(s.vardas_);
            pavarde_ = std::move(s.pavarde_);
            egzaminas_ = s.egzaminas_;
            galutinisMed_ = s.galutinisMed_;
            galutinisVid_ = s.galutinisVid_;
            pazymiuVidurkis_ = s.pazymiuVidurkis_;
            pazymiai_ = std::move(s.pazymiai_);
            
            return *this;
        }

        //output operator
        friend std::ostream& operator<<(std::ostream& out, const Studentas &s);

        //input operator
        friend std::istream& operator>>(std::istream& cin, Studentas& s);
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
