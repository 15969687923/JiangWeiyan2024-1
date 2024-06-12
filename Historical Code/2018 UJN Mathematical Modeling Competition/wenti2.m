close all;clc;

img=imread('A1.jpg');
%imshow(img);

[h,w,r]=size(img);
imgn=zeros(h,w,r);
imgn(:,:,:)=img(:,:,:);

%b=sum(sum(img(:,:,1)));
%c=sum(sum(img(:,:,2)));
%d=sum(sum(img(:,:,3)));
for y=1:1:386
    for x=1:1:346
        a=(img(y,x,1)*0.35+img(y,x,2)*0.31+img(y,x,3)*0.34);
        imgn(y,x,1)=a;
        imgn(y,x,2)=a;
        imgn(y,x,3)=a;
    end
end

figure;imshow(imgn/255);