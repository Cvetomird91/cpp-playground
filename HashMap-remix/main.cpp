#include <iostream>

#include <string>
#include <array>

#include "HashMap.h"
#include "HashMapNode.h"

using namespace std;

int main()
{
    HashMap *map = new HashMap(default_compare, default_hash);
    std::string *key1 = new std::string("asd");
    std::string *key2 = new std::string("fgh");
    std::string *key3 = new std::string("jkl");
    std::string *key4 = new std::string("zxc");
    std::string *key5 = new std::string("vbn");

    std::string *val1 = new std::string("my value");
    std::string *val2 = new std::string("fgh");
    std::string *val3 = new std::string("jkl");
    std::string *val4 = new std::string("zxc");
    std::string *val5 = new std::string("vbn");

    map->setNode(*key1, *val1);
    map->setNode(*key2, *val2);
    map->setNode(*key3, *val3);
    map->setNode(*key4, *val4);
    map->setNode(*key5, *val5);
    std::cout << map->getData("asd") << std::endl;
    std::cout << map->getData("fgh") << std::endl;
    std::cout << map->getData("jkl") << std::endl;
    std::cout << map->getData("omgomg") << std::endl;

    HashMapNode *node1 = map->getNode("asd");
    HashMapNode *node2 = map->getNode("fgh");
    HashMapNode *node3 = map->getNode("jkl");

    std::cout << node1->hash << std::endl;
    std::cout << node2->hash << std::endl;
    std::cout << node3->hash << std::endl;

    delete key1;
    delete key2;
    delete key3;
    delete key4;
    delete key5;

    delete val1;
    delete val2;
    delete val3;
    delete val4;
    delete val5;

    delete map;
}
