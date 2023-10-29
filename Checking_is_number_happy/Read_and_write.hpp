#pragma once
#include "Happy_number_result.hpp"
#include <vector>
#include <string>

size_t find_natural_number(const std::string& str);

std::vector<size_t> read_natural_numbers_from_istream(std::istream& input_stream);

void write_numbers_and_their_happiness_to_ostream(const std::vector<happy_number_result>& num_res, std::ostream& output_stream);