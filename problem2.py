def length_of_longest_substring(s):
    char_dict = {}
    left = 0
    max_len = 0
    for right in range(len(s)):
        if s[right] in char_dict:
            left = max(left, char_dict[s[right]] + 1)
        char_dict[s[right]] = right
        max_len = max(max_len, right - left + 1)
    return max_len


s = input("Enter a string: ")
result = length_of_longest_substring(s)
print(f"Length of longest substring without repeating characters: {result}")
