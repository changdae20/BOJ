import sys

def preorder(node):
    if node==".": return
    global tree
    print(node, end="")
    preorder(tree[node]["left"])
    preorder(tree[node]["right"])

def inorder(node):
    if node==".": return
    global tree
    inorder(tree[node]["left"])
    print(node, end="")
    inorder(tree[node]["right"])

def postorder(node):
    if node==".": return
    global tree
    postorder(tree[node]["left"])
    postorder(tree[node]["right"])
    print(node, end="")

N = int(sys.stdin.readline())
tree = {}
for _ in range(N):
    parent, left, right = sys.stdin.readline().split()
    tree[parent] = {"left" : left, "right" : right}

preorder("A")
print()
inorder("A")
print()
postorder("A")