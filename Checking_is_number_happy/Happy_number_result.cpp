#include "Happy_number_result.hpp"
#include "Constants.hpp"
#include <stdexcept>

static const size_t max_digit = 1000000000, min_digit = 1, remainder_of_happy_num = 1, remainder_of_unhappy_num = 4;

happy_number_result::happy_number_result(const size_t num, const bool happiness) : number(num), happy(happiness) {}

happy_number_result happy_number_result::check_is_number_happy(const size_t natural_num) {
    if (natural_num == 0) {
        return happy_number_result(natural_num, false);
    }
    size_t current_number = natural_num;
    while (true) {
        size_t converted_number = 0;
        for (size_t digit = max_digit; digit >= min_digit; digit /= dimension_of_system) {
            converted_number += (current_number / digit) * (current_number / digit);
            current_number -= current_number / digit * digit;
        }
        current_number = converted_number;
        if (current_number == remainder_of_happy_num) {
            return happy_number_result(natural_num, true);
        }
        if (current_number == remainder_of_unhappy_num) {
            return happy_number_result(natural_num, false);
        }
    }
}

size_t happy_number_result::get_num() const {
	return number;
}

bool happy_number_result::is_happy() const {
	return happy;
}
