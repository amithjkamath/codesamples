def bubbleSort(arrayIn):
    for i in range(1, len(arrayIn)):
        numSwap = 0
        for j in range(1, len(arrayIn) - i + 1): 
            #optimized: loops only until len(array) - i + 1: the last i elements are known to be sorted by now.
            if arrayIn[j-1] > arrayIn[j]:
                # the next line is a swap in python.
                arrayIn[j-1], arrayIn[j] = arrayIn[j], arrayIn[j-1]
                numSwap += 1
        if numSwap == 0:
            break # as no swaps mean that the list is already sorted.
    return arrayIn            
        
arrayIn = [2, 1, 5, 3, 6, 4]
print arrayIn
print bubbleSort(arrayIn)

print bubbleSort([1])

print bubbleSort([])
