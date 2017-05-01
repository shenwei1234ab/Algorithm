#ifndef _KMP_H
#define _KMP_H
#include <string>

//http://www.cnblogs.com/yjiyjige/p/3263858.html
//http://blog.csdn.net/v_july_v/article/details/7041827

//��򵥵ı����ƽ�
int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);
	int pLen = strlen(p);

	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			//�������ǰ�ַ�ƥ��ɹ�����S[i] == P[j]������i++��j++      
			i++;
			j++;
		}
		else
		{
			//�����ʧ�䣨��S[i]! = P[j]������i = i - (j - 1)��j = 0      
			i = i - j + 1;
			j = 0;
		}
	}
	//ƥ��ɹ�������ģʽ��p���ı���s�е�λ�ã����򷵻�-1  
	if (j == pLen){
		return i - j;
	}
	else{
		return -1;
	}
		
}

void GetNext(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

//s:�ı���  p:Ҫƥ���ģʽ��
int KmpSearch(char* s, char* p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	//���next����
	int *next= new int[pLen];
	GetNext(s, next);
	while (i < sLen && j < pLen)
	{
		//�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++      
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			//�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]      
			//next[j]��Ϊj����Ӧ��nextֵ        
			j = next[j];
		}
	}
	if (j == pLen){
		return i - j;
	}
	else{
		return -1;
	}
	delete []next;
}







#endif