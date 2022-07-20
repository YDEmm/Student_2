#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
enum function{
	Stu_Add    = 1,
	Stu_Delete = 2,
	Stu_Change = 3,
	Stu_Select = 4,
	Stu_Print  = 5,
	Stu_Pai    = 6,
	Stu_charu  = 7,
	Stu_Exit   = 0

};
typedef struct student
{
	char name[20];
	int id;
	float score;
	struct student* next;
}stu;
int menu();
stu* Creat_jie_dian();
stu* Creat_student(stu* head, int num);
stu* Delete_student(stu* head, int id);
stu* Change_student(stu* head, int id);
stu* Select_student(stu* head, int id);
stu* Print_student(stu* head);
stu* Print_Pai_xu(stu* head);
stu* Cha_ru_student(stu* N_head, stu* NEW);

int stu_sum;
stu* head = NULL;
stu* tail = NULL;
stu* New_head = NULL;
stu* New_tail = NULL;

int main()
{
	int num, id, function;

	while (1)
	{
		function = menu();
		
		switch (function)
		{
			case Stu_Add:
			{
				printf("请输入想要添加的学生个数：\n");
				scanf("%d", &num);
				head = Creat_student(head, num);
				
			}break;
			case Stu_Delete:
			{
				printf("请输入想要删除的学生id：\n");
				scanf("%d", &id);
				head = Delete_student(head, id);
			}break;
			case Stu_Select:
			{
				printf("请输入想要查询的学生id：\n");
				scanf("%d", &id);
				Select_student(head, id);
			}break;
			case Stu_Change:
			{
				printf("请输入想要修改的学生id：\n");
				scanf("%d", &id);
				Change_student(head, id);
			}break;
			case Stu_Print:
			{
				Print_student(head);
			}break;
			case Stu_Pai:
			{
				New_head = Print_Pai_xu(head);
				Print_student(New_head);
				head = New_head;          //1. 出现的问题，系统在排序完之后再进行添加，会添加成功，但是再进行排序则不会出现最后添加的
				tail = New_tail;
			}break;
			case Stu_charu:
			{
				stu* NEW = NULL;
				printf("请输入要插入的学生信息：\n");
				NEW = Creat_jie_dian();
				New_head = Cha_ru_student(head, NEW);
				Print_student(New_head);
				head = New_head;
				tail = New_tail;
			}break;
			case Stu_Exit:
			{
				printf("感谢使用本系统！\n");
				return 0;
			}break;
		}
	}	
}
/*******************************************************
函数功能：菜单
*******************************************************/
int menu()
{
	int fun;
	
	printf("-----------------------------------------------\n");
	printf("----------------学生成绩管理系统---------------\n");
	printf("-----------------1.添加学生信息----------------\n");
	printf("-----------------2.删除学生信息----------------\n");
	printf("-----------------3.修改学生信息----------------\n");
	printf("-----------------4.查询学生信息----------------\n");
	printf("-----------------5.打印学生信息----------------\n");
	printf("----------------6.按学生学号排序---------------\n");
	printf("----------------7.按学生学号插入---------------\n");
	printf("-------------------0.退出系统------------------\n");
	printf("-----------------------------------------------\n");
	printf("请输入想要执行的步骤：\n");
	scanf("%d", &fun);
	system("cls");
	return fun;
}

/*******************************************************
函数功能：创建节点
返回值：节点首地址
*******************************************************/
stu* Creat_jie_dian()
{
	stu* p = NULL;
	p = (stu*)malloc(sizeof(stu));
	scanf("%s%d%f", p->name, &p->id, &p->score);
	return p;
}


