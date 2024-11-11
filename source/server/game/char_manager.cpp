// add at the bottom of the file:

#ifdef BOSS_INFO
void CHARACTER_MANAGER::BossInfoUpdate(DWORD dwVnum, DWORD dwMapIndex, BYTE bIsAlive)
{
	if (m_MapBossInfo.find(dwMapIndex) == m_MapBossInfo.end())
	{
		return;
	}

	std::vector<TBossInfo>& vecBossInfo = m_MapBossInfo[dwMapIndex];

	for (auto& boss : vecBossInfo)
	{
		if (boss.dwBossVnum == dwVnum && boss.bIsAlive != bIsAlive)
		{
			boss.bIsAlive = bIsAlive;
			break;
		}
	}
}

void CHARACTER_MANAGER::SendBossInfo(LPCHARACTER ch)
{
	if (!ch)
	{
		return;
	}

	if (m_MapBossInfo.find(ch->GetMapIndex()) == m_MapBossInfo.end())
	{
		return;
	}

	std::vector<TBossInfo>& vecBossInfo = m_MapBossInfo[ch->GetMapIndex()];

	if (vecBossInfo.empty())
	{
		return;
	}

	ch->ChatPacket(CHAT_TYPE_COMMAND, "ClearBossInfo");

	for (auto const& boss : vecBossInfo)
	{
		ch->ChatPacket(CHAT_TYPE_COMMAND, "AddBossInfo %d %d", boss.dwBossVnum, boss.bIsAlive);
	}

	ch->ChatPacket(CHAT_TYPE_COMMAND, "BossInfoLoadComplete");
}

void CHARACTER_MANAGER::AddBossToMap(DWORD dwMapIndex, DWORD dwBossVnum, BYTE isAlive)
{
    std::vector<TBossInfo>& vecBossInfo = m_MapBossInfo[dwMapIndex];
    vecBossInfo.push_back(TBossInfo(dwBossVnum, isAlive));
}
#endif