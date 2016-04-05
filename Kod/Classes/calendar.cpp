
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

struct Event
{
	string name;
	Date date;	
};

bool check(string& birth);
Date create(string& birth);
void print_date(Date& date)
{
	cout << "\tDay: " << date.day;
	cout << " Month: " << date.month;
	cout << " Year: " << date.year << endl;
}
void print_event(Event& event)
{
	cout << "Name: " << event.name;
	print_date(event.date);
}

int main()
{
	string event;
	vector<Event> events; // mamy worek na wydarzenia które chcemy zapamiêtaæ

	while(1)
	{
		string date;
		string name;
		do
		{
			cout << "Give me imporant dates as: <name> dd.mm.yyyy" << endl;
			cout << "Quit to finish" << endl;
					
			cin >> name;
			if ( name == "Quit" || name == "quit" )
				break;
				
			getline(cin, date);
			
		} while( ! check(date) );

		if ( name == "Quit" || name == "quit" )
			break;
			
		Date important = create(date);
		Event event = { name, important }; // inicjalizacja struktury wydarzenia
		events.push_back(event);	// wrzucamy wydarzenie do worka
	}
	
	// jeœli worek nie jest pusty 
	if ( !events.empty() )
		cout << "Your calendar: " << endl;
	
	// size - zwraca rozmiar worka
	// pêtla jest identyczna jak przy tablicy
	for( int i = 0; i < events.size(); i++ )
		print_event(events[i]); // odwo³ujemy siê jak do tablicy
	
	system("pause");
	
	// iterator
	//events.begin() -> to pierwszy element (czyli indeks 0)
	//events.begin() + x -> to elementu o numerze x (czyli indeks x - 1)
	for( vector<Event>::iterator it = events.begin();
		 it != events.end(); it++ ) // taki wskaŸnik, który przesuwamy od pocz¹tku do koñca
	{
		print_event(*it); // tutaj do elementu odwo³ujemy siê jak do wskaŸnika 
	}
	return 0;
}

bool check(string& birth)
{
stringstream st(birth);						//nie podoba mi się że jeszcze raz używam tego samego co poniżej
	Date user;									
	st >> user.day;
	st.ignore(1);
	st >> user.month;
	st.ignore(1);
	st >> user.year;
	
	if ((user.day > 29 && user.month == 2) || user.day > 31 || user.month > 12 || user.year > 3000)	{ 	//jeśli dzień jest większy od 31 lub miesiąc większy od 12 oczywiście kontrola lutego, no i można dopisać inne mieisące
	cout << "Incorect data format or range" << endl;		//to wyświetla komunikat i zwraca false
	return false;
	}
	else {
	return true;
	}
}

Date create(string& birth)
{
	stringstream st(birth);
	Date user;
	st >> user.day;
	st.ignore(1);
	st >> user.month;
	st.ignore(1);
	st >> user.year;
	
	return user;
}

