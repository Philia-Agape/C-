#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//const char* englishToMorse(char);
const char* englishToMorse(char morse){
    char* Morse = "eeee";
    switch (morse){
    case 'a': Morse = ".-";
        break;
    case 'b': Morse = "-...";
        break;
    case 'c': Morse = "-.-.";
        break;
    case 'd': Morse = "-..";
        break;
    case 'e': Morse = ".";
        break;
    case 'f': Morse = "..-.";
        break;
    case 'g': Morse = "--.";
        break;
    case 'h': Morse = "....";
        break;
    case 'i': Morse = "..";
        break;
    case 'j': Morse = ".---";
        break;
    case 'k': Morse = "-.-";
        break;
    case 'l': Morse = ".-..";
        break;
    case 'm': Morse = "--";
        break;
    case 'n': Morse = "-.";
        break;
    case 'o': Morse = "---";
        break;
    case 'p': Morse = ".--.";
        break;
    case 'q': Morse = "--.-";
        break;
    case 'r': Morse = ".-.";
        break;
    case 's': Morse = "...";
        break;
    case 't': Morse = "-";
        break;
    case 'u': Morse = "..-";
        break;
    case 'v': Morse = "...-";
        break;
    case 'w': Morse = ".--";
        break;
    case 'x': Morse = "-..-";
        break;
    case 'y': Morse = "-.--";
        break;
    case 'z': Morse = "--..";
        break;
    case 'A': Morse = ".-";
        break;
    case 'B': Morse = "-...";
        break;
    case 'C': Morse = "-.-.";
        break;
    case 'D': Morse = "-..";
        break;
    case 'E': Morse = ".";
        break;
    case 'F': Morse = "..-.";
        break;
    case 'G': Morse = "--.";
        break;
    case 'H': Morse = "....";
        break;
    case 'I': Morse = "..";
        break;
    case 'J': Morse = ".---";
        break;
    case 'K': Morse = "-.-";
        break;
    case 'L': Morse = ".-..";
        break;
    case 'M': Morse = "--";
        break;
    case 'N': Morse = "-.";
        break;
    case 'O': Morse = "---";
        break;
    case 'P': Morse = ".--.";
        break;
    case 'Q': Morse = "--.";
    }
    const char* ans = Morse;
    return ans;
}

//char morseToEnglish (const char*);
char morseToEnglish(const char* alpha){
    char Alpha = ' ';
    
    if(strcmp(alpha,"/") == 0) Alpha = ' ';
    else if (strcmp(alpha,"eeee") == 0) Alpha = '#';
    else{
       for(int i=0;i<26;++i){
          if(strcmp(alpha,englishToMorse((char)('A'+i))) == 0){
              Alpha = (char)('A'+i);
              break;
          }
       }   
    } 
    /*switch (alpha)
    {
    case ".-": Alpha = 'a';
        break;
    case "-...": Alpha = 'b';
        break;
    case "-.-.": Alpha = 'c';
        break;
    case "-..": Alpha = 'd';
        break;
    case ".":  Alpha = 'e';
        break;
    case "..-.": Alpha= 'f';
        break;
    case "--.": Alpha= 'g';
        break;
    case "....": Alpha= 'h';
        break;
    case "..": Alpha= 'i';
        break;
    case ".---": Alpha= 'j';
        break;
    case "-.-": Alpha= 'k';
        break;
    case ".-..": Alpha= 'l';
        break;
    case "--": Alpha= 'm';
        break;
    case "-.": Alpha = 'n';
        break;
    case "---": Alpha = 'o';
        break;
    case ".--.": Alpha = 'p';
        break;
    case "--.-": Alpha= 'q';
        break;
    case ".-.": Alpha= 'r';
        break;
    case "...": Alpha= 's';
        break;
    case "-":   Alpha= 't';
        break;
    case "..-": Alpha= 'u';
        break;
    case "...-": Alpha= 'v';
        break;
    case ".--": Alpha='w';
        break;
    case "-..-": Alpha= 'x';
        break;
    case "-.--": Alpha= 'y';
        break;
    case "--..": Alpha ='z';
        break;
    case ".-": Alpha = 'A';
        break;
    case "-...": Alpha = 'B';
        break;
    case "-.-.": Alpha = 'C';
        break;
    case "-..": Alpha = 'D';
        break;
    case ".":  Alpha = 'E';
        break;
    case "..-.": Alpha= 'F';
        break;
    case "--.": Alpha= 'G';
        break;
    case "....": Alpha= 'H';
        break;
    case "..": Alpha= 'I';
        break;
    case ".---": Alpha= 'J';
        break;
    case "-.-": Alpha= 'K';
        break;
    case ".-..": Alpha= 'L';
        break;
    case "--": Alpha= 'M';
        break;
    case "-.": Alpha = 'N';
        break;
    case "---": Alpha = 'O';
        break;
    case ".--.": Alpha = 'P';
        break;
    case "--.-": Alpha= 'Q';
        break;
    case ".-.": Alpha= 'R';
        break;
    case "...": Alpha= 'S';
        break;
    case "-":   Alpha= 'T';
        break;
    case "..-": Alpha= 'U';
        break;
    case "...-": Alpha= 'V';
        break;
    case ".--": Alpha='W';
        break;
    case "-..-": Alpha= 'X';
        break;
    case "-.--": Alpha= 'Y';
        break;
    case "--..": Alpha= 'Z';
        break;
    }*/
    return Alpha;
}

int main(int argc, char** argv){
    FILE *fr, *fw;
    fr = fopen (argv[1],"r");
    fw = fopen (argv[3],"w");
    char line[256];
    
    char c;
    //Morse to english
    if(strcmp(argv[2],"-e") == 0){ //compare if argv[2] is equal to -e 判断两者是否相等
        while (fgets(line,256,fr)){ //read the text to fr
           int len = strlen(line);
           if (len > 0 && line[len-1] == '\n') line[--len] = '|';
           char *str=strtok(line,"|");//这是把fr 里的 | 都展示出来。
           while(str!=NULL){//不等于NULL就说明里面有东西，然后就call
              //calling morseToEnglish 然后储存进去
              c=toupper(morseToEnglish(str));
              //print 进 fw 
              fprintf(fw,"%c",c);
              //printing c to the console//编译器
              printf("%c",c);
              str=strtok(NULL,"|");//再输出到编译器里
           }
           //adding new line to the file
           fprintf(fw,"%s","\n");// send to the output stream 
           printf("\n");// send the stdout
        }
        
        fclose(fr);                                
   }
   //english to Morse
   else if(strcmp(argv[2],"-mc")  == 0){
      while(fgets(line, 256, fr)){        
         int len = strlen(line);
         if (len > 0 && line[len-1] == '\n') line[--len] = '\0'; 
         //process each line character by character
         for(int i = 0; line[i] != '\0'; i++){
             if(line[i] == ' ') fprintf(fw, "/");
             else{ 
                fprintf(fw, "%s", englishToMorse(tolower(line[i])));
                //fprintf("%s", englishToMorse(tolower(line[i])));
             }   
             if(line[i+1] == '\0') fprintf(fw, "\n");
             else fprintf(fw, "|");   
         }
      }
      
      fclose(fr);   
   }
   //improper command line!
   else
      printf("Wrong command given!!\n");   
    
    
   fclose(fw);
   return 0;
}
