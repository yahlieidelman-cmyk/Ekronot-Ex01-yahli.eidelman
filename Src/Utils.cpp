#include <iostream>
#include "Stack.h"
#include "Utils.h"

void reverse(int *nums,unsigned int size)
{
    Stack temp={0};
    unsigned int i=0;
    if(size>=1||size!=NULL)
    {
        initStack(&temp);
        for(i=0;i<size;i++)
        {
            push(&temp,nums[i]);
        }
        for(i=0;i<size;i++)
        {
            nums[i]=pop(&temp);
        }
        cleanStack(&temp);
    }
}
int *reverse10()
{
    int i=0;
    int temp=0;
    const int sizeOfArr=10;
    int *nums=new int[sizeOfArr]();
    Stack tempStack={0};
    initStack(&tempStack);
    std::cout<<"Please chose 10 numbers\n";
    for(i=0;i<sizeOfArr;i++)
    {
        std::cin>>temp;
        push(&tempStack,temp); 
    }
    for(i=0;i<sizeOfArr;i++)
    {
        nums[i]=pop(&tempStack);
    }
    cleanStack(&tempStack); 
    return nums;
}