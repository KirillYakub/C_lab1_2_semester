#include <iostream>

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

    const int n = 3;

	students number[n];

	for (int i = 0; i < 3; i++)
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

	int count = 0;

	cout << "��������, ������� ���������� �� 95: ";

	for (int i = 0; i < n; i++)
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
		cout << "���� �� ������� " << i + 1 << endl;
		cout << "������� �����: ";
		cin >> number[i].number;
		cout << endl;

		cout << "������� ����� ������: ";
		cin >> number[i].depart;
		cout << endl;

		cout << "������� ����� �������: ";
		cin >> number[i].arrive;
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

	cout << "���������� � ����� � ���������� ������������� ������:" << endl;
	cout << "����� �����: " << number[max_flight_time].number << endl;
	cout << "����� ������: " << number[max_flight_time].depart << endl;
	cout << "����� �������: " << number[max_flight_time].arrive << endl;
	cout << "�����������: " << number[max_flight_time].direct << endl;
	cout << "����� ��������: " << number[max_flight_time].mark << endl;
	cout << "����� ������: " << number[max_flight_time].flight_time << endl;
}

int main()
{

	int number;

	setlocale(LC_ALL, "ru");
	
	cout << "������� � 20" << endl;
	cout << "������� ����� 1(easy) ��� 2(medium): ";
    
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