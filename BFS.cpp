#include <iostream>
#define MAX 10
class Node{
public:
    int cost;
    char obj;

    Node* LeftNode= nullptr;
    Node* RightNode= nullptr;
    Node(int o)
    {
        this->obj=o;
        //giving cost according to the object category
        {
            if (obj == '(' || obj == ')' || obj == '{' || obj == '}' || obj == '[' || obj == ']') {
                this->cost = 5;
            } else if (obj == '^') {
                this->cost = 4;
            } else if (obj == '*' || obj == '/') {
                this->cost = 3;
            } else if (obj == '+' || obj == '-') {
                this->cost = 2;
            } else {
                this->cost = 1;
            }
        }
    }
};

class BinaryTree{
public:
    Node *root;
    BinaryTree(Node &n)
    {root=&n;}
    void Add(Node &n)
    {
        Node* ptr;
        ptr=root;
        while(true){

            if(root->cost < n.cost){
                if(ptr->LeftNode!= nullptr){
                    ptr=ptr->LeftNode;
                }
                else{
                    ptr->LeftNode=&n;
                    break;
                }
            }
            else if(root->cost >= n.cost){
                if(ptr->RightNode!= nullptr){
                    ptr=ptr->RightNode;
                }
                else{
                    ptr->RightNode=&n;
                    break;
                }
            }
        }
    }
    void Inorder(Node *n){
        char obj;
        if(n->LeftNode!= nullptr){
            Inorder(n->LeftNode);
        }
        obj=n->obj;
        std::cout<<" "<<obj;
        if(n->RightNode!= nullptr){
            Inorder(n->RightNode);
        }
    }
    void Preorder(Node *n){
        char obj;
        if(n->LeftNode!= nullptr){
            Preorder(n->LeftNode);
        }
        if(n->RightNode!= nullptr){
            Preorder(n->RightNode);
        }
        obj=n->obj;
        std::cout<<" "<<obj;
    }
    void Postorder(Node *n) {
        char obj;
        obj = n->obj;
        std::cout << " " << obj;
        if (n->LeftNode != nullptr) {
            Postorder(n->LeftNode);
        }
        if (n->RightNode != nullptr) {
            Postorder(n->RightNode);
        }
    }
};
int main() {

    char arr[MAX];
    std::cout<<"enter the equation\n";
    std::cin>>arr;
    Node Start(arr[0]);
    BinaryTree root(Start);
    int i=1;
    while(arr[i]!='\0'){
        Node *newNode= new Node(arr[i]);
        root.Add(*newNode);
        i++;
    }
    std::cout<<"\nInorder \n";
    root.Inorder(&Start);
    std::cout<<"\nPostorder \n";
    root.Postorder(&Start);
    std::cout<<"\nPreorder \n";
    root.Preorder(&Start);

    return 0;
}

//there is an error in this code, i will verify it later, i think this one is a bit difficult