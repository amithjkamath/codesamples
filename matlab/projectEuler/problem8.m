%Author: Amith Kamath.
%Date: 3/13/2013.
function problem8(number)
%% Problem: What is the 10 001st prime number?
% Input: number, the index of the prime number to be calculated.
j = 2;
i = 1;
while i <= number
    if(isprime(j))
        i = i + 1;
    end
        j = j + 1;
end
fprintf('The %d th prime number is is %d \n',number,j - 1);
end