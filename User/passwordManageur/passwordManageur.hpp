#include <array>
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <algorithm> // pour std::shuffle
#include <random> 
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"
#include "../User.hpp"

class passwordManageur : public User
{
private:

    //attribut

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
    std::string Majuscule = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Minuscule = "abcdefghijklmnopqrstuvwxyz";
    std::string Speciale = ",?;.:!%^$*-+~#'({@})";
    std::string nombre = "0123456789";

public:

    //methode

    /**
     * la methode demandera a l'utilisateur qui est dans son compte ce qu'il veut faire entre:
    1. Generer un mot de passe pour un site
    2. lire vos mots de passes
    3. Quitter

    * @param nomFichier qui est le fichier personnel de l'user : "id_user.txt"
    * @return void
    */
    passwordManageur(std::string _id_user, std::string _passWord, std::string _site);

    /**
     * la methode demandera a l'utilisateur qui est dans son compte ce qu'il veut faire entre:
    1. Generer un mot de passe pour un site
    2. lire vos mots de passes
    3. Quitter

    * @param nomFichier qui est le fichier personnel de l'user : "id_user.txt"
    * @return void
    */
    void new_user(std::string nomFichier) override;
    

};



