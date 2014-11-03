%Author: Amith Kamath.
%Date: 3/10/2013.
function problem5(number)
%% Problem: What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
% Input: Largest number for divisibility.
result = 1;
for i = 1:number
    result = lcm(i, result);
end
fprintf('The smallest number is %f \n',result);
end