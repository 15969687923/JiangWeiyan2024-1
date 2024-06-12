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
        y=j/k;b=floor(y);%双线性插值算法  
        if a>0&&b>0&&a<h&&b<w 
              cxb=img(a+1,b,rgb)*(x-a)+img(a,b,rgb)*(1+a-x);  
              cxb1=img(a+1,b+1,rgb)*(x-a)+img(a,b+1,rgb)*(1+a-x);  
              img_new(i,j,rgb)=round(cxb1*(y-b)+cxb*(1+b-y));  
        end  
      end  
   end  
end  
[m ,n]=size(img_new);

Fe=1;%控制参数
Fd=128;

xmax=max(max(img_new));
u=(1+(xmax-img_new)/Fd).^(-Fe);     %空间域变换到模糊域

%也可以多次迭代
for i=1:m                       %模糊域增强算子
   for j=1:n
      if u(i,j)<0.5
        u(i,j)=2*u(i,j)^2; 
      else
        u(i,j)=1-2*(1-u(i,j))^2;
      end
   end
end

img_new=xmax-Fd.*(u.^(-1/Fe)-1);    %模糊域变换回空间域
img_new=uint8(img_new);

   
figure,imshow(img_new);
imwrite(img_new,'A3.jpg'); 