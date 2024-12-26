#include<iostream>
using namespace std;
#include<conio.h>
#include<bits/stdc++.h>
int ascii=178,i=0;
char ch=ascii;
class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        next=nullptr;

    }
    node(int data,node* next){
        this->data=data;
        this->next=next;

    }
};
void add(node*& head,int data){
    system("cls");

    node* newnode=new node(data);
    if(head==nullptr){
        head= newnode;

    }
    else{

        node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertHead(node*& head,int val){
    if(head==nullptr){
        head=new node(val);


    }
    node* temp=new node(val);
    temp->next=head;
    head=temp;

}
void insertTail(node* head,int val){
    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node* newnode=new node(val);
    temp->next=newnode;
}
void insertPos(node*& head,int val,int k){
    if(head==nullptr){
        if(k==1){
            node* newnode=new node(val);
            head=newnode;
            return;

        }else{
            cout<<"NOT BE POSSIBLE";

        }
    }
    if(k==1){
        insertHead(head,val);

    }
    int cnt=0;
    node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k-1){
                node* newnode=new node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                break;

        }
        temp=temp->next;

    }




}
void insertval(node* &head,int val,int ele){
    if(head==nullptr){
        insertHead(head,val);

    }
    node* temp=head;

    while(temp->next!=nullptr){
        if(temp->data==ele){
            node* newnode=new node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                break;
        }
        temp=temp->next;

    }

}
void deleteHead(node*& head){
    if(head==nullptr){
        cout<<"Empty";
    }
    node* temp=head;
    head=head->next;
    // temp->next=nullptr;
    delete temp;

}
void deleteTail(node*& head){
    if(head==nullptr){
        cout<<"NO node available";

    }
    node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;

    }
    temp->next=nullptr;

}
void deletePos(node*& head,int k){
    if(head==nullptr){
        cout<<"NO node available";

    }
    node* temp=head;
    int cnt=0;
    node* prev=nullptr;

    while(temp->next!=nullptr){
        cnt++;

        if(cnt==k){
           prev->next=prev->next->next;
           free(temp);

            break;

        }
        prev=temp;

        temp=temp->next;

    }
}
void deleteVal(node* head,int val)
{
    if(head==nullptr){
        cout<<"NO node available";

    }
    node* temp=head;
    node* prev;

    while(temp->next!=nullptr){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;

        }
        prev=temp;
        temp=temp->next;
    }

}
void length(node* head){
    int cnt=0;
    node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;

    }
    cout<<"LENGTH OF LINKED LIST -> "<<cnt<<endl;

}
void search(node* head,int val){
    node* temp=head;
    int ele;
    int found=0;

    if(head==nullptr){
        cout<<"NO LINKED AVAILABLE "<<endl;
        return;

    }
    while(temp){
        if(temp->data==val){
            //
            found=1;
            ele=temp->data;


            break;
        }
        temp=temp->next;

    }
    if(found!=0){
        cout<<"SEARCH SUCCESSFULL "<<ele<<" FOUND"<<endl;
    }
    else{
        cout<<"SEARCH UNSUCCESSFULL"<<endl;
    }
}
void displayList(node* head){
    system("cls");

    if(head==nullptr){
        cout<<"empty list";


    }
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<"---->";
        temp=temp->next;
          if(temp==nullptr){
                cout<<"null";

            }

    }
}
void heading(){
    system("cls");
    
    cout<<"NOTE : PRESS THE ENTER KEY TO BACK TO MENU !!!"<<endl;

   cout<<"\n ";
    for(int m=0;m<=26;m++){
        cout<<ch;

    }
    cout<<" MENU DRIVEN USING LINKED LIST C++ ";
    for(int m=0;m<=26;m++){
        cout<<ch;

    }
}

int main(){

    node* head=nullptr;
    p:
    system("cls");

    int choice;
    heading();

        cout<<"\n\n"<<ch<<ch<<" 1.ADD DATA ";
        cout<<"\n\n"<<ch<<ch<<" 2.INSERT DATA ";
        cout<<"\n\n"<<ch<<ch<<" 3.DELETE DATA ";
        cout<<"\n\n"<<ch<<ch<<" 4.SHOW ALL DATA ";
        cout<<"\n\n"<<ch<<ch<<" 5.SEARCH DATA ";
        cout<<"\n\n"<<ch<<ch<<" 6.LENGTH OF LINKED LIST ";
        cout<<"\n\n"<<ch<<ch<<" 7.EXIT \n\n ";

        cout<<ch<<ch<<" ENTER YOUR CHOICE -> ";
        cin>>choice;
        switch(choice){
            case 1:
            int val;
            cout<<"ENTER THE VALUE ";
            cin>>val;
            add(head,val);
            break;

            case 2:
                int subChoice;
            cout << "\n1. Insert at Head";
            cout << "\n2. Insert at Tail";
            cout << "\n3. Insert at Position";
            cout << "\n4. Insert After Value";
            cout << "\n\nEnter your choice: ";
            cin >> subChoice;

            if (subChoice == 1) {
                int val;
                cout << "Enter the value: ";
                cin >> val;
                insertHead(head, val);
            } else if (subChoice == 2) {
                int val;
                cout << "Enter the value: ";
                cin >> val;
                insertTail(head, val);
            } else if (subChoice == 3) {
                int val, pos;
                cout << "Enter the value: ";
                cin >> val;
                cout << "Enter the position: ";
                cin >> pos;
                insertPos(head, val, pos);
            } else if (subChoice == 4) {
                int val, ele;
                cout << "Enter the value to insert: ";
                cin >> val;
                cout << "Enter the value after which to insert: ";
                cin >> ele;
                insertval(head, val, ele);
            } else {
                cout << "Invalid sub-option!" << endl;
            }
            break;


            break;
            case 3:
                 int subchoice;
                cout << "\n1. delete at Head";
                cout << "\n2. delete at Tail";
                cout << "\n3. delete at Position";
                cout << "\n4. delete By Value";
                cout << "\n\nEnter your choice: ";
                cin >> subchoice;

                if (subchoice == 1) {


                    deleteHead(head);

                } else if (subchoice == 2) {


                    deleteTail(head);

                } else if (subchoice == 3) {
                    int val, pos;
                    // cout << "Enter the value: ";
                    // cin >> val;
                    cout << "Enter the position: ";
                    cin >> pos;
                    deletePos(head, pos);
                } else if (subchoice == 4) {
                    int val, ele;
                    cout << "Enter the value to delete: ";
                    cin >> val;

                    deleteVal(head, val);
                } else {
                    cout << "Invalid sub-option!" << endl;
                }
                break;

            case 4:
                cout<<"ALL DATA OF LINKED LIST IS :\n";
                 displayList(head);
                break;
            case 5:
                cout<<"SEARCH THE DATA IN LINKED LIST :\n";
                search(head,val);
                break;
            case 6:
                 cout<<" 6.LENGTH OF LINKED LIST \n";
                length(head);
                break;

            case 7:
                exit(0);

             default:
                cout<<"\n\n "<<ch<<ch<<" PLEASE SELECT CORRECT OPTION "<<ch<<ch;


    }
    getch();

    goto p;


}