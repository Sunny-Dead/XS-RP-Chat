class XSChatSettings {
    private static string DIR = "$profile:XSChat";
    private static string PATH = DIR + "\\settings.json";
    private static const int DEFAULT_SIZE = 20;

    static vector DEFAULT_COLOR_OOC = "0 200 0";
    static vector DEFAULT_COLOR_ACTION = "0 0 255";

    private int size = DEFAULT_SIZE;

    ref XSChatColour ColorOOC = new XSChatColour(DEFAULT_COLOR_OOC);
    ref XSChatColour ColorAction = new XSChatColour(DEFAULT_COLOR_ACTION);

    int GetColorOOC() {
        if (ColorOOC && ColorOOC.R != 0 && ColorOOC.G != 0 && ColorOOC.B != 0)
        {
            return ColorOOC.Get();
        }
        else
        {
            return GetXSChatServerSettings().GetColorOOC();
        }
    }

    int GetColorAction() {
        if (ColorAction && ColorAction.R != 0 && ColorAction.G != 0 && ColorAction.B != 0)
        {
            return ColorAction.Get();
        }
        else
        {
            return GetXSChatServerSettings().GetColorAction();
        }
    }

    int GetSize() {
        return size;
    }

    void SetSize(int newSize) {
        size = newSize;
        Save();
    }

    void Save() {
        if (GetGame().IsClient())
        {
            if (!FileExist(DIR))
            {
                MakeDirectory(DIR);
            }
            JsonFileLoader<XSChatSettings>.JsonSaveFile(PATH, this);
        }
    }

    static ref XSChatSettings Get() {
        XSChatSettings settings = new XSChatSettings();
        if (FileExist(PATH)) {
            JsonFileLoader<XSChatSettings>.JsonLoadFile(PATH, settings);
        }
        return settings;
    }
}

static ref XSChatSettings g_XSChatSettings;

static ref XSChatSettings GetXSChatSettings() {
    if (!g_XSChatSettings) {
        g_XSChatSettings = XSChatSettings.Get();
        if (GetGame().IsClient()) {
            g_XSChatSettings.Save();
        }
    }
    return g_XSChatSettings;
}
