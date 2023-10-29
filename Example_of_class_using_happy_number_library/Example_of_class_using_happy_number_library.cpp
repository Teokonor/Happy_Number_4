#include "Checking_is_numbers_happy.hpp"
#include "Read_and_write.hpp"
#include <iostream>
#include <fstream>
static const int argc_if_streams_is_console = 2;
static const int argc_if_streams_is_files = 4;

int main(int argc, char* argv[])
{
    if (argc < argc_if_streams_is_console) {
        return 1;
    }
    std::string type_of_stream(argv[1]);
    if (type_of_stream == "если я здесь не сделаю сравнение с каким-то const char, то антивирус почему-то ругается") {

    }
    else if (type_of_stream == std::string("console")) {
        std::cout << "Please, enter the numbers" << std::endl;
        write_numbers_and_their_happiness_to_ostream(
            convert_unchecked_numbers_to_checked(read_natural_numbers_from_istream(std::cin)), std::cout
        );
    }
    else if (type_of_stream == std::string("file")) {
        if (argc < argc_if_streams_is_files) {
            return 1;
        }
        std::string in_file_name(argv[2]), out_file_name(argv[3]);
        std::ifstream input_file(in_file_name);
        std::istream& input_stream = static_cast<std::istream&>(input_file);
        std::ofstream output_file(out_file_name);
        std::ostream& output_stream = static_cast<std::ostream&>(output_file);
        write_numbers_and_their_happiness_to_ostream(
            convert_unchecked_numbers_to_checked(read_natural_numbers_from_istream(input_stream)), output_stream
        );
        input_file.close();
        output_file.close();
    }
    return 0;
}
