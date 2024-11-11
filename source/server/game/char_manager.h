// find: typedef std::map<DWORD, CHARACTER_SET> pkCharRaceSet;
// add below:
#ifdef BOSS_INFO
typedef struct SBossInfo
{
	SBossInfo(DWORD dwVnum, BYTE bAlive) : dwBossVnum(dwVnum), bIsAlive(bAlive) {}

	DWORD dwBossVnum;
	BYTE bIsAlive;
} TBossInfo;

// map index -> vector of bosses
typedef std::map<DWORD, std::vector<SBossInfo>> bossInfoMap;
#endif

// find: CHARACTER_SET m_set_pkChrPendingDestroy;
// add below:
#ifdef BOSS_INFO
private:
	bossInfoMap m_MapBossInfo;
public:
	void BossInfoUpdate(DWORD dwRaceVnum, DWORD dwMapIndex, BYTE bIsAlive);
	void SendBossInfo(LPCHARACTER ch);
	void AddBossToMap(DWORD dwMapIndex, DWORD dwBossVnum, BYTE isAlive = 1);
#endif