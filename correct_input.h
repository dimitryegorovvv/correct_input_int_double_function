#pragma once
// функции для проверка на ввод только чисел для int и double
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
			// очистка буфера ввода
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			// ввод символов
			getline(cin, number);
			// проверка на пробел или enter
			if (enter_and_backspace_check[0] == "" || enter_and_backspace_check[0] == " ")
			{
				cout << "Вы ввели некорректный символ" << endl;
				goto back;
			}
			// проверка на присутствие иных символов (не цифр)
			for (int i = 0; i < number.length(); i++)
			{
				if (incorrect_symbol[i] < 48 || incorrect_symbol[i] > 57)
				{
					is_incorrect_symbols = true;
					cout << "Вы ввели некорректный символ" << endl;
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
				cout << "Вы ввели некорректный символ" << endl;
				goto back;
			}
			for (int i = 0; i < number.length(); i++)
			{
				if (incorrect_symbol[i] == '.')
				{
					is_incorrect_symbols = true;
					cout << "Дробную часть необходимо вводить через запятую" << endl;
					break;
				}
				if (incorrect_symbol[i] < 48 || incorrect_symbol[i] > 57)
				{
					is_incorrect_symbols = true;
					cout << "Вы ввели некорректный символ" << endl;
					break;
				}				
			}					
		} while (is_incorrect_symbols);
		double new_number_type = atof(number.c_str());
		return new_number_type;
	}
}