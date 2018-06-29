#ifndef HASHMAPNODE_H
#define HASHMAPNODE_H

#include <cstdint>
#include <string>

typedef int (*Hashmap_compare)(std::string a, std::string b);
typedef uint32_t (*Hashmap_hash)(std::string key);

class HashMapNode
{
public:
    HashMapNode(int hash, std::string key, std::string data);
    HashMapNode();
    //HashMapNode( const HashMapNode &other);  // copy constructor
    //HashMapNode operator=(const HashMapNode &other);
    std::string key;
    std::string data;
    uint32_t hash;
};

#endif // HASHMAPNODE_H
