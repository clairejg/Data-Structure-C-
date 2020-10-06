#include <stdexcept> // For out_of_range
#include <iostream>

class ordered_array {
  public:
    /* constructor
       Construct a new ordered_array with the given capacity (maximum size).
       The size of a new ordered_array should be 0.
    */

    ordered_array(int cap) 
	{ 
	pointer = new int[cap];
	capac = cap;
	size2 =0;
	}
	
	//copy ctor
	ordered_array(const ordered_array& other) 
	{ 
	
	capac = other.capac;
	size2 = other.size2;
       pointer = new int[capac];
	
	for(int i = 0; i < size(); ++i)
      pointer[i] = other.pointer[i];

	}


 
    // destructor
    ~ordered_array() { delete []pointer; }

    /* size()
       Returns the size (number of elements in the array).
    */

    int size() { return size2;}


    /* capacity()
       Returns the maximum size of the array.
    */

    int capacity() { return capac;}


//In Best case method runs One time, in Worst case: n times.	
    /* insert(e)
       Insert e into the array. Note that it is OK to insert duplicates; if n 
       copies of a value are inserted into the array then n copies should appear
       in the array.

       If size() == capacity() then this does nothing.

       If e == -2147483648 then this does nothing (i.e., -2147483648 is not a
       valid value to insert).
    */

    void insert(int elem)
   {
   if(size() == capacity())
       { return;       }   
  
   else{
    
     if (elem != -2147483648)
     {
         
       pointer[size()] = elem; 
        size2++;
        }    
     } 	 
 }


//In Best case method runs One time, in Worst case: n times.
    /* remove(e)
       Remove e from the array, if it exists. (If it does not exist, the
       array should be unchanged.) If multiple copies of e are present, only
       one should be removed.

       If e = -2147483648 then this does nothing.
    */
   
 void remove(int elem)
 {

    if(size()==0) { return;}
    
     if(size()!=0)
     {           
      for( int i =0; i<size(); i++)
       {
       if (pointer[i] == elem)
          {  
             pointer[i] = pointer[size()-1];
            size2--;
            break;               
          }     
        }    
      }
}



//In Best case method runs One time, in Worst case: n times.
    /* exists(e)
       Returns true if e is present at least once in the array.
              If e == -2147483648 then this returns false.
    */

    bool exists(int elem)
    { 
        if(elem == -2147483648)
           	{return false;}
           
        if (size() == 0)  {return false;}  	      
          	
        else {      
         for(int i = 0; i<size();  i++)
	     {
          if (pointer[i] == elem)
	      	 {
              return true;
              
        
             }
           } 
                  
           
         }  	
         return false;            
  }  
     
     
    /* at(i)
       Returns the value in the array at index i, which should be >= 0 and <
       size(). 

       If i < 0 or i >= size(), then at(i) should throw a std::out_of_range
       exception. (This is what std::vector does in this situation.)

       Note that at() should *never* return -2147483648 (because insert() should
       never insert it).
   */

      
 int at(int i)
 {
   int temp; 
 
        if( i<0 || i>= size())  
      	{
		throw std::out_of_range("std::out_of_range!!!");
		
		}
    	
    	else
    	{
          for(int i=0; i<size(); i++)
          {
            for(int j=i+1; j<size(); j++)
              {
              if (pointer[i] > pointer[j])
               { 
                  temp = pointer[i];
                  pointer[i]=pointer[j];
                  pointer[j]=temp; 
                               
            // std::swap(pointer[j], pointer[j+1]);
                }          
               }
            }          
       return pointer[i];
        }           
             
     }

  private:
	int capac;
	int size2;
	int *pointer;

};

