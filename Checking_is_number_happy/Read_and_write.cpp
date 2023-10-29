#include "Read_and_write.hpp"
#include "Constants.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

static const size_t ASCII_code_of_number_0 = 48, ASCII_code_of_null_terminator = 0;

size_t find_natural_number(const std::string& str) {
    size_t number = 0;
    for (char str_element : str) {
        size_t digit = static_cast<size_t>(str_element);
        if ((digit < ASCII_code_of_number_0) || (digit >= ASCII_code_of_number_0 + dimension_of_system)) {
            if (digit != ASCII_code_of_null_terminator) {
                throw std::invalid_argument("Invalid string");
            }
            break;
        }
        digit -= ASCII_code_of_number_0;
        number = number * dimension_of_system + digit;
    }
    if (number == 0) {
        throw std::invalid_argument("0 isn't natural number");
    }
    return number;
}

std::vector<size_t> read_natural_numbers_from_istream(std::istream& input_stream) {
    std::string str;
    std::vector<size_t> numbers;
    while (!input_stream.eof()) {
        getline(input_stream, str);
        try {
            numbers.push_back(find_natural_number(str));
        }
        catch (std::invalid_argument) {

        }
    }
    return numbers;
}

void write_numbers_and_their_happiness_to_ostream(const std::vector<happy_number_result>& array_of_checked_numbers, std::ostream& output_stream) {
    for (happy_number_result checked_number : array_of_checked_numbers) {
        output_stream << checked_number.get_num() << " - " << std::boolalpha << checked_number.is_happy() << std::endl;
    }
}