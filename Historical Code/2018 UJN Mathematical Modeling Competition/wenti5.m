close all;clc;

img=imread('A3.jpg');
png=imread('A2.png');
%imshow(img);
[hm,wm,rm]=size(img);
[hn,wn,rn]=size(png);
h=20;w=290;
for x=1:1:hn
    for y=1:1:wn
        if png(x,y,1)~=255
            img(x+h,y+w,1)=png(x,y,1);
            img(x+h,y+w,2)=png(x,y,2);
            img(x+h,y+w,3)=png(x,y,3);
        end
    end
end

% figure;imshow(png);
figure;imshow(img);