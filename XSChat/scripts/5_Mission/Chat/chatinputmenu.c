modded class ChatInputMenu extends UIScriptedMenu {
    override bool OnChange(Widget w, int x, int y, bool finished)
    {
        if (UIScriptedWindow.GetActiveWindows()) {
            for (int i = 0; i < UIScriptedWindow.GetActiveWindows().Count(); i++) {
                UIScriptedWindow.GetActiveWindows().GetElement(i).OnChange(w, x, y, finished);
            }
        }
        if (!finished) return false;

        string text = m_edit_box.GetText();
        if (text != "") {
            // Get the current channel from MissionGameplay.
            MissionGameplay mission = MissionGameplay.Cast(GetGame().GetMission());
            int channel = mission.XSGetChatChannel();
            string prefix = "";
            if (channel == 1) {   // OOC channel
                prefix = "OOC ";
            }
            else if (channel == 2) {   // ACTION channel
                prefix = "ACTION ";
            }
            // For DIRECT (channel 0), no prefix is added.
            string finalText;
            if (prefix != "") {
                finalText = "-> " + prefix + text;
            }
            else {
                finalText = text;
            }
            GetGame().ChatPlayer(finalText);
            if (!GetGame().IsMultiplayer()) {
                string name;
                GetGame().GetPlayerName(name);
                ChatMessageEventParams localParams = new ChatMessageEventParams(CCDirect, name, finalText, "");
                MissionGameplay.Cast(GetGame().GetMission()).m_Chat.Add(localParams);
            }
        }
        m_close_timer.Run(0.1, this, "Close");
        GetUApi().GetInputByName("UAPersonView").Supress();
        return true;
    }
}

