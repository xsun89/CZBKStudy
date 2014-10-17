#include "iostream"
#include "Array.h"
using namespace std;

int test()
{
    Array a1(10);
    
    for(int i=0; i<a1.length(); i++)
    {
        //a1.setData(i, i);  
		a1[i] = i;
    }
    
    for(int i=0; i<a1.length(); i++)
    {
        printf("array %d: %d\n", i, a1.getData(i));
		printf("second array %d: %d\n", i, a1[i]);
    }
    
    Array a2 = a1;
    
    for(int i=0; i<a2.length(); i++)
    {
        printf("array a2 %d: %d\n", i, a2.getData(i));
    }
    
// 	if (a2==a1)
// 	{
// 		printf("相等");
// 	}
// 	else
// 	{
// 		printf("不相等");
// 	}

// 
 	Array a3(15);
 	a3 = a2; //执行=操作
	for (int i = 0; i < a3.length(); i++)
	{
		printf("array a3 %d: %d\n", i, a3.getData(i));
	}
    return 0;
}

int main()
{
	test();
	system("pause");
	return 0;
}
