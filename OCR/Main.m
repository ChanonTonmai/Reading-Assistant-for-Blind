% PRINCIPAL PROGRAM

warning off %#ok<WNOFF>
% Clear all
clc, close all, clear all

% Read image LOAD AN IMAGE
[filename, pathname] = uigetfile('*','LOAD AN IMAGE');
imagen = imread(fullfile(pathname, filename));

% Show image
imshow(imagen);
title('ENTER');

% Convert to gray scale
if size(imagen,3) == 3 %RGB image
    imagen=rgb2gray(imagen);
end
% Convert to BW
threshold = graythresh(imagen);
imagen =~ imbinarize(imagen,threshold);


%Storage matrix word from image
word = [ ];
re = imagen;

%Make and open *.txt as file for write
b = find(filename=='.');
pathname = [pathname filename(:,1:b-1) '.TXT'] ;
[FileName, PathName]= uiputfile('*.txt','Where do you want to save?', pathname);
save(fullfile(PathName, FileName));
fid = fopen(fullfile(PathName, FileName), 'wt');



tic

while 1 
    [fl, re] = lines(re);
    [ocrI, results] = evaluateOCRTraining(fl);
       
    %letter concatenation
    word = [word results.Text]; 
    if isempty(re)  %breaks loop when there are no more characters
           break;
    end
end

fprintf(fid,word);
fclose(fid);

% %Open '*.txt' file
open(fullfile(PathName, FileName))
toc




