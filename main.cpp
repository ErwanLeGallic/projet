
// #include <array>
// #include <vector>
// #include <iostream>
// #include <string>
// #include <cstdlib>
// #include <chrono>
// #include <thread>
// #include <fstream>
// #include <sstream>
// #define ANSI_COLOR_RED "\x1b[31m"
// #define ANSI_COLOR_GREEN "\x1b[32m"
// #define ANSI_COLOR_RESET "\x1b[0m"

// class User
// {
// public:
//     std::string id_user = "";
//     std::string passWord = "";
//     bool identification = false;

//     User(std::string _id_user, std::string _passWord) : id_user(_id_user), passWord(_passWord) {}

<<<<<<< HEAD
//     void new_user(std::string fichierTXT)
//     {
//         std::string verifPassword = "";
//         std::cout << "Entrer votre identifiant : " << std::endl;
//         std::cin >> this->id_user;
//         std::cout << "Entrer votre mot de passe : " << std::endl;
//         std::cin >> this->passWord;
//         std::cout << "Entrer votre mot de passe a nouveau : " << std::endl;
//         std::cin >> verifPassword;
//         if (this->passWord == verifPassword)
//         {
//             std::cout << ANSI_COLOR_GREEN << " Verification mot de passe good  " << std::endl;
//             std::cout << ANSI_COLOR_RESET << "" << std::endl;
//             std::this_thread::sleep_for(std::chrono::seconds(1));
//         }
//         else
//         {
//             std::cout << ANSI_COLOR_RED << " Verification mot de passe erreur  " << std::endl;
//             std::cout << ANSI_COLOR_RESET << "" << std::endl;
//             std::this_thread::sleep_for(std::chrono::seconds(1));
//         }

//         /// verification mot de passe A faire ici

//         std::ofstream monFlux(fichierTXT, std::ios::app);
=======
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
>>>>>>> 634f8924d6e84bdaac38999c2fae188d29178e22

//         if (monFlux)
//         {
//             monFlux << this->id_user;
//             monFlux << "/" << this->passWord << std::endl;
//             std::cout << "L'utilisateur : " << id_user << " a bien ete ajoute." << std::endl;
//         }
//         else
//         {
//             std::cout << "Erreur fichier : " << std::endl;
//         }
//     }

//     bool user_identification(void)
//     {
//         std::ifstream monFichier("users.txt");

//         if (monFichier)
//         {
//             std::vector<std::string> lignes_id;
//             std::vector<std::string> lignes_mdp;
//             std::string ligne;
//             size_t found;
//             while (std::getline(monFichier, ligne))
//             {

//                 found = ligne.find("/");
//                 std::string user = ligne.substr(0, found);
//                 std::string mdp = ligne.substr(found + 1);
//                 lignes_mdp.push_back(mdp);
//                 lignes_id.push_back(user);
//             }
//             std::string password;
//             std::string id;
//             std::cout << "Entrez votre ID : " << std::endl;
//             std::cin >> id;

//             std::cout << "Entrez votre mdp : " << std::endl;
//             std::cin >> password;

//             for (size_t i = 0; i < lignes_id.size(); ++i)
//             {
//                 if (lignes_id[i] == id && lignes_mdp[i] == password)
//                 {
//                     return true;
//                 }
//             }
//         }
//         else
//         {
//             std::cerr << "Erreur d'ouverture du fichier." << std::endl;
//         }
//         return false;
//     }

<<<<<<< HEAD
//     ~User()
//     {
//         std::cout << "Passage destructeur" << std::endl;
//     }
// };

// class mdpGene: public User{
// private:
//     mdpGene(const std::char _capital_letter,const std::char _letter , unsigned int _int, const std::string _special):
//     User(_id_user,_passWord){
//     this->model = _model;
//     }
//     void wipers_on(void);
//     void wipers_off(void);
//     private:
//     std::string model;
// };
=======
    ~User()
    {
        std::cout << "Aurevoir"<< this->id_user << std::endl;
    }
};

