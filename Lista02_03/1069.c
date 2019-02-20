#include <stdio.h>

int main(){

    int i, stack, total,n;
    char input;

    scanf("%d", &n);
    getchar();
    
    for(i = 0; i < n; i++){
        stack = 0, total = 0;
    
        while(1){
            scanf("%c", &input);
            if(input == '\n')
                break;
            if(input == '<')
                stack++;
            else if(input == '>' && stack > 0){
                stack--;
                total++;
            }
            
        }
        printf("%d\n",(stack < 0 ? stack + total : total));       
    }
    

    return 0;
}
