    #include <iostream>
    #include <time.h>
    using namespace std;

    int main ( ) {
        int close = 0;
        const int currentYear = 2022;
        const int currentMonth = 9;
        const int currentDay = 26;

        int day;
        int month;
        int year;
        int ageMonths;

        //time_t currentDate;
        //time (&timer);

        cout << "Voer je geboortedatum in met het format, yyyy mm dd: "
             << endl;
        cin >> year;
        if (( currentYear - year < 10 ) || ( currentYear - year ) > 101 ) {
            cout << "Als " << currentYear - year
                 << " jarige voldoet U niet aan de leeftijdseisen om in "
                 << "aanmerking te komen voor de universiteit." << endl;
            return 1;
        }//Verificatie van geboortejaar, 10 en 101 jarige worden doorgelaten
        else {
            cin >> month;
            ageMonths = 12 * ( currentYear - year ) + ( currentMonth - month );
            if ((( currentYear - year == 10 ) && ( month > currentMonth )) || (( currentYear - year == 101 ) && ( month < currentMonth ))) {
                cout << "Als " << ageMonths / 12
                 << " jarige voldoet U niet aan de leeftijdseisen om in "
                 << "aanmerking te komen voor de universiteit." << endl;
                return 1;
            }//verificatie van geboortemaand, 10 en 101 jarige worden doorgelaten als ze in dezelfde maand jarig zijn.
            else {
                cin >> day;
                if (( currentYear - year == 10 ) && ( month == currentMonth ) && ( day > currentDay )) {
                    ageMonths--;
                    cout << "Als " << ageMonths / 12
                         << " jarige voldoet U niet aan de leeftijdseisen om in "
                         << "aanmerking te komen voor de universiteit." << endl;
                    return 1;
                }//verificatie van geboortedag 10 jarige, geweigerd wanneer ze later in de maand jarig zijn.
                if (( currentYear - year == 101 ) && ( month == currentMonth ) && ( day < currentDay )) {
                    cout << "Als " << ageMonths / 12
                         << " jarige voldoet U niet aan de leeftijdseisen om in "
                         << "aanmerking te komen voor de universiteit." << endl;
                    return 1;
                }//verificatie van geboortedag 101 jarige, geweigerd wanneer ze eerder in de maand jarig zijn.
            }
        }
        
        cout << "U bent " << ageMonths / 12 << " maanden oud, dit staat gelijk aan "
             << ageMonths / 12 << " jaar en " << ageMonths % 12 << " maanden." << endl;

        //cout << ctime(&currentDate);


        return 0;
    }//main