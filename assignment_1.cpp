    #include <iostream>
    #include <time.h>
    using namespace std;

    int main ( ) {
        int close = 0;
        int currentYear = 2022;
        int currentMonth = 9;
        int currentDay = 26;

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
        }
        else {
            cin >> month;
            ageMonths = 12 * ( currentYear - year ) + ( currentMonth - month );
            cout << "Uw leeftijd is " << ageMonths / 12 << " jaar en "
             << ageMonths % 12 << " maanden oud." << endl;
            if (( currentYear - year == 10 ) && ( month > currentMonth )) {
                cout << "Als " << ageMonths / 12
                 << " jarige voldoet U niet aan de leeftijdseisen om in "
                 << "aanmerking te komen voor de universiteit." << endl;
                return 1;
            }
            if (( currentYear - year == 101 ) && ( month < currentMonth )) {
                cout << "Als " << ageMonths / 12
                 << " jarige voldoet U niet aan de leeftijdseisen om in "
                 << "aanmerking te komen voor de universiteit." << endl;
                return 1;
            }
        }
        cin >> day;  //Invoer van geboorte-data

        //cout << ctime(&currentDate);


        return 0;
    }//main