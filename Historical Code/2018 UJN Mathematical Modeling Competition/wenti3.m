%单线条效果  
handles.pic=imread('A1.jpg');  
figure,imshow(handles.pic);
handles.pic=rgb2gray(handles.pic);  
%figure,imshow(handles.pic);title('灰度效果');  
bw=edge(handles.pic,'canny');%数字图像轮廓提取   
se = strel('line',3,0);%创建直线长度3角度为0形态学元素  
bwd=imdilate(bw,se);%对图像实施膨胀操作  
figure,imshow(bwd);title('单线条效果');  
%matlab实现油画,浮雕,伪色彩,底片,单线条效果程序。  
%下载[图片]http://www.wenkuxiazai.com/doc/515b31260722192e4536f64b-10.html  
d=imcomplement(bwd);  
figure,imshow(d);  
title('白底黑线图像')  