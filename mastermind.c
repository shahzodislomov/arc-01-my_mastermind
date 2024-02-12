#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int function_length(char* str) {
    int i = 0;
    while(str[i++]);
    return i - 1;
}

void my_copyright(char* destab, char* sourcexxs) {
    for(int i = 0; i < function_length(sourcexxs); i++) {
        destab[i] = sourcexxs[i];
    }
}

int my_function(char* strab, char numbw) {
    for(int i = 0; i < function_length(strab); i++) {
        if(strab[i] == numbw) return 1;
    }
    return 0;
}

char* random_g() {
    char* random_num = calloc(5, sizeof(char));
    int i = 0;
    char temp;
    srand(time(0));

    while(i < 4) {
        temp = rand() % 9 + 48;

        if(my_function(random_num, temp) == 0) {
            random_num[i] = temp;
            i++;
        }
    }
    return random_num;
}

char* my_scanf() {
    char n = '>';
    write(1, &n, 1);
    fflush(stdout);
    char* user_input = calloc(100, sizeof(char));
    int i = 0;
    char temp;

    while(read(0, &temp, 1)) {
        if(temp == '\n') {
            return user_input;
        }
        user_input[i] = temp;
        i++;
    }
    return NULL;
}

int user_function(char* user_input1) {
    for(int i = 0; i < function_length(user_input1); i++) {
        if(!(user_input1[i] >= 48 && user_input1[i] <= 56)) return 0;
    }
    return 1;
}

int dup_function(char* user_input) {
    for(int i = 0; i < function_length(user_input); i++) {
        for(int j = i+1; j < function_length(user_input); j++) {
            if(user_input[i] == user_input[j]) return 0;
        }
    }
    return 1;
}

int good_func(char* sc_code, char* user_code) {
    int counter = 0;
    for(int i = 0; i < function_length(sc_code); i++) {
        if(sc_code[i] == user_code[i]) counter++;
    }
    return counter;
}

int function_scp(char* sc_code, char* user_code) {
    int counter = 0;
    for(int i = 0; i < function_length(sc_code); i++) {
        for(int j = 0; j < function_length(user_code); j++) {
            if(sc_code[i] == user_code[j] && i != j) counter++;
        }
    }
    return counter;
}

int check_function(char* user_input) {
    if(function_length(user_input) != 4) return 0;
    if(user_function(user_input) == 0) return 0;
    if(dup_function(user_input) == 0) return 0;
    return 1;
}

void game_function(int attempts, char* sc_code) {
    printf("are you going to find secret code?\nenter the number\n");
    char* user_input;
    for(int i = 0; i < attempts; i++) {
        printf("---\nRound %d\n", i);
        user_input = my_scanf();
        if(user_input == NULL) {
            free(user_input);
            return;
        }
        while (check_function(user_input) == 0) {
            free(user_input);
            printf("wrong input!\n");
            user_input = my_scanf();
        }
        int well = good_func(sc_code, user_input);
        if(well == 4) {
            free(user_input);
            printf("congratulation you did it!\n");
            return;
        } else {
            printf("well placeded: %d\n", well);
            printf("miss placeded: %d\n", function_scp(sc_code, user_input));
        }
    }
}

int main(int argc, char** argv) {
    int i = 1; 
    char* sec_num = NULL;
    int attempts = 10;
    while(i < argc) {
        if(strcmp(argv[i], "-c") == 0) {
            i++;
            sec_num = malloc(sizeof(char) * 5);
            my_copyright(sec_num, argv[i]);
        } else if (strcmp(argv[i], "-t") == 0) {
            i++;
            attempts = atoi(argv[i]);
        }
        i++;
    }
    if(sec_num == NULL) {
        sec_num = random_g();
    }
    game_function(attempts, sec_num);
    free(sec_num);
    return 0;
}
