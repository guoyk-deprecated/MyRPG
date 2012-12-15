#pragma once
#include "rendable.h"
class Role :
	public Rendable
{
public:
	Map *map;                     //��ɫ���ڵĵ�ͼ
	int speed;                       //�ƶ��ٶ�

	float x,y;                       //λ��
	int direction;                   //���򣬣��������ϣ�
	bool isongoing;                  //�Ƿ����ƶ�״̬
	bool isvisible;                  //��ɫ�Ƿ�ɼ�

	bool effect;             //�Ƿ�ʹ�ø߼���Ч
	float z1,z2;             //��ɫͷ�ͽ�������Zֵ
	float visibility;        //͸����0~1f

	Item *item[20];                   //��ɫ���е���Ʒ
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Role(HTEXTURE texture,Map *mapo);//���ݲ��ʺ͵�ͼλ���½���ɫ
	void FlushQuad();                      //���ݵ�ǰ��ɫ��λ�����ԣ�ˢ�½�ɫ����ȾԪ����������ȾԪ��λ�ñ仯��ͼ��仯
	void Effect(float z1,float z2,float visibility);//������Ч��Ҳ����ϸ����ʾЧ��
	void Effectoff();

	Role(void);
	~Role(void);
};

