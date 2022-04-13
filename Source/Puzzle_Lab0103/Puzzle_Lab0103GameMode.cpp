// Copyright Epic Games, Inc. All Rights Reserved.

#include "Puzzle_Lab0103GameMode.h"
#include "Puzzle_Lab0103PlayerController.h"
#include "Puzzle_Lab0103Pawn.h"

APuzzle_Lab0103GameMode::APuzzle_Lab0103GameMode()
{
	// no pawn by default
	DefaultPawnClass = APuzzle_Lab0103Pawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = APuzzle_Lab0103PlayerController::StaticClass();
}
