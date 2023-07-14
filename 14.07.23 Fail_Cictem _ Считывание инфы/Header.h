#pragma once

#ifndef  _HEADER_H_
#define _HEADER_H_

#include<iostream>
#include<fstream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>

struct Record
{
	int id;
	std::wstring name;
	char sex;
	int peopleCount;
};


std::vector<Record> ReadDB()
{
	std::vector<Record>result;
	std::wifstream inf("russian_names.csv"); // wifstream поток файлового кода с двубайтовыми символами  w - это сокращение от слова whise- Ширина
	if (!inf.is_open())
	{
		throw 1;// Кидает исключение В случае ошибки прервать функцию
	}
	else
	{
		std::wstring tmp; // Создаем хранилище данных из строки
		std::getline(inf, tmp, L'\n');// 
		while (!inf.eof())
		{
			Record temp{}; // Принимает нулевые значения( Можно их в Record не писать) Как конструктор по умолчанию Это тоже самое temp = Record();			
			std::getline(inf, tmp, L'\n');
			std::getline(inf, temp.name, L'\n'); // Считали имя и записали его во временную переменную
			std::getline(inf, tmp, L'\n');
			temp.sex = (tmp == L"M") ? true : false; // Проверка
			std::getline(inf, tmp, L'\n'); // считываем элемент
			temp.peopleCount = std::stoi(tmp); // Обработка stoi - работает со всеми классами строк atoi - работает только с однобайтовыми символами.
			std::getline(inf, tmp, L'\n'); // считываем элемент
			std::getline(inf, tmp, L'\n');
			result.push_back(temp);
		}

	}
	inf.close();

 return std::move(result);
}

bool print_file(std::string file_path);







#endif // ! _HEADER_H_