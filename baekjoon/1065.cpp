#include<iostream>
using namespace std;

int main()
{
    int n,cnt=99;
    cin >> n;
    if(n<100) 
      cnt = n; // 100보다 작다면 99면 99개 반환
    for(int i=100;i <= n; i++)
    {
        int a,b,c;
        a = i /100; // 100의 자리수
        b = (i % 100)/10;  //10의 자리수
        c = i % 10;     // 1의 자리수
        
        if(a - b == b - c)  cnt++;// 각 자리의 차이가 같다면
    }
    cout<<cnt;
}
