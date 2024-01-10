#include<iostream>
#include "bst.cpp"
using namespace std;

int main()
{
	bst trewly_tree;
	int choice;
	while(1)
	{
		cout << "-----------------------------------------\n";
		cout << "1. Add leaf\n";
		cout << "2. Return root key \n";
		cout << "3. Print children\n";
		cout << "4. Return smallest key";
		cout << "5. Remove key\n";
		cout << "6. Print in order\n";
		cout << "0. Exit\n\n";
		cout << "@Choice: ";
		cin >> choice;
		cout << "-----------------------------------------\n";
		switch(choice)
		{
			case 0:
				break;
			case 1:
				int leaf;
				cout << "Node muon them vao cay la: ";
				cin >> leaf;
				trewly_tree.add_leaf(leaf);
				cout << "them thanh cong ^^\n";
				break;
			case 2:
				cout << "Root key la : " << trewly_tree.return_root_key() << "\n";
				break;
			case 3:
				int key;
				cout << "Nhap key ban muon xem con: " ;
				cin >> key;
				trewly_tree.print_children(key);
				break;
			case 4:
				cout << "Key nho nhat trong cay la: " ;
				cout << trewly_tree.smallest_key() << "\n";
				break;
			case 5:
				int key1;
				cout << "Nhap key ban muon xoa: " ;
				cin >> key1;
				trewly_tree.remove_node(key1);
				break;
			case 6:
				cout << "Cay in theo thu tu: \n" ;
				trewly_tree.print_in_order();
				break;
			default:
				cout << "Hay chon lua chon duoc liet ke trong bang\n";
				break;
		}
		cout << "\n\n";
		if(choice==0)
		{
			break;
		}
	}
}
