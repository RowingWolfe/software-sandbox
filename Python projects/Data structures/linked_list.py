#The humble linked list. You know your start node, it knows the next node and so on. Easier to iterate over.
#I do wonder if I should rewrite the methods of SLL to automatically create the nodes... or if I should leave it simple.
#Assumes all data stored in nodes is Unique for searching.
#Should I add a function to check the data is unique? No, adding and iterating should be fast.
#This would add an iteration each time you add an item, which will slow down as you add more items.
#Good enough. Maybe.

#So we need us a node that will store some data and a link to the next node.
#Probably use a class, eh?
class SLL_Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None

    def __str__(self):
        return self.data 



#Singly linked lists go one way. No arrays, arrays are slow. This is supposed to be fast.
class SLL:
    def __init__(self, head_node):
        self.head_node = head_node
        #Wont track the tail here, keep it slim. ( I know, how much data could a tail be? Could be a whole page though... I don't know how python deals with this stuff under the hood...)
    
    def __str__(self):
        return self.head_node.data

    #Add a node to replace the current head node.
    def add_node_head(self, node):
        node.next_node = self.head_node
        self.head_node = node
    
    #Automatically create the node. Why not both?
    def add_node_head_auto(self, val):
        new_node = SLL_Node(val)
        new_node.next_node = self.head_node
        self.head_node = new_node
        
    #Add a node to the tail.
    def add_node_tail(self, node):
        tail_node = self.find_tail()
        tail_node.next_node = node

    #Automatically create and add a node to tail.
    def add_node_tail_auto(self, val):
        new_node = SLL_Node(val)
        tail_node = self.find_tail()
        tail_node.next_node = new_node

    #Add a node after the node_to_find.
    def add_node_after(self, node_to_find, val):
        if self.search(node_to_find) != None:
            node_to_add = SLL_Node(val)
            print(node_to_add)
            node_after = self.search(node_to_find).next_node
            print(node_after)
            node_before = self.search(node_to_find)
            print(node_before)
            node_before.next_node = node_to_add
            node_to_add.next_node = node_after
        else:
            return "Can not add node, node_to_find not found."

    #Find the last node. (The one with next_node == None)
    def find_tail(self):
        #Eh, why not?
        # if self.head_node.next_node == None:
        #     #print("Only one node here!")
        #     return self.head_node

        current_node = self.head_node
        while current_node.next_node != None:
            current_node = current_node.next_node
        #print("Tail node is: ", current_node)
        return current_node

    #Iterate through from head until value found and return it's node, else return None
    def search(self, val):
        current_node = self.head_node
        while current_node != None:
            if current_node.data == val:
                return current_node
            #print("Current node val: ", current_node, " Looking for: ", val)
            current_node = current_node.next_node
        return None

    #Print each node from head to tail.
    def display_all(self):
        current_node = self.head_node
        while current_node != None:
            print(current_node)
            #print(current_node.next_node)
            current_node = current_node.next_node

    #Return a string of all the nodes' vals.
    def stringify_nodes(self):
        node_string = ""
        current_node = self.head_node
        while current_node != None:
            node_string += current_node.data + " "
            current_node = current_node.next_node
        return node_string

    #Replace the next_node pointer for previous node to searched(by val) node's next_node.
    def del_node(self, val):
        previous_node = None
        current_node = self.head_node
        while current_node != None:      
            if current_node.data == val:
                previous_node.next_node = current_node.next_node
            previous_node = current_node
            current_node = current_node.next_node


            
        



        

first_node = SLL_Node("Hello")
second_node = SLL_Node("World")
third_node = SLL_Node("!")
new_first_node = SLL_Node("Well,")

hello_world = SLL(first_node)

hello_world.add_node_tail(second_node)
hello_world.add_node_tail(third_node)
hello_world.add_node_head(new_first_node)
hello_world.add_node_head_auto("Cats say:")
hello_world.add_node_tail_auto("!?")
hello_world.add_node_after("World", "Biscuits")

print(hello_world.search("Hello"))
print(hello_world.search("World"))
print(hello_world.search("BANANA"))

print(hello_world.stringify_nodes()) #Cats say: Well, Hello World Biscuits ! !? 

hello_world.del_node("Biscuits")

print(hello_world.stringify_nodes()) #Cats say: Well, Hello World ! !? 

hello_world.display_all()
# Cats say:
# Well,
# Hello
# World
# !
# !?
