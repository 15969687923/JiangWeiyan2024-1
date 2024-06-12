I=imread('A1.jpg');  
% imshow(I);  
figure();  
[height,width,r]=size(I);
n=zeros(height,width);  
d=zeros(height,width);
g=zeros(height,width);  
out=zeros(height,width);  
outt=zeros(height,width);
% spec=zeros(height,width,3);  

for y=1:1:height
    for x=1:1:width
        
        d(y,x)=(I(y,x,1)*0.35+I(y,x,2)*0.31+I(y,x,3)*0.34);%取黑白
        n(y,x)=255-d(y,x);%取反色
        
    end
end 

%  disp(n);
%  imshow(n/255);   %因为是黑白图，所以需要数值是0~1

for i=2:1:height-1  %高斯模糊
    for j=2:1:width-1  
        sum=0;  
        sum=2*double(n(i-1,j-1))+4*double(n(i-1,j))+2*double(n(i-1,j+1));  
        sum=sum+4*double(n(i,j-1))+8*double(n(i,j))+4*double(n(i,j+1));  
        sum=sum+2*double(n(i+1,j-1))+4*double(n(i+1,j))+2*double(n(i+1,j+1));  
        sum=sum/32;
        g(i,j)=sum;
    end  
end  
%disp(n(1:20,1:20));
%disp(g(1:20,1:20));
for i=2:1:height-1  
    for j=2:1:width-1

%         sum1=0;  sum2=0;  sum3=0;  sum4=0;  sum5=0;  sum6=0; summ=0;
%         sum1=g(i-1,j-1)+g(i-1,j)+g(i-1,j+1);    %上
%         sum5=d(i-1,j-1)+d(i-1,j)+d(i-1,j+1);    %上
%         sum2=g(i+1,j-1)+g(i+1,j)+g(i+1,j+1);    %下
%         sum6=d(i+1,j-1)+d(i+1,j)+d(i+1,j+1);    %下
%         sum3=g(i-1,j-1)+g(i,j-1)+g(i+1,j-1);    %左
%         sum7=d(i-1,j-1)+d(i,j-1)+d(i+1,j-1);    %左
%         sum4=g(i-1,j+1)+g(i,j+1)+g(i+1,j+1);    %右
%         sum8=d(i-1,j+1)+d(i,j+1)+d(i+1,j+1);    %右
%         if abs(sum1-sum5)>700 & abs(sum2-sum6)>700
%             summ=1;
%         elseif abs(sum3-sum7)>700 & abs(sum4-sum8)>700
%             summ=1;
%         end
%         if summ==1
%             out(i,j)=0;
%         else
%             out(i,j)=255;
%         end


        b=double(g(i,j));  %颜色减淡算法
        a=d(i,j);  
        temp=a+a*b/(256-b);  
        out(i,j)=min(temp,255); 
%         if out(i,j)<240
%             out(i,j)=0;
%         else
%             out(i,j)=255;
%         end
        

    end  
end  
% outt = imadjust(out, [75/255, 160/255], [0, 1]);
disp(out);
imshow(out/255);