# A Huffman Tree Node 
import heapq 


class node: 
	def __init__(self, freq, symbol, left=None, right=None): 
		self.freq = freq 
		self.symbol = symbol 
		self.left = left 
		self.right = right 
		self.huff = '' 

	def __lt__(self, nxt): 
		return self.freq < nxt.freq 

freq_dict = {}
chars = []
freq = []
nodes = [] 

def create_char_freq_array(input_str):
    for i in input_str:
        if i in freq_dict:
            freq_dict[i] += 1
        else:
            freq_dict[i] = 1
    dict(sorted(freq_dict.items(), key=lambda item: item[1]))
    for key, value in freq_dict.items():
        chars.append(key)
        freq.append(value)

def print_nodes(node, code):
    if node.symbol not in chars:
        print_nodes(node.left, code + "0")
        print_nodes(node.right, code + "1")
    else:
        print(node.symbol, ": ", code)

def create_heap():
    for x in range(len(chars)): 
        heapq.heappush(nodes, node(freq[x], chars[x])) 

    while len(nodes) > 1: 

        # sort all the nodes in ascending order 
        # based on their frequency 
        left = heapq.heappop(nodes) 
        right = heapq.heappop(nodes) 

        # assign directional value to these nodes 
        left.huff = 0
        right.huff = 1

        # combine the 2 smallest nodes to create 
        # new node as their parent 
        newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right) 

        heapq.heappush(nodes, newNode) 

def main():
    print("Apurva Mishra 22BCE2791")
    input_str = input()
    create_char_freq_array(input_str)
    create_heap()
    print_nodes(nodes[0], "")

main()
