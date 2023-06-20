#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>






struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
};





void AddingTree(struct tree **node, int a);
void ShowingTree(struct tree *node);
void ChangeNode(struct tree *node);
struct tree *DeletingNode(struct tree *node, int z);
struct tree* minimum(struct tree* node);

bool printLevelLeftToRight(struct tree* root, int level);
bool printLevelRightToLeft(struct tree* root, int level);
void spiralOrderTraversal(struct tree* root);

int main() {
    
    struct tree *node = NULL;
    

    printf("Start creating the tree:");
    
    

    

    while (1) {

        fflush(stdin);

        puts("Choose the option between the following:");
        puts("1 --- Add the tree");
        puts("2 --- Show the tree");
        puts("3 --- Changing the node");
        puts("4 --- Delete node");
        puts("5 --- Spiral checkout");
        puts("6 --- Exit");

        int input;

        while (!scanf("%d", &input) || input <= 0) {
            rewind(stdin);
            printf("Incorrect input try again\n");

        }

        if (input > 7) {
            printf("There is no such option");
            rewind(stdin);
            continue;
        }
        int i;
        
        switch (input) 
        {
            case 1: 
                printf("Input the nodes:\n");
                while(scanf("%d", &i))
                    AddingTree(&node,  i);
                break;
            case 2: ShowingTree(node); break;

            case 3: ChangeNode(node); break;

            case 4:
                printf("Input the node you want to delete:\n");
                int j;
                while (!scanf("%d", &j)) {
                    rewind(stdin);
                    printf("\nIncorrect input, try again please:\n");
                }
                DeletingNode(node, j); break;
                
            case 5: printf("\n\nSpiral walk:\n"); spiralOrderTraversal(node); printf("\n"); break;

            case 6: return 0;
        }
        


    }

    

   
    
    return 0;
}







void AddingTree(struct tree **node, int a)
{
    
    struct tree* ptr;
    if (NULL == ((*node)))  //Если дерева нет, то добавляем первый корневой элемент
    {
        ((*node)) = (struct tree*)calloc(1, sizeof(struct tree)); //Выделяем память под звено дерева
        ((*node))->data = a; //Записываем данные в звено
        ((*node))->left = NULL; //Подзвенья инициализируем пустотой во избежание ошибок
        ((*node))->right = NULL;
    }

    else if (a < ((*node))->data)   //Если нововведенный элемент x меньше чем элемент x из корня дерева, уходим влево
    {
        if (((*node))->left != NULL) AddingTree(&((*node))->left, a); //При помощи рекурсии помещаем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            ((*node))->left = (struct tree*)calloc(1, sizeof(struct tree));  //Выделяем память левому подзвену. 
            ((*node))->left->left = ((*node))->left->right = NULL; //У левого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            ((*node))->left->data = a; //Записываем в левое подзвено записываемый элемент 
        }
    }


    if (a > ((*node))->data)   //Если нововведенный элемент x больше чем элемент x из корня дерева, уходим вправо
    {
        if (((*node))->right != NULL) AddingTree(&(*node)->right, a); //При помощи рекурсии заталкиваем элемент на свободный участок
        else //Если элемент получил свой участок, то
        {
            ((*node))->right = (struct tree*)calloc(1, sizeof(struct tree));   //Выделяем память правому подзвену. 
            ((*node))->right->left = ((*node))->right->right = NULL; //У правого подзвена будут свои левое и правое подзвенья, инициализируем их пустотой
            ((*node))->right->data = a; //Записываем в правое подзвено записываемый элемент 
        }
    }
    system("cls");
    
    

    
    return 0;
}

void ShowingTree(struct tree *node) {

    

    if (node != NULL) //Пока не встретится пустое звено
    {

        printf("%d ", node->data);
        ShowingTree(node->left);
        printf("\n");
        ShowingTree(node->right);

    }
    return 0;
}

void ChangeNode(struct tree *node) {

    system("cls");


    int input;

    


    while (1) {


        int tryout;

        while (!scanf("%d", &tryout) || tryout <= 0) {
            rewind(stdin);
            printf("Incorrect input try again\n");

        }

    }
}

struct tree *DeletingNode(struct tree *node, int z) {

    system("cls");

    

    if (node == NULL)
        return node;
    if (z < node->data)
        node->left = DeletingNode((node->left), z);
    else if (z > node->data)
        node->right = DeletingNode(node->right, z);
    else if (node->left != NULL && node->right != NULL)
    {
        node->data = minimum(node->right)->data;
        node->right = DeletingNode(node->right, node->data);
    }
    else
        if (node->left != NULL)
            node = node->left;
        else
            node = node->right;
    return node;
    
    printf("The chosen one was deleted.\n");
   


    return 0;
}

struct tree* minimum(struct tree* node)
{
    if (node->left == NULL)
        return node;
    return minimum(node->left);
}


bool printLevelLeftToRight(struct tree* root, int level) {
    if (root == NULL) {
        return false;
    }

    if (level == 1) {
        printf("%d ", root->data);
        return true;
    }

    bool left = printLevelLeftToRight(root->left, level - 1);
    bool right = printLevelLeftToRight(root->right, level - 1);

    return left || right;
}

bool printLevelRightToLeft(struct tree* root, int level) {
    if (root == NULL) {
        return false;
    }

    if (level == 1) {
        printf("%d ", root->data);
        return true;
    }
    bool right = printLevelRightToLeft(root->right, level - 1);
    bool left = printLevelRightToLeft(root->left, level - 1);
    

    return right || left;
}

void spiralOrderTraversal(struct tree* root) {
    
    if (root == NULL)
        return;

    int level = 1;

    while (printLevelLeftToRight(root, level++) && printLevelRightToLeft(root, level++));
}





