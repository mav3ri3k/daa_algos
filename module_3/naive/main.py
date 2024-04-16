def search(pattern, text):
    m = len(pattern)
    n = len(text)
    for x in range(n):
        j = 0
        if n - x >= m:
            while j < m and text[x+j] == pattern[j]:
                j += 1
            if j == m:
                return x
    return -1

text = input("Text: ")
pattern = input("Pattern: ")
index = search(pattern, text)
if index < 0:
    print("Pattern not found")
else:
    print(f"Pattern found at index {index}")
