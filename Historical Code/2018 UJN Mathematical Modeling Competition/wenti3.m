%������Ч��  
handles.pic=imread('A1.jpg');  
figure,imshow(handles.pic);
handles.pic=rgb2gray(handles.pic);  
%figure,imshow(handles.pic);title('�Ҷ�Ч��');  
bw=edge(handles.pic,'canny');%����ͼ��������ȡ   
se = strel('line',3,0);%����ֱ�߳���3�Ƕ�Ϊ0��̬ѧԪ��  
bwd=imdilate(bw,se);%��ͼ��ʵʩ���Ͳ���  
figure,imshow(bwd);title('������Ч��');  
%matlabʵ���ͻ�,����,αɫ��,��Ƭ,������Ч������  
%����[ͼƬ]http://www.wenkuxiazai.com/doc/515b31260722192e4536f64b-10.html  
d=imcomplement(bwd);  
figure,imshow(d);  
title('�׵׺���ͼ��')  