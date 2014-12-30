% Author: Amith Kamath
% Date: 3/6/2013.
function flagPassed = testSiblings(n)
%% Inputs: n, the test number, 0 if test all.

maxTestNum = 7; %Change this everytime a new test is made.

close all

if n == 0
    for i = 1:maxTestNum
        testSiblings(i);
    end
end

switch n
    case 1
        %1. Create a scene
        %2. save the handle.
        hIn      = plot(linspace(1,5,10),rand(1,10));
        hCorrect = line(linspace(1,5,10),rand(1,10));
        %3. run siblings on hIn
        hOut = siblings(hIn);
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for two lines.\n');
        end
        close all
    case 2
        %1. Create a scene
        %2. save the handle.
        hIn      = figure(1);
        plot(linspace(1,5,10),rand(1,10));
        hCorrect = figure(2);
        plot(linspace(1,5,10),rand(1,10));
        %3. run siblings on hIn
        hOut = siblings(hIn);
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for two figures.\n');
        end
        close all
    case 3
        %1. Create a scene
        %2. save the handle.
        hIn      = subplot(2,1,1);
        plot(linspace(1,5,10),rand(1,10));
        hCorrect = subplot(2,1,2);
        plot(linspace(1,5,10),rand(1,10));
        %3. run siblings on hIn
        hOut = siblings(hIn);
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for two plots.\n');
        end
        close all
    case 4
        %1. Create a scene
        %2. save the handle.
        hIn      = plot(linspace(1,5,10),rand(1,10));
        hCorrect = patch([0 .5 1], [0 1 0], [1 0 0]);
        %3. run siblings on hIn
        hOut     = siblings(hIn);
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for a line and a patch.\n');
        end
        close all   
    case 5
        %1. Create a scene
        %2. save the handle.
        hIn = plot(linspace(1,5,10),rand(1,10));
        %3. run siblings on hIn
        hOut = siblings(hIn);
        hCorrect = [];
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for a single child.\n');
        end
        close all
    case 6
        %1. Create a scene
        %2. save the handle.
        hIn = 0;
        %3. run siblings on hIn
        hOut = siblings(hIn);
        hCorrect = [];
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
            fprintf('Passed test for root.\n');
        end
        close all        
    case 7
        %1. Create a scene
        %2. save the handle.
        hIn       = plot(linspace(1,5,10),rand(1,10));
        hCorrect1 = line(linspace(1,5,10),rand(1,10));
        hCorrect2 = line(linspace(1,5,10),rand(1,10));
        hCorrect  = [hCorrect2; hCorrect1];
        %3. run siblings on hIn
        hOut      = siblings(hIn);
        %4. are hOut and hCorrect the same.
        if evalResult(hOut,hCorrect)
        %5. store results
        fprintf('Passed test for three lines.\n');
        end
        close all
    otherwise
        fprintf('No more test cases.\n');
end
end

function boolPassed = evalResult(hOut, hCorrect)
if isempty(hCorrect)
    boolPassed = isempty(hOut);
end
if size(hOut,2) > 1
    boolPassed = all(hOut == hCorrect);
end
if size(hOut,2) == 1
    boolPassed = (hOut == hCorrect);
end
end