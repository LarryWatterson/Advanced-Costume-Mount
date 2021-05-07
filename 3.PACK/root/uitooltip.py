# aratın

	def __AppendAttributeInformation(self, attrSlot):
		itemSubType = item.GetItemSubType()
		if 0 != attrSlot:

			for i in xrange(playermeto.ATTRIBUTE_SLOT_MAX_NUM):
				type = attrSlot[i][0]
				value = attrSlot[i][1]

				if 0 == value:
					continue

# altına ekleyin
				if app.ENABLE_MOUNT_COSTUME_SYSTEM:
					if item.APPLY_MOUNT == type:
						continue

# aratın

		isCostumeBody = 0

# altına ekleyin

		if app.ENABLE_MOUNT_COSTUME_SYSTEM:
			isCostumeMount = 0

# aratın (hemen altında)
				isCostumeBody = item.COSTUME_TYPE_BODY == itemSubType

# altına ekleyin

				if app.ENABLE_MOUNT_COSTUME_SYSTEM:
					isCostumeMount = item.COSTUME_TYPE_MOUNT == itemSubType

# aratın

elif 0 != isCostumeItem

# değiştirin

elif 0 != isCostumeItem and isCostumeMount == 0:

# aratın

			elif item.LIMIT_TIMER_BASED_ON_WEAR == limitType:
				self.AppendTimerBasedOnWearLastTime(metinSlot)
				#dbg.TraceError("1) REAL_TIME flag On ")

# altına ekleyin

		## New Mount System LWT
		if isCostumeItem and isCostumeMount:
			if 0 != attrSlot:
				# chat.ChatPacket(1, "slot1 %d" % metinSlot[1])
				if itemVnum != 91000:
					self.__AppendAffectInformation()
				self.__AppendAttributeInformation(attrSlot)
				self.AppendSpace(2)
				try:
					mountNames =nonplayer.GetMonsterName(metinSlot[3])
					self.AppendTextLine(str(translate.mount_tooltip) % (str(mountNames)))
				except:
					mountNames = ""
				self.AppendSpace(1)
				self.AppendTextLine("Seviye: %d" % (metinSlot[2]))
			if 0 != metinSlot:
				bHasRealtimeFlag = 0
				for i in xrange(item.LIMIT_MAX_NUM):
					(limitType, limitValue) = item.GetLimit(i)
					if item.LIMIT_REAL_TIME == limitType:
						bHasRealtimeFlag = 1
				if 1 == bHasRealtimeFlag:
					self.AppendMallItemLastTime(metinSlot[0])