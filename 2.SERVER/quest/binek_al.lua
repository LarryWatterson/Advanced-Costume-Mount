-----------------------------------------------------------------
-- Bu files & Quest [Watterson] tarafından geliştirilmiştir --
-- İletişim skype: live:wattersondev --
-----------------------------------------------------------------
quest binek_al begin
	state start begin
		when 20349.chat.locale.seyis.binekal begin --npc vnum
			say_title("Seyis")
			say_sari(locale.seyis.binektext1)
			say_sari(locale.seyis.binektext2)
			say("")
			wait()
			say_turkuaz(locale.seyis.kimekarsi)
			local graphic = 20210 --verilecek binek mobvnum
			local typesec = select(locale.seyis.yarilibinek, locale.seyis.canavarlibinek, locale.seyis.metintasi, locale.seyis.expbonus, locale.seyis.vazgectim)
			if typesec == 1 then
				say_turkuaz(locale.seyis.binekho)
				pc.binek_ver(1, graphic)
			end
			if typesec == 2 then
				say_turkuaz(locale.seyis.binekho)
				pc.binek_ver(2, graphic)
			end
			if typesec == 3 then
				say_turkuaz(locale.seyis.binekho)
				pc.binek_ver(3, graphic)
			end
			if typesec == 4 then
				say_turkuaz(locale.seyis.binekho)
				pc.binek_ver(4, graphic)
			end
			if typesec == 5 then
				say_sari("Sen bilirsin.")
				return
			end
			end
		end
	end