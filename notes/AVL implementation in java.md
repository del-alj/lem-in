### a class tha got any thing we need to store date, and the neccessery pointers:
class Node<T> 
{
	t data;
	node <T> left;
	node <T> right;
	Node <T> parent;
	public Node (T obj)
	{
		data = obj;
		parent = left = right = NULL;
	}
}

### adding a node 
public avltree () 
{
	root = null;
	current_size = 0;
}

public void add(E obj)
{
	node <E> node = new Node<E> (obj);
	if (root == null)
	{
		root = node;
		current_size++;
		return ;
	}
	add (root, node);
}

### recursive add methode
public void add(Node<E> parent, Node<E> newNode)  
{  
	if ((( comparable<E>) newNode.data.compareTO(parent.data) > 0)  
	{  
		if (parant.right == null)  
		{  
			parent.right = newNode;  
			newNode.parent = parent;  
			current_size++;  
		} else   
		{  
			add (parent.right, newNode);  
		}
	} else  
	{  
		... the same thing for the left;  
	}    
	check balance (newNode);  
}  

### checking balance 
public void check_balance (node<E> node)
{
	if ( (height(node.left) - height(node.right) > 1) || (height(node.left) - height(node.right) < -1) )  
	{  
		rebalance(node);  
	}  
	if (node.parent == null)
		return;
	check_balance(node.parent);  
}


private int Height(Node)  
<!-- the height is the result of the func -1 -->
{  
	 if (node == null)
    	return 0;
    int left = 0;
    int right = 0;

	 if (node.Left != null)
    	left = Height(node.Left) + 1;

    if (node.Right != null)
    	right = Height(node.Right) + 1;
    return right >= left ? right : left;  
}


### rebalancing the tree

public void rebalance (node<E> node)
{
	if (height(node.left) - height(node.right) > 1)
	{
		if (height(node.left.left) > height(node.left.right))
			node = right_retate(node);
		else
			node = left_right_retate(node);
	}
	else if (height(node.left) - height(node.right) < -1)
	{
			do the same thing for the other side;
	}
	if (node.parent == null)
		root = node;
}

jjjjj
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
