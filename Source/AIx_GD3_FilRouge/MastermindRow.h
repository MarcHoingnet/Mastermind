#pragma once

#include "CoreMinimal.h"
#include "MasterMindGM.h"
#include "GameFramework/Actor.h"
#include "MastermindRow.generated.h"

// Forward declaration de la classe UMastermindSphere si tu n'as pas déjà d'inclusion pour cette classe
class UMastermindSphere;

UCLASS()
class AIX_GD3_FILROUGE_API AMastermindRow : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMastermindRow();

	// Référence au Manager (GM)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMasterMindGM* Manager;

	// Liste des sphères de réponse existantes (PlayerSpheres)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> PlayerSpheres;

	// Méthode qui est appelée lors du clic
	UFUNCTION(BlueprintCallable)
	void Clicked();

	// Méthode pour appliquer les résultats de la solution
	UFUNCTION(BlueprintCallable)
	void ApplySolution(uint8 GoodPlaces, uint8 WrongPlaces);

	// Méthode pour réinitialiser les sphères
	void ResetSpheres();

	// Méthode pour générer de nouvelles sphères
	void GenerateNewSpheres();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};