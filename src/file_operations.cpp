#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void writeFile(string filename, string toWrite)
{
    ofstream file(filename, ios::app);
    if (file.is_open())
    {
        file << toWrite;
        file.close();
    }
    else cout << "Unable to write to file.";
}

void readFile(string filename)
{
    ifstream file(filename);
    string line;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << '\n';
        }
        file.close();
    }
    else cout << "Unable to open file.";
}
