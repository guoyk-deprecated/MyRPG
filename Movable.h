#pragma once
#include "HGEHeaders.h";
#include "Rendable.h";
#define FRAME_COUNT 4;
//Movable����������Rendable������Ĭ�ϲ����ļ�Ϊ����ר�ò����ļ���ʹ���ĺ��д����ĸ�����
class Movable:public Rendable
{
public:
	float speed;   //�˶��ٶ�
	int direction; //���� ��������
	bool isongoing;//�Ƿ����˶�״̬
	void TryMove(int odirection,bool domove=false,bool doupdate=true);  //������ĳ�������˶�һ�£�Ȼ���Ƿ�����˶����Ƿ�ˢ��Quad
	Movable(void);
	~Movable(void);
};

