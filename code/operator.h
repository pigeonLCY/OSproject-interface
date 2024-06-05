#ifndef operater_h
#define operater_h
//删除语句中的空格
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

struct A{
    char sentence[100];
    char *mystr[20]; //存储每个字符（按照空格分开）
    int numcount;
};

//%1 这种标号的数据存储
struct C_int{
    int flag;
    char contant[10];
}; 

//存储set的字符串数值
struct B_char{
    char flag[30]; //未知数标号
    char contant[30];
};

//存储变量
struct B_int{
    char flag[30];
    char contant[30];
};

void action(struct A* word, int i,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count); 
void del_char(char a[],char c);
void seperate(struct A* word,int line);
char int_tran(int x); 
void func_shift_ori(struct C_int* charater_num);
void select(struct A* word, int count,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num); 
void func_echo(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
char *str_cut(char *str); 
char *find_charater(char *str,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num);
int char_tran(char x); 
int str_judge(char *str,char *judge);
void func_set(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num);
void func_if(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void func_if_exist(struct A* word, int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
int find_if_doc(struct A* word,int line);
int find_doc5(char *che,char *doc); //*
int find_doc6(char *che);  //*
void func_if_char(struct A* word, int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void func_for(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void func_for_s(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void func_for_d(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void func_for_f(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
void seperate_delim(struct A* word, int line,char* delim);
void func_label(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);
int get_ch_num(struct C_int* charater_num); 
void func_goto(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count);
void func_shift(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num); 
void func_copy(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num);

void del_char(char a[],char c)
{
    int i,j;
    for(i=0,j=0; *(a+i)!='\0'; i++)
    {
          if(*(a+i)==c)
             continue;
         else
         {
             *(a+j)=*(a+i);
             j++;
         }
     }
     *(a+j)='\0';
}

void seperate(struct A* word,int line)
{
    const char s[2] = " ";
    char *token;
    
    /* 获取第一个子字符串 */
    token = strtok(word[line].sentence, s);
    
    /* 继续获取其他的子字符串 */
    while( token != NULL ) {
        word[line].mystr[word[line].numcount] = token;
        word[line].numcount++;
        token = strtok(NULL, s);
    }
}

//标号数组初始化
char int_tran(int x)
{
    char i;
    i = '0'+x;
    return i;
}

void func_shift_ori(struct C_int* charater_num)
{
    char ch6;
    char *ch7;
    for (int i = 0;i<10;i++)
    {
        memset(charater_num[i].contant, '\0', sizeof(charater_num[i].contant));
        charater_num[i].flag = i;
        ch6 = int_tran(i);
        charater_num[i].contant[0]=ch6;
    }
}

//执行函数 
void action(struct A* word, int i,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count)
{
	if (!strcmp(word[i].mystr[0],"echo")) {
				//printf("in echo");
				func_echo(word,i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"set")) func_set(word,i,store_str,store_num,number_str,number_num);
			//for 的各种职能，在for_if 中进行实现
			if (!strcmp(word[i].mystr[0],"for")) {
				func_for(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"if")) {
					func_if(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"shift")) {
				func_shift(word,i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],":")) {	//标号 
				func_label(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"goto")) {
				func_goto(word, i,store_str,store_num,number_str,number_num,charater_num,count);
			}
			if (!strcmp(word[i].mystr[0],"copy")) {
				func_copy(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
}

//选择功能编译 
void select(struct A* word, int count,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	for (int i = 0; i<count; i++) {
		action(word,i,store_str,store_num,number_str,number_num,charater_num,count);
		}
}

//实现echo功能 

char *str_cut(char *str) //去除%var%的头部和尾部 
{
	char ch[50];
    str = str+1;
    int len;
    len = strlen(str);
    memset(ch, '\0', sizeof(ch));
    strncat(ch,str,(len-1));
    return ch;
}

char *find_charater(char *str,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num)
{
    for (int i = 0;i<*number_num;i++)
    {
        if (!strcmp(store_num[i].flag,str))
        {
            return store_num[i].contant;
        }
    }
    for (int i = 0;i<*number_str;i++)
    {
        if (!strcmp(store_str[i].flag,str))
        {
            return store_str[i].contant;
        }
    }
    return NULL;
}

int char_tran(char x)	//数字转制 
{
    int i = 0;
    i = x - '0';
    return i;
}
 
void func_echo(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	if (!strcmp(word[line].mystr[word[line].numcount-2],">")){	//文本写入文件 
		FILE* file = fopen(word[line].mystr[word[line].numcount-1],"w");
		char write[100] = "";
		for(int i=1;i<word[line].numcount-2;i++){	//构造写入字符串write 
			strcat(write,word[line].mystr[i]);
			strcat(write," ");
		}
		//printf(write);
		fputs(write,file);
		fputs("\n",file);
		fclose(file);		
		return;
	}
	
	if (!strcmp(word[line].mystr[word[line].numcount-2],">>")){ //文件追加文本 
		FILE* file = fopen(word[line].mystr[word[line].numcount-1],"ab");
		char write[100] = "";
		for(int i=1;i<word[line].numcount-2;i++){	//构造追加字符串write 
			strcat(write,word[line].mystr[i]);
			strcat(write," ");
		}
		//printf(write);
		fputs(write,file);
		fputs("\n",file);
		fclose(file);		
		return;
	}
    for (int i=1;i<word[line].numcount;i++)
    {
    	char* val; //值 
        char ch2[30];        
        strcpy(ch2,word[line].mystr[i]);
        if ((ch2[0] == '%') && (ch2[strlen(ch2)-1] == '%' ))	//显示环境变量的值 
        {
        	//printf("to find"); 
            char *ch1;
            ch1=str_cut(ch2);
            val=find_charater(ch1,store_str,store_num,number_str,number_num);
            if(val != NULL){	//找到输出环境变量值 
            	printf("%s ",val);	
			}
            else{	//未找到直接输出字符串 
            	printf("%s ",ch2);
			}
            continue;
        }
        if ((ch2[0] == '%')) //实现标号变量 
        {
            int j;
            j = char_tran(ch2[1]);
            printf("%s",charater_num[j].contant);
            continue;
        }
        printf("%s ",word[line].mystr[i]); //显示字符串 
    }
    printf("\n");
}

//set中的对它是否与条件c匹配的判断 set c
//set 的格式为
//set....
int str_judge(char *str,char *judge)	//前缀是否匹配 
{
	int i = 0;
	//printf("strlen(c)=%d\n",strlen(judge)); //前缀长
	//printf("strlen(key)=%d\n",strlen(str)); //键长
	//printf("judge=%s\n",judge);
	//printf("str=%s\n",str);
    if (strlen(judge)>strlen(str)) return 0;
    char judgement[20]; //judgement 为从原来的flag的前端截取的，与judge等长的字符串
	/*for(;i<strlen(judge);i++)
		judgement[i] = str[i];
	judgement[i+1] = '\0';*/
    memset(judgement, '\0', sizeof(judgement));
    strncpy(judgement, str, strlen(judge));
    //printf("judgement=%s\n",judgement);
    if (!strcmp(judgement, judge)) return 1;  //为1符合
    return 0;
}

void func_set(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num)
{
	//显示当前所有环境变量 
    //set
    if (word[line].numcount==1)
    {
        for (int i = 0; i < *number_num;i++)
        {
            printf("%s=%s\n",store_num[i].flag,store_num[i].contant);
        }
        for (int i = 0; i < *number_str;i++)
        {
            printf("%s=%s\n",store_str[i].flag,store_str[i].contant);
        }
        return;
    }
    
    //输出前缀包含c的环境变量值 
    //set c   
    if (word[line].numcount == 2)
    {
    	//printf("in set c");
    	int key = 0;
        char *judgestr;//set 给出的判断c
        judgestr = word[line].mystr[1];
        //printf("strlen(c)=%d\n",strlen(judgestr)); //前缀长 
        for (int i = 0; i < *number_num;i++)
        {       	
			//printf("strlen(key)=%d\n",strlen(store_num[i].flag));	//键长 
            if (str_judge(store_num[i].flag,judgestr))//找到包含前缀c的环境变量 
            {
            	//printf("in pipei");
                printf("%s=%s\n",store_num[i].flag,store_num[i].contant);
                key = 1;
            }
        }
        for (int i = 0; i < *number_str;i++)
        {
        	//printf("strlen(c)=%d\n",strlen(judgestr)); //前缀长 
			//printf("strlen(key)=%d\n",strlen(store_str[i].flag));	//键长 
            if (str_judge(store_str[i].flag,judgestr))
            {
            	//printf("in pipei");
                printf("%s=%s\n",store_str[i].flag,store_str[i].contant);
                key = 1;
            }
        }
        if(key == 0){
        	printf("环境变量 %s 没有定义\n",judgestr);
		}
        return;
    }
    
    //删除环境变量 
    if (word[line].numcount == 3){
    	//printf("yes");
    	for (int i = 0; i < *number_num;i++){
    		if(!strcmp(word[line].mystr[1],store_num[i].flag)){
    			for(int j = i; j < *number_num; j++){
    				store_num[i] = store_num[i+1];
				}
				(*number_num)--;
			}
		}
		for (int i = 0; i < *number_str;i++){
    		if(!strcmp(word[line].mystr[1],store_str[i].flag)){
    			for(int j = i; j < *number_str; j++){
    				store_str[i] = store_str[i+1];
				}
				(*number_str)--;
			}
		}
		/*for (int i = 0; i < number_num;i++){
    		if(!strcmp(word[line].mystr[1],store_num[i].flag)){
    			store_num[i]=store_num[number_num-1];
				number_num--;
			}
		}
		for (int i = 0; i < number_str;i++){
    		if(!strcmp(word[line].mystr[1],store_str[i].flag)){
    			store_str[i]=store_str[number_str-1];
				number_str--;
			}
		}*/
		return;
	}
	
    
    //set \p var = 1234
    //添加环境变量 
    /*if (!strcmp(word[line].mystr[1],"\\p"))
    {
        strcpy(store_str[number_str].flag, word[line].mystr[2]);
        strcpy(store_str[number_str].contant, word[line].mystr[4]);
        number_str++;
    }*/
    //set \a var = 1243
    if (!strcmp(word[line].mystr[1],"\\a"))
    {
        strcpy(store_num[*number_num].flag, word[line].mystr[2]);
        /*
        int x;
        x=char_tran(word[line].mystr[4]);
        store_num[number_num].contant = x;
         */
        strcpy(store_num[*number_num].contant, word[line].mystr[4]);
        printf("%s=%s \n",store_num[*number_num].flag,store_num[*number_num].contant);
        FILE* file = fopen("new.txt","ab");
        fputs(store_num[*number_num].flag,file);
    	fputs("=",file);
    	fputs(store_num[*number_num].contant,file);
    	fputs("\n",file);
    	fclose(file);
        (*number_num)++;
    }
    else{
    	strcpy(store_str[*number_str].flag, word[line].mystr[2]);
        strcpy(store_str[*number_str].contant, word[line].mystr[4]);
        printf("%s=%s \n",store_str[*number_str].flag,store_str[*number_str].contant);
        FILE* file = fopen("new.txt","ab");
        fputs(store_str[*number_str].flag,file);
    	fputs("=",file);
    	fputs(store_str[*number_str].contant,file);
    	fputs("\n",file);
    	fclose(file);
        (*number_str)++;
	} 
}

//1、判断驱动器、文件或文件夹是否存在，用 if exist 语句；
//2、判断某两个字符串是否相等，用 if "字符串1"=="字符串2" 语句；
//3、判断某两个数值是否相等，用 if 数值1 equ 数值2 语句；
//4、判断某个变量是否已经被赋值，用 if defined str 语句；
//1、if exist d:\test.txt (echo D盘下有test.txt存在) else (echo D盘下不存在test.txt)
//2、if "abc" == "xyz" (echo 字符串abc等于字符串xyz) else (echo 字符串abc不等于字符串xyz)
//3、if 1 equ 2 (echo 1等于2) else (echo 1不等于2)
//4、if defined str (echo 变量str已经被赋值，其值为%str%) else (echo 变量str的值为空)

void func_if_exist(struct A* word,int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int braket = 0;	//记录括号数 
	//int braket1[2]={0,0};
	//int braket2[2]={0,0}; //记录两个括号
	struct A word1[1];	
	struct A word2[1];	//括号内语句
	word1[0].numcount = 0;
	word2[0].numcount = 0;
	//printf("yes");
	for(int i = 3+flag;i<word[line].numcount;i++)	//构造word1,word2 
	{
		//printf("yes");
		if (!strcmp(word[line].mystr[i],"("))
		{
			//printf("%d",i);
			braket = braket + 1;
			for(int j=i+1;strcmp(word[line].mystr[j],")");j++)
			{
				if(braket == 1)
				{
					word1[0].mystr[word1[0].numcount] = word[line].mystr[j];
					word1[0].numcount++;
				}
				else if(braket == 2)
				{
					word2[0].mystr[word2[0].numcount] = word[line].mystr[j];
					word2[0].numcount++;
				}	
			}	
		}	
	}
	/*printf("%d\n",braket);
	printf("%d\n",word1[0].numcount);
	for(int i = 0; i < word1[0].numcount; i++)
	{
		printf("%s  ",word1[0].mystr[i]);
	}
	printf("\n");
	printf("%d\n",word2[0].numcount);
	for(int i = 0; i < word2[0].numcount; i++)
	{
		printf("%s  ",word2[0].mystr[i]);
	}
	printf("\n");*/  
    if ((find_if_doc(word,line))^flag)
    {
    	//递归调用select 
    	select(word1,1,store_str,store_num,number_str,number_num,charater_num);
    	//func_echo(word1,0,store_str,store_num,number_str,number_num,charater_num);
        //printf("%s\n",word[line].mystr[5+flag]);
		//echo_if(line, 5+flag);
        return;
    }
    else
    {
        if (braket == 2)
        {
        	select(word2,1,store_str,store_num,number_str,number_num,charater_num);
        	//func_echo(word2,0,store_str,store_num,number_str,number_num,charater_num);
        	//printf("%s\n",word[line].mystr[10+flag]);
        	//echo_if(line, 9+flag);
        }
    }
    return;
}

//若缺省，在指定目录下寻找
int find_if_doc(struct A* word,int line)
{
    char ch2[50];
    strcpy(ch2,word[line].mystr[2]);
    
    FILE *f = NULL;
    //printf("%s",ch2);
	f = fopen(ch2,"r");
    if(f != NULL){
    	//printf("yes fopen");
    	fclose(f);
    	return 1;
	} 
    else{
    	//printf("no fopen");
    	fclose(f);
    	return 0;
	} 
	
    /*char *ret;
    ret = strchr(ch2,'/');
    if (ret == NULL)
    {
        return find_doc5("/Users/sherry/Desktop/osFile", ch2);
    }
    return find_doc6(ch2);*/
}

//在默认路径下寻找是否有该文件(没用上)
int find_doc5(char *che,char *doc)
{
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(che); ///open the dir
    while((ptr = readdir(dir)) != NULL) //read the list of this dir
    {
        if (!strcmp(ptr->d_name,doc))
        {
            return 1;
        }
    }
    return 0;
}

//从该路径寻找是否有该文件(没用上)
int find_doc6(char *che)
{
    DIR    *dir;
    dir = opendir(che); ///open the dir
    if (dir == NULL) return 0;
    return 1;
}

void func_if_char(struct A* word, int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int braket = 0;	//记录括号数 
	//int braket1[2]={0,0};
	//int braket2[2]={0,0}; //记录两个括号
	struct A word1[1];	
	struct A word2[1];	//括号内语句
	word1[0].numcount = 0;
	word2[0].numcount = 0;
	//printf("yes");
	for(int i = 4+flag;i<word[line].numcount;i++)	//构造word1,word2 
	{
		//printf("yes");
		if (!strcmp(word[line].mystr[i],"("))
		{
			//printf("%d",i);
			braket = braket + 1;
			for(int j=i+1;strcmp(word[line].mystr[j],")");j++)
			{
				if(braket == 1)
				{
					word1[0].mystr[word1[0].numcount] = word[line].mystr[j];
					word1[0].numcount++;
				}
				else if(braket == 2)
				{
					word2[0].mystr[word2[0].numcount] = word[line].mystr[j];
					word2[0].numcount++;
				}	
			}	
		}	
	}
	
	//printf("flag=%d\n",flag);
	//printf("left=%s\n",word[line].mystr[1+flag]);
	//printf("right=%s\n",word[line].mystr[3+flag]);
	if ((!strcmp(word[line].mystr[1+flag],word[line].mystr[3+flag]))^flag)
    {
        select(word1,1,store_str,store_num,number_str,number_num,charater_num);
        return;
    }
    else
    {
        if (braket == 2)
        {
            select(word2,1,store_str,store_num,number_str,number_num,charater_num);
        }
    }
    return;
}

void func_if(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int flag = 0;
	char str[30];
	char str_eq[30];
    strcpy(str, word[line].mystr[1]);
    strcpy(str_eq, word[line].mystr[2]);
    if (!strcmp(str, "NOT"))
	{
    	flag = 1;
    	//printf("flag=%d",flag);
    	strcpy(str, word[line].mystr[2]);
    	strcpy(str_eq, word[line].mystr[3]);
	}
    if (!strcmp(str, "exist"))
    {
        func_if_exist(word,line,flag,store_str,store_num,number_str,number_num,charater_num);
        return;
    }
    if (!strcmp(str_eq, "=="))
    {
        func_if_char(word,line,flag,store_str,store_num,number_str,number_num,charater_num);
        return;
    }
}

//for功能实现

void func_for_s(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int i;
    char strspilit[30];//去括号后字符串
	char str[10][20];
	int stri[10]; 
	int index=0;	//拆分括号后的字符串数组
	struct A word1[1];	
	word1[0].numcount = 0; //构造的word[1]
	int flag = 0; //标记变量替换位置 
	
    strcpy(strspilit, str_cut(word[line].mystr[3])); //除去括号
    //printf("strspilit=%s\n",strspilit);
    //printf("length=%d\n",strlen(strspilit));
    for(i = 0;i < strlen(strspilit);i++)
    {
    	if(strspilit[i] == ',')
		{
    		index++;//启动下一个新的字符串 
		}
    	else
		{
    		str[index][stri[index]]=strspilit[i];	//生成字符串 
    		stri[index]++;
		}
	}
	//for(i = 0;i<=index;i++)
	//	printf("str=%s\n",str[i]);
	//构造word[0] 
	//printf("word[line].numcount=%d",word[line].numcount);
	for(i = 5;i < word[line].numcount;i++)
	{
		if (!strcmp(word[line].mystr[i],word[line].mystr[1]))
			flag=word1[0].numcount;	//标记变量在word1中的位置 
		word1[0].mystr[word1[0].numcount] = word[line].mystr[i];
		word1[0].numcount++;
	}
	
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]);
	//printf("flag=%d",flag);
	//实现循环
	for(i = 0;i<=index;i++)
	{
		if(flag!=0) //说明有变量替换 
			word1[0].mystr[flag]=str[i];	//替换变量
		select(word1,1,store_str,store_num,number_str,number_num,charater_num); //递归调用select	 
	}
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]); 
}

void func_for_d(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int i;
	int num[3]; //起始，步长，终止数组 
    char strspilit[30];//去括号后字符串
	struct A word1[1];	
	word1[0].numcount = 0; //构造的word[1]
	int flag = 0; //标记变量替换位置
	
    strcpy(strspilit, str_cut(word[line].mystr[4])); //除去括号
    //printf("strspilit=%s\n",strspilit);
    //printf("length=%d\n",strlen(strspilit));
    num[0] = strspilit[0] - '0';
    num[1] = strspilit[2] - '0';
    num[2] = strspilit[4] - '0';
    /*for(int i = 0;i<3;i++)
    {
    	printf("num=%d",num[i]);
	}*/
    /*for(i = 0;i < 3;i++)
    {
    	num[i] = strspilit[2*i] - '0';
	}
	for(i = 0;i<3;i++)
		printf("num=%s\n",num[i]);*/
		
	//构造word[0] 
	//printf("word[line].numcount=%d",word[line].numcount);
	for(i = 6;i < word[line].numcount;i++)
	{
		if (!strcmp(word[line].mystr[i],word[line].mystr[2]))
			flag=word1[0].numcount;	//标记变量在word1中的位置 
		word1[0].mystr[word1[0].numcount] = word[line].mystr[i];
		word1[0].numcount++;
	}
	
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]);
	//printf("flag=%d",flag);
	//实现循环
	for(i = num[0];i<=num[2];i+=num[1])
	{
		if(flag!=0) //说明有变量替换
		{
			char change[10]; //替换用的字符串
			change[0] = i+'0'; 
			word1[0].mystr[flag]=change;	//替换变量
		} 
		select(word1,1,store_str,store_num,number_str,number_num,charater_num); //递归调用select	 
	}
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]); 
} 

void func_for(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	char str[30];
	strcpy(str, word[line].mystr[1]);
	//for %%i in (A,B,C) do  
	if (str[0]=='%')	//字符循环 
	{
		func_for_s(word,line,store_str,store_num,number_str,number_num,charater_num);
	}
	if (str[0]=='/')
	{
		if(str[1]=='d')	//数字循环 
		{
			func_for_d(word,line,store_str,store_num,number_str,number_num,charater_num);
		}
		if (str[1] == 'f')
        {
            func_for_f(word,line,store_str,store_num,number_str,number_num,charater_num);
            return;
        }
	}
}

int tran_tri(char *str,int n)
{
    char ch2;
    ch2 = *(str+n);
    int i;
    i = char_tran(ch2);
    return i;
}

void seperate_delim(struct A* word, int line,char* delim)
{
	const char* s = delim;
	//printf("s=%s",s);
    char *token;
    //printf("%s",word[line].sentence);
    /* 获取第一个子字符串 */
    token = strtok(word[line].sentence, s);
    //printf("%s",token);
    /* 继续获取其他的子字符串 */
    while( token != NULL ) {
    	//printf("yes");
        word[line].mystr[word[line].numcount] = token;
        word[line].numcount++;
        token = strtok(NULL, s);
    }
}

void func_for_f(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int i = 0;
	//printf("in f");
	//第三个元素，判断是哪一种
    char ch3[10];
    strcpy(ch3, word[line].mystr[2]);
    //取出文件的名字
    char chr[30];
    
    //for /f %c in (abc.txt) do echo %c  只读入每行首给%c，只输出%c 
    //缺省条件下的判断
	//自动按照空格判断
    if (ch3[0]=='%') 
    {
        strcpy(chr,str_cut(word[line].mystr[4])); //获取文件名 
        //printf("filename=%s",chr); 
		
		//读文件 
		char buff[255];
	    FILE *filein = NULL;
	    filein = fopen(chr,"r"); 
	    if (filein==NULL) 
		{
			printf("error file open");	
		}
	    fscanf(filein, "%s", buff);
	    do
	    {
	        
	        printf("%s\n",buff);
	        fgets(buff,255,(FILE*)filein);
	        fscanf(filein, "%s", buff);
	    }while (!feof(filein));
	    
	    fclose(filein);
	    return;
    }
    
    //for /f “skip=1 tokens=1,4 delims= ” %c in (d:\abc.txt) do @echo %c %d
    //delims为分割字符
    if (ch3[0]=='"')
    {
        strcpy(chr,str_cut(word[line].mystr[9])); //获取文件名
        //printf("filename=%s",chr);
		
		//获取skip 
		int skip;
	    skip=tran_tri(word[line].mystr[3], 5);	//获取skip 
	    //printf("skip=%d",skip);
	    
	    //获取tokens 
	    int token[5];
	    int num = 0; //token的下标 
	    for (i = 7 ;i<strlen(word[line].mystr[4]);i++)
	    {
	    	//printf("%c",word[line].mystr[4][i]);
	        if(word[line].mystr[4][i] == ',')
	        	continue;
	        else
	        {
	        	//printf("yes");
	        	//保存取第几个被分隔的字符串段
	        	token[num]=word[line].mystr[4][i] - '0';
				//printf("token=%d",token[num]);	 
	        	num++;
			}
	    }

	    //取出 delim delim为分割方式
	    char delim[2];
	    char delimain[10];
	    strcpy(delimain, word[line].mystr[5]); //取出delims字段 
	    if (strlen(delimain)==7)	//缺省为空格分割 
	    {
	    	//printf("yes"); 
	        //delim = ' ';
	        strcpy(delim," ");
	    }
	    else{	//否则取出分割字段
	        delim[0] = word[line].mystr[5][7];
	        //printf("%s",delim);
	    }
	    //printf("delim=%s",delim);
	    
	    //读文件
		FILE *fp = NULL;
		char buff[255];
		fp = fopen(chr,"r");	//读入文件 
		if(fp == NULL) {
			printf("error to open file");
		} else {
			//读入
			int pc=0; //用于跳过前skip条指令 
			while (!feof(fp)){
				struct A word1[1]; //保存每行分割后的字符串数组
				word1[0].numcount = 0; 
				fgets(buff, 255, (FILE*)fp);
				if(pc<skip)
				{
					pc++;
					continue;					
				}
				//printf("%s",buff);
				if (!feof(fp)) {
					//读一行文件并分割 
					strcpy(word1[0].sentence, buff);
					//printf("word1 = %s \n",word1[0].sentence);
					del_char(word1[0].sentence, '\n');
					//printf("word1 = %s \n",word1[0].sentence);
					seperate_delim(word1,0,delim);
					//printf("word.mystr = %s \n",word1[0].mystr[0]);
					for(i = 0;i<num;i++)
					{
						//输出tokens指定的位置的字段 
						printf("%s ",word1[0].mystr[token[i]-1]); 	
					}
					printf("\n"); 
				} //sentence空 
			} 
    }}
}

//实现标号 

//计算charater_num包含的标号数量 
int get_ch_num(struct C_int* charater_num)
{
	int num = 0;
	for(int i = 0;charater_num[i].flag!=0;i++)
		num++;
	return num;	
}

void func_label(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int chnum = get_ch_num(charater_num);
	//printf("chnum=%d",chnum);
	strcpy(charater_num[chnum].contant,word[line].mystr[1]);	//存入标号
	//printf("label=%s",charater_num[chnum].contant); 
	charater_num[chnum].flag = line;	//存入指令位置(在word中的位置) 
	//printf("pc=%d",charater_num[chnum].flag);
	printf("chnum=%d",get_ch_num(charater_num));
}

void func_goto(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count)
{
	int i = 0;
	char ch[30];
	strcpy(ch,word[line].mystr[1]);	//获取要goto的标号
	int pc = 0; //要跳转到的位置 
	//printf("goto %s",ch); 
	int chnum = get_ch_num(charater_num);
	//printf("chnum=%d",chnum);
	
	//找到要跳转的位置 
	for(i = 0;i<chnum;i++)	
	{
		if(!strcmp(ch,charater_num[i].contant))
			pc =  charater_num[i].flag;
	}
	//printf("pc=%d",pc);\
	
	//从pc+1处开始重新顺序执行指令
	for(i = pc+1;i<count;i++)
	{
		action(word,i,store_str,store_num,number_str,number_num,charater_num,count);	//重新顺序执行 
	} 
}

void func_shift(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	char temp = word[line].mystr[1][0];	
	int sh_time = temp -'0';	//从第sh_time个参数开始移位 
	for (int i = sh_time;i<9;i++)
    {
        strcpy(charater_num[i].contant, charater_num[i+1].contant);
    }
}

void func_copy(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	//printf("src=%s",word[line].mystr[1]);
	//printf("dest=%s",word[line].mystr[2]);
	FILE *fp1 = fopen(word[line].mystr[2],"w");
    FILE *fp2 = fopen(word[line].mystr[1],"r");
    if(fp1 == NULL) {
        printf("error dest");
        return;
    }
    if(fp2 == NULL) {
        perror("error src");
        return;
    }
    char buffer = fgetc(fp2);
    int cnt = 0;
    while(!feof(fp2)) {
        cnt++;
        fputc(buffer,fp1);
        buffer = fgetc(fp2);
    }
    fclose(fp1);
    fclose(fp2);
}

#endif

