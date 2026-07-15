#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SerialReader.generated.h"

UCLASS()
class SERIALCONNECTION_API ASerialReader : public AActor
{
    GENERATED_BODY()

public:
    ASerialReader();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    // COM Tools serial object
    UPROPERTY()
    class USerialCom* SerialPort;
};