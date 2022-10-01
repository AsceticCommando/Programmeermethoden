    #include<iostream>
    #include<fstream>
    #include<string>
    using namespace std;

    int squareNumber(int x) {
        return x*x;
    }

    void createFile() {
        ifstream input ("input.txt"); // denk aan <fstream>
        ofstream output ("output.txt");
        char kar = input.get ( );
        int k = 1;
        int n = 0;
        int store = 0;
        char prev1;
        char prev2;
        int de = 0;
        while ( !input.eof ( ) ) {
            if (kar >= '0' && kar <= '9') {
                cout << kar << endl;
                store = store * 10 + (kar - '0');
            }
            else {
                cout << squareNumber(store % 10) << endl;
                output.put (kar); // of uitvoer << kar;
            }
            if (kar == '\n') {
                n++;
            }
            else {
                k++;
            }
            if (prev2 == ' ' && prev1 == 'd' && kar == 'e') {
                de++;
            }
            prev2 = prev1;
            prev1 = kar;
            kar = input.get();
        }//while
        cout << de;
        input.close();
        output.close();
    }

    int main() {
        createFile();
        return 0;
    }