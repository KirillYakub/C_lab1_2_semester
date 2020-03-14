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

//начало сложного уровня;
/*Создать структуру NOTE2 с ФИО, полной датой рождения и номером телефона.
Создать массив BLOCK2 типа NOTE1, вывести данные отсортированные по первым 3-м цифрам номера телефона.
Также вывести информацию о человеке, фамилия которого введена с клавиатуры. Если такого нет - выдать сообщение*/
struct birthday
{
	int day;
	int month;
	int year;
	bool isCorrect();
};

struct FIO
{
	char name[32];
	char surname[56];
	char patronymic[56];
};

struct NOTE2
{
	FIO Name;
	long long int TELE;
	birthday DATE;
};

struct NOTE1
{
	NOTE2 Name1;
	NOTE2 TELE1;
	NOTE2 DATE1;
	long long int TELE2;
	int count = 0;
	int figure1;
	int figure2;
	int figure3;
};

bool birthday::isCorrect()
{
	bool result = false;

	switch (month)
	{

	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

void hard()
{
	
    const int N = 2;
	NOTE1 BLOCK2[N];
	
	for (int i = 0; i < N; i++)
	{
		cout << "Введите Фамилию: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.surname, 56);
		cout << endl;

		cout << "Введите Имя: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.name, 32);
		cout << endl;

		cout << "Введите Отчество: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.patronymic, 56);
		cout << endl << endl;

		//так как стандартный номер телефона состоит из 11 или 12 цифр, учитывая первые 1-2 цифры номера страны, то вводим ограничения;
		do 
		{
			BLOCK2[i].count = 0;
			do
			{
				//находим количество цифр в номере;
				cout << "Введите Номер Телефона: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> BLOCK2[i].TELE1.TELE;
				BLOCK2[i].TELE2 = BLOCK2[i].TELE1.TELE; /*присваевам значение другой переменной
														так как в цикле делим номер для нахождения
														количества цифр*/
				do
				{
					BLOCK2[i].count++;
				} while ((BLOCK2[i].TELE1.TELE /= 10) > 0);
			} while (BLOCK2[i].count <= 10); //если номер является 10-ным числом и меньше;
		} while (BLOCK2[i].count >= 13); //если номер является 13-ным числом и меньше;
		cout << endl;
        cout << "Количество цифр в числе: "<< BLOCK2[i].count << endl << endl;
		
		//проверка точности ввода даты;
		do
		{

			cout << "Введите День Рождения: ";
			cin >> BLOCK2[i].DATE1.DATE.day;
			cout << endl;

			cout << "Введите Номер Месяца: ";
			cin >> BLOCK2[i].DATE1.DATE.month;
			cout << endl;

			cout << "Введите Год: ";
			cin >> BLOCK2[i].DATE1.DATE.year;
			cout << endl << endl;

		} while (!BLOCK2[i].DATE1.DATE.isCorrect());
	}

	//находим первые 3 цифры номера телефона;
    for (int i = 0; i < N; i++)
	{
		if (BLOCK2[i].count == 12)
		{
			BLOCK2[i].figure1 = BLOCK2[i].TELE2 / 100000000000;
			BLOCK2[i].figure2 = (BLOCK2[i].TELE2 / 10000000000) % 10;
			BLOCK2[i].figure3 = (BLOCK2[i].TELE2 / 1000000000) % 10;
		}

		if (BLOCK2[i].count == 11)
		{
			BLOCK2[i].figure1 = BLOCK2[i].TELE2 / 10000000000;
			BLOCK2[i].figure2 = (BLOCK2[i].TELE2 / 1000000000) % 10;
			BLOCK2[i].figure3 = (BLOCK2[i].TELE2 / 100000000) % 10;
		}

		cout << "Первые 3 числа " << i + 1 << " номера: " << BLOCK2[i].figure1 << ", " << BLOCK2[i].figure2 << ", " << BLOCK2[i].figure3 << endl;
    }

	cout << endl << endl;

	NOTE1 temp;

	//сортируем по первым 3-м цифрам;
	for (int i = 0; i < N; i++)
	{
		for (int i = 0; i < N - 1; i++)
		{
            if (BLOCK2[i].figure1 > BLOCK2[i + 1].figure1 && BLOCK2[i].figure2 > BLOCK2[i + 1].figure2 && BLOCK2[i].figure3 > BLOCK2[i + 1].figure3)
			{
				temp = BLOCK2[i];
				BLOCK2[i] = BLOCK2[i + 1];
				BLOCK2[i + 1] = temp;
			}
		}
	}

	cout << "Отсортированный массив структур по первым 3 цифрам номера телефона: " << endl << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "ФИО: " << BLOCK2[i].Name1.Name.surname << " " << BLOCK2[i].Name1.Name.name << " " << BLOCK2[i].Name1.Name.patronymic << endl;
		cout << "Номер телефона: +" << BLOCK2[i].TELE2 << endl;
		cout << "Дата Рождения: " << BLOCK2[i].DATE1.DATE.day << "." << BLOCK2[i].DATE1.DATE.month << "." << BLOCK2[i].DATE1.DATE.year;
		cout << endl << endl;
	}

	cout << "Вывод информации о человеке, чья фамилия введена с клавиатуры. Если такого нет - будет выведено сообщение" << endl;
	cout << "Введите фамилию: " << endl;

	string surname;
	
	//вводим переменную count1, что-бы в случае если человек с введенной фамилией уже найден не выводилось сообщение при следующей итерации;
	int count1 = 0;

	cin >> surname;

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (surname == BLOCK2[i].Name1.Name.surname)
		{
			cout << "Информация о человеке с фамилией " << surname << ": " << endl;
			cout << "ФИО: " << BLOCK2[i].Name1.Name.surname << " " << BLOCK2[i].Name1.Name.name << " " << BLOCK2[i].Name1.Name.patronymic << endl;
			cout << "Номер телефона: +" << BLOCK2[i].TELE2 << endl;
			cout << "Дата Рождения: " << BLOCK2[i].DATE1.DATE.day << "." << BLOCK2[i].DATE1.DATE.month << "." << BLOCK2[i].DATE1.DATE.year << endl;
			count1++;
		}

		else if (surname != BLOCK2[i].Name1.Name.surname && i == N - 1 && count1 == 0)
		{
			cout << "Нет человека с такой фамилией" << endl << endl;
		}
	}

}

int main()
{

	int number;
	int Correct = 0;

	setlocale(LC_ALL, "ru");

	cout << "Вариант № 20" << endl;

	do
	{
		cout << "Введите номер 1(easy) или 2(medium) или 3(hard): ";

		cin >> number;

		if (number == 1)
		{
			easy();
			Correct++;
		}

		if (number == 2)
		{
			medium();
			Correct++;
		}

		if (number == 3)
		{
			hard();
			Correct++;
		}
	} while (Correct == 0);

}