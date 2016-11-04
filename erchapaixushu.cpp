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

//����״̬
#define	TRUE	1
#define	FALSE	0
#define	OK		1
#define	ERROR	0

// ����״̬����
typedef int Status;

// �ؼ�������
typedef char KeyType;

// ����Ԫ������
typedef struct
{
	KeyType key;
}ElemType;


// ���������ṹ������������
typedef struct BiTNode{
	ElemType data;		// �ؼ���
	BiTNode* lchild;	// ����ָ��
	BiTNode* rchild;	// �Һ���ָ��
	BiTNode* parent;
}BiTNode, *BiTree;

// �������������ö�������洢�ṹ
typedef BiTree BSTree;

//���������
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

//���������������㷨
//�ڸ�ָ�� T ��ָ�����������еݹ�ز�����ؼ��ֵ��� key ������Ԫ�أ�
//�����ҳɹ���
//�򷵻�ָ�� p ָ�������Ԫ�صĽ�㣬�����غ���ֵΪ TRUE; 
//����������Ҳ��ɹ���
//����ָ�� p ָ�����·���Ϸ��ʵ����һ����㣬ָ�� f ָ��ǰ���ʵĽ���˫�ף�
// �����غ���ֵΪFALSE, 
//ָ�� f ���ʼ����ֵΪNULL
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


//���������������㷨
  // �������������в����ڹؼ��ֵ��� e.key ��
  // ����Ԫ��ʱ������Ԫ��ֵΪ e �Ľ�㣬����
  // �� TRUE; ���򣬲����в��벢����FALSE
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

   // �Ӷ�����������ɾ����� p��
   // ���ؽ�������������������
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

//������������ɾ���㷨
  // ������������ T �д�����ؼ��ֵ��� key ��
  // ����Ԫ�أ���ɾ��������Ԫ�ؽ�㣬������
  // ����ֵ TRUE�����򷵻غ���ֵ FALSE
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
	//���ı��ļ�����������������.txt���ж�������
	FILE *fp;

	if((fp = fopen("��������������.txt", "r")) == 0)
	{
		printf("�򿪡���������������.txt���ļ�ʧ��");
		getch();
		return -1;
	}

	//���ı��ļ�����������������.txt���ж�������
	while(1)
	{
		char buf[20];

		if(fscanf(fp, "%s", buf) != 1)
			break;

		e.key = buf[0];
		InsertBST(T, e);
	}
	//�ر��ı��ļ�����������������.txt��
	fclose(fp);
	////////////////////////

	printf("������������");
	PrintBiTree(T);
	printf("\n");

	printf("����Ҫɾ����Ԫ�أ�");
	key = getchar();
	if(SearchBST ( T, key, NULL, p ))
	{
		DeleteBST(T, key);

		printf("ɾ����Ķ�����������");
		PrintBiTree(T);
		printf("\n");
	}
	else
	{
		printf("�����Ԫ�ز�������\n");
	}

	printf("�������������������أ�");
	getch();
	return 0;
}