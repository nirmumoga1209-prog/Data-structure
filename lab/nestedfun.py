def process (data,callback):
    result =data*2
    callback(result)

def show_output(value):
    print("processed:",value)
process(5,show_output)

process(10,lambda x: print("processed with lambda:",x))

name=["alice","bob","charlie"]
print(sorted(name,key=lambda x: len(x)))