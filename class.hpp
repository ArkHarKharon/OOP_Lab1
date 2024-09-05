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
		vector1.resize(10); //Ћень расписывать выбор длины векторов
		vector2.resize(10);
	}

	~MainClass() {};

	static int get_random_int(int min, int max);
	void init_random_vectors(int min, int max); 

	void print_vectors();

	int vector_number_check(int vector_number);
	int return_min(int vector_number); //номер вектора(1 или 2)
	int return_max(int vector_number);

	void swap_min_max(int min_number); //номер вектора, откуда берЄм минимальное значение

	void loop(); //основна€ диалогова€ петл€

	void run(); //точка входа
	
};