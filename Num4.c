/*
Romario Medeiros
Assignment Number 2
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
char line[1000];
int lineCount=0;
char lexeme[100];
char list[200][100];
int listCount=0;

void placeToken(char token[]);
void getToken(char linE[], int lineSize);

int main(void){

   /* Open the file for reading */
   char *lineBuf = NULL;  //stores line text
   size_t bufSize = 0;
   int lineCount = 0;
   ssize_t lineSize;  
   
   
   FILE *fp = fopen("FILENAME.in", "r");
   if (!fp){
      printf("Error opening file \n");
   }
   lineSize = getline(&lineBuf, &bufSize, fp);
   while (lineSize >= 0)
   {
      lineCount++;
      getToken(lineBuf, lineSize);
      lineSize = getline(&lineBuf, &bufSize, fp);
   }
   free(lineBuf);
   lineBuf = NULL;
   fclose(fp);
   
   
   
	//print tokens from array
	int i;
	printf("List of tokens:\n");
	for(i=0; i<listCount; i++){
	int j=0;
		while(list[i][j]!='\0'){
			
			printf("%c",list[i][j]);
			j++;
		}
		printf("\n");
		
	}

   return 0;
}

void getToken(char linE[], int lineSize){ //find token
	int i;
   for(i=0; linE[i]!='\0';i++){
   	char token[100];
      if(linE[i]=='#'){
         return;
      }
      else if(linE[i]=='\"'){
         int j=i+1;
         while(linE[j]!='\"'){
            j++;
         }
         i=j;
      }
      else if(linE[i]=='@' || linE[i]=='$' || linE[i]=='%'){
         int j=i+1;
         int s=0;
         while(j<strlen(linE)){
         	if(linE[j]=='=' || linE[j]==' '){
         		break;
         	}
            token[s]=linE[j];
            token[s+1]='\0';
            s++;
            j++;
         }
         i=j;
         placeToken(token);
      }
      else if(linE[i]=='s' && linE[i+1]=='u' && linE[i+2]=='b' && linE[i+3]==' '){
      	int j=i+4;
        int s=0;
        while(j<strlen(linE)){
        	if(linE[j]=='{' || linE[j]==' '){
        		break;
        	}
           token[s]=linE[j];
           token[s+1]='\0';
           s++;
           j++;
        }
        i=j;
        placeToken(token);
      }
   }
}
//places new token in 2d string array list
void placeToken(char token[]){
	
   if(listCount==0){
      strcpy(list[0],token);
      int i;
      listCount++;
   }
   else{ //check to see if token is already in list
   	int contains=1;
   	int i;
      for(i=0; i<listCount; i++){
         if(strcmp(token, list[i]) == 0){ //found match
            contains=0;
         }
      }
         if(contains==1){ //if not in array
            strcpy(list[listCount],token);
            listCount++;
         }
      
   }
   
}

