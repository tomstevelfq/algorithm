//dfs输出自由组合优化版
//不需要记录数组v[i]
//每次循环都从比当前now中元素大的地方开始循环
//缩短时间复杂度，变为一半
//剪纸函数提前删去不符合条件的那些递归

#include<iostream>

using namespace std;

const int M=25;
int v[M];

int now[M];

int m,n;

int flag;

void put(int now[])
{
    for(int i=1;i<=n;i++)
    {
        cout<<now[i]<<" ";
    }
    cout<<endl;
}

void dfs(int len)
{
    flag++;
    if(len>n)
    {
        put(now);//输出当前数组
        return;
    }
    for(int i=now[len-1]+1;i<=m&&(m-now[len-1]+len>n);i++)
    {
        //cout<<m<<"  "<<now[len-1]<<"   "<<len<<"   "<<n<<endl;
        //cout<<m-now[len-1]+len<<"  "<<n<<endl;
        now[len]=i;
        dfs(len+1);
    }
    return;
}

int main()
{
    cin>>m>>n;
    dfs(1);
    cout<<"调用"<<flag<<"次"<<endl;
    return 0;
}