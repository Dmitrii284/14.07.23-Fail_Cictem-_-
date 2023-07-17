#pragma once

// Графические игры WXVigetc  Графический SFML  все это графические редакторы.

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
	/*	* Способы открыть файл :
		* 1 std::getline(inf, tmp, L'\n');
		* 2 std::ofstream iof("", std::ios:: ntr)
		* 3 FILE file = fopen("", "r+"); - Это версия С обоснавать  почему так нужно.
		// Вывод: Варианты решения менее вадны чем следование аогоритмам
		*/
	if (!inf.is_open())
	{
		throw 1;// Кидает исключение В случае ошибки прервать функцию
	}
	else		
	{
		std::wstring tmp; // Создаем хранилище данных из строки
		std::getline(inf, tmp, L'\n');// В коде профигурировало "L" - Это Этап игнорирования первой точки
		while (!inf.eof())// Цикл с пред условием( А не закончился у нас файл)
			// Если данные были то мы их перетаскиваем в некую структуру Record temp{} следующим шагом
		{
			Record temp{}; // Принимает нулевые значения( Можно их в Record не писать) Как конструктор по умолчанию Это тоже самое temp = Record();			
			std::getline(inf, tmp, L'\n');

			std::getline(inf, temp.name, L'\n'); // Считали имя и записали его во временную переменную

			std::getline(inf, tmp, L'\n');
			temp.sex = (tmp == L"M") ? true : false; // Проверка ( Тут использовали тернарник (так как оно работает очевидно)
			// Но сам тернарник temp.sex = (tmp == L"M") ? true : false; делает более непонятный код ( Дибо иф элсе) или еще проще temp.sex = (tmp == L"M")
			// temp.sex = (tmp == L"M"); так как знак == это и ест булевое значение и оно вернет Булевое значнение (либо true или false)
			std::getline(inf, tmp, L'\n'); // считываем элемент
			temp.peopleCount = std::stoi(tmp); // Обработка stoi - работает со всеми классами строк atoi - работает только с однобайтовыми символами.
			std::getline(inf, tmp, L'\n'); // считываем элемент

			std::getline(inf, tmp, L'\n');// Просто добавили в коллекцию запись.

			result.push_back(temp);
		}

	}
	inf.close();

 return std::move(result);// Это ускорит немного передачу ( Сам алгоритм не поменяется)
}

bool print_file(std::string file_path);







#endif // ! _HEADER_H_