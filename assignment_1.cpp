    #include <iostream>
    #include <time.h>
    using namespace std;

    int main() {
        bool dbg = false;

        srand(42);

        const int currentYear = 2022;
        const int currentMonth = 9;
        const int currentDay = 21;
 
        const int calYear = 1901;
        const int calMonth = 1;
        const int calDay = 1;

        const int lJan = 31;
        const int lFeb = 28;
        const int lMar = 31;
        const int lApr = 30;
        const int lMay = 31;
        const int lJun = 30;
        const int lJul = 31;
        const int lAug = 31;
        const int lSep = 30;
        const int lOct = 31;
        const int lNov = 30;

        int calNum = calYear*365 + calYear/4 - calYear/100 + calYear/400
                   + calDay;

        if (calMonth == 2) {
            calNum = calNum + lJan;
        }
        if (calMonth == 3) {
            calNum = calNum + lJan + lFeb;
        }
        if (calMonth == 4) {
            calNum = calNum + lJan + lFeb + lMar;
        }
        if (calMonth == 5) {
            calNum = calNum + lJan + lFeb + lMar + lApr;
        }
        if (calMonth == 6) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay;
        }
        if (calMonth == 7) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun;
        }
        if (calMonth == 8) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun + lJul;
        }
        if (calMonth == 9) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun + lJul
                   + lAug;
        }
        if (calMonth == 10) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun + lJul
                   + lAug + lSep;
        }
        if (calMonth == 11) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun + lJul
            + lAug + lSep + lOct;
        }
        if (calMonth == 12) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun + lJul
                   + lAug + lSep + lOct + lNov;
        }

        int calcDay;

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
        
        cout << "Beste gebruiker, u heeft zich aangemeld als student voor een b"
             << "eta-studie bij onze universiteit." << endl << "Voordat u toege"
             << "laten kunt worden, moeten wij enkele vragen aan u stellen om t"
             << "e verifieren of u hiervoor geschikt bent." << endl;
        //Hier begint de code voor de invoer en verificatie van de leeftijd van
        //de gebruiker.
        cout << "Om verder te gaan, voert uw geboortejaar in: ";
        cin >> year;
        if ( year > currentYear ) {
            cout << "Ben jij een tijdreiziger? Kan je dan de antwoorden voor"
            << " het tentamen Progammeermethoden 2022-2023 meenemen?" << endl;
            return 1;
        }//Uitsluiting van ongeldige jaartallen boven de huidige.
        else if ( year < 0 ) {
            cout << "Esne viator per tempus? Me contactum!" << endl;
            return 1;
        }//Vertaling: Ben jij een tijdreiziger? Neem contact op met mij! Latijn
        if (( currentYear - year < 10 ) || ( currentYear - year ) > 101 ) {
            ageMonths = 12 * ( currentYear - year );
            allowedEntry = false;
        }//Verificatie van geboortejaar, 10 en 101 jarige worden doorgelaten
        else {
            cout << "Voer uw geboortemaand in ( 1: Januari, 2: Februari, 3: Maa"
                 << "rt, 4: April, etc. ): ";
            cin >> month;
            if ( month < 1 || month > 12 ) {
                cout << "Deze maand bestaat niet!" << endl;
                return 1;
            }
            ageMonths = 12 * ( currentYear - year ) + ( currentMonth - month );
            if ((( currentYear - year == 10 ) && ( month > currentMonth )) 
                || (( currentYear - year == 101 )
                && ( month < currentMonth ))) {
                allowedEntry = false;
            }//verificatie van geboortemaand, 10 en 101 jarige worden
             //doorgelaten als ze in dezelfde maand jarig zijn.
            else {
                cout << "Voer uw geboortedag in: ";
                cin >> day;
                if ( day < 1 || (day > lJan && ( month == 1 || month == 3 
                    || month == 5 || month == 7 || month == 8 || month == 10
                    || month == 12 )) || ( day > lApr && ( month == 4
                    || month == 6 || month == 9 || month == 11 ))
                    || (( day > lFeb+1 && month == 2 && (( year % 4 == 0 
                    && year % 100 != 0 ) || year % 400 == 0))) || ( day > lFeb
                    && month == 2 && (( year % 4 != 0 || year % 100 == 0 )
                    && year % 400 != 0))) {
                    cout << "Deze dag bestaat niet!" << endl;
                    return 1;
                }//voor uitsluiting van niet bestaande dagen
                 //inclusief schikkeljaren.
                if ( day > currentDay ) {
                    ageMonths--;
                }//wanneer gebruiker later in de maand geboren is, leeftijd =
                 //maanden - 1.
                if (( currentYear - year == 10 ) && ( month == currentMonth )
                    && ( day > currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 10 jarige, geweigerd wanneer ze
                 //later in de maand jarig zijn.
                if (( currentYear - year == 101 ) && ( month == currentMonth )
                    && ( day < currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 101 jarige, geweigerd wanneer ze
                 //eerder in de maand jarig zijn.
            }
        }
        //Printen van leeftijd in maanden en jaren aan de gebruiker
        cout << "U bent " << ageMonths << " maanden oud, dit staat" 
             << " gelijk aan " << ageMonths / 12 << " jaar en " 
             << ageMonths % 12 << " maanden." << endl;

        if ( month == currentMonth && day == currentDay ) {
            cout << "Gefeliciteerd, met uw verjaardag!" << endl;
        }//Felicitaties voor de jarige

        if ( !allowedEntry ) {
            cout << "Helaas, u voldoet niet aan de leeftijdseisen van de univer"
                 << "siteit." << endl;
            return 1;
        }//Afwijzing van de gebruiker.
        else {
            if ( month == 1 ) {
                calcDay = year * 365 + day;
            }
            if ( month == 2 ) {
                calcDay = year * 365 + lJan + day;
            }
            if ( month == 3 ) {
                calcDay = year * 365 + lJan + lFeb + day;
            }
            if ( month == 4 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + day;
            }
            if ( month == 5 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + day;
            }
            if ( month == 6 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + day;
            }
            if ( month == 7 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + day;
            }
            if ( month == 8 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + lJul + day;
            }
            if ( month == 9 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + lJul + lAug + day;
            }
            if ( month == 10 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + lJul + lAug + lSep + day;
            }
            if ( month == 11 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + lJul + lAug + lSep + lOct + day;
            }
            if ( month == 12 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr + lMay + lJun
                        + lJul + lAug + lSep + lOct + lNov + day;
            }//Hier berekent is het aantal dagen vanaf jaar 0 tot dag van
             //de gebruiker, excl. schrikkels
            calcDay = calcDay + year/4 - year/100 + year/400; //berekening van
                                                              //schrikkeldagen
            if (( calcDay - calNum ) % 7 == 0) {
               birthDay = 'd';
               birthDay2 = 'i';
            }
            if (( calcDay - calNum ) % 7 == 1) {
               birthDay = 'w';
            }
            if (( calcDay - calNum ) % 7 == 2) {
               birthDay = 'd';
               birthDay2 = 'o';
            }
            if (( calcDay - calNum ) % 7 == 3) {
               birthDay = 'v';
            }
            if (( calcDay - calNum ) % 7 == 4) {
               birthDay = 'z';
               birthDay2 = 'a';
            }
            if (( calcDay - calNum ) % 7 == 5) {
               birthDay = 'z';
               birthDay2 = 'o';
            }
            if (( calcDay - calNum ) % 7 == 6) {
               birthDay = 'm';
            }//besluit op welke dag de gebruiker geboren is.
             //zie bovenaan voor uitleg calNum en verslag voor de formules.
            cout << "Vul de eerste letter in van de dag waarop u geboren bent:"
                 << " ";
            cin >> weekDay;
            if ( weekDay == 'd' || weekDay == 'z' ) {
                cout << "Vul ook de tweede letter van de dag in: ";
                cin >> weekDay2;
                if ( weekDay2 == birthDay2 ) {
                    cout << "Correct! U krijgt nu een aantal vragen om te kijke"
                         << "n of u past bij onze studie." << endl;
                }
                else {
                    cout << "Dat is incorrect. Leer eerst uzelf kennen zodat u " 
                         << "met zekerheid aan uw studie kan beginnen." << endl;
                    return 1;                    
                }
            }
            else if ( weekDay == birthDay ) {
                cout << "Correct! U krijgt nu een aantal vragen om te kijken of"
                     << " u past bij onze studie." << endl;
            }
            else {
                cout << "Dat is incorrect. Leer eerst uzelf kennen zodat u " 
                     << "met zekerheid aan uw studie kan beginnen." << endl;
                return 1;
            }
            cout << "Je bent geboren op: " << birthDay << birthDay2 << endl;
        }//Berekening en check van de geboortedag.

        //Hier beginnen de vragen over de temperatuur.
        bool Q1 = true;
        bool Q2 = true;
        int C;
        C = ( rand() % 159 ) - 39;
        float F = ( 9 * C / 5 )+32;
        int roundF;
        if ( (int) F >= F - 0,5 ) {
            roundF = F;
        }
        else {
            roundF = F+1;
        }
        int rounddF;
        int dF = F*100;
        if ((int) dF >= dF - 0,5) {
            rounddF = dF;
        }
        else {
            rounddF = dF + 1;
        }
        float ddF = rounddF / 100;
        int x;
        cout << "Hoeveel graden Fahrenheit staat gelijk aan " << C
             << " graden Celsius? Type een geheel getal, toets daarna ENTER. "
             << endl;
        cin >> x;
        if (( x < roundF-1 ) || ( x > roundF+1 )) {
            Q1 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }
        cout << ddF << " is het goede antwoord." << endl;
        float W;
        W = ( rand() % 161 ) - 40;
        float S;
        int roundS;
        S = ( W - 32 ) * 5 / 9;
        if ((int) S >= S - 0,5 ) {
            roundS = S;
        }
        else {
            roundS = S + 1;
        }
        int rounddS;
        int dS = S*100;
        if ((int) dS >= dS - 0,5) {
            rounddS = dS;
        }
        else {
            rounddS = dS + 1;
        }
        int ddS = rounddS / 100;
        int Z;
        cout << "Hoeveel graden Celsius staat gelijk aan " << W
             << " graden Fahrenheit? Typ een geheel getal,"
             << " toets daarna ENTER."
             << endl;
        cin >> Z;
        if ((Z < roundS-1) || (Z > roundS+1)) {
            Q2 = false;
            cout << "Oeps!" << endl;
        }
        cout << ddS << " is het goede antwoord." << endl;

        if (!Q1 && !Q2) {
            cout << "Uw antwoorden wijken te veel af van de juiste antwoorden."
                 <<" Helaas bent u niet geschikt voor een beta-studie."
                 << endl;
        }
        else {
            cout << "Graag zien wij u volgend jaar terug bij een van de bèta"
                 <<" studies aan de universiteit van Leiden." << endl;
            return 1; 
        }
        return 0;
    }//main