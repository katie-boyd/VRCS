// Fill out your copyright notice in the Description page of Project Settings.

#include "BlankVrproject.h"
#include "CString.h"
#include "UnrealString.h"
#include "NameTypes.h"
#include "NG.h"

UNG::UNG(const class FObjectInitializer &PCIP)
	: Super(PCIP)
{

}



TArray <FString> UNG::LaunchNGspice(FString circuitName)//need to add arguments here
{
	FString outputFilename, outputFileDir, cirFilename, ngFlags, ngDir;
	//const TCHAR* ngspiceTchar = *ngspice;
	TArray <FString> simOut;
	FProcHandle beep;

	outputFileDir = "C:\\VRCS\\Outputs\\";
	outputFilename = "C:\\VRCS\\Outputs\\" + circuitName + ".raw";
	cirFilename = "C:\\VRCS\\Netlists\\" + circuitName + ".cir";
	ngFlags = "-b -o " + outputFilename + " " + cirFilename;
	ngDir = "C:/spice/bin/ngspice.exe";

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	PlatformFile.CreateDirectoryTree(*outputFileDir);

	if (!(FPaths::FileExists(ngDir))) {
		return simOut;
	}
	beep = FPlatformProcess::CreateProc(*ngDir, *ngFlags, true, true, false, nullptr, 0, nullptr, nullptr);

	FPlatformProcess::WaitForProc(beep);

	FFileHelper::LoadANSITextFileToStrings(*outputFilename, nullptr, simOut);

	return simOut;
}


bool UNG::SaveNetlist(FString netlistName, FString netlist) {
	FString SaveDirectory = FString("C:/VRCS/Netlists/");

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// CreateDirectoryTree returns true if the destination
	// directory existed prior to call or has been created
	// during the call.
	if (PlatformFile.CreateDirectoryTree(*SaveDirectory))
	{
		// Get absolute file path
		FString AbsoluteFilePath = SaveDirectory + "/" + netlistName + ".cir";

		return (FFileHelper::SaveStringToFile(netlist, *AbsoluteFilePath));
	}
	return false;
}


FString UNG::LoadSimResults(FString simResultsFilepath) {

	return "";
}