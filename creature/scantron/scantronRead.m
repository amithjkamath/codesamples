function scantronRead(filename)
%% Input: filename for the scantron image.
% Author: Amith Kamath
% Date: 3/4/2013.

I = imread(filename);
SE = strel('disk',3);
K = imopen(I,SE);
K = ~im2bw(K);
imshow(K)
figure, plot(sum(K,1));
end