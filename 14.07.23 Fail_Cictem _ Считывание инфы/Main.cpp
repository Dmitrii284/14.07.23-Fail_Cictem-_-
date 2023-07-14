#include"Header.h"
#include<direct.h>
#include <stdio.h>

int main()
{

	setlocale(LC_ALL, "Rus");

	char sym = 0, file_name = 0;
	
	std::string path = "russian_names.csv";

	// Проверка файла на открытие с помощью метода .is_open()
	print_file(path);


	return 0;
}