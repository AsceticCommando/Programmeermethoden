    #include <iostream>
    #include <time.h>
    using namespace std;

    int main ( ) {
        
        srand(42);

        const int currentYear = 2022;
        const int currentMonth = 9;
        const int currentDay = 21;
 
        int day;
        int month;
        int year;
        int ageMonths;

        bool allowedEntry = true;

        char weekDay;
        char weekDay2;
        char birthDay;
        char birthDay2;

        //time_t currentDate;
        //time (&timer);

        //Hier begint de code voor de invoer en verificatie van de leeftijd van de gebruiker.
        cout << "Voer uw geboortejaar in: " << endl;
        cin >> year;
        if (( currentYear - year < 10 ) || ( currentYear - year ) > 101 ) {
            ageMonths = 12 * ( currentYear - year );
            allowedEntry = false;
        }//Verificatie van geboortejaar, 10 en 101 jarige worden doorgelaten
        else {
            cout << "Voer uw geboortemaand in ( 1: Januari, 2: Februari, 3: Maa"
                 << "rt, 4: ... ): " << endl;
            cin >> month;
            ageMonths = 12 * ( currentYear - year ) + ( currentMonth - month );
            if ((( currentYear - year == 10 ) && ( month > currentMonth )) || (( currentYear - year == 101 ) && ( month < currentMonth ))) {
                allowedEntry = false;
            }//verificatie van geboortemaand, 10 en 101 jarige worden
             //doorgelaten als ze in dezelfde maand jarig zijn.
            else {
                cout << "Voer uw geboortedag in: " << endl;
                cin >> day;
                if ( day > currentDay ) {
                    ageMonths--;
                }//wanneer gebruiker later in de maand geboren is, leeftijd maanden - 1.
                if (( currentYear - year == 10 ) && ( month == currentMonth ) && ( day > currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 10 jarige, geweigerd wanneer ze
                 //later in de maand jarig zijn.
                if (( currentYear - year == 101 ) && ( month == currentMonth ) && ( day < currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 101 jarige, geweigerd wanneer ze
                 //eerder in de maand jarig zijn.
            }
        }
        //Printen van leeftijd in maanden en jaren aan de gebruiker
        cout << "U bent " << ageMonths << " maanden oud, dit staat" 
             << " gelijk aan " << ageMonths / 12 << " jaar en " 
             << ageMonths % 12 << " maanden." << endl;

        //cout << ctime(&currentDate);

        if ( month == currentMonth && day == currentDay ) {
            cout << "Gefeliciteerd, met uw verjaardag!" << endl;
        }//Felicitaties voor de jarige

        if ( !allowedEntry ) {
            cout << "Helaas, u voldoet niet aan de leeftijdseisen van de univer"
                 << "siteit." << endl;
            return 1;
        }//Afwijzing van de geweigerde.
        else {
            cout << "Vul de eerste letter in van de dag waarop u geboren bent, "
                 << "gebruik 1 letter." << endl;
            cin >> weekDay;
            if ( weekDay == 'd' || weekDay == 'z' ){
                cout << "Vul ook de tweede letter van de dag in." << endl;
                cin >> weekDay2;
                if ( weekDay2 == birthDay2 ) {
                    cout << "Dat is incorrect." << endl;
                    return 1;
                }
                else {

                }
            }
            else if ( weekDay == birthDay ) {
                
            }
            else {
                cout << "Dat is incorrect." << endl;
                return 1;
            }
        }//Berekening en check van de geboortedag.

        //Hier beginnen de vragen over de temperatuur.
        bool Q1 = true;
        bool Q2 = true;
        int C;
        C = (rand() % 159) - 39;
        float F = (9*C/5)+32;
        int roundF;
        if ((int) F >= F - 0,5) {
            roundF = F;
        }
        else {
            roundF = F+1;
        }
        int x;
        cout << "Hoeveel graden Fahrenheit staat gelijk aan " << C <<  " graden Celsius? Type een geheel getal, toets daarna ENTER. "  << endl;
        cin >> x;
        if ((x < roundF-1) || (x > roundF+1)) {
            Q1 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }
        cout << F << " is het goede antwoord." << endl;
        float W;
        W = (rand() % 161) - 40;
        float S;
        int roundS;
        S = (W-32)*5/9;
        if ((int) S >= S - 0,5) {
            roundS = S;
        }
        else {
            roundS = S+1;
        }
        int Z;
        cout << "Hoeveel graden Celsius staat gelijk aan " << W <<  " graden Fahrenheit? Type een geheel getal, toets daarna ENTER. " << endl;
        cin >> Z;
        if ((Z < roundS-1) || (Z > roundS+1)) {
            Q2 = false;
            cout << "Oeps!" << endl;
        }
        cout << S << " is het goede antwoord." << endl;

        if (!Q1 && !Q2) {
            cout << "Uw antwoorden wijken te veel af van de juiste antwoorden. Helaas bent u niet geschrikt voor een beta-studie." << endl;
        }
        else {
            cout << "Graag zien wij u volgend jaar terug bij een van de beta studies aan de universiteit van Leiden." << endl;
            return 1; 
        }
        return 0;
    }//main