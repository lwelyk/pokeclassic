.set LOCALID_RIVAL, 1

PokemonTower_2F_MapScripts::
	.byte 0

PokemonTower_2F_EventScript_Channeler::
	msgbox PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts, MSGBOX_NPC
	end

PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts::
    .string "Even we could not identify the\n"
    .string "wayward ghosts.\p"
    .string "A Silph Scope might be able to\n"
    .string "unmask them.$"

PokemonTower_2F_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 0
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_RivalTriggerDown::
	lockall
	setvar VAR_TEMP_1, 1
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_Rival::
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalFacePlayerRight
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalFacePlayerDown
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 1
	msgbox PokemonTower_2F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_RIVAL
	call_if_eq VAR_RIVAL_WINRATE, 2, PokemonTower_2F_EventScript_RivalJolteon
	call_if_eq VAR_RIVAL_WINRATE, 1, PokemonTower_2F_EventScript_RivalFlareon
	call_if_eq VAR_RIVAL_WINRATE, 0, PokemonTower_2F_EventScript_RivalVaporeon
	msgbox PokemonTower_2F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalExitRight
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalExitDown
	playse SE_EXIT
	delay 25
	fadedefaultbgm
	removeobject LOCALID_RIVAL
	setvar VAR_POKEMON_TOWER_STATE, 1
	clearflag FLAG_SAFE_FOLLOWER_MOVEMENT
	releaseall
	end

PokemonTower_2F_EventScript_RivalJolteon::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_JOLTEON, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalFlareon::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_FLAREON, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalVaporeon::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_VAPOREON, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalFacePlayerRight::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 1
	return

PokemonTower_2F_EventScript_RivalFacePlayerDown::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 1
	return

PokemonTower_2F_EventScript_RivalExitRight::
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitRight
	waitmovement 1
	return

PokemonTower_2F_EventScript_RivalExitDown::
	applymovement LOCALID_RIVAL, PokemonTower_2F_Movement_RivalExitDown
	waitmovement 1
	return

PokemonTower_2F_Movement_RivalExitRight::
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PokemonTower_2F_Movement_RivalExitDown::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PokemonTower_2F_Text_RivalIntro::
    .string "{RIVAL}: Hey, {PLAYER}!\n"
    .string "What brings you here?\l"
    .string "Is your Pokémon dead?\p"
    .string "Hey! It's alive!\p"
    .string "I can at least make them faint!\n"
    .string "Let's go!$"

PokemonTower_2F_Text_RivalDefeat::
    .string "What?\n"
    .string "You stinker!\p"
    .string "I took it easy on you, too!$"

PokemonTower_2F_Text_RivalPostBattle::
    .string "How's your Pokédex coming?\n"
    .string "I just caught a Cubone!\p"
    .string "I can't find the bigger Marowak.\n"
    .string "Where could they be?\p"
    .string "I bet there aren't any left!\p"
    .string "Well, I better get going.\n"
    .string "I've got a lot to accomplish,\l"
    .string "unlike you.\p"
    .string "Smell ya later!$"
