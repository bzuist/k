#include "Header.h"

Hospital::Hospital()
{

}
Hospital::Hospital(string surname, double time, string phonenumber, int kategory, string patronymic, string name, string specialist)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->phonenumber = phonenumber;
	this->specialist = specialist;
	this->kategory = kategory;
	this->time = time;
}

string Hospital::getSpecialist()
{
	return specialist;
}
int Hospital::getKategory()
{
	return kategory;
}
double Hospital::getTime()
{
	return time;
}

void Hospital::setSurname(string surname)
{
	this->surname = surname;
}
void Hospital::setKategory(int kategory)
{
	this->kategory = kategory;
}
void Hospital::setTime(double time)
{
	this->time = time;
}
void Hospital::setName(string name)
{
	this->name = name;
}
void Hospital::setPatronymic(string patronymic)
{
	this->patronymic = patronymic;
}
void Hospital::setSpecialist(string specialist)
{
	this->specialist = specialist;
}
void Hospital::setPhonenumber(string phonenumber)
{
	this->phonenumber = phonenumber;
}

void Hospital::input()
{
	cout << "Ââåäèòå ôàìèëèþ: ";
	cin >> surname;
	cout << "Ââåäèòå èìÿ";
	cin >> name;
	cout << "Ââåäèòå îò÷åñòâî: ";
	cin >> patronymic;
	cout << "Ââåäèòå íîìåð òåëåôîíà: ";
	cin >> phonenumber;
	cout << "Ââåäèòå êàòåãîðèþ (1 - äåòñêèé, 2- âçðîñëûé): ";
	cin >> kategory;
	while ((kategory != 1) and (kategory != 2))
	{
		cout << "\nÍåâåðíûé ââîä! Ââåäèòå êàòåãîðèþ ñîãëàñíî èíñòðóêöèè.\nÒèï: ";
		cin >> kategory;
	}
	cout << "Ââåäèòå ñïåöèàëèñòà: ";
	cin >> specialist;
	cout << "Ââåäèòå âðåìÿ â ôîðìàòå ÷÷.ìì";
	cin >> time;
	while (cin.fail() or time < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nÍåâåðíûé ââîä! Ââåäèòå âðåìÿ â ôîðìàòå ÷÷.ìì\n";
		cin >> time;
	}
}
void Hospital::print()
{
	cout << "Ôàìèëèÿ: " << surname << "\nÈìÿ: " << name << "\nÎò÷åñòâî: " << patronymic << "\nÍîìåð òåëåôîíà : " << phonenumber;
	cout << "\nÑïåöèàëèñò: " << specialist << "\nÊàòåãîðèÿ : " << kategory << "\nÂðåìÿ çàïèñè : " << time;
	cout << '\n' << '\n';
}
Hospital::Hospital(const Hospital& Hospital)
{
	surname = Hospital.surname;
	time = Hospital.time;
	kategory = Hospital.kategory;
	name = Hospital.name;
	patronymic = Hospital.patronymic;
	specialist = Hospital.specialist;

}
Hospital::~Hospital()
{
}
