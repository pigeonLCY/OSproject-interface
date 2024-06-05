#include <stdio.h>
#include "operator.h"

int main() {
	//指令数组 
	int count = 0;
	struct A word[100];
	//标号数组
	struct C_int charater_num[10];
	//参数数组 
	struct B_char store_str[100];
	struct B_int store_num[100];
	int number_str;
	int number_num;
	number_str = 0;
	number_num = 0;
	 
	
	FILE *fp = NULL;
	char buff[664];
	count = 0;
	char doc[30];
	printf("the file input:");
	scanf("%s",doc);
	fp = fopen(doc,"r");
	if(fp == NULL) {
		printf("error to open file");
	} else {
		//读入
		do {
			fgets(buff, 255, (FILE*)fp);
			//printf("%s",buff);
			if (!feof(fp)) {
				strcpy(word[count].sentence, buff);
				//printf("%s  count = %d \n",word[count].sentence, count);
				del_char(word[count].sentence, '\n');
				seperate(word,count);
				//printf("%s  count = %d \n",word[count].mystr[0], count);
				count++;
			} //sentence空 
		} while (!feof(fp));
		//printf("count:%d \n",count);
		//初始化参数数组 
		func_shift_ori(charater_num);

		/*for (int i = 0; i<count; i++) {
			printf("%s",word[count].sentence);
		}*/

		fclose(fp);
		
		select(word, count,store_str,store_num,&number_str,&number_num,charater_num);
		//printf("number_num=%d",number_num);
		//printf("number_str=%d",number_str);
		
		return 0;
	}
}
