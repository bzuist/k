#include<iostream>
#include<string>
#include<locale>
#include<vector>
using namespace std;

class Hospital
{
private:
	string surname;
	string name;
	string patronymic;
	string phonenumber;
	double time;
	string specialist;
	int kategory;
public:
	Hospital();
	Hospital(string surname, double time, string phonenumber, int kategory, string patronymic, string name, string specialist);
	Hospital(string surname, double time, string name, string patronymic, int kategory, string specialist, string phonenumber);

		string getSpecialist();
		double getTime();
		int getKategory();
		void setSurname(string surname);
		void setName(string name);
		void setPatronymic(string patronymic);
		void setKategory(int kategoriya);
		void setTime(double time);
		void setSpecialist(string specialist);
		void setPhonenumber(string phonenumber);

		void input();
		void print();
		Hospital(const Hospital & Hospital);
		~Hospital();
	};