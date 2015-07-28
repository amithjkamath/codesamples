def bubbleSort(arrayIn):
    for i in range(len(arrayIn)-1):
        for j in range(len(arrayIn)-1):
            if arrayIn[j] > arrayIn[j+1]:
                # the next line is a swap in python.
                arrayIn[j], arrayIn[j+1] = arrayIn[j+1], arrayIn[j]
    return arrayIn            
        
arrayIn = [2, 1, 5, 3, 6, 4]
print arrayIn
print bubbleSort(arrayIn)

print bubbleSort([1])

print bubbleSort([])
