# add import at the top:
if app.BOSS_INFO:
    import uibossinfo
    
# find:
self.wndChat = None

# add below:
if app.BOSS_INFO:
    self.wndBossInfo = None
    
# find:
self.wndChatLog = wndChatLog

# add below:
if app.BOSS_INFO:
    self.wndBossInfo = uibossinfo.BossInfoWindow()
    
# find:
self.wndChatLog.Destroy()

# add above:
if app.BOSS_INFO:
    self.wndBossInfo.Destroy()
    
# find:
del self.wndChat

# add below:
if app.BOSS_INFO:
    del self.wndBossInfo
    
# find:
if __name__ == "__main__":

# add above:
    if app.BOSS_INFO:
        def ClearBossInfo(self):
            if self.wndBossInfo:
                self.wndBossInfo.ClearBossInfo()

        def AddBossInfo(self, bossVnum, isAlive):
            if self.wndBossInfo:
                self.wndBossInfo.AddBossInfo(bossVnum, isAlive)

        def BossInfoLoadComplete(self):
            if self.wndBossInfo:
                self.wndBossInfo.BossInfoLoadComplete()
                
# find:
if self.wndParty:
    self.wndParty.Show()
            
# add below:
if app.BOSS_INFO and self.wndBossInfo:
    self.wndBossInfo.Show()
    
# find:
if self.wndChat:
    self.wndChat.hide_btnChatSizing()
    self.wndChat.Hide()
    
# add below:
if app.BOSS_INFO and self.wndBossInfo:
    self.wndBossInfo.Hide()
# find:
if self.wndChat:
    hideWindows += self.wndChat,
            
# add below:
if app.BOSS_INFO and self.wndBossInfo:
    hideWindows += self.wndBossInfo,