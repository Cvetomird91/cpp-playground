#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cstring>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

using namespace boost::filesystem;
const boost::regex txt_filter(".*\.txt$");

int main(int argc, char* argv[]) {

    path p( argc > 1 ? argv[1] : ".");
    std::vector<directory_entry> v; // To save the file names in a vector.
    std::vector<std::string> matching_files;

    if(is_directory(p)) {
        copy(directory_iterator(p), directory_iterator(), back_inserter(v));
        //std::cout << p << " is a directory containing:\n";

        for ( std::vector<directory_entry>::const_iterator it = v.begin(); it != v.end();  ++it )
        {
            if(!boost::filesystem::is_regular_file(it->status()))
                continue;

            boost::smatch watch;

            if(boost::regex_match(it->path().string(), watch, txt_filter))
                std::cout<< it->path().string() << std::endl;
        }
    }

    return 0;
}
