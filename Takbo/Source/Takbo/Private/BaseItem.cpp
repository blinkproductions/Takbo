// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionVolume = CreateDefaultSubobject<UBoxComponent>(FName("CollisionVolume"));
	RootComponent = CollisionVolume;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnOverlapEnd);
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StaticMesh->AddLocalRotation(FRotator(0.f, 1.f, 0.f));

	/** Makes the item oscillate up and down*/
	FVector NewLocation = GetActorLocation();
	NewLocation.Z = NewLocation.Z + (Amplitude)* FMath::Cos((Oscillations)* RunningTime);
	SetActorLocation(NewLocation);
	RunningTime += DeltaTime;
}

int32 ABaseItem::GetRandomMass()
{
	return CurrentQuantity;
}

void ABaseItem::SetMass()
{
	CurrentQuantity = FMath::Abs(FMath::RandRange(MinMass, MaxMass));
}

void ABaseItem::SetScale()
{
	StaticMesh->SetWorldScale3D(FVector((CurrentQuantity / 2.f), (CurrentQuantity / 2.f), (CurrentQuantity / 2.f)));
}

void ABaseItem::OnOverlapBegin(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::OnOverlapBegin"))
}

void ABaseItem::OnOverlapEnd(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::OnOverlapEnd"))
}
