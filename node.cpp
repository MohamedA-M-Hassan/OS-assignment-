#include "node.h"
node :: node(processes d){proc = d; next = nullptr; }
void node::setData(processes d) { proc = d; }
processes node:: get_Data(){ return proc; }
void node::setNext(node* n) { next = n; }
node* node::getNext() { return next; }