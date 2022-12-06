#include<iostream>
#include<string>
#include<locale>
#include<vector>
#include "Header.h"

using namespace std;


void menu()
{
	cout << "1. Если хотите сделать новую запись, выберите '1'\n";
	cout << "2. Если хотите изменить данные о записи, выберите '2'\n";
	cout << "3. Если хотите удалить запись из списка, выберите '3'\n";
	cout << "4. Если хотите вывести все введенные записи, выберите '3'\n";
	cout << "Для выхода из программы нажмите '0'\n\n";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int kategory = 0;
	string surname, name, phonenumber, specialist, patronymic = "";
	double time;
	menu();
	vector <Hospital*> hospital;
	hospital.push_back(new Hospital);
	char option = 1;
	while (option != 0)
	{
		cin >> option;
		cout << '\n';
		switch (option)
		{
		case '1':
		{
			while (true)
			{
				int val = 1;
				cout << '\n' << "Введите информацию о " << hospital.size() << " новой записи: " << '\n' << '\n';
				hospital.push_back(new Hospital);
				hospital[hospital.size() - 1]->input();
				cout << '\n';
				cout << "Если хотите продолжить - нажмите '1'. Для выхода - '0': ";
				cin >> val;
				while (cin.fail() or (val != 1 and val != 0))
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "Неверный ввод! Введите корректное значение: ";
					cin >> val;
				}
				cout << '\n' << '\n';
				if (val == 0)
				{
					menu();
					break;
				}
			}
			break;
		}
		case '2':
		{
			if (hospital.size() - 1 != 0)
			{
				cout << "Введите порядковый номер записи, которую хотите изменить: ";
				int num_1 = 0;
				cin >> num_1;
				while (cin.fail() or ((num_1 <= hospital.size() - 1) and (num_1 > 0)))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\nНеверный ввод! Введите положительное число.\n" << "Порядковый номер урагана: ";
					cin >> num_1;
				}
				cout << '\n';
				if ((num_1 <= hospital.size() - 1) and (num_1 > 0))
				{
					cout << "Введите номер свойства, которое хотите изменить.\n";
					cout << "Свойства:\n1. - фамилия \n2. - имя \n3. - отчество\n4. - номер телефона\n5. - категория\n6. - специалист\n7. - время";
					int num_2 = 0;
					cin >> num_2;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cout << "\nНеверный ввод! Введите целое.\n" << "Номер свойства: ";
						cin >> num_2;
					}
					if (num_2 > 0 and num_2 < 7)
					{
						if (num_2 == 1)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Фамилия': ";
							cin >> surname;
							hospital.at(hospital.size() - 1)->setSurname(surname);
						}
						if (num_2 == 2)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Имя': ";
							cin >> name;
							hospital.at(hospital.size() - 1)->setName(name);
						}
						if (num_2 == 3)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Отчество': ";
							cin >> patronymic;
							hospital.at(hospital.size() - 1)->setPatronymic(patronymic);
						}
						if (num_2 == 4)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Номер телефона': ";
							cin >> phonenumber;
							hospital.at(hospital.size() - 1)->setSurname(surname);
						}
						if (num_2 == 5)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Категория': ";
							cin >> kategory;
							while ((kategory != 1) and (kategory != 2))
							{
								cout << "\nНеверный ввод! Введите категорию согласно инструкции (1 - 5).\nТип: ";
								cin >> kategory;
							}
							hospital.at(hospital.size() - 1)->setKategory(kategory);
						}
						if (num_2 == 6)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Специальность': ";
							cin >> specialist;
							hospital.at(hospital.size() - 1)->setSpecialist(specialist);
						}
						if (num_2 == 7)
						{
							cout << "Введите новое значение, которое хотите задать в поле 'Время': ";
							cin >> time;
							while (cin.fail() or time < 0)
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "\nНеверный ввод! Введите положительное число.\n" << "Время: ";
								cin >> time;
							}
							hospital.at(hospital.size() - 1)->setTime(time);
						}						
					}
					else
						cout << "Неверный ввод!" << '\n' << '\n';
				}
				else
					cout << "Записи с таким номером не существует!" << '\n' << '\n';
			}
			else
			{
				cout << "Список пуст! Сначала добавьте ноую запись в список. " << '\n' << '\n';
			}
			cout << '\n' << '\n';
			menu();
			break;
		}
		case '3':
		{
			if (hospital.size() - 1 != 0)
			{
				cout << "Введите порядковый номер записи, которую необходимо удалить из списка: ";
				int delete_ind = 0;
				cin >> delete_ind;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(cin.rdbuf()->in_avail());
					cout << "\nНеверный ввод! Введите целое число.\n" << "Порядковый номер записи: ";
					cin >> delete_ind;
				}
				cout << '\n';
				if ((delete_ind <= hospital.size() - 1) and (delete_ind > 0))
				{
					hospital.erase(hospital.begin() + delete_ind - 1);
					cout << "Запись номер " << delete_ind << " успешно удалена из списка" << '\n' << '\n';
					menu();
				}
				else
				{
					cout << "Записи с таким порядковым номером не существует!\nПопробуйте снова." << '\n' << '\n';
					menu();
				}
			}
			else
			{
				cout << "Список пуст! Сначала добавьте ноую запись в список и повторите попытку. " << '\n' << '\n';
				menu();
			}
			break;
		}
		case '4':
		{
			if (hospital.size() - 1 != 0)
			{
				cout << "Всего узаписей : " << hospital.size() - 1 << '\n' << '\n';
				for (int i = 1; i < hospital.size(); i++)
				{
					hospital[i]->print();
				}
			}
			else
				cout << "Список пуст!  Сначала добавьте ноую запись в список и повторите попытку. " << '\n' << '\n';
			menu();
			break;
		}
		case '0':
		{
			option = 0;
		}
		default:
			if (option != 0)
				cout << "Введено некорректное значение!\n\n";
			break;
		}
	}
	return 0;
}
