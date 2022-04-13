// Copyright Epic Games, Inc. All Rights Reserved.

#include "Puzzle_Lab0103BlockGrid.h"
#include "Puzzle_Lab0103Block.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

APuzzle_Lab0103BlockGrid::APuzzle_Lab0103BlockGrid()
{
	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f,0.f,0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f,0.f,0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);


	//Biografia del estudiante

	BiografiaText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("BiografiaText0"));
	BiografiaText->SetRelativeLocation(FVector(350.f, 0.f, 0.f));
	BiografiaText->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	BiografiaText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Biografia de la estudiante Lizeth Maribel Condori Cuiza"), FText::AsNumber(0)));
	BiografiaText->SetupAttachment(DummyRoot);

	FechaLugarNacText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("FechaLugarNacText0"));
	FechaLugarNacText->SetRelativeLocation(FVector(380.f, 0.f, 0.f));
	FechaLugarNacText->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	FechaLugarNacText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Fecha de nacimiento: 26/09/2000  en la ciudad de Potosi"), FText::AsNumber(0)));
	FechaLugarNacText->SetupAttachment(DummyRoot);
	// Set defaults
	Size = 3;
	BlockSpacing = 300.f;
}


void APuzzle_Lab0103BlockGrid::BeginPlay()
{
	Super::BeginPlay();

	// Number of blocks
	const int32 NumBlocks = Size * Size;

	// Loop to spawn each block
	for(int32 BlockIndex=0; BlockIndex<NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex/Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex%Size) * BlockSpacing; // Modulo gives remainder

		// Make position vector, offset from Grid location
		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();

		// Spawn a block
		APuzzle_Lab0103Block* NewBlock = GetWorld()->SpawnActor<APuzzle_Lab0103Block>(BlockLocation, FRotator(0,0,0));

		// Tell the block about its owner
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		}
	}
}


void APuzzle_Lab0103BlockGrid::AddScore()
{
	// Increment score
	Score++;

	// Update text
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));
}

#undef LOCTEXT_NAMESPACE
