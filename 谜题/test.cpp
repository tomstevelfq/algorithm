#include<iostream>
#include<vector>
#include<cstring>
#include<cassert>
#define TEST

using namespace std;

char m[5][5];

void output()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            printf("%c  ",m[i][j]);
        }
        printf("\n");
    }
}

void blank(int &x,int &y)
{
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)
    {
        if(m[i][j]==' ')
        {
            x=i;
            y=j;
            return;
        }
    }
}

int main()
{
    #ifdef TEST
    freopen("/home/tom/Desktop/cpp/test.txt","rw",stdin);
    #endif

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%c",&m[i][j]);
        }
        getchar();
    }

    int x,y;

    blank(x,y);

    assert(x==2&&y==1);

    char c;

    while((c=getchar())!='0')
    {
        if(c=='A')
        {
            if(x==0)
            {
                printf("This puzzle has no final configuration.");
                break;
            }
            else
            {
                m[x][y]=m[x-1][y];
                m[x-1][y]=' ';
                x=x-1;
               
            }
        }
        else if(c=='B')
        {
            if(x==4)
            {
                printf("This puzzle has no final configuration.");
                break;
            }
            else
            {
                m[x][y]=m[x+1][y];
                m[x+1][y]=' ';
                x=x+1;
                
            }
        }
        else if(c=='L')
        {
            if(y==0)
            {
                printf("This puzzle has no final configuration.");
                break;
            }
            else
            {
                m[x][y]=m[x][y-1];
                m[x][y-1]=' ';
                y=y-1;
               
            }
        }
        else if(c=='R')
        {
            if(y==4)
            {
                printf("This puzzle has no final configuration.");
                break;
            }
            else
            {
                m[x][y]=m[x][y+1];
                m[x][y+1]=' ';
                y=y+1;
                
            }
        }
    }

    output();

    return 0;
}