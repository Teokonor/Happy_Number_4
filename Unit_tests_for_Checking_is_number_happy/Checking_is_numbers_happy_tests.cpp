#include "pch.h"
#include "Checking_is_numbers_happy.hpp"




// Группа тестов для проверки, что программа правильно заполняет вектор чисел и результатов по ним

TEST(Check_many_numbers, 0numbers) {
	std::vector<size_t> vect1 = { };
	std::vector<happy_number_result> vect2 = convert_unchecked_numbers_to_checked(vect1);
	EXPECT_EQ(vect2.size(), 0);
}

TEST(Check_many_numbers, 1number) {
	const size_t vector_size = 1;
	std::vector<size_t> input_numbers = { 111 };
	std::vector<happy_number_result> result = convert_unchecked_numbers_to_checked(input_numbers);
	// Настоящее значение для 111: false. Проверим, так ли это в новом векторе vect2
	EXPECT_EQ(result.size(), vector_size);
	EXPECT_FALSE(result[0].is_happy());
}

TEST(Check_many_numbers, long_vector_with_numbers_from_first_test_group) {
	const size_t vector_size = 10;
	// 1 3 4 7 10 12 15 23 44 111
	std::vector<size_t> numbers = { 1, 3, 4, 7, 10, 12, 15, 23, 44, 111 };
	std::vector<bool> right_result = { true, false, false, true, true, false, false, true, true, false };
	std::vector<happy_number_result> result = convert_unchecked_numbers_to_checked(numbers);
	EXPECT_EQ(result.size(), vector_size);
	for (size_t index_in_vectors = 0; index_in_vectors < vector_size; index_in_vectors++) {
		EXPECT_EQ(numbers[index_in_vectors], result[index_in_vectors].get_num());
		EXPECT_EQ(right_result[index_in_vectors], result[index_in_vectors].is_happy());
	}
}
