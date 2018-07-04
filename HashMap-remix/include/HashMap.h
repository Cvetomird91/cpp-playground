#ifndef HASHMAP_H
#define HASHMAP_H

#include <string>
#include <array>

#include "HashMapNode.h"

#define DEFAULT_NUMBER_OF_BUCKETS 100

typedef int (*Hashmap_compare) (std::string a, std::string b);
typedef uint32_t (*Hashmap_hash) (std::string key);
typedef int (*Hashmap_traverse_cb) (HashMapNode *node);

class HashMap
{
    public:
        HashMap();
        HashMap(Hashmap_compare compare, Hashmap_hash hash);
        Hashmap_compare compare;
        Hashmap_hash    hash;
        //std::array<HashMapNode*, DEFAULT_NUMBER_OF_BUCKETS> *buckets;
        HashMapNode *buckets;
        HashMapNode *findBucket(std::string key, uint32_t* hash_out);
        void setNode(std::string key, std::string data);
        HashMapNode* getNode(uint32_t hash, std::string key);
        HashMapNode* getNode(std::string key);
        std::string getData(std::string key);
        int traverse(Hashmap_traverse_cb traverse_cb);
        std::string deleteNode(std::string key);
        ~HashMap();
};

#endif // HASHMAP_H

int default_compare(std::string a, std::string b);
uint32_t default_hash(std::string key);
