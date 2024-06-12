close all;clc;

img=imread('A1.jpg');
imshow(img,[]);

[h,w,r]=size(img);
imgn=zeros(h,w,r);
imgn(:,:,:)=img(:,:,:);
n=6;
nw=floor(w/n)*n;
nh=floor(h/n)*n;
for y=19:n:25
    for x=175:n:211
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=25:n:31
    for x=163:n:223
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=31:n:37
    for x=157:n:229
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=37:n:73
    for x=145:n:235
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=73:n:85
    for x=139:n:241
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=85:n:115
    for x=145:n:241
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=115:n:121
    for x=145:n:229
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=121:n:127
    for x=169:n:229
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=127:n:133
    for x=175:n:217
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end
for y=133:n:139
    for x=181:n:211
        imgn(y:y+n-1,x:x+n-1,1)=mean(mean(img(y:y+n-1,x:x+n-1,1))); 
        imgn(y:y+n-1,x:x+n-1,2)=mean(mean(img(y:y+n-1,x:x+n-1,2)));
        imgn(y:y+n-1,x:x+n-1,3)=mean(mean(img(y:y+n-1,x:x+n-1,3)));
    end

   
end

figure;imshow(imgn/255);