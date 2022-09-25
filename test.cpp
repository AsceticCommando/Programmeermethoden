    #include<iostream>
    using namespace std;

    int main() {
        srand(7);
        bool dbg = true;
        bool Q1 = true;
        bool Q2 = true;

        int x;
        int y;

        int C1 = ( rand() % 159 ) - 39;
        float F1 = 9 * (float) C1 / 7 + 32;
        if(dbg) cout << F1 << endl;
        float tF1 = F1 * 100;
        if(dbg) cout << tF1 << endl;
        if ((int) tF1 < tF1 - 0.5 ) {
            tF1++;
        }
        if(dbg) cout << tF1 << endl;;
        float dF1 = (int) tF1;
        if(dbg) cout << dF1 << endl;
        dF1 = dF1 / 100;
        if(dbg) cout << dF1 << endl;

        int F2 = ( rand() % 159 ) - 39;
        float C2 = ( (float) F2 - 32 ) * 5 / 9;
        float tC2 = C2 * 100;
        if ((int) tC2 < tC2 - 5 ) {
            tC2++;
        }
        float dC2 = (int) tC2;
        dC2 = dC2 / 100;
        cout << "Hoeveel graden Fahrenheit staat gelijk aan " << C1
             << " graden Celsius? Typ een geheel getal, toets daarna ENTER. "
             << endl;
        cin >> x;

        if (( x < dF1 - 1 ) || ( x > dF1 + 1 )) {
            Q1 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }
        cout << dF1 << " is het goede antwoord." << endl;

        cout << "Hoeveel graden Celsius staat gelijk aan " << F2
             << " graden Fahrenheit? Typ een geheel getal, toets daarna ENTER. "
             << endl;
        cin >> y;

        if (( y < dC2 - 1 ) || ( y > dC2 + 1 )) {
            Q2 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }
        cout << dC2 << " is het goede antwoord." << endl;

        return 0;
    }       
        