// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "NG.generated.h"

/**
 * 
 */
UCLASS()
class BLANKVRPROJECT_API UNG : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "spice"), Category = "UNG")
		static TArray <FString> LaunchNGspice(FString circuitName);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "spice"), Category = "UNG")
		static bool SaveNetlist(FString netlistName, FString netlist);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "spice"), Category = "UNG")
		static FString LoadSimResults(FString simResultsFilepath);



};
