#include <iostream>

#include "HashMap.h"
#include "HashMapNode.h"

using namespace std;

int main()
{
    HashMap *myMap = new HashMap(default_compare, default_hash);
    uint32_t hash_out;

    std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket = myMap->find_bucket("1", &hash_out);

    std::cout << myMap->buckets->front() << std::endl;
    std::cout << myMap->buckets->front() << std::endl;
    std::cout << myMap->buckets->front() << std::endl;
    std::exit(0);

    std::string *key1 = new std::string("asd");
    std::string *key2 = new std::string("fgh");
    std::string *key3 = new std::string("jkl");
    std::string *key4 = new std::string("zxc");
    std::string *key5 = new std::string("vbn");

    std::string *val1 = new std::string("asd");
    std::string *val2 = new std::string("fgh");
    std::string *val3 = new std::string("jkl");
    std::string *val4 = new std::string("zxc");
    std::string *val5 = new std::string("vbn");

    myMap->setNode(*key1, *val1);

    delete myMap, key1, key2, key3, key4, key5;
    delete val1, val2, val3, val4, val5;

    return 0;
}
