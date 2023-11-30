#include<iostream>
#include "assign6 (1).h"
using namespace std;

class node{
    public:
        int data;
        int lth,rth;
        node*left,*right;
};
class threadDemo{
    private:
        node *dummy;
        node*New,*root,*temp,*parent;
        public:
        threadDemo();
        void create();  
        void insert(node*,node*);
        void display();
      
        void find();
        void delet();
        void del(node*root,node*dummy,int key);
};
threadDemo::thread()
{
    root=NULL;
};
// the create function
void threadDemo::create()
{ 
		cout<<"thread created";
    New=new node;
    New->left=NULL;
    New->right=NULL;
    New->lth=0;
    New->rth=0;
    cout<<"\n enter the element";
    cin>>New->data;
    if(root==NULL)
    {
        root=New;
        dummy=new node;
        dummy->data=-999;
        dummy->left=root;
        root->left=dummy;
        root->right=dummy;
    }
    else
    insert(root,New);
}
// create
void threadDemo::insert(node*root,node*New)
{
    if(New->data<root->data)  
    {
        if(root->lth==0)
        { 
            New->left=root->left;  
            New->right=root;  
            root->left=New;
            root->lth=1;
        }
        else
            insert(root->left,New);
    }
    if(New->data>root->data)
    {
        if(root->rth==0)
        { 
            New->right=root->right;  
            New->left=root;  
            root->rth=1;
            root->right=New;

        }
        else
            insert(root->right,New);
    }
}
//display
void threadDemo::display()
{	
	cout<<"hello display";
    void inorder(node*,node*dummy);
    void preorder(node*,node*dummy);     
    if(root==NULL)
    {
	cout<<"Thread is not created";	
    }
    else
    { 
        cout<<"\n inorder Traversal";
        inorder(root,dummy);
        cout<<"\n preorder Traversal";
        preorder(root,dummy);

    }
}
//inorder
void inorder(node*temp,node*dummy)
{ 
    while(temp!=dummy)
    {
        while(temp->lth==1)
        temp=temp->left;
    cout<<" "<<temp->data;
    while(temp->rth==0)
    {
        temp=temp->right;
        if(temp==dummy)
        return;
        cout<<" "<<temp->data;
    } 
    temp=temp->right;    
    }
}
//preorder
void preorder(node*temp,node*dummy) 
{
    int flag=0;
    while(temp!=dummy) 
    {
        if(flag==0)
        cout<<" "<<temp->data;
        if((temp->lth==1)&&(flag==0))
        {
            temp=temp->left;   
        } 

        else
        {
            while(1)
            {
                if(temp->rth==1)
                {
                    flag=0;
                    temp=temp->right;
                    break; 
                } 
                else
                {
                    if(temp!=dummy)
                    {
                        flag=1;
                        temp=temp->right;
                        break; 
                     }
                }
            }
       }                    
    }
}
int main()
{
    int choise;
    char ans='N';
    threadDemo th;
    do
    {
        cout<<"\n\tprogramme for threadder binary tree";
        cout<<"\n1.create\n2.display";
        cin>>choise;
        switch(choise)
        {
            case 1:
            do
            {
		
                th.create();
                cout<<"\ndo you want to enter more elements?(y/n)";
                cin>>ans;
            }while(ans=='y');
            break; 
            case 2:
			th.display();
			
            break;
       }
       cout<<"\n\t want to see menu?(y/n)";
       cin>>ans;
   }while(ans=='y');
   return 0;
}   









