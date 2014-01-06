#ifndef MORSE_HPP
#define MORSE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

class Morse
{
    public:
        static std::string decode(std::string code);
        static std::string encode(std::string code);

        static void decrypt(std::string& code);
        static void encrypt(std::string& code);

        static void saveCodeInFile(std::string path, std::string toCode);
        static std::string loadTextFromFile(std::string path);

    //private:
        static std::string toMorse(char normal);
        static std::string toNormal(std::string morse);

        static void saveInFile(std::string path, std::string str);
        static std::string loadFromFile(std::string path);
};

#endif // MORSE_HPP
