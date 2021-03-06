
#ifndef _ARRAY_H_
#define _ARRAY_H_
 
class Array
{
private:
    int mLength;
    int* mSpace;

public:
    Array(int length);
    Array(const Array& obj);
    int length();
    void setData(int index, int value);
    int getData(int index);
    ~Array();
	int& operator[](int index);
	Array& operator=(const Array& array);
};


//[]  =  ==  !=
//


#endif
