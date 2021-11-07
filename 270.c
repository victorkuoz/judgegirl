#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct var {
    int val;
    char *name;
} Var;

void initialize_vars ( char *input, Var *var, int *n ) {
    char *head = input, *rear = input;
    for ( ; (*rear) != '\0'; rear++ ) {
        if ( (*rear) == ' ' ) {
            (*rear) = '\0';
            var[*n].name = head;
            head = (rear+=3);
            var[*n].val = atoi(head);
            while ( (*rear) != ' ' )
                rear++;
            head = (++rear);
            (*n)++;
        }
    }
    return;
}

void initialize_lines ( char **line, int *n ) {
    while (true) {
        char *buf = (char*) calloc(128, sizeof(char)), c;
        scanf("%[^\n]%c", buf, &c);
        if ( buf[0] == '\0' )
            break;
        line[*n] = buf;
        (*n)++;
    }
    return;
}

int var_idx ( char *cur, Var *var, int n ) {
    for ( int i= 0; i < n; i++ )
        if ( strcmp(cur, var[i].name) == 0 )
            return i;
}

int execute ( int l, char *line, Var *var, int n ) {
    //printf("execute %s\n", line);
    if ( line[0] == 'S' && line[1] == 'T' && line[2] == 'O' && line[3] == 'P' && line[4] == '\0' )
        return (-1);
    if ( line[0] == 'G' && line[1] == 'O' && line[2] == 'T' && line[3] == 'O' && line[4] == ' ' )
        return atoi(line+5);
    if ( line[0] == 'P' && line[1] == 'R' && line[2] == 'I' && line[3] == 'N' && line[4] == 'T' && line[5] == ' ' ) {
        char *cur = (line+6);
        printf("%d\n", var[var_idx(cur, var, n)].val);
        return (l+1);
    }
    if ( line[0] == 'I' && line[1] == 'F' && line[2] == ' ' ) {
        char *var_1 = (char*) calloc(8,sizeof(char)), *var_2 = (char*) calloc(8,sizeof(char)), *head = (line+3), *rear = (line+3);
        
        while ( rear[0] != ' ')
            rear++;
        strncpy(var_1, head, (rear-head));
        head = (rear+=1);
        int idx_1 = var_idx(var_1, var, n);

        int type;
        if ( head[0] == '<' ) {
            if ( head[1] == '=' )
                type = 3;
            else
                type = 2;
        }
        else if ( head[0] == '>' ) {
            if ( head[1] == '=' )
                type = 7;
            else
                type = 6;
        }
        else if ( head[0] == '=')
            type = 11;
        else
            type = 15;
        head = rear = (head+=(type%4));

        while ( rear[0] != ' ')
            rear++;
        strncpy(var_2, head, (rear-head));
        head = (rear+=1);
        int idx_2 = var_idx(var_2, var, n);

        switch (type) {
            case 2 :
                if ( var[idx_1].val >= var[idx_2].val )
                    return (l+1);
                break;
            case 3 :
                if ( var[idx_1].val > var[idx_2].val )
                    return (l+1);
                break;
            case 6 :
                if ( var[idx_1].val <= var[idx_2].val )
                    return (l+1);
                break;
            case 7 :
                if ( var[idx_1].val < var[idx_2].val )
                    return (l+1);
                break;
            case 11 :
                if ( var[idx_1].val != var[idx_2].val )
                    return (l+1);
                break;
            case 15 :
                if ( var[idx_1].val == var[idx_2].val )
                    return (l+1);
                break;
            default :
                exit(0);
        }
        return execute(l, head, var, n);
    }
    else {
        char *var_1 = (char*) calloc(8,sizeof(char)), *var_2 = (char*) calloc(8,sizeof(char)), *var_3 = (char*) calloc(8,sizeof(char)), *head = line, *rear = line;

        while( rear[0] != ' ' )
            rear++;
        strncpy(var_1, head, (rear-head));
        head = (rear+=3);
        int idx_1 = var_idx(var_1, var, n);

        while( rear[0] != ' ' )
            rear++;
        strncpy(var_2, head, (rear-head));
        char op = rear[1];
        head = (rear+=3);
        int idx_2 = var_idx(var_2, var, n);

        strcpy(var_3, head);
        int idx_3 = var_idx(var_3, var, n);

        switch (op) {
            case '+' :
                var[idx_1].val = var[idx_2].val + var[idx_3].val;
                break;
            case '-' :
                var[idx_1].val = var[idx_2].val - var[idx_3].val;
                break;
            case '*' :
                var[idx_1].val = var[idx_2].val * var[idx_3].val;
                break;
            case '/' :
                var[idx_1].val = var[idx_2].val / var[idx_3].val;
                break;
            case '%' :
                var[idx_1].val = var[idx_2].val % var[idx_3].val;
                break;
            default :
                exit(0);
        }
        return (l+1);
    }
    return (-1);
}

int main(void) {
    int num_var = 0, num_line = 1;
    Var *var = (Var*) calloc(100, sizeof(Var));
    char **line = (char**) calloc(1000, sizeof(char*)), c;

    
    line[0] = (char*) calloc(1024, sizeof(char));
    scanf("%[^\n]%c", line[0], &c);
    initialize_vars(line[0], var, &num_var);
    initialize_lines(line, &num_line);

    int l = 1;
    while ( l > 0 )
        l = execute(l, line[l], var, num_var);
    return 0;
}