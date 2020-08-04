#Let's do this better this time around, eh?
#A binary tree is a data structure where each node can have 2 children
#The children without children are the leaves, the node without a parent is the root.
#I think I overthrought the last one and was thinking of a BST? Overcomplicating it.
#Though I will be adding a BST to these data structs.

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

#Uncertain if I should add the traversal algorithms in a seperate file... probably, right?
#TODO: When time allows, Create an algorithm folder, write classes for each data structure type and add methods for
#traversing/operating on the data structures. Like tree traversal algos?


    