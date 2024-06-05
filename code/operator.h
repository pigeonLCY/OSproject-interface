#ifndef operater_h
#define operater_h
//ɾ������еĿո�
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

struct A{
    char sentence[100];
    char *mystr[20]; //�洢ÿ���ַ������տո�ֿ���
    int numcount;
};

//%1 ���ֱ�ŵ����ݴ洢
struct C_int{
    int flag;
    char contant[10];
}; 

//�洢set���ַ�����ֵ
struct B_char{
    char flag[30]; //δ֪�����
    char contant[30];
};

//�洢����
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
    
    /* ��ȡ��һ�����ַ��� */
    token = strtok(word[line].sentence, s);
    
    /* ������ȡ���������ַ��� */
    while( token != NULL ) {
        word[line].mystr[word[line].numcount] = token;
        word[line].numcount++;
        token = strtok(NULL, s);
    }
}

//��������ʼ��
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

//ִ�к��� 
void action(struct A* word, int i,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count)
{
	if (!strcmp(word[i].mystr[0],"echo")) {
				//printf("in echo");
				func_echo(word,i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"set")) func_set(word,i,store_str,store_num,number_str,number_num);
			//for �ĸ���ְ�ܣ���for_if �н���ʵ��
			if (!strcmp(word[i].mystr[0],"for")) {
				func_for(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"if")) {
					func_if(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"shift")) {
				func_shift(word,i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],":")) {	//��� 
				func_label(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
			if (!strcmp(word[i].mystr[0],"goto")) {
				func_goto(word, i,store_str,store_num,number_str,number_num,charater_num,count);
			}
			if (!strcmp(word[i].mystr[0],"copy")) {
				func_copy(word, i,store_str,store_num,number_str,number_num,charater_num);
			}
}

//ѡ���ܱ��� 
void select(struct A* word, int count,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	for (int i = 0; i<count; i++) {
		action(word,i,store_str,store_num,number_str,number_num,charater_num,count);
		}
}

//ʵ��echo���� 

char *str_cut(char *str) //ȥ��%var%��ͷ����β�� 
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

int char_tran(char x)	//����ת�� 
{
    int i = 0;
    i = x - '0';
    return i;
}
 
void func_echo(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	if (!strcmp(word[line].mystr[word[line].numcount-2],">")){	//�ı�д���ļ� 
		FILE* file = fopen(word[line].mystr[word[line].numcount-1],"w");
		char write[100] = "";
		for(int i=1;i<word[line].numcount-2;i++){	//����д���ַ���write 
			strcat(write,word[line].mystr[i]);
			strcat(write," ");
		}
		//printf(write);
		fputs(write,file);
		fputs("\n",file);
		fclose(file);		
		return;
	}
	
	if (!strcmp(word[line].mystr[word[line].numcount-2],">>")){ //�ļ�׷���ı� 
		FILE* file = fopen(word[line].mystr[word[line].numcount-1],"ab");
		char write[100] = "";
		for(int i=1;i<word[line].numcount-2;i++){	//����׷���ַ���write 
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
    	char* val; //ֵ 
        char ch2[30];        
        strcpy(ch2,word[line].mystr[i]);
        if ((ch2[0] == '%') && (ch2[strlen(ch2)-1] == '%' ))	//��ʾ����������ֵ 
        {
        	//printf("to find"); 
            char *ch1;
            ch1=str_cut(ch2);
            val=find_charater(ch1,store_str,store_num,number_str,number_num);
            if(val != NULL){	//�ҵ������������ֵ 
            	printf("%s ",val);	
			}
            else{	//δ�ҵ�ֱ������ַ��� 
            	printf("%s ",ch2);
			}
            continue;
        }
        if ((ch2[0] == '%')) //ʵ�ֱ�ű��� 
        {
            int j;
            j = char_tran(ch2[1]);
            printf("%s",charater_num[j].contant);
            continue;
        }
        printf("%s ",word[line].mystr[i]); //��ʾ�ַ��� 
    }
    printf("\n");
}

//set�еĶ����Ƿ�������cƥ����ж� set c
//set �ĸ�ʽΪ
//set....
int str_judge(char *str,char *judge)	//ǰ׺�Ƿ�ƥ�� 
{
	int i = 0;
	//printf("strlen(c)=%d\n",strlen(judge)); //ǰ׺��
	//printf("strlen(key)=%d\n",strlen(str)); //����
	//printf("judge=%s\n",judge);
	//printf("str=%s\n",str);
    if (strlen(judge)>strlen(str)) return 0;
    char judgement[20]; //judgement Ϊ��ԭ����flag��ǰ�˽�ȡ�ģ���judge�ȳ����ַ���
	/*for(;i<strlen(judge);i++)
		judgement[i] = str[i];
	judgement[i+1] = '\0';*/
    memset(judgement, '\0', sizeof(judgement));
    strncpy(judgement, str, strlen(judge));
    //printf("judgement=%s\n",judgement);
    if (!strcmp(judgement, judge)) return 1;  //Ϊ1����
    return 0;
}

void func_set(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num)
{
	//��ʾ��ǰ���л������� 
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
    
    //���ǰ׺����c�Ļ�������ֵ 
    //set c   
    if (word[line].numcount == 2)
    {
    	//printf("in set c");
    	int key = 0;
        char *judgestr;//set �������ж�c
        judgestr = word[line].mystr[1];
        //printf("strlen(c)=%d\n",strlen(judgestr)); //ǰ׺�� 
        for (int i = 0; i < *number_num;i++)
        {       	
			//printf("strlen(key)=%d\n",strlen(store_num[i].flag));	//���� 
            if (str_judge(store_num[i].flag,judgestr))//�ҵ�����ǰ׺c�Ļ������� 
            {
            	//printf("in pipei");
                printf("%s=%s\n",store_num[i].flag,store_num[i].contant);
                key = 1;
            }
        }
        for (int i = 0; i < *number_str;i++)
        {
        	//printf("strlen(c)=%d\n",strlen(judgestr)); //ǰ׺�� 
			//printf("strlen(key)=%d\n",strlen(store_str[i].flag));	//���� 
            if (str_judge(store_str[i].flag,judgestr))
            {
            	//printf("in pipei");
                printf("%s=%s\n",store_str[i].flag,store_str[i].contant);
                key = 1;
            }
        }
        if(key == 0){
        	printf("�������� %s û�ж���\n",judgestr);
		}
        return;
    }
    
    //ɾ���������� 
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
    //��ӻ������� 
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

//1���ж����������ļ����ļ����Ƿ���ڣ��� if exist ��䣻
//2���ж�ĳ�����ַ����Ƿ���ȣ��� if "�ַ���1"=="�ַ���2" ��䣻
//3���ж�ĳ������ֵ�Ƿ���ȣ��� if ��ֵ1 equ ��ֵ2 ��䣻
//4���ж�ĳ�������Ƿ��Ѿ�����ֵ���� if defined str ��䣻
//1��if exist d:\test.txt (echo D������test.txt����) else (echo D���²�����test.txt)
//2��if "abc" == "xyz" (echo �ַ���abc�����ַ���xyz) else (echo �ַ���abc�������ַ���xyz)
//3��if 1 equ 2 (echo 1����2) else (echo 1������2)
//4��if defined str (echo ����str�Ѿ�����ֵ����ֵΪ%str%) else (echo ����str��ֵΪ��)

void func_if_exist(struct A* word,int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int braket = 0;	//��¼������ 
	//int braket1[2]={0,0};
	//int braket2[2]={0,0}; //��¼��������
	struct A word1[1];	
	struct A word2[1];	//���������
	word1[0].numcount = 0;
	word2[0].numcount = 0;
	//printf("yes");
	for(int i = 3+flag;i<word[line].numcount;i++)	//����word1,word2 
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
    	//�ݹ����select 
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

//��ȱʡ����ָ��Ŀ¼��Ѱ��
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

//��Ĭ��·����Ѱ���Ƿ��и��ļ�(û����)
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

//�Ӹ�·��Ѱ���Ƿ��и��ļ�(û����)
int find_doc6(char *che)
{
    DIR    *dir;
    dir = opendir(che); ///open the dir
    if (dir == NULL) return 0;
    return 1;
}

void func_if_char(struct A* word, int line,int flag,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int braket = 0;	//��¼������ 
	//int braket1[2]={0,0};
	//int braket2[2]={0,0}; //��¼��������
	struct A word1[1];	
	struct A word2[1];	//���������
	word1[0].numcount = 0;
	word2[0].numcount = 0;
	//printf("yes");
	for(int i = 4+flag;i<word[line].numcount;i++)	//����word1,word2 
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

//for����ʵ��

void func_for_s(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int i;
    char strspilit[30];//ȥ���ź��ַ���
	char str[10][20];
	int stri[10]; 
	int index=0;	//������ź���ַ�������
	struct A word1[1];	
	word1[0].numcount = 0; //�����word[1]
	int flag = 0; //��Ǳ����滻λ�� 
	
    strcpy(strspilit, str_cut(word[line].mystr[3])); //��ȥ����
    //printf("strspilit=%s\n",strspilit);
    //printf("length=%d\n",strlen(strspilit));
    for(i = 0;i < strlen(strspilit);i++)
    {
    	if(strspilit[i] == ',')
		{
    		index++;//������һ���µ��ַ��� 
		}
    	else
		{
    		str[index][stri[index]]=strspilit[i];	//�����ַ��� 
    		stri[index]++;
		}
	}
	//for(i = 0;i<=index;i++)
	//	printf("str=%s\n",str[i]);
	//����word[0] 
	//printf("word[line].numcount=%d",word[line].numcount);
	for(i = 5;i < word[line].numcount;i++)
	{
		if (!strcmp(word[line].mystr[i],word[line].mystr[1]))
			flag=word1[0].numcount;	//��Ǳ�����word1�е�λ�� 
		word1[0].mystr[word1[0].numcount] = word[line].mystr[i];
		word1[0].numcount++;
	}
	
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]);
	//printf("flag=%d",flag);
	//ʵ��ѭ��
	for(i = 0;i<=index;i++)
	{
		if(flag!=0) //˵���б����滻 
			word1[0].mystr[flag]=str[i];	//�滻����
		select(word1,1,store_str,store_num,number_str,number_num,charater_num); //�ݹ����select	 
	}
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]); 
}

void func_for_d(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	int i;
	int num[3]; //��ʼ����������ֹ���� 
    char strspilit[30];//ȥ���ź��ַ���
	struct A word1[1];	
	word1[0].numcount = 0; //�����word[1]
	int flag = 0; //��Ǳ����滻λ��
	
    strcpy(strspilit, str_cut(word[line].mystr[4])); //��ȥ����
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
		
	//����word[0] 
	//printf("word[line].numcount=%d",word[line].numcount);
	for(i = 6;i < word[line].numcount;i++)
	{
		if (!strcmp(word[line].mystr[i],word[line].mystr[2]))
			flag=word1[0].numcount;	//��Ǳ�����word1�е�λ�� 
		word1[0].mystr[word1[0].numcount] = word[line].mystr[i];
		word1[0].numcount++;
	}
	
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]);
	//printf("flag=%d",flag);
	//ʵ��ѭ��
	for(i = num[0];i<=num[2];i+=num[1])
	{
		if(flag!=0) //˵���б����滻
		{
			char change[10]; //�滻�õ��ַ���
			change[0] = i+'0'; 
			word1[0].mystr[flag]=change;	//�滻����
		} 
		select(word1,1,store_str,store_num,number_str,number_num,charater_num); //�ݹ����select	 
	}
	//for(i = 0;i<word1[0].numcount;i++)
	//	printf("word=%s\n",word1[0].mystr[i]); 
} 

