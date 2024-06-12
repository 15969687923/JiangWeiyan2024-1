% function dst_img=myHE(src_img)    
% 
%     [height,width] = size(src_img);  
%     dst_img=uint8(zeros(height,width));  
%     %�������ػҶ�ͳ��;      
%     NumPixel = zeros(1,256);%ͳ�Ƹ��Ҷ���Ŀ����256���Ҷȼ�      
%     for i = 1:height      
%         for j = 1: width      
%             NumPixel(src_img(i,j) + 1) = NumPixel(src_img(i,j) + 1) + 1;%��Ӧ�Ҷ�ֵ���ص���������һ      
%         end      
%     end      
%     %����Ҷȷֲ��ܶ�      
%     ProbPixel = zeros(1,256);      
%     for i = 1:256      
%         ProbPixel(i) = NumPixel(i) / (height * width * 1.0);      
%     end      
%     %�����ۼ�ֱ��ͼ�ֲ�      
%     CumuPixel = zeros(1,256);      
%     for i = 1:256      
%         if i == 1      
%             CumuPixel(i) = ProbPixel(i);      
%         else      
%             CumuPixel(i) = CumuPixel(i - 1) + ProbPixel(i);      
%         end      
%     end      
% 
%     % ָ����Χ���о��⻯    
%     % pixel_max=max(max(I));    
%     % pixel_min=min(min(I));    
%     pixel_max=255;    
%     pixel_min=0;    
%     %�ԻҶ�ֵ����ӳ�䣨���⻯��      
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
imshow(out),title('ԭͼ��');%��ʾԭʼͼ��    
imhist(out),title('ԭͼ��ֱ��ͼ');%��ʾԭʼͼ��ֱ��ͼ    
  
matlab_eq=histeq(out);         %����matlab�ĺ���ֱ��ͼ���⻯  
imshow(matlab_eq),title('matlabֱ��ͼ���⻯ԭͼ��');%��ʾԭʼͼ��    
imshow(matlab_eq),title('matlab���⻯���ֱ��ͼ');%��ʾԭʼͼ��ֱ��ͼ   
  
% dst_img=myHE(out);             %�����Լ�д�ĺ���ֱ��ͼ���⻯  
% subplot(325),imshow(dst_img),title('��д���⻯Ч��');%��ʾԭʼͼ��    
% subplot(326),imhist(dst_img),title('��д���⻯ֱ��ͼ');%��ʾԭʼͼ��ֱ��ͼ   

% imshow(imggray/255);title("imggray");
% imshow(N/255);title("N");
 imshow(out/255);title("out");
% imshow(g/255);title("g");
% imshow(spec/255);title("spec");