#pragma once
#include <stdc++.h>

class HelperFunction
{
public:
	std::vector<std::string> read_line_from_file(std::string path);
	void write_line_on_file(std::string path, std::vector<std::string> lines, bool append = false) const;
	std::vector<std::string> split_string(std::string line, char delimiter = ',');
	int to_int(std::string str);
};

