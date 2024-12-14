#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} node;
node* create_node(char data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
void decode_huff(node* root, const char* s) {
    node* current = root;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current != NULL && current->left == NULL && current->right == NULL) {
            printf("%c", current->data);  
            current = root;               
        }
    }
}
int main() {
    node* root = create_node('\0');
    root->left = create_node('\0');
    root->right = create_node('A');
    root->left->left = create_node('B');
    root->left->right = create_node('C');

    const char* encoded_string = "0100110";

    printf("Decoded string: ");
    decode_huff(root, encoded_string);
    printf("\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}