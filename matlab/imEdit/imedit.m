classdef imedit < handle
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties (SetAccess = private, GetAccess = private)
        Figure
        Axis
        ImageHandle
        
        Load
        Save
        FileName
        PathName
        
        ImageData
        ImageShow
        
        Invert
        Revert
        WhiteBalance
        Brightness
        BrightText
        Contrast
        ContrastText
        Saturation
        SaturationText
    end
    
    methods
        function app = imedit
        % This is the "constructor" for the class
        % It runs when an object of this class is created
            app.ImageData = imread('peppers.png');
            app.Figure = figure('MenuBar','none',...          % Main figure
            'NumberTitle','off','Name','Image Editing Tool',...
            'Resize','off',...
            'CloseRequestFcn',@app.closeApp);
            
            %Position the app in the center of the screen
            sz = get(0,'ScreenSize');
            wSz = get(app.Figure,'Position');
            wSz(1) = round((sz(3)-wSz(3))/2);
            wSz(2) = round((sz(4)-wSz(4))/2);
            wSz(3) = round(sz(3)/2);
            wSz(4) = round(sz(4)/2);
            set(app.Figure,'Position',wSz);
            
            app.ImageShow = app.ImageData;
            app.ImageHandle = image(app.ImageShow);
            app.Axis = get(app.Figure,'Children');
            
            set(app.Axis,'Position',[0.15 0.15 0.80 0.80]);
            set(app.Axis,'XTickLabel',[]);
            set(app.Axis,'YTickLabel',[]);
            
            app.Invert = uicontrol(app.Figure,...          % 'Symbol' label
            'Style','togglebutton','Position',[20 40 50 20],...
            'String','Invert',...
            'Callback', @app.invertCB);       
            
            app.WhiteBalance = uicontrol(app.Figure,...          % 'Symbol' label
            'Style','togglebutton','Position',[20 80 50 20],...
            'String','WB',...
            'Callback', @app.WhiteBalanceCB);        
        
            app.Brightness = uicontrol('Style', 'slider',...
            'Min',-50,'Max',50,'Value',0,...
            'Position', [150 20 120 20],...
            'Callback', @app.brightnessCB);   
            
            app.BrightText = uicontrol('Style','text',...
            'Position',[150 0 120 20],...
            'String','Brightness');   
        
            app.Contrast = uicontrol('Style', 'slider',...
            'Min',0,'Max',0.49,'Value',0,... %to avoid the 0, 0 case.
            'Position', [350 20 120 20],...
            'Callback', @app.contrastCB);

            app.ContrastText = uicontrol('Style','text',...
            'Position',[350 0 120 20],...
            'String','Contrast');      
        
            app.Saturation = uicontrol('Style', 'slider',...
            'Min',0,'Max',2,'Value',1,... %to avoid the 0, 0 case.
            'Position', [550 20 120 20],...
            'Callback', @app.saturationCB);

            app.ContrastText = uicontrol('Style','text',...
            'Position',[550 0 120 20],...
            'String','Saturation');   
        
            app.Load = uicontrol(app.Figure,...          % 'Symbol' label
            'Style','pushbutton','Position',[20 200 50 20],...
            'String','Load',...
            'Callback', @app.loadCB);    
            app.Save = uicontrol(app.Figure,...          % 'Symbol' label
            'Style','pushbutton','Position',[20 160 50 20],...
            'String','Save',...
            'Callback', @app.saveCB);   
            app.Revert = uicontrol(app.Figure,...          % 'Symbol' label
            'Style','pushbutton','Position',[20 120 50 20],...
            'String','Revert',...
            'Callback', @app.revertCB);   
        end

        function closeApp(app,~,~)
            % This function runs when the app is closed
            delete(app.Figure)
            clc
        end
