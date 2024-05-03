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
    //creation des objets user et nom_fichier
    User user("", "");
    std::string nom_fichier = "users.txt";
    std::string connexionFichier;

    int cas;
    while (cas != 3)
    {
        printf("\e[1;1H\e[2J");//permet de clean le terminal
        std::cout << "******************************************************************************************************************************" << std::endl;
        std::cout << " 1. Inscription" << std::endl;
        std::cout << " 2. Connexion" << std::endl;
        std::cout << " 3. Quitter" << std::endl;
        std::cout << "                                              Quel choix voulez-vous faire :   " << std::endl;
        std::cin >> cas;
        switch (cas)
        {
        case 1:
            user.new_user(nom_fichier);//appel la methode new_user de la class user
            break;
        case 2:
            bool identification_result = user.user_identification();
            passwordManageur password(user.id_user, "", "");//cree un objet password qui à en id_user l'id de l'objet user
            std::this_thread::sleep_for(std::chrono::seconds(1));//Delay de 1 seconde

            if (identification_result == true)
            {
                std::cout << ANSI_COLOR_GREEN << "Identification reussie !" << std::endl;//change la couleur du texte
                std::cout << ANSI_COLOR_RESET << "";
                std::this_thread::sleep_for(std::chrono::seconds(1));//Delay de 1 seconde
                password.new_user(connexionFichier);
            }
            else
            {
                std::cout << ANSI_COLOR_RED << "Erreur d'identification. Veuillez reessayer." << std::endl;//change la couleur du texte
                std::cout << ANSI_COLOR_RESET << "";
                std::this_thread::sleep_for(std::chrono::seconds(1));//Delay de 1 seconde
            }
            break;
        }
    }
    return 0;
}