#include "Movable.h";



void Movable::TryMove(int odirection,bool domove,bool doupdate){
	int seed=((int)(TIME*7))%FRAME_COUNT;//从时间中得出的一个种子，是个整数，用来选择使用横向的哪个图像进行贴图
	direction=odirection;
	txy[0]=seed*twh[0];     //修改材质x
	txy[1]=direction*twh[1];//修改材质y
	if(domove){             //如果确实要移动，进行位移；
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
	if(doupdate){          //确定是否要更新渲染元
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
