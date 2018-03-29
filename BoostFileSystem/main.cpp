#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <map>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/find.hpp>
#include <boost/algorithm/string/join.hpp>
#include <boost/regex.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "DatePatterns.h"

using namespace boost::filesystem;
using namespace boost::gregorian;
const boost::regex txt_filter(".*\.txt$");
const boost::regex date_filter("[\d\.]{4,}");
//^Matches found.*(?= \()
const boost::regex frequency_line(R"(^Matches found.*?(?= \())");
//const boost::regex frequency_line("^Matches found.*(?= \\()");
int db_occurence_count = 0;

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

std::vector<std::string> get_dates();

int main(int argc, char* argv[]) {

    if (argc < 3) {
        show_usage(argv[0]);
        return 1;
    }

    path p( argc > 1 ? argv[1] : ".");
    std::string search_string = argv[2];
    std::vector<directory_entry> v; // To save all the .txt file names in a vector.
    std::vector<path> matching_files;
    std::map<std::string, std::string> *results_container = new std::map<std::string, std::string>();

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
            std::set<std::string> *frequency_data_lines = new std::set<std::string>;
            std::string current_frequency_line;
            int search_hits = 0;

            //generate the regex for matching the full pathogen names and octaves
            //e.g. abdominal .*\(octave #\d\)
            boost::regex full_name_octave(std::string(search_string).append(" .*?\(octave #\d\)"), boost::regex_constants::perl | boost::regex::icase);

            //std::cout << std::string(search_string).append(".*?\(octave #\\d\)") << std::endl;

            if (*file) {

                std::string *content = new std::string((std::istreambuf_iterator<char>(*file)), std::istreambuf_iterator<char>());
                boost::iterator_range<std::string::const_iterator> search_range_iterator = boost::ifind_first(*content, search_string);

                delete content;

                if (search_range_iterator) {
                    db_occurence_count++;
                } else {
                    delete file;
                    delete frequency_data_lines;

                    continue;
                }

                file->clear();
                file->seekg(0);

                for (std::string str; std::getline(*file, str);) {

                    boost::smatch match;

                    if(boost::regex_search(str, match, frequency_line)) {
                        current_frequency_line = match[0];
                    }

                    boost::iterator_range<std::string::const_iterator> rng;
                    rng = boost::ifind_first(str, search_string);

                    if(rng) {
                        search_hits++;
                        frequency_data_lines->insert(current_frequency_line);
                    }

                    boost::smatch octave_match;

                    if(boost::regex_match(str, octave_match, full_name_octave)) {
                        //frequency_data_lines->insert(octave_match[0]);
                    }

                }

                if (search_hits > 0) {
                    std::cout << matching_files[i].string() << std::endl;

                    for (std::set<std::string>::iterator it = frequency_data_lines->begin(); it != frequency_data_lines->end(); ++it) {
                        std::cout << *it << std::endl;
                    }
                    std::cout << std::endl;
                }

                delete file;
                delete frequency_data_lines;
            }

        }

        std::cout << std::endl;
        std::cout << "Number of databases, containing the match: " << db_occurence_count << std::endl;
        std::cout << std::endl;

    }

    delete results_container;

    return 0;
}
