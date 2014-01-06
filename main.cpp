#include <iostream>
#include "Morse.hpp"

using namespace std;

const string theString = "Monsieur Jack vous dactylographiez bien mieux que votre ami Wolf";

// Use it for try encrypt / decrypt
int main()
{
    string a = theString;
    Morse::encrypt(a);
    cout << a << std::endl;
    Morse::decrypt(a);
    cout << a << std::endl;
    return 0;
}

// Use it for try with files
int main()
{
    Morse::saveCodeInFile("code.morse", theString);
    cout << Morse::loadTextFromFile("code.morse") << endl;
    return 0;
}
