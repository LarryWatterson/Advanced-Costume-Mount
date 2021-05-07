# arat

class GameWindow(ui.ScriptWindow):
	def __init__(self, stream):
		ui.ScriptWindow.__init__(self, "GAME")
		self.SetWindowName("game")
		net.SetPhaseWindow(net.PHASE_WINDOW_GAME, self)
		player.SetGameWindow(self)

# altına ekleyin

		self.mountTime = app.GetGlobalTimeStamp()
		self.mountCounter = 0

# aratın

	def	__PressJKey(self):
		if app.IsPressed(app.DIK_LCONTROL) or app.IsPressed(app.DIK_RCONTROL):

#altına ekleyin

			if self.CheckMountTime() == False:
				return

# def __PressJKey fonksiyonunun altına ekleyin

	def CheckMountTime(self):
		if self.mountCounter == 0:
			self.mountCounter = 1
		else:
			if self.mountTime < app.GetGlobalTimeStamp():
				self.mountTime = app.GetGlobalTimeStamp() + 2
				self.mountCounter = 0
			else:
				self.mountCounter += 1
				if self.mountCounter == 7:
					self.mountCounter += 1
					chat.AppendChat(1, translate.birazyavasol)
					self.mountTime = app.GetGlobalTimeStamp() + 10
					return False
				elif self.mountCounter > 7:
					chat.AppendChat(1, translate.birazyavasol)
					return False
		return True

