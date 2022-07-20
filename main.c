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
				printf("��������Ҫ��ӵ�ѧ��������\n");
				scanf("%d", &num);
				head = Creat_student(head, num);
				
			}break;
			case Stu_Delete:
			{
				printf("��������Ҫɾ����ѧ��id��\n");
				scanf("%d", &id);
				head = Delete_student(head, id);
			}break;
			case Stu_Select:
			{
				printf("��������Ҫ��ѯ��ѧ��id��\n");
				scanf("%d", &id);
				Select_student(head, id);
			}break;
			case Stu_Change:
			{
				printf("��������Ҫ�޸ĵ�ѧ��id��\n");
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
				head = New_head;          //1. ���ֵ����⣬ϵͳ��������֮���ٽ�����ӣ�����ӳɹ��������ٽ��������򲻻���������ӵ�
				tail = New_tail;
			}break;
			case Stu_charu:
			{
				stu* NEW = NULL;
				printf("������Ҫ�����ѧ����Ϣ��\n");
				NEW = Creat_jie_dian();
				New_head = Cha_ru_student(head, NEW);
				Print_student(New_head);
				head = New_head;
				tail = New_tail;
			}break;
			case Stu_Exit:
			{
				printf("��лʹ�ñ�ϵͳ��\n");
				return 0;
			}break;
		}
	}	
}
/*******************************************************
�������ܣ��˵�
*******************************************************/
int menu()
{
	int fun;
	
	printf("-----------------------------------------------\n");
	printf("----------------ѧ���ɼ�����ϵͳ---------------\n");
	printf("-----------------1.���ѧ����Ϣ----------------\n");
	printf("-----------------2.ɾ��ѧ����Ϣ----------------\n");
	printf("-----------------3.�޸�ѧ����Ϣ----------------\n");
	printf("-----------------4.��ѯѧ����Ϣ----------------\n");
	printf("-----------------5.��ӡѧ����Ϣ----------------\n");
	printf("----------------6.��ѧ��ѧ������---------------\n");
	printf("----------------7.��ѧ��ѧ�Ų���---------------\n");
	printf("-------------------0.�˳�ϵͳ------------------\n");
	printf("-----------------------------------------------\n");
	printf("��������Ҫִ�еĲ��裺\n");
	scanf("%d", &fun);
	system("cls");
	return fun;
}

/*******************************************************
�������ܣ������ڵ�
����ֵ���ڵ��׵�ַ
*******************************************************/
stu* Creat_jie_dian()
{
	stu* p = NULL;
	p = (stu*)malloc(sizeof(stu));
	scanf("%s%d%f", p->name, &p->id, &p->score);
	return p;
}


