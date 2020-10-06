#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
#include<cstdint>

//uint16_t x; // x has exactly 16 bits, and is unsigned
const int T_S = 200;



class HashTableEntry {
   public:
      int k;
      int v;
      HashTableEntry(int k, int v) {
         t->k= k;
         t->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry *t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for(int i = 0; i<200; i++) {
            t[i] = NULL;
         }
      }


~HashMapTable(){
         for(int i = 0; i <200; i++) {
            if (t[i] != NULL)
              { delete t[i];
               delete[] t;
                     }         
 }
}




      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, int v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      int SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return -1;
         else
            return t[h]->v;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) 
              {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"No Element found at key "<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         
               cout<<"Element Deleted"<<endl;
            }
	

};