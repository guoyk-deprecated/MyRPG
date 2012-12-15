#pragma once
//大规模HGE引用
#include <hge\hge.h>
#include <hge\hgeanim.h>
#include <hge\hgecolor.h>
#include <hge\hgedistort.h>
#include <hge\hgefont.h>
#include <hge\hgegui.h>
#include <hge\hgeguictrls.h>
#include <hge\hgeparticle.h>
#include <hge\hgerect.h>
#include <hge\hgeresource.h>
#include <hge\hgesprite.h>
#include <hge\hgestrings.h>
#include <hge\hgevector.h>

#define TIME hge->Timer_GetTime()
static HGE *hge=hgeCreate(HGE_VERSION); //全局HGE引擎指针，只使用一个，并且必须在此处初始化
