img=double(imread('A1.jpg')); 

[h, w, r]=size(img);  
img=double(img);  
k=2;
x_new=h*k;  
y_new=w*k;
  
img_new=zeros(x_new,y_new,r);  
for rgb=1:r  
   for i=1:x_new  
     for j=1:y_new  
        x=i/k;a=floor(x);  
        y=j/k;b=floor(y);%˫���Բ�ֵ�㷨  
        if a>0&&b>0&&a<h&&b<w 
              cxb=img(a+1,b,rgb)*(x-a)+img(a,b,rgb)*(1+a-x);  
              cxb1=img(a+1,b+1,rgb)*(x-a)+img(a,b+1,rgb)*(1+a-x);  
              img_new(i,j,rgb)=round(cxb1*(y-b)+cxb*(1+b-y));  
        end  
      end  
   end  
end  
[m ,n]=size(img_new);

Fe=1;%���Ʋ���
Fd=128;

xmax=max(max(img_new));
u=(1+(xmax-img_new)/Fd).^(-Fe);     %�ռ���任��ģ����

%Ҳ���Զ�ε���
for i=1:m                       %ģ������ǿ����
   for j=1:n
      if u(i,j)<0.5
        u(i,j)=2*u(i,j)^2; 
      else
        u(i,j)=1-2*(1-u(i,j))^2;
      end
   end
end

img_new=xmax-Fd.*(u.^(-1/Fe)-1);    %ģ����任�ؿռ���
img_new=uint8(img_new);

   
figure,imshow(img_new);
imwrite(img_new,'A3.jpg'); 