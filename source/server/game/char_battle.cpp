// at the end of function void CHARACTER::Dead(LPCHARACTER pkKiller, bool bImmediateDead) add:
#ifdef BOSS_INFO
	if (pkKiller && pkKiller->IsPC() && !pkKiller->GetDungeon() && IsBoss())
	{
		CHARACTER_MANAGER::Instance().BossInfoUpdate(GetRaceNum(), GetMapIndex(), 0);

		CHARACTER_MANAGER::instance().for_each_pc([&](LPCHARACTER ch)
		{
			CHARACTER_MANAGER::Instance().SendBossInfo(ch);
		});
	}
#endif