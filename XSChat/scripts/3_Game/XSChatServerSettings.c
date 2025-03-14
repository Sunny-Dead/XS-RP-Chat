class XSChatServerSettings
{
    protected static string DIR = "$profile:XSChat";
    protected static string PATH = DIR + "\\server-settings.json";

    static vector DEFAULT_COLOR_OOC = "0 200 0";
    static vector DEFAULT_COLOR_ACTION = "0 0 255";

    ref XSChatColour ColorOOC = new XSChatColour(DEFAULT_COLOR_OOC);
    ref XSChatColour ColorAction = new XSChatColour(DEFAULT_COLOR_ACTION);

    int GetColorOOC()
    {
        return ColorOOC.Get();
    }

    int GetColorAction()
    {
        return ColorAction.Get();
    }

    void Save()
    {
        if (GetGame().IsServer())
        {
            if (!FileExist(DIR))
            {
                MakeDirectory(DIR);
            }
            JsonFileLoader<XSChatServerSettings>.JsonSaveFile(PATH, this);
        }
    }

    void Load()
    {
        if (FileExist(PATH))
        {
            JsonFileLoader<XSChatServerSettings>.JsonLoadFile(PATH, this);
        }
        Save();
    }
}

class XSChatColour
{
    int R;
    int G;
    int B;

    void XSChatColour(vector c)
    {
        float rr = c[0];
        float gg = c[1];
        float bb = c[2];
        R = rr;
        G = gg;
        B = bb;
    }

    int Get()
    {
        return ARGB(255, R, G, B);
    }

    string Debug()
    {
        return "[XSChatColour] R: " + R + " G: " + G + " B: " + B;
    }
}

static ref XSChatServerSettings g_XSChatServerSettings;

static ref XSChatServerSettings GetXSChatServerSettings()
{
    if (!g_XSChatServerSettings)
    {
        g_XSChatServerSettings = new XSChatServerSettings();
        if (GetGame().IsServer())
        {
            g_XSChatServerSettings.Load();
        }
    }
    return g_XSChatServerSettings;
}
