#Herein lies a BT. Implemented based on description.
#Calling the root a head, just to keep some semblance of consistancy.
#Having a real hard time focusing right now. Maybe I should take a couple days off and play some video games or something.
#TODO: Finish me Monday.

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class Binary_Tree:
    def __init__(self, data):
        head_node = Node(data)
        #We don't track depth here. Simple binary tree.

    #If I recall we must start at the head node and look for high/low.
    def add_node(self, data):
        new_node = Node(data)
        #Check if  the node's data is > head_node.data.
        if new_node.data > self.head_node.data:
            # new_node is the new head node and take over old head's left and right,
            # old head node needs to be sorted down. (Probably need recursion here.)
            old_head_node = self.head_node
            self.head_node = new_node
            self.head_node.left = old_head_node.left
            self.head_node.right = old_head_node.right
            # Now we just sort old head into the tree.
            # Where should I sort higher values to? I'll go for right.
            if old_head_node.data > self.head_node.right:
                #This looks like a job for a recursive function.
                pass
    
    #A recursive function that takes a node to sort, then compares it against each node down the tree
    # to find where it should be, then sets it's left/right and the node above's left/right depending.
    def sort_node(self, sorting_node, compared_node):
        if sorting_node.data > compared_node.data:
            #If compared_node is None we're at the bottom.
            if compared_node != None:
                #Sorting to the right because it's larger.
                compared_node = compared_node.right
                sort_node(sorting_node, compared_node)
            else:
                #it occurs to me I might need a refresher on binary trees.
                pass

    #DFS - Start at the root and go as deep as possible on each child, then go up and traverse the sibling, one by one.
    def dfs(self):

        pass

    def dfs_inorder(self):
        #In-order traversal.
        current_node = self.head_node
        if current_node is None:
            return
        #Start traversing the left sub-tree and call this func recursively.
        self.dfs_inorder(current_node.left)
        print(current_node.data)
        self.dfs_inorder(current_node.right)

        #Visit the root node
        #Traverse the right sub-tree and then call this func recursively.

        pass
    #BFS
    def bfs(self):
        pass