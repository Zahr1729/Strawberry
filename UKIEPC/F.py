n = int(input())
inputs = []
for i in range(n):
    inputs.append(input().split())

inputs = sorted(inputs, key=lambda x: x[0])

print(inputs)
