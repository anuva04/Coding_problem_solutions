
#include <stdio.h>
#include <string.h>

int main(){
    char S[200];
    gets(S);
    int length = strlen(S);
    int x=0, y=0;
    for(int i=0; i<length; i++){
        if(S[i] == 'L'){
            x--;
        }
        else if(S[i] == 'R') {
            x++;
        }
        else if(S[i] == 'U') {
            y++;
        }
        else if(S[i] == 'D') {
            y--;
        }
    }
   printf("%d %d", x, y);
}