void func_for(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	char str[30];
	strcpy(str, word[line].mystr[1]);
	//for %%i in (A,B,C) do  
	if (str[0]=='%')	//�ַ�ѭ�� 
	{
		func_for_s(word,line,store_str,store_num,number_str,number_num,charater_num);
	}
	if (str[0]=='/')
	{
		if(str[1]=='d')	//����ѭ�� 
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
    /* ��ȡ��һ�����ַ��� */
    token = strtok(word[line].sentence, s);
    //printf("%s",token);
    /* ������ȡ���������ַ��� */
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
	//������Ԫ�أ��ж�����һ��
    char ch3[10];
    strcpy(ch3, word[line].mystr[2]);
    //ȡ���ļ�������
    char chr[30];
    
    //for /f %c in (abc.txt) do echo %c  ֻ����ÿ���׸�%c��ֻ���%c 
    //ȱʡ�����µ��ж�
	//�Զ����տո��ж�
    if (ch3[0]=='%') 
    {
        strcpy(chr,str_cut(word[line].mystr[4])); //��ȡ�ļ��� 
        //printf("filename=%s",chr); 
		
		//���ļ� 
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
    
    //for /f ��skip=1 tokens=1,4 delims= �� %c in (d:\abc.txt) do @echo %c %d
    //delimsΪ�ָ��ַ�
    if (ch3[0]=='"')
    {
        strcpy(chr,str_cut(word[line].mystr[9])); //��ȡ�ļ���
        //printf("filename=%s",chr);
		
		//��ȡskip 
		int skip;
	    skip=tran_tri(word[line].mystr[3], 5);	//��ȡskip 
	    //printf("skip=%d",skip);
	    
	    //��ȡtokens 
	    int token[5];
	    int num = 0; //token���±� 
	    for (i = 7 ;i<strlen(word[line].mystr[4]);i++)
	    {
	    	//printf("%c",word[line].mystr[4][i]);
	        if(word[line].mystr[4][i] == ',')
	        	continue;
	        else
	        {
	        	//printf("yes");
	        	//����ȡ�ڼ������ָ����ַ�����
	        	token[num]=word[line].mystr[4][i] - '0';
				//printf("token=%d",token[num]);	 
	        	num++;
			}
	    }

	    //ȡ�� delim delimΪ�ָʽ
	    char delim[2];
	    char delimain[10];
	    strcpy(delimain, word[line].mystr[5]); //ȡ��delims�ֶ� 
	    if (strlen(delimain)==7)	//ȱʡΪ�ո�ָ� 
	    {
	    	//printf("yes"); 
	        //delim = ' ';
	        strcpy(delim," ");
	    }
	    else{	//����ȡ���ָ��ֶ�
	        delim[0] = word[line].mystr[5][7];
	        //printf("%s",delim);
	    }
	    //printf("delim=%s",delim);
	    
	    //���ļ�
		FILE *fp = NULL;
		char buff[255];
		fp = fopen(chr,"r");	//�����ļ� 
		if(fp == NULL) {
			printf("error to open file");
		} else {
			//����
			int pc=0; //��������ǰskip��ָ�� 
			while (!feof(fp)){
				struct A word1[1]; //����ÿ�зָ����ַ�������
				word1[0].numcount = 0; 
				fgets(buff, 255, (FILE*)fp);
				if(pc<skip)
				{
					pc++;
					continue;					
				}
				//printf("%s",buff);
				if (!feof(fp)) {
					//��һ���ļ����ָ� 
					strcpy(word1[0].sentence, buff);
					//printf("word1 = %s \n",word1[0].sentence);
					del_char(word1[0].sentence, '\n');
					//printf("word1 = %s \n",word1[0].sentence);
					seperate_delim(word1,0,delim);
					//printf("word.mystr = %s \n",word1[0].mystr[0]);
					for(i = 0;i<num;i++)
					{
						//���tokensָ����λ�õ��ֶ� 
						printf("%s ",word1[0].mystr[token[i]-1]); 	
					}
					printf("\n"); 
				} //sentence�� 
			} 
    }}
}

//ʵ�ֱ�� 

//����charater_num�����ı������ 
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
	strcpy(charater_num[chnum].contant,word[line].mystr[1]);	//������
	//printf("label=%s",charater_num[chnum].contant); 
	charater_num[chnum].flag = line;	//����ָ��λ��(��word�е�λ��) 
	//printf("pc=%d",charater_num[chnum].flag);
	printf("chnum=%d",get_ch_num(charater_num));
}

void func_goto(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num,int count)
{
	int i = 0;
	char ch[30];
	strcpy(ch,word[line].mystr[1]);	//��ȡҪgoto�ı��
	int pc = 0; //Ҫ��ת����λ�� 
	//printf("goto %s",ch); 
	int chnum = get_ch_num(charater_num);
	//printf("chnum=%d",chnum);
	
	//�ҵ�Ҫ��ת��λ�� 
	for(i = 0;i<chnum;i++)	
	{
		if(!strcmp(ch,charater_num[i].contant))
			pc =  charater_num[i].flag;
	}
	//printf("pc=%d",pc);\
	
	//��pc+1����ʼ����˳��ִ��ָ��
	for(i = pc+1;i<count;i++)
	{
		action(word,i,store_str,store_num,number_str,number_num,charater_num,count);	//����˳��ִ�� 
	} 
}

void func_shift(struct A* word, int line,struct B_char* store_str,struct B_int* store_num,int* number_str,int* number_num,struct C_int* charater_num)
{
	char temp = word[line].mystr[1][0];	
	int sh_time = temp -'0';	//�ӵ�sh_time��������ʼ��λ 
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

