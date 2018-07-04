#ifndef HASHMAPNODE_H
#define HASHMAPNODE_H

#include <string>

class HashMapNode
{
    public:
        HashMapNode(int hash, std::string key, std::string data);
        HashMapNode();
        std::string key;
        std::string data;
        uint32_t hash;
};

#endif // HASHMAPNODE_H
