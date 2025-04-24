<h1>v1.2</h2>

<p>v1.2 šakoje implementuoti ir testuoti "Rule of five" metodai bei perdengti įvesties ir išvesties operatoriai. Jų veikimas pritaikytas anksčiau naudotose programos dalyse, tokiose kaip: nuskaitymas iš failo, studentų įvedimas ranka, studentų rezultatų išvedimas. </p>

<p> Žemiau pateikiamos kodo iškarpos, rodančios "Rule of five" bei operatorių perdengimą. </p>

```cpp
//copy konstruktorius
        Studentas(const Studentas &s)
        : vardas_{s.vardas_}, 
        pavarde_{s.pavarde_}, 
        egzaminas_{s.egzaminas_}, 
        galutinisMed_{s.galutinisMed_}, 
        galutinisVid_{s.galutinisVid_}, 
        pazymiuVidurkis_{s.pazymiuVidurkis_},
        pazymiai_{s.pazymiai_}{}

//move konstruktorius
        Studentas(Studentas&& s)
        : vardas_{std::move(s.vardas_)}, 
        pavarde_{std::move(s.pavarde_)}, 
        egzaminas_{s.egzaminas_}, 
        galutinisMed_{s.galutinisMed_}, 
        galutinisVid_{s.galutinisVid_}, 
        pazymiuVidurkis_{s.pazymiuVidurkis_},
        pazymiai_{std::move(s.pazymiai_)}{}

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

//destruktorius
        ~Studentas(){
            vardas_.clear();
            pavarde_.clear();
            pazymiai_.clear();
        };

//perdengtas įvesties operatorius (panaikintas vardo ir pavardės tikrinimas dėl failuose esančio formatavimo, kur vardas ir pavardė GALI turėti skaičius)
std::istream& operator>>(std::istream& cin, Studentas& s){
            string vardas, pavarde;
            vector<int> pazymiai;
            int egzaminas, pazymys;

            cin >> vardas >> pavarde;

            if (cin.eof()) {
                throw std::runtime_error("Netinkamas failo formatas: faile nėra pažymių");
            }
                
            while (cin >> pazymys){
                if (cin.fail()){
                    if (cin.eof()){
                        break;
                    }
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::runtime_error("Netinkamas failo formatas: pažymiai nėra skaitinės reikšmės");
                }
                    if (pazymys < 1 || pazymys > 10){
                        throw std::runtime_error("Netinkamas failo formatas: pažymiai nėra sveiki skaičiai ribose nuo 1 iki 10");
                    }
                    pazymiai.push_back(pazymys);
                }
                if (!pazymiai.empty()) {
                    egzaminas = pazymiai.back();
                    pazymiai.pop_back();
                } else {
                    throw std::runtime_error("Netinkamas failo formatas: faile nėra pažymių");
                }
                s = Studentas(vardas, pavarde, pazymiai, egzaminas);
            return cin;
}

//perdengtas išvesties operatorius
std::ostream& operator<<(std::ostream& out, const Studentas &s) {
            out << std::left << std::setw(20) << s.pavarde() << std::setw(20) << s.vardas() << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisVid() << std::setw(20) << std::fixed << std::setprecision(2) << s.galutinisMed() << endl;
            return out;
        }

```
v1.2 versijoje sukurta klasės testavimo programa leidžia testuoti visas minėtas funkcijas, gaunami rezultatai: 
```cpp
—— Default konstruktorius ——
Egzaminas: 0

—— Vardo, pavardės konstruktorius ——
Vardas: Jonas, pavardė: Jonaitis

—— Pilnas konstruktorius ——
Vardas: Petras, pavardė: Petraitis, egzaminas: 9, galutinis vid: 8.76, galutinis med: 8.6

—— Copy konstruktorius ——
s3 kopija - vardas: Petras, pavardė: Petraitis, egzaminas: 9, galutinis vid: 8.76

Po kopijos pakeitimo - s3.vardas: Petras, s4.vardas: Antanas

—— Move konstruktorius ——
Movint’as iš s4 - vardas: Antanas, pavardė: Petraitis, egzaminas: 9

—— Copy assignment operatorius ——
s6 po s3 kopijavimo - vardas: Petras, pavardė: Petraitis

—— Move assignment operatorius ——
s7 po movinimo iš s6 - vardas: Petras, pavardė: Petraitis

—— Output’o operatorius ——
s3 naudojant operatorių <<: Petraitis           Petras              8.76                8.60                


—— Input’o operatorius ——
s8 po input: Tomauskas           Tomas               8.52                8.60                


—— Destruktorius ——
Destruktorius suveikė
```
<p>Ankstesnė v1.1 šaka skirta palyginti "class" ir "struct" naudojimą talpinant studento duomenis. Tyrimas ir jo rezultatai pateikiami žemiau, v1.1 implementuota "class" lyginama su v1.0 versijoje naudotu "struct".</p>

<p>Tyrimas vykdytas su 3 strategija (žr. v1.0) bei vektoriaus konteineriu, vykdytos 3 iteracijos.</p>

<h3>"Class" ir "struct" | Tyrimo rezultatai  </h3>

| Programos veikimo laikas su CLASS | Programos veikimo laikas su STRUCT | Studentų kiekis | Optimizavimo vėliava | .exe failo dydis su CLASS (KB)| .exe failo dydis su STRUCT |
| ------ | ----- | --------------- | ------------------------ | ---- | ---- | 
| 0.434467s | 0.418547s | 100 000 | -O3 | 332 | 329
| 0.453639s | 0.428051s | 100 000 | -O2 | 319 | 315
| 0.453065s | 0.427737s | 100 000 | -O1 | 317 | 331
| 1.54309s | 1.32805s | 100 000 | - | 861 | 841 | 
| |
| 1.95142s | 1.70978s | 1 000 000 | -O3 | 332 | 329
| 1.9155s | 1.73843s | 1 000 000 | -O2 | 319 | 315
| 1.93125s | 1.7828s | 1 000 000 | -O1 | 317 | 331
| 7.94422s | 6.41446s | 1 000 000 | - | 861 | 841




