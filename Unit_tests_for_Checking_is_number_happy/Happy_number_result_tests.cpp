#include "pch.h"
#include "Happy_number_result.hpp"



// Группа тестов для проверки, что программа корректно определяет, счастливое число или нет

TEST(Check_one_number, 0_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(0);
	EXPECT_FALSE(number.is_happy());
}

TEST(Check_one_number, 1_is_true) {
	happy_number_result number = happy_number_result::check_is_number_happy(1);
	EXPECT_TRUE(number.is_happy());
}

TEST(Check_one_number, 3_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(3);
	EXPECT_FALSE(number.is_happy());
}

TEST(Check_one_number, 4_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(4);
	EXPECT_FALSE(number.is_happy());
}

TEST(Check_one_number, 7_is_true) {
	happy_number_result number = happy_number_result::check_is_number_happy(7);
	EXPECT_TRUE(number.is_happy());
}

TEST(Check_one_number, 10_is_true) {
	happy_number_result number = happy_number_result::check_is_number_happy(10);
	EXPECT_TRUE(number.is_happy());
}

TEST(Check_one_number, 12_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(12);
	EXPECT_FALSE(number.is_happy());
}

TEST(Check_one_number, 15_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(15);
	EXPECT_FALSE(number.is_happy());
}

TEST(Check_one_number, 23_is_true) {
	happy_number_result number = happy_number_result::check_is_number_happy(23);
	EXPECT_TRUE(number.is_happy());
}

TEST(Check_one_number, 44_is_true) {
	happy_number_result number = happy_number_result::check_is_number_happy(44);
	EXPECT_TRUE(number.is_happy());
}

TEST(Check_one_number, 111_is_false) {
	happy_number_result number = happy_number_result::check_is_number_happy(111);
	EXPECT_FALSE(number.is_happy());
}
