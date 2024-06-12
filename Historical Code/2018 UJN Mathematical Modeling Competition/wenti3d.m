% function dst_img=myHE(src_img)    
% 
%     [height,width] = size(src_img);  
%     dst_img=uint8(zeros(height,width));  
%     %进行像素灰度统计;      
%     NumPixel = zeros(1,256);%统计各灰度数目，共256个灰度级      
%     for i = 1:height      
%         for j = 1: width      
%             NumPixel(src_img(i,j) + 1) = NumPixel(src_img(i,j) + 1) + 1;%对应灰度值像素点数量增加一      
%         end      
%     end      
%     %计算灰度分布密度      
%     ProbPixel = zeros(1,256);      
%     for i = 1:256      
%         ProbPixel(i) = NumPixel(i) / (height * width * 1.0);      
%     end      
%     %计算累计直方图分布      
%     CumuPixel = zeros(1,256);      
%     for i = 1:256      
%         if i == 1      
%             CumuPixel(i) = ProbPixel(i);      
%         else      
%             CumuPixel(i) = CumuPixel(i - 1) + ProbPixel(i);      
%         end      
%     end      
% 
%     % 指定范围进行均衡化    
%     % pixel_max=max(max(I));    
%     % pixel_min=min(min(I));    
%     pixel_max=255;    
%     pixel_min=0;    
%     %对灰度值进行映射（均衡化）      
%     for i = 1:height      
%         for j = 1: width      
%             dst_img(i,j) = CumuPixel(src_img(i,j)+1)*(pixel_max-pixel_min)+pixel_min;      
%         end      
%     end      
% return;  

I=imread('A1.jpg');  
% imshow(I);  
figure();  
info_size=size(I);  
height=info_size(1);  
width=info_size(2);  
N=zeros(height,width);  
g=zeros(height,width);  
imggray=rgb2gray(I);  
out=zeros(height,width);  
  
spec=zeros(height,width,3);  
for i=1:height  
    for j=1:width  
          
        N(i,j)=255-imggray(i,j);  
          
    end  
end  
  
for i=2:height-1  
    for j=2:width-1  
        sum=0;  
        sum=1*double(N(i-1,j-1))+2*double(N(i-1,j))+1*double(N(i-1,j+1));  
        sum=sum+2*double(N(i,j-1))+4*double(N(i,j))+2*double(N(i,j+1));  
        sum=sum+1*double(N(i+1,j-1))+2*double(N(i+1,j))+1*double(N(i+1,j+1));  
        sum=sum/16;  
        g(i,j)=sum;  
    end  
end  
  
for i=1:height  
    for j=1:width  
        b=double(g(i,j));  
        a=double(imggray(i,j));  
        temp=a+a*b/(256-b);  
        out(i,j)=uint8(min(temp,255));  
          
    end  
end     
  
figure (1)   
imshow(out),title('原图像');%显示原始图像    
imhist(out),title('原图像直方图');%显示原始图像直方图    
  
matlab_eq=histeq(out);         %利用matlab的函数直方图均衡化  
imshow(matlab_eq),title('matlab直方图均衡化原图像');%显示原始图像    
imshow(matlab_eq),title('matlab均衡化后的直方图');%显示原始图像直方图   
  
% dst_img=myHE(out);             %利用自己写的函数直方图均衡化  
% subplot(325),imshow(dst_img),title('手写均衡化效果');%显示原始图像    
% subplot(326),imhist(dst_img),title('手写均衡化直方图');%显示原始图像直方图   

% imshow(imggray/255);title("imggray");
% imshow(N/255);title("N");
 imshow(out/255);title("out");
% imshow(g/255);title("g");
% imshow(spec/255);title("spec");