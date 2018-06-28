#include "HashMap.h"
#include "HashMapNode.h"

#include <string>
#include <vector>

uint32_t default_hash(void *a) {
    std::string key = std::string((char*)a);
    size_t len = key.size();
    uint32_t hash = 0;
    uint32_t i = 0;

    for (hash = i = 0; i < len; ++i) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

int default_compare(void *a, void *b) {
    return std::string((char*)a) == std::string((char*)b);

}

HashMap::HashMap(Hashmap_compare compare, Hashmap_hash hash)
{
    this->compare = compare == NULL ? default_compare : compare;
    this->hash = hash == NULL ? default_hash : hash;
    this->buckets = new std::array<void*, DEFAULT_NUMBER_OF_BUCKETS>();
}

void HashMap::destroy() {

}

void *HashMap::find_bucket(void *key, int create, uint32_t *hash_out) {
    uint32_t hash = this->hash(key);
    int bucket_n = hash % DEFAULT_NUMBER_OF_BUCKETS;
    *hash_out = hash;

    void *bucket = this->buckets->at(bucket_n);

    if (!bucket && create) {

    }

    return bucket;
}
