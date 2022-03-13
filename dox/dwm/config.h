/*
    dwm/config.h
    Configuration file for building dwm.
    by decrovert
*/

#pragma region APPEARANCE
// Layout
static const unsigned int borderpx = 2;  // border pixel of windows
static const unsigned int snap     = 32; // no idea what this is
static const int showbar           = 1;  // 0 means no bar
static const int topbar            = 1;  // 0 means bottom bar

// Fonts
static const char *fonts[]    = { "OverpassMono:size=10" };
static const char dmenufont[] = "OverpassMono:size=10";

// Colours
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[]  = "#203C3C";

// Just an array for organizing the colours
static const char *colors[][3] = {
    //               fg         bg         border
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
#pragma endregion APPEARANCE

// Tags (workspaces)
static const char *tags[] = {
    "1", "2", "3", "4", "5"
};

// Rules for specific windows
static const Rule* rules = NULL;

#pragma region LAYOUTS
// Factor of master area size (0.05f..0.95f)
static const float mfact = 0.55;

// Number of clients in the master area
static const int nmaster = 1;

// 1 means respect size hints in tiled resizals
static const int resizehints = 1;

// 1 will force focus on the fullscreen window
static const int lockfullscreen = 1;

// Layouts (the first index is the default one)
static const Layout layouts[] = {
    // symbol  arrangefunction
    {  "[]=",  tile },    // master and stack
    {  "><>",  NULL },    // no layout function means floating windows
    {  "[M]",  monocle }, // monocle layout (aka "fullscreen")
};
#pragma endregion LAYOUTS

// Mod1Mask for Alt and Mod4Mask for Windows key
#define MODKEY Mod4Mask

/*
    Maps keys with their respective functionality. For example, if I
    press Mod+1, it will "move" to workspace 1. If I press Mod+Shift+1,
    the focused window will have its tag reassigned to 1.
*/
#define TAGKEYS(KEY,TAG) \
    { MODKEY,           KEY, view, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask, KEY, tag,  {.ui = 1 << TAG} }

// Helper for spawning shell commands in the pre-dwm-5.0 fashion
#define SHCMD(CMD) { .v = (const char*[]){ "/bin/sh", "-c", CMD, NULL } }

#pragma region COMMANDS
// Component of dmenucmd, manipulated in spawn()
static char dmenumon[2] = "0";

// Menu app
static const char *dmenucmd[] = {
    "dmenu_run",
    "-m",
    dmenumon,
    "-fn",
    dmenufont,
    "-nb",
    col_gray1,
    "-nf",
    col_gray3,
    "-sb",
    col_cyan,
    "-sf",
    col_gray4,
    NULL
};
#pragma endregion COMMANDS

#pragma region KEYS_AND_BUTTONS
static Key keys[] = {
    //      modifier          key        function        argument
    {       MODKEY,           XK_p,      spawn,          { .v = dmenucmd } },

    {       MODKEY,           XK_b,      togglebar,      { 0 } },

    {       MODKEY,           XK_j,      focusstack,     { .i = +1 } },
    {       MODKEY,           XK_k,      focusstack,     { .i = -1 } },

    {       MODKEY,           XK_i,      incnmaster,     { .i = +1 } },
    {       MODKEY,           XK_d,      incnmaster,     { .i = -1 } },

    {       MODKEY,           XK_h,      setmfact,       { .f = -0.05 } },
    {       MODKEY,           XK_l,      setmfact,       { .f = +0.05 } },

    {       MODKEY,           XK_Tab,    view,           { 0 } },

    {       MODKEY,           XK_z,      zoom,           { 0 } },

    {       MODKEY|ShiftMask, XK_k,      quit,           { 0 } },

    {       MODKEY|ShiftMask, XK_c,      killclient,     { 0 } },

    {       MODKEY,           XK_t,      setlayout,      { .v = &layouts[0] } },
    {       MODKEY,           XK_m,      setlayout,      { .v = &layouts[2] } },
    {       MODKEY,           XK_space,  togglefloating, { 0 } },

    {       MODKEY,           XK_comma,  focusmon,       { .i = -1 } },
    {       MODKEY,           XK_period, focusmon,       { .i = +1 } },
    {       MODKEY|ShiftMask, XK_comma,  tagmon,         { .i = -1 } },
    {       MODKEY|ShiftMask, XK_period, tagmon,         { .i = +1 } },

    TAGKEYS(                  XK_1,                      0),
    TAGKEYS(                  XK_2,                      1),
    TAGKEYS(                  XK_3,                      2),
    TAGKEYS(                  XK_4,                      3),
    TAGKEYS(                  XK_5,                      4),
    TAGKEYS(                  XK_6,                      5),
    TAGKEYS(                  XK_7,                      6),
    TAGKEYS(                  XK_8,                      7),
    TAGKEYS(                  XK_9,                      8)
};

/*
    Possible values of click:
    - ClkTagBar;
    - ClkLtSymbol;
    - ClkStatusText;
    - ClkWinTitle;
    - ClkClientWin;
    - ClkRootWin
*/
static Button buttons[] = {
    // click         eventmask button   function        argument
    {  ClkLtSymbol,  0,        Button1, setlayout,      { 0 } },
    {  ClkWinTitle,  0,        Button1, zoom,           { 0 } },
    {  ClkClientWin, MODKEY,   Button1, movemouse,      { 0 } },
    {  ClkClientWin, MODKEY,   Button2, togglefloating, { 0 } },
    {  ClkClientWin, MODKEY,   Button3, resizemouse,    { 0 } },
    {  ClkTagBar,    0,        Button1, view,           { 0 } },
    {  ClkTagBar,    MODKEY,   Button1, tag,            { 0 } }
};
#pragma endregion KEYS_AND_BUTTONS
