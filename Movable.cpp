#include "Movable.h";



void Movable::TryMove(int odirection,bool domove,bool doupdate){
	int seed=((int)(TIME*7))%FRAME_COUNT;//��ʱ���еó���һ�����ӣ��Ǹ�����������ѡ��ʹ�ú�����ĸ�ͼ�������ͼ
	direction=odirection;
	txy[0]=seed*twh[0];     //�޸Ĳ���x
	txy[1]=direction*twh[1];//�޸Ĳ���y
	if(domove){             //���ȷʵҪ�ƶ�������λ�ƣ�
		switch(direction){
		case 0:
			xy[1]+=speed;
			break;
		case 1:
			xy[0]-=speed;
			break;
		case 2:
			xy[0]+=speed;
			break;
		case 3:
			xy[1]-=speed;
			break;
		}
	}
	if(doupdate){          //ȷ���Ƿ�Ҫ������ȾԪ
		UpdateQuad(Texture);
		UpdateQuad(Position);
	}
}

Movable::Movable(void)
{
	direction=0;
}


Movable::~Movable(void)
{
}
