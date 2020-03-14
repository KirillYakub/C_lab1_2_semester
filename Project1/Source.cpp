#include <iostream>
#include <time.h>

using namespace std;

void easy()
{

	cout << "���������� ������� ���������, ������� ����� ���������� �� 95 � ���������� �� ����������" << endl << endl;
	
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
		cout << "������� �� ������� " << i + 1 << endl;
		cout << "������� �������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(number[i].surname, 56);
		cout << endl;

		cout << "������� ����� ������: ";
		cin >> number[i].group;
		cout << endl;

		cout << "������� ���: ";
		cin >> number[i].year;
		cout << endl;

		cout << "������ �� ������: ";
		cin >> number[i].physics;
		cout << endl;

		cout << "������ �� ��������: ";
		cin >> number[i].math;
		cout << endl;

		cout << "������ �� �����������: ";
		cin >> number[i].inform;
		cout << endl << endl;
	}

	//������� ������� � ���� � �������� ��� �������� ��������� � ������ �� ���������� = 95 � ������� �� �������;
	int count = 0;

	cout << "��������, ������� ���������� �� 95: ";

	for (int i = 0; i < N; i++)
	{
		if (number[i].math == 95)
		{
			cout << number[i].surname << "; ";
			count++;
		}
	}

	cout << endl;

	cout << "���������� ����� ���������: " << count << endl << endl;

}

