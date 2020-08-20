#A library? I suppose of functions to traverse trees.
# Or is the vernacular "module"?

#Traverse a tree in order from left to right. Takes a tree's root node as it's single arg.
def in_order_traversal(tree_root):
    nodes_in_order = []
    if tree_root:
        #First down the left side.
        nodes_in_order = in_order_traversal(tree_root.left)
        #Then the root
        nodes_in_order.append(tree_root.data)
        #Then down the right side.
        nodes_in_order = nodes_in_order + in_order_traversal(tree_root.right)

    return nodes_in_order


#TODO: Pre-order Traversal.
    
#TODO: Post-order Traversal.
