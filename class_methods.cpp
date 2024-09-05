#include "class.hpp"

int MainClass::get_random_int(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void MainClass::init_random_vectors(int min, int max)
{
	for (size_t i = 0; i < vector1.size(); i++)
		vector1.at(i) = get_random_int(min, max); //���� ���� ����������� ���������� �� ������ ��������� ��������� �����
	
	for (size_t i = 0; i < vector2.size(); i++)
		vector2.at(i) = get_random_int(min, max);
}

void MainClass::print_vectors()
{
	std::cout 
		<< "\n--------------------------------------\n"
		<< "������ 1: ";
	for (size_t i = 0; i < vector1.size(); i++)
		std::cout << vector1.at(i) << " ";
	std::cout << std::endl;

	std::cout << "������ 2: ";
	for (size_t i = 0; i < vector2.size(); i++)
		std::cout << vector2.at(i) << " ";

	std::cout
		<< std::endl
		<< "--------------------------------------\n\n";
}

int MainClass::vector_number_check(int vector_number)
{
	return ((vector_number == 1 or vector_number == 2)?(1):(0));
}

int MainClass::return_min(int vector_number)
{
	if (vector_number == 1)
		return *std::min_element(begin(vector1), end(vector1));

	else if (vector_number == 2)
		return *std::min_element(begin(vector2), end(vector2));
}

int MainClass::return_max(int vector_number)
{
	if (vector_number == 1)
		return *std::max_element(begin(vector1), end(vector1));

	else if (vector_number == 2)
		return *std::max_element(begin(vector2), end(vector2));
}

void MainClass::swap_min_max(int min_number)
{
	if (min_number == 1)
	{
		unsigned int min_index = *std::find(begin(vector1), end(vector1), return_min(1)); //���� ���. ��������� ������ ������, ����� ������ �������
		unsigned int max_index = *std::find(begin(vector2), end(vector2), return_max(2)); //���� ���. ��������� ������ ������, ����� ������ �������

		int temp_min = vector1.at(min_index);
		int temp_max = vector2.at(max_index);

		vector1.at(min_index) = temp_max;
		vector2.at(max_index) = temp_min;
	}

	else if (min_number == 2)
	{
		unsigned int min_index = *std::find(begin(vector2), end(vector2), return_min(2)); //���� ���. ��������� ������ ������, ����� ������ �������
		unsigned int max_index = *std::find(begin(vector1), end(vector1), return_max(1)); //���� ���. ��������� ������ ������, ����� ������ �������

		int temp_min = vector2.at(min_index);
		int temp_max = vector1.at(max_index);

		vector2.at(min_index) = temp_max;
		vector1.at(max_index) = temp_min;
	}
}

void MainClass::loop()
{
	int answer{};
	do
	{
		print_vectors();

		std::cout
			<< "��� ������?\n\n"
			<< "1) ���� ����������� �����!\n"
			<< "2) ���� ������������ �����!\n"
			<< "3) ������ ����������� ����� �� ������������!\n"
			<< "4) ������� (\n\n"
			<< "�����: ";

		std::cin >> answer;

		switch (answer)
		{
		case(MIN):
			int vector_min_number;
			std::cout << "����� ����� �������: ";
			std::cin >> vector_min_number;

			if (vector_number_check(vector_min_number))
				std::cout << "����������� ����� � ������� " << vector_min_number << " -- " << return_min(vector_min_number) << std::endl;
			
			else std::cout << "�������� ����� �������!\n\n";
			
			break;

		case(MAX):
			int vector_max_number;
			std::cout << "����� ����� �������: ";
			std::cin >> vector_max_number;

			if (vector_number_check(vector_max_number))
				std::cout << "������������ ����� � ������� " << vector_max_number << " -- " << return_max(vector_max_number) << std::endl;
			
			else std::cout << "�������� ����� �������!\n\n";

			break;

		case(SWAP):
			int min_number;
			std::cout << "����� ����� �������, � ������� ��������� ����������� �����: ";
			std::cin >> min_number;

			if (vector_number_check(min_number))
			{
				swap_min_max(min_number);
				std::cout << "������!\n";
			}

			else std::cout << "�������� ����� �������!\n\n";

			break;

		case(EXIT):
			std::cout << "�� �������!";
			break;

		default:
			std::cout << "�������� ������!\n\n";
		}
	} while (answer != EXIT);
}

void MainClass::run()
{
	srand(time(0));
	setlocale(0, "");

	init_random_vectors(-10, 10);

	loop();
}