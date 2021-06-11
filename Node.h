#ifndef __NODE_H__
#define __NODE_H__

class Node {
	private:
		int elem;
		Node* next;
	public:
		Node();
		void acceder(int);
		int dato();
		Node* sgte() { return next; } //siguiente/avance
		void fill(Node);	//llenar
};

Node::Node() {
	elem = 0;
}
void Node::acceder(int e) {
	elem = e;
}
int Node::dato() {
	return elem;
}
void Node::fill(Node e) {
	next = new Node();
	*next = e;
}

#endif
