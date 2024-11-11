# find:
self.serverCommander = stringCommander.Analyzer()

# add above:
if app.BOSS_INFO:
    serverCommandList.update({
        "AddBossInfo": self.__AddBossInfo,
        "ClearBossInfo": self.__ClearBossInfo,
        "BossInfoLoadComplete": self.__BossInfoLoadComplete,
    })
    
# add at the bottom of the file:
   if app.BOSS_INFO:
        def __AddBossInfo(self, bossVnum, isAlive):
            if self.interface:
                self.interface.AddBossInfo(int(bossVnum), int(isAlive))

        def __ClearBossInfo(self):
            if self.interface:
                self.interface.ClearBossInfo()

        def __BossInfoLoadComplete(self):
            if self.interface:
                self.interface.BossInfoLoadComplete()