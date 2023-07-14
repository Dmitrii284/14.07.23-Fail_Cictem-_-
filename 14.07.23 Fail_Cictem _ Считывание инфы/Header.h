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
	std::wifstream inf("russian_names.csv"); // wifstream ����� ��������� ���� � ������������ ���������  w - ��� ���������� �� ����� whise- ������
	if (!inf.is_open())
	{
		throw 1;// ������ ���������� � ������ ������ �������� �������
	}
	else
	{
		std::wstring tmp; // ������� ��������� ������ �� ������
		std::getline(inf, tmp, L'\n');// 
		while (!inf.eof())
		{
			Record temp{}; // ��������� ������� ��������( ����� �� � Record �� ������) ��� ����������� �� ��������� ��� ���� ����� temp = Record();			
			std::getline(inf, tmp, L'\n');
			std::getline(inf, temp.name, L'\n'); // ������� ��� � �������� ��� �� ��������� ����������
			std::getline(inf, tmp, L'\n');
			temp.sex = (tmp == L"M") ? true : false; // ��������
			std::getline(inf, tmp, L'\n'); // ��������� �������
			temp.peopleCount = std::stoi(tmp); // ��������� stoi - �������� �� ����� �������� ����� atoi - �������� ������ � ������������� ���������.
			std::getline(inf, tmp, L'\n'); // ��������� �������
			std::getline(inf, tmp, L'\n');
			result.push_back(temp);
		}

	}
	inf.close();

 return std::move(result);
}

bool print_file(std::string file_path);







#endif // ! _HEADER_H_