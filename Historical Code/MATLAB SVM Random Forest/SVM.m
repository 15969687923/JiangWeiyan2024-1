%%鸢尾花二分类
load fisheriris  
xdata = meas(1:100,1:2);  
group = species(1:100);  
xdata(101,1)=8.0;
xdata(101,2)=3.6;
group(101)={'setosa'};

svmStruct = svmtrain(xdata,group,'ShowPlot',true);  
% plot(xdata(101,1),xdata(101,2),'ro');
