//////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <iostream.h>

//操作状态
#define	TRUE	1
#define	FALSE	0
#define	OK		1
#define	ERROR	0

// 操作状态类型
typedef int Status;

// 关键字类型
typedef char KeyType;

// 数据元素类型
typedef struct
{
	KeyType key;
}ElemType;


// 二叉树结点结构、二叉树类型
typedef struct BiTNode{
	ElemType data;		// 关键字
	BiTNode* lchild;	// 左孩子指针
	BiTNode* rchild;	// 右孩子指针
	BiTNode* parent;
}BiTNode, *BiTree;

// 二叉排序树采用二叉链表存储结构
typedef BiTree BSTree;

//输出二叉树
void PrintBiTree(BiTree &T)
{
	if(T)
	{
		//printf("%c-%3.1f( ", T->data.key, T->data.weight);
		printf("%c(", T->data.key);

		PrintBiTree(T->lchild);
		printf(",");

		PrintBiTree(T->rchild);
		printf(")");
	}
	else
	{
		printf("#");
	}
}

//二叉排序树查找算法
//在根指针 T 所指二叉排序树中递归地查找其关键字等于 key 的数据元素，
//若查找成功，
//则返回指针 p 指向该数据元素的结点，并返回函数值为 TRUE; 
//否则表明查找不成功，
//返回指针 p 指向查找路径上访问的最后一个结点，指针 f 指向当前访问的结点的双亲，
// 并返回函数值为FALSE, 
//指针 f 其初始调用值为NULL
Status SearchBST (BSTree T, KeyType key, BSTree f, BSTree &p )
{
	if(T==0)
	{
		p=f;
		return FALSE;
	}
	if(T->data.key==key)
	{
		p=T;
		return TRUE;
	}
	else if(T->data.key<key)
	{
		f=T;
		T=T->rchild;
		SearchBST(T,key,f,p);
	}
	else
	{
		f=T;
		T=T->lchild;
		SearchBST(T,key,f,p);
	}
	return TRUE; 
}


//二叉排序树插入算法
  // 当二叉排序树中不存在关键字等于 e.key 的
  // 数据元素时，插入元素值为 e 的结点，并返
  // 回 TRUE; 否则，不进行插入并返回FALSE
Status InsertBST(BSTree &T, ElemType e ) 
{
	int status;
	BSTree p, s;
	status=SearchBST(T,e.key,NULL,p);
	if(status==TRUE)
		return FALSE;
	else
	{
		s=new BiTNode;
		s->data=e;
		s->lchild=s->rchild=s->parent=0;
		if(p==0) T=s;
		else 
		{
			s->parent=p;
			if(e.key<p->data.key)
				p->lchild=s;
			else
				p->rchild=s;
		}

	return TRUE;
}
}

   // 从二叉排序树中删除结点 p，
   // 并重接它的左子树或右子树
void Delete ( BSTree &p )
{
	BSTree q;
	if(p->lchild==0&&p->rchild==0)
	{
		p->parent->lchild=p->parent->rchild=0;
		delete p;
	}
	else if(p->lchild==0)
	{
		p->rchild->parent=p->parent;
		p->parent->rchild=p->rchild;
		delete p;
	}
	else if(p->rchild==0)
	{
		p->lchild->parent=p->parent;
		p->parent->lchild=p->lchild;
		delete p;
	}
	else
	{
		for(q=p->rchild;q->lchild!=0;q=q->lchild);
		p->data=q->data;
		Delete(q);
	}
}

//二叉排序树的删除算法
  // 若二叉排序树 T 中存在其关键字等于 key 的
  // 数据元素，则删除该数据元素结点，并返回
  // 函数值 TRUE，否则返回函数值 FALSE
Status DeleteBST (BiTree &T,  KeyType key ) 
{
	int status;
	BiTree p;
	status=SearchBST(T,key,NULL,p);
	if(status==0) return FALSE;
	else
	{
		Delete(p);
		return TRUE;
	}
}


int main()
{
	BSTree T = 0;
	BSTree p;
	ElemType e;
	KeyType key;

	////////////////////////
	//从文本文件“二叉排序树数据.txt”中读入数据
	FILE *fp;

	if((fp = fopen("二叉排序树数据.txt", "r")) == 0)
	{
		printf("打开“二叉排序树数据.txt”文件失败");
		getch();
		return -1;
	}

	//从文本文件“二叉排序树数据.txt”中读入数据
	while(1)
	{
		char buf[20];

		if(fscanf(fp, "%s", buf) != 1)
			break;

		e.key = buf[0];
		InsertBST(T, e);
	}
	//关闭文本文件“二叉排序树数据.txt”
	fclose(fp);
	////////////////////////

	printf("二叉排序树：");
	PrintBiTree(T);
	printf("\n");

	printf("输入要删除的元素：");
	key = getchar();
	if(SearchBST ( T, key, NULL, p ))
	{
		DeleteBST(T, key);

		printf("删除后的二叉排序树：");
		PrintBiTree(T);
		printf("\n");
	}
	else
	{
		printf("输入的元素不在树中\n");
	}

	printf("程序结束，按任意键返回！");
	getch();
	return 0;
}