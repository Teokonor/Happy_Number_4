#pragma once

class happy_number_result final {
	size_t number;
	bool happy;
	happy_number_result(const size_t num, const bool happiness);
public:
	static happy_number_result check_is_number_happy(const size_t natural_num);
	size_t get_num() const;
	bool is_happy() const;
};
