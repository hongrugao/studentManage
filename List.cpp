#include<iostream>       // 
using namespace std;

typedef struct node      //节点的结构体 
{
	char name[20];
	int age;
	node * next;
 }Student;
 
int length(Student * head)     //计算链表长度 
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
Student * createList(int n)       //创建链表 
{
 	Student * head=new Student;
 	Student * pre=head;
 	for(int i=0;i<n;i++)
 	{
 		Student *p=new Student;
 		cout<<"请输入第"<<i+1<<"个学生的姓名与年龄"<<endl;
		cin>>p->name>>p->age;
		pre->next=p;
		pre=p; 
		p->next=NULL;
	}
	return head;
} 
void insertElement(Student *head,int index)        //在第几号节点处插入节点 
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
		cout<<"请输入新学生的信息"<<endl; 
		cin>>p_insert->name>>p_insert->age;
                                p_insert->next=pre->next;
	                pre->next=p_insert;
		
	}
} 
void deleteElement(Student *head,int index)        //删除第几号节点 
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
void display(Student *head)                //遍历输出节点
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
		cout<<"输入1插入新学生，输入2删除学生，输入3展示学生信息，输入4退出"<<endl; 
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
			               cout<<"插入到第几号学生"<<endl; 
			               int k;
			               cin>>k;
			               insertElement(h,k);
			               break;
		                }
		                case 2:
		                {
			               cout<<"删除第几号学生"<<endl; 
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
