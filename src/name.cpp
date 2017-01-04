#include <string>
#include <sstream>
#include "name.h"

bool isValid(char name[])
{
    string tmp = name;

    int charsize = tmp.size();

    for (int index = 0; index < charsize; index++)
    {
    	name[index] = toupper(name[index]);
    }

    for (int index = 0; index < charsize; index++)
    {
    	if (name[index] < 65 || name[index] > 122)
    	{
    	   return false;
    	}
    }
    return true;
}

string morph(char name[])
{
    string result = name;
    int charsize = result.size();

    result = ""; // The name must be deleted, otherwise the syllables will get appended.

    for (int index = 0; index < charsize; index++)
    {
    	name[index] = toupper(name[index]);
    }

    string syllables[] =
    {
    "KA", "ZU", "MI", "TE", "KU",
    "LU", "JI", "RI", "KI", "ZU",
    "ME", "TA", "RIN", "TO", "MO",
    "NO", "KE", "SHI", "ARI", "CHI",
    "DO", "RU", "MEI", "NA", "FU", "Zi"
    };

    for (int index = 0; index < charsize; index++)
    {
    	result.append(syllables[name[index]-65]);
    }
    return result;
}

string demorph(string name)
{
    string syllables[] =
    {
    "KA", "ZU", "MI", "TE", "KU",
    "LU", "JI", "RI", "KI", "ZU",
    "ME", "TA", "RIN", "TO", "MO",
    "NO", "KE", "SHI", "ARI", "CHI",
    "DO", "RU", "MEI", "NA", "FU", "Zi"
    };

    string result = "";
    string tmp;

    bool found = false;
    unsigned int it = 0; // subtr doesn't support iterators.

    while (it < name.size())
    {
    	tmp = name.substr(it, 2);
    	int next = 2;
    	while (found == false)
    	{
    	   for (int index = 0; index < 26; index++)
    	   {
    	   	if (tmp.compare(syllables[index]) == 0)
    	   	{
    	   	    stringstream ss;
    	   	    string tmp2;
    	   	    ss << char (toascii(index+65));
    	   	    ss >> tmp2;
    	   	    result.append(tmp2);
    	   	    it = it + next;
    	   	    found = true;
    	   	    break;
    	   	}
    	   }
    	   if (next == 3)
    	   {
    	   	throw "Invalid input.";
    	   }
    	   tmp = name.substr(it, 3);
    	   next = 3;
    	}
    	found = false;
    }
    return result;
}
