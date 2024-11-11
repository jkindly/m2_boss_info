import ui
import wndMgr
import nonplayer
import systemSetting

ROOT_PATH = "d:/ymir work/ui/boss_info/"
PATTERN_PATH = "d:/ymir_work/ui/pattern/"
GREEN_COLOR = 0xffc3d4c4
RED_COLOR = 0xFFe57875


class BossInfoWindow(ui.Window):
    def __init__(self):
        ui.Window.__init__(self)
        self.AddFlag("float")

        self.bossInfo = []
        self.bossInfoImages = []
        self.bossInfoTexts = []
        self.backgrounds = []
        self.expandButton = None
        self.minimizeButton = None
        self.isExpanded = False
        self.windowWidth = 0
        self.board = ui.Board()
        self.__CreateButtons()

    def __del__(self):
        self.bossInfo = None
        self.bossInfoImages = None
        self.bossInfoTexts = None
        self.backgrounds = None
        self.expandButton = None
        self.minimizeButton = None
        self.isExpanded = None
        self.windowWidth = None
        self.board = None

        ui.Window.__del__(self)

    def __CreateButtons(self):
        self.expandButton = ui.MakeButton(self, 0, 20, "", ROOT_PATH, "r_01.png", "r_02.png", "r_03.png")
        self.minimizeButton = ui.MakeButton(self, 0, 20, "", ROOT_PATH, "z_01.png", "z_02.png", "z_03.png")

        self.expandButton.SetEvent(ui.__mem_func__(self.__ToggleWindow))
        self.minimizeButton.SetEvent(ui.__mem_func__(self.__ToggleWindow))

        self.expandButton.Hide()

    def __ToggleWindow(self):
        if self.isExpanded:
            self.isExpanded = False
            systemSetting.SetIsBossInfoExpandend(False)
            self.expandButton.Show()
            self.minimizeButton.Hide()
            self.SetPosition(wndMgr.GetScreenWidth() - 10, 250)
        else:
            self.isExpanded = True
            systemSetting.SetIsBossInfoExpandend(True)
            self.expandButton.Hide()
            self.minimizeButton.Show()
            self.SetPosition(wndMgr.GetScreenWidth() - self.windowWidth, 250)

    def ClearBossInfo(self):
        self.bossInfo = []
        self.bossInfoImages = []
        self.bossInfoTexts = []
        self.backgrounds = []

    def AddBossInfo(self, bossVnum, isAlive):
        boss = Boss(bossVnum, isAlive)
        self.bossInfo.append(boss)

    def BossInfoLoadComplete(self):
        if len(self.bossInfo) == 0:
            self.Close()
            return

        bossCount = len(self.bossInfo)

        longestBossName = 0
        iter = 0
        minWidth = 120 + 18
        for boss in self.bossInfo:
            if longestBossName < boss.GetBossNameLength():
                longestBossName = boss.GetBossNameLength()

        for boss in self.bossInfo:
            bg = ui.ImageBox()
            bg.SetParent(self.board)

            if bossCount == 1:
                bg.SetPosition(10, 21)
            else:
                bg.SetPosition(10, 10 + (iter * 24))

            if longestBossName <= 18:
                bg.LoadImage(ROOT_PATH + "bg_small.png")
            else:
                bg.LoadImage(ROOT_PATH + "bg_middle.png")
                minWidth = 167 + 18

            bg.Show()
            self.backgrounds.append(bg)

            icon = ROOT_PATH + "alive.png" if boss.IsAlive() else ROOT_PATH + "dead.png"

            image = ui.MakeImageBox(bg, icon, 3, 2)
            self.bossInfoImages.append(image)

            colorText = GREEN_COLOR if boss.IsAlive() else RED_COLOR
            text = ui.MakeText(bg, boss.GetBossName(), 23, 0, None)
            text.SetVerticalAlignCenter()
            text.SetWindowVerticalAlignCenter()
            text.SetPackedFontColor(colorText)

            self.bossInfoTexts.append(text)

            iter += 1

        windowHeight = max(2, bossCount) * 32
        
        # TODO: its kinda hardcoded, so it should be refactored to be more flexible
        if bossCount == 3:
            windowHeight -= 8
        elif bossCount == 4:
            windowHeight -= 15
        elif bossCount == 5:
            windowHeight -= 22
        elif bossCount == 6:
            windowHeight -= 29

        self.windowWidth = minWidth

        self.SetSize(minWidth + 2, windowHeight)
        self.board.SetParent(self)
        self.board.SetSize(minWidth, windowHeight)
        self.board.SetPosition(10, 0)
        self.board.Show()

        if bossCount == 1:
            self.expandButton.SetPosition(0, 16)
            self.minimizeButton.SetPosition(0, 16)
        else:
            self.expandButton.SetPosition(0, windowHeight / 2 - 32 / 2)
            self.minimizeButton.SetPosition(0, windowHeight / 2 - 32 / 2)

        if systemSetting.IsBossInfoExpandend():
            self.isExpanded = True
            self.minimizeButton.Show()
            self.expandButton.Hide()
            self.SetPosition(wndMgr.GetScreenWidth() - self.windowWidth, 250)
        else:
            self.isExpanded = False
            self.expandButton.Show()
            self.minimizeButton.Hide()
            self.SetPosition(wndMgr.GetScreenWidth() - 10, 250)

        self.Show()

    def Close(self):
        self.Hide()


class Boss:
    def __init__(self, bossVnum, isAlive):
        self.bossVnum = bossVnum
        self.isAlive = isAlive

    def GetBossName(self):
        return nonplayer.GetMonsterName(self.bossVnum)

    def GetBossNameLength(self):
        return len(self.GetBossName())

    def IsAlive(self):
        return self.isAlive
