#include "Morse.hpp"

using namespace std;

string Morse::decode(string code)
{
    string str;
    stringstream stream(code);
    string input;
    while(getline(stream, input, '/'))
    {
        str.append(toNormal(input));
    }
    return str;
}

string Morse::encode(string code)
{
    string str;
    for (unsigned int i = 0; i < code.size() ; ++i)
    {
        code[i] = toupper(code[i]);
        str.append(toMorse(code[i]));
    }
    return str;
}

void Morse::decrypt(string& code)
{
    code = decode(code);
}

void Morse::encrypt(string& code)
{
    code = encode(code);
}

string Morse::toMorse(char normal)
{
    if(normal == 'A') { return string(".-/"); }
    if(normal == 'B') { return string("-.../"); }
    if(normal == 'C') { return string("-.-./"); }
    if(normal == 'D') { return string("-../"); }
    if(normal == 'E') { return string("./"); }
    if(normal == 'F') { return string("..-./"); }
    if(normal == 'G') { return string("--./"); }
    if(normal == 'H') { return string("..../"); }
    if(normal == 'I') { return string("../"); }
    if(normal == 'J') { return string(".---/"); }
    if(normal == 'K') { return string("-.-/"); }
    if(normal == 'L') { return string(".-../"); }
    if(normal == 'M') { return string("--/"); }
    if(normal == 'N') { return string("-./"); }
    if(normal == 'O') { return string("---/"); }
    if(normal == 'P') { return string(".--./"); }
    if(normal == 'Q') { return string("--.-/"); }
    if(normal == 'R') { return string(".-./"); }
    if(normal == 'S') { return string(".../"); }
    if(normal == 'T') { return string("-/"); }
    if(normal == 'U') { return string("..-/"); }
    if(normal == 'V') { return string("...-/"); }
    if(normal == 'W') { return string(".--/"); }
    if(normal == 'X') { return string("-..-/"); }
    if(normal == 'Y') { return string("-.--/"); }
    if(normal == 'Z') { return string("--../"); }
    if(normal == '1') { return string(".----/"); }
    if(normal == '2') { return string("..---/"); }
    if(normal == '3') { return string("...--/"); }
    if(normal == '4') { return string("....-/"); }
    if(normal == '5') { return string("...../"); }
    if(normal == '6') { return string("-..../"); }
    if(normal == '7') { return string("--.../"); }
    if(normal == '8') { return string("---../"); }
    if(normal == '9') { return string("----./"); }
    if(normal == '0') { return string("-----/"); }
    return string("/");
}

string Morse::toNormal(string morse)
{
    if(morse == ".-") { return string("A"); }
    if(morse == "-...") { return string("B"); }
    if(morse == "-.-.") { return string("C"); }
    if(morse == "-..") { return string("D"); }
    if(morse == ".") { return string("E"); }
    if(morse == "..-.") { return string("F"); }
    if(morse == "--.") { return string("G"); }
    if(morse == "....") { return string("H"); }
    if(morse == "..") { return string("I"); }
    if(morse == ".---") { return string("J"); }
    if(morse == "-.-") { return string("K"); }
    if(morse == ".-..") { return string("L"); }
    if(morse == "--") { return string("M"); }
    if(morse == "-.") { return string("N"); }
    if(morse == "---") { return string("O"); }
    if(morse == ".--.") { return string("P"); }
    if(morse == "--.-") { return string("Q"); }
    if(morse == ".-.") { return string("R"); }
    if(morse == "...") { return string("S"); }
    if(morse == "-") { return string("T"); }
    if(morse == "..-") { return string("U"); }
    if(morse == "...-") { return string("V"); }
    if(morse == ".--") { return string("W"); }
    if(morse == "-..-") { return string("X"); }
    if(morse == "-.--") { return string("Y"); }
    if(morse == "--..") { return string("Z"); }
    if(morse == ".----") { return string("1"); }
    if(morse == "..---") { return string("2"); }
    if(morse == "...--") { return string("3"); }
    if(morse == "....-") { return string("4"); }
    if(morse == ".....") { return string("5"); }
    if(morse == "-....") { return string("6"); }
    if(morse == "--...") { return string("7"); }
    if(morse == "---..") { return string("8"); }
    if(morse == "----.") { return string("9"); }
    if(morse == "-----") { return string("0"); }
    return string(" ");
}

void Morse::saveCodeInFile(string path, string toCode)
{
    saveInFile(path,encode(toCode));
}

string Morse::loadTextFromFile(string path)
{
    return decode(loadFromFile(path));
}

void Morse::saveInFile(string path, string str)
{
    ofstream stream(path.c_str());
    if(stream)
    {
        stream << str;
        stream.close();
    }
}

string Morse::loadFromFile(string path)
{
    string str;
    ifstream stream(path.c_str());
    if(stream)
    {
        getline(stream,str);
        stream.close();
    }
    return str;
}
