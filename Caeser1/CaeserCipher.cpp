#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// map<char, int> alphabets = {
//     {'A', 0},
//     {'B', 1},
//     {'C', 2},
//     {'D', 3},
//     {'E', 4},
//     {'F', 5},
//     {'G', 6},
//     {'H', 7},
//     {'I', 8},
//     {'J', 9},
//     {'K', 10},
//     {'L', 11},
//     {'M', 12},
//     {'N', 13},
//     {'O', 14},
//     {'P', 15},
//     {'Q', 16},
//     {'R', 17},
//     {'S', 18},
//     {'T', 19},
//     {'U', 20},
//     {'V', 21},
//     {'W', 22},
//     {'X', 23},
//     {'Y', 24},
//     {'Z', 25},
//     {'?', 26},
//     {',', 27},
//     {'.', 28},
//     {':', 29},
//     {'&', 30},
//     {'?', 31},
//     {'"', 32},
//     {'/', 33},
//     {' ', 34},
// };

map<char, int> alphabets;

void GenerateAlphabets()
{
    int i = 0;
    for (char c{' '}; c <= '~'; c++)
    {
        alphabets.insert({c, i});
        i++;
    }
}

int mod(int value, int limit)
{

    int remainder = value / limit;

    int quot = remainder * limit;

    int answer = value - quot;

    return answer < 0 ? limit + answer : answer;
}

string cipher(string text, int key)
{
    string encrypted;

    for (int i = 0; i < text.length(); i++)
    {

        for (auto element : alphabets)
        {
            if (element.first == text[i])
            {
                int newValue = mod(element.second + key, alphabets.size());
                for (auto letter : alphabets)
                {
                    if (letter.second == newValue)
                    {
                        encrypted += letter.first;
                    }
                }
            }
        }
    }
    return encrypted;
}

string decrypt(string text, int key)
{
    string encrypted;

    for (int i = 0; i < text.length(); i++)
    {

        for (auto element : alphabets)
        {
            if (element.first == text[i])
            {
                int newValue = mod(element.second - key, alphabets.size());
                for (auto letter : alphabets)
                {
                    if (letter.second == newValue)
                    {
                        encrypted += letter.first;
                    }
                }
            }
        }
    }
    return encrypted;
}

bool isWordInDictionary(string word){
    bool value = false;

    std::ifstream inFile("./words.txt");


   if (! inFile) {
        cout << "Could not open world list.";
        cout << endl;
        return false;
}
    std::stringstream strStream;
    strStream << inFile.rdbuf();       // read the file
    std::string str = strStream.str(); // str holds the content of the file

    // std::cout << str << "\n"; // you can do anything with the string!!!
    cout << "Reading the file...\n";
    cout << str << std::endl;

    return value;
}

void brute_force(string encrypted){
    for (int i = 0; i < alphabets.size(); i++){
        cout <<  "Attempt " + to_string(i) + ": " + decrypt(encrypted, i) << std::endl;
    }
}

const int key = 3973;

int main()
{
   GenerateAlphabets();
        cout << isWordInDictionary("hello") << std::endl;
    string filename;

    cout << "Enter a file name to be encrypted and press ENTER: ";
    //eg /Users/user/Documents/Cyptography/file.txt
    cin >> filename;
    std::ifstream inFile(filename);

   if (! inFile) {
        cout << filename << " could not be opened.";
        cout << endl;
        return -1;
}
    //inFile.open(filename); // open the input file

    std::stringstream strStream;
    strStream << inFile.rdbuf();       // read the file
    std::string str = strStream.str(); // str holds the content of the file

    // std::cout << str << "\n"; // you can do anything with the string!!!
    cout << "Reading the file...\n";
    cout << str << std::endl;

    inFile.close();

    string encrypted = cipher(str, key);

    cout << encrypted << endl;

    //cout << decrypt(encrypted, key) << endl;

    brute_force(encrypted);



    return 0;
}
