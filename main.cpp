
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

class User
{
public:
    std::string id_user = "";
    std::string passWord = "";
    bool identification = false;

    User(std::string _id_user, std::string _passWord) : id_user(_id_user), passWord(_passWord) {}

    void new_user(std::string fichierTXT)
    {
        std::string verifPassword = "";
        std::cout << "Entrer votre identifiant : " << std::endl;
        std::cin >> this->id_user;
        std::cout << "Entrer votre mot de passe : " << std::endl;
        std::cin >> this->passWord;
        std::cout << "Entrer votre mot de passe a nouveau : " << std::endl;
        std::cin >> verifPassword;
        if (this->passWord == verifPassword)
        {
            std::cout << ANSI_COLOR_GREEN << " Verification mot de passe good  " << std::endl;
            std::cout << ANSI_COLOR_RESET << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else
        {
            std::cout << ANSI_COLOR_RED << " Verification mot de passe erreur  " << std::endl;
            std::cout << ANSI_COLOR_RESET << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        /// verification mot de passe A faire ici

        std::ofstream monFlux(fichierTXT, std::ios::app);

        if (monFlux)
        {
            monFlux << this->id_user;
            monFlux << "/" << this->passWord << std::endl;
            std::cout << "L'utilisateur : " << id_user << " a bien ete ajoute." << std::endl;
        }
        else
        {
            std::cout << "Erreur fichier : " << std::endl;
        }
    }

    bool user_identification(void)
    {
        std::ifstream monFichier("users.txt");

        if (monFichier)
        {
            std::vector<std::string> lignes_id;
            std::vector<std::string> lignes_mdp;
            std::string ligne;
            size_t found;
            while (std::getline(monFichier, ligne))
            {

                found = ligne.find("/");
                std::string user = ligne.substr(0, found);
                std::string mdp = ligne.substr(found + 1);
                lignes_mdp.push_back(mdp);
                lignes_id.push_back(user);
            }
            std::string password;
            std::string id;
            std::cout << "Entrez votre ID : " << std::endl;
            std::cin >> id;

            std::cout << "Entrez votre mdp : " << std::endl;
            std::cin >> password;

            for (size_t i = 0; i < lignes_id.size(); ++i)
            {
                if (lignes_id[i] == id && lignes_mdp[i] == password)
                {
                    return true;
                }
            }
        }
        else
        {
            std::cerr << "Erreur d'ouverture du fichier." << std::endl;
        }
        return false;
    }

    ~User()
    {
        std::cout << "Passage destructeur" << std::endl;
    }
};

int main(int /* argc */, char const * /* argv */[])
{
    User user("", "");
    std::string nom_fichier = "users.txt";

    int cas;

    while (cas != 3)
    {
        std::cout << "*************************************************************************************************************************" << std::endl;
        std::cout << " 1. Inscription" << std::endl;
        std::cout << " 2. Connexion" << std::endl;
        std::cout << " 3. Quitter" << std::endl;
        std::cout << "                                              Quelle choix voulez-vous faire :   " << std::endl;
        std::cin >> cas;
        switch (cas)
        {
        case 1:
            user.new_user(nom_fichier);
            break;
        case 2:
            bool identification_result = user.user_identification();
            if (identification_result)
            {
                std::cout << "Identification reussie !" << std::endl;

            }
            else
            {
                std::cerr << "Erreur d'identification. Veuillez reessayer." << std::endl;
                
            }
            break;
        /*default:
            std::cout << "Choix invalide" << std::endl;*/
        }
    }
    return 0;
}