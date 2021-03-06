#include<iostream>
using namespace std;
#define MAX 500
int multiply(int x,int res[],int res_size)
{
    int carry=0;
    for(int i=0;i<res_size;i++)
    {
        int product=res[i]*x+carry;
        res[i]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        res[res_size]=carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}



void factorial(int n)
{
     int res[MAX];
     res[0]=1;
     int res_size=1;
    for(int x=2;x<=n;x++)
      {
          res_size=multiply(x,res,res_size);
      }
    for(int i=res_size-1;i>=0;i--)
    {
        cout<<res[i];
    }
    cout<<'\n';
}
int main()
{   
    int t; //t is no of test cases
    cin>>t;
    int n;
    for(int i=0;i<t;i++)
    {
    cin>>n; // n is the no whose factorial we have to find
    factorial(n);
    }
    return 0;
}
