#ifndef HASHMAPNODE_H
#define HASHMAPNODE_H

#include <cstdint>
#include <string>

typedef int (*Hashmap_compare)(void *a, void *b);
typedef uint32_t (*Hashmap_hash)(void *key);

class HashMapNode
{
public:
    HashMapNode(int hash, void *key, void *data);
    void *key;
    void *data;
    uint32_t hash;
};

#endif // HASHMAPNODE_H
