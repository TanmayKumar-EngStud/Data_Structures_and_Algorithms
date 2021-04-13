#include <iostream>
class Node{
public:
    Node* prev= nullptr;
    int Val=0;
    Node* next= nullptr;
    Node(int item){
        Val=item;
        prev= nullptr;
        next= nullptr;
    }
};
class List{
public:
    Node* head;
    List(Node *item){
        head=item;
    }
    void AddItem(Node *item) const{

        Node *ptr=head;
        while(ptr->next!= nullptr)
        {
            ptr=ptr->next;
        }
        item->prev=ptr;
        ptr->next=item;
    }
    void Display() const{
        Node *ptr=head;
        while(ptr!=nullptr)
        {
            std::cout<<ptr->Val<<" ";
            ptr=ptr->next;
        }

        std::cout<<std::endl;
    }
    int SearchIndex(int i) const{
        Node *ptr=head;
        int index=0;
        while(ptr->next!= nullptr)
        {
            if(ptr->Val==i){
                break;
            }
            index++;
            ptr=ptr->next;
        }
        return index;
    }
    void Delete(int i) const{
        Node *ptr=head;
        while(ptr->next!= nullptr){
            if(ptr->Val==i){
                Node *temp=ptr;
                ptr->prev->next=ptr->next;
                ptr->next->prev=ptr->prev;
            }
            ptr=ptr->next;
        }
    }
};

int main() {
    std::cout <<"what value you want to add in List?\n";
    int temp;
    std::cin>>temp;
    Node Start(temp);
    List root(&Start);
    std::cout<<"Want to add mode values?(y/n)\t";
    char ans;
    std::cin>>ans;

    while (ans=='y'||ans=='Y'){
        std::cout <<"what value you want to add in List?\n";
        std::cin>>temp;
        Node *newNode=new Node(temp);
        root.AddItem(newNode);
        std::cout<<"Want to add mode values?(y/n)\t";
        std::cin>>ans;
    }

    std::cout<<"Want to operate something?(y/n)\t";
    char ans2;
    std::cin>>ans2;
    while (ans2=='y'||ans2=='Y'){
        std::cout<<" 1. Display\n"
                   " 2. Delete\n"
                   " 3. Search index\n"
                   " 4. Add Item\n";
        int reply;
        std::cin>>reply;
        if (reply==1)   {root.Display();}
        else if(reply==2) {
            std::cout<<"which item you want to delete?\n";
            int x;
            std::cin>>x;
            root.Delete(x);
            std::cout<<"Item: "<<x<<" is deleted\n";
        }
        else if(reply==3){
            std::cout<<"which item index you want to search?\n";
            int item;
            std::cin>>item;
            int index=root.SearchIndex(item);
            std::cout<<"item "<<item<<" is at index:\t"<<index<<std::endl;
        }
        else if(reply==4){
            std::cout<<"which item you want to add?\n";
            int item;
            std::cin>>item;
            Node add(item);
            root.AddItem(&add);
            std::cout<<"item inserted!!\n";
        }
        else{
            std::cout<<"enter valid value!!\n";
        }
    }
    return 0;
}