/* See LICENSE file for copyright and license details. */
#pragma once

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=14" };
static const char dmenufont[]       = "monospace:size=14";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_green[]       = "#006622";
static const char col_yellow[]      = "#ddaa00";
static const char col_orange[]      = "#ff9933";
static const char col_unused[]      = "#ff00ff"; /* magenta */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_unused, col_unused, col_gray2 },
	[SchemeSel]  = { col_unused, col_unused, col_yellow},
	[SchemeTagsNorm] = { col_gray3, col_gray1, col_unused},
	[SchemeTagsSel]  = { col_gray4, col_green, col_unused},
	[SchemeInfoNorm] = { col_unused, col_gray1, col_unused},
	[SchemeInfoSel]  = { col_gray4, col_cyan,  col_unused},
	[SchemeStatus]   = { col_gray3, col_gray1, col_unused},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* first entry is default */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",      monocle },
	{ "[]=",      tile },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << (TAG)} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << (TAG)} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << (TAG)} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << (TAG)} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
#ifdef USE_ROFI
static const char *dmenucmd[] = { "rofi", "-show", "run", NULL };
#else
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
#endif
static const char *termcmd[]  = { "xterm", "-e", "tmux", NULL };
static const char *lockcmd[]  = { "xtrlock", "-b", NULL };
static const char *scratchcmd[] = { "xterm", "-e", "nvim", "+star", NULL };

static const Key keys[] = {
	/* modifier                     key              function          argument */
	{ MODKEY,                       XK_p,            spawn,            {.v = dmenucmd} },
	{ MODKEY|ShiftMask,             XK_Return,       spawn,            {.v = termcmd} },
	{ MODKEY,                       XK_KP_Enter,     spawn,            {.v = termcmd} },
	{ MODKEY|ControlMask,           XK_l,            spawn,            {.v = lockcmd} },
	{ MODKEY,                       XK_e,            spawn,            {.v = scratchcmd} },
	{ MODKEY,                       XK_b,            togglebar,        {0} },
	{ MODKEY,                       XK_j,            focusstack,       {.i = +1} },
	{ MODKEY,                       XK_k,            focusstack,       {.i = -1} },
	{ MODKEY,                       XK_i,            incnmaster,       {.i = +1} },
	{ MODKEY,                       XK_d,            incnmaster,       {.i = -1} },
	{ MODKEY,                       XK_h,            setmfact,         {.f = -0.05} },
	{ MODKEY,                       XK_l,            setmfact,         {.f = +0.05} },
	{ MODKEY,                       XK_Return,       zoom,             {0} },
	{ MODKEY,                       XK_Tab,          view,             {0} },
	{ MODKEY|ShiftMask,             XK_Page_Down,    shiftview,        {.i = +1} },
	{ MODKEY|ShiftMask,             XK_Page_Up,      shiftview,        {.i = -1} },
	{ MODKEY|ShiftMask,             XK_Tab,          shiftviewclients, {.i = +1} },
	{ MODKEY|ShiftMask,             XK_backslash,    shiftviewclients, {.i = -1} },
	{ MODKEY|ShiftMask,             XK_c,            killclient,       {0} },
	{ MODKEY,                       XK_m,            setlayout,        {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,            setlayout,        {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,            setlayout,        {.v = &layouts[2]} },
	{ MODKEY,                       XK_u,            setlayout,        {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,            setlayout,        {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,        setlayout,        {0} },
	{ MODKEY|ShiftMask,             XK_space,        togglefloating,   {0} },
	{ MODKEY,                       XK_0,            view,             {.ui = ~0} },
	{ MODKEY|ShiftMask,             XK_0,            tag,              {.ui = ~0} },
	{ MODKEY,                       XK_comma,        focusmon,         {.i = -1} },
	{ MODKEY,                       XK_period,       focusmon,         {.i = +1} },
	{ MODKEY|ShiftMask,             XK_comma,        tagmon,           {.i = -1} },
	{ MODKEY|ShiftMask,             XK_period,       tagmon,           {.i = +1} },
	{ MODKEY|ShiftMask,             XK_q,            quit,             {0} },
	TAGKEYS(                        XK_1,                              0)
	TAGKEYS(                        XK_2,                              1)
	TAGKEYS(                        XK_3,                              2)
	TAGKEYS(                        XK_4,                              3)
	TAGKEYS(                        XK_5,                              4)
	TAGKEYS(                        XK_6,                              5)
	TAGKEYS(                        XK_7,                              6)
	TAGKEYS(                        XK_8,                              7)
	TAGKEYS(                        XK_9,                              8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

