// find:
static void regen_spawn(LPREGEN regen, bool bOnce)

// change it to:
#ifdef BOSS_INFO
static void regen_spawn(LPREGEN regen, bool bOnce, bool bFirstSpawn = false)
#else
static void regen_spawn(LPREGEN regen, bool bOnce)
#endif


// find:
if (regen->time != 0)
{
	regen_spawn(regen, false);
	
// change to:
if (regen->time != 0)
{
#ifdef BOSS_INFO
	regen_spawn(regen, false, true);
#else
	regen_spawn(regen, false);
#endif

// find:
if (ch && !bOnce)
	ch->SetRegen(regen);

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