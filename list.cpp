#include "list.hpp"
#include "node.hpp"


List::List(){
	this ->head = new Node();		
}
List::List(Person persona){
	this->head = new Node(persona);		
}
List::~List(){
}
void List::setHead(Person persona){
	this->head=new Node(persona);
}
Person List::getHead(){
	return head->getValue();
}
void List::insert(int posicion, Person persona){
	Node* temp= head;
	
	for(int i=0; i<=posicion;i++){
		if(temp->hasNext()){
			temp=temp->getNext();
		}else{
			throw "Array Index Out of Bound";
		}
	}
	Node* siguiente = temp->getNext();
	temp->setNext(new Node(persona));
	temp= temp->getNext();
	temp->setNext(siguiente);
				
}
Person List::at(int posicion){
	Node* temp= head;
	for(int i=0; i<=posicion;i++){
		if(temp->hasNext())
			temp=temp->getNext();
		else
			throw "ERROR! Array Index out of Bound";
	}
	return temp->getValue();
}
void List::erase(int posicion){
	Node* temp= head;
	for(int i=0; i<posicion;i++){
		temp = temp->getNext();
	}
	Node* eliminado= temp->getNext();
	temp->setNext(eliminado->getNext());			
}
void List::concat(List* lista){
	Node* temp=head;
	
	while(temp->hasNext()){
		temp=temp->getNext();
	}
	temp->setNext(lista->first());
	
}
int List::find(Person persona){
	Node* temp= head;
	int cont=0;
	bool esta=false;
	while(temp->hasNext()){
		if((temp->getValue()).getName() == persona.getName()){
			break;
			esta=true;
		}else{
			cont++;
		}
	}
	
	if(esta){
		return cont;
	}else{
		return -1;
	}
}
int List::size(){
	int cont=0;
	Node* temp = head; 
	if(head){
		while(temp->hasNext()){
			if(temp->hasNext()){	
				temp = temp->getNext();
				cont++;	
			}
		}
		return cont;
	}else{
		return 1;
	}
}
void List::push_back(Person persona){
	Node* temp = head;
	if(head){
		while(temp->hasNext()){
			temp= temp->getNext();
		}
		temp->setNext(new Node(persona));
	}else{
		head =new Node(persona);
	}

}
Node* List::first(){
	return head;
}

