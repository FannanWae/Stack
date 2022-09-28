import re


class Stack(object):
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return self.items == []


def eval_postfix(expression):
    """Evaluate postfix expressions.
    E.g. "3 4 + 2 *" -> 14
    """
    tokens = re.split("([^0-9])", expression)
    stack = Stack()
    for token in tokens:
        token = token.strip()
        if not token:
            continue
        if token == '+':
            result = stack.pop() + stack.pop()
            stack.push(result)
        elif token == '*':
            result = stack.pop() * stack.pop()
            stack.push(result)
        else:
            stack.push(float(token))
    return stack.pop()


s = Stack()

s.push(3)
s.push(4)
s.push(5)
s.push(10)
s.push(20)
a = s.is_empty()
b = s.pop()

print(a)
print(b)


print(eval_postfix('23 43 + 5 *'))
# 330.0
print(eval_postfix('2 1 + 2 * 3 + 4 *'))
# 36.0
