#include "Checking_is_numbers_happy.hpp"
#include <algorithm>
#include <iterator>

std::vector<happy_number_result> convert_unchecked_numbers_to_checked(const std::vector<size_t>& numbers) {
    std::vector<happy_number_result> checked_numbers;
    checked_numbers.reserve(numbers.size() * sizeof(happy_number_result));
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(checked_numbers), happy_number_result::check_is_number_happy);
    return checked_numbers;
}