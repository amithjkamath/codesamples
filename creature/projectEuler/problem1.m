%Author: Amith Kamath.
%Date: 3/7/2013.
function problem1(limit)
%% Input: Find the sum of all multiples of 3 or 5, up to but not including limit.
%limit= 1000;

runningTotal = 0;
for n = 1:limit - 1
   if(mod(n,3) == 0 || mod(n,5) == 0)
       runningTotal = runningTotal + n;
   end
end

disp(runningTotal)