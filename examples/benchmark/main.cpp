#include "clang/Lex/Lexer.h"
#include "test_utils.h"
#include <iostream>
#include <string.h>
#include <chrono>
//#include <boost/filesystem.hpp>
#include <boost/optional.hpp>

//namespace fs = boost::filesystem;

void bench_clang_lexer(std::string& input) {
    using namespace clang;

    const char* begin = input.c_str();

    Lexer lexer(SourceLocation(), LangOptions(), begin, begin, begin + input.size());

    Token tok;
    while(!lexer.LexFromRawLexer(tok)) {
//        std::cout << tok.getName() << std::endl;
    }

    std::cout << tok.getName() << std::endl;
}

template <typename T>
void accumulate_min(boost::optional<T>& accum, T const& newval)
{
    if (accum)
        *accum = std::min(*accum, newval);
    else
        accum = newval;
}

template <typename T>
void accumulate_max(boost::optional<T>& accum, T const& newval)
{
    if (accum)
        *accum = std::max(*accum, newval);
    else
        accum = newval;
}

void print_time(std::ostream& os, std::chrono::high_resolution_clock::duration dur)
{
    os << std::chrono::duration_cast<std::chrono::microseconds>(dur).count() << "us";
}

void run_test_on_file(/*fs::path const& filename*/)
{
    std::vector<char> input = read_whole_file();
    std::string filename;
    std::cout << filename << '\t' << input.size() << " bytes" << "\n\t";

    boost::optional<std::chrono::high_resolution_clock::duration> min, max;
    std::chrono::high_resolution_clock::duration sum{};

    std::string input_str(input.begin(), input.end());

    size_t const N = 100;
    for (size_t i = 0; i != N; ++i)
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        bench_clang_lexer(input_str);
//        lexer lex(input.data(), input.data() + input.size());
//        while (lex.tt() != token_type::eof)
//            lex.next();

        auto end_time = std::chrono::high_resolution_clock::now();
        auto dur = end_time - start_time;
        print_time(std::cout, dur);
        std::cout << '\t';

        accumulate_min(min, dur);
        accumulate_max(max, dur);
        sum += dur;
    }
    std::cout << "\n\tmin = ";
    print_time(std::cout, *min);
    std::cout << " max = ";
    print_time(std::cout, *max);
    std::cout << " avg = ";
    print_time(std::cout, sum / N);
    std::cout << " MB/s = " << (double)input.size() / std::chrono::duration_cast<std::chrono::microseconds>(sum).count() * N;
    std::cout << '\n';
}

int main()
{
    run_test_on_file();
//    for (fs::directory_iterator i = fs::directory_iterator("./performance_tests/"), end; i != end; ++i)
//        if (i->path().extension() == ".txt")
//            run_test_on_file(i->path());
}
