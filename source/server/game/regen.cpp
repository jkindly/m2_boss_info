// find:
/*
if (ch && !bOnce)
	ch->SetRegen(regen);
*/
// in function: static void regen_spawn(LPREGEN regen, bool bOnce, bool bFirstSpawn = false)
// and add below:
#ifdef BOSS_INFO
		if (ch && regen->lMapIndex < 10000 && ch->IsBoss())
		{
			if (bFirstSpawn)
			{
				CHARACTER_MANAGER::Instance().AddBossToMap(regen->lMapIndex, ch->GetRaceNum());
			}
			else
			{
				CHARACTER_MANAGER::Instance().BossInfoUpdate(ch->GetRaceNum(), ch->GetMapIndex(), 1);

				CHARACTER_MANAGER::instance().for_each_pc([&](LPCHARACTER ch)
				{
					CHARACTER_MANAGER::Instance().SendBossInfo(ch);
				});
			}
		}
#endif