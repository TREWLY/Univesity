#include<iostream>
#include "bst.h"
using namespace std;

bst::bst()
{
	root=NULL;	
}

//tao node moi 
bst::node* bst::create_leaf(int key)
{
	node* n= new node;
	n->key=key;
	n->left=NULL;
	n->right=NULL;
	return n;
}

//them node
void bst::add_leaf(int key)
{
	add_leaf_private(key,root);
}
void bst::add_leaf_private(int key,node *ptr)
{
	if(root==NULL)
	{
		root=create_leaf(key);
	}else if(key<ptr->key)
	{
		if(ptr->left!=NULL)
		{
			add_leaf_private(key,ptr->left);
		}else{
			ptr->left=create_leaf(key);
		}
	}else if(key>ptr->key)
	{
		if(ptr->right!=NULL)
		{
			add_leaf_private(key,ptr->right);
		}else{
			ptr->right=create_leaf(key);
		}
	}else{
		cout << "the key " << key << " has already been added to the tree\n";
	}
}
	
//tim vi tri node trong cay	
bst::node* bst::return_node(int key)
{
	return return_node_private(key,root);
}
bst::node* bst::return_node_private(int key,node* ptr)
{
	if(root==NULL)
	{
		return NULL;
	}else{
		if(key<ptr->key)
		{
			return	return_node_private(key,ptr->left);
		}else if(key>ptr->key)
		{
			return 	return_node_private(key,ptr->right);
		}else{
			return ptr;
		}
	}
}

//duyet node in_order <=> sap xep tang dan
void bst::print_in_order(){
	print_in_order_private(root);
}
void bst::print_in_order_private(node *ptr){
	if(root!=NULL)
	{
		if(ptr->left!=NULL)
		{
			print_in_order_private(ptr->left);
		}
		cout << ptr->key << " ";
		if(ptr->right!=NULL)
		{
			print_in_order_private(ptr->right);
		}
	}else{
		cout << "the tree is empty\n";
	}
}

//tra ve gia tri node goc
int bst::return_root_key()
{
	if(root!=NULL)
	{
		return root->key;
	}else{
		return -166; //gia tri neu khong co node goc
	}
}

//tra ve con cua mot node
void bst::print_children(int key1)
{
	node* ptr=return_node(key1);
	if(ptr!=NULL)
	{
		cout << "parent: " << ptr->key << "\n";
		if(ptr->left==NULL && ptr->right==NULL)
		{
			cout << "khong co con \n" ;
		}else{
			if(ptr->left!=NULL)
			{
				cout << "Co con trai: " << ptr->left->key << "\n"; 
			}
			if(ptr->right!=NULL)
			{
				cout << "Co con phai: " << ptr->right->key << "\n"; 
			}
		}
	}else{
		cout << "Key khong ton tai\n";
	}
}

//gia tri nho nhat trong node
int bst::smallest_key()
{
	return smallest_key_private(root);
}
int bst::smallest_key_private(node *ptr)
{
	if(ptr->left==NULL)
	{
		return ptr->key;
	}else{
		return smallest_key_private(ptr->left);
	}
}

//xoa node
void bst::remove_node(int key) 
{
	remove_node_private(key,root);
}
void bst::remove_node_private(int key,node* ptr)
{
	if(root!=NULL)
	{
		if(root->key==key)
		{
			remove_root();
		}else
		{
			if(key<ptr->key && ptr->left!=NULL) //xoa node con ben trai
			{
				ptr->left->key==key ?
				remove(ptr,ptr->left,true) :
				remove_node_private(key,ptr->left);
			}else if(key>ptr->key && ptr->right!=NULL) //xoa node con ben phai
			{
				ptr->right->key==key ?
				remove(ptr,ptr->right,false) :
				remove_node_private(key,ptr->right);
			}
			else if(key==ptr->key) //xoa node hien tai
			{
				int smallest_right=smallest_key_private(ptr->right);
				ptr->key=smallest_right;
				remove_node_private(smallest_right, ptr->right);
    			cout << "The node with key " << key << " was removed\n";
			}else{
				cout << "key doesnt exist\n";
			}
		}
	}else{
		cout << "there is nothing to delete\n";
	}
}
//xoa goc
void bst::remove_root() 
{
	if(root!=NULL)
	{
		node* del_ptr=root;
		int smallest_right;
		//co 0 con
		if(root->left==NULL && root->right==NULL)
		{
			root=NULL;
			delete del_ptr;
		}
		//co 1 con
		else if(root->left==NULL && root->right!=NULL) //1 con ben phai
		{
			root=root->right;
			del_ptr->right=NULL;
			delete del_ptr;
			cout << "The root key is deleted, the new root is " << root->key << "\n";	
		}
		else if(root->left!=NULL && root->right==NULL) //1 con ben trai
		{
			root=root->left;
			del_ptr->left=NULL;
			delete del_ptr;
			cout << "The root key is deleted, the new root is " << root->key << "\n";	
		}
		//co 2 con
		else{
			smallest_right=smallest_key_private(root->right);
			remove_node_private(smallest_right,root); //dua node con nho nhat phia ben phai thay cho root
			root->key=smallest_right;
			cout << "The root key is deleted, the new root is " << root->key << "\n";	
		}
	}
}
//ham thuc hien chuc nang xoa node
void bst::remove(node* parent, node* match, bool left) //bool phan biet con trai hay con phai
{
    node* del_ptr;
    int match_key=match->key;
    int smallest_right;
	//0 con
	if(match->left==NULL && match->right==NULL)
	{
		del_ptr=match;
		left==true ? parent->left=NULL : parent->right=NULL;
		delete del_ptr;	
		cout << "the node containing key " << match_key << " was removed\n";
	}
	//1 con
	else if(match->left==NULL && match->right!=NULL) //1 con phai
	{
		del_ptr=match;
		left==true ? parent->left=match->right : parent->right=match->right; //neu la con trai thi con trai cua
		match->right==NULL;													//parent noi den con trai cua node
		delete del_ptr;
		cout << "the node containing key " << match_key << " was removed\n";
	}else if(match->left!=NULL && match->right==NULL) //1 con trai
	{
		del_ptr=match;
		left==true ? parent->left=match->left : parent->right=match->left; //neu la con phai thi con phai cua
		match->left==NULL;													//parent noi den con phai cua node
		delete del_ptr;
		cout << "the node containing key " << match_key << " was removed\n";
	}
	//2 con
	else{		
		smallest_right=smallest_key_private(match->right); //tim key nho nhat phia con phai gan cho roi xoa node co key nho nhat ay
		remove_node_private(smallest_right,match);
		match->key=smallest_right;
	}
}

