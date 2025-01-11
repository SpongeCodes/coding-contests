import re

with open("input.txt", "r") as file:
    lines = ''
    for line in file:
        lines += line

pattern = r"(?:don't\(\)|do\(\)|mul\(\d{1,3},\s*\d{1,3}\))"

matches = re.findall(pattern, lines)

print(matches)

state = True
result = 0
while matches:
    curr = matches.pop(0)

    if curr == 'do()':
        state = True
    elif curr == "don't()":
        state = False
    else:
        if state:
            parts = curr[4:-1].split(',')
            a, b = int(parts[0]), int(parts[1])
            result += (a * b)

print(result)