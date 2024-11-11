// find:
void initsystem()

// add below:
#ifdef BOSS_INFO
PyObject* systemSetIsBossInfoExpandend(PyObject* poSelf, PyObject* poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetIsBossInfoExpandend(iFlag);

	return Py_BuildNone();
}

PyObject* systemIsBossInfoExpandend(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsBossInfoExpandend());
}
#endif

// find:
{ "GetWidth", systemGetWidth, METH_VARARGS },

// add above:
#ifdef BOSS_INFO
	{ "SetIsBossInfoExpandend",	systemSetIsBossInfoExpandend, METH_VARARGS },
	{ "IsBossInfoExpandend", systemIsBossInfoExpandend, METH_VARARGS },
#endif