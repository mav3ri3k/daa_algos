def create_lsp(pattern):
    ret = [0]
    
    for i in range(1, len(pattern)):
        j = ret[i - 1]
        while j > 0 and pattern[j] != pattern[i]:
            j = ret[j - 1]
        ret.append(j + 1 if pattern[j] == pattern[i] else j)
    return ret
    
def search(T, P):
    lsp = create_lsp(P)
    ret = []
    j = 0
    
    for i in range(len(T)):
        while j > 0 and T[i] != P[j]:
            j = lsp[j - 1]
        if T[i] == P[j]: j += 1
        if j == len(P): 
            ret.append(i - (j - 1))
            j = lsp[j - 1]
        
    if len(ret) == 0:
        return -1
    else:
        return ret[-1]
print("Apurva Mishra 22BCE2791")
text = input("Text: ")
pattern = input("Pattern: ")
index = search(text, pattern)
if index < 0:
    print("Pattern not found")
else:
    print(f"Pattern found at index {index}")
