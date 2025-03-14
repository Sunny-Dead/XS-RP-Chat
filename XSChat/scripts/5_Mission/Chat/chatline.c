modded class ChatLine {
    void ChatLine(Widget root_widget)
    {
        m_RootWidget = GetGame().GetWorkspace().CreateWidgets("XSChat/GUI/layouts/chatline.layout", root_widget);
        m_NameWidget = TextWidget.Cast(m_RootWidget.FindAnyWidget("ChatItemSenderWidget"));
        m_TextWidget = TextWidget.Cast(m_RootWidget.FindAnyWidget("ChatItemTextWidget"));
        m_NameWidget.SetTextExactSize(GetXSChatSettings().GetSize());
        m_TextWidget.SetTextExactSize(GetXSChatSettings().GetSize());
    }

    void XSUpdateSize()
    {
        m_NameWidget.SetTextExactSize(GetXSChatSettings().GetSize());
        m_TextWidget.SetTextExactSize(GetXSChatSettings().GetSize());
    }

    override void Set(ChatMessageEventParams params)
    {
        super.Set(params);
        int cindex = params.param3.IndexOf(" : ");
        string theName = params.param2;
        string theText = params.param3;
        string channelIndicator = "";
        if (params.param2 == "" && cindex > 0)
        {
            theName = theText.Substring(0, cindex);
            cindex += 3;
            int len = theText.Length() - cindex;
            theText = theText.Substring(cindex, len);
        }

        // Check for the OOC prefix "-> OOC " (7 characters)
        if (theText.IndexOf("-> OOC ") == 0)
        {
            theText = theText.Substring(7, theText.Length() - 7).Trim();
            channelIndicator = " OOC";
            SetXSChatColour(GetXSChatSettings().GetColorOOC(), GetXSChatSettings().GetColorOOC());
        }
        // Check for the ACTION prefix "-> ACTION " (10 characters)
        else if (theText.IndexOf("-> ACTION ") == 0)
        {
            theText = theText.Substring(10, theText.Length() - 10).Trim();
            channelIndicator = " ACTION";
            SetXSChatColour(GetXSChatSettings().GetColorAction(), GetXSChatSettings().GetColorAction());
        }
        else
        {
            // Default to white for DIRECT messages.
            SetColour(0xFFFFFFFF);
        }
        m_NameWidget.SetText(theName + channelIndicator + ": ");
        m_TextWidget.SetText(theText);
    }

    protected void SetXSChatColour(int tcolour, int pcolour)
    {
        m_NameWidget.SetColor(pcolour);
        m_TextWidget.SetColor(tcolour);
    }
}