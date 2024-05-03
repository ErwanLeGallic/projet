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
#include "User/PasswordManageur/PasswordManageur.hpp"


int main(int /* argc */, char const * /* argv */[])
{
    User user("", "");
    std::string nom_fichier = "users.txt";
    std::string connexionFichier;

    int cas;
    while (cas != 3)
    {
        printf("\e[1;1H\e[2J");
        std::cout << "********************************************************************************************************************************" << std::endl;
        std::cout << " 1. Inscription" << std::endl;
        std::cout << " 2. Connexion" << std::endl;
        std::cout << " 3. Quitter" << std::endl;
        std::cout << "                                              Quel choix voulez-vous faire :   " << std::endl;
        std::cin >> cas;
        switch (cas)
        {
        case 1:
            user.new_user(nom_fichier);
            break;
        case 2:
            bool identification_result = user.user_identification();
            passwordManageur password(user.id_user, "", "");
            std::cout << user.id_user << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            if (identification_result == true)
            {
                std::cout << ANSI_COLOR_GREEN << "Identification reussie !" << std::endl;
                std::cout << ANSI_COLOR_RESET << "";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                password.new_user(connexionFichier);
            }
            else
            {
                std::cout << ANSI_COLOR_RED << "Erreur d'identification. Veuillez reessayer." << std::endl;
                std::cout << ANSI_COLOR_RESET << "";
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            break;
            /*default:
                std::cout << "Choix invalide" << std::endl;*/
        }
    }
    return 0;
}