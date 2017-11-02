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
		printf("������ �̸��� �Է��ϼ��� : ");
		scanf_s("%s", &_ppMonsterInfo[i]->name,sizeof(_ppMonsterInfo[i]->name));
		printf("HP�� �Է� �ϼ��� : ");
		scanf_s("%d",&_ppMonsterInfo[i]->nHp);
		printf("MP�� �Է� �ϼ��� : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nMp);
		printf("���ݷ��� �Է� �ϼ��� : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nDamage);
		printf("������ �Է� �ϼ��� : ");
		scanf_s("%d", &_ppMonsterInfo[i]->nDefence);
		printf("��ų���� �Է��ϼ��� : ");
		scanf_s("%s", &_ppMonsterInfo[i]->skillName,sizeof(_ppMonsterInfo[i]->name));
		printf("\n");
	}	
}

void PrintMonsterInfo(int _monsterCnt, MonsterInfo **_ppMonsterInfo)
{
	int i;

	for (i = 0; i < _monsterCnt; i++)
	{
		printf("%d��° ������ ����\n", i + 1 );
		printf("�̸� : %s\n", _ppMonsterInfo[i]->name);
		printf("HP : %d\n", _ppMonsterInfo[i]->nHp );
		printf("MP : %d\n", _ppMonsterInfo[i]->nMp );
		printf("���ݷ� : %d\n", _ppMonsterInfo[i]->nDamage );
		printf("���� : %d\n", _ppMonsterInfo[i]->nDefence );
		printf("��ų�� : %s\n", _ppMonsterInfo[i]->skillName );
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

	printf("�Է��� ������ ���ڸ� �Է� �ϼ��� : ");
	scanf_s("%d", &monsterCnt);

	Initialize(monsterCnt, &ppMonsterinfo);
	InputInfo(monsterCnt, &ppMonsterinfo);
	PrintMonsterInfo(monsterCnt, &ppMonsterinfo);
	Release(monsterCnt, &ppMonsterinfo);
}
