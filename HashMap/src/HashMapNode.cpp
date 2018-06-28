#include "HashMapNode.h"

HashMapNode::HashMapNode(int hash, void *key, void *data)
{
    this->key = key;
    this->data = data;
    this->hash = hash;
}