void medium()
{

	cout << "������� ������ �� ��������� � ������������ ������������� ������" << endl << endl;

	//������� ��������� �� �������� ������ � �������;
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

	//������� ������ � ���� ��� ����������������� ����� �������� ��������� ���������;
	const int N = 2;

	avia number[N];

	for (int i = 0; i < N; i++)
	{
		
		cout << "������� �����: ";
		cin >> number[i].number;
		cout << endl;

		do
		{
			cout << "������� ����� ������ � �����: ";
			cin >> number[i].depart.hours_depart;
		} while (number[i].depart.hours_depart > 23 || number[i].depart.hours_depart < 0);
		cout << endl;

		do
		{
			cout << "������� ����� ������ � �������: ";
			cin >> number[i].depart.minutes_depart;
		} while (number[i].depart.minutes_depart > 59 || number[i].depart.minutes_depart < 0);
		cout << endl;
			
		do
		{
			cout << "������� ����� ������� � �����: ";
			cin >> number[i].arrive.hours_arrive;
		} while (number[i].arrive.hours_arrive > 23 || number[i].arrive.hours_arrive < 0);
		cout << endl;

		do
		{
			cout << "������� ����� ������� � �������: ";
			cin >> number[i].arrive.minutes_arrive;
		} while (number[i].arrive.minutes_arrive > 59 || number[i].arrive.minutes_arrive < 0);
	    cout << endl;

		cout << "�����������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(number[i].direct, 32);
		cout << endl;

		cout << "����� ��������: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(number[i].mark, 32);
		cout << endl;

		cout << "����������: ";
		cin >> number[i].distance;
		cout << endl << endl;

		//��������� ���� � ������ � ������� ����� ������;
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

	//��������� ������ ������� � ����;
	for (int i = 0; i < N; i++)
	{
		number[i].fly_time_hours = number[i].fly_time/60;
		number[i].fly_time_minutes = number[i].fly_time % 60;
	}

	cout << "���������� � ����� � ���������� ������������� ������:" << endl;
	cout << "����� �����: " << number[max_fligth_time].number << endl;
	cout << "����� ������: " << number[max_fligth_time].depart.hours_depart << ":" << number[max_fligth_time].depart.minutes_depart << endl;
	cout << "����� �������: " << number[max_fligth_time].arrive.hours_arrive << ":" << number[max_fligth_time].arrive.minutes_arrive << endl;
	cout << "�����: " << number[max_fligth_time].mark << endl;
	cout << "���������: " << number[max_fligth_time].distance << endl;
	cout << "����� ������: " << number[max_fligth_time].fly_time_hours << ":" << number[max_fligth_time].fly_time_minutes << endl << endl;

}

//������ �������� ������;
/*������� ��������� NOTE2 � ���, ������ ����� �������� � ������� ��������.
������� ������ BLOCK2 ���� NOTE1, ������� ������ ��������������� �� ������ 3-� ������ ������ ��������.
����� ������� ���������� � ��������, ������� �������� ������� � ����������. ���� ������ ��� - ������ ���������*/
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
		cout << "������� �������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.surname, 56);
		cout << endl;

		cout << "������� ���: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.name, 32);
		cout << endl;

		cout << "������� ��������: ";
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(BLOCK2[i].Name1.Name.patronymic, 56);
		cout << endl << endl;

		//��� ��� ����������� ����� �������� ������� �� 11 ��� 12 ����, �������� ������ 1-2 ����� ������ ������, �� ������ �����������;
		do 
		{
			BLOCK2[i].count = 0;
			do
			{
				//������� ���������� ���� � ������;
				cout << "������� ����� ��������: ";
				cin.ignore(cin.rdbuf()->in_avail());
				cin >> BLOCK2[i].TELE1.TELE;
				BLOCK2[i].TELE2 = BLOCK2[i].TELE1.TELE; /*���������� �������� ������ ����������
														��� ��� � ����� ����� ����� ��� ����������
														���������� ����*/
				do
				{
					BLOCK2[i].count++;
				} while ((BLOCK2[i].TELE1.TELE /= 10) > 0);
			} while (BLOCK2[i].count <= 10); //���� ����� �������� 10-��� ������ � ������;
		} while (BLOCK2[i].count >= 13); //���� ����� �������� 13-��� ������ � ������;
		cout << endl;
        cout << "���������� ���� � �����: "<< BLOCK2[i].count << endl << endl;
		
		//�������� �������� ����� ����;
		do
		{

			cout << "������� ���� ��������: ";
			cin >> BLOCK2[i].DATE1.DATE.day;
			cout << endl;

			cout << "������� ����� ������: ";
			cin >> BLOCK2[i].DATE1.DATE.month;
			cout << endl;

			cout << "������� ���: ";
			cin >> BLOCK2[i].DATE1.DATE.year;
			cout << endl << endl;

		} while (!BLOCK2[i].DATE1.DATE.isCorrect());
	}

	//������� ������ 3 ����� ������ ��������;
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

		cout << "������ 3 ����� " << i + 1 << " ������: " << BLOCK2[i].figure1 << ", " << BLOCK2[i].figure2 << ", " << BLOCK2[i].figure3 << endl;
    }

	cout << endl << endl;

	NOTE1 temp;

	//��������� �� ������ 3-� ������;
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

	cout << "��������������� ������ �������� �� ������ 3 ������ ������ ��������: " << endl << endl;

	for (int i = 0; i < N; i++)
	{
		cout << "���: " << BLOCK2[i].Name1.Name.surname << " " << BLOCK2[i].Name1.Name.name << " " << BLOCK2[i].Name1.Name.patronymic << endl;
		cout << "����� ��������: +" << BLOCK2[i].TELE2 << endl;
		cout << "���� ��������: " << BLOCK2[i].DATE1.DATE.day << "." << BLOCK2[i].DATE1.DATE.month << "." << BLOCK2[i].DATE1.DATE.year;
		cout << endl << endl;
	}

	cout << "����� ���������� � ��������, ��� ������� ������� � ����������. ���� ������ ��� - ����� �������� ���������" << endl;
	cout << "������� �������: " << endl;

	string surname;
	
	//������ ���������� count1, ���-�� � ������ ���� ������� � ��������� �������� ��� ������ �� ���������� ��������� ��� ��������� ��������;
	int count1 = 0;

	cin >> surname;

	cout << endl;

	for (int i = 0; i < N; i++)
	{
		if (surname == BLOCK2[i].Name1.Name.surname)
		{
			cout << "���������� � �������� � �������� " << surname << ": " << endl;
			cout << "���: " << BLOCK2[i].Name1.Name.surname << " " << BLOCK2[i].Name1.Name.name << " " << BLOCK2[i].Name1.Name.patronymic << endl;
			cout << "����� ��������: +" << BLOCK2[i].TELE2 << endl;
			cout << "���� ��������: " << BLOCK2[i].DATE1.DATE.day << "." << BLOCK2[i].DATE1.DATE.month << "." << BLOCK2[i].DATE1.DATE.year << endl;
			count1++;
		}

		else if (surname != BLOCK2[i].Name1.Name.surname && i == N - 1 && count1 == 0)
		{
			cout << "��� �������� � ����� ��������" << endl << endl;
		}
	}

}

int main()
{

	int number;
	int Correct = 0;

	setlocale(LC_ALL, "ru");

	cout << "������� � 20" << endl;

	do
	{
		cout << "������� ����� 1(easy) ��� 2(medium) ��� 3(hard): ";

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