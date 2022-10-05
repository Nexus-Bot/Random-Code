#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n=s.length();
		int count[500]={0};
		for (int i = 0; i <n; ++i)
		{
			if (s[i]==s[i+1])
			{
				i++;
			}
			else
			{
				count[s[i]]++;
			}
		}
		for (int i = 'a'; i<='z'; ++i)
		{
			if (count[i]>0)
			{
				cout << char(i);
			}
		}
		cout << endl;

	}
	return  0;
}