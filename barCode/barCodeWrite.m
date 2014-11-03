function done = barCodeWrite(number, height, edgeSize)
%% Inputs: number to be encoded, height of the bar code, width of edges.
% Author: Amith Kamath
% Date: 3/4/2013.

%if ~exist(height,'var')
%    height = 30;
%end
%if ~exist(edgeSize,'var')
%    edgeSize = 3;
%end

binNumber = dec2bin(number);

mat = ones(1,edgeSize);

for i = 1:numel(binNumber)
   if binNumber(i) == '1'
      mat = [mat 0 0 0 1]; 
   else
      mat = [mat 0 1]; 
   end
end

mat = [mat ones(1,edgeSize)];
mat = repmat(mat,[height,1]);

imshow(mat,[]); title(['Bar code for: ',num2str(number)]);
try
numStr = num2str(number);
if(numel(numStr) > 4)
    done = 0;
    return;
end

while(numel(numStr) ~= 4)
   numStr = strcat('0',numStr); 
end
filename = ['bc',numStr,'.png'];

imwrite(mat,filename,'png');
done = 1;

catch
    disp('Cannot Write file. Try again.');
    done = 0;
end
end