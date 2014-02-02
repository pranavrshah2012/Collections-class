/*
/*
 * Collection.cpp
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */

#include "Collection.h"
#include<iostream>
#include<stddef.h>
using namespace std;
#include"Array.h"
#include"OrderedCollection.h"

 Collection::Collection()
	{
		size_=0;
	}


 Collection::~Collection() {
	 size_=0;
}

 Collection* vCopy()
{
	 }



 int x=0;


void addAll(int number)
{
x+=number;
}

  void Collection::iterate(void (*funptr)(int n))
  {
	  Array *arr=dynamic_cast<Array*>(this);
	  OrderedCollection* ocnew1=dynamic_cast<OrderedCollection*>(this);


	  if(arr!=NULL)
	  {
		  int *arrptr=arr->head;
		  for(int i=0;i<arr->arrsize;i++)
		  {
			  (*funptr)(*arrptr);
			  arrptr++;
		  }


		  arr=NULL;
		  ocnew1=NULL;

	  }
	  if(ocnew1!=NULL)
	  {
		  int *arrptr=ocnew1->head;

		 		  for(int i=ocnew1->first;i<=ocnew1->last;i++)
		 		  {
		 			  (*funptr)(*arrptr);
		 			  arrptr++;
		 		  }

		 		  cout<<"\nx = :"<<::x;
		 		  arr=NULL;
		 		  ocnew1=NULL;

	  }


  }//end of function

bool Collection::contains(int n)
{
Array* arr=dynamic_cast<Array*>(this);
OrderedCollection *ocnew1=dynamic_cast<OrderedCollection*>(this);
bool flag=false;
if(arr)
{
int *arrptr=arr->head;
for(int i=0;i<arr->arrsize;i++)
{
	if(arrptr[i]==n)
	{
		flag=true;
		break;
	}


}//for ends

if(flag)
return true;
	else return false;
}

if(ocnew1)
{
int *arrptr=ocnew1->head;
for(int i=ocnew1->first;i<ocnew1->last;i++)
{
	if(arrptr[i]==n)
	{
		flag=true;
		break;
	}


}//for ends

if(flag)
return true;
	else return false;
}

}
//func ends




  int main()
    {

	  std::cout << "Testing started!\n";

	  Collection* temp = new Array();
	  (*temp)[0]=10;
	  (*temp)[1]=250;
	  (*temp)[2] = 200;
	  for (int i = 0; i <= temp->size() - 1; i++) {
	  std::cout << "(*temp)[" << i << "] = " << (*temp)[i] << "\n" ;
	  }

	  Collection* temp2;
	  temp2 = temp->copy() ;
	  (*temp2)[2]=300;
	  for (int i = 0; i <= temp->size() - 1; i++) {
	  std::cout << "(*temp)[" << i << "] = " << (*temp)[i] << "\n" ;
	  }
	  for (int i = 0; i <= temp2->size()- 1; i++) {
	  std::cout << "(*temp2)[" << i << "] = " << (*temp2)[i] << "\n" ;
	  }

	  (*temp2)[2]=275;
	  for (int i = 0; i <= temp2->size()- 1; i++) {
	  std::cout << "(*temp2)[" << i << "] = " << (*temp2)[i] << "\n" ;
	  }

	  Collection** a ;
	  a = new Collection*[5] ;
	  a[0] = new Array ;
	  (*a[0])[0]=50;
	  (*a[0])[1]=75;
	  (*a[0])[2]=100;
	  a[1] = a[0]->copy() ;
	  for (int i = 0; i <= a[1]->size()- 1; i++) {
	  std::cout << "(*a[1])[" << i << "] = " << (*a[1])[i] << "\n" ;
	  }
	  x = 0;
	  temp2->iterate(&addAll) ;
	  std::cout << "x = " <<x << ".\n" ;
	  std::cout << "Does *temp contain 300? " << (temp->contains(300) ? "True" : "False")
	  << "! \n" ;
	  std::cout << "Does *temp2 contain 275? " << (temp2->contains(275) ? "True" : "False")
	  << "! \n" ;

	  delete temp ;
	  delete temp2 ;
	  delete a[0] ;
	  delete a[1] ;
	  delete[] a ;

	  temp = new Array;
	  (*temp)[0]=9;
	  (*temp)[0]=10;
	  (*temp)[2]=11;
	  (*temp)[1] = 100;

	  for (int i = 0; i <= temp->size() - 1; i++) {
	  std::cout << "(*temp)[" << i << "] = " << (*temp)[i] << "\n" ;
	  }
	  temp->add(55,3);//to show error
	  temp->remove(55);//to show error

	  delete temp;

	  cout<<"\n \n testing Ordered Collection functions";
	  	Collection *occ=new OrderedCollection;
	  	(*occ)[0]=10;
	  	(*occ)[1]=20;
	  	(*occ)[2]=30;
	  	(*occ)[3]=40;
	  	cout<<" \n"<<(*occ)[0]<<" "<<(*occ)[1]<<" "<<(*occ)[2]<<" "<<(*occ)[3];

	  	cout<<"\ntesting copy method";
	  	Collection** ab ;
	  	ab = new Collection*[5] ;
	  	ab[0] = new OrderedCollection ;
	  	(*ab[0])[0]=100;
	  		  	(*ab[0])[1]=200;
	  		  	(*ab[0])[2]=300;
	  		  	(*ab[0])[3]=400;
	  		  	ab[1]=ab[0]->copy();
	  		  cout<<" \n array ab[1]="<<(*ab[1])[0]<<" "<<(*ab[1])[1]<<" "<<(*ab[1])[2]<<" "<<(*ab[1])[3];
	  		  delete ab[0];
	  		  delete ab[1];
	  		  delete []ab;

	  		  cout<<"\n testing operator=";
	  		Collection** cde;
	  			  cde=new Collection*[5];

	  			  cde[0]=new OrderedCollection;
	  			  cde[1]=new OrderedCollection;
	  			  (*cde[0])[0]=121;
	  			  (*cde[0])[1]=131;
	  			  (*cde[0])[2]=141;

	  			  cde[1]=cde[0];//overload ==
		  		  cout<<" \n array cde[0]="<<(*cde[0])[0]<<" "<<(*cde[0])[1]<<" "<<(*cde[0])[2];
		  		  cout<<" \n array cde[1]="<<(*cde[1])[0]<<" "<<(*cde[1])[1]<<" "<<(*cde[1])[2];

		  		delete cde[0];

		  			  		  delete []cde;


    	return 0;
    }





