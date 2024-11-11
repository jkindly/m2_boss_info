// add at the bottom of the file:
bool CHARACTER::IsBoss() const 
{
	if (!m_pkMobData)
		return false;

	return m_pkMobData->m_table.bRank == MOB_RANK_BOSS;
}