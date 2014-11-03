%Author: Amith Kamath.
%Date: 3/7/2013.
function problem4()
%% Input: Find the largest palindrome from product of two 3 digit numbers.

i = 999;
j = 999;
result = zeros(i,j);

for i = 1:size(result,1)
    for j = 1:size(result,2)
        number = i*j;
        if ispalindrome(number)
            result(i,j) = number; 
        end
    end
end
maxPalindrome = max(max(result));
fprintf('Largest palimdrome is: %f\n',maxPalindrome);
[row col] = find(result == maxPalindrome);
fprintf('The two numbers are: %f and %f\n',row,col);
end

function result = ispalindrome(number)
    numStr  = num2str(number);
    numFlip = fliplr(numStr);
    if (isequal(numStr,numFlip))
        result = 1;
    else
        result = 0;
    end
end