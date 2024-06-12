 rng(1); % For reproducibility  
r = sqrt(rand(100,1)); % Radius  
t = 2*pi*rand(100,1);  % Angle  
data1 = [r.*cos(t), r.*sin(t)]; % Points  
r2 = sqrt(3*rand(100,1)); % Radius  
t2 = 2*pi*rand(100,1);      % Angle  
data2 = [r2.*cos(t2), r2.*sin(t2)]; % points  
figure;  
plot(data1(:,1),data1(:,2),'r.','MarkerSize',15)  
hold on  
plot(data2(:,1),data2(:,2),'b.','MarkerSize',15)  
ezpolar(@(x)1);ezpolar(@(x)2);  
axis equal  
hold off  
 data3 = [data1;data2];  
theclass = ones(200,1);  
theclass(1:100) = -1;  
% svmModel = svmtrain(data3, theclass, 'kernel_function','rbf','ShowPlot',true);  %高斯核函数
% svmModel = svmtrain(data3, theclass, 'kernel_function','polynomial','ShowPlot',true);  %多项式核函数

