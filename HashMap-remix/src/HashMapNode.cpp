#include "HashMapNode.h"

HashMapNode::HashMapNode(int hash, std::string key, std::string data)
{
    this->key = key;
    this->data = data;
    this->hash = hash;
}

HashMapNode::HashMapNode() {

}
