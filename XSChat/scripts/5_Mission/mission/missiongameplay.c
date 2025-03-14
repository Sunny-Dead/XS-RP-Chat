modded class MissionGameplay extends MissionBase
{
    // 0 = DIRECT, 1 = OOC, 2 = ACTION
    private int m_XSChatChannel = 0;

    void MissionGameplay()
    {
    }

    override void OnUpdate(float timeslice)
    {
        super.OnUpdate(timeslice);
        if (GetUApi() && !m_UIManager.IsMenuOpen(MENU_CHAT_INPUT))
        {
            UAInput inpChannel = GetUApi().GetInputByName("UAXSChatChannel");
            if (inpChannel && inpChannel.LocalPress())
            {
                m_XSChatChannel = (m_XSChatChannel + 1) % 3;
                string channelName;
                string colorTag;
                if (m_XSChatChannel == 0)
                {
                    channelName = "DIRECT";
                    colorTag = "colorDirect";
                }
                else if (m_XSChatChannel == 1)
                {
                    channelName = "OOC";
                    colorTag = "colorOOC";
                }
                else
                {
                    channelName = "ACTION";
                    colorTag = "colorAction";
                }
                ChatMessageEventParams msgParams = new ChatMessageEventParams(CCSystem, "", "You swapped to " + channelName + " channel", colorTag);
                MissionGameplay.Cast(GetGame().GetMission()).m_Chat.Add(msgParams);
            }

            UAInput inpDown = GetUApi().GetInputByName("UAXSChatSizeDown");
            if (inpDown && inpDown.LocalPress())
            {
                int newSizeDown = Math.Max(12, GetXSChatSettings().GetSize() - 1);
                GetXSChatSettings().SetSize(newSizeDown);
                Chat.Cast(m_Chat).XSUpdateSize();
            }

            UAInput inpUp = GetUApi().GetInputByName("UAXSChatSizeUp");
            if (inpUp && inpUp.LocalPress())
            {
                int newSizeUp = Math.Min(30, GetXSChatSettings().GetSize() + 1);
                GetXSChatSettings().SetSize(newSizeUp);
                Chat.Cast(m_Chat).XSUpdateSize();
            }
        }
    }

    int XSGetChatChannel()
    {
        return m_XSChatChannel;
    }

    string XSGetChatChannelName()
    {
        if (m_XSChatChannel == 0) return "DIRECT";
        else if (m_XSChatChannel == 1) return "OOC";
        return "ACTION";
    }
}