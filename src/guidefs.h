// ETH32 - an Enemy Territory cheat for windows
// Copyright (c) 2007 eth32 team
// www.cheatersutopia.com & www.nixcoders.org

#pragma once

#include "CAimbot.h"

#define SETFLOAT(x)			((int)(x * 1000))		// only keeping up to 0.001
#define GETFLOAT(x)			(x / 1000.f)

// NOTE: cast arg0-arg4 to int if used, use SETFLOAT/GETFLOAT for floats

static const windef_t windows[] =
{
	{
		"Status",			// title
		WIN_STATUS,			// type
		GUI_MAINVIEW,			// view
		5, 422, 120, 60,			// x, y, w, h
		0,				// num controls
	},
	{
		"Weapon",			// title
		WIN_WEAPON,			// type
		GUI_MAINVIEW,			// view
		95, 422, 120, 60,		// x, y, w, h
		0,				// num controls
	},
	{
		"Spectators",			// title
  		WIN_SPECTATOR,			// type
		GUI_MAINVIEW,			// view
		50, 193, 100, 160,		// x, y, w, h
		0,				// num controls
	},
	{
		"Respawn",		 	// title
		WIN_RESPAWN,			// type
		GUI_MAINVIEW,			// view
		280, 5, 38, 20,			// x, y, w, h
		0,				// num controls
	},
	{
		"Radar",			// title
		WIN_RADAR,			// type
		GUI_MAINVIEW,			// view
		395, 302, 120, 120,		// x, y, w, h
		0,						// num controls
	},
	{
		"Cameras",			// title
		WIN_CAMERA,			// type
		GUI_MAINVIEW,			// view
		5, 5, 5, 5,			// x, y, w, h : these don't matter though
		0,				// num controls
	},
	{
		"Clients",			// title
		WIN_CLIENTS,			// type
		GUI_CLIENTVIEW,			// view
		5, 5, 630, 470,			// x, y, w, h
		0,				// num controls
	},
	{
		"Banner",
		WIN_BANNER,			// type
		GUI_MAINVIEW,			// view
		20, 20, 1, 1,			// x, y, w, h
		0,				// num controls
	},
		/******************AIMBOT*****************/
	{
		"Aimbot",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 200, 400,		// x, y, w, h
		15,				// num controls
		{
			// Type			Label			X		Y		W		H		Arg0 ... Arg4
			{ CTRL_DROPBOX,		"Aimbot Mode", 		5, 		5,		190,		23,		0, AIMMODE_MAX-1, (int)&eth32.settings.aimMode, (int)aimModeText },
			{ CTRL_DROPBOX,		"Aim",			5,		33,		190,		23,		AIM_OFF, AIM_MAX-1, (int)&eth32.settings.aimType, (int)aimTypeText },
			{ CTRL_CHECKBOX,	"Autofire",		5,		67,		190,		8,		(int)&eth32.settings.autofire },
			{ CTRL_CHECKBOX,	"Validate Attack",	5,		80,		190,		8,		(int)&eth32.settings.atkValidate },
			{ CTRL_FLOATSLIDER, 	"FOV",			5,		93,		190,		20,		SETFLOAT(0), SETFLOAT(360), (int)&eth32.settings.fov },
			{ CTRL_DROPBOX,		"Target Sort",		5,		120,		190,		23,		SORT_OFF, SORT_MAX-1, (int)&eth32.settings.aimSort, (int)sortTypeText },
			{ CTRL_DROPBOX,		"Aim Priority",		5,		148,		190,		23,		0, AP_MAX-1, (int)&eth32.settings.headbody, (int)priorityTypeText },
			{ CTRL_CHECKBOX,	"Target Lock",		5,		173,		190,		8,		(int)&eth32.settings.lockTarget },
			{ CTRL_DROPBOX,		"Hitbox Style",		5,		186,		190,		23,		HITBOX_OFF, HITBOX_MAX-1, (int)&eth32.settings.hitboxType, (int)hitboxText },
			{ CTRL_DROPBOX,		"Trace Style",		5,		216,		190,		23,		SEL_CENTER, SEL_MAX-1, (int)&eth32.settings.selectTraceType, (int)selectTraceTypeText },
			{ CTRL_DROPBOX,		"Prediction Type",	5,		246,		190,		23,		PRED_BASIC, PRED_MAX-1, (int)&eth32.settings.predictionType, (int)predictionTypeText },
			{ CTRL_DROPBOX,		"Self Predict",		5,		276,		190,		23,		SPR_OFF, SPR_MAX-1, (int)&eth32.settings.predSelfType, (int)selfPredictText },
			{ CTRL_FLOATSLIDER,	"Predself Amount",	5,		306,		190,		20,		SETFLOAT(-1), SETFLOAT(1), (int)&eth32.settings.predSelf },
			{ CTRL_FLOATSLIDER, 	"Anim. Correction", 	5,		336,		190,		20,		SETFLOAT(-10), SETFLOAT(10), (int)&eth32.settings.animCorrection },
			{ CTRL_CHECKBOX,	"Auto Crouch",		5,		361,		190,		8,		(int)&eth32.settings.autoCrouch },
		}
	},
	{
		"Humanaim",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		325, 60, 200, 318,		// x, y, w, h
		9,						// num controls
		{
			// Type			Label				X	Y	W	H		Arg0 ... Arg4
	    		{ CTRL_DROPBOX,		"Human Mode", 		        5,      5,	190,	23,		0, HUMAN_AIM_MAX-1, (int)&eth32.settings.humanMode, (int)humanModeText },
	    		{ CTRL_FLOATSLIDER,	"Simple Logins - Speed",	5,	38,	190,	20,		SETFLOAT(-0.0), SETFLOAT(0.2), (int)&eth32.settings.human1_speed },
	    		{ CTRL_FLOATSLIDER,	"Full Logins - Human Value",	5,	73,	190,	20,		SETFLOAT(-0.0), SETFLOAT(3), (int)&eth32.settings.human2_humanValue },
            		{ CTRL_FLOATSLIDER,	"Full Logins - SpeedX",		5,	108,	190,	20,		SETFLOAT(-0.0), SETFLOAT(10), (int)&eth32.settings.human2_aimX },
            		{ CTRL_FLOATSLIDER,	"Full Logins - SpeedY",		5,	143,	190,	20,		SETFLOAT(-0.0), SETFLOAT(100), (int)&eth32.settings.human2_aimY },
            		{ CTRL_FLOATSLIDER,	"Full Logins - DivMin",		5,	178,	190,	20,		SETFLOAT(-0.0), SETFLOAT(10), (int)&eth32.settings.human2_divMin },
            		{ CTRL_FLOATSLIDER,	"Full Logins - DivMax",		5,	213,	190,	20,		SETFLOAT(-0.0), SETFLOAT(10), (int)&eth32.settings.human2_divMax },
            		{ CTRL_DROPBOX,		"Aim Protect", 		      	5, 	248,    190,	23,		0, PROTECT_MAX-1, (int)&eth32.settings.aimprotect, (int)aimprotectText },            		
            		{ CTRL_CHECKBOX,	"Lock mouse while aiming",	5,	283,	190,	8,		(int)&eth32.settings.lockMouse },

		}
	},
	{
		"Aimbot Misc",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		157, 300, 150, 225,		// x, y, w, h
		8,				// num controls
		{
			// Type			Label				X	Y	W	H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Preshoot",		        5,	5,      140,	8,		(int)&eth32.settings.preShoot },
			{ CTRL_CHECKBOX,	"Preaim",		        5,	20,     140,	8,		(int)&eth32.settings.preAim },
			{ CTRL_CHECKBOX,	"Auto PreAim/Shoot",		5,	35,     140,	8,		(int)&eth32.settings.autoPreAimShoot },
			{ CTRL_FLOATSLIDER,	"Preshoot Time",	        5,	50,	140,	20,		SETFLOAT(0), SETFLOAT(300), (int)&eth32.settings.preShootTime },
			{ CTRL_FLOATSLIDER,	"Preaim Time",		        5,	85, 	140,	20,		SETFLOAT(0), SETFLOAT(300), (int)&eth32.settings.preAimTime },
			{ CTRL_FLOATSLIDER,	"Weapon Spread",	    	5,	120, 	140,	20,		SETFLOAT(0), SETFLOAT(500), (int)&eth32.settings.spread },
			{ CTRL_FLOATSLIDER,	"Target Predict",	        5,     	155,	140,	20,		SETFLOAT(-0.1), SETFLOAT(0.1), (int)&eth32.settings.pred },
			{ CTRL_FLOATSLIDER,	"Bot Predict",	                5,     	190,	140,	20,		SETFLOAT(-0.1), SETFLOAT(0.1), (int)&eth32.settings.predbot },
		}
	},
	{
		"Weapon Config",		// title
		WIN_WEAPCONFIG,			// type
		GUI_MENUVIEW,			// view
		157, 55, 150, 225,		// x, y, w, h
		0,				// num controls
	},
		/******************VECS*****************/
	{
		"Corrections",		// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 250, 205,		// x, y, w, h
		7,				// num controls
		{
			{ CTRL_CHECKBOX,	"Enable Auto Corrections",   		5,	5,	240,	8,		(int)&eth32.settings.autocorrections },
			{ CTRL_FLOATSLIDER,	"Auto Corrections Range",	    	5,	20, 	240,	20,		SETFLOAT(0), SETFLOAT(10000), (int)&eth32.settings.RangE },
			{ CTRL_FLOATSLIDER,	"Body Hitbox Size",	    		5,	50, 	240,	20,		SETFLOAT(0), SETFLOAT(40), (int)&eth32.settings.bodybox },
			{ CTRL_FLOATSLIDER,	"Head Hitbox Size Close",		5,	80, 	240,	20,		SETFLOAT(0), SETFLOAT(20), (int)&eth32.settings.closeBoxSize },
			{ CTRL_FLOATSLIDER,	"Head Hitbox Size Far",		   	5,	110, 	240,	20,		SETFLOAT(0), SETFLOAT(20), (int)&eth32.settings.farBoxSize },
			{ CTRL_FLOATSLIDER,	"Autopoints close",     		5,	140, 	240,	20,		SETFLOAT(0), SETFLOAT(100), (int)&eth32.settings.pointsclose },
			{ CTRL_FLOATSLIDER,	"Autopoints far",       		5,	170, 	240,	20,		SETFLOAT(0), SETFLOAT(100), (int)&eth32.settings.pointsfar },
		}
	},
	{
		"Hitbox",		// title
		WIN_HITBOX,			// type
		GUI_MENUVIEW,			// view
		7, 55, 250, 205,		// x, y, w, h
		0,				// num controls
	},
		/******************VISUALS*****************/
	{
		"Visuals",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 150, 275,		// x, y, w, h
		15,				// num controls
		{
			// Type			Label				X		Y		W		H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Wallhack",			5,		5,		140,		8,		(int)&eth32.settings.wallhack },
			{ CTRL_CHECKBOX,	"Do distance wallhack",		5,		18,		140,		8,		(int)&eth32.settings.doDistWallhack },
			{ CTRL_FLOATSLIDER,	"Wallhack Dist.",		5,		31,		140,		20,		SETFLOAT(0), SETFLOAT(10000), (int)&eth32.settings.wallhackDistance },
			{ CTRL_CHECKBOX,	"Draw Scope Blackout",		5,		55,		140,		8,		(int)&eth32.settings.blackout },
			{ CTRL_CHECKBOX,	"Weapon Zoom",			5,		68,		140,		8,		(int)&eth32.settings.weaponZoom },
			{ CTRL_FLOATSLIDER,	"Scoped Turning",		5,		81,		140,		20,		SETFLOAT(0.1), SETFLOAT(1.0), (int)&eth32.settings.scopedTurnSpeed },
			{ CTRL_INTSLIDER,	"Smoke Visibility",		5,		106,		140,		20,		0, 100, (int)&eth32.settings.smoketrnsp },
			{ CTRL_FLOATSLIDER,	"Radar Range",			5,		131,		140,		20,		SETFLOAT(100), SETFLOAT(10000), (int)&eth32.settings.radarRange },
			{ CTRL_CHECKBOX,	"Disguised ESP",		5,		156,		140,		8,		(int)&eth32.settings.drawDisguised },
			{ CTRL_CHECKBOX,	"Missile Blast Light",		5,		169,		140,		8,		(int)&eth32.settings.grenadeDlight },
			{ CTRL_CHECKBOX,	"Mortar Blast Light",		5,		182,		140,		8,		(int)&eth32.settings.mortarDlight },
			{ CTRL_CHECKBOX,	"Mortar Trace and Esp",		5,		195,		140,		8,		(int)&eth32.settings.mortarTrace },
			{ CTRL_CHECKBOX,	"Arty Markers",			5,		208,		140,		8,		(int)&eth32.settings.artyMarkers },
			{ CTRL_CHECKBOX,	"Banner",			5,		221,		140,		8,		(int)&eth32.settings.guiBanner },
			{ CTRL_FLOATSLIDER,	"Banner size",			5,		235,		140,		20,		SETFLOAT(0), SETFLOAT(3), (int)&eth32.settings.BannerScale },

		},
	},
	{
		"Chams",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 150, 175,		// x, y, w, h
		6,				// num controls
		{
			// Type			Label				X		Y		W		H		Arg0 ... Arg4
			{ CTRL_DROPBOX,		"Player Chams",			5,		5,		140,		23,		0, MAX_CHAMS-1, (int)&eth32.settings.chamsPlayer, (int)chamsText },
			{ CTRL_DROPBOX,		"Player OutChams",		5,		35,		140,		23,		0, MAX_CHAMSOUT-1, (int)&eth32.settings.outChams, (int)outchamsText },
			{ CTRL_DROPBOX,		"Weapon Chams",			5,		65,		140,		23,		0, MAX_CHAMS-1, (int)&eth32.settings.chamsWeapon, (int)chamsText },
			{ CTRL_DROPBOX,  	"Weapon OutChams",  		5,              95,      	140,            23,        	0, MAX_CHAMSOUT-1, (int)&eth32.settings.weapoutChams, (int)outchamsText },
			{ CTRL_CHECKBOX,	"My Weapon Cham",		5,		130,		140,		8,		(int)&eth32.settings.chamsOurWeapon },
			{ CTRL_CHECKBOX,	"Weapon OutChams",		5,		143,		140,		8,		(int)&eth32.settings.outchamweapon },

		},
	},
	{
		"Hitbox Display",		// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		157, 55, 150, 85,		// x, y, w, h
		5,				// num controls
		{
			// Type			Label			X		Y		W		H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Head",			5,		5,		140,		8,		(int)&eth32.settings.drawHeadHitbox },
			{ CTRL_CHECKBOX,	"Head Axes",		5,		18,		140,		8,		(int)&eth32.settings.drawHeadAxes },
			{ CTRL_CHECKBOX,	"Body",			5,		31,		140,		8,		(int)&eth32.settings.drawBodyHitbox },
			{ CTRL_CHECKBOX,	"Bullet Rail",		5,		44,		140,		8,		(int)&eth32.settings.drawBulletRail },
			{ CTRL_CHECKBOX,	"Rail Wallhack",	5,		57,		140,		8,		(int)&eth32.settings.railWallhack }
		},
	},
	{
		"Colors",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		300, 350, 500, 160,		// x, y, w, h
		1,				// num controls
		{
			// Type		    Label			X		Y		W		H		Arg0 ... Arg4
			{ CTRL_COLORPICKER, "Picker",			5,		5,		490,		140 },
		},
	},
	{
		"Esp",				// title
		WIN_ESPCONFIG,			// type
		GUI_MENUVIEW,			// view
		310, 55, 150, 220,		// x, y, w, h
		0,				// num controls
	},
	{
		"Camera Settings",
		WIN_CAMCONFIG,
		GUI_MENUVIEW,
		500, 55, 150, 150,
		0,
	},
		/******************MISC*****************/
	{
		"Misc",				// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 150, 200,		// x, y, w, h
		12,				// num controls
		{
			//{ CTRL_CHECKBOX,	"Name Click",		5,		5,		140,	8,		(int)&eth32.settings.nameClick },
			{ CTRL_CHECKBOX,	"Spec list", 		5, 		5, 		140, 	8, 		(int)&eth32.settings.getSpeclist },
			//{ CTRL_CHECKBOX,	"Third Person",		5,		31,		140,	8,		(int)&eth32.settings.thirdPerson },
			{ CTRL_CHECKBOX,	"Transparent Console",	5,		20,		140,	8,		(int)&eth32.settings.transparantConsole },
			{ CTRL_CHECKBOX,	"Respawn Timers",	5,		35,		140,	8,		(int)&eth32.settings.respawnTimers },
			{ CTRL_CHECKBOX,	"Auto Tapout",		5,		50,		140,	8,		(int)&eth32.settings.autoTapout },
			{ CTRL_DROPBOX,		"PB Screenshot",	5,		65,		140,	23,		0, PB_SS_MAX-1, (int)&eth32.settings.pbScreenShot, (int)pbssText },
			{ CTRL_CHECKBOX,	"Draw Hackvisuals",	5,		90,		140,	8,		(int)&eth32.settings.drawHackVisuals },
			{ CTRL_CHECKBOX,	"Original Viewvalues",	5,		105,		140,	8,		(int)&eth32.settings.origViewValues },
			{ CTRL_CHECKBOX,	"Interpolated PS",	5,		120,		140,	8,		(int)&eth32.settings.interpolatedPs },
			{ CTRL_CHECKBOX,	"Damage Feedback",	5,		135,		140,	8,		(int)&eth32.settings.dmgFeedback },
			{ CTRL_CHECKBOX,	"Remove Foliage",	5,		148,		140,	8,		(int)&eth32.settings.removeFoliage },
			{ CTRL_CHECKBOX,	"Auto Vote",		5,		161,		140,	8,		(int)&eth32.settings.autoVote },
			{ CTRL_CHECKBOX,	"Warning Messages",	5,		174,		140,	8,		(int)&eth32.settings.showReload },
		},
	},
	{
		"Grenadebot",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		320, 55, 150, 300,		// x, y, w, h
		16,						// num controls
		{
			// Type				Label					X		Y		W		H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Grenade Aimbot",		5,		5,		140,		8,		(int)&eth32.settings.grenadeBot },
			{ CTRL_CHECKBOX,	"Riflenade Aimbot",		5,		18,		140,		8,		(int)&eth32.settings.rifleBot },
			{ CTRL_CHECKBOX,	"Block fire",			5,		31,		140,		8,		(int)&eth32.settings.grenadeBlockFire },
			{ CTRL_CHECKBOX,	"Grenade Trajectory",		5,		44,		140,		8,		(int)&eth32.settings.valGrenTrajectory },
			{ CTRL_CHECKBOX,	"Rifle Trajectory",		5,		57,		140,		8,		(int)&eth32.settings.valRifleTrajectory },
			{ CTRL_CHECKBOX,	"Grenade Senslock",		5,		70,		140,		8,		(int)&eth32.settings.grenadeSenslock },
			{ CTRL_FLOATSLIDER,	"Rifle Z correction",		5,		93,		140,		20,		SETFLOAT(-50), SETFLOAT(50), (int)&eth32.settings.riflenadeZ },
			{ CTRL_FLOATSLIDER,	"Grenade Z correction",		5,		118,		140,		20,		SETFLOAT(-50), SETFLOAT(50), (int)&eth32.settings.grenadeZ },
			{ CTRL_INTSLIDER,	"Grenade Fire Delay",		5,		142,		140,		20,		0, 1000, (int)&eth32.settings.grenadeFireDelay },
			{ CTRL_CHECKBOX,	"Grenade Autofire",		5,		165,		140,		8,		(int)&eth32.settings.grenadeAutoFire },
			{ CTRL_CHECKBOX,	"Riflenade Autofire",		5,		178,		140,		8,		(int)&eth32.settings.rifleAutoFire },
			{ CTRL_DROPBOX,		"Target Predict",		5,		191,		140,		23,		0, RF_PREDICT_MAX-1, (int)&eth32.settings.ballisticPredict, (int)riflePredictText},
			{ CTRL_CHECKBOX,	"Check Radius Damage",		5,		220,		140,		8,		(int)&eth32.settings.ballisticRadiusDamage },
			{ CTRL_FLOATSLIDER,	"Blast radius",			5,		233,		140,		20,		SETFLOAT(30), SETFLOAT(500), (int)&eth32.settings.radiusDamage },
			{ CTRL_CHECKBOX,	"Auto Targets",			5,		258,		140,		8,		(int)&eth32.settings.autoGrenTargets },
			{ CTRL_CHECKBOX,	"Multi Bounce",			5,		271,		140,		8,			(int)&eth32.settings.allowMultiBounce },
		}
	},
	{
		"Crosshair",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		7, 55, 200, 90,			// x, y, w, h
		3,				// num controls
		{
			{ CTRL_DROPBOX,		"Custom Crosshair",	5,		5,		190,	23,		0, XHAIR_MAX-1, (int)&eth32.settings.customXhair, (int)crosshairText },
			{ CTRL_FLOATSLIDER,	"Xhair Size",		5,		35,		190,	20,		SETFLOAT(0), SETFLOAT(50), (int)&eth32.settings.crossSize },
			{ CTRL_FLOATSLIDER,	"Xhair Thick",		5,		55,		190,	20,		SETFLOAT(0), SETFLOAT(5), (int)&eth32.settings.crossThick },
		},
	},
	{
		"Sound",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		157, 250, 150, 125,		// x, y, w, h
		7,				// num controls
		{
			{ CTRL_CHECKBOX,	"Kill Sounds",		        5,		5,		140,	8,		(int)&eth32.settings.killSounds },
			{ CTRL_CHECKBOX, 	"HitSound 1",		        5,		18,		140,	8,		(int)&eth32.settings.hitsounds },
			{ CTRL_CHECKBOX, 	"HitSound 2",		        5,		31,		140,	8,		(int)&eth32.settings.hitsounds2 },
			{ CTRL_CHECKBOX, 	"HitSound 3",		        5,		44,		140,	8,		(int)&eth32.settings.hitsounds3 },
			{ CTRL_CHECKBOX,	"Pure Only",		        5,		57,		140,	8,		(int)&eth32.settings.pureSounds },
			{ CTRL_CHECKBOX,	"HQ sounds",		        5,		70,		140,	8,		(int)&eth32.settings.hqSounds },
			{ CTRL_FLOATSLIDER,	"MK Reset Time",		5,		83,		140,	20,		SETFLOAT(0), SETFLOAT(10000), (int)&eth32.settings.mkResetTime },
		},
	},
	{
		"Namestealer",			// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		320, 370, 150, 100,		// x, y, w, h
		4,				// num controls
		{
			// Type			Label				X		Y		W		H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Name Steal",			5,		5,		140,		8,		(int)&eth32.settings.doNamesteal },
			{ CTRL_INTSLIDER,	"Delay",			5,		18,		140,		20,		0, 20000, (int)&eth32.settings.NamestealDelay },
			{ CTRL_INTSLIDER,	"Init Grace",			5,		41,		140,		20,		0, 20000, (int)&eth32.settings.NamestealGrace },
			{ CTRL_DROPBOX,		"Steal type",			5,		64,		140,		23,		0, NAMESTEAL_MAX-1, (int)&eth32.settings.NamestealMode, (int)namestealText },
		}
	},
	{
		"Spam",					// title
		WIN_STANDARD,			// type
		GUI_MENUVIEW,			// view
		320, 150, 150, 110,		// x, y, w, h
		6,				// num controls
		{
			// Type			Label				X		Y		W		H		Arg0 ... Arg4
			{ CTRL_CHECKBOX,	"Kill Spam",			5,		5,		140,		8,		(int)&eth32.settings.killSpam },
			{ CTRL_CHECKBOX,	"Multikill Spam",		5,		18,		140,		8,		(int)&eth32.settings.multikillSpam },
			{ CTRL_CHECKBOX,	"Death Spam",			5,		31,		140,		8,		(int)&eth32.settings.deathSpam },
			{ CTRL_CHECKBOX,	"Suicide Spam",			5,		44,		140,		8,		(int)&eth32.settings.suicideSpam },
			{ CTRL_CHECKBOX,	"PrivateMsg killspam",		5,		57,		140,		8,		(int)&eth32.settings.pmKillspam },
			{ CTRL_DROPBOX,		"Killspam Type",		5,		70,		140,		23,		0, KILLSPAM_MAX-1, (int)&eth32.settings.KillspamType, (int)killspamText },
		}
	},
};

static const assetdef_t assetDefs[] =
{
//	  Key			Type				Target
	{ "titlecolor",		ASSET_VEC4,			(void*)eth32.guiAssets.titleColor },
	{ "textcolor1",		ASSET_VEC4,			(void*)eth32.guiAssets.textColor1 },
	{ "textcolor2",		ASSET_VEC4,			(void*)eth32.guiAssets.textColor2 },
	{ "titleleft",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.titleLeft },
	{ "titlecenter",	ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.titleCenter },
	{ "titleright",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.titleRight },
	{ "winleft",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.winLeft },
	{ "wintop",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.winTop },
	{ "wintopl",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.winTopLeft },
	{ "wincenter",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.winCenter },
	{ "txtinputl",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.txtinputLeft },
	{ "txtinputc",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.txtinputCenter },
	{ "txtinputr",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.txtinputRight },
	{ "btnl",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnLeft },
	{ "btnc",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnCenter },
	{ "btnr",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnRight },
	{ "btnsell",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnselLeft },
	{ "btnselc",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnselCenter },
	{ "btnselr",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.btnselRight },
	{ "check",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.check },
	{ "checkbox",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.checkBox },
	{ "mouse",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.mousePtr },
	{ "dropboxarrow",	ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.dropboxArrow },
	//{ "scrollarrow",	ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.scrollbarArrow },
	//{ "scrollbtn",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.scrollbarBtn },
	//{ "scrolltrack",	ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.scrollbarTrack },
	{ "sliderbtn",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.sliderBtn },
	{ "slidertrack",	ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.sliderTrack },
	{ "camcorner",		ASSET_SHADERNOMIP,		(void*)&eth32.guiAssets.camCorner },
};
