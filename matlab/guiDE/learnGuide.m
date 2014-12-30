function varargout = learnGuide(varargin)
% LEARNGUIDE MATLAB code for learnGuide.fig
%      LEARNGUIDE, by itself, creates a new LEARNGUIDE or raises the existing
%      singleton*.
%
%      H = LEARNGUIDE returns the handle to a new LEARNGUIDE or the handle to
%      the existing singleton*.
%
%      LEARNGUIDE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in LEARNGUIDE.M with the given input arguments.
%
%      LEARNGUIDE('Property','Value',...) creates a new LEARNGUIDE or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before learnGuide_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to learnGuide_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help learnGuide

% Last Modified by GUIDE v2.5 07-Mar-2013 14:51:43

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @learnGuide_OpeningFcn, ...
                   'gui_OutputFcn',  @learnGuide_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before learnGuide is made visible.
function learnGuide_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to learnGuide (see VARARGIN)

% Choose default command line output for learnGuide
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes learnGuide wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = learnGuide_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
doRefresh(handles);

% --- Executes on button press in checkbox1.
function checkbox1_Callback(hObject, eventdata, handles)
% hObject    handle to checkbox1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of checkbox1
doRefresh(handles);


function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double
doRefresh(handles);

% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


function doRefresh(handles)

if(get(handles.checkbox1,'value') ~= 0)
    title('The title is on!');
    %disp('button checked');
else
    title(''); %Reset the title to blank.
    %disp('button unchecked'); 
end

number = get(handles.edit1,'string');
numVal = str2double(number);
if(~isnan(numVal) && numVal <= 12 && numVal > 0)
    surf(membrane(numVal));
    title(['Membrane of order: ',num2str(numVal)]);
elseif (~isnan(numVal) && numVal > 12)
    surf(membrane(12));
    title(['Membrane of order: 12']);
else
    surf(membrane);
       title(['Membrane of order: 1']); 
end

