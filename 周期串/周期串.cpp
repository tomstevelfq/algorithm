#include <iostream>
#include<vector>
#include<cassert>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
//周期串
using namespace std;

char s[100];

int fun(int len,int x)
{
    if(len%x)
        return 0;
    else
    {
        char t[100];
        for(int i=0;i<x;i++)
            t[i]=s[i];
        int a=len/x;
        for(int i=1;i<a;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(t[j]!=s[i*x+j])
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    scanf("%s",s);
    int len=strlen(s);
    int T;
    for(int i=1;i<=len;i++)
    {
        if(fun(len,i))
            {
                T=i;
                break;
            }
    }
    cout<<"最小周期"<<T<<endl;
    return 0;
}
