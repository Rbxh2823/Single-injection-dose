#include <stdio.h>

//定义注射器信息结构体
typedef struct 
{
    /* data */
    //注射器容量
    int capacity;                       //1ml 3ml 5ml
    //需要注射的剂量
    float injected_dose[5];            //0.8/1ml 2/3ml 3/3ml 4/5ml 5/5ml
}InjectorTypeDef;

int main (void)
{
    //初始化注射器信息
    InjectorTypeDef InjectorStruct[] = {{1, {0.8, 0, 0, 0, 0}},\
                                        {3, {0, 2, 3, 0, 0}},\
                                        {5, {0, 0, 0, 4, 5}}};

    //用结构体总大小除以第一个成员大小，得到成员数量。
    int Inject_Num = sizeof(InjectorStruct) / sizeof(InjectorStruct[0]);

    //循环第一个参数i，范围0~Inject_Num(3)，代表1ml、3ml、5ml量程
    for (int i=0; i<Inject_Num; i++)
    {
        //第二个参数j，范围0~5，代表5个不同注射剂量。
        for (int j=0; j<5; j++)
        {
            //判断当剂量存在时，可以注射
            if (InjectorStruct[i].injected_dose[j] != 0)
            {
                //10~180次的注射次数，每次加10
                for(int time=10; time<=180; time+=10)
                {
                    //计算单次注射剂量
                    float Single_injectier_dose = InjectorStruct[i].injected_dose[j] / time;
                    
                    //打印相关信息
                    printf("Injection dose selection: %1.1f/%dml\n", InjectorStruct[i].injected_dose[j], InjectorStruct[i].capacity);
                    printf("Injection frequency selection: %d times\n", time);
                    printf("The single injection dose is %1.1f / %d = %1.5f ml\n", InjectorStruct[i].injected_dose[j], time, Single_injectier_dose);
                }
            }
        }
    }
    
    return 0;
}