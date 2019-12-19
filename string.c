#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

#define MaxLineLength 256
#define MaxWordsInLine 128
#define MaxWordLength 30

bool findWordInLine(char Line[], char Word[]){
    int WordLength = strlen(Word);
    int LineLength = strlen(Line);
    if(WordLength > LineLength) return false;
    char FirstLetter = Word[0];
    bool Found = false; //main boolean variable - indicates if the word was found in the line
    for (int i = 0 ; i<LineLength && !Found; i++){
        char currentChar = Line[i];
        if(FirstLetter == currentChar){
            bool Equal = true; //minor boolean variable - indicates if current place in line has the word
            for (int j = 1; j < WordLength && Equal; j++){
                char currentWordChar = Word[j];
                char currentLineChar = Line[i+j];
                if(currentWordChar != currentLineChar){
                    Equal = false;
                }
            }//end 2nd for
            if (Equal) {Found = true;}
        }//end if found first character of word
    }//end 1st for
    return Found;
}//end findWordInLine

void printSimilarWordsInWordArray(char* AllWords[], int numOfWords, char Word[]){
    
    int wordLength = strlen(Word);
    for (size_t i = 0; i < numOfWords; i++)//for each word in the given array
    {   
        int currentWordLength = strlen(AllWords[i]);
        if(currentWordLength==wordLength){ //equal length case (length of given word and current word)
            if(strcmp(AllWords[i],Word)==0){
                printf("%s\n", Word);
                continue;
            }
        }

        if (currentWordLength-1==wordLength){//currentWord's length is greater by 1 case
            char currentWord[currentWordLength];
            strcpy(currentWord, AllWords[i]); 

            char subWord[wordLength];
            bool keepWorking = true;   
            for (size_t j = 0; j < currentWordLength && keepWorking; j++)
            {
                memcpy(subWord, currentWord, j);
                memcpy(subWord+j, currentWord+j+1, currentWordLength-j-1);
                *(subWord+wordLength) = '\0';
                if(strcmp(subWord,Word)==0){
                    printf("%s\n", currentWord);
                    keepWorking=false;
                }
            }//end for, omiting one letter each time from the currentWord  
        }//end if currentWordLength-1 == wordLength
    }//end for each word in given array
}//end printSimilarWordsInWordArray

void substring(char s[], char sub[], int start, int end) {
   int c = 0;
   while ( c < end) {
      sub[c] = s[c+start];
      c++;
   }
   sub[c] = '\0';
}
void append(char str1[]){ //adds space at the end of the line
    char str[strlen(str1)+1];
    int i = 0, j = 0; 
    while (str1[i] != '\0' && str1[i]!='\n') { 
        str[j] = str1[i]; 
        i++; 
        j++; 
    }
    str[j]=' ';
    j++; 
    str[j] = '\0';
    strcpy(str1,str);
    
}
int main()
{   
    char line[MaxLineLength];
    fgets(line, sizeof(line), stdin);
    char* Option = &line[strlen(line)-2];
    char* Line = line;
    char Word[MaxWordLength];
    substring(line,Word,0,strlen(Line)-3); 
    if(*Option == 'a'){
        while (fgets(line, MaxLineLength , stdin) != NULL){
            if (findWordInLine(line,Word))
            {
                printf("%s",line);
            }
        }
    }//end 'a' case
    else if (*Option == 'b')
    {
        int j = 0;
        int NumOfWordsInLine = 0;
        char* Words[MaxWordsInLine];
        while (fgets(line, MaxLineLength , stdin) != NULL){
            if(j != 0){
                char delim[] = " ";
                append(line);
                char *ptr = strtok(line, delim);
                int i = 0;
                while (ptr != NULL){
                    Words[i] = ptr;
                    ptr = strtok(NULL, delim);
                    i++;
                }
                NumOfWordsInLine = i;

                printSimilarWordsInWordArray(Words,NumOfWordsInLine,Word);
            }
            j++;
        }    
    }//end 'b' case
    return 0;
    
}

