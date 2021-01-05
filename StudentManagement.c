#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Write();
void Read();

struct student      //定义学生信息结构体
{
    char id[15],name[15];
    int Math,English,Chinese;
} st[1000];     //1000个 先用着 不够再加
int total;      //用于统计学生总人数
FILE* pf;       //文件指针

void Write_1()  //首次写入信息
{
    int i,n;
    printf("请输入要添加的学生人数：\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入学生学号：");
        scanf("%s",&st[i].id);
        printf("请输入学生姓名：");
        scanf("%s",&st[i].name);
        printf("请输入学生数学成绩：");
        scanf("%d",&st[i].Math);
        printf("请输入学生英语成绩：");
        scanf("%d",&st[i].English);
        printf("请输入学生语文成绩：");
        scanf("%d",&st[i].Chinese);
        printf("\n");
    }
    total=n;
    Write();
}

void Read()     //读取文本(学生)数据
{
    int i=0;    //统计学生人数
    pf=fopen("E:\\test.txt","r");
	if (!pf)
	{
		printf("file cannot open!");
		exit(1);
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
	pf = fopen("E:\\test.txt", "w");
	if (!pf)
	{
		printf("file cannot open!");
		exit(1);
	}
    for(i=0;i<total;i++)
        fprintf(pf,"%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
    fclose(pf);
}

void Add()      //增加学生信息
{
    int i,n;
    Read();
    printf("请输入要添加的学生人数：\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("请输入学生学号：");
        scanf("%s",&st[total+i].id);
        printf("请输入学生姓名：");
        scanf("%s",&st[total+i].name);
        printf("请输入学生数学成绩：");
        scanf("%d",&st[total+i].Math);
        printf("请输入学生英语成绩：");
        scanf("%d",&st[total+i].English);
        printf("请输入学生语文成绩：");
        scanf("%d",&st[total+i].Chinese);
        printf("\n");
    }
    total+=n;
    Write();
}

void ModifyDo(int i)    //修改学生信息
{
    printf("请输入修改学生学号：");
    scanf("%s",&st[i].id);
    printf("请输入修改学生姓名：");
    scanf("%s",&st[i].name);
    printf("请输入修改学生数学成绩：");
    scanf("%d",&st[i].Math);
    printf("请输入修改学生英语成绩：");
    scanf("%d",&st[i].English);
    printf("请输入修改学生语文成绩：");
    scanf("%d",&st[i].Chinese);
}

void Modify()           //检索要修改的学生
{
    Read();
    int i,n,m=1;        //m==循环开关，n==修改的选项
    char buf[15];       //储存检索目标
    while(m){
        printf("若想输入要修改的学生学号请输入1，若想输入要修改的学生姓名请输入2\n请输入：");
        scanf("%d",&n);
        switch (n){
            case 1:
                printf("请输入要修改的学生的学号：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                        ModifyDo(i);
                        m=0;
                        printf("修改成功！！！\n");
                        break;
                    }
                if(m==1)
                    printf("输入学号错误或不存在该学生或该学生信息错误！！！\n");
                break;
            case 2:
                printf("请输入要修改的学生姓名：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                        ModifyDo(i);
                        printf("修改成功！！！\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("输入姓名错误或不存在该学生或该学生信息错误！！！\n");
                break;
            default:
                printf("输入错误！！！\n");
                break;
        }
            printf("若想继续修改学生信息请输入1，退出请输入0\n请输入：");
            scanf("%d",&m);
    }
    Write();
}

void Del()              //删除学生信息
{
    Read();
    int i,n,m=1;        //m==循环开关，n==修改的选项
    char buf[15];       //储存检索目标
    while(m){
        printf("若想输入要删除的学生学号请输入1，若想输入要删除的学生姓名请输入2\n请输入：");
        scanf("%d",&n);
        switch (n){   
            case 1:
                printf("请输入要删除的学生学号：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                        total-=1;
                        for(;i<total;i++)
                        st[i]=st[i+1];
                        printf("删除成功！！！\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("输入学号错误或不存在该学生！！！\n");
                break;
            case 2:
                printf("请输入要删除的学生姓名：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                        total-=1;
                        for(;i<total;i++)
                        st[i]=st[i+1];
                        printf("删除成功！！！\n");
                        m=0;
                        break;
                    }
                if(m==1)
                    printf("输入姓名错误或不存在该学生！！！\n");
                break;
            default:
                printf("输入错误！！！\n");
                break;
        }
            printf("若想继续删除学生信息请输入1，退出请输入0\n请输入：");
            scanf("%d",&m);
    }
    Write();
}

void OrderPrint(int i)  //排序打印
{
    
    printf("\n学号\t\t姓名\t数学成绩\t英语成绩\t语文成绩\n");
    switch (i)  //倒序排序==1，顺序排序==0
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
            printf("输入错误！！！\n");
            break;
    }
}

void OrderMath()    //按数学成绩排序并打印
{
    Read();
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
    printf("倒序排序请键入1，顺序排序请键入0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("输入错误！！！\n");
    
}

void OrderCh()      //按语文成绩排序并打印
{
    Read();
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
    printf("顺序排序请键入1，倒序排序请键入0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("输入错误！！！\n");
}

void OrderEn()      //按英语成绩排序并打印
{
    Read();
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
    printf("顺序排序请键入1，倒序排序请键入0\n");
    scanf("%d",&i);
    if(i==0 || i==1)
        OrderPrint(i);
    else
        printf("输入错误！！！\n");
}

void Order()        //统计排序
{
    char buf[15];
    printf("请输入要统计的学科：");
    scanf("%s",&buf);
    if(strcmp(buf,"数学")==0)
        OrderMath();
    if(strcmp(buf,"英语")==0)
        OrderEn();
    if(strcmp(buf,"语文")==0)
        OrderCh();
    if(strcmp(buf,"数学")!=0 && strcmp(buf,"英语")!=0 && strcmp(buf,"语文")!=0)
        printf("输入错误！！！\n");
}

void Check()        //查询学生信息
{
    Read();
    int i,n,m=1;
    char buf[15];
    while(m){
        printf("若想输入要查询的学生学号请输入1，若想输入要查询的学生姓名请输入2\n请输入：");
        scanf("%d",&n);
        switch (n){   
            case 1:
                printf("请输入要查询的学生的学号：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].id,buf)==0){
                            printf("%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                            m=0;
                            break;
                        }
                    if(m==1){
                    printf("输入学号错误或不存在该学生或该学生信息错误！！！\n");
                    }
                break;
            case 2:
                printf("请输入要查询的学生姓名：\n");
                scanf("%s",&buf);
                for(i=0;i<total;i++)
                    if(strcmp(st[i].name,buf)==0){
                            printf("%s\t%s\t%d\t%d\t%d\n",st[i].id,st[i].name,st[i].Math,st[i].English,st[i].Chinese);
                            m=0;
                            break;
                        }
                    if(m==1){
                    printf("输入姓名错误或不存在该学生或该学生信息错误！！！\n");
                    }
                break;
            default:
                printf("输入错误！！！\n");
                break;
        }
            printf("若想继续查询学生信息请输入1，退出请输入0\n请输入：");
            scanf("%d",&m);
    }
    Write();
}

void ConditionMath()    //统计数学在指定分数段情况并打印
{
    int i,j;
    int max,min;    //分数段
    Read();
    printf("请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("请输入要统计的分数最大值：");
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
    Read();
    printf("请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("请输入要统计的分数最大值：");
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
    Read();
    printf("请输入要统计的分数最小值：");
    scanf("%d",&min);
    printf("请输入要统计的分数最大值：");
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
    char buf[15];
    printf("请输入要统计的学科：");
    scanf("%s",&buf);
    if(strcmp(buf,"数学")==0)
        ConditionMath();
    if(strcmp(buf,"英语")==0)
        ConditionEn();
    if(strcmp(buf,"语文")==0)
        ConditionCh();
    if(strcmp(buf,"数学")!=0 && strcmp(buf,"英语")!=0 && strcmp(buf,"语文")!=0)
        printf("输入错误！！！\n");
}

int main()      //主函数
{
    int n;  //操作选项
    int m=1;    //操作开关
    printf("欢迎使用学生信息管理系统\n");
    while(m)
    {
        printf("\n\n\n\n\n\n");
        printf("0==首次写入学生数据，1==增加学生信息，2==删除学生信息，3==修改学生信息\n4==查询学生信息，5==成绩统计,6==条件统计排序\n");
        printf("请输入操作代码:");
        scanf("%d",&n);
        switch(n)
        {
            case 0:
                Write_1();
                break;
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
            default:
                printf("输入错误！！！\n");
                break;
        }
        printf("若想继续操作请输入1，退出请输入0\n请输入：");
        scanf("%d",&m);
    }
    return 0;
}
