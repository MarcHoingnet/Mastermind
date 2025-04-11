#pragma once

#include "CoreMinimal.h"
#include "MasterMindGM.h"
#include "GameFramework/Actor.h"
#include "MastermindRow.generated.h"

// Forward declaration de la classe UMastermindSphere si tu n'as pas d�j� d'inclusion pour cette classe
class UMastermindSphere;

UCLASS()
class AIX_GD3_FILROUGE_API AMastermindRow : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMastermindRow();

	// R�f�rence au Manager (GM)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMasterMindGM* Manager;

	// Liste des sph�res de r�ponse existantes (PlayerSpheres)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> PlayerSpheres;

	// M�thode qui est appel�e lors du clic
	UFUNCTION(BlueprintCallable)
	void Clicked();

	// M�thode pour appliquer les r�sultats de la solution
	UFUNCTION(BlueprintCallable)
	void ApplySolution(uint8 GoodPlaces, uint8 WrongPlaces);

	// M�thode pour r�initialiser les sph�res
	void ResetSpheres();

	// M�thode pour g�n�rer de nouvelles sph�res
	void GenerateNewSpheres();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};