#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
    setlocale(LC_ALL, "Rus");
    int N = 0, N1, N2;
    cin >> N1 >> N2;
    ifstream inp("F1.txt");
    ofstream out("F2.txt");

    string line;
    while (getline(inp, line)) {
        ++N;
        if ((N > N1 && N < N2) && line[0] == 'a') {
            out << line << endl;
        }
        if ((N >= N2 + 3) && line[0] == 'a') {
            out << line << endl;
        }
    }
    inp.close();
    out.close();

    ifstream f2("F2.txt");
    string lastline;
    int wordInLastline = 0;
    int wordCount = 0; 

    while (getline(f2, lastline)) {
        char prevChar = ' ';
        for (char currentChar : lastline) {
            if (prevChar == ' ' && currentChar != ' ') {
                ++wordCount;
            }
            prevChar = currentChar;
        }
        if (f2.peek() != EOF) { 
            wordInLastline += wordCount; 
            wordCount = 0;
        }
    }

    cout << "Количество слов в последней строке файла F2: " << wordCount << endl;

    f2.close();

}


