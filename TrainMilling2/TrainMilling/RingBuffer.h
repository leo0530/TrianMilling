#pragma once

#ifndef RINGBUFFER_H_INCLUDED
#define RINGBUFFER_H_INCLUDED

#include <cstring>
#include <iostream>
#include <cstdlib>

template<class T>
class RingBuffer
{
public:
	RingBuffer(int _bufferSize=512);
	~RingBuffer(void);

public:
	int bufferSize;
	T* buffer;
	int head;
	int tail;

public:
	bool empty( );
	bool full( );
	int  size( );
	int  count( );
	bool append(T);
	T	 at(int i);
	void clear( );
	void remove(int index);
	void remove(int iStart,int Len);
};

template<class T> RingBuffer<T>::RingBuffer(int _bufferSize)
{
	bufferSize = _bufferSize;
	buffer = new T[bufferSize];
	head = 0;
	tail = 0;
	memset(buffer,0,bufferSize*sizeof(T));
}

template<class T> RingBuffer<T>::~RingBuffer(void)
{
	delete [] buffer;
	buffer = NULL;
}

template<class T> void RingBuffer<T>::clear()
{
	delete [] buffer;
	buffer = NULL;

	buffer = new T[bufferSize];
	head = 0;
	tail = 0;
	memset(buffer,0,bufferSize*sizeof(T));
}

template<class T> bool RingBuffer<T>::empty() 
{
	return head == tail;
}

template<class T> bool RingBuffer<T>::full() 
{
	return (tail + 1) % bufferSize == head;
}

template<class T> int  RingBuffer<T>::size()
{
	int iSize = (tail - head + bufferSize) % bufferSize;
	return iSize;
}

template<class T> int  RingBuffer<T>::count()
{
	int iCount = (tail - head + bufferSize) % bufferSize;
	return iCount;
}

template<class T> bool RingBuffer<T>::append(T item)
{
	if ( full() ) {
		return false;
	}
	buffer[tail] = item;
	tail = (tail + 1+bufferSize) % bufferSize;
	return true;
}

template<class T> T RingBuffer<T>::at(int i)
{
    if (i < 0 || i >= size())
    {
         //cerr << "Error in array limits: " << i << " is out of range\n";
         exit(EXIT_FAILURE);
    }
	int index = ( i + head + bufferSize ) % bufferSize;
	return buffer[index];
}

template<class T> void RingBuffer<T>::remove(int index)
{
	remove(index,1);
}

template<class T> void RingBuffer<T>::remove(int iStart,int Len)
{
	if(iStart == 0){
		head = (head + Len + bufferSize)% bufferSize;
	}
	else{
		int iStartDst = (head+iStart+bufferSize)%bufferSize;
		int iCopyLen = size() - (iStart+Len);

		for(int k=0 ; k<iCopyLen ; k++){
			int i = (iStartDst+k+bufferSize)%bufferSize;
			int j = (i+Len+bufferSize)%bufferSize;
			buffer[i] = buffer[j];
		}
		tail = (tail-Len+bufferSize)%bufferSize;
	}
}

#endif // RINGBUFFER_H_INCLUDED
