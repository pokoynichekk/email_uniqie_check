#include <iostream>
#include <string>
#include <unordered_set>
#include <Windows.h>
#include <regex>

using namespace std;

bool CheckEmail(const std::string& str)
{
	return std::regex_match(str, std::regex("([\\w-\\.*]+)@((?:\\w+\\.)+)([a-zA-Z]{2,4})"));
}


int main()
{
	setlocale(LC_ALL, "Russian");
	unsigned int n;

	std::cout << "Количество адресов: ";
	std::cin >> n;

	std::string *emailAdress = new std::string[n];
	unordered_set<string> uniqAdresses;

	system("cls");

	std::cout << "Введите список адресов: \n";
	for (int i = 0; i < n; i++)
	{	
		while (true)
		{
			std::cin >> emailAdress[i];
			if (CheckEmail(emailAdress[i]))
			{
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(32767, '\n');
				std::cout << "Некорректный ввод. \n";
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < sizeof(emailAdress[i]); j++)
		{
			if (emailAdress[i][j] == '*')
			{
				emailAdress[i].erase(emailAdress[i].find_first_of('*'), 
					(emailAdress[i].find('@') - emailAdress[i].find('*')));
			}
			if (emailAdress[i][j] == '.')
			{
				emailAdress[i].erase(j, 1);
			}
			if (emailAdress[i][j] == '@')
			{
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		uniqAdresses.insert(emailAdress[i]);
	}

	std::cout << "Количество уникальных адресов = " << uniqAdresses.size();

	delete [] emailAdress;
}


