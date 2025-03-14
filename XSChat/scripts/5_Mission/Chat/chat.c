modded class Chat
{
    override void Add(ChatMessageEventParams params)
    {
        super.Add(params);
    }

    override void AddInternal(ChatMessageEventParams params)
    {
        super.AddInternal(params);
    }

    // This function is called when the font size is changed.
    void XSUpdateSize()
    {
        foreach(ChatLine line : m_Lines)
        {
            line.XSUpdateSize();
        }
    }
}
