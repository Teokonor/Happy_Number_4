#include "pch.h"
#include "Read_and_write.hpp"
#include "Checking_is_numbers_happy.hpp"
#include <iostream>
#include <fstream>



// Группа тестов для проверки, что программа считывает числа только с идеально чистых строк и игнорирует невалидные строки

TEST(Eliminate_invalid_strings, empty_string) {
	std::string str;
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}

TEST(Eliminate_invalid_strings, 14) {
	std::string str("14");
	EXPECT_EQ(find_natural_number(str), 14);
}

TEST(Eliminate_invalid_strings, minus9) {
	std::string str("-9");
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}

TEST(Eliminate_invalid_strings, __8) {
	std::string str("  8");
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}

TEST(Eliminate_invalid_strings, 9_) {
	std::string str("9 ");
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}

TEST(Eliminate_invalid_strings, a28b) {
	std::string str("a28b");
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}

TEST(Eliminate_invalid_strings, t_eryeh__tjcfj) {
	std::string str("t eryeh_ tjcfj");
	EXPECT_THROW(find_natural_number(str), std::invalid_argument);
}




// Группа тестов для проверки считывания данных из потока ввода (здесь из файлового потока)

TEST(Reading_file, empty_file) {
	std::ofstream my_file("MyFile.txt");
	my_file.close();
	std::ifstream input_file("MyFile.txt");
	std::istream& input_stream = static_cast<std::istream&>(input_file);
	std::vector<size_t> readed_vector = read_natural_numbers_from_istream(input_stream);
	input_file.close();
	EXPECT_EQ(readed_vector.size(), 0);
}

TEST(Reading_file, many_valid_and_invalid_strings) {
	/* Ниже указано содержимое создаваемого файла (после 25 стоит несколько пробелов)

	12
	a84
	  8
	25
	sdfb

	29.
	42
	43 01
	-10


	0
	7
	Валидными являются строки с числами 12, 42, 7 */
	std::ofstream my_file("MyFile.txt");
	my_file << "\n12\na84\n  8\n25   \nsdfb\n\n29.\n42\n43 01\n-10\n\n\n0\n7";
	my_file.close();
	std::ifstream input_file("MyFile.txt");
	std::istream& input_stream = static_cast<std::istream&>(input_file);
	std::vector<size_t> readed_vector = read_natural_numbers_from_istream(input_stream);
	input_file.close();
	EXPECT_EQ(readed_vector.size(), 3);
	EXPECT_EQ(readed_vector[0], 12);
	EXPECT_EQ(readed_vector[1], 42);
	EXPECT_EQ(readed_vector[2], 7);
}

TEST(Reading_file, every_strings_are_invalid) {
	/* Ниже указано содержимое создаваемого файла (после 25 стоит несколько пробелов)

	a84
	  8
	25
	sdfb

	29.
	43 01
	-10


	0
	*/
	std::ofstream my_file("MyFile.txt");
	my_file << "\na84\n  8\n25   \nsdfb\n\n29.\n43 01\n-10\n\n\n0";
	my_file.close();
	std::ifstream input_file("MyFile.txt");
	std::istream& input_stream = static_cast<std::istream&>(input_file);
	std::vector<size_t> readed_vector = read_natural_numbers_from_istream(input_stream);
	input_file.close();
	EXPECT_EQ(readed_vector.size(), 0);
}

TEST(Reading_file, every_strings_are_valid) {
	/* Ниже указано содержимое создаваемого файла
	12
	42
	7
	*/
	std::ofstream my_file("MyFile.txt");
	my_file << "12\n42\n7";
	my_file.close();
	std::ifstream input_file("MyFile.txt");
	std::istream& input_stream = static_cast<std::istream&>(input_file);
	std::vector<size_t> readed_vector = read_natural_numbers_from_istream(input_stream);
	input_file.close();
	EXPECT_EQ(readed_vector.size(), 3);
	EXPECT_EQ(readed_vector[0], 12);
	EXPECT_EQ(readed_vector[1], 42);
	EXPECT_EQ(readed_vector[2], 7);
}


// Группа тестов для проверки вывода результатов в поток вывода (здесь в файловый поток)

TEST(Writing_file, 0_elements) {
	std::vector<happy_number_result> our_vect = { };
	std::ofstream output_file("MyFile.txt");
	std::ostream& output_stream = static_cast<std::ostream&>(output_file);
	write_numbers_and_their_happiness_to_ostream(our_vect, output_stream);
	output_file.close();
	std::ifstream my_file("MyFile.txt");
	std::string str;
	std::getline(my_file, str);
	EXPECT_EQ(str.size(), 0);
	my_file.close();
}

TEST(Writing_file, 1_element) {
	std::vector<happy_number_result> our_vect = convert_unchecked_numbers_to_checked({ 111 });
	std::ofstream output_file("MyFile.txt");
	std::ostream& output_stream = static_cast<std::ostream&>(output_file);
	write_numbers_and_their_happiness_to_ostream(our_vect, output_stream);
	output_file.close();
	std::ifstream my_file("MyFile.txt");
	std::string str, str1("111 - false");
	std::getline(my_file, str);
	EXPECT_TRUE(str == str1);
	my_file.close();
}

TEST(Writing_file, 10_elements) {
	// 1 3 4 7 10 12 15 23 44 111
	std::vector<happy_number_result> our_vect = convert_unchecked_numbers_to_checked({ 1, 3, 4, 7, 10, 12, 15, 23, 44, 111 });
	std::ofstream output_file("MyFile.txt");
	std::ostream& output_stream = static_cast<std::ostream&>(output_file);
	write_numbers_and_their_happiness_to_ostream(our_vect, output_stream);
	output_file.close();
	std::ifstream my_file("MyFile.txt");
	std::string str, str1("1 - true");
	std::vector<std::string> strs = { "1 - true", "3 - false", "4 - false", "7 - true", "10 - true",
									   "12 - false", "15 - false", "23 - true", "44 - true", "111 - false" };
	for (int index_in_vector_of_strings = 0; index_in_vector_of_strings < 10; index_in_vector_of_strings++) {
		std::getline(my_file, str);
		EXPECT_TRUE(str == strs[index_in_vector_of_strings]);
	}
	my_file.close();
}
