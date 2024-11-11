// add at the end of the file, just before "}"

#if defined(BOSS_INFO)
	PyModule_AddIntConstant(poModule, "BOSS_INFO", 1);
#else
	PyModule_AddIntConstant(poModule, "BOSS_INFO", 0);
#endif