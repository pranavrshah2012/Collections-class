/*
 * OrderedCollection.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */

#include "OrderedCollection.h"
#include "Collection.h"
#include<iostream>
using namespace std;

OrderedCollection::OrderedCollection():Collection(4) {

	head=new int[4];
	for(int i=0;i<4;i++)
	{
		head[i]=0;
	}
	first=2;
last=1;
cSize=4;
size_=0;
}

 OrderedCollection::~OrderedCollection() {

	delete head;
	first=0;
	last=0;
	size_=0;
	cSize=0;
}

 OrderedCollection::OrderedCollection(const OrderedCollection& ocn):Collection(ocn)
    {
	 first=2;
	 last=1;
 	   head=new int[ocn.size_];
 	   cSize=size_;
 	       int *ptr_new=head;
 	       int *ptr_old=ocn.head;
 	       for(int i=0;i<=ocn.size_;i++)
 	       {
 	      	 (*ptr_new)=(*ptr_old);
 	      	 ptr_new++;
 	      	 ptr_old++;
 	       }
 	       ptr_new=NULL;
 	       ptr_old=NULL;
    }


 OrderedCollection* OrderedCollection::copy()
 {
	  OrderedCollection* oc2= new OrderedCollection(*this);
	  return oc2;

 }

 bool OrderedCollection::add(int number,int index)
 {
		return false;
 }

 bool OrderedCollection::remove(int number)
 {
return false;
 }


int& OrderedCollection::operator[](const int i)
{


	  	  if((i<0)||(i>this->size_))
	  	  {
	  		  cout<<"\n error as invalid index "<<i;;
	  	  exit(1);
	  	  }

	  	  else
	  		  {
	  		  size_++;
	  		  return head[i];
	  		  }

}


OrderedCollection& OrderedCollection::operator=( Collection& rhs)
{
	OrderedCollection* ocnew = &(dynamic_cast<OrderedCollection&> (rhs));

	if(this==&rhs)return *this;
	else
	{

    delete[] head;
     head=new int[this->size_];
     int *ptr_new=head;
     int *ptr_old=ocnew->head;
     for(int i=0;i<=ocnew->size_;i++)
     {
    	 (*ptr_new)=(*ptr_old);
    	 ptr_new++;
    	 ptr_old++;
     }
     ptr_new=NULL;
     ptr_old=NULL;
     return *this;
	}
}

