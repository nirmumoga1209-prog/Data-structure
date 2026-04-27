def is_valid(s):
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    
    for char in s:
        if char in mapping:
            # Closing bracket
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            # Opening bracket
            stack.append(char)
    
    return not stack

# Example usage
test_string = "({[]})"
result = is_valid(test_string)
print(f"Is '{test_string}' valid? {result}")  # Output: True

# Another example
test_string2 = "([)]"
result2 = is_valid(test_string2)
print(f"Is '{test_string2}' valid? {result2}")  # Output: False
