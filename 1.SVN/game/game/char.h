// aratın

class CPetSystem;

// altına ekleyin

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
class CMountSystem;
#endif

// aratın
};
ESex GET_SEX(LPCHARACTER ch);

// üstüne ekleyin (DİKKAT EDİN }; ÜSTÜNE EKLENECEK

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
private:
	bool m_bIsMount;
public:
	void SetMount() { m_bIsMount = true; }
	bool IsMount() { return m_bIsMount; }
	CMountSystem* GetMountSystem() { return m_mountSystem; }
	void MountSummon(LPITEM mountItem);
	void MountUnsummon(LPITEM mountItem);
	void CheckMount();
	bool IsRidingMount();
	bool MountGraphic(int graphic, LPITEM item); // by LWT
protected:
	CMountSystem* m_mountSystem;
	BYTE m_bMountCounter;
#endif