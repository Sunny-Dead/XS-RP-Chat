class CfgPatches
{
    class XSChatDefine
    {
        requiredVersion = 0.1;
        requiredAddons[] = {};
    };
};

class CfgMods
{
    class XSChatDefine
    {
        dir = "XSChatDefine";
        name = "XSChatDefine";
        credits = "XS Sunny";
        author = "XS Sunny";
        authorID = "0";
        version = "0.1";
        extra = 0;
        type = "mod";
        dependencies[] = { "Game", "World", "Mission" };

        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = { "XSChatDefine/scripts/thing" };
            };
            class worldScriptModule
            {
                value = "";
                files[] = { "XSChatDefine/scripts/thing" };
            };
            class missionScriptModule
            {
                value = "";
                files[] = { "XSChatDefine/scripts/thing" };
            };
        };
    };
};
