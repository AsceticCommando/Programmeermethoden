    #include<iostream>
    #include<string>
    #include<fstream>
    using namespace std;

    void createInfoblock() {
        cout << "Hier is een beetje info" << endl;
    }

    int addNumbers(int x, int y) {
        return x + y;
    }

    void addDivision(int x1, int x2, int y1, int y2, int & z1, int & z2) {
        z1 = (x1*y2) + (y1*x2);
        z2 = x2*y2;
    }

    double power(double x, int y) {
        double answer = x;
        for(int i = 1; i < y; i++) {
            answer = answer*x;
        }
        return answer;
    }

    int countInvertNumbers(int n) {
        int amount = 0;
        while(n > 0){
            cout << n % 10 << endl;
            n = n / 10;
            amount++;
        }
        return amount;
    }

    int main() {
        int n1;
        int d1;
        int n2;
        int d2;
        int n3;
        int d3;
        double x;
        int y;
        double z;
        int n;

        createInfoblock();

        cout << "Vul een breuk som in als volgt ('noemer1' 'deler 1' 'noemer 2' 'deler 2') zonder aanhalingsteken: ";
        cin >> n1;
        cin >> d1;
        cin >> n2;
        cin >> d2;
        addDivision(n1, d1, n2, d2, n3, d3);
        cout << "Het antwoord is: " << n3 << "/" << d3 << endl;

        cout << "Geef nu een machtsom op als volgt ('getal' 'macht') waarbij de macht een heel getal is: ";
        cin >> x;
        cin >> y;
        z = power(x, y);
        cout << "Het antwoord is: " << z << endl;
        
        cout << "Voer een geheel getal in:";
        cin >> n;
        cout << "Dit is achterstevoren: " << countInvertNumbers(n) << endl;
        return 0;
    }//main