#include"Header.h"
#include<direct.h>
#include <stdio.h>

int main()
{

	setlocale(LC_ALL, "Rus");

	char sym = 0, file_name = 0;
	
	std::string path = "russian_names.csv";

	// �������� ����� �� �������� � ������� ������ .is_open()
	print_file(path);


	return 0;
}