#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost::filesystem;
using namespace boost::gregorian;
const boost::regex txt_filter(".*\.txt$");
const boost::regex date_filter("[\d\.]{4,}");
const boost::regex frequency_line("^Matches found.*$");
int occurence_count;

/*
 * Possible date conventions:
    - 0505
    - 20170505
    - 02.05.2017
    - 14.05.17
    - 02052017
 *
 */

void show_usage(std::string name) {
    std::cerr << "Usage: " << name << " <path> <search-string>\n" << std::endl;
}

void show_result(std::vector<path> p) {

}

int main(int argc, char* argv[]) {

    if (argc < 3) {
        show_usage(argv[0]);
        return 1;
    }

    path p( argc > 1 ? argv[1] : ".");
    std::string search_string = argv[2];
    std::vector<directory_entry> v; // To save the file names in a vector.
    std::vector<path> matching_files;

    if(is_directory(p)) {
        copy(directory_iterator(p), directory_iterator(), back_inserter(v));

        for ( std::vector<directory_entry>::const_iterator it = v.begin(); it != v.end();  ++it )
        {
            if(!boost::filesystem::is_regular_file(it->status()))
                continue;

            boost::smatch watch;

            if(boost::regex_match(it->path().string(), watch, txt_filter)) {
                matching_files.push_back(it->path());
            }
        }

        for (unsigned int i = 0; i < matching_files.size(); i++) {
            std::ifstream *file = new std::ifstream(matching_files[i].string());

            if (*file) {
                std::string* str = new std::string((std::istreambuf_iterator<char>(*file)), std::istreambuf_iterator<char>());
                boost::iterator_range<std::string::const_iterator> rng;
                rng = boost::ifind_first(*str, search_string);

                if (rng) {
                    occurence_count++;
                    std::cout << matching_files[i].string() << std::endl;
                }

                delete str;
                file->close();
            }

            delete file;
        }

        std::cout << "Number of occurences: " << occurence_count << std::endl;
    }

    return 0;
}
