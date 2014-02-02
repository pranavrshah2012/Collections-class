/*
 * OrderedCollection.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */

#ifndef ORDEREDCOLLECTION_H_
#define ORDEREDCOLLECTION_H_
#include<iostream>
#include"Collection.h"

class OrderedCollection:public Collection
{
public:

	OrderedCollection();
	OrderedCollection(const OrderedCollection &ocn);
	 OrderedCollection(int n)
		{
		 n=4;
			head=new int[4];
				for(int i=0;i<4;i++)
				{
					head[i]=0;
				}
				cSize=4;
				first=2;
				last=1;
				size_=0;
			}
	virtual ~OrderedCollection();
	virtual OrderedCollection& operator=( Collection &c);
	bool add(int number,int index);
	bool remove(int number);
	virtual int& operator[](const int index);
	virtual OrderedCollection* copy();
	int *head;
	int cSize;
	int first;
	int last;

};

#endif /* ORDEREDCOLLECTION_H_ */
