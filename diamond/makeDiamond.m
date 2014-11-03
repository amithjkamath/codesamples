function mat = makeDiamond(imWidth,rowC, colC, radius)
%% Inputs: width of the image, row center, column center and 'radius' of the diamond.
% Author: Amith Kamath
% Date: 3/4/2013.

%Input parsing.
if nargin == 0
    imWidth = 100;
    rowC    = 50;
    colC    = 50;
    radius  = 25;
end

mat = zeros(imWidth);

%%Dirty way
%mat(rowC-radius:rowC+radius,colC-radius:colC+radius) = 1;
%mat = imrotate(mat,45);
%imshow(mat);

%%Computer Sciency way
%Vertical line.
mat(rowC-radius:rowC+radius,colC) = 1;
radiusTemp = radius;
%bottom triangle.
for x = rowC:rowC+radius
    mat(x,colC-radiusTemp:colC+radiusTemp) = 1;
    radiusTemp = radiusTemp - 1;
end
%Upper triangle.
radiusTemp = 0;
for x = rowC-radius:rowC-1
    mat(x,colC-radiusTemp:colC+radiusTemp) = 1;
    radiusTemp = radiusTemp + 1;
end

%%Image processing way
%mat(rowC,colC) = 1;
%SE = strel('diamond',radius);
%mat = imdilate(mat,SE);
%imshow(mat);

%%matlabby way
%Do a manhattan distance with rows and columns distance measured in a new
%matrix. try mandist. Check Pete's code!

%%Visualize.
imshow(mat,[]); 
title(['Diamond with location (',num2str(rowC), ',', num2str(colC), ') with radius: ', num2str(radius)]);
end