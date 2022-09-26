    //Infoblok voor programmeurs
    //Compiler:          g++.exe (Rev1, Built by MSYS2 project) 12.2.0
    //Programmeerpgave:                                              1
    //Gemaakt op:                                           26-09-2022
    //Namen:                   Vijgeboom, Thijs;       Wulffele, Lotte
    //Studentnummers:                   2648261;               3661814
    //Jaar van aankomst:                   2019;                  2022
    //Studierichting:                  Biologie;              Wiskunde
    //Gebruikte IDE:         Visual Studio Code;          Sublime Text

    #include <iostream>
    #include <time.h>
    using namespace std;

    int main() {
        srand(420);                       //Seed voor temperatuurvraag
        const int errMargin = 1;  //Foutmarge voor de temperatuurvraag

        int day;                               //Data voor geboortedag
        int month;
        int year;                                       
        int ageMonths;                           //Leeftijd in maanden

        bool allowedEntry = true;    //Toegang na leeftijdsverificatie

        const int currentYear = 2022;     //Data voor dag van toetsing
        const int currentMonth = 9;
        const int currentDay = 26;
 
        const int calYear = 1901;  //Data voor de ijking van (week)dag
        const int calMonth = 1;    //berekening
        const int calDay = 1;

        const int lJan = 31;                         //Dagen per maand
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

        int calNum = calYear*365 + calYear/4 - calYear/100
                   + calYear/400
                   + calDay;         //ijking van (week)dag berekening

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
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun
                   + lJul;
        }
        if (calMonth == 9) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun
                   + lJul + lAug;
        }
        if (calMonth == 10) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun 
                   + lJul + lAug + lSep;
        }
        if (calMonth == 11) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun 
                   + lJul + lAug + lSep + lOct;
        }
        if (calMonth == 12) {
            calNum = calNum + lJan + lFeb + lMar + lApr + lMay + lJun 
                   + lJul + lAug + lSep + lOct + lNov;
        }//Berekening van aantal dagen per maand in
         //ijking van (week)dagen

        int calcDay;        //variabele voor berekening van het aantal
                            //dagen voor stellen van de (week)dag

        char weekDay;            //Invoer van (week)dag door gebruiker
        char weekDay2;
        char birthDay;  //Opslag van (week)dag door programma berekend
        char birthDay2;

                                                            //infoblok
        cout << "+---------------------------------------------------"
             << "---+" << endl << "| Programmeermethoden; eerste prog"
             << "rammeeropgave        |" << endl << "| Gemaakt op;   "
             << "       26-09-2022                      |" << endl
             << "| Gemaakt door:      Thijs Vijgeboom en Lotte Wulffe"
             << "le |" << endl << "| Studentnummers:    2648261      " 
             << "      3661814        |" << endl << "| Jaar van aanko"
             << "mst: 2019               2022           |" << endl
             << "| Studierichting:    Biologie           Wiskunde    "
             << "   |" << endl << "+---------------------------------"
             << "---------------------+" << endl << endl << "Welkom b"
             << "ij de test voor toelating bij onze universiteit." 
             << endl << "De test bestaat uit twee delen, in het eerst"
             << "e deel vragen wij om" << endl << "uw geboortegegeven"
             << "s in te voeren om te kijken of u voldoet aan onze le"
             << "eftijdseisen." << endl << "Vervolgens krijgt u enkel"
             << "e vragen om uw affiniteit met een beta of alpha stud"
             << "ie te verhelderen." << endl << endl;
        
        //Hier begint de code voor de invoer en verificatie van de
        //leeftijd van de gebruiker.
        cout << "1) Voer eerst uw geboortejaar als volgt in (YYYY), t"
             << "oets vervolgens op ENTER: ";
        cin >> year;
        if ( year > currentYear ) {
            cout << "Ben jij een tijdreiziger? Kan je dan de antwoord"
            << "en voor het tentamen Progammeermethoden 2022-2023 mee"
            << "nemen?" << endl;
            return 1;
        }//Uitsluiting van ongeldige jaartallen boven de huidige.
        else if ( year < 0 ) {
            cout << "Esne viator per tempus? Me accede!" << endl;
            return 1;
        }//Uitsluiting jaartallen onder 0, arbitrair gekozen.
         //Vertaling: Ben jij een tijdreiziger? 
         //Neem contact op met mij! Latijn.
        if (( currentYear - year < 10 ) ||
            ( currentYear - year ) > 101 ) {
            ageMonths = 12 * ( currentYear - year );
            allowedEntry = false;
        }//Verificatie van geboortejaar, 10 en 101 jarige worden
         //doorgelaten
        else {
            cout << "2) Voer uw geboortemaand in ( 1: Januari, 2: Feb"
                 << "ruari, ... , 11: November, 12: December ), toets"
                 << " vervolgens op ENTER: ";
            cin >> month;
            if ( month < 1 || month > 12 ) {
                cout << "Deze maand staat niet in onze kalender!" 
                     << endl;
                return 1;
            }//Uitsluiting niet bestaande maanden.
            ageMonths = 12 * ( currentYear - year ) 
                      + ( currentMonth - month );
            if ((( currentYear - year == 10 ) && 
                ( month > currentMonth )) || (( currentYear - year 
                == 101 ) && ( month < currentMonth ))) {
                allowedEntry = false;
            }//verificatie van geboortemaand, 10 en 101 jarige worden
             //doorgelaten als ze in dezelfde maand jarig zijn.
            else {
                cout << "3) Voer uw geboortedag in (1, 2, ..., 31), t"
                << "oets vervolgens op ENTER: ";
                cin >> day;
                if ( day < 1 || (day > lJan && ( month == 1 || month 
                    == 3 || month == 5 || month == 7 || month == 8 ||
                    month == 10 || month == 12 )) || ( day > lApr &&
                    ( month == 4 || month == 6 || month == 9 || month
                    == 11 )) || (( day > lFeb+1 && month == 2 && 
                    (( year % 4 == 0 && year % 100 != 0 ) ||
                    year % 400 == 0))) || ( day > lFeb && month == 2 
                    && (( year % 4 != 0 || year % 100 == 0 ) && 
                    year % 400 != 0))) {
                    cout << "Deze dag staat niet in onze kalender!" 
                         << endl;
                    return 1;
                }//voor uitsluiting van niet bestaande dagen
                 //inclusief schikkeljaren.
                if ( day > currentDay ) {
                    ageMonths--;
                }//wanneer gebruiker later in de maand geboren is,
                 //leeftijd = maanden - 1.
                if (( currentYear - year == 10 ) && ( month == 
                    currentMonth ) && ( day > currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 10 jarige, geweigerd
                 //wanneer ze later in de maand jarig zijn.
                if (( currentYear - year == 101 ) && ( month == 
                    currentMonth ) && ( day < currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 101 jarige, geweigerd
                 //wanneer ze eerder in de maand jarig zijn.
            }
        }
        //Printen van leeftijd in maanden en jaren aan de gebruiker
        cout << "U bent " << ageMonths << " maanden oud, dit staat" 
             << " gelijk aan " << ageMonths / 12 << " jaar en " 
             << ageMonths % 12 << " maanden." << endl;

        if ( month == currentMonth && day == currentDay ) {
            cout << "Gefeliciteerd, met uw verjaardag!" << endl;
        }//Felicitaties voor de jarige
        
        if ( month != currentMonth && day == currentDay ) {
            cout << "Gefeliciteerd, met uw vermaanding!" << endl;
        }//Felicitaties voor de maandige

        if ( allowedEntry ) {
            cout << "U voldoet aan de leeftijdseisen voor de universi"
                 << "teit." << endl;
        }//Tekst bij voltooing van leeftijdsverificatie
        if ( !allowedEntry ) {
            cout << "Helaas, u voldoet niet aan de leeftijdseisen van"
                 << " de universiteit." << endl;
            return 1;
        }//Afwijzing van de gebruiker voor het eerste deel van de test.
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
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + day;
            }
            if ( month == 6 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + day;
            }
            if ( month == 7 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + lJun + day;
            }
            if ( month == 8 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + lJun + lJul + day;
            }
            if ( month == 9 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + lJun + lJul + lAug + day;
            }
            if ( month == 10 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + lJun + lJul + lAug + lSep + day;
            }
            if ( month == 11 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                        + lMay + lJun + lJul + lAug + lSep + lOct
                        + day;
            }
            if ( month == 12 ) {
                calcDay = year * 365 + lJan + lFeb + lMar + lApr 
                + lMay + lJun + lJul + lAug + lSep + lOct + lNov
                + day;
            }//Hier berekent is het aantal dagen vanaf jaar 0 tot dag
             //waarop de gebruiker geboren is, excl. schrikkeljaren.

            calcDay = calcDay + year/4 - year/100 + year/400; 
            //Toevoeging van schrikkeljaren aan de bovenstaande
            //berekening

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

            cout << "Vul de eerste letter in van de dag waarop u gebo"
                 << "ren bent met een kleine letter, toets vervolgens"
                 << " op ENTER: ";
            cin >> weekDay;
            if ( weekDay == 'd' || weekDay == 'z' ) {
                cout << "Vul ook de tweede letter van de dag in, toet"
                     << "s vervolgens op ENTER: ";
                cin >> weekDay2;
                if ( weekDay2 == birthDay2 ) {
                    cout << "Correct!" << endl;
                }
                else {
                    cout << "Dat is incorrect. Leer eerst uzelf kenne"
                         << "n zodat u met zekerheid aan uw studie ka"
                         << "n beginnen." << endl;
                    return 1;                    
                }
            }
            else if ( weekDay == birthDay ) {
                cout << "Correct!" << endl;
            }
            else {
                cout << "Dat is incorrect. Leer eerst uzelf kennen zo"
                     << "dat u met zekerheid aan uw studie kan beginn" 
                     << "en." << endl;
                return 1;
            }//Bepaald of de gebruiker de juiste dag ingevoerd heeft.

            cout << "U bent geboren op een ";
            if ( birthDay == 'm' ) {
                cout << "maandag" << endl;
            }
            if ( birthDay == 'd' && birthDay2 == 'i' ) {
                cout << "dinsdag" << endl;
            }
            if ( birthDay == 'w' ) {
                cout << "woensdag" << endl;
            }
            if ( birthDay == 'd' && birthDay2 == 'o' ) {
                cout << "donderdag" << endl;
            }
            if ( birthDay == 'v' ) {
                cout << "vrijdag" << endl;
            }
            if ( birthDay == 'z' && birthDay2 == 'a'  ) {
                cout << "zaterdag" << endl;
            }
            if ( birthDay == 'z' && birthDay2 == 'o'  ) {
                cout << "zondag" << endl;
            }//Print de geboortedag van de gebruiker
        }//Berekening en check van de geboortedag.

        //Hier beginnen de vragen over de temperatuur.
        bool Q1 = true;      //Check voor opslag van juiste antwoorden
        bool Q2 = true;

        int x;           //Invoer van temperatuurvragen door gebruiker
        int y;
        char antw;               //Invoer van antwoord literatuurvraag     

        int C1 = ( rand() % 159 ) - 39;      //Randomgenerator Celsius
        float F1 = 9 * (float) C1 / 5 + 32;    //Berekening Fahrenheit
        float tF1 = F1 * 100;  //Formule voor afronding op 2 decimalen
        if ((int) tF1 < tF1 - 0.5 ) {
            tF1++;
        }
        float dF1 = (int) tF1;
        dF1 = dF1 / 100;

        int F2 = ( rand() % 159 ) - 39;   //Randomgenerator Fahrenheit
        float C2 = ( (float) F2 - 32 ) * 5 / 9;   //Berekening Celsius
        float tC2 = C2 * 100;  //Formule voor afronding op 2 decimalen
        if ((int) tC2 < tC2 - 0.5 ) {
            tC2++;
        }
        float dC2 = (int) tC2;
        dC2 = dC2 / 100;
        if ( ageMonths / 12 >= 30 ) {
            cout << "U krijgt nu enkele vragen om uw affiniteit met e"
                 << "en beta-studie op te helderen. U moet tenminste "
                 << "een van de twee vragen voldoende beantwoorden."
                 << endl;
        }//Uitleg over temperatuurvragen aan de gebruiker 30 en ouder
        else {
            cout << "Je krijgt nu enkele vragen om te kijken of een b"
                 << "eta-studie bij je past. Je moet tenminste een va"
                 << "n de twee vragen voldoende beantwoorden."
                 << endl;
        }//Idem dito voor gebruiker onder de 30
        
        cout << "1) Hoeveel graden Fahrenheit staat gelijk aan " << C1
             << " graden Celsius? Typ een geheel getal, toets vervolg"
             << "ens op ENTER: ";
        cin >> x;
        if (( x < dF1 - errMargin ) || ( x > dF1 + errMargin )) {
            Q1 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }//Toetsing van eerste temperatuurvraag
        cout << dF1 << " is het goede antwoord." << endl << endl;

        cout << "2) Hoeveel graden Celsius staat gelijk aan " << F2
             << " graden Fahrenheit? Typ een geheel getal, toets verv"
             << "olgens op ENTER: ";
        cin >> y;
        if (( y < dC2 - 1 ) || ( y > dC2 + 1 )) {
            Q2 = false;
            cout << "Helaas is dit niet het juiste antwoord." << endl;
        }//Toetsing van tweede temperatuurvraag
        cout << dC2 << " is het goede antwoord." << endl << endl;
        
        if ( !Q1 && !Q2 ) {
            if ( ageMonths / 12 >= 30 ) {
                cout << "Uw antwoorden wijken te veel af van de juist"
                    << "e antwoorden. Daarom bent u helaas niet gesch"
                    << "ikt voor een beta-studie." << endl << "U kunt"
                    << " zich wel aanmelden voor een alpha-studie wan"
                    << "neer u de volgende vraag goed beantwoordt." 
                    << endl << endl << "In 1999 werd de verkiezing " 
                    << "'100 beste boeken van de eeuw' gehouden. Op "
                    << "welke plaatst eindigde 'Le Petit Prince'? ges"
                    << "chreven door Antoine de Saint-Exupery." 
                    << endl << "A) #1 " << endl << "B) #4 " << endl
                    << "C) #82" << endl << "D) Zo'n verkiezing is noo"
                    << "it gehouden." << endl;
            }//Doorverwijzing en vraag over alphastudie voor gebruiker
             //30 en ouder
            else {
                cout << "Je hebt de vragen niet goed beantwoord, daar"
                    << "om kan je helaas niet verder met een beta-stu"
                    << "die aan onze universiteit. Je kan je wel aanm"
                    << "elden voor een alpha studie als je de volgend"
                    << "e vraag goed beantwoordt." << endl << endl 
                    << "In het boek '1984' geschreven door George Orw"
                    << "ell, wordt gesproken over " 
                    << "'Het Ministerie van Liefde.' Wat regelt dit m"
                    << "inisterie?" << endl << "A) De sociale omgang "
                    << "tussen burgers." << endl << "B) De staatsveil"
                    << "igheid." << endl << "C) De verdeling van (lux"
                    << "e) goederen." << endl << "D) Fysieke interact"
                    << "ie tussen burgers onderling." << endl;
            }//Idem dito voor gebruiker jonger dan 30
            cout << "Vul de letter in die bij het juiste antwoord hoo"
                << "rt, toets vervolgens op ENTER: ";
            cin >> antw;
            if ( antw == 'B' || antw == 'b' ) {
                cout << "Dat is het juiste antwoord!" << endl;
                if ( ageMonths >= 30 ) {
                    cout << "Wij zien u volgend jaar graag tegemoet b"
                    << "ij een van de alpha studies aan onze universi"
                    << "teit." << endl;
                }//Toelatingsbericht voor alphastudie aan gebruiker
                 //30 en ouder
                else {
                    cout << "Wij zien je volgend jaar graag terug bij"
                    << "een van de alpha studies aan onze universitei"
                    << "t." << endl;
                }//Toelatingsbericht voor alphastudie aan gebruiker
                 //jonger dan 30
                return 1;
            }//Check van antwoord
            else {
                cout << "Dat is helaas niet het juiste antwoord." 
                     << endl << "Het juiste antwoord was 'B'."
                     << endl;
                if ( ageMonths >= 30 ) {
                    cout << "U komt niet in aanmerking voor een van d"
                         << "e studies aan onze universiteit." << endl
                         << "Bedankt voor uw deelname aan onze vragen"
                         << "lijst.";
                }//Afwijzingsbericht voor gebruikers 30 en ouder
                else {
                    cout << "Je bent jammer genoeg niet geschikt om b"
                         << "ij onze universiteit te komen studeren."
                         << endl << "Bedankt voor je deelname aan onz"
                         << "e vragenlijst.";
                }//Afwijzingsbericht voor gebruikers jonger dan 30
                return 1;
            }//Afwijzing voor universiteit
        }
        else {
            if ( ageMonths >= 30 ) {
                cout << "U heeft voldoende gescoord!" << endl << "U k"
                     << "omt in aanmerking voor een beta-studie aan o" 
                     << "nze universiteit. Wij zien u volgend studiej"
                     << "aar graag tegemoet." << endl;
            }//Toelatingsbericht voor gebruikers 30 en ouder
            else {
                cout << "Je hebt voldoende gescoord!" << endl << "Je "
                     << "mag je aanmelden voor een beta-studie aan on"
                     << "ze universiteit. Dan zien we je graag terug "
                     << "aan het begin van het volgend studiejaar!";
            }//Toelatingsbericht voor gebruiker jonger dan 30
            return 1;
        }//Toelating betastudie aan de universiteit
        return 0;
    }//main