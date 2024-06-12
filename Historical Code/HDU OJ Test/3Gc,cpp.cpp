#include<iostream>
#include<cstdio>
#include<cstring>

int num[4]={0,5,3,1};
int box[7];

int main(){

    //freopen("input.txt","r",stdin);

    while(1){
        int tmp=0;
        for(int i=1;i<=6;i++){
            scanf("%d",&box[i]);    // 读入每个物品的数目
            tmp+=box[i];
        }
        if(tmp==0)
            break;
        int ans=box[6]+box[5]+box[4]+(box[3]+3)/4;  //a6,a5,a4,每个物品占有一个箱子(a3 + 3 ) / 4 代表a3的物品需要占
        int a2=box[4]*5+num[box[3]%4];  //统计所有的大物品放进箱子中后a2物品的空位子有多少
        if(box[2]>a2)
            ans+=(box[2]-a2+8)/9;
        int a1=ans*36-box[6]*36-box[5]*25-box[4]*16-box[3]*9-box[2]*4;
        if(box[1]>a1)   //求a1的空位子，只需要统计剩余的面积即可
            ans+=(box[1]-a1+35)/36;
        printf("%d\n",ans);
    }
    return 0;
}
