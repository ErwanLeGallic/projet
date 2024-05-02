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

    User(std::string _id_user, std::string _passWord) : id_user(_id_user), passWord(_passWord) {};

    virtual void new_user(std::string fichierTXT)
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
        std::cout << "Aurevoir : " << this->id_user << std::endl;
    }
};

class passwordManageur : public User
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
    passwordManageur(std::string _id_user, std::string _passWord, std::string _site) : User(_id_user, _passWord), site(_site){};
    std::string Majuscule = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    std::string Minuscule = "azertyuiopqsdfghjklmwxcvbn";
    std::string Speciale = ",?;.:/!%^$*-/+";
    std::string nombre = "0123456789";
    bool verification(std::string _motdepasse)
    {
        for (char caractere : _motdepasse)
        {
            if (Majuscule.find(caractere) >= 1)
            {
                contientMajuscule = true;
            }
            else if (Minuscule.find(caractere) >= 1)
            {
                contientMinuscule = true;
            }
            else if (Speciale.find(caractere) >= 1)
            {
                contientSpecial = true;
            }
            else if (nombre.find(caractere) >= 1)
            {
                contientNombre = true;
            }
        }
        if (contientMajuscule == true && contientMinuscule == true && contientSpecial == true)
        {
            return true;
        }
        return false;
    }

    void new_user(std::string fichierTXT) override
    {
        std::string ligne;
        std::ofstream monFlux(fichierTXT, std::ios::app);
        system("cls");
        std::cout << "*************************************************************************************************************************" << std::endl;
        std::cout << " 1. Generer un mdp d'un site" << std::endl;
        std::cout << " 2. lire les mots de passes" << std::endl;
        std::cout << " 3. Quitter" << std::endl;
        std::cout << "                                              Quelle choix voulez-vous faire :   " << std::endl;
        int cas2;
        std::cin >> cas2;
        std::ifstream fichier(fichierTXT);
        switch (cas2)
        {
        case 1:
            std::cout << " Pour quel site voulez vous generer un mot de passe ?" << std::endl;
            std::cin >> this->site;
            size_t found;
            while (getline(fichier, ligne))
            {
                found = ligne.find(id_user);
                
            }

            std::cout << "Combien de Nombre voulez vous : ";
            std::cin >> this->choixNombre;
            std::cout << std::endl;
            std::cout << "Combien de Majuscule voulez vous : ";
            std::cin >> this->choixMaj;
            std::cout << std::endl;
            std::cout << "Combien de Minuscule voulez vous : ";
            std::cin >> this->choixMin;
            std::cout << std::endl;
            std::cout << "Combien de caractere speciale voulez vous : ";
            std::cin >> this->choixSpe;
            std::cout << std::endl;
            for (int i = 0; i < this->choixNombre; i++)
            {
                int index = rand() % nombre.size();
                motdepasse += nombre[index];
            }
            for (int i = 0; i < this->choixMaj; i++)
            {
                int index = rand() % Majuscule.size();
                motdepasse += Majuscule[index];
            }
            for (int i = 0; i < this->choixMin; i++)
            {
                int index = rand() % Minuscule.size();
                motdepasse += Minuscule[index];
            }
            for (int i = 0; i < this->choixSpe; i++)
            {
                int index = rand() % Minuscule.size();
                motdepasse += Speciale[index];
            }
            std::cout << "Votre mot de passe est : " << motdepasse << std::endl;

            break;
        case 2:
            /* code */
            break;

        default:
            break;
        }
    }
};

    int main(int /* argc */, char const * /* argv */[])
    {
        User user("", "");
        std::string nom_fichier = "users.txt";

        int cas;
        while (cas != 3)
        {
            system("cls");
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
                if (identification_result == true)
                {
                    std::cout << ANSI_COLOR_GREEN << "Identification reussie !" << std::endl;
                    std::cout << ANSI_COLOR_RESET << "";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
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