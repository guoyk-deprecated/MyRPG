#pragma once
#include "rendable.h"
class Role :
	public Rendable
{
public:
	Map *map;                     //角色所在的地图
	int speed;                       //移动速度

	float x,y;                       //位置
	int direction;                   //方向，（下左右上）
	bool isongoing;                  //是否处于移动状态
	bool isvisible;                  //角色是否可见

	bool effect;             //是否使用高级特效
	float z1,z2;             //角色头和脚所处的Z值
	float visibility;        //透明度0~1f

	Item *item[20];                   //角色持有的物品
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Role(HTEXTURE texture,Map *mapo);//根据材质和地图位置新建角色
	void FlushQuad();                      //根据当前角色的位置属性，刷新角色的渲染元。着重于渲染元的位置变化和图像变化
	void Effect(float z1,float z2,float visibility);//开启特效，也就是细化显示效果
	void Effectoff();

	Role(void);
	~Role(void);
};

