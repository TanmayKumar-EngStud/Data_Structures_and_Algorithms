#include <iostream>
class Node{
public:
    int value;
    Node *left= nullptr;
    Node *right= nullptr;
    Node *parent= nullptr;
    Node(int val){
        this->value=val;
    }
};
void Swap(Node &n, Node &l){
    int temp=l.value;
    l.value=n.value;
    n.value=temp;
}
Node* BFS(Node *ptr){//order of left to right
    if(ptr->left== nullptr||ptr->right==nullptr){
        return ptr;
    }
    else if(ptr->parent!= nullptr && ptr->parent->right!= nullptr){
        if(ptr->parent->right->left==nullptr||ptr->parent->right->left== nullptr){
            ptr=ptr->parent->right;
            BFS(ptr);
        }
    }
    else{
        ptr=ptr->left;
        BFS(ptr);
    }
}
class Heap{
public:
    Node *root;
    Heap(Node &n)
    {root=&n;}
    void MaxHeapify(Node *n){
        if(n->right!= nullptr){
            MaxHeapify(n->right);
        }
        if(n->left!= nullptr){
            MaxHeapify(n->left);
        }

        if(n->parent!= nullptr &&n->parent->value < n->value){
            Swap(*n,*n->parent);
        }

    }
    void Add(Node *n){
        Node *ptr= root;
        while(true){
            ptr=BFS(root);
            if(ptr->left== nullptr){
                ptr->left=n;
                n->parent=ptr;
                MaxHeapify(root);

                break;
            }
            else if(ptr->right== nullptr){
                ptr->right=n;
                n->parent=ptr;
                MaxHeapify(root);
                break;
            }
        }
    }
    void Delete(Node *n){
        Node *ptr=root;
        if(n->parent== nullptr){
            ptr=BFS(root);
            Swap(*n,*ptr);
            if(n->parent->left==n){
                n->parent->left = nullptr;
                delete n;
            }
            else if(n->parent->right==n){
                n->parent->right = nullptr;
                delete n;
            }
        }//if n is root
        else{
            if(n->right== nullptr && n->left== nullptr){
                if(n->parent->left==n) {
                    n->parent->left= nullptr;
                    delete n;
                }
                else{
                    n->parent->right= nullptr;
                    delete n;
                }
            }//if n is a leaf node
            else{
                ptr=BFS(n);
                Swap(*n,*ptr);
                if(n->parent->left==n){
                    n->parent->left= nullptr;
                    delete n;
                }
                else{
                    n->parent->right= nullptr;
                    delete n;
                }
            }//if n is any other node
        }
        MaxHeapify(root);
    }
    Node* Find(Node* n,Node* TempRoot){
        Node *ptr = TempRoot;
        if(ptr->value==n->value){return ptr;}
        else if(ptr->right!= nullptr){Find(n,ptr->right);}
        else if(ptr->left!= nullptr){Find(n,ptr->left);}
    }
    void Inorder(Node *n){
        if(n->left!= nullptr){Inorder(n->left);}
        std::cout<<" "<<n->value;
        if(n->right!=nullptr){Inorder(n->right);}
    }
    void Preorder(Node* n){
        if(n->left!= nullptr){Inorder(n->left);}
        if(n->right!=nullptr){Inorder(n->right);}
        std::cout<<" "<<n->value;
    }
    void Postorder(Node* n){
        std::cout<<" "<<n->value;
        if(n->left!= nullptr){Inorder(n->left);}
        if(n->right!=nullptr){Inorder(n->right);}
    }
    void Display(){
        std::cout<<"Inorder:\t\t";
        Inorder(root);
        std::cout<<"\nPreorder:\t\t";
        Preorder(root);
        std::cout<<"\nPostorder:\t\t";
        Postorder(root);
        std::cout<<std::endl;
    }
};
int main() {
    std::cout<<"this is for heap\n";
    std::cout<<"Enter input:-\t";
    int n;
    std::cin>>n;
    Node t(n);//t is the root node of our heap
    Heap heap(t);
    int temp;
    while(std::cin>>temp){
        Node *n= new Node(temp);
        heap.Add(n);

    }// this  will take all the values that we need to input inside heap
    while(true){
        std::cout<<"\n1. Add"
                   "\n2. Delete"
                   "\n3. Display\n";
        int response;
        std::cin>>response;

        if(response==1){
            std::cout<<"which value(s) you want to add:\t";
            while(std::cin){
                int TempValue;
                std::cin>>TempValue;
                Node *n= new Node(TempValue);
                heap.Add(n);}
        }
        else if(response==2){
            std::cout<<"which value(s) you want to delete:\t";
            int TempVal;
            while(std::cin>>TempVal){
                Node *New= new Node(TempVal);
                heap.Find(New,&t);
                heap.Delete(New);
            }
        }
        else if(response==3){
            heap.Display();
        }
        else{
            break;}
    }
    return 0;
}