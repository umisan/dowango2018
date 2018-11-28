#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <limits>

using namespace std;
using ll = unsigned long long int;

ll calc_bit(vector<int> &bit)
{
  ll result = 0;
  ll temp = 1;
  for(int i = 0; i < bit.size(); i++)
  {
    if(bit[i] == 1)
    {
      result += temp;
    }
    temp *= 2;
  }
  return result;
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  //美しさの列挙
  vector<ll> beautiy;
  for(int i = 0; i < n; i++)
  {
    ll temp = 0;
    for(int j = i; j < n; j++)
    {
      temp += a[j];
      beautiy.push_back(temp);
    }
  }

  //bit列の用意
  vector<int> bit(40, 0);
  //各bitに対してそのbitを1にすることができるか大きい方から試していく
  for(int i = 39; i >= 0; i--)
  {
    vector<int> temp = bit;
    temp[i] = 1;
    ll check = calc_bit(temp);
    int count = 0;
    for(int j = 0; j < beautiy.size(); j++)
    {
      if((check & beautiy[j]) == check)
      {
        count++;
      }
    }
    if(count >= k)
    {
      bit[i] = 1;
    }
  }
  cout << calc_bit(bit) << endl;
  return 0;
}
