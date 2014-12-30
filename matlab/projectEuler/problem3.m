%Author: Amith Kamath.
%Date: 3/7/2013.
function problem3(number)
%% Input: Find the largest prime factor of number.

factors = [];
divVal = 2;
while (number ~= 1)
    if(rem(number,divVal) == 0)
        number = number/divVal;
        factors = [factors divVal];
    else
        divVal = divVal + 1;
    end
end

max(divVal)
end