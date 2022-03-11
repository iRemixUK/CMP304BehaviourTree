// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIPatrol.h"
#include "AIPatrolPoint.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Kismet/GameplayStatics.h"
#include "AIPatrolController.generated.h"

/**
 * 
 */
UCLASS()
class BEHAVIOURTREE_API AAIPatrolController : public AAIController
{
	GENERATED_BODY()

		// Behavior tree component;
		UBehaviorTreeComponent* BehaviorComp;

		// Blackboard component
		UBlackboardComponent* BlackboardComp;

		// Blackboard keys
		UPROPERTY(EditDefaultsOnly, Category = AI)
		FName LocationToGoKey;

		UPROPERTY(EditDefaultsOnly, Category = AI)
		FName PlayerKey;
		 
		TArray<AActor*> PatrolPoints;

		virtual void OnPossess(APawn* pawn) override;

		int32 CurrentPatrolPoint = 0;
	
public:

	AAIPatrolController();
	void SetPlayerCaught(APawn* pawn);

	// Getter functions
	FORCEINLINE UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }
	FORCEINLINE TArray<AActor*> GetPatrolPoints() const { return PatrolPoints; }
};
