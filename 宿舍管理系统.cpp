#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student{
    char name[10];   //����
    int number;      //ѧ��
    int dorm_num;    //�����
    int calss;       //�༶
    char sex[4];     //�Ա�

    struct student *next;
}stu;

void mainface();  			//��ҳ��
stu *create();     			//�����б�
void add(stu* head);     //������ݼ�¼
stu *del(stu* head);     //ɾ�����ݼ�¼
void show(stu *head); 		//��ʾ��ǰ���ݼ�¼
void modifystu(stu *head);  //�༭���ݼ�¼
void findstu(stu *head);    //��ѯ��¼

stu *sortstu(stu *head);    //ѡ���������
void outputstu(stu *head);  //�����ļ����

int main()
{
    stu *head;
    mainface();//��ҳ��
    head = create();
    int choice;
    while(1){
        printf("�������1-7:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                add(head);
                break;
            case 2:
                head = del(head);
                break;
            case 3:
                modifystu(head);
                break;
            case 4:
                findstu(head);
                break;
            case 5:
                head = sortstu(head);
                break;
            case 6:
                outputstu(head);
                break;
            case 7:
                show(head);
                break;
            default :
                printf("����������������룡\n");
                break;
        }

    }


    return 0;
}


void mainface()//������
{
	printf("\n\n");
	printf("\t*********************************************************\n");
	printf("\t*\t\t��ӭʹ��������Ϣ����ϵͳ\t\t*\n");
	printf("\t*********************************************************\n");
	printf("\t*\t\t\t1-�������\t\t\t*\n");
	printf("\t*\t\t\t2-����ɾ��\t\t\t*\n");
	printf("\t*\t\t\t3-�����޸�\t\t\t*\n");
	printf("\t*\t\t\t4-���ݲ�ѯ\t\t\t*\n");
	printf("\t*\t\t\t5-��������\t\t\t*\n");
	printf("\t*\t\t\t6-�����ļ����\t\t\t*\n");
	printf("\t*\t\t\t7-��ǰ����չʾ\t\t\t*\n");
	printf("\t*********************************************************\n");
}

stu* create()   //��ʼ���������ļ��л�ȡ����
{
    FILE *fp;
    stu *head,*end,*p;
    char name[10];
    int number,dorm_num,calss;
    char sex[4];

    head = (stu*)malloc(sizeof(stu));
    head->next = NULL;
    p = head;
    end = head;
    int i = 0;
    if((fp = fopen("studentData.txt","r")) == NULL){
        printf("�ļ������ڣ��Ѵ������ļ���\n");
        fopen("studentData.txt","w");
        fp = fopen("studentData.txt","r");
        add(head);
    }else{
        printf("�ɹ���ȡ�ļ���\n");
        while(fscanf(fp,"%s %d %d %d %s\n",&p->name,&p->number,&p->dorm_num,&p->calss,p->sex)>0){
                end = p;
                p->next = (stu*)malloc(sizeof(stu));
                p = p->next;

        }
    }
    free(end->next);
    end->next = NULL;
    p = head;
    fclose(fp);
    return head;
}

void add(stu *head) //���ѧ������
{
    stu* end,*p;
    int i=0;
    p = head;
    while(p->next != NULL){
        p = p->next;
    }
    end = p;
    p->next = (stu*)malloc(sizeof(stu));
    p=p->next;
    printf("��ʼ���ѧ�����ݣ�\n");
    while(1){
            printf("����������\n");
            scanf("%s",&p->name);
            printf("����ѧ�ţ�\n");
            scanf("%d",&p->number);
            printf("�������᣻\n");
            scanf("%d",&p->dorm_num);
            printf("����༶��\n");
            scanf("%d",&p->calss);
            printf("�����Ա�\n");
            scanf("%s",&p->sex);
            end = p;
            p->next = NULL;

            printf("������1��������,�����������˳���\n");
            scanf("%d",&i);
            if(i!=1) break;
            p->next = (stu*)malloc(sizeof(stu));
            p = p->next;
    }
    printf("�������롣\n");
}

