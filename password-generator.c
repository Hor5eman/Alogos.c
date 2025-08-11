#include <stdio.h>
#include <errno.h> 
#include <fcntl.h> 
#include <unistd.h> 

int main() {

    char characters[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '!', '@', '#', '$', '^', '&', '*', '(', ')', '_', '+'};

    int i;
    int length;
    unsigned char raw_byte[225];


    int fd = open("/dev/urandom", O_RDONLY);
    
 
    if (fd == -1){
        perror("Error");
    } 
    else{
        printf("Password-Length: ");
        scanf("%d", &length);
        read(fd, raw_byte, length);
    }
    close(fd);

    for(i=0; i<length; i++){
        if(raw_byte[i]<=73){

            printf("%c",characters[raw_byte[i]]);
        }
        else{
            while(raw_byte[i]>73){
                raw_byte[i] = raw_byte[i] -74;
                if(raw_byte[i]<=73){
 
                    printf("%c",characters[raw_byte[i]]);
                }
            }
        }
    }

    return 0;
}