/*******************************************************
�������ܣ�1---���ѧ����Ϣ
����ֵ�������ͷ
�������ڵ����
*******************************************************/
stu* Creat_student(stu* head, int num)
{
	int i;
	stu* temp = head;   //�ڵ�

	for (i = stu_sum; i < stu_sum + num; i++)
	{
		temp = Creat_jie_dian();
		if (i == 0)     //ͷ
		{
			head = temp;
		}
		else
		{
			tail->next = temp;
		}
		tail = temp;  //����
		
	}
	temp->next = NULL;
	
	stu_sum += num;
	return head;
}
/*******************************************************
�������ܣ�2---ɾ��ѧ����Ϣ
����ֵ�������ͷ
��������ͷ �ڵ����
*******************************************************/
stu* Delete_student(stu* head, int id)
{
	stu* temp = NULL;
	stu* p = NULL;
	temp = head;
	if (temp == NULL)
	{
		printf("ɾ��ʧ�ܣ�\n");
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
			printf("--------ɾ���ɹ���\n");
		}
		else
		{
			p->next = temp->next;
			free(temp);
			temp->next = NULL;
			printf("ɾ���ɹ���\n");
		}
	}
	
	return head;
}
/*******************************************************
�������ܣ�3---�޸�ѧ����Ϣ
����ֵ�������ͷ
��������ͷ �ڵ����
*******************************************************/
stu* Change_student(stu* head, int id)
{
	char ch;
	char fun[20];
	stu* temp = head;
	if (temp == NULL)
	{
		printf("�޸Ĵ���û��ѧ����Ϣ��\n");
		return NULL;
	}
	while (temp != NULL)
	{
		if (id == temp->id)
		{
			printf("��Ҫ�޸ĵ�ѧ����Ϣ���£�\n");
			printf("-----------------------------------------------\n");
			printf("����\tѧ��\t�ɼ�\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
			printf("��ȷ���Ƿ�����޸ģ�( Y or N )\n");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("������Ҫ�޸ĵ����( name or score )\n");
				scanf("%s", fun);
				if (strcmp(fun, "name") == 0)
				{
					printf("�������µ�������\n");
					scanf("%s", temp->name);
				}
				else if (strcmp(fun, "score") == 0)
				{
					printf("�������µĳɼ���\n");
					scanf("%f", &temp->score);
				}
			}
			else
			{
				printf("�޸��жϣ��˳�����\n");
				return;
			}
			printf("�޸ĳɹ���\n");
			printf("-----------------------------------------------\n");
			printf("����\tѧ��\t�ɼ�\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
		}
		temp = temp->next;
	}
	return NULL;
}

/*******************************************************
�������ܣ�4---��ѯѧ����Ϣ
����ֵ�������ͷ
��������ͷ �ڵ����
*******************************************************/
stu* Select_student(stu* head, int id)
{
	stu* temp = head;      
	if (temp == NULL)
	{
		printf("��ѯ����û��ѧ����Ϣ��\n");
		return NULL;
	}
	while (temp!= NULL)
	{
		if (id == temp->id)
		{
			printf("-----------------------------------------------\n");
			printf("����\tѧ��\t�ɼ�\t\n");
			printf("%s\t%d\t%.2f\t\n", temp->name, temp->id, temp->score);
			printf("-----------------------------------------------\n");
		}
		temp = temp->next;
	}
	return NULL;
}
/*******************************************************
�������ܣ�5---��ӡѧ����Ϣ
����ֵ�������ͷ
�������ڵ����
*******************************************************/
stu* Print_student(stu* head)
{
	stu* p = head;      //
	if (p == NULL)
	{
		printf("��ӡ����û��ѧ����Ϣ��\n");
		return NULL;
	}
	while (p != NULL)
	{
		printf("-----------------------------------------------\n");
		printf("����\tѧ��\t�ɼ�\t\n");
		printf("%s\t%d\t%.2f\t\n", p->name, p->id, p->score);
		printf("-----------------------------------------------\n");
		p = p->next;
	}
	return NULL;
}

/*******************************************************
�������ܣ�6---�����ӡѧ����Ϣ
����ֵ���������ͷ
�������ڵ����
*******************************************************/
stu* Print_Pai_xu(stu* head)
{
	New_head = NULL;
	New_tail = NULL;       //����������գ��������У�����һ���

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
�������ܣ�7---����ѧ����Ϣ,��������õĲ���
����ֵ���������ͷ
����������������Լ�Ҫ������½ڵ�
*******************************************************/
stu* Cha_ru_student(stu* N_head, stu *NEW)
{
	stu* temp = N_head;
	stu* p = NULL;
	if (N_head == NULL)
	{
		N_head = NEW;                      //����ڵ�Ҫע���һ���ط���NEW-----�½ڵ�����֪�ģ�����������Ҫ��ֵ������
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
			printf("����ɹ���\n");
			
		}
		else
		{
			p->next = NEW;
			NEW->next = temp;
			printf("����ɹ���\n");
			
		}
	}
	else if (temp->next == NULL)
	{
		temp->next = NEW;
		NEW->next = NULL;
	}
	
	return N_head;
}

