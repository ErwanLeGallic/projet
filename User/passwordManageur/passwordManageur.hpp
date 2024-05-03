#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#include "../User.hpp"


class passwordManageur : private User
{
private:
    std::string site;
    std::string motdepasse = "";
    bool contientMajuscule = false;
    bool contientMinuscule = false;
    bool contientSpecial = false;
    bool contientNombre = false;
    int choixMaj;
    int choixMin;
    int choixSpe;
    int choixNombre;

public:
    passwordManageur(std::string _id_user, std::string _passWord, std::string _site);
    std::string Majuscule = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Minuscule = "abcdefghijklmnopqrstuvwxyz";
    std::string Speciale = ",?;.:!%^$*-+~#'({@})";
    std::string nombre = "0123456789";
    void new_user(std::string nomFichier) override;
    

};



