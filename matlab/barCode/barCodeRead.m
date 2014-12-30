function number = barCodeRead(filename)
%% Inputs: Filename for the bar code to be read.
% Author: Amith Kamath
% Date: 3/4/2013.

mat = imread(filename);
mat = im2bw(mat);
mat(:,1:3) = [];
mat(:,end-2:end) = [];

%Avoid all the redundant rows.
mat = mat(1,:);

xLim = size(mat,2);
result = [];
x = 1;
while x < xLim - 1
    if (mat(x) == 0 && mat(x+1) == 0)
        result = [result,'1'];
        x = x + 4;
    else
        result = [result,'0'];
        x = x + 2;
    end
end
disp(['The decoded number is: ',num2str(bin2dec(result))]);
%imshow(mat);
end