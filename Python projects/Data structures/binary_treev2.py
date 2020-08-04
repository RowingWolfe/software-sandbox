#Let's do this better this time around, eh?
#A binary tree is a data structure where each node can have 2 children
#The children without children are the leaves, the node without a parent is the root.
#I think I overthrought the last one and was thinking of a BST? Overcomplicating it.
#Though I will be adding a BST to these data structs.

#Tree traversal algorithms
import tree_traversal


#The humble node, initialized with <data> to be stored in it as an arg, left and right node = None
#EG; new_node = Node("foo")
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


    #Inserts a node into the tree after searching to find it a location based on it's data.
    #Sorting lower values left and higher values right.
    #EG; my_tree.insert()
    def insert(self, data):
        #First compare new data with the parent node.
        if self.data:
            #Then check the left node if the new node's data value is less than current node's data value.
            if data < self.data:
                if self.left == None:
                    self.left = Node(data)
                #If there's no space, call this function recursively on the left node of the current node.
                else:
                    self.left.insert(data) 
            #If the value is higher, we should insert to the right if we can, otherwise recurse on the right node.
            elif data > self.data:
                if self.right == None:
                    self.right = Node(data)
                else:
                    #Again, call recursively down the line.
                    self.right.insert(data)
        else:
            self.data = data
    
    #Print contents of the tree by visiting each node starting down left branches, then going down the right.
    def print_tree(self):
        #Check for left branch.
        if self.left:
            #Call print_tree recursively on the left branch.
            self.left.print_tree()
        #Print the data from the current node.    
        print(self.data)
        #After printing data, check the right.
        if self.right:
            #Then traverse down the right side.
            self.right.print_tree()

    
root = Node(27)
root.insert(14)
root.insert(35)
root.insert(10)
root.insert(19)
root.insert(31)
root.insert(42)
print(tree_traversal.in_order_traversal(root))