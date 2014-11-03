%Author: Amith Kamath.
%Date: 3/13/2013.
function problem6(number)
%% Problem: Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
% Input: number, to find the difference, 100 here.

sumSq = 0;
sqSum = 0;
for i = 1:number
    sumSq = sumSq + i^2;
    sqSum = sqSum + i;
end
sqSum = sqSum^2;
fprintf('The difference between square of sum and sum of squares of natural numbers up to %d is %d \n',number,sqSum - sumSq);
end