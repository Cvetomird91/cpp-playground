#include "HashMapNode.h"

HashMapNode::HashMapNode(int hash, std::string key, std::string data) : key(key), data(data), hash(hash)
{

}

HashMapNode::HashMapNode() : key(0), data(0), hash(0)
{

}
