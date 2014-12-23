// Programm zur Generierung deines Ninja-Namens.
// Das Programm nimmt einen Vornamen entgegen und generiert daraus einen Ninja-Namen.
// Dazu werden die Buchstaben des Vornamens der Reihe nach durch japanische Silben ersetzt.

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

bool istValid(char name[])
{
    string tmp = name;

    int charsize = tmp.size();

    for (int i = 0; i < charsize; i++)
    {
        name[i] = toupper(name[i]);
    }

    for (int i = 0; i <charsize; i++)
    {
        if (name[i] < 65 || name[i] > 122)
        {
            return false;
        }
    }
    return true;
}

string umwandeln(char name[])
{
    string ergebnis = name;

    int charsize = ergebnis.size();

    ergebnis = ""; // Der Name muss wieder gelöscht werden, sonst werden die Silben einfach drangehängt.

    for (int i = 0; i < charsize; i++)
    {
        name[i] = toupper(name[i]);
    }

    string silben[] = { "KA", "ZU", "MI", "TE", "KU", "LU", "JI", "RI", "KI", "ZU", "ME", "TA", "RIN", "TO", "MO", "NO", "KE", "SHI", "ARI", "CHI", "DO", "RU", "MEI", "NA", "FU", "Zi" };

    for (int i = 0; i < charsize; i++)
    {
        ergebnis.append(silben[name[i]-65]);
    }

    return ergebnis;
}

string zurueckwandeln(string name)
{
    string silben[] = { "KA", "ZU", "MI", "TE", "KU", "LU", "JI", "RI", "KI", "ZU", "ME", "TA", "RIN", "TO", "MO", "NO", "KE", "SHI", "ARI", "CHI", "DO", "RU", "MEI", "NA", "FU", "Zi" };

    string ergebnis = "";
    string tmp;

    bool gefunden = false;

    unsigned int it = 0; // substr erlaubt die Verwendung von Iteratoren nicht.

    while (it < name.size())
    {
        tmp = name.substr(it, 2);
        int next = 2;
        while (gefunden == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (tmp.compare(silben[i]) == 0)
                {
                    stringstream ss;
                    string tmp2;
                    ss << char (toascii(i+65));
                    ss >> tmp2;
                    ergebnis.append(tmp2);
                    it = it + next;
                    gefunden = true;
                    break;
                }
            }
            if (next == 3)
            {
                throw "Fehlerhafte Eingabe.";
            }
            tmp = name.substr(it, 3);
            next = 3;
        }
        gefunden = false;
    }
    return ergebnis;
}

int main()
{
    bool menu = true;

    while(menu)
    {
        cout << "Menue: \n";
        cout << "1 - Ninja-Name aus Vorname generieren.\n";
        cout << "2 - Vorname aus Ninja-Name zurueckgenerieren. \n";
        cout << "3 - Programm beenden.\n";

        string test;
        getline(cin, test);

        if (test.compare("1") == 0)
        {
            char vorname[256];
            do
            {
                cout << "Bitte deinen Vorname eingeben: ";
                cin.getline(vorname, 256);
            } while (istValid(vorname) == false);

            string genninja = umwandeln(vorname);

            cout << genninja << endl;
        }

        else if (test.compare("2") == 0)
        {
            char ninjaname[256];
            do
            {
                cout << "Bitte deinen Ninja-Namen eingeben: ";
                cin.getline(ninjaname, 256);
            } while (istValid(ninjaname) == false);

            string zwschspchr = ninjaname;

            try
            {
                string genvor = zurueckwandeln(zwschspchr);
                cout << genvor << endl;
            } catch (const char * msg) { cerr << msg << endl; }
        }

        else if (test.compare("3") == 0)
        {
            cout << "Programm wird beendet.";
            menu  = false;
        }
        else
        {
                cout << "Fehlerhafte Eingabe. Eingabe wiederholeen.";
        }
    }
    return 0;
}
