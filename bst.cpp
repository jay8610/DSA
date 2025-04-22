#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
};

class BST
{
public:
	node *root;
	int cnt;
	BST()
	{
		root=NULL;
		cnt=0;
	}
	void insert();
	void inorder(node *temp);
	void preorder(node *temp);
	void postorder(node *temp);
	int search();
	void smallest();
	void largest();
	void mirror(node *r);
	int height(node *r);
	
};

void BST::insert()
{
	int flag=0;
	node *temp;
	node *new_node=new node();
	new_node->left=NULL;
	new_node->right=NULL;
	cout<<"Enter node value : ";
	cin>>new_node->data;
	if(root==NULL)
	{
		root=new_node;
	}
	else
	{
		temp=root;
		while(flag==0)
		{
			if(new_node->data < temp->data)
			{
				if(temp->left==NULL)
				{
					temp->left=new_node;
					flag=1;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(new_node->data > temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=new_node;
					flag=1;
				}
				else
				{
					temp=temp->right;
				}
			}
			else
			{
				flag++;
				cout<<"Element already exists !!";
			}
		}
	}
}

void BST::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout<<temp->data<<"\t";
		cnt++;
		inorder(temp->right);
	}
}

void BST::preorder(node *temp)
{
	if(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		cnt++;
		preorder(temp->left);
		preorder(temp->right);
	}
}

void BST::postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		cout<<temp->data<<"\t";
		cnt++;
		
	}
}

void BST::smallest()
{
	node *temp;
	temp=root;
	
	while(temp->left!=NULL)
	{
		temp=temp->left;
		
	}
	cout<<"Smallest element : ";
	cout<<temp->data;
}



void BST::largest()
{
	node *temp;
	temp=root;
	
	
	while(temp->right!=NULL)
	{
		temp=temp->right;
		
	}
	cout<<"largest element : ";
	cout<<temp->data;
}

int BST::search()
{
	node *temp;
	temp=root;
	int key;
	cout<<"Enter key to be searched : ";
	cin>>key;
	
	while(1)
	{
		if(key<temp->data)
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else
			{
			    cout<<"Not found!!";
				return 0;
			}
		}
		else if(key>temp->data)
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else
			{
				cout<<"Not found!!";
				return 0;
			}
	}
	else
	{
		cout<<"Element found :) ";
		return 1;
	}
	
}

}

void BST::mirror(node *r)
{
	node *temp;
	if(r!=NULL)
	{
		temp = r->left;
		r->left = r->right;
		r->right = temp;
		
		mirror(r->left);
		mirror(r->right);
	}
}

int BST::height(node *r)
{
	int r_height,l_height;
	if(r==NULL)
	{
		return 0;
	}
	else if(r->left==NULL&&r->right==NULL)
	{
		return 0;
	}
	
	l_height = height(r->left);
	r_height = height(r->right);
	
	if(r_height>l_height)
	{
		return (r_height+1);
	}
	else
	{
		return (l_height+1);
	}
}



int main()
{
	BST b;
	int ch;
	
	do
	{
		cout<<"\n--------MENU---------"<<endl;
		cout<<"\n1)Insert "<<endl;
		cout<<"\n2)Inorder "<<endl;
		cout<<"\n3)preorder "<<endl;
		cout<<"\n4)postorder "<<endl;
		cout<<"\n5)smallest element "<<endl;
		cout<<"\n6)largest element "<<endl;
		cout<<"\n7)search element "<<endl;
		cout<<"\n8)Mirror "<<endl;
		cout<<"\n9)Height "<<endl;
		cout<<"\n10)Exit"<<endl;
		
		cout<<"Enter your choice : ";
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:
	            	  b.insert();
	            	  break;
	          case 2:
	          	  b.inorder(b.root);
	          	  break;
	          case 3:
	          	  b.preorder(b.root);
	          	  break;
	          case 4:
	          	  b.postorder(b.root);
	          	  break;
	          case 5:
	         	  b.smallest();
	          			break;
	          case 6:
	          	  b.largest();
	          			break;
	          case 7:
	          	  b.search();
	          			break;
	          			
	          case 8:
	          		cout<<"Mirror : ";
	          	     b.mirror(b.root);
	          		break;
	          		
	          case 9:
	          		cout<<"Height of the tree : ";
	          		cout<<b.height(b.root);
	          		break;
	          case 10:
	          	  cout<<"Thank you for using this program :)"<<endl;
	          	  break;
		}
		
	}while(ch!=10);
	
	
	
	return 0;
}
