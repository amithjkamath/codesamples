%Author: Amith Kamath.
%Date: 3/7/2013.
function result = problem2(limit)
%% Find the sum of all even fibonacci numbers, up to limit.
%limit= 1000;

numbers = genFibonacci(limit);
indices = mod(numbers,2) == 0;
result = sum(numbers(indices));
end

function numbers = genFibonacci(limit)
    num1 = 1;
    num2 = 2;
    numbers = [num1 num2];
    nextNum = 0;
    while(nextNum < limit - 1)
       numbers = [numbers numbers(end)+numbers(end-1)];
       nextNum = numbers(end);
    end
end