#pragma once
#include "includes.hpp"

class MainClass
{
private:
	std::vector<int> vector1;
	std::vector<int> vector2;

	enum Menu 
	{ 
		MIN = 1,
		MAX, 
		SWAP,
		EXIT
	};
public:
	MainClass() :vector1{}, vector2{}
	{
		vector1.resize(10); //���� ����������� ����� ����� ��������
		vector2.resize(10);
	}

	~MainClass() {};

	static int get_random_int(int min, int max);
	void init_random_vectors(int min, int max); 

	void print_vectors();

	int vector_number_check(int vector_number);
	int return_min(int vector_number); //����� �������(1 ��� 2)
	int return_max(int vector_number);

	void swap_min_max(int min_number); //����� �������, ������ ���� ����������� ��������

	void loop(); //�������� ���������� �����

	void run(); //����� �����
	
};