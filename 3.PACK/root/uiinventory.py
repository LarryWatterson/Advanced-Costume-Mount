# aratın
	def __LoadWindow(self):
#içinde bulun
		self.toolTip = tooltip

# altına ekleyin

		self.tasonay = None

# aratın

		self.interface = None

#altına ekleyin

		self.tasonay = None


# arat

		elif item.IsRefineScroll(srcItemVID):
			self.RefineItem(srcItemSlotPos, dstItemSlotPos)

# altına ekle

		elif int(srcItemVID) >= 91001 and int(srcItemVID) <= 91040: # sertrifika
			self.MountGraphic(srcItemVID,srcItemSlotPos,dstItemSlotPos)	

# aratın

		elif item.IsKey(srcItemVNum):
			if player.CanUnlock(srcItemVNum, dstSlotPos):

# altına ekleyin

		elif srcItemVNum >= 91001 and srcItemVNum <= 91040:
			if self.__CanAddMountGraphic(dstSlotPos) == True:
				return True

# aratın

	def __CanUseSrcItemToDstItem(self, srcItemVNum, srcSlotPos, dstSlotPos):

# fonksiyon bitişine ekleyin

	def __CanUseForMounts(self, srcitem, srcpos, dstSlotPos, silah=0):
		dstItemVNum = player.GetItemIndex(dstSlotPos)
		if dstItemVNum == 0:
			return False
		item.SelectItem(dstItemVNum)
		itemType = item.GetItemType()
		itemSub = item.GetItemSubType()
		if itemType != item.ITEM_TYPE_COSTUME and itemSub != item.COSTUME_TYPE_MOUNT:	 
			return False

		return True

	def __CanAddMountGraphic(self, dstSlotPos):
		dstItemVNum = player.GetItemIndex(dstSlotPos)
		if dstItemVNum == 0:
			return False
			
		item.SelectItem(dstItemVNum)
		
		if item.ITEM_TYPE_COSTUME != item.GetItemType() and item.COSTUME_TYPE_MOUNT != item.GetItemSubType():
			return False
			
			
		return True

	def MountGraphic(self, srcitem, metinSlotPos, targetSlotPos):
		metinIndex = player.GetItemIndex(metinSlotPos)
		targetIndex = player.GetItemIndex(targetSlotPos)
		item.SelectItem(targetIndex)
		level = int(player.GetItemMetinSocket(targetSlotPos, 2))

		if self.__CanAddMountGraphic(targetSlotPos) == False:
			chat.AppendChat(chat.CHAT_TYPE_INFO, translate.justmount)
			return

		if int(level) == 15 and int(srcitem) == 91001:
			chat.AppendChat(chat.CHAT_TYPE_INFO, translate.mountmaxlevel)
			return

		if int(srcitem) == 91001:
			tasonay = uicommon.QuestionDialog3()
			tasonay.SetText1(translate.mount_gelisiyor)
			tasonay.SetText2(translate.mount_gerekli % ((level+1)*5))
			tasonay.SetText3(translate.mount_desc2)
			tasonay.SetAcceptEvent(lambda arg=True: self.mountokey(arg, metinSlotPos, targetSlotPos))
			tasonay.SetCancelEvent(lambda arg=False: self.mountokey(arg, metinSlotPos, targetSlotPos))
			tasonay.Open()
			self.tasonay = tasonay

		elif int(targetIndex) == 91000:
			tasonay = uicommon.QuestionDialog2()
			tasonay.SetText1(translate.mount_desc)
			tasonay.SetText2(translate.mount_desc2)
			tasonay.SetAcceptEvent(lambda arg=True: self.mountokey(arg, metinSlotPos, targetSlotPos))
			tasonay.SetCancelEvent(lambda arg=False: self.mountokey(arg, metinSlotPos, targetSlotPos))
			tasonay.Open()
			self.tasonay = tasonay

	def mountokey(self, onay, matkap, item):
		if self.tasonay:
			if onay:
				self.tasonay.Close()
				self.tasonay = None
				net.SendItemUseToItemPacket(matkap, item)
			else:
				self.tasonay.Close()
				self.tasonay = None