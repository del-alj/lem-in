AVL Trees
-----------------
##Binary Search Trees (BST)

	A BST is a rooted binary tree, whose internal nodes each store a key (and optionally, an associated value) and each have two distinguished  sub-trees, commonly denoted left and right.
	The tree additionally satisfies the binary search property, which states that the key in each node must be greater than or equal to any key stored in the left sub-tree, and less than or equal to any key stored in the right sub-tree..  
	BST is a sorted binary tree, this type of trees have a problem that's the height :  
		log(n) <= height of a BST <= n.  

###Drawbacks of Binary Search Tree
With this the complexity of any operation (insertion, Deletion, Traversal, searching...) to the tree ranges from O(log n) to O(n).

##What are AVL Trees 
An 'AVL' is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.  Lookup, insertion, and deletion all take `O(log n)` time in both the average and worst cases, where `n` is the number of nodes in the tree prior to the operation. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.  
meaning avl is just a minimum height BST.  
Height of AVL tree == 1.44 * log(n)  
==> time complexity == O(logn).
 
**the heigt :** is the number of edges.  
**Balance factor** : height of left - height of right subtree.  
for a balanced tree :  
bf = hl - hr = {-1, 0, 1} >> |bf| == |hl - hr| <= 1.


##Rotations in AVL Trees

**there is 4 different types of retations :**  
knowing that L = left and R = right.

LL-imbalance -> ll-retaion (simple step).  
RR-imbalance -> RR-retaion (simple step).  
LR-imbalance -> LR-retaion (double steps).  
RL-imbalance -> RL-retaion (Double steps).


##Creating AVL Trees
	the creation is just as creating a BST, the new thing is that you have to balance it every time you add a new key.
**1. this is a left-left imbalanced tre:**. 

A-left = B, a-right = Ar.  
B-left = C, B-right = Br.   
C-left = Cr, C-right = Cr.  

to balance it you have to do the LL retation : 
`temp = A && A-left = Br && B-right = temp;`

**2. The RR retation : is just like LL, just in the other side.**  
**3. this is a left-right imbalanced tree :**  

A-left = B, a-right = Ar.  
B-left = Bl, B-right = C.  
C-left = Cr, C-right = Cr.  

to do the balancing we'll do the  LR retation :  
` tmp1 = C-left		&& tmp2 = C-right`  
` C-left = A-left	&& C-right = &A`  
` B-right = tmp1		&& A-left = tmp2;`

**4. RL retation : the same just in the other side;**

Note : after any insertion calculate the balance, and balance the tree.


### Sources 
[Abdul bari : 10.1 AVL Tree - Insertion and Rotations](https://www.youtube.com/watch?v=jDM6_TnYIqE)    
[RobEdwardsSDSU : AVL Tree 1 Introduction](https://youtu.be/nMExd4DthdA)  
[RobEdwardsSDSU : AVL Tree 2 Nodes](https://www.youtube.com/watch?v=91aebuLdWok&list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk&index=60)  
[RobEdwardsSDSU : AVL Tree 3 Adding a node](https://youtu.be/uTLiAbHH8xI)  
[RobEdwardsSDSU : AVL Tree 4 recursive add for an AVL tree](https://youtu.be/vYkgmdzhBoI)  
[RobEdwardsSDSU : AVL Tree 5 checking balance in an AVL tree](https://youtu.be/iNy6c4Q9Umw)  
[RobEdwardsSDSU : AVL Tree 6 Rebalancing AVL trees](https://youtu.be/wn1tc5SAGZk)  
[RobEdwardsSDSU : AVL Tree 7 complete example of adding data to an AVL tree.](https://youtu.be/7m94k2Qhg68)  
 
 
 Red Trees
-----------------
### the rules 
* Every node is red or black
* Root is always black
* New insertions are always red
* Every path from root - leaf has the same numver of *black* nodes
* no path can have two consecutive *red* nodes
* Nulls are black

### rebalance 
* black aunt --> retate = BAR
* Red aunt   --> ColorFlip





### Sources 
[Red Black Tree 1 The Rules](https://youtu.be/nMExd4DthdA)
[]()
[]()




