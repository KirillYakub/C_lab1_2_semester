#include <iostream>
#include <time.h>

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

    const int N = 2;

	students number[N];

	for (int i = 0; i < N; i++)
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

	//создаем счетчик и цикл с условием для подсчета студентов с баллом по математике = 95 и выводим их фамилии;
	int count = 0;

	cout << "Студенты, сдавшие математику на 95: ";

	for (int i = 0; i < N; i++)
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

	//создаем структуры со временем вылета и прилета;
	struct time_depart
	{
		int hours_depart;
		int minutes_depart;
	};

	struct time_arrive
	{
		int hours_arrive;
		int minutes_arrive;
	};

	struct avia
	{
		int number;
		time_depart depart;
		time_arrive arrive;
		char direct[32];
		char mark[32];
		int distance;
		int fly_time;
		int fly_time_hours;
		int fly_time_minutes;
    };

	//создаем массив и цикл для последовательного ввода значений элементов структуры;
	const int N = 2;

	avia number[N];

	for (int i = 0; i < N; i++)
	{
		
		cout << "Введите номер: ";
		cin >> number[i].number;
		cout << endl;

		do
		{
			cout << "Введите время вылета в часах: ";
			cin >> number[i].depart.hours_depart;
		} while (number[i].depart.hours_depart > 23 || number[i].depart.hours_depart < 0);
		cout << endl;

		do
		{
			cout << "Введите время вылета в минутах: ";
			cin >> number[i].depart.minutes_depart;
		} while (number[i].depart.minutes_depart > 59 || number[i].depart.minutes_depart < 0);
		cout << endl;
			
		do
		{
			cout << "Введите время прилета в часах: ";
			cin >> number[i].arrive.hours_arrive;
		} while (number[i].arrive.hours_arrive > 23 || number[i].arrive.hours_arrive < 0);
		cout << endl;

		do
		{
			cout << "Введите время прилета в минутах: ";
			cin >> number[i].arrive.minutes_arrive;
		} while (number[i].arrive.minutes_arrive > 59 || number[i].arrive.minutes_arrive < 0);
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

		//переводим часы в минуты и находим время полета;
		int hour_in_minutes_depart = number[i].depart.hours_depart*60;
		hour_in_minutes_depart = hour_in_minutes_depart + number[i].depart.minutes_depart;

		int hour_in_minutes_arrive = number[i].arrive.hours_arrive * 60;
		hour_in_minutes_arrive = hour_in_minutes_arrive + number[i].arrive.minutes_arrive;

		if (hour_in_minutes_arrive >= hour_in_minutes_depart)
		{
			number[i].fly_time = hour_in_minutes_arrive - hour_in_minutes_depart;
		}

		if (hour_in_minutes_arrive < hour_in_minutes_depart)
		{
			number[i].fly_time = (24 * 60) - (hour_in_minutes_depart - hour_in_minutes_arrive);
		}
	}

	int max_fligth_time = 0;

	for (int i = 0; i < N; i++)
	{
        if (number[i].fly_time > number[max_fligth_time].fly_time)
		{
			max_fligth_time = i;
		}
	}

	//переводим минуты обратно в часы;
	for (int i = 0; i < N; i++)
	{
		number[i].fly_time_hours = number[i].fly_time/60;
		number[i].fly_time_minutes = number[i].fly_time % 60;
	}

	cout << "Информация о рейсе с найбольшей длительностью полета:" << endl;
	cout << "Номер рейса: " << number[max_fligth_time].number << endl;
	cout << "Время вылета: " << number[max_fligth_time].depart.hours_depart << ":" << number[max_fligth_time].depart.minutes_depart << endl;
	cout << "Время прилета: " << number[max_fligth_time].arrive.hours_arrive << ":" << number[max_fligth_time].arrive.minutes_arrive << endl;
	cout << "Марка: " << number[max_fligth_time].mark << endl;
	cout << "Дистанция: " << number[max_fligth_time].distance << endl;
	cout << "Время полета: " << number[max_fligth_time].fly_time_hours << ":" << number[max_fligth_time].fly_time_minutes << endl << endl;
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
	
	if(number == 2)
	{
		medium();
	}

}