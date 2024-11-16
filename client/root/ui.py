# if you dont have this def, add it at the bottom of the file:
def MakeText(parent, textlineText, x, y, color):
    textline = TextLine()
    if parent:
        textline.SetParent(parent)
    textline.SetPosition(x, y)
    if color:
        textline.SetFontColor(color[0], color[1], color[2])
    textline.SetText(textlineText)
    textline.Show()
    return textline