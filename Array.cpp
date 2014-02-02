/*
 * Array.cpp
 *
 *  Created on: Nov 7, 2013
 *      Author: Pranav Shah
 */

/*
 * Array.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */

#include "Array.h"
#include "Collection.h"
#include<iostream>
using namespace std;
Array::Array():Collection(3)
{
	head=new int[3];
	for(int i=0;i<3;i++)
	{
		head[i]=0;
	}
	arrsize=3;
	size_=arrsize;

}

  Array::~Array() {
	 delete head;

}
   Array::Array(const Array& array):Collection(array)
   {
	   head=new int[array.size_];
	   arrsize=size_=array.size_;
	       for(int i=0;i<=array.size_;i++)
	       {
	      	 head[i]=array.head[i] ;

	       }

   }

  Array* Array::copy()
  {
	  Array* array2= new Array(*this);
	  return array2;

  }

  bool Array:: add(int number,int index)
 {
	 cout<<"\n Error:you cannot add in arrays";
	 return false ;
 }

  bool Array::remove(int n)
  {
	  cout<<"\n Error:You cannot remove from an array";
	  return false ;
  }

  int& Array::operator[](const int i)
  {
  	  if((i<0)||(i>=this->arrsize))
	  	  {
  		  cout<<"\nindexed error"<<i;
  		  cout<<"\n error as invalid index";
	  	  exit(1);
	  	  }

	  	  else
	  		  {

	  		  return head[i];
	  		  }
  }

Array& Array::operator=( Collection& rhs)
{
	Array* array_old = &(dynamic_cast<Array&> (rhs));
	this->setSize(array_old->size_);//
	arrsize=array_old->arrsize;//
	if(this==&rhs)return *this;
	else
	{

    delete[] head;
	head=new int[arrsize];

     int *ptr_new=head;
     int *ptr_old=array_old->head;
     for(int i=0;i<arrsize;i++)
     {
    	 (*ptr_new)=(*ptr_old);
    	 ptr_new++;
    	 ptr_old++;
     }
     ptr_new=NULL;
     ptr_old=NULL;

	}
	 return *this;
}



