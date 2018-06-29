#ifndef HASHMAP_H
#define HASHMAP_H

#include <cstdint>
#include <vector>
#include <array>
#include <string>

#include "HashMapNode.h"

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int (*Hashmap_compare)(std::string a, std::string b);
typedef uint32_t (*Hashmap_hash)(std::string a);
typedef int (*Hashmap_traverse_cb) (HashMapNode *node);

class HashMap
{
public:
    HashMap(Hashmap_compare compare, Hashmap_hash hash);
    std::array<std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS>*, DEFAULT_NUMBER_OF_BUCKETS> *buckets;
    int setNode(std::string key, std::string data);
    int getNode(uint32_t hash, std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket, std::string key);
    std::string get(std::string key);
    void deleteNode(std::string key);
    int traverse(Hashmap_traverse_cb traverse_cb);
    Hashmap_compare compare;
    Hashmap_hash hash;
    std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *find_bucket(std::string key, uint32_t *hash_out);
    ~HashMap();
};

uint32_t default_hash(std::string a);
int default_compare(std::string a, std::string b);

#endif // HASHMAP_H
