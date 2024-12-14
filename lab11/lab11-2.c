#include <stdio.h>
#include <stdbool.h>

bool checkValidString(char *s) {
    int stack_size = 1000; 
    int stack[stack_size][2]; 
    int top = -1;
    stack[++top][0] = 0;
    stack[top][1] = 0;

    while (top >= 0) {
        int index = stack[top][0];
        int balance = stack[top][1];
        top--;

        if (balance < 0) {
            continue;
        }
        if (index == strlen(s) && balance == 0) {
            return true;
        }
        if (index < strlen(s)) {
            if (s[index] == '(') {
                stack[++top][0] = index + 1;
                stack[top][1] = balance + 1;
            } else if (s[index] == ')') {
                stack[++top][0] = index + 1;
                stack[top][1] = balance - 1;
            } else {  
                stack[++top][0] = index + 1;
                stack[top][1] = balance + 1;

                stack[++top][0] = index + 1;
                stack[top][1] = balance - 1;

                stack[++top][0] = index + 1;
                stack[top][1] = balance;
            }
        }
    }
    return false;
}

int main() {
    printf("%d\n", checkValidString("()"));       // Should print 1 (true)
    printf("%d\n", checkValidString("(*)"));      // Should print 1 (true)
    printf("%d\n", checkValidString("(*))"));     // Should print 1 (true)

    return 0;
}