stu *del(stu *head)  //ɾ��ѧ������ ����ѧ��
{
    stu *p,*pre;
    pre = head;
    p = head;
    int num;
    int i = 0;
    printf("������Ҫɾ����ѧ��ѧ�ţ�\n");
    scanf("%d",&num);
    while(p){
        if(p->number == num){
            break;
        }
        i++;
        pre = p;
        p = p->next;

    }
    if(p == NULL){
        printf("δ�ҵ���ѧ����\n");
    }
    else
    {
        if(i==0){
            head = p->next;
        }
        else
        {
            pre->next = p->next;


        }


    }
    return head;
}

void show(stu *head)
{
    stu *p;
    p = head;
    while(p){
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        p = p->next;
    }
}

void modifystu(stu *head)
{
    stu *p;
    int num;
    printf("�������޸�ѧ����ѧ�ţ�\n");
    scanf("%d",&num);
    while(p){
        if(num == p->number){
            break;
        }
        p = p->next;
    }
    if(p == NULL){
        printf("δ�ҵ���ѧ�������ݼ�¼��\n");
    }
    else
    {
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        printf("�������޸ĺ����ݣ�\n");
        printf("����������\n");
        scanf("%s",&p->name);
        printf("����ѧ�ţ�\n");
        scanf("%d",&p->number);
        printf("�������᣻\n");
        scanf("%d",&p->dorm_num);
        printf("����༶��\n");
        scanf("%d",&p->calss);
        printf("�����Ա�\n");
        scanf("%s",&p->sex);
        printf("�޸ĳɹ���");
    }
}

void findstu(stu *head)
{
    stu *p = sortstu(head);
    int num;
    printf("�������ѯѧ����ѧ�ţ�\n");
    scanf("%d",&num);
    while(p){
        if(num == p->number){
            break;
        }
        p = p->next;
    }
    if(p == NULL){
        printf("δ�ҵ���ѧ�������ݼ�¼��\n");
    }
    else
    {
        printf("%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        printf("��ѯ�ɹ���");
    }
}

stu *sortstu(stu *head)   //������ס����Ϣ���ؼ��֣�A����������B����ѧ�ţ�C��������ţ�����
{
    stu *p,*pmin,*pminpre,*newhead,*newp;
    p = head;
    pmin = head;
    newhead = NULL;
    newp = NULL;
    char sort_way;
    printf("����������ʽ��A ��������B ��ѧ�ţ�C �������\n");
    getchar();
    scanf("%c",&sort_way);
    switch(sort_way)
    {
        case 'A':
            pminpre = NULL;
            while(head!=NULL)
            {
                //�ҵ���Сֵ
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->name[0] < pmin->name[0]){
                        pminpre = p;
                        pmin = p->next;
                    }
                    else if(p->next->name[0] == pmin->name[0]){
                        if(p->next->name[2] < pmin->name[2]){
                            pminpre = p;
                            pmin = p->next;
                        }
                    }
                     p = p->next;
                }
                //����������
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //�뿪ԭ������
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }


            break;
        case 'B':
            pminpre = NULL;
            while(head!=NULL)
            {
                //�ҵ���Сֵ
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->number < pmin->number){
                        pminpre = p;
                        pmin = p->next;
                    }
                     p = p->next;
                }
                //����������
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //�뿪ԭ������
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }
            break;
        case 'C':
           pminpre = NULL;
            while(head!=NULL)
            {
                //�ҵ���Сֵ
                p = head;
                pmin = head;
                while(p->next!=NULL)
                {
                    if(p->next->dorm_num < pmin->dorm_num){
                        pminpre = p;
                        pmin = p->next;
                    }
                     p = p->next;
                }
                //����������
                if(newhead == NULL)
                {
                    newhead = pmin;
                    newp = newhead;

                }
                else
                {
                    newp->next = pmin;
                    newp = newp->next;
                }
                //�뿪ԭ������
                if(pmin == head)
                {
                    head = head->next;
                }
                else
                {
                    pminpre->next = pmin->next;
                }

            }
            if(newhead != NULL)
            {
                newp = NULL;
            }
            break;
        default:
            printf("δ������ȷ�ַ���\n");

    }
    return newhead;
}

void outputstu(stu *head)
{
    FILE *fp;
    fp = fopen("studentData.txt","w");
    stu *p;
    p = head;
    while(p)
    {
        fprintf(fp,"%s,%d,%d,%d,%s\n",p->name,p->number,p->dorm_num,p->calss,p->sex);
        p = p->next;
    }
    fclose(fp);
    printf("�ɹ�д���ļ���\n");

}
