#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstdint>
#include <vector>
#include <array>

#include "HashMapNode.h"

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int (*Hashmap_compare)(void *a, void *b);
typedef uint32_t (*Hashmap_hash)(void *key);
typedef int (*Hashmap_traverse_cb) (HashMapNode *node);

class HashMap
{
public:
    HashMap(Hashmap_compare compare, Hashmap_hash hash);
    std::array<void*, DEFAULT_NUMBER_OF_BUCKETS> *buckets;
    int setNode(void *key, void *data);
    void getNode(void *key);
    void deleteNode(void *key);
    int traverse(Hashmap_traverse_cb traverse_cb);
    void destroy();
    Hashmap_compare compare;
    Hashmap_hash hash;
    void *find_bucket(void *key, int create, uint32_t *hash_out);
};

uint32_t default_hash(void *a);
int default_compare(void *a, void *b);

#endif // HASHMAP_H
