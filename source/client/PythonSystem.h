// find:
bool bWindowed;

/// add below:
#ifdef BOSS_INFO
	bool bIsBossInfoExpandend;
#endif

// find:
bool IsWindowed();

// add below:
#ifdef BOSS_INFO
	bool IsBossInfoExpandend();
	void SetIsBossInfoExpandend(int iFlag);
#endif