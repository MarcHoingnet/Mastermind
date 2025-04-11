// Fill out your copyright notice in the Description page of Project Settings.


#include "MastermindRow.h"

#include "MastermindSphere.h"

// Sets default values
AMastermindRow::AMastermindRow()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMastermindRow::BeginPlay()
{
	Super::BeginPlay();
	Manager->OnSolutionChecked.AddDynamic(this, &AMastermindRow::ApplySolution);
}

// Called every frame
void AMastermindRow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMastermindRow::Clicked()
{
	if (!Manager || !Manager->HasRemainingAttempts())
	{
		UE_LOG(LogTemp, Warning, TEXT("Impossible de continuer, nombre max d'essais atteint."));
		return;
	}

	TArray<uint8> Answer;
	Answer.SetNum(4);
	for (int i = 0; i < 4; i++)
	{
		Answer[i] = PlayerSpheres[i]->GetComponentByClass<UMastermindSphere>()->GetSphereColor();
	}
	Manager->CheckAnswer(Answer);
}

void AMastermindRow::GenerateNewSpheres()
{
	for (int i = 0; i < 4; i++)
	{

		FVector NewLocation = FVector(100.f * i, 0.f, 0.f); 
		AActor* NewSphere = GetWorld()->SpawnActor<AActor>(PlayerSpheres[i]->GetClass(), NewLocation, FRotator::ZeroRotator);

		UMastermindSphere* MastermindSphere = NewSphere->FindComponentByClass<UMastermindSphere>();
		if (MastermindSphere)
		{
			MastermindSphere->ChangeColor(Manager->GetColor(FMath::RandRange(0, 5)));
		}
	}
}

void AMastermindRow::ApplySolution(uint8 GoodPlaces, uint8 WrongPlaces)
{
}

