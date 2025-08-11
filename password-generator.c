#include <stdio.h>
#include <errno.h> //Used for error handling
#include <fcntl.h> //Used for file control in Unix-like operating systems (flags)
#include <unistd.h> //Used for file control in Unix-like operating systems (open() and close() are defined inside)

int main() {

    char characters[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    '!', '@', '#', '$', '^', '&', '*', '(', ')', '_', '+'};

    int i;
    int length;
    unsigned char raw_byte[225];

    //open("path",flag) - can add multiple flags using pipe | 
    //if file does not exist it is created
    int fd = open("/dev/urandom", O_RDONLY);
    
    //if fd = -1 probably the file wasn't found 
    if (fd == -1){
        perror("Error");
    } 
    else{
        printf("Password-Length: ");
        scanf("%d", &length);
        read(fd, raw_byte, length);
    }
    close(fd);

    //used to get characters[] bytes
    /*int characters_bytes = sizeof(characters)/sizeof(characters[0]);
    printf("%d\n",characters_bytes);*/ 

    for(i=0; i<length; i++){
        if(raw_byte[i]<=73){
            //printf("%d ",raw_byte[i]);
            //u can use %d, %X etc depending on what u want to print
            //i think the chances for printing the 3 first characters are a bit higher but i dont know how to fix this without adding more characters
            printf("%c",characters[raw_byte[i]]);
        }
        else{
            while(raw_byte[i]>73){
                raw_byte[i] = raw_byte[i] -74;
                if(raw_byte[i]<=73){
                    //printf("%d ",raw_byte[i]);
                    printf("%c",characters[raw_byte[i]]);
                }
            }
        }
    }

    return 0;
}