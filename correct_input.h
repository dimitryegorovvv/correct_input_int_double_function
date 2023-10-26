#pragma once
// ������� ��� �������� �� ���� ������ ����� ��� int � double
namespace correct_numbers
{
	using namespace std;
	int correct_input_int()
	{
		string number;
		setlocale(LC_ALL, "ru");
		bool is_incorrect_symbols;
		string* enter_and_backspace_check = &number;
		char* incorrect_symbol = const_cast<char*>(number.c_str());
		do
		{
		back:
			is_incorrect_symbols = false;
			// ������� ������ �����
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			// ���� ��������
			getline(cin, number);
			// �������� �� ������ ��� enter
			if (enter_and_backspace_check[0] == "" || enter_and_backspace_check[0] == " ")
			{
				cout << "�� ����� ������������ ������" << endl;
				goto back;
			}
			// �������� �� ����������� ���� �������� (�� ����)
			for (int i = 0; i < number.length(); i++)
			{
				if (incorrect_symbol[i] < 48 || incorrect_symbol[i] > 57)
				{
					is_incorrect_symbols = true;
					cout << "�� ����� ������������ ������" << endl;
					break;
				}
			}

		} while (is_incorrect_symbols);
		int new_number_type = stoi(number);
		return new_number_type;
	}

	double correct_input_double()
	{
		string number;
		bool is_incorrect_symbols;
		string* enter_and_backspace_check = &number;
		char* incorrect_symbol = const_cast<char*>(number.c_str());
		do
		{
		back:
			is_incorrect_symbols = false;
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin, number);
			if (enter_and_backspace_check[0] == "" || enter_and_backspace_check[0] == " ")
			{
				cout << "�� ����� ������������ ������" << endl;
				goto back;
			}
			for (int i = 0; i < number.length(); i++)
			{
				if (incorrect_symbol[i] == '.')
				{
					is_incorrect_symbols = true;
					cout << "������� ����� ���������� ������� ����� �������" << endl;
					break;
				}
				if (incorrect_symbol[i] < 48 || incorrect_symbol[i] > 57)
				{
					is_incorrect_symbols = true;
					cout << "�� ����� ������������ ������" << endl;
					break;
				}				
			}					
		} while (is_incorrect_symbols);
		double new_number_type = atof(number.c_str());
		return new_number_type;
	}
}