// binio.cpp - Binary Input and Output with Integers

#include <fstream>  
#include <iostream>

using namespace std;

const int MAX = 100; 
int buff[MAX];       

int main() {

    for (int j = 0; j < MAX; j++) 
        buff[j] = j; // (0, 1, 2, ...)

    
    ofstream os("edata.dat", ios::binary);
    if (!os) {
        cerr << "Error opening file for writing\n";
        return 1;
    }
    
    
    os.write(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    os.close(); 

    
    for (int j = 0; j < MAX; j++)
        buff[j] = 0;

    
    ifstream is("edata.dat", ios::binary);
    if (!is) {
        cerr << "Error opening file for reading\n";
        return 1;
    }
    
    
    is.read(reinterpret_cast<char*>(buff), MAX * sizeof(int));
    is.close();

    
    for (int j = 0; j < MAX; j++) {
        if (buff[j] != j) {
            cerr << "Data is incorrect\n";
            return 1;
        }
    }

    cout << "Data is correct\n";
    return 0;
}
