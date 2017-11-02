#include<stdio.h>
#include<stdlib.h>

#define MONSTER_COUNT 5

typedef struct monsterInfo
{	
	int nHp;
	int nMp;
	int nDamage;
	int nDefence;
	char name[30];
	char skillName[30];
	
}MonsterInfo;


void Initialize(int _monsterCnt, MonsterInfo **_pMonsterInfo)
{
	int i;

	for (i = 0; i < _monsterCnt; i++)
	{
		_pMonsterInfo[i] = (MonsterInfo*)malloc(sizeof(_pMonsterInfo) * _monsterCnt);
	}
}
void InputInfo(int _monsterCnt, MonsterInfo **_ppMonsterInfo)
{
	int i = 0;
	
	for (i = 0; i < _monsterCnt; i++)
	{
		printf("몬스터의 이름을 입력하세요 : ");
		scanf_s("%s", &_ppMonsterInfo[i]->name,sizeof(_ppMonsterInfo[i]->name));
		printf("HP를 입력 하세요 : ");
		scanf_s("%d",&_ppMonsterInfo[i]->nHp);
		printf("MP를 입력 하세요 : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nMp);
		printf("공격력을 입력 하세요 : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nDamage);
		printf("방어력을 입력 하세요 : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nDefence);
		printf("스킬명을 입력하세요 : ");
		scanf_s("%s", &_ppMonsterInfo[i]->skillName,sizeof(_ppMonsterInfo[i]->name));
		printf("\n");
	}	
}

void PrintMonsterInfo(int _monsterCnt, MonsterInfo **_ppMonsterInfo)
{
	int i;

	for (i = 0; i < _monsterCnt; i++)
	{
		printf("%d번째 몬스터의 정보\n", i + 1 );
		printf("이름 : %s\n", _ppMonsterInfo[i]->name);
		printf("HP : %d\n", _ppMonsterInfo[i]->nHp );
		printf("MP : %d\n", _ppMonsterInfo[i]->nMp );
		printf("공격력 : %d\n", _ppMonsterInfo[i]->nDamage );
		printf("방어력 : %d\n", _ppMonsterInfo[i]->nDefence );
		printf("스킬명 : %s\n", _ppMonsterInfo[i]->skillName );
		printf("\n");
	}
}
void Release(int _monsterCnt, MonsterInfo **_ppMonsterInfo)
{
	int i;
	for (i = 0; i < _monsterCnt; i++)
	{
		free(_ppMonsterInfo[i]);
	}
}

void main()
{
	int monsterCnt = 0;

	MonsterInfo *ppMonsterinfo;

	printf("입력할 몬스터의 숫자를 입력 하세요 : ");
	scanf_s("%d", &monsterCnt);

	Initialize(monsterCnt, &ppMonsterinfo);
	InputInfo(monsterCnt, &ppMonsterinfo);
	PrintMonsterInfo(monsterCnt, &ppMonsterinfo);
	Release(monsterCnt, &ppMonsterinfo);
}