/*******************************************************
函数功能：1---添加学生信息
返回值：链表表头
参数：节点个数
*******************************************************/
stu* Creat_student(stu* head, int num)
{
	int i;
	stu* temp = head;   //节点

	for (i = stu_sum; i < stu_sum + num; i++)
	{
		temp = Creat_jie_dian();
		if (i == 0)     //头
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;  //覆盖
		
	}
	temp->next = NULL;
	
	stu_sum += num;
	return head;
}
/*******************************************************
函数功能：2---删除学生信息
返回值：链表表头
参数：表头 节点个数
*******************************************************/
stu* Delete_student(stu* head, int id)
{
	stu* temp = NULL;
	stu* p = NULL;
	temp = head;
	if (temp == NULL)
	{
		printf("删除失败！\n");
		return NULL;
	}
	while (temp->id != id && temp -> next != NULL)
	{
		p = temp;
		temp = temp->next;
	}
	if (temp->id == id)
	{
		if (temp == head)
		{
			head = head->next;
			free(temp);
			//temp->next = NULL;
			printf("--------删除成功！\n");
		}
		else
		{
			p->next = temp->next;
			free(temp);
			temp->next = NULL;
			printf("删除成功！\n");
		}
	}
	
	return head;
}
/*******************************************************
函数功能：3---修改学生信息
返回值：链表表头
参数：表头 节点个数
*******************************************************/
stu* Change_student(stu* head, int id)
{
	char ch;
	char fun[20];
	stu* temp = head;
	if (temp == NULL)
	{
		printf("修改错误！没有学生信息！\n");
		return NULL;
	}
	while (temp != NULL)
	{
		if (id == temp->id)
		{
			printf("您要修改的学生信息如下：\n");
			printf("-----------------------------------------------\n");
			printf("姓名\t学号\t成绩\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
			printf("请确定是否继续修改：( Y or N )\n");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("请输入要修改的类别：( name or score )\n");
				scanf("%s", fun);
				if (strcmp(fun, "name") == 0)
				{
					printf("请输入新的姓名：\n");
					scanf("%s", temp->name);
				}
				else if (strcmp(fun, "score") == 0)
				{
					printf("请输入新的成绩：\n");
					scanf("%f", &temp->score);
				}
			}
			else
			{
				printf("修改中断，退出程序！\n");
				return;
			}
			printf("修改成功！\n");
			printf("-----------------------------------------------\n");
			printf("姓名\t学号\t成绩\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
		}
		temp = temp->next;
	}
	return NULL;
}

/*******************************************************
函数功能：4---查询学生信息
返回值：链表表头
参数：表头 节点个数
*******************************************************/
stu* Select_student(stu* head, int id)
{
	stu* temp = head;      
	if (temp == NULL)
	{
		printf("查询错误！没有学生信息！\n");
		return NULL;
	}
	while (temp!= NULL)
	{
		if (id == temp->id)
		{
			printf("-----------------------------------------------\n");
			printf("姓名\t学号\t成绩\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
		}
		temp = temp->next;
	}
	return NULL;
}
/*******************************************************
函数功能：5---打印学生信息
返回值：链表表头
参数：节点个数
*******************************************************/
stu* Print_student(stu* head)
{
	stu* p = head;      //
	if (p == NULL)
	{
		printf("打印错误！没有学生信息！\n");
		return NULL;
	}
	while (p != NULL)
	{
		printf("-----------------------------------------------\n");
		printf("姓名\t学号\t成绩\t\n");
		printf("%s\t%d\t%.2f\t\n", p->name, p->id, p->score);
		printf("-----------------------------------------------\n");
		p = p->next;
	}
	return NULL;
}

/*******************************************************
函数功能：6---排序打印学生信息
返回值：新链表表头
参数：节点个数
*******************************************************/
stu* Print_Pai_xu(stu* head)
{
	New_head = NULL;
	New_tail = NULL;       //让新链表清空，重新排列，问题一解决

	stu* temp = head;
	stu* min = NULL;
	stu* F_min = head;

	if (head == NULL)
	{
		return NULL;
	}
	while (head != NULL)
	{
		min = head;
		for (temp = min; temp->next != NULL; temp = temp->next)
		{
			if (min->id > ((temp->next)->id))
			{
				F_min = temp;
				min = F_min->next;
			}
		}
		if (min == head)
		{
			head = min->next;
		}
		else
		{
			F_min->next = min->next;
		}
		if (New_head == NULL)
		{
			New_head = min;
		}
		else
		{
			New_tail->next = min;
		}
		New_tail = min;
		if (New_head != NULL)
		{
			New_tail->next = NULL;
		}
	}
	return New_head;
}

/*******************************************************
函数功能：7---插入学生信息,按照排序好的插入
返回值：新链表表头
参数：排序的链表以及要插入的新节点
*******************************************************/
stu* Cha_ru_student(stu* N_head, stu *NEW)
{
	stu* temp = N_head;
	stu* p = NULL;
	if (N_head == NULL)
	{
		N_head = NEW;                      //插入节点要注意的一个地方，NEW-----新节点是已知的！！！！！！要赋值给其他
		NEW->next = NULL;
		return N_head;
	}
	while ((temp->id) < (NEW->id) && (temp->next != NULL))
	{
		p = temp;
		temp = p->next;
	}
	if (temp->id > NEW->id)
	{
		if (temp == N_head)
		{
			N_head = NEW;
			NEW->next = temp;
			printf("插入成功！\n");
			
		}
		else
		{
			p->next = NEW;
			NEW->next = temp;
			printf("插入成功！\n");
			
		}
	}
	else if (temp->next == NULL)
	{
		temp->next = NEW;
		NEW->next = NULL;
	}
	
	return N_head;
}

