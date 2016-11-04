#include <bits/stdc++.h>
// #include <cstdio>
// #include <ionameeam>
// #include <cnameing>
// #include <algorithm>
// #include <cmath>
// #include <cstdlib>
#ifdef __WINDOWS_
	#include <windows.h>
#endif
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define root 1, n, 1

const int maxn = 205;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x7f7f7f7f;

struct CharWeight
{
	char ch;
	unsigned int weight;
	CharWeight() {}
	CharWeight(char _c, unsigned int _w)
	{
		ch = _c; weight = _w;
	}
};

struct HTNode
{
	char ch;
	unsigned int weight;
	unsigned int parent;
	unsigned int lchild;
	unsigned int rchild;
	HTNode() {}
	HTNode(char _c, unsigned int _w, unsigned int _p, unsigned int _l, unsigned int _r)
	{
		ch = _c; weight = _w; parent = _p; lchild = _l; rchild = _r;
	}
	HTNode(unsigned int _w, unsigned int _p, unsigned int _l, unsigned int _r)
	{
		weight = _w; parent = _p; lchild = _l; rchild = _r;
	}
};
typedef HTNode *HuffmanTree;

struct HCodeNode
{
	char ch;
	char *code;
};
typedef HCodeNode *HuffmanCode;

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, CharWeight *w, int n)
{
	int s1, s2;
	unsigned int min1, min2;
	char buff[28];
	int p;

	HT = new HTNode[n << 1];
	HT[0].weight = 200;
	for(int i = 1; i <= n; i++)
	{
		// HT[i] = HTNode(w[i - 1].ch, w[i - 1].weight, 0, 0, 0);
		HT[i].ch = w[i - 1].ch;
		HT[i].weight = w[i - 1].weight;
		HT[i].lchild = HT[i].parent = HT[i].rchild = 0;
	}
	for(int i = n + 1; i <= n << 1; i++)
	{
		int t = 0;
		for(int j = 1; j < i; j++)
		{
			if(HT[j].parent) continue;
			t++;
			if(t == 1)
			{
				min1 = HT[j].weight;
				s1 = j;
			}
			else if(t == 2)
			{
				if(HT[j].weight < min1)
				{
					s2 = s1; min2 = min1;
					s1 = j;  min1 = HT[j].weight;
				}
				else
				{
					s2 = j;  min2 = HT[j].weight;
				}
			}
			else
			{
				if(HT[j].weight < min1)
				{
					s2 = s1; min2 = min1;
					s1 = j;  min1 = HT[j].weight;
				}
				else if(HT[j].weight < min2)
				{
					s2 = j; min2 = HT[j].weight;
				}
			}
		}

		// HT[i] = HTNode(min1 + min2, 0, s1, s2);
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].parent = 0;
		HT[i].weight = min1 + min2;
		HT[s1].parent = HT[s2].parent = i;
	}

	HC = new HCodeNode[n + 1];
	buff[n] = 0;
	for(int i = 1; i <= n; i++)
	{
		HC[i].ch = HT[i].ch;
		HC[i].code = new char[27];
		p = n;
		int k = i;
		while(HT[k].parent != 0)
		{
			p--;
			int j = HT[k].parent;
			if(HT[j].lchild == k) buff[p] = '0';
			else buff[p] = '1';
			k = j;
		}
		int l;
		for(l = 0; buff[p] != 0; l++, p++)
			HC[i].code[l] = buff[p];
		HC[i].code[l] = 0;
	}
}

char* Code(char ch, HuffmanCode HC, int n)
{
	for(int i = 1; i <= n; i++)
		if(ch == HC[i].ch) return HC[i].code;
	return NULL;
}

char Decode(char * str, HuffmanCode HC, int n)
{
	for(int i = 1; i <= n; i++)
		if(strcmp(str, HC[i].code) == 0) return HC[i].ch;
	return 0;
}

void solve()
{
	FILE *fp;
	CharWeight CW[200];

	if((fp = fopen("pindu.txt", "r")) == 0)
	{
		printf("打开“pindu.txt”文件失败");
		system("pause");
		return ;
	}
	int cnt(0);
	char buf[200];
	int w;
	while(fscanf(fp, "%s%d", buf, &w) != EOF)
	{
		CW[cnt].ch = buf[0];
		CW[cnt++].weight = w;
	}
	fclose(fp);

	HuffmanTree HT;
	HuffmanCode HC;

	HuffmanCoding(HT, HC, CW, cnt);
	FILE *fin, *fout;
	cerr << "done" << endl;

	if((fin = fopen("yuanma.txt", "r")) == 0)
	{
		printf("打开“yuanma.txt”文件失败");
		system("pause");
		return ;
	}
	if((fout = fopen("bianma.txt", "w")) == 0)
	{
		printf("创建“bianma.txt”文件失败");
		system("pause");
		return ;
	}

	char ch;
	while((ch = fgetc(fin)) != EOF)
	{
		if(ch >= 'a' && ch <= 'z')
			ch += 'A' - 'a';
		else if(ch < 'A' || ch > 'Z')
			ch = '#';

		char *p = Code(ch, HC, cnt);
		if(p) fprintf(fout, "%s", p);
	}
	fclose(fin);
	fclose(fout);

	if((fin = fopen("bianma.txt", "r")) == 0)
	{
		printf("打开“bianma.txt”文件失败");
		system("pause");
		return ;
	}
	if((fout = fopen("jiema.txt", "w")) == 0)
	{
		printf("创建“jiema.txt”文件失败");
		system("pause");
		return ;
	}

	int i = 0;
	while((ch = fgetc(fin)) != EOF)
	{
		buf[i++] = ch;
		if(i>=200) i = 0;
		buf[i] = 0;

		ch = Decode(buf, HC, cnt);
		if(ch)
		{
			if(ch < 'A' || ch > 'Z')
				ch = ' ';
			fputc(ch, fout);
			i = 0;
		}
	}
	fclose(fin);
	fclose(fout);

	system("pause");
}


int main()
{
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif

	solve();

#ifndef ONLINE_JUDGE
	// fclose(stdin);
	// fclose(stdout);
	system("bianma.txt");
	system("jiema.txt");
#endif

	return 0;
}
