/*
 * Array.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */
#ifndef ARRAY_H_
#define ARRAY_H_
#include"Collection.h"
class Array:public Collection {
public:
	int* head;
	int arrsize;
	Array();
	Array(const Array &array);
	 Array(int n)
	{
		head=new int[n];
			for(int i=0;i<n;i++)
			{
				head[i]=0;
			}
			arrsize=n;
			size_=arrsize;
		}
	virtual ~Array();
	virtual int& operator[](const int index);
	virtual Array& operator=( Collection &c);
	virtual bool add(int number,int index);
	virtual bool remove(int number);
	virtual Array* copy();



};


#endif /* ARRAY_H_ */
