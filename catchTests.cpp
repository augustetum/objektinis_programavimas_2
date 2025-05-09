#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "studentClass.h"

TEST_CASE("Studento Rule of Five testai", "[studentas]") {

    SECTION("Copy Konstruktorius") {
        vector<int> pazymiai = {8, 9, 10, 7, 8};
        Studentas originalas("Jonas", "Jonaitis", pazymiai, 9);
        Studentas kopija(originalas);
        
        REQUIRE(kopija == originalas);
    }   

    SECTION("Move konstruktorius") {
        
    }
}