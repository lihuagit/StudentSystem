#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
void Write();
void Read();

struct student      //定义学生信息结构体
{
    char id[15],name[15];
    int Math,English,Chinese;
} st[1000];     //1000个 先用着 不够再加
int total;      //用于统计学生总人数
FILE* pf;       //文件指针

void RED() {//控制台调整前景色为红色
	HANDLE kai_1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(kai_1, FOREGROUND_INTENSITY | FOREGROUND_RED); // 为红色
}

void GREEN() {//控制台调整前景色为绿色
	HANDLE kai_2 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(kai_2, FOREGROUND_INTENSITY | FOREGROUND_GREEN);// 为绿色
}

void Input(int i)  //录入信息
{
    printf("\t\t请输入学生学号：");
    scanf("%s",&st[i].id);
    printf("\t\t请输入学生姓名：");
    scanf("%s",&st[i].name);
    printf("\t\t请输入学生数学成绩：");
    scanf("%d",&st[i].Math);
    printf("\t\t请输入学生英语成绩：");
    scanf("%d",&st[i].English);
    printf("\t\t请输入学生语文成绩：");
    scanf("%d",&st[i].Chinese);
    printf("\n");
}

void Read()     //读取文本(学生)数据
{
    int i=0;    //统计学生人数
    pf=fopen("D:\\StudentData.txt","r");
	if (!pf)
	{
    	pf=fopen("D:\\StudentData.txt","w+");
    	total=0;
    	return;
	}
    while(!feof(pf))
    {
        fscanf(pf,"%s\t%s\t%d\t%d\t%d\n",&st[i].id,&st[i].name,&st[i].Math,&st[i].English,&st[i].Chinese);
        i++;        //统计学生人数
    }
    fclose(pf);
    total=i;
}

void Write()    //写入学生信息
{
    int i;
	pf = fopen("D:\\StudentData.txt", "w");
	if (!pf)
	{
		printf("\t\tfile cannot open!");
		printf("\t\t按任意键退出程序:");
		getch();
		exit(1);
	}
    for(i=0;i<total;i++)
        fprintf(pf,"%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
    fclose(pf);
}

void Add()      //增加学生信息
{
    int i,n;
    system("cls");
    GREEN();
    printf("\n-------------------增加学生信息-------------------\n");
    printf("\n\t\t请输入要添加的学生人数：");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    	Input(total+i);
    total+=n;
    RED();
    printf("\n\t\t添加成功！！！\n");
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

void Modify()           //检索要修改的学生
{
    int i,n,m=1;        //m==循环开关，n==修改的选项
    char buf[15];       //储存检索目标
    system("cls");
    GREEN();
    printf("--------若想输入要修改的学生学号请输入1，若想输入要修改的学生姓名请输入2--------\n\n");
    printf("\t\t请输入：");
    scanf("%d",&n);
    switch (n){
        case 1:
	        printf("\t\t请输入要修改的学生的学号：");
	        scanf("%s",&buf);
	        for(i=0;i<total;i++)
	            if(strcmp(st[i].id,buf)==0){
	                Input(i);
	                m=0;
	                RED();
	                printf("\n\t\t操作成功！！！\n\n");
	                break;
	            }
	        if(m==1){
	            RED();
	            printf("\t！！！输入学号错误或不存在该学生或该学生信息错误！！！\n");
	        }
	        break;
    	case 2:
        	printf("\t\t请输入要修改的学生姓名：");
        	scanf("%s",&buf);
        	for(i=0;i<total;i++)
            	if(strcmp(st[i].name,buf)==0){
                	Input(i);
                	RED();
                	printf("\n\t\t操作成功！！！\n\n");
                	m=0;
                	break;
            	}
            if(m==1){
                RED();
                printf("\t！！！输入学号错误或不存在该学生或该学生信息错误！！！\n");
            }
            break;
    	default:
        	RED();
        	printf("\t\t输入错误！！！\n");
        	break;
    }
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

void Del()              //删除学生信息
{
    int i,n,m=1;        //m==循环开关，n==修改的选项
    char buf[15];       //储存检索目标
    system("cls");
    GREEN();
    printf("---------若想输入要删除的学生学号请输入1，若想输入要删除的学生姓名请输入2--------\n\n");
    printf("\t\t请输入：");
    scanf("%d",&n);
    switch (n){   
        case 1:
            printf("\t\t请输入要删除的学生学号：");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].id,buf)==0){
                    total-=1;
                    for(;i<total;i++)
                        st[i]=st[i+1];
                    RED();
                    printf("\t\t删除成功！！！\n");
                    m=0;
                    break;
                }
            if(m==1){
                RED();
                printf("\t\t输入学号错误或不存在该学生！！！\n");
            }
            break;
        case 2:
            printf("\t\t请输入要删除的学生姓名：");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].name,buf)==0){
                    total-=1;
                    for(;i<total;i++)
                        st[i]=st[i+1];
                    RED();
                    printf("\t\t删除成功！！！\n");
                	m=0;
                    break;
                }
            if(m==1){
                RED();
                printf("\t\t输入学号错误或不存在该学生！！！\n");
            }
            break;
        default:
            RED();
            printf("\t\t输入错误！！！\n");
            break;
    }
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

