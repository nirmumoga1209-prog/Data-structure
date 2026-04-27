def merge_intervals(intervals):
    if not intervals:
        return []
    
    # Sort intervals by start time
    intervals.sort(key=lambda x: x[0])
    
    merged = [intervals[0]]
    
    for current in intervals[1:]:
        last = merged[-1]
        if last[1] >= current[0]:
            # Overlap, merge
            last[1] = max(last[1], current[1])
        else:
            # No overlap, add new
            merged.append(current)
    
    return merged

# Example usage
intervals = [[1, 3], [2, 6], [8, 10]]
result = merge_intervals(intervals)
print(f"Merged intervals: {result}")

# To take input from user (optional)
# Uncomment below to input manually
# import ast
# intervals_input = input("Enter intervals as list of lists, e.g., [[1,3],[2,6],[8,10]]: ")
# intervals = ast.literal_eval(intervals_input)
# result = merge_intervals(intervals)
# print(f"Merged intervals: {result}")
