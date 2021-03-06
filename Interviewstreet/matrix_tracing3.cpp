#include<iostream>
#include<cmath>
using namespace std;
long long calculate_path(long long m, long long n);
long long factorial(long long n);

int main()
{
    long long t, m, n;
    cin>>t;
    for(long long q=0;q<t;q++)
    {
        cin>>m>>n;
        cout<<calculate_path(m, n)<<endl;
    }
    return 0;
}

long long calculate_path(long long m, long long n)
{
    if(n>m)
    {
         long long temp = m;
         m = n;
         n = temp;
    }
    long long mod = pow(10, 9)+7;
    long long numerator = (m-1+n-1)%mod;
    long long multiply = numerator;
    for(long long i=0;i<n-2;i++)
    {
         multiply = (long long)(multiply*(numerator-1))%mod;
         numerator--;
    }
    numerator = multiply;
    long long denominator = factorial(n-1);
    return ((long long)(numerator/denominator)%mod);
}

long long factorial(long long n)
{
    long long mod = pow(10, 9)+7;
    long long x = 1;
    for(long long i=1;i<=n;i++)
        x = (long long)(x*i)%mod;
    return x;
}
