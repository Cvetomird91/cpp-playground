#include "HashMap.h"
#include "HashMapNode.h"

#include <string>
#include <vector>
#include <array>
#include <iostream>

uint32_t default_hash(std::string key) {
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

int default_compare(std::string a, std::string b) {
    return a == b;
}

HashMap::HashMap(Hashmap_compare compare, Hashmap_hash hash)
{
    this->compare = compare == NULL ? default_compare : compare;
    this->hash = hash == NULL ? default_hash : hash;
    this->buckets = new std::array<std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS>*, DEFAULT_NUMBER_OF_BUCKETS>();
}

std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *HashMap::find_bucket(std::string key, uint32_t *hash_out)
{
    uint32_t hash = this->hash(key);
    int bucket_n = hash % DEFAULT_NUMBER_OF_BUCKETS;
    *hash_out = hash;

    std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket = this->buckets->at(bucket_n);

    return bucket;
}

int HashMap::setNode(std::string key, std::string data)
{
    uint32_t hash = 0;
    std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket = this->find_bucket(key, &hash);
    HashMapNode *node = new HashMapNode(hash, key, data);
    //std::cout << bucket->size() << std::endl;
    //std::exit(0);
    //bucket[bucket->size()-1] = *node;
    bucket->back() = *node;

    return 0;
}

int HashMap::getNode(uint32_t hash, std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket, std::string key) {
    unsigned int i = 0;

    for (i = 0; i < bucket->size(); i++) {
        HashMapNode *node = &bucket->at(i);
        if(node->hash == hash && this->compare(node->key, key) == 0) {
            return i;
        }
    }

    return -1;

}

std::string HashMap::get(std::string key) {
    uint32_t hash = 0;
    std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket = this->find_bucket(key, &hash);
    if (!bucket) return NULL;

    int i = this->getNode(hash, bucket, key);
    if (i == -1) return NULL;

    HashMapNode *node = &bucket->at(i);

    return node->data;
}

int HashMap::traverse(Hashmap_traverse_cb traverse_cb) {
    unsigned int i = 0;
    int j = 0;
    int rc = 0;

    for (i = 0; i < this->buckets->size(); i++) {
        std::array<HashMapNode, DEFAULT_NUMBER_OF_BUCKETS> *bucket = this->buckets->at(i);
        if(bucket) {
            for (j = 0; j < bucket->size(); j++) {
                HashMapNode *node = &bucket->at(j);
                rc = traverse_cb(node);
                if (rc != 0)
                    return rc;
            }
        }
    }

    return 0;
}

HashMap::~HashMap() {
    delete this->buckets;
}
