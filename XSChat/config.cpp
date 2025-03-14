class CfgPatches
{
    class XSChat
    {
        requiredAddons[] = { "XSChatDefine" };
    };
};

class CfgMods
{
    class XSChat
    {
        name = "XS Chat Types";
        author = "XS Sunny";
        type = "mod";
        inputs = "XSChat/data/Input.xml";
        dependencies[] = { "Game", "Mission", "World" };

        class defs
        {
			class gameScriptModule
			{
				value = "";
				files[] = { "XSChat/scripts/3_Game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "XSChat/scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "XSChat/scripts/5_Mission" };
			};
        };
    };
};
