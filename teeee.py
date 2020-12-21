# Find max element of a stack.

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
        self.count = 0
        self.maximum = None
    def getMax(self):
        if self.head is None:
            return "Stack is empty"
        else:
            print("Max Element is - ",end='')
            print(self.maximum)
    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False
    def push(self,value):
        if self.head is None:
            self.head = Node(value)
            self.maximum = value
        elif value > self.maximum:
            temp = (2 * value) - self.maximum
            new_node = Node(temp)
            new_node.next = self.head
            self.head = new_node
            self.maximum = value
        else:
            new_node = Node(value)
            new_node.next = self.head
            self.head = new_node
    def pop(self):
        if self.head is None:
            print("Stack is empty.")
        else:
            temp = self.head.value
            self.head = self.head.next
            if temp > self.maximum:
                self.maximum = (2 * self.maximum) - temp

arr = [3,4,5,1,2,6]
stack = Stack()
for i in arr:
    stack.push(i)

#Perform push/pop operations here.

stack.getMax()
stack.push(22)
stack.getMax()
stack.pop()
stack.getMax()
stack.pop()
stack.getMax()