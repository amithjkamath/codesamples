% Interface: 
%   String vector output.
%   Integer numeric input.
function outstr = fizzbuzz(n)
    validateattributes(n, {'numeric'}, {'integer', 'positive'}, mfilename);
    
    outstr = repmat(string(), n, 1);
    
    for idx = 1:n
        if mod(idx, 3) == 0
            outstr(idx) = "fizz";
        end
        if mod(idx, 5) == 0
            outstr(idx) = outstr(idx) + "buzz";
        end
    end
end