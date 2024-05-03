#include <iostream>
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
    //attribut
    std::string id_user = "";
    std::string passWord = "";
    bool identification = false;

    //methode

    /**
     * la methode demandera a l'utilisateur qui est dans son compte ce qu'il veut faire entre:
    1. Generer un mot de passe pour un site
    2. lire vos mots de passes
    3. Quitter

    * @param nomFichier qui est le fichier personnel de l'user : "id_user.txt"
    * @return void
    */
    virtual void new_user(std::string fichierTXT);

    /**
    *fait une identification, la methode demande à l'utilisateur d'entrer son identifiant et son mot de passe 
    *pour pouvoir avoir acces à son compte 
    * @param void
    * @return bool
    */ 
    bool user_identification(void);

    //destructeur
    ~User();
    //constructeur
    User(std::string _id_user, std::string _passWord);
};