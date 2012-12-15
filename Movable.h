#pragma once
#include "HGEHeaders.h";
#include "Rendable.h";
#define FRAME_COUNT 4;
//Movable子类派生于Rendable基类则默认材质文件为人物专用材质文件，使用四横行代表四个方向
class Movable:public Rendable
{
public:
	float speed;   //运动速度
	int direction; //方向 下左右上
	bool isongoing;//是否处在运动状态
	void TryMove(int odirection,bool domove=false,bool doupdate=true);  //尝试向某个方向运动一下，然后是否真的运动，是否刷新Quad
	Movable(void);
	~Movable(void);
};

