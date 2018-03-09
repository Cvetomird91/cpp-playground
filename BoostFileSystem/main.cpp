#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <boost/filesystem.hpp>

using namespace boost::filesystem;

int main(int argc, char* argv[])
{
    path p( argc > 1 ? argv[1] : ".");
    std::vector<directory_entry> v; // To save the file names in a vector.

    if(is_directory(p))
    {
        copy(directory_iterator(p), directory_iterator(), back_inserter(v));
        std::cout << p << " is a directory containing:\n";

        for ( std::vector<directory_entry>::const_iterator it = v.begin(); it != v.end();  ++ it )
        {
            std::cout<< it->path().string() << std::endl;
        }
    }

    return 0;
}
