#include <stdio.h>

//����ע������Ϣ�ṹ��
typedef struct 
{
    /* data */
    //ע��������
    int capacity;                       //1ml 3ml 5ml
    //��Ҫע��ļ���
    float injected_dose[5];            //0.8/1ml 2/3ml 3/3ml 4/5ml 5/5ml
}InjectorTypeDef;

int main (void)
{
    //��ʼ��ע������Ϣ
    InjectorTypeDef InjectorStruct[] = {{1, {0.8, 0, 0, 0, 0}},\
                                        {3, {0, 2, 3, 0, 0}},\
                                        {5, {0, 0, 0, 4, 5}}};

    //�ýṹ���ܴ�С���Ե�һ����Ա��С���õ���Ա������
    int Inject_Num = sizeof(InjectorStruct) / sizeof(InjectorStruct[0]);

    //ѭ����һ������i����Χ0~Inject_Num(3)������1ml��3ml��5ml����
    for (int i=0; i<Inject_Num; i++)
    {
        //�ڶ�������j����Χ0~5������5����ͬע�������
        for (int j=0; j<5; j++)
        {
            //�жϵ���������ʱ������ע��
            if (InjectorStruct[i].injected_dose[j] != 0)
            {
                //10~180�ε�ע�������ÿ�μ�10
                for(int time=10; time<=180; time+=10)
                {
                    //���㵥��ע�����
                    float Single_injectier_dose = InjectorStruct[i].injected_dose[j] / time;
                    
                    //��ӡ�����Ϣ
                    printf("Injection dose selection: %1.1f/%dml\n", InjectorStruct[i].injected_dose[j], InjectorStruct[i].capacity);
                    printf("Injection frequency selection: %d times\n", time);
                    printf("The single injection dose is %1.1f / %d = %1.5f ml\n", InjectorStruct[i].injected_dose[j], time, Single_injectier_dose);
                }
            }
        }
    }
    
    return 0;
}