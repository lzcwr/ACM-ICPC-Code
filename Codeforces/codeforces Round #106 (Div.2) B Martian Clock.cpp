#include <bits/stdc++.h>
using namespace std; 

#define showtime printf("time = %.15f\n",clock() / (double)CLOCKS_PER_SEC); 

const int maxn = 1005; 

string s;
char a[maxn],b[maxn];

int value(char c)
{
	if(c >= '0' && c <= '9') return c - '0';
	if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
	return -1;
}
bool judge(int a, int b)
{
	if(a >= 0 && a < 24 && b >= 0 && b < 60) return true;
	return false;
}
vector<int> ans;
int main()
{
	cin >> s;
	int len = s.length();
	int pos = s.find(':');
	int la(0), lb(0);
	for (int i = 0; i < pos; i++) a[la++] = s[i];
	a[la] = 0;
	for (int i = pos + 1; i < len; i++) b[lb++] = s[i];
	b[lb] = 0;
	int hour(0), minute(0);
	bool stat;
	for (int base = 2; base <= 150; base++)
	{
		hour = 0, minute = 0;
		stat = true;
		for (int i = 0; i < la; i++)
		{
			int num = value(a[i]);
			if(num >= base)
			{ 
				stat = false;
				break;
			}
			hour = hour * base + num;
		}
		if(!stat) continue;
		for (int i = 0; i < lb; i++)
		{
			int num = value(b[i]);
			if(num >= base)
			{
				stat = false;
				break;
			}
			minute = minute * base + num;
		}
		if(!stat) continue;
		if(judge(hour, minute)) ans.push_back(base);
	}
	int sz = ans.size();
	if(sz == 0) printf("0\n");
	else if(sz > 100) printf("-1\n");
	else for(int i = 0; i < sz; i++) printf("%d%c", ans[i], i == sz - 1 ? '\n' : ' ');
	//cout << sz << "----" << endl;
	return 0;
}
