#include <iostream>
using std::string;

class Zmogus {
    private:
        string vardas_;
        string pavarde_;
    public:
        //get'eriai
        inline std::string vardas() const { return vardas_; }    
        inline std::string pavarde() const { return pavarde_; } 

};