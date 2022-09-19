    #include <iostream>
    #include <time.h>
    using namespace std;

    int main ( ) {
        const int currentYear = 2022;
        const int currentMonth = 9;
        const int currentDay = 26;
 
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
                if (( currentYear - year == 10 ) && ( month == currentMonth ) && ( day > currentDay )) {
                    ageMonths--;
                    allowedEntry = false;
                }//verificatie van geboortedag 10 jarige, geweigerd wanneer ze
                 //later in de maand jarig zijn.
                if (( currentYear - year == 101 ) && ( month == currentMonth ) && ( day < currentDay )) {
                    allowedEntry = false;
                }//verificatie van geboortedag 101 jarige, geweigerd wanneer ze
                 //eerder in de maand jarig zijn.
            }
        }

        cout << "U bent " << ageMonths << " maanden oud, dit staat" 
             << " gelijk aan " << ageMonths / 12 << " jaar en " 
             << ageMonths % 12 << " maanden." << endl;

        //cout << ctime(&currentDate);

        if ( month == currentMonth && day == currentDay ) {
            cout << "Gefeliciteerd, met uw verjaardag!" << endl;
        }

        if ( allowedEntry == false ) {
            cout << "Helaas, u voldoet niet aan de leeftijdseisen van de univer"
                 << "siteit." << endl;
            return 1;
        }
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
        }

        return 0;
    }//main