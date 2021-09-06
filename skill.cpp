#include "pch.h"
#include "skill.h"
#include "poketmon.h"

skill::skill()
{
}

skill::~skill()
{
}

HRESULT skill::init()
{
	STATUS_AILMENT::NONE;	// 상태이상 초기값은 없음

	return S_OK;
}

void skill::release()
{
}

void skill::update()
{
}

void skill::render()
{
}

void skill::tackle()			// 몸통박치기
{
	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입

}

void skill::stringShot()		//실뿜기
{
	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 95;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::BUG;					//타입

}

void skill::harden()			//단단해지기
{
	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::confusion()			//염동력
{
	_power = 50;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::PSYCHC;				//타입	
}

void skill::poisonPowder()		//독가루
{
	_power = NULL;				//위력
	_PP = 35;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::POISON;				//타입
	STATUS_AILMENT::POISON;		//상태이상
}

void skill::stunSpore()			//저리가루
{
	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GRASS;				//타입
	STATUS_AILMENT::PARALYSIS;	//상태이상
}

void skill::sleepPowder()		//수면가루
{
	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 75;				//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GRASS;				//타입
	STATUS_AILMENT::SLEEP;		//상태이상
}

void skill::poisonSting()		//독침
{
	_index = RND->getFromIntTo(0, 100);

	_power = 15;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::POISON;				//타입

	if (_index > 80) STATUS_AILMENT::POISON;	//상태이상 20퍼 확률로..

}

void skill::focusEnergy()		//기충전
{
	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::twineedle()			//더블니들
{
	_power = 25;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::BUG;					//타입
}

void skill::sandAttack()		//모래뿌리기
{
	_power = NULL;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::GROUND;				//타입

}

void skill::gust()				//바람일으키기
{
	_power = 40;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::FLYING;				//타입
}

void skill::quickAttack()		//전광석화
{
	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입
}

void skill::wingAttack()		//날개치기
{
	_power = 60;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::FLYING;				//타입
}

void skill::tailWhip()			//꼬리흔들기
{
	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::peck()				//쪼기
{
	_power = 35;				//위력
	_PP = 35;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::FLYING;				//타입
}

void skill::growl()				//울음소리
{
	_power = NULL;				//위력
	_PP = 40;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::leer()				//째려보기
{
	_power = NULL;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::thunderShock()		//전기쇼크
{
	_index = RND->getFromIntTo(0, 100);

	_power = 40;				//위력
	_PP = 30;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::ELECTR;				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼확률로 마비

}

void skill::thunderbolt()		//10만볼트
{
	_index = RND->getFromIntTo(0, 100);

	_power = 90;				//위력
	_PP = 15;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::ELECTR;				//타입

	if (_index > 90) STATUS_AILMENT::PARALYSIS;	//상태이상 10퍼 확률로 마비
}

void skill::razorLeaf()			//잎날가르기
{
	_power = 55;				//위력
	_PP = 25;					//PP
	_accuracy = 95;				//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::GRASS;				//타입
}

void skill::reflect()			//리플렉터 물리데미지 반감.
{
	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = NULL;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::PSYCHC;				//타입
}

void skill::smokescreen()		//연막
{
	_power = NULL;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::CHANGE;		//분류
	TYPE::NOMAL;				//타입
}

void skill::ember()				//불꽃세례
{
	_index = RND->getFromIntTo(0, 100);

	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::FIRE;					//타입

	if (_index > 90) STATUS_AILMENT::BURN; //상태이상
	if (static_cast<int>(STATUS_AILMENT::FREEZE)) STATUS_AILMENT::NONE;	//상대가 얼음상태면 녹일 수 있음 --지워질것--
}

void skill::rage()				//분노
{
	_power = 20;				//위력
	_PP = 20;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::PHYSICS;		//분류
	TYPE::NOMAL;				//타입
}

void skill::waterGun()			//물대포
{
	_power = 40;				//위력
	_PP = 25;					//PP
	_accuracy = 100;			//명중률
	CLASSIFCATION::SPECIAL;		//분류
	TYPE::WATER;				//타입
}
