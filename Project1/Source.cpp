#include <iostream>

using namespace std;

void easy()
{

	cout << "Напечатать фамилии студентов, которые сдали математику на 95 и определить их количество" << endl << endl;
	
    struct students
	{
		char surname[56];
		int group;
		int year;
		int physics;
		int math;
		int inform;
	};

    const int n = 3;

	students number[n];

	for (int i = 0; i < 3; i++)
	{
		cout << "Студент по номером " << i + 1 << endl;
		cout << "Введите фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(number[i].surname, 56);
		cout << endl;

		cout << "Введите номер группы: ";
		cin >> number[i].group;
		cout << endl;

		cout << "Введите год: ";
		cin >> number[i].year;
		cout << endl;

		cout << "Оценка по физике: ";
		cin >> number[i].physics;
		cout << endl;

		cout << "Оценка по матетике: ";
		cin >> number[i].math;
		cout << endl;

		cout << "Оценка по информатике: ";
		cin >> number[i].inform;
		cout << endl << endl;
	}

	int count = 0;

	cout << "Студенты, сдавшие математику на 95: ";

	for (int i = 0; i < n; i++)
	{
		if (number[i].math == 95)
		{
			cout << number[i].surname << "; ";
			count++;
		}
	}

	cout << endl;

	cout << "Количество таких студентов: " << count << endl << endl;

}

void medium()
{

	cout << "Вывести данные об авиарейсе с максимальной длительностью полета" << endl << endl;

	struct avia
	{
		int number;
		double depart;
		double arrive;
		char direct[32];
		char mark[32];
		int distance;
		double flight_time;
    };

	const int n = 3;

	avia number[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Рейс по номером " << i + 1 << endl;
		cout << "Введите номер: ";
		cin >> number[i].number;
		cout << endl;

		cout << "Введите время вылета: ";
		cin >> number[i].depart;
		cout << endl;

		cout << "Введите время прилета: ";
		cin >> number[i].arrive;
		cout << endl;

		cout << "Направление: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(number[i].direct, 32);
		cout << endl;

		cout << "Марка самолета: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(number[i].mark, 32);
		cout << endl;

		cout << "Расстояние: ";
		cin >> number[i].distance;
		cout << endl << endl;

		number[i].flight_time = abs(number[i].arrive - number[i].depart);
    }

	cout << endl << endl;

	short max_flight_time = 0;

	for (int i = 0; i < n; i++)
	{
		if (number[i].flight_time > number[max_flight_time].flight_time)
		{
			max_flight_time = i;
		}
	}

	cout << "Информация о рейсе с найбольшей длительностью полета:" << endl;
	cout << "Номер рейса: " << number[max_flight_time].number << endl;
	cout << "Время вылета: " << number[max_flight_time].depart << endl;
	cout << "Время прилета: " << number[max_flight_time].arrive << endl;
	cout << "Направление: " << number[max_flight_time].direct << endl;
	cout << "Марка самолета: " << number[max_flight_time].mark << endl;
	cout << "Время полета: " << number[max_flight_time].flight_time << endl;
}

int main()
{

	int number;

	setlocale(LC_ALL, "ru");
	
	cout << "Вариант № 20" << endl;
	cout << "Введите номер 1(easy) или 2(medium): ";
    
	cin >> number;
	
	if (number == 1)
	{
		easy();
	}
	else 
	{
		medium();
	}
	
}