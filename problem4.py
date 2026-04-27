def product_except_self(nums):
    n = len(nums)
    output = [1] * n
    
    # Compute prefix products
    prefix = 1
    for i in range(n):
        output[i] = prefix
        prefix *= nums[i]
    
    # Compute suffix products and multiply
    suffix = 1
    for i in range(n - 1, -1, -1):
        output[i] *= suffix
        suffix *= nums[i]
    
    return output

# Example usage
nums = [1, 2, 3, 4]
result = product_except_self(nums)
print(f"Product except self for {nums}: {result}")  # Output: [24, 12, 8, 6]