class passwordManageur : private User
{
private:
    std::string Majuscule = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    std::string Minuscule = "azertyuiopqsdfghjklmwxcvbn";
    std::string Speciale = ",?;.:/!%^$*-/+";
    std::string nombre="0123456789";
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
bool verification(std::string _motdepasse){
    for (char caractere : _motdepasse) {
        if (Majuscule.find(caractere) >=1) {
            contientMajuscule = true;
        } else if (Minuscule.find(caractere)>=1) {
            contientMinuscule = true;
        } else if (Speciale.find(caractere) >=1) {
            contientSpecial = true;
        }else if(nombre.find(caractere)>=1){
            contientNombre=true;
        }
    }
    if (contientMajuscule==true && contientMinuscule==true && contientSpecial==true)
    {
        return true;
    }
    return false;
}
void generation(){
    
    std::cout<< "Combien de Nombre voulez vous : ";
    std::cin>>this->choixNombre;
    std::cout<<std::endl;
    std::cout<< "Combien de Majuscule voulez vous : ";
    std::cin>>this->choixMaj;
    std::cout<<std::endl;
    std::cout<< "Combien de Minuscule voulez vous : ";
    std::cin>>this->choixMin;
    std::cout<<std::endl;
    std::cout<< "Combien de caractere speciale voulez vous : ";
    std::cin>>this->choixSpe;
    std::cout<<std::endl;
    for( int i = 0; i < this->choixNombre; i++)
    {
        int index = rand() % nombre.size();
        motdepasse += nombre[index];
    }
    for (int i = 0; i < this->choixMaj; i++)
    {
        int index = rand() % Majuscule.size();
        motdepasse +=Majuscule[index];
    }
    for (int i = 0; i < this->choixMin; i++)
    {
        int index = rand() % Minuscule.size();
        motdepasse+=Minuscule[index];
    }
    for (int i = 0; i < this->choixSpe; i++)
    {
        int index = rand() % Minuscule.size();
        motdepasse+=Speciale[index];
    }
    std::cout<<"Votre mot de passe est "<<motdepasse<<std::endl;
}

};

int main(int /* argc */, char const * /* argv */[])
{
    User user("", "");
    std::string nom_fichier = "users.txt";
>>>>>>> 634f8924d6e84bdaac38999c2fae188d29178e22

// int main(int /* argc */, char const * /* argv */[])
// {
//     User user("", "");
//     std::string nom_fichier = "users.txt";

<<<<<<< HEAD
//     int cas;

//     while (cas != 3)
//     {
//         std::cout << "*************************************************************************************************************************" << std::endl;
//         std::cout << " 1. Inscription" << std::endl;
//         std::cout << " 2. Connexion" << std::endl;
//         std::cout << " 3. Quitter" << std::endl;
//         std::cout << "                                              Quelle choix voulez-vous faire :   " << std::endl;
//         std::cin >> cas;
//         switch (cas)
//         {
//         case 1:
//             user.new_user(nom_fichier);
//             break;
//         case 2:
//             bool identification_result = user.user_identification();
//             if (identification_result)
//             {
//                 std::cout << "Identification reussie !" << std::endl;


//             }
//             else
//             {
//                 std::cerr << "Erreur d'identification. Veuillez reessayer." << std::endl;
                
//             }
//             break;
//         /*default:
//             std::cout << "Choix invalide" << std::endl;*/
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <cstdlib>
#include <ctime>


char generateRandomLetter(int i,std::string lettre) {
  //std::srand(time(NULL));

  int indexAleatoire = rand() % lettre.length();
  int j=0;
  while  (j<i) {
    j++;
    return lettre[indexAleatoire];
  }
}

int main() {
  std::string lettre = "azertyuiop";
  int i;
  std::cout<<"combien?"<<std::endl;
  std::cin>>i;
  std::cout << "Lettre aleatoire : " << generateRandomLetter(i,lettre) << std::endl;

  return 0;
}
=======
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
>>>>>>> 634f8924d6e84bdaac38999c2fae188d29178e22
