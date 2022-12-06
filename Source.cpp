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
	cout << "������� �������: ";
	cin >> surname;
	cout << "������� ���";
	cin >> name;
	cout << "������� ��������: ";
	cin >> patronymic;
	cout << "������� ����� ��������: ";
	cin >> phonenumber;
	cout << "������� ��������� (1 - �������, 2- ��������): ";
	cin >> kategory;
	while ((kategory != 1) and (kategory != 2))
	{
		cout << "\n�������� ����! ������� ��������� �������� ����������.\n���: ";
		cin >> kategory;
	}
	cout << "������� �����������: ";
	cin >> specialist;
	cout << "������� ����� � ������� ��.��";
	cin >> time;
	while (cin.fail() or time < 0)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n�������� ����! ������� ����� � ������� ��.��\n";
		cin >> time;
	}
}
void Hospital::print()
{
	cout << "�������: " << surname << "\n���: " << name << "\n��������: " << patronymic << "\n����� �������� : " << phonenumber;
	cout << "\n����������: " << specialist << "\n��������� : " << kategory << "\n����� ������ : " << time;
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
