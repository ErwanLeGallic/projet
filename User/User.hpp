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
    std::string id_user = "";
    std::string passWord = "";
    bool identification = false;
    virtual void new_user(std::string fichierTXT);
    bool user_identification(void);
    ~User();
    User(std::string _id_user, std::string _passWord);
};