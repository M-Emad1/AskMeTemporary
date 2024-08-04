#include "HelperFunction.h"


std::vector<std::string> HelperFunction::read_line_from_file(std::string path) {
    // Read all lines from any file in the system and return a vector of files.
    std::vector<std::string> lines;
    std::fstream file(path.c_str());

    if (file.fail()) {
        std::cerr << "\n\nERROR: Can't open the file\n\n";
        return lines;
    }

    std::string line;
    while (getline(file, line)) {
        if ((int)line.size() == 0)
            continue;
        lines.push_back(line);
    }

    file.close();
    return lines; // return a vector of files.
}

void HelperFunction::write_line_on_file(std::string path, std::vector<std::string> lines, bool append) const {
    std::ios_base::openmode statue = std::ios::in | std::ios::out | std::ios::app; // append

    if (!append)
        statue = std::ios::in | std::ios::out | std::ios::trunc; // overwrite

    std::fstream file(path.c_str(), statue);

    if (file.fail()) {
        std::cerr << "\n\nERROR: Can't open the file\n\n";
        return;
    }

    for (const auto& line : lines)
        file << line << '\n';

    file.close();
}

std::vector<std::string> HelperFunction::split_string(std::string line, char delimiter) {
    // split line from a file to vector of string.
    std::vector<std::string> fields;
    std::string s = line;
    int pos = 0;
    std::string substr;

    while ((pos = (int)s.find(delimiter)) != -1) {
        substr = s.substr(0, pos);
        fields.push_back(substr);
        s.erase(0, pos + 1);
    }

    fields.push_back(s);
    return fields;
}

int HelperFunction::to_int(std::string str) {
    // read number from line from any file and return it.
    std::istringstream iss(str);
    int number;
    iss >> number;
    return number;
}
