
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){




    ifstream file;
    file.open(argv[1]);
    if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    cout << "Reading from file: " << argv[1] << endl;;
    string line;
    char arr[10];
    int j=0;
    while (getline(file, line) && j < 10) {
    	cout << line << "ENDLINE" <<endl;
    }
}