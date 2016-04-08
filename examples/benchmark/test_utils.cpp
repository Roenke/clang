#include "test_utils.h"

#include <stdexcept>
#include <boost/optional.hpp>

std::vector<char> read_whole_file()
{
    std::vector<char> data;

    FILE* f = fopen("libstdc++-4.9.txt", "rb");
//    if (!f)
//        throw std::runtime_error("can not open file");

    fseek(f, 0, SEEK_END);
    data.resize(ftell(f));
    fseek(f, 0, SEEK_SET);

    fread(data.data(), 1, data.size(), f);

    fclose(f);
    return data;
}

boost::optional<std::vector<char>> read_whole_file_if_exists()
{
    std::vector<char> data;
    FILE* f = fopen("libstdc++-4.9.txt", "rb");
//    FILE* f = fopen(filename.string().c_str(), "rb");
    if (!f)
    {
        if (errno == ENOENT)
            return boost::none;

//        throw std::runtime_error("can not open file");
    }

    fseek(f, 0, SEEK_END);
    data.resize(ftell(f));
    fseek(f, 0, SEEK_SET);

    fread(data.data(), 1, data.size(), f);

    fclose(f);
    return data;
}

void write_string_screened(std::ostream& os, std::string const& str)
{
    for (char c : str)
    {
        if (c >= ' ' && c < 0x7f)
            os << c;
        else
        {
            unsigned char uc = (unsigned char)c;
            os << std::hex << "\\x" << uc;
        }
    }
}

void write_entire_file(std::string const& data)
{
//    FILE* f = fopen(filename.string().c_str(), "wb");
//    if (!f)
//        throw std::runtime_error("can not open file");

//    fwrite(data.data(), 1, data.size(), f);

//    fclose(f);
}
