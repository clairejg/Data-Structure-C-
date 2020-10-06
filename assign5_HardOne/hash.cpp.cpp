#include <iostream>
#include "hash.hpp"
using namespace std;

int main() {
   HashMapTable hash;
   int key, elem;  
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>elem;
            cout<<"Enter key at which element to be inserted: ";
            cin>>key;
            hash.Insert(key,elem);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>key;
            if (hash.SearchKey(key) == -1) {
               cout<<"No element found at key "<<key<<endl;
               continue;
            } else {
               cout<<"Element at key "<<key<<" : ";
               cout<<hash.SearchKey(key)<<endl;
            }
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>key;
            hash.Remove(key);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}