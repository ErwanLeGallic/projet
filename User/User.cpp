#include "User.hpp"

//constructeur
User ::User(std::string _id_user, std::string _passWord) : id_user(_id_user), passWord(_passWord){} 

//destructeur
User ::~User()
{
    std::cout << "Aurevoir : " << this->id_user << std::endl;
}

//methode
bool User::user_identification()
    {
        std::ifstream monFichier("users.txt");//ouvre le fichier en lecture

        if (monFichier)
        {
            std::vector<std::string> lignes_id;
            std::vector<std::string> lignes_mdp;
            std::string ligne;
            size_t found;
            while (std::getline(monFichier, ligne))
            {
                found = ligne.find("/");//on detecte le separateur "/"
                //extrait une sous-chaîne de la ligne, commençant à l'indice 0 et se terminant juste avant la position de la première occurrence de "/". 
                //Cette sous-chaîne correspond à l'identifiant de l'utilisateur.                
                std::string user = ligne.substr(0, found);
                //on fera de meme pour le mot de passe
                std::string mdp = ligne.substr(found + 1);

                //Ces lignes ajoutent le mot de passe extrait et l'identifiant extrait aux vecteurs lignes_mdp et lignes_id,respectivement. 
                //Ces vecteurs sont utilisés pour stocker tous les identifiants et mots de passe lus à partir du fichier "users.txt".
                lignes_mdp.push_back(mdp);
                lignes_id.push_back(user);
            }
            std::string password;
            std::string id;
            std::cout << "Entrez votre Identifiant : " << std::endl;
            std::cin >> id;

            std::cout << "Entrez votre mot de passe : " << std::endl;
            std::cin >> password;
            
            //On fait l'identification
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

void User::new_user(std::string fichierTXT){
    
        std::string verifPassword = "";
        std::cout << "Entrer votre identifiant : " << std::endl;
        std::cin >> this->id_user;
        std::cout << "Entrer votre mot de passe : " << std::endl;
        std::cin >> this->passWord;
        std::cout << "Entrer votre mot de passe a nouveau : " << std::endl;
        std::cin >> verifPassword;
    
        if (this->passWord == verifPassword)
        {
            std::cout << ANSI_COLOR_GREEN << " Votre mot de passe est correct  " << std::endl;//colloration du texte
            std::cout << ANSI_COLOR_RESET << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));//Delay de 1 seconde
        }
        else
        {
            std::cout << ANSI_COLOR_RED << " Votre mot de passe est incorrect  " << std::endl;//colloration du texte
            std::cout << ANSI_COLOR_RESET << "" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));//Delay de 1 seconde
        }

        std::ofstream monFlux(fichierTXT, std::ios::app);//ouverture du fichier en ecriture

        if (monFlux)
        {
            monFlux << this->id_user;//on ajoute id_user au fichier
            monFlux << "/" << this->passWord << std::endl;
            std::cout << "L'utilisateur : " << id_user << " a bien ete ajoute." << std::endl;
        }
        else
        {
            std::cout << "Erreur fichier : " << std::endl;
        }
}
    