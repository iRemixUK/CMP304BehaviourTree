// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPatrolController.h"

void AAIPatrolController::OnPossess(APawn* pawn)
{
	Super::OnPossess(pawn);

	// Get reference to the character
	AAIPatrol* AICharacter = Cast<AAIPatrol>(pawn);

	if (AICharacter)
	{
		if (AICharacter->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(AICharacter->BehaviorTree->BlackboardAsset));
		}

		// Populate patrol point array
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAIPatrolPoint::StaticClass(), PatrolPoints);

		BehaviorComp->StartTree(*AICharacter->BehaviorTree);
	}
}

AAIPatrolController::AAIPatrolController()
{
	// Initialise blackboard and behavior tree
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	// Initialise blackboard keys
	PlayerKey = "Target";
	LocationToGoKey = "LocationToGo";

	CurrentPatrolPoint = 0;
}

void AAIPatrolController::SetPlayerCaught(APawn* pawn)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(PlayerKey, pawn);
	}
}

