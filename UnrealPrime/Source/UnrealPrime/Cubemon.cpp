// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubemon.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CubemonHP.h"

// Sets default values
ACubemon::ACubemon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	RootComponent = MeshComponent;

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	WidgetComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	WidgetComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ACubemon::BeginPlay()
{
	Super::BeginPlay();
	Cast<UCubemonHP>(WidgetComponent->GetUserWidgetObject())->Cubemon = this;
}

// Called every frame
void ACubemon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto camera = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	WidgetComponent->SetWorldRotation(camera->GetCameraRotation());
	WidgetComponent->AddLocalRotation(FRotator(0, 180, 0));
}
