// find: ch->StartCheckSpeedHackEvent();
// add below:
#ifdef BOSS_INFO
	CHARACTER_MANAGER::Instance().SendBossInfo(ch);
#endif