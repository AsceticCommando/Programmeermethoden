    #include<iostream>
    #include<fstream>
    #include<string>
    using namespace std;

    void createFile() {
        ifstream input ("input.txt"); // denk aan <fstream>
        ofstream output ("output.txt");
        char kar = input.get ( );
        while ( !input.eof ( ) ) {
            output.put (kar); // of uitvoer << kar;
            kar = input.get ( );
        }//while
        input.close ( );
        output.close ( );
    }

    int main() {
        return 0;
    }