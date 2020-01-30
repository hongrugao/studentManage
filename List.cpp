#include<iostream>       // 
using namespace std;

typedef struct node      //�ڵ�Ľṹ�� 
{
	char name[20];
	int age;
	node * next;
 }Student;
 
int length(Student * head)     //���������� 
{
	int count =0;
	Student *p=head->next;
	while(p!=NULL)
	{
		count++; 
		p=p->next;
	}
	return count;
	
 } 
Student * createList(int n)       //�������� 
{
 	Student * head=new Student;
 	Student * pre=head;
 	for(int i=0;i<n;i++)
 	{
 		Student *p=new Student;
 		cout<<"�������"<<i+1<<"��ѧ��������������"<<endl;
		cin>>p->name>>p->age;
		pre->next=p;
		pre=p; 
		p->next=NULL;
	}
	return head;
} 
void insertElement(Student *head,int index)        //�ڵڼ��Žڵ㴦����ڵ� 
{
	if(index<0||index>length(head))
	{
		throw"out of range"; 
	}
	else
	{
		Student *pre=head;
		for(int i=0;i<index-1;i++)
		{
			pre=pre->next;
		} 
		Student *p_insert =new Student;
		cout<<"��������ѧ������Ϣ"<<endl; 
		cin>>p_insert->name>>p_insert->age;
        p_insert->next=pre->next;
	    pre->next=p_insert;
		
	}
} 
void deleteElement(Student *head,int index)        //ɾ���ڼ��Žڵ� 
{
	if(index<0||index>length(head))
	{
		throw"out of range"; 
	}
	else
	{
		Student *pre=head;
		for(int i=0;i<index-1;i++)
		{
			pre=pre->next; 
		} 
		Student *p_delete=pre->next;
		pre->next=p_delete->next;
		delete p_delete;
	}
} 
void display(Student *head)                //��������ڵ�
{
  	Student *p=head->next;
  	while(p!=NULL)
  	{
  		cout<<p->name<<" "<<p->age<<endl;
  		p=p->next;
	}
}
int main()
 {
    Student * h=createList(3);
    display(h);
	while(1)
	{
		cout<<"����1������ѧ��������2ɾ��ѧ��������3չʾѧ����Ϣ������4�˳�"<<endl; 
		int a;
		cin>>a;
		if(a==4)
		{
			break;
		}
		else
		{
			switch(a)
	        {
		        case 1:
		        {
			        cout<<"���뵽�ڼ���ѧ��"<<endl; 
			        int k;
			        cin>>k;
			        insertElement(h,k);
			        break;
		        }
		        case 2:
		        {
			        cout<<"ɾ���ڼ���ѧ��"<<endl; 
			        int k;
			        cin>>k;
			        deleteElement(h,k);
			        break;
	            }
	            case 3:
		        {
			        display(h);
			        break;
	            }
	        }
		}	
	}
 } 
