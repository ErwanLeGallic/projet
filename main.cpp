
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>

class User
{
public:
    std::string id_user = "";
    std::array<int, 4> passWord = {0, 0, 0, 0};
    bool identification = false;

    User(std::string _id_user, std::array<int, 4> _passWord) :
        id_user(_id_user), passWord(_passWord) {}

    void new_user(std::string fichierTXT)
    {
        std::cout << "Entrer votre identifiant : " << std::endl;
        std::cin >> this->id_user;
        std::cout << "Entrer votre mot de passe à 4 chiffres : " << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cin >> this->passWord[i];
        }

        std::ofstream monFlux(fichierTXT, std::ios::app);

        if (monFlux)
        {
            monFlux << "User ID: " << this->id_user << std::endl;
            monFlux << "Password: " << this->passWord[0] << this->passWord[1] << this->passWord[2] << this->passWord[3] << std::endl;
            std::cout << "L'utilisateur : " << id_user << " a bien été ajouté." << std::endl;
        }
        else
        {
            std::cout << "Erreur fichier : " << std::endl;
        }
    }

    bool user_identification(std::string &id, std::array<int, 4> &passWord)
    {
        std::ifstream monFichier("C:/Users/Acer Nitro RTX/programation/projet/users.txt");

        if (monFichier)
        {
            std::vector<std::string> lignes_id;
            std::vector<std::array<int, 4>> lignes_mdp;
            std::string ligne;

            while (std::getline(monFichier, ligne))
            {
                if (ligne.find("User ID:") )
                {
                    lignes_id.push_back(ligne.substr(9));
                }
                //else if (ligne.find("Password"))
                //{
                //    lignes_mdp.push_back(ligne.substr(9));
                //}
                else if (ligne.find("Password:"))
                {
                    std::array<int, 4> password;
                    for (int i = 0; i < 4; ++i)
                    {
                        monFichier >> password[i];
                        lignes_mdp.push_back(password);

                    }
                }
            }

            std::cout << "Entrez votre ID : " << std::endl;
            std::cin >> id;

            int id_index = -1;
            for (int i = 0; i < lignes_id.size(); ++i)
            {
                if (lignes_id[i] == id)
                {
                    id_index = i;
                }
            }

            if (id_index == -1)
            {
                std::cerr << "ID non trouvé dans le fichier." << std::endl;
                return false;
            }
            std::array<int, 4> password;
            std::cout << "Entrez votre mdp : " << std::endl;
            std::cin >> password[0]>> password[1]>> password[2]>> password[3];
            if (passWord == lignes_mdp[id_index]) return true;
        }
        else
        {
            std::cerr << "Erreur d'ouverture du fichier." << std::endl;
            return false;
        }
    }

    ~User(){
        std::cout << "Passage destructeur" << std::endl;

    }

};




int main(int argc, char **argv)
{
    User user("", {0, 0, 0, 0});
    std::string nom_fichier = "C:/Users/Acer Nitro RTX/programation/projet/users.txt";

    int cas;

    while(cas!=5){
        std::cout << "Pour creer un compte, tapez 1" << std::endl;
        std::cout << "Pour vous connecter, tapez 2" << std::endl;
        std::cout << "Pour vous quitter, tapez 5" << std::endl;
        std::cin >> cas;
        switch (cas)
        {
        case 1:
            user.new_user(nom_fichier);
            break;
        case 2:    
            bool identification_result = user.user_identification(user.id_user, user.passWord);
            if (identification_result)
            {
                std::cout << "Identification reussie !" << std::endl;

            }
            else
            {
                std::cerr << "Erreur d'identification. Veuillez reessayer." << std::endl;
            }
            break;
        } groupe 6
    }   
    return 0;
}
