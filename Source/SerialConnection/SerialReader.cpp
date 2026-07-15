#include "SerialReader.h"
#include "SerialCom.h"

ASerialReader::ASerialReader()
{
    PrimaryActorTick.bCanEverTick = true;
    SerialPort = nullptr;
}

void ASerialReader::BeginPlay()
{
    Super::BeginPlay();

    SerialPort = USerialCom::OpenSerialPort(this, TEXT("COM8"), 115200);

    if (SerialPort)
    {
        UE_LOG(LogTemp, Log, TEXT("COM Tools: Serial port opened successfully"));
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("COM Tools: Failed to open serial port"));
    }
}

void ASerialReader::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (SerialPort)
    {
        FString Line = SerialPort->Readln();
        if (!Line.IsEmpty())
        {
            UE_LOG(LogTemp, Log, TEXT("Pot Value: %s"), *Line);
        }
    }
}

void ASerialReader::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (SerialPort)
    {
        SerialPort->Close();
    }
    Super::EndPlay(EndPlayReason);
}