#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>

char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                         "do","double","else","enum","extern","float","for","goto",
                         "if","int","long","register","return","short","signed",
                         "sizeof","static","struct","switch","typedef","union",
                         "unsigned","void","volatile","while"};
int isKeyword(char buffer[]){
    int flag = 0;

    for(int i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }

    return flag;
}

void lexicalAnalyser(){
    char ch, buffer[15], operators[] = "+-*/%=";
    FILE *fp;

    fp = fopen("program.txt","r");


    int keyWordCount = 0;
    int identifierCount = 0 ;
    int operatorCount = 0;
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }

    int j = 0;

    while((ch = fgetc(fp)) != EOF){
        for(int i = 0; i < 6; ++i){
            if(ch == operators[i])
                operatorCount++;
                printf("%c is operator\n", ch);
        }

        if(isalnum(ch)){
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n') && (j != 0)){
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer) == 1){
                keyWordCount++;
                printf("%s is keyword\n", buffer);
            }
            else {
                identifierCount++;
                printf("%s is indentifier\n", buffer);
            }
        }

    }

    fclose(fp);

    return 0;
}