// ichar.cpp // file input with characters
#include <fstream> //for file functions
#include <iostream>

using namespace std;

int main()
{
    char ch;
    ifstream infile("TEST.TXT");
    while (infile)
    {
        infile.get(ch);
        cout << ch;
    }

    cout << endl;
    return 0;
}