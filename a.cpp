#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n, 0);
  int total = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
    total += a[i];
  }
  double mean = double(total) / n;
  double mind = 100.0;
  for(int i = 0; i < n; i++)
  {
    mind = min(mind, abs(mean - a[i]));
  }
  for(int i = 0; i < n; i++)
  {
    if(abs(mean - a[i]) == mind)
    {
      cout << i << endl;
      break;
    }
  }
	return 0;
}
