#include "Header.h"

bool print_file(std::string file_path)
{
	std::ifstream in(file_path);
	if (in.is_open())
	{
		std::cout << "���� ������ ��� ����������\n";
		std::string str;
		/*while (std::getline(in, str))
			file_path += str + '\n';*/
		std::cout << file_path;
		return true;
	}
	else
		std::cout << "������ �������� �����!\n";
			in.close();
		
	return false;
}