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

    User(std::string _id_user, std::string _passWord) : id_user(_id_user), passWord(_passWord){};

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
            std::cout << ANSI_COLOR_GREEN << " Votre mot de passe est correct  " << std::endl;
            std::cout << ANSI_COLOR_RESET << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        else
        {
            std::cout << ANSI_COLOR_RED << " Votre mot de passe est incorrect  " << std::endl;
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
            std::cout << "Entrez votre Identifiant : " << std::endl;
            std::cin >> id;

            std::cout << "Entrez votre mot de passe : " << std::endl;
            std::cin >> password;

            for (size_t i = 0; i < lignes_id.size(); ++i)
            {
                if (lignes_id[i] == id && lignes_mdp[i] == password)
                {
                    this->id_user = id;
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
    std::string Majuscule = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string Minuscule = "abcdefghijklmnopqrstuvwxyz";
    std::string Speciale = ",?;.:!%^$*-+~#'({@})";
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

    void new_user(std::string nomFichier) override
    {
        std::string ligne;
        int cas2;
        // std::ofstream fichier(fichierTXT, std::ios::app);        
        // std::ifstream fichier_lecture(fichierTXT);
        nomFichier = this->id_user + ".txt";
        // std::ofstream fichier_ecriture(nomFichier, std::ios::app);
        while (cas2 != 3)
        {
            printf("\e[1;1H\e[2J");
            std::cout << "*************************************************************************************************************************" << std::endl;
            std::cout << "                                              Compte de " << this->id_user << std::endl;
            std::cout << " 1. Generer un mot de passe pour un site" << std::endl;
            std::cout << " 2. lire vos mots de passes" << std::endl;
            std::cout << " 3. Quitter" << std::endl;
            std::cout << "                                              Quel choix voulez-vous faire :   " << std::endl;
            std::cin >> cas2;
            switch (cas2)
            {
            case 1:
            {
                printf("\e[1;1H\e[2J");
                std::ofstream fichier_ecriture(nomFichier, std::ios::app);
                std::string motdepasse = "";
                std::cout << " Pour quel site voulez vous generer un mot de passe ?" << std::endl;
                std::cin >> this->site;
                if (fichier_ecriture)
                {

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
                        int index = rand() % Speciale.size();
                        motdepasse += Speciale[index];
                    }
                    std::cout << "Votre mot de passe est : " << motdepasse << std::endl<< std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                    fichier_ecriture << this->site;
                    fichier_ecriture << "/" << motdepasse << std::endl;
                    std::cout << this->id_user << " Le site : " << site << " a bien ete ajoute." << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));
                }
                else
                {
                    std::cout << "Erreur fichier : " << std::endl;
                }
                break;
            }
            break;
            case 2:
            {
                printf("\e[1;1H\e[2J");
                std::ifstream fichier_lecture(nomFichier);
                if (fichier_lecture)
                {
                    bool found = false;
                    std::string ligne;
                    std::cout << " Pour quel site voulez vous voir le mot de passe ?" << std::endl;
                    std::cin >> this->site;
                    std::cout << "Voici votre mots de passe " << this->id_user << ":" << std::endl;
                    while (std::getline(fichier_lecture, ligne))
                    {
                        size_t pos = ligne.find("/");
                        std::string site_in_file = ligne.substr(0, pos);
                        if (site_in_file == this->site)
                        {
                            std::string mot_de_passe = ligne.substr(pos + 1);
                            std::cout << "Site : " << site_in_file << ", Mot de passe : " << mot_de_passe << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(5));
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        std::cout << "Aucun mot de passe trouvé pour le site : " << this->site << std::endl;
                        break;
                    }
                }
                else
                {
                    std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
                    break;
                }
                break;
            }
            break;

            default:
                break;
            }
        }
    }
};

int main(int /* argc */, char const * /* argv */[])
{
    User user("", "");
    std::string nom_fichier = "users.txt";
    std::string connexionFichier;

    int cas;
    while (cas != 3)
    {
        printf("\e[1;1H\e[2J");
        std::cout << "*************************************************************************************************************************" << std::endl;
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