void OrderPrint(int i)  //排序打印
{
    printf("\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
    switch (i)  //升序排序==1，降序排序==0
    {
        case 0:
        {
            for(i=total-1;i>=0;i--){
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            }
            printf("\n");
            break;
        }
        case 1:
        {
            for(i=0;i<total;i++){
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            }
            printf("\n");
            break;
        }
        default:
        	RED();
            printf("\t\t输入错误！！！\n");
            break;
    }
}

void OrderMath()    //按数学成绩排序并打印
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].Math=0;   //用于储存最大值、交换时作中间变量
        for(j=0;j<total-i;j++)
        {
            if(st[j].Math>=st[total].Math){
                n=j;
                st[total].Math=st[j].Math;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t升序排序请键入1，降序排序请键入0\n");
    printf("\t\t请输入："); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t输入错误！！！\n");
    }
}

void OrderCh()      //按语文成绩排序并打印
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].Chinese=0;
        for(j=0;j<total-i;j++)
        {
            if(st[j].Chinese>=st[total].Chinese){
                n=j;
                st[total].Chinese=st[j].Chinese;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t升序排序请键入1，降序排序请键入0\n");
    printf("\t\t请输入："); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t输入错误！！！\n");
    }
}

void OrderEn()      //按英语成绩排序并打印
{
    int i,j,n;
    for(i=0;i<total;i++)
    {
        st[total].English=0;
        for(j=0;j<total-i;j++)
        {
            if(st[j].English>=st[total].English){
                n=j;
                st[total].English=st[j].English;
            }
        }
        st[total]=st[n];
        st[n]=st[total-i-1];
        st[total-i-1]=st[total];
    }
    printf("\t\t升序排序请键入1，降序排序请键入0\n");
    printf("\t\t请输入："); 
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else{
    	RED(); 
        printf("\t\t输入错误！！！\n");
    }
}

void Order()        //统计排序
{
	system("cls");
	GREEN();
    char buf[15];
    printf("--------统计排序 对任意课程按降序或升序排列并打印------\n\n");
    printf("\t\t课程：数学 语文 英语\n");
    printf("\t\t请输入要统计的学科：");
    scanf("%s",&buf);
    if(strcmp(buf,"数学")==0)
        OrderMath();
    if(strcmp(buf,"英语")==0)
        OrderEn();
    if(strcmp(buf,"语文")==0)
        OrderCh();
    if(strcmp(buf,"数学")!=0 && strcmp(buf,"英语")!=0 && strcmp(buf,"语文")!=0){
    	RED();
        printf("\t\t输入错误！！！\n");
    }
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

void Check()        //查询学生信息
{
    int i,n,m=1;
    char buf[15];
    system("cls");
    GREEN();
    printf("--------若想输入要查询的学生学号请输入1，若想输入要查询的学生姓名请输入2-----\n\n");
    printf("\t\t请输入：");
    scanf("%d",&n);
    switch (n){
        case 1:
            printf("\t\t请输入要查询的学生的学号：");
            scanf("%s",&buf);
        	for(i=0;i<total;i++)
				if(strcmp(st[i].id,buf)==0){
                    printf("\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
                    printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                    m=0;
                    printf("\n");
                    break;
                    }
                if(m==1){
                    RED();
                    printf("\t\t输入学号错误或不存在该学生或该学生信息错误！！！\n");
                }
            break;
		case 2:
            printf("\t\t请输入要查询的学生姓名：");
            scanf("%s",&buf);
            for(i=0;i<total;i++)
                if(strcmp(st[i].name,buf)==0){
                    printf("\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
                    printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                    m=0;
                    printf("\n");
                    break;
                    }
                if(m==1){
                    RED();
                    printf("\t\t输入姓名错误或不存在该学生或该学生信息错误！！！\n");
                }
            break;
        default:
            RED();
            printf("\t\t输入错误！！！\n");
            break;
    }
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

void ConditionMath()    //统计数学在指定分数段情况并打印
{
    int i,j;
    int max,min;    //分数段
    printf("\t\t请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("\t\t请输入要统计的分数最大值：");
    scanf("%d",&max);
    printf("\n\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].Math>=min && st[i].Math<=max)
        {  
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\n数学成绩在%d到%d的人数一共有%d人\n\n",min,max,j);
}

void ConditionEn()      //统计英语在指定分数段情况并打印
{
    int i,j;
    int max,min;
    printf("\t\t请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("\t\t请输入要统计的分数最大值：");
    scanf("%d",&max);
    printf("\n\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].English>=min && st[i].English<=max)
        {  
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\n英语成绩在%d到%d的人数一共有%d人\n\n",min,max,j);
}

void ConditionCh()      //统计语文在指定分数段情况并打印
{
    int i,j;
    int max,min;
    printf("\t\t请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("\t\t请输入要统计的分数最大值：");
    scanf("%d",&max);
    printf("\n\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
    for(i=0,j=0;i<total;i++)
    {
        if(st[i].Chinese>=min && st[i].Chinese<=max)
        {
            printf("%-16s%-8s%-16d%-16d%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
            j++;
        }
    }
    printf("\n语文成绩在%d到%d的人数一共有%d人\n\n",min,max,j);
}

void Condition()        //统计
{
	system("cls");
	GREEN();
    char buf[15];
    printf("-------成绩统计 统计任意学科在任意分数段的情况------\n\n");
    printf("\t\t课程：数学 语文 英语\n");
    printf("\t\t请输入要统计的学科：");
    scanf("%s",&buf);
    if(strcmp(buf,"数学")==0)
        ConditionMath();
    if(strcmp(buf,"英语")==0)
        ConditionEn();
    if(strcmp(buf,"语文")==0)
        ConditionCh();
    if(strcmp(buf,"数学")!=0 && strcmp(buf,"英语")!=0 && strcmp(buf,"语文")!=0)
        printf("/t/t输入错误！！！\n");
    printf("\t\t键入任意字符继续\n\n");
    getch();
}

int main()      //主函数
{
    int n;  //操作选项
    GREEN();
    Read();
    while(1)
    {
	    printf("------------欢迎使用学生信息管理系统-------------\n");
	    printf("\n\t数据文件路径：D:\\StudentData.txt\n");
        printf("\n\n\n");
        printf("\t\t1==增加学生信息\n\t\t2==删除学生信息\n\t\t3==修改学生信息\n\t\t4==查询学生信息\n\t\t5==成绩统计\n\t\t6==条件统计排序\n\t\t7==保存并退出\n\n");
        printf("\t\t请输入对应操作代码:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:
                Add();
                break;
            case 2:
                Del();
                break;
            case 3:
                Modify();
                break;
            case 4:
                Check();
                break;
            case 5:
                Condition();
                break;
            case 6:
                Order();
                break;
            case 7:
				Write();
				RED();
				printf("\t\t保存成功！！！\n\n");
				return; 
            default:
                printf("输入错误！！！\n");
                break;
        }
        GREEN();
        system("cls");
    }
    return 0;
}
