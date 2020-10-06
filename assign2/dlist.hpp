
////WOrkin..
#pragma once
/*
  dlist.h
  Doubly-linked lists of ints
 */
class dlist {
  public:
    dlist() { }

    struct node {
        int value;
        node* next;
        node* prev;
    };

    node* head() const { return _head; }
    node* tail() const { return _tail; }

    // **** Implement ALL the following methods ****

    // Returns the node at a particular index (0 is the head). If n >= size()
    // return nullptr; if n < 0, return the head of the list.
    // Must run in O(n) time.
    node* at(int n) const 
{  	node *temp = new node;  // make memory for temp in a heap !!!!
  	 temp = _head;
 	  
	   if( (_head == nullptr) && (_tail == nullptr)) //if list is empty
          return nullptr;
    	   
        else
   	while(n > 0) {
   	temp = temp->next;
   	--n;
  	 }
	return temp;      
}

    // Insert a new value, after an existing one. If previous == nullptr, then
    // the list is assumed to be empty.
    // Must run in O(1) time.
    void insert(node *previous, int value) 
{ //previous is a previous node ! and we are gonna add new node after previous node

  	 node *temp = new node;
   	 temp->value = value;
   	 
       if(previous == nullptr){ //if prev is empty list
  	temp->prev = temp->next = nullptr;
	_head=_tail=temp;
	   return;	
        }
 	
	else if(previous==_tail)
	{
	 previous->next = temp; // * set linke tp point to temp !
	temp->prev = previous;  //*
	_tail= temp;  //update tail to tempt !
	temp->next =nullptr; // complete temp node as tail
        }

       else         // ( previous != nullptr)
	{
         previous->next->prev =temp;  //set link
        temp->next = previous->next;  //setting link
        temp->prev = previous; //setting link
        previous->next = temp;    //setting last link
       } 
  	
}

    // Delete the given node. Should do nothing if which == nullptr.
    // Must run in O(1) time.
    void remove(node* which){

  	 if(which == nullptr)
  	 return;  

	else if((which->prev == nullptr )&& (which->next ==nullptr))
	{ delete which;	}
  	   	
	else if( which ==_head)
	{ _head = which->next;
	 which->next->prev = nullptr;
	delete which;}
	
	else if (which == _tail)
	{ _tail= which->prev;
		which->prev->next = nullptr;
	delete which;}

	else{
	which->next->prev = which->prev;  // (which->next->prev)link is point to which's previous node itself..
	which->prev->next = which->next;
         delete which;
        }

  }

    // Add a new element to the *end* of the list
    // Must run in O(1) time.
    void push_back(int value) {
	node *temp = new node;
	temp->value= value;
 	if( _head == NULL && _tail == NULL)
	{  _head=_tail=temp;
		temp->prev=temp->next=nullptr; //complete the node
        }

	else{
        temp->prev = _tail;  // link is pting to tail node
	_tail->next=temp;    // link of tail->next is pting to temp node
        temp->next = nullptr;  // completing tail 
	_tail = temp; // now new tail is temp node.
	}
 }

    // Add a new element to the *beginning* of the list
    // Must run in O(1) time.
    void push_front(int value){
	node *temp = new node;
	temp->value = value;
	
	if( _head==nullptr && _tail==nullptr)
	{
	 temp->prev = nullptr;
	temp->next= nullptr; 
	_head = _tail = temp;
       } 
	else
	{ //push as head 

	temp->prev=nullptr;
         temp->next =_head;    //ILLEGAL :temp->next = temp->next->prev;
        _head->prev=temp;  //ILLEGAL: temp->next->prev=temp; 
	_head=temp;
       }
 }

    // Remove the first element
    // Must run in O(1) time
    void pop_front(){
 	if( _head==nullptr and _tail==nullptr)
	{return ;}  //Ill return 0;

	
	else if(_head->next == nullptr)	
	{ //when head is the only node in list


	delete _head;   // ILLEGAL ALWAYS make loca ptr VAR separate from head
	node *temp = new node;
	temp= _head; //temp is a head now..
	delete temp;
         _head=_tail =nullptr;} 
	
	else{
	node *temp = new node;
	temp=_head;
	_head = temp->next;      // == _head = _head->next;
        _head->prev = nullptr;

        delete temp;
       }		

}

    // Remove the last element
    // Must run in O(1) time
    void pop_back() {
   if(_head == nullptr and _tail == nullptr){
   return;
   }
   else{
    node *temp = new node;
    temp = tail();
   if(_tail->prev == nullptr){ //only 1 node exist in list
      delete temp;
      _head = _tail = nullptr;
   }

   else{
    _tail = _tail->prev;
    tail()->next = nullptr;
    delete temp;
    }
   }
 }

    // Get the size of the list
    // Should run in O(n) time at the worst
    int size() const {
	
	int count=0;
	node* temp = new node;
	temp =_head; //set temp to head
	while(temp !=nullptr)  // not temp->next != nullptr bc it will do -- num incorrect
	{ 
	count ++;
	temp= temp->next;}
	return count;
}

   // Returns true if the list is empty
   // Must run in O(1) time
   bool empty() const { //no need to declare dynamice var!!!!!!
   if(_head== nullptr && tail() == nullptr)
   return true;
   else   return false;
   }

   private:
node* _head = nullptr;
node* _tail = nullptr;
};

// **** Implement ALL the following functions ****

/* a == b
  Compares two lists for equality, returning true if they have the same
  elements in the same positions. (Hint: it is *not* enough to just compare
  pointers! You have to compare the values stored in the nodes.)

  Must run in O(m) time, where m is the length of the shorter of the two lists.
*/
bool operator== (const dlist& a, const dlist& b)
{if(a.size() == b.size())
   {
    for(int i=0; i< b.size()-1; i++) 
        {
           if(a.at(i)->value != b.at(i)->value)
               {return false;}
         }
  return true; 
  }
  
   else {return false;}        

}












/* a + b
  Returns a new list consisting of all the elements of a, followed by all the
  elements of b (i.e., the list concatenation).

  Must run in O(n) time in the length of the result.
*/
dlist operator+ (const dlist& a, const dlist& b){
	dlist List;
	for(int i = 0; i < a.size(); ++i)
	List.push_back(a.at(i)->value);
	for(int j= 0; j < b.size(); ++j)
	  List.push_back(b.at(j)->value);
        
	return List;
}


/* reverse(l)
  Returns a new list that is the *reversal* of l; that is, a new list
  containing the same elements as l but in the reverse order.

  Must run in O(n) time.
*/
dlist reverse(const dlist& l){
	dlist *List = new dlist;
	for(int i = (l.size()-1); i >= 0; --i)
	{
	List->push_back(l.at(i)->value);
	}
	return *List;
}
