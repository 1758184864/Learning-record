#include <stdio.h>

int main()
{
	double oldHour;
	double oldMin;
	double newHour;
	double newMin;
	//	�����һ��ʱ��
	scanf("%d %d",&oldHour,&oldMin); 
	//	����ڶ���ʱ��
	scanf("%d %d",&newHour,&newMin);
	
	double dex = newHour*60+newMin - (oldHour*60 + oldMin);
	printf("���%d����",dex);
	return 0;
}
