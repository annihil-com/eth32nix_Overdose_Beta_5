/*#include "cg_local.h"

cg_t cg;
cgs_t cgs;

static void CG_ParseScore( team_t team ) {
	int		i, j, powerups;
	int		numScores;
	int		offset;

	if( team == TEAM_AXIS ) {
		cg.numScores = 0;
		
		cg.teamScores[0] = atoi( CG_Argv( 1 ) );
		cg.teamScores[1] = atoi( CG_Argv( 2 ) );
		
		offset = 4;
	} else {
		offset = 2;
	}


	numScores = atoi( CG_Argv( offset - 1 ) );

	for(j = 0; j < numScores; j++) {
		i = cg.numScores;

		cg.scores[i].client = atoi(			CG_Argv( offset + 0 + (j*7)));
		cg.scores[i].score = atoi(			CG_Argv( offset + 1 + (j*7)));
		cg.scores[i].ping = atoi(			CG_Argv( offset + 2 + (j*7)));
		cg.scores[i].time = atoi(			CG_Argv( offset + 3 + (j*7)));
		powerups = atoi(					CG_Argv( offset + 4 + (j*7)));
		cg.scores[i].playerClass = atoi(	CG_Argv( offset + 5 + (j*7)));
		cg.scores[i].respawnsLeft = atoi(	CG_Argv( offset + 6 + (j*7)));

		if ( cg.scores[i].client < 0 || cg.scores[i].client >= MAX_CLIENTS ) {
			cg.scores[i].client = 0;
		}

		cgs.clientinfo[ cg.scores[i].client ].score = cg.scores[i].score;
		cgs.clientinfo[ cg.scores[i].client ].powerups = powerups;

		cg.scores[i].team = cgs.clientinfo[cg.scores[i].client].team;

		cg.numScores++;
	}
}

static void CG_ServerCommand( void ) {
	const char	*cmd;

 	cmd = CG_Argv(0);

	if ( !cmd[0] ) {
		// server claimed the command
		return;
	}

	if ( !strcmp( cmd, "sc0" ) ) {
		CG_ParseScore(TEAM_AXIS);
		return;
	} else if ( !strcmp( cmd, "sc1" ) ) {
		CG_ParseScore(TEAM_ALLIES);
		return;
	}

	if ( !Q_stricmp( cmd, "entnfo" ) ) {
		char buffer[16];
		int allied_number, axis_number;

		trap_Argv(1, buffer, 16);
		axis_number = atoi(buffer);

		trap_Argv(2, buffer, 16);
		allied_number = atoi(buffer);

		return;
	}
}

void CG_ExecuteNewServerCommands( int latestSequence ) {
	while ( cgs.serverCommandSequence < latestSequence ) {
		if ( trap_GetServerCommand( ++cgs.serverCommandSequence ) ) {
			CG_ServerCommand();
		}
	}
}
*/