%{
        function ResizeFigFcn(app,~,~)
             sz = get(app.Figure,'Position');
             if(sz(3) < 600)
                 sz(3) = 600;
                 set(app.Figure,'Position',sz);
             end
             sz = get(app.Figure,'Position');
             if(sz(4) < 600)
                 sz(4) = 600;
                 set(app.Figure,'Position',sz);
             end
         end
%}        
        function revertCB(app,~,~)
            % This function runs when the revert button is clicked
            app.ImageShow = app.ImageData;
            set(app.ImageHandle,'CData',app.ImageData);
            set(app.Brightness,'Value',0);
            set(app.Contrast,'Value',0);
            set(app.Invert,'Value',0);
            set(app.WhiteBalance,'Value',0);
            set(app.Saturation,'Value',1);
        end

        function loadCB(app,~,~)
            % This function runs when the invert button is clicked
            [app.FileName,app.PathName] = uigetfile('*.jpg','Select the Image to open');
            if(app.FileName ~= 0)
                app.ImageData = imread(fullfile(app.PathName,app.FileName));
                app.ImageData = uint8(app.ImageData); % force 255 levels on load.
            end
            app.ImageShow = app.ImageData;
            app.ImageHandle = image(app.ImageShow);
            set(app.Axis,'XTickLabel',[]);
            set(app.Axis,'YTickLabel',[]);
            set(app.Invert,'Value',0);
            set(app.Brightness,'Value',0.5);
            set(app.Contrast,'Value',0);
        end
        
        function saveCB(app,~,~)
            % This function runs when the invert button is clicked
            [file,path] = uiputfile({'*.jpg;*.tif;*.png;*.gif','All Image Files';...
            '*.*','All Files' },'Save Image');
            if isequal(file,0) || isequal(path,0)
                msgbox('File saving cancelled.','No file saved','warn','modal');
            else
                ext = regexp(file,'\.');
                imwrite(app.ImageShow,fullfile(path,file),file(ext+1:end));
            end
        end        

        function WhiteBalanceCB(app,~,~)
            % This function runs when the WB button is clicked
            app.processImg();
        end           
        
        function invertCB(app,~,~)
            % This function runs when the invert button is clicked
            app.processImg();
        end

        function brightnessCB(app,~,~)
            % This function runs when the brightness slider is used
            app.processImg();
        end
        
        function contrastCB(app,~,~)
            % This function runs when the contrast slider is used
            app.processImg();
        end
 
        function saturationCB(app,~,~)
            % This function runs when the saturation slider is used
            app.processImg();
        end
        
        function processImg(app)
            if(get(app.Invert,'Value') == 1)
                app.ImageShow = app.invertImage(app.ImageData);
            else
                app.ImageShow = app.ImageData;
            end
            app.ImageShow = app.changeBrightness(app.ImageShow, get(app.Brightness,'Value'));            
            app.ImageShow = app.changeSaturation(app.ImageShow, get(app.Saturation,'Value'));                        
            if(get(app.WhiteBalance,'Value') == 1)
            app.ImageShow = app.whiteBalance(app.ImageShow);              
            end                   
            app.ImageShow = app.changeContrast(app.ImageShow, get(app.Contrast,'Value'));
            set(app.ImageHandle,'CData',app.ImageShow);            
        end
        
        function outImg = invertImage(~,inImg) % ~ is the app object, not used here.
            I = uint8(255*ones(size(inImg)));
            outImg = I - inImg;               
        end
        
        function outImg = whiteBalance(~,inImg)
            pageSize = size(inImg,1) * size(inImg,2);
            avg_rgb = mean( reshape(inImg, [pageSize,3]) );
            avg_all = mean(avg_rgb);
            scaleArray = max(avg_all, 128)./avg_rgb;
            scaleArray = reshape(scaleArray,1,1,3);
            outImg = uint8(bsxfun(@times,double(inImg),scaleArray));               
        end
        
        function outImg = changeBrightness(~,inImg, brightVal)
            outImg = inImg + brightVal.*2;              
        end
        
        function outImg = changeContrast(~,inImg, contVal)
            outImg = imadjust(inImg,[contVal 1-contVal],[]);            
        end
        
        function outImg = changeSaturation(~,inImg, satVal)
            hsvIm = rgb2hsv(inImg);
            hsvIm(:,:,2) = hsvIm(:,:,2).*satVal;
            inds = hsvIm >= 1;
            hsvIm(inds) = 1;
            outImg = uint8(hsv2rgb(hsvIm).*255); %to avoid doubles.           
        end        
    end
end

