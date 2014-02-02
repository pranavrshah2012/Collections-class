/*
 * Collection.h
 *
 *  Created on: Nov 29, 2012
 *      Author: Pranav Shah
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_


class Collection {

public:
	int size_;
	void addAll(int number);
	inline Collection();
	Collection(int s){size_=s;}//parameterized constructor
	inline Collection (const Collection& c){this->size_=c.size_;}//copy constructor1
	virtual ~Collection();
	virtual bool add(int number,int index)=0;
	virtual Collection* copy()=0;//base class pointer virtual copy function required with no arguments.
	virtual bool remove(int n)=0;
	virtual Collection& operator=( Collection& c)=0;//op=
	virtual int& operator[](const int index)=0;
	 void iterate(void(*funptr)(int n));//function pointer
	 bool contains(int n);//check present or not

	 int size()
	{
		return size_;
	}


protected:
	inline void setSize(int s){size_=s;}//given a size
	inline int getSize(){return size_;}

};

#endif /* COLLECTION_H_ */
