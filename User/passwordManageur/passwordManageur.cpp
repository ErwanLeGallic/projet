#include "passwordManageur.hpp"

passwordManageur::passwordManageur(std::string _id_user, std::string _passWord, std::string _site) : User(_id_user, _passWord), site(_site){}


void passwordManageur::new_user(std::string nomFichier) 
    {
        std::string ligne;
        int cas2;
        nomFichier = this->id_user + ".txt";//on cree un fichier propre à chaque user qui sera l'equivalent de sa base de donnee
        while (cas2 != 3)
        {
            printf("\e[1;1H\e[2J");//permet de clean le terminal
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
                printf("\e[1;1H\e[2J");//permet de clean le terminal
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
                    //on fait choisir un char aleatoire avec la fonction rand()
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

                    //on fait melanger le password car pour l'instant ils sont dans l'ordre des attributs
                    std::shuffle(motdepasse.begin(), motdepasse.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
                    std::cout << "Votre mot de passe est : " << motdepasse << std::endl<< std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));//Delay de 5 seconde
                    fichier_ecriture << this->site;
                    fichier_ecriture << "/" << motdepasse << std::endl;
                    std::cout << this->id_user << " Le site : " << site << " a bien ete ajoute." << std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(5));//Delay de 5 seconde
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
                printf("\e[1;1H\e[2J");//permet de clean le terminal
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
                        if (site_in_file == this->site)//on confirme bien que le site demandé par l'utilisateur est bien le site qui nous interesse pour avoir le mot de passe
                        {
                            std::string mot_de_passe = ligne.substr(pos + 1);
                            std::cout << "Site : " << site_in_file << ", Mot de passe : " << mot_de_passe << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(5));//Delay de 5 seconde
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