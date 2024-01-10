 class bst
{
	private:
		struct node
		{
			int key;
			node* left;
			node* right;
		};
		node *root;
		//hien thuc ham 
		void add_leaf_private(int key,node *ptr);
		void print_in_order_private(node *ptr);
		node* return_node_private(int key,node* ptr);
		int smallest_key_private(node *ptr);
		void remove_node_private(int key,node* ptr);
		void remove(node* parent,node* match, bool left); 
		void remove_root();
	public:
		bst();
		node* create_leaf(int key);
		void add_leaf(int key);
		void print_in_order();
		node* return_node(int key);
		int return_root_key();
		void print_children(int key);
		int smallest_key();
		void remove_node(int key);
};
