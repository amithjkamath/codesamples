%Author: Amith Kamath
%Date: 3/6/2013.
function hStruct = createDCPlot(x,y,lev)
%% Inputs: row vector xdata, row vector ydata and scalar horizontal level.

close all
len = size(x,2);
if(size(y,2) ~= len)
    error('x and y need to have same lengths.');
end

figure, 
hStruct.lev = plot(x,lev.*ones(size(x)));
set(hStruct.lev,'Color','g');
hi = y;
hi(y < lev) = nan;
hStruct.hi = line(x,hi);
set(hStruct.hi,'Color','r');
lo = y;
lo(y > lev) = nan;
hStruct.lo = line(x,lo);
set(hStruct.lo,'Color','b');

title('Interactive level color changer demo.');
end