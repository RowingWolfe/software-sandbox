#Welp. Doubly linked list time. I was going to roll this into the linked_list.py but it got rather large.
#At least these are only data structures and not full projects, not gonna have to worry too much about overscoping.
#I hope...
# Though it is fun to try and write these based off descriptions of them without psuedocode. Feels more free.

#Just gonna call it node this time.
class Node:
    def __init__(self, data):
        self.data = data
        self.next_node = None
        self.last_node = None

    def __str__(self):
        return self.data 

#The doubly linked list can traverse forward and backward. Nodes know their neighbors in both directions.
#This one we'll just automatically create the nodes from the DLL methods to save space and code.
class Doubly_Linked_List:
    def __init__(self, val):
        self.head_node = Node(val)
        self.tail_node = None

    def __str__(self):
        return self.head_node.data

    #Add us a new head, give the old head the last_node val of the new head.
    def add_new_head(self, val):
        new_node = Node(val)
        old_head = self.head_node #Just make it easy to read I guess since it's the first bit anyone will see.
        new_node.next_node = old_head
        old_head.last_node = new_node
        self.head_node = new_node

    #Add a new node, if there is a tail point the it's next_node pointer to it. 
    #Otherwise just add a tail and point the head's next_node to it.
    def add_new_tail(self, val):
        new_node = Node(val)
        #If there is only a head node...
        if self.tail_node == None:
            new_node.last_node = self.head_node
            self.head_node.next_node = new_node
        else:
            self.tail_node.next_node = new_node
            new_node.last_node = self.tail_node
        self.tail_node = new_node
      
    # How about we let the list just keep track of the tail for us?
    # def find_tail(self):
    #     current_node = self.head_node
    #     while current_node.next_node != None:
    #         current_node = current_node.next_node
    #     return current_node

    #Search for node, add new node after.
    def add_node_after(self, node, val):
        found_node = self.search_forward(node)
        if found_node != None:
            new_node = Node(val)
            node_before = found_node
            node_after = found_node.next_node
            new_node.next_node = node_after
            new_node.last_node = node_before
            node_before.next_node = new_node
            node_after.last_node = new_node
        else:
            print("Can not find node to insert after.")
    
    #Start from head, look through each node until it's data matches val.
    def search_forward(self, val):
        current_node = self.head_node
        while current_node != None:
            if current_node.data == val:
                return current_node
            current_node = current_node.next_node
        return None

    #Start from tail, look through each node until it's data matches val.
    def search_backward(self, val):
        current_node = self.tail_node
        while current_node != None:
            if current_node.data == val:
                return current_node
            current_node = current_node.last_node
        return None

    #Start from head, add all node data to a string and space it out, going forward.
    def stringify_forward(self):
        current_node = self.head_node
        node_string = ""
        while current_node != None:
            node_string += current_node.data + " "
            current_node = current_node.next_node
        return node_string

    #Start from tail and add all node data to a string with spaces, going backward.
    def stringify_reverse(self):
        current_node = self.tail_node
        node_string = ""
        while current_node != None:
            node_string += current_node.data + " "
            current_node = current_node.last_node
        return node_string

    #Search for node with data == val, replace pointers of it's last_node's next_node to the found node's next_node.
    #And then replace the last_node's next_node with a pointer to the found node's next_node.
    def del_node(self, val):
        node_to_del = self.search_forward(val)
        if node_to_del != None:
            if node_to_del.last_node != None:
                node_to_del.last_node.next_node = node_to_del.next_node
            if node_to_del.next_node != None:
                node_to_del.next_node.last_node = node_to_del.last_node
        else:
            print("Can't find node to delete.")


    
hello_world = Doubly_Linked_List("Hello")
print(hello_world)
hello_world.add_new_head("Well,")
print(hello_world)
hello_world.add_new_tail("Bonk!")
print(hello_world.tail_node)
hello_world.add_new_tail("Smoosh")
print(hello_world.tail_node)
print(hello_world.search_forward("Well,"))
hello_world.add_node_after("Bonk!", "Swish")
print(hello_world.stringify_forward())
hello_world.del_node("Smoosh")
print(hello_world.stringify_reverse())
