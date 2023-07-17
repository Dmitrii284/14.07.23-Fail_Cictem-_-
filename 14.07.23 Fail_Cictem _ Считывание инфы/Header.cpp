#include "Header.h"

bool print_file(std::string file_path)
{
	std::ifstream in(file_path);
	if (in.is_open())
	{
		std::cout << "Файл открыт для считывания\n";
		std::string str;
		/*while (std::getline(in, str))
			file_path += str + '\n';*/
		std::cout << file_path;
		return true;
	}
	else
		std::cout << "Ошибка открытия файла!\n";
			in.close();
		
	return false;
}