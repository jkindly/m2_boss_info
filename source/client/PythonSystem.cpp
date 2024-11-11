// add at the end of the function: void CPythonSystem::SetDefaultConfig()
#ifdef BOSS_INFO
	m_Config.bIsBossInfoExpandend = true;
#endif

// find:
bool CPythonSystem::IsWindowed()
{
	return m_Config.bWindowed;
}

// add below:
#ifdef BOSS_INFO
bool CPythonSystem::IsBossInfoExpandend()
{
	return m_Config.bPingPktStatus;
}
void CPythonSystem::SetIsBossInfoExpandend(int iFlag)
{
	m_Config.bPingPktStatus = iFlag == 1 ? true : false;
}
#endif	

// find:
if (!stricmp(command, "WIDTH"))
	m_Config.width = atoi(value);
		
// add below:
#ifdef BOSS_INFO
else if (!stricmp(command, "BOSS_INFO"))
	m_Config.bIsBossInfoExpandend = atoi(value) == 1 ? true : false;
#endif

// find:
if (m_Config.bWindowed == 1)
	fprintf(fp, "WINDOWED				%d\n", m_Config.bWindowed);

// add below:
#ifdef BOSS_INFO
	fprintf(fp, "BOSS_INFO					%d\n", m_Config.bIsBossInfoExpandend);
#endif	