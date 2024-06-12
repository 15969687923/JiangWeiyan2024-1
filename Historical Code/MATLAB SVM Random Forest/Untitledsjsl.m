%% I. 清空环境变量
clear all
clc
warning off
%% II. 导入数据
load fisheriris
%%
% 1. 随机产生训练集/测试集
a = randperm(150);
P_train = features(a(1:120),:);
P_test = features(a(121:end),:);
T_train = classes(a(1:120),:);
T_test = classes(a(121:end),:);
%% III. 创建随机森林分类器
model = classRF_train(P_train,T_train);
%% IV. 仿真测试
[T_sim,votes] = classRF_predict(P_test,model);
index = find(T_sim ~= T_test);
accuracy = 1-length(index)/length(T_test)