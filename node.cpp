#include "node.hpp"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

Node::Node(){
}
Node::Node(Person persona){
}
Node::~Node(){
}
Person Node::getValue(){
}
Node* Node::getNext(){
}
void Node::setValue(Person persona){
}
void Node::setNext(Node* next){
}
bool Node::hasNext(){
}
