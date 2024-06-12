%% I. ��ջ�������
clear all
clc
warning off
%% II. ��������
load fisheriris
%%
% 1. �������ѵ����/���Լ�
a = randperm(150);
P_train = features(a(1:120),:);
P_test = features(a(121:end),:);
T_train = classes(a(1:120),:);
T_test = classes(a(121:end),:);
%% III. �������ɭ�ַ�����
model = classRF_train(P_train,T_train);
%% IV. �������
[T_sim,votes] = classRF_predict(P_test,model);
index = find(T_sim ~= T_test);
accuracy = 1-length(index)/length(T_test)