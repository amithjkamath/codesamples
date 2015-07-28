function inArray = bubbleSort(inArray)

for i = 1:numel(inArray) - 1
   numSwaps = 0;
    for j = 1:numel(inArray) - i %optimization: last i elements are already sorted.
        if(inArray(j) > inArray(j+1))
            temp = inArray(j);
            inArray(j) = inArray(j+1);
            inArray(j+1) = temp;
            numSwaps = numSwaps + 1;
        end 
    end
    if(numSwaps == 0) 
        % this means that no swap has happened in the ith iteration
        % and hence means that the list is already sorted.
        break;
    end
end